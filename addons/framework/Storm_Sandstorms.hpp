// SAND STORMS
class PVAR(Sandstorm) : PVAR(base) {
    fx_ai_skill_preset = QEGVAR(fx_ai_skill,reducedVisibility);
    fx_ai_skill_coef = 0.8;

    fx_weather_preset = QEGVAR(fx_weather,Sandstorm);
    fx_weather_coef = 1;

    fx_weather_fog_preset = QEGVAR(fx_weather,fog_STATIC_90);
    fx_weather_fog_coef = 1;

    fx_post_presets[] = {QEGVAR(fx_post,CC_Mars_Storm), QEGVAR(fx_post,FG_Storm), QEGVAR(fx_post,DB_20)};
    fx_post_coef = 1;

    fx_particle_presets[] = {QEGVAR(fx_particle,Branches), QEGVAR(fx_particle,Dust_35), QEGVAR(fx_particle,Dust_100)};
    fx_particle_coef = 1;
    
    fx_sound_presets[] = {QEGVAR(fx_sound,3D_WindLong),QEGVAR(fx_sound,3D_WindBursts)};
    fx_sound_coef = 1;
};

class PVAR(Sandstorm_Light) : PVAR(Sandstorm) {
    fx_post_presets[] = {QEGVAR(fx_post,CC_01), QEGVAR(fx_post,FG_Storm), QEGVAR(fx_post,DB_20)};
};


// DUST STORM
class PVAR(Duststorm_Green) : PVAR(Sandstorm) {
    fx_post_presets[] = {QEGVAR(fx_post,CC_Alias), QEGVAR(fx_post,FG_Storm), QEGVAR(fx_post,DB_20)};
};