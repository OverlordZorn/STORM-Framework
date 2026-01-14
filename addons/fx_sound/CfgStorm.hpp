class CfgStorm {
    class CVAR(Presets)             // class to be used for 3D sounds
    {
        class CVAR(3D_Base)             // class to be used for 3D sounds
        {
            name = "3D_Base";

            distanceMax = 0;
            distanceMin = 0;
            direction = "WIND";
            sounds[] = {};  

            delayMax = 0;
            delayMin = 0;  
        };

        class CVAR(3D_WindLong) : CVAR(3D_Base)             // class to be used for 3D sounds
        {
            name = "3D_WindLong";

            distanceMax = 1000;
            distanceMin = 250;

            direction = "WIND";

            delayMax = 30;
            delayMin = 0;  

            sounds[] = {QCVAR(WindLong1), QCVAR(WindLong2)};
        };

        class CVAR(3D_WindBursts) : CVAR(3D_Base)               // class to be used for 3D sounds
        {
            name = "3D_WindBursts";

            distanceMax = 50;
            distanceMin = 5;

            delayMax = 30;
            delayMin = 0;  

            direction = "RAND";

            sounds[] = {QCVAR(WindBurst1), QCVAR(WindBurst2), QCVAR(WindBurst3), QCVAR(WindBurst4), QCVAR(WindBurst5)};  
        };
    };
};
