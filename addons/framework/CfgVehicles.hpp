class CfgVehicles
{
    class Helper_Base_F;
    class Storm_Base_Helper : Helper_Base_F {
        author = ECSTRING(main,author_team);
        displayName = "STORM Helper";
        icon = PATH_TO_ADDON_3(data,icons,logo_256.paa);
    };
    class Storm_FX_Sound_Helper : Storm_Base_Helper {
        displayName = "STORM FX Sound Helper";
    };
    class Storm_FX_Particle_Helper : Storm_Base_Helper {
        displayName = "STORM FX Particle Helper";
    };


    class Sign_Arrow_Large_F;
    class Storm_Debug_Helper : Sign_Arrow_Large_F {
        scope = 1;
        author = ECSTRING(main,author_team);
        displayName = "STORM Debug Helper";
        icon = PATH_TO_ADDON_3(data,icons,logo_256.paa);
    };
};