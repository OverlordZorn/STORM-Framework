// SNOW STORMS
class PVAR(SnowStorm) : PVAR(base) {
    fx_ai_skill_preset = QEGVAR(fx_ai_skill,reducedVisibility);
    fx_ai_skill_coef = 0.8;

    fx_weather_preset = QEGVAR(fx_weather,SnowStorm);
    fx_weather_coef = 1;

    fx_weather_fog_preset = QEGVAR(fx_weather,fog_STATIC_70);
    fx_weather_fog_coef = 1;

    fx_post_presets[] = {QEGVAR(fx_post,CC_ColdSnow), QEGVAR(fx_post,FG_Storm_10), QEGVAR(fx_post,DB_15)};
    fx_post_coef = 1;

    fx_particle_presets[] = {QEGVAR(fx_particle,Snow)};               /// , QEGVAR(fx_particle,Snow_25)
    fx_particle_coef = 1;
    
    fx_sound_presets[] = {QEGVAR(fx_sound,3D_WindLong),QEGVAR(fx_sound,3D_WindBursts)};
    fx_sound_coef = 1;
};

class PVAR(SnowStorm_Bleak) : PVAR(SnowStorm) {
    fx_post_presets[] = {QEGVAR(fx_post,CC_ColdSnow_Bleak), QEGVAR(fx_post,FG_Storm_10), QEGVAR(fx_post,DB_20)};
};

class PVAR(SnowStorm_Calm) : PVAR(SnowStorm) {
    fx_weather_preset = QEGVAR(fx_weather,SnowStorm_Calm);
    fx_weather_coef = 1;
    fx_sound_coef = 0.3;
};

class PVAR(SnowStorm_Calm_Bleak) : PVAR(SnowStorm_Calm) {
    fx_post_presets[] = {QEGVAR(fx_post,CC_ColdSnow_Bleak), QEGVAR(fx_post,FG_Storm), QEGVAR(fx_post,DB_20)};        
};
