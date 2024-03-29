#include "..\script_component.hpp"

/*
 * Author: [Zorn]
 * Function to apply the Particle Effects - Handles creation, deletion and adjustment of intensity of particlespawners on each client locally.
 * Intensity will be regulated simply by dropInterval (The bigger the number, the less particles)
 * If the same Effect has already been called, it will instead adjust the already existing PE spawner.
 * If _intensityTarget == 0, the function will ether exit in case the spawner doesnt exist already or transition the spawner to 0 intensity and afterwards, the spawner will be deleted.  
 * If a transition is currently taking place (GVAR(Active_hashMap)#_x#3), then the funciton will simply fail silently.
 *
 * Arguments:
 * 0: _EffectName           <STRING> CfgCloudlet Classname of the desired Particle Effect. 
 * 1: _intensityTarget      <Number> 0..1 Intensity of Effect with 1 having the strongest Effect. 
 * 2: _duration             <Number> in seconds. Defines the Duration of the Transition. 
 *
 * Return Value:
 * none - intended to be remoteExecCall -> returns JIP Handle
 *
 * Note: 
 *
 * Example:
 *
 * ["CVO_PE_Leafes", 600, 0.75] remoteExecCall ["storm_fxParticle_fnc_remote",[0,2] select isDedicated, _jip_handle_string];
 * ["CVO_PE_Leafes", 600]       remoteExecCall ["storm_fxParticle_fnc_remote",[0,2] select isDedicated, _jip_handle_string];
 * ["CLEANUP"]                  remoteExecCall ["storm_fxParticle_fnc_remote",[0,2] select isDedicated, _jip_handle_string];
 * ["CVO_PE_Leafes"]                      call   storm_fxParticle_fnc_remote;
 * ["CLEANUP"]                            call   storm_fxParticle_fnc_remote;
 * 
 * Public: No
 */

#define COEF_SPEED_HELI 9
#define COEF_SPEED 5
#define COEF_WIND  0.2
#define PFEH_ATTACH_DELAY 0
#define PFEH_INTENSITY_DELAY 7 // _duration /  PFEH_INTENSITY_DELAY == _delay
#define DROP_INTERVAL_MIN 20



if (!hasInterface) exitWith {};

params [
    ["_effectName",        "",       [""]],
    ["_duration",         300,        [0]],
    ["_intensityTarget",    0,        [0]]
];


// CLEANUP MODE
if ( _effectName isEqualTo "CLEANUP")  exitWith {
    if ( missionNamespace getVariable [QPVAR(DEBUG), false] ) then {
        // Deletes Debug Red Arrow
        deleteVehicle ( (GVAR(Active_hashMap) get "Debug_Helper") select 0 ); 
        GVAR(Active_hashMap) deleteAt "Debug_Helper";
    };

        // Transition to 0 over Default duration for each existing Particle Spawner
    {  
        [_x#1] call cvo_storm_fnc_particle_remote;
    } forEach GVAR(Active_hashMap);
};




if ( _effectName isEqualTo "")  exitWith {false};
if (_intensityTarget < 0     )  exitWith {false};
if (_duration    isEqualTo  0)  exitWith {false};

///////////////////////////////////////////////////
// Handles framework for first new particle Source 
///////////////////////////////////////////////////

if (isNil QGVAR(Active_hashMap)) then {
    //GVAR(Active_hashMap) Nested Array of particle spawners [_spawnerObj, "IdentString",_intensity] 
    GVAR(Active_hashMap) = createHashMap;
    GVAR(isActive) = true;
   
    // Adds Debug_Helper Object (arrow)
    if (missionNamespace getVariable [QPVAR(DEBUG), false]) then {
            _helper = createVehicleLocal [ "Sign_Arrow_Large_F", [0,0,0] ];
            GVAR(Active_hashMap) set [ "Debug_Helper", [_helper]];
    };

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // ATTACH-TO PER FRAME HANDLER
    // Start pfEH to re-attach all Particle Spawners according to player speed & wind.
    // watch GVAR(isActive), if inactive, stop/exit the pfH and delete remaining particle spawners + the particle array
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    private _codeToRun = {
        private _player = vehicle ace_player;  
        //_SpeedVector vectorDiff _windVector
        
        private _isHeli = typeof vehicle player isKindOf "Air";

        _coef_speed = [COEF_SPEED, COEF_SPEED_HELI] select (_isHeli);

        private _relPosArray = (( velocityModelSpace _player ) vectorMultiply _coef_speed) vectorDiff (( _player vectorWorldToModel wind ) vectorMultiply COEF_WIND);

        _relPosArray set [2, (_relPosArray#2) + 1];
        { 
            if (_isHeli && { _x == "Debug_Helper" } ) then { detach (_y#0); continue };
           
            _y#0 attachTo [_player, _relPosArray];
             } forEach GVAR(Active_hashMap);
    };

    private _exitCode  = { 
        { deleteVehicle (_y#0) } forEach GVAR(Active_hashMap); 
        GVAR(Active_hashMap) = nil;  
    };

    private _condition = { GVAR(isActive) };
    private _delay = PFEH_ATTACH_DELAY;

    [{
        params ["_args", "_handle"];
        _args params ["_codeToRun", "_exitCode", "_condition"];

        if ([] call _condition) then {
            [] call _codeToRun;
        } else {
            _handle call CBA_fnc_removePerFrameHandler;
            [] call _exitCode;
        };
    }, _delay, [_codeToRun, _exitCode, _condition]] call CBA_fnc_addPerFrameHandler;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

};

///////////////////////////////////////////////////
///////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////
// Check if a spawner of that type already exists, 
// if not, create, setParticleClass, store as _name = [_obj,_intensity,_isTransitioning] and add it to the array.
// if already exists, take previous intensity and set as start inensity. 
////////////////////////////////////////////////////////////////////////////////////////////////////

private _intensityStart = 0;
private _preExists = _effectName in GVAR(Active_hashMap);

private _dropIntervalStart = getNumber (configFile >> "CfgCloudlets" >> _effectname >> "interval_min");
private _dropIntervalMax   = getNumber (configFile >> "CfgCloudlets" >> _effectname >> "interval");

//private _dropIntervalStart = DROP_INTERVAL_MIN;
//private _dropIntervalMax = ([_effectName] call BIS_fnc_getCloudletParams) select 2; // #0 setParticleParams, #1 setParticleRandom, #2 setDropInterval
private _dropIntervalTarget = linearConversion [0, 1, _intensityTarget, _dropIntervalStart, _dropIntervalMax, true];


private "_spawner";
if (_preExists) then { // Index -1: Requested Type of Particle Spawner does not exist yet, therefor, it creates a new one.

    // Interrupts cration of a new particle spwaner if the target intensity is 0. 
    if (_intensityTarget == 0) exitWith {
        // Stops the reAttach pfh there is no other already existing particlesource. (parseNumber Bool => 0,1 # if Debugmode, expect 1 obj in array to consider it empty, if not, 0 means empty)
        if ( count GVAR(Active_hashMap) == ( parseNumber ( missionNamespace getVariable [QPVAR(DEBUG), false] ) ) ) then { GVAR(isActive) = false; };
        false
    };

    _spawner = createVehicleLocal ["#particlesource", [0,0,0]];
    _spawner setParticleClass _effectName;

    _isTransitioning = true;
    GVAR(Active_hashMap) set [_effectName, [_spawner, _intensityTarget, _isTransitioning] ];

} else {

    _spawnerArray = GVAR(Active_hashMap) get _effectName;

    if (_spawnerArray#2) exitWith {false}; // exits when transition of this PE is already in progress.    
    
    _spawner = _spawnerArray#0; 
    _intensityStart = _spawnerArray#1;
    _spawnerArray set [3, true];
    _dropIntervalStart = linearConversion [0, 1, _intensityTarget, DROP_INTERVAL_MIN, _dropIntervalMax, true];
};

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
// TRANSITION PER FRAME HANDLER
////////////////////////////////////////////////////////////////////////////////////////////////////
///////////// Particle Intensity will simply be adjusted over time via setDropInterval /////////////
///////////// Maybe in Future, Intensity could be applied via colorAlpha, Size, ...    /////////////
///////////// Problem: bad solution solution for non-dust-like particles like leafes   /////////////
///////////// Therefore, for now, particle quantitiy has been chosen as the regulator  /////////////
////////////////////////////////////////////////////////////////////////////////////////////////////

private _startTime = time;
private _endTime = _startTime + _duration;


//// params inside the pfEH
private _parameters = [ _spawner, _startTime, _endTime, _dropIntervalStart, _dropIntervalTarget, _intensityTarget,_effectName ];

private _codeToRun = {
    params [ "_spawner", "_startTime", "_endTime", "_dropIntervalStart", "_dropIntervalTarget", "_intensityTarget","_effectName" ];
    _drop = linearConversion [ _this#1, _this#2 , time, _this#3, _this#4 ];
    _this#0 setDropInterval _drop;
}; 

private _exitCode = {   
    params [ "_spawner", "_startTime", "_endTime", "_dropIntervalStart", "_dropIntervalTarget", "_intensityTarget","_effectName" ];
    diag_log "Transition pfEH Exit";

    (GVAR(Active_hashMap) get _this#6) set [2, false];


    _spawner setDropInterval  _dropIntervalTarget; 
    if ( _intensityTarget isEqualTo 0) then {

        diag_log "Transition pfEH Exit - Intensity == 0 -> Spawner Deleted";
        GVAR(Active_hashMap) deleteAt _this#6;   
        deleteVehicle _spawner;


        if ( count GVAR(Active_hashMap) == ( parseNumber ( missionNamespace getVariable [QPVAR(DEBUG), false] ) ) ) then {
            GVAR(isActive) = false;
        };

        
    };
};

private _condition = {  _this#2 >= time };

private _delay = _duration / PFEH_INTENSITY_DELAY;

[{
    params ["_args", "_handle"];
    _args params ["_codeToRun", "_parameters", "_exitCode", "_condition"];

    if (_parameters call _condition) then {
        _parameters call _codeToRun;
    } else {
        _handle call CBA_fnc_removePerFrameHandler;
        _parameters call _exitCode;
    };
}, _delay, [_codeToRun, _parameters, _exitCode, _condition]] call CBA_fnc_addPerFrameHandler;


////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////// ## Notes ##/////////////////////////////////////////////////
/////////////////// Handling of the Debug_arrow during "CLEANUP" could be optimized, ///////////////
/////////////////// but its happening so rarely, i dont think its gonna be necessary ///////////////
////////////////////////////////////////////////////////////////////////////////////////////////////


// TODO: turn spawner ARRAY into hashMap