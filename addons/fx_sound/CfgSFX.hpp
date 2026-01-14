class CfgSFX
{
	class GVAR(SFX_Base)
	{
		empty[] = { "", 0, 0, 0, 0, 0, 0, 0 };
	};

   	class GVAR(SFX_WindBursts) : GVAR(SFX_Base)
	{
        name = "STORM - Windburst Soundeffects";
        description = "~10s Sound Effects for the Storm SFX Module - Most of them are originally from the Alias Dust Storm Script";

        // {soundPath, soundVolume, soundPitch, maxDistance, probability, minDelay, midDelay, maxDelay}
		sound0[] = { PATH_TO_ADDON_2(data,sandstorm.ogg), "db+20", 1.0, 500, 1, 5, 15, 30 };	// path to addon sound
		sound1[] = { PATH_TO_ADDON_2(data,windburst_1.ogg), "db+20", 1.0, 500, 1, 5, 15, 30 };	// path to addon sound
		sound2[] = { PATH_TO_ADDON_2(data,windburst_2.ogg), "db+20", 1.0, 500, 1, 5, 15, 30 };	// path to addon sound
		sound3[] = { PATH_TO_ADDON_2(data,windburst_3_dr.ogg), "db+20", 1.0, 500, 1, 5, 15, 30 };	// path to addon sound
		sound4[] = { PATH_TO_ADDON_2(data,windburst_4_st.ogg), "db+20", 1.0, 500, 1, 5, 15, 30 };	// path to addon sound
		sounds[] = { "sound0", "sound1", "sound2","sound3","sound4" };
	};

   	class GVAR(SFX_WindLong) : GVAR(SFX_Base)
	{
        name = "STORM - Long Storm Soundeffects";
        description = "~60s Sound Effects for the Storm SFX Module - Most of them are originally from the Alias Dust Storm Script";

        // {soundPath, soundVolume, soundPitch, maxDistance, probability, minDelay, midDelay, maxDelay}
		sound0[] = { PATH_TO_ADDON_2(data,hurricane.ogg), "db+20", 1.0, 50000, 1, 0, 3, 5 };	// path to addon sound
		sound1[] = { PATH_TO_ADDON_2(data,strong_wind.ogg), "db+20", 1.0, 50000, 1, 0, 3, 5 };	// path to addon sound
		sounds[] = { "sound0", "sound1" };
	};
};