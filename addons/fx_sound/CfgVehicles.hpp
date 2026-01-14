class CfgVehicles
{
	class Sound;
    class GVAR(SS_Base) : Sound
    {
        name = "STORM - Base Soundsource";
        description = "Base SoundSource Obj Effects for the Storm SFX Module";
        sound = QGVAR(SFX_Base);
    };

	class GVAR(SS_Windbursts) : GVAR(SS_Base) // class name to be used with createSoundSource
	{
        name = "STORM - WindBurst SoundSource";
		sound = QGVAR(SFX_WindBursts); // reference to CfgSFX class
	};

	class GVAR(SS_WindLong) : GVAR(SS_Base) // class name to be used with createSoundSource
	{
        name = "STORM - WindLong SoundSource";
		sound = QGVAR(SFX_WindLong); // reference to CfgSFX class
	};
};