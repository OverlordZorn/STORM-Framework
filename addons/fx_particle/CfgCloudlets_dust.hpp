class GVAR(Dust) : GVAR(DEFAULT)
{
    particleShape = "\A3\data_f\cl_basic";
    particleFSNtieth = 1;
    particleFSIndex = 0;
    particleFSFrameCount = 1;
    particleFSLoop = 1;

    animationName = "";
    particleType = "Billboard";
    timerPeriod = 1;
    lifeTime = 30;

    position[] = {-5, -5, -5};
    moveVelocity[] =  {-5,-5,-5};

    rotationVelocity = 3;
    weight = 1.30;
    volume = 1.00;
    rubbing = 0.013;

    size[] = {0,1,3,5,7,5,2};

    color[] = {
		{0.65, 0.5, 0.5, 0.01}, 
		{0.65, 0.6, 0.5, 0.05}, 
		{1,   0.95, 0.8, 0.08},
		{1,   0.95, 0.8, 0.10},
		{1,   0.95, 0.8, 0.08},
		{0.65, 0.6, 0.5, 0.05}, 
		{0.65, 0.6, 0.5, 0.00}
	};

    animationSpeed[] = {0.08};	

    randomDirectionPeriod = 1;
    randomDirectionIntensity = 0; 

    onTimerScript = "";
    beforeDestroyScript = "";

    angle = 1;

    onSurface = "false";

	// setParticleRandom
    lifeTimeVar = 10;
    positionVar[] = {10, 10, 15};
    moveVelocityVar[] = {10, 10, 10};
   	rotationVelocityVar = 1;
	sizeVar = 0;
    colorVar[] = {0, 0, 0, 0.05};	
    angleVar = 360;

	bounceOnSurface = 1;
  	bounceOnSurfaceVar = 0.0;

	// setParticleCircle
   	circleRadius = 35;
	circleVelocity[] = {-3, -3, 2};

	// setDropInterval
	interval = 0.01;					    // interval of particle's creation
	// 0.01+random 0.1

	intervalMin = 2;

};


class GVAR(Dust_100) : GVAR(Dust)
{
   	circleRadius = 100;
};

class GVAR(Dust_50) : GVAR(Dust)
{
   	circleRadius = 50;
};

class GVAR(Dust_35) : GVAR(Dust)
{
   	circleRadius = 35;
};