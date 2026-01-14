
// Twigs
class GVAR(Branches) : GVAR(DEFAULT)
{
    particleShape = "\A3\data_f\ParticleEffects\Hit_Leaves\Sticks_Green"; 
    particleFSNtieth = 1;
    particleFSIndex = 1;
    particleFSFrameCount = 1;
    particleFSLoop = 1;

    animationName = "";
    particleType = "SpaceObject";
    timerPeriod = 1;
    lifeTime = 27;

    position[] = {-10, -10, 0.5};
    moveVelocity[] =  {-15,-15,10};

    rotationVelocity = 1;
    weight = 0.000001;
    volume = 0.001;
    rubbing = 0.1;

    size[] = {0.2};

    color[] = {{0.68, 0.68, 0.68, 1}};

    animationSpeed[] = {1.5, 1};	

    randomDirectionPeriod = 13;
    randomDirectionIntensity = 7; 

    onTimerScript = "";
    beforeDestroyScript = "";

    angle = 0;

    onSurface = "false";
	bounceOnSurface = 0;

	emissiveColor[] = {{0,0,0,0}};

	// setParticleRandom
	sizeVar = 3;
    lifeTimeVar = 0;
    positionVar[] = {20, 20, 5};
    moveVelocityVar[] = {30, 30, 10};
   	rotationVelocityVar = 2;
    colorVar[] = {0, 0, 0, 0.1};	
    angleVar = 100;
  	bounceOnSurfaceVar = 1;

	// setParticleCircle
   	circleRadius = 75;
	circleVelocity[] = {-2, -2, 1};

	// setDropInterval
	interval = 0.05;					    // interval of particle's creation
	// 0.01+random 0.1
	intervalMin = 1;
};