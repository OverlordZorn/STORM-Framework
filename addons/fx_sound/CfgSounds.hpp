// Simple Sounds files for 3D playback
class CfgSounds
{
	class GVAR(Base)
	{
		titles[] = { 0, "" };								// subtitles
		forceTitles = 0;			// Arma 3 - display titles even if global show titles option is off (1) or not (0)
		titlesStructured = 0;		// Arma 3 - treat titles as Structured Text (1) or not (0)
	};

    // Used for "3D_WindLong"
	class GVAR(WindLong1) : GVAR(Base)
	{
		name = "STORM - Wind Long: 1 - Hurricane";								// display name
		sound[] = { PATH_TO_ADDON_2(data,hurricane.ogg), "db+20", 1, 5000 };		// file, volume, pitch, maxDistance
		duration = 60;
	};
	
	class GVAR(WindLong2) : GVAR(Base)
	{
		name = "STORM - Wind Long: 2 - Strong Wind";								// display name
		sound[] = { PATH_TO_ADDON_2(data,strong_wind.ogg), "db+20", 1, 5000 };		// file, volume, pitch, maxDistance
		duration = 70;
	};

    // Used for "3D_WindBursts"
	class GVAR(WindBurst1) : GVAR(Base)
	{
		name = "STORM - Wind Burst: 1";											// display name
		sound[] = { PATH_TO_ADDON_2(data,windburst_1.ogg), "db+20", 1, 250};		// path to addon sound // 05
		duration = 5;
	};

	class GVAR(WindBurst2) : GVAR(Base)
	{
		name = "STORM - Wind Burst: 2";											// display name
		sound[] = { PATH_TO_ADDON_2(data,windburst_2.ogg), "db+20", 1, 250};		// path to addon sound
		duration = 8;
	};

	class GVAR(WindBurst3) : GVAR(Base)
	{
		name = "STORM - Wind Burst: 3";											// display name
		sound[] = { PATH_TO_ADDON_2(data,windburst_3_dr.ogg), "db+20", 1, 250};		// path to addon sound // 05
		duration = 4;
	};

	class GVAR(WindBurst4) : GVAR(Base)
	{
		name = "STORM - Wind Burst: 4";											// display name
		sound[] = { PATH_TO_ADDON_2(data,windburst_4_st.ogg), "db+20", 1, 250};		// path to addon sound
		duration = 4;
	};

	class GVAR(WindBurst5) : GVAR(Base) // sounda kind of like wind wooshing into treetops and rattling leaves
	{
		name = "STORM - Wind Burst: 5 Sandstorm";							// display name
		sound[] = { PATH_TO_ADDON_2(data,sandstorm.ogg), "db+20", 1, 250};		// path to addon sound // 05
		duration = 16;
	};
};
