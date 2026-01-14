class CfgStorm {
    class StormPresets {
        class PVAR(base) {
            author = ECSTRING(main,author_team);
            description = "";

            fx_ai_skill_preset = ""; // QEGVAR(mod_skill,reducedVisibility)
            fx_ai_skill_coef = 1;

            fx_weather_preset = "";
            fx_weather_coef = 1;
            fx_weather_fog_preset = "";
            fx_weather_fog_coef = 1;

            fx_post_presets[] = { "" };
            fx_post_coef = 1;

            fx_particle_presets[] = {""};
            fx_particle_coef = 1;
            
            fx_sound_presets[] = {""};
            fx_sound_coef = 1;
        };

        #include "Storm_Sandstorms.hpp"
        #include "Storm_Snowstorms.hpp"
    };
};