class GVAR(SnowBurst) : GVAR(Dust)
{
	color[] = {
		{0.5,	 0.5, 	0.65, 	0.01}, 
		{0.5,	 0.6, 	0.65, 	0.03}, 
		{0.8,	0.95, 	1,    	0.07},
		{0.8,	0.95, 	1,    	0.10},
		{0.8,	0.95, 	1,    	0.07},
		{0.5,	 0.6, 	0.65, 	0.01}, 
		{0.5,	 0.6, 	0.65, 	0.00}
	};
};
class GVAR(SnowBurst_35) : GVAR(SnowBurst)
{
   	circleRadius = 35;
};
class GVAR(SnowBurst_50) : GVAR(SnowBurst)
{
   	circleRadius = 50;
};
class GVAR(SnowBurst_75) : GVAR(SnowBurst)
{
   	circleRadius = 75;
};


class GVAR(Snow) : GVAR(DEFAULT)
{
	interval = 0.001;
	intervalMin = 0.1;

	circleRadius = 5;
	circleVelocity[] = {2,2,5};
	particleFSNtieth = 1;
	particleFSIndex = 0;
	particleFSFrameCount = 1;
	particleFSLoop = 1;
	angleVar = 0;
	particleShape = "\A3\Data_f\cl_basic.p3d";
	particleType = "Billboard";
	timerPeriod = 1;
	lifeTime = 30;
	moveVelocity[] = {0,0,0};
	moveVelocityVar[] = {5,5,0};
	rotationVelocity = 0;
	weight = 3.0;
	volume = 1;
	rubbing = 1;
	size[] = {0.1};
	color[] = {{1,1,1,1},{1,1,1,0}};
	animationSpeed[] = {1};
	randomDirectionPeriod = 0;
	randomDirectionIntensity = 0;
	onTimerScript = "";
	beforeDestroyScript = "";
	lifeTimeVar = 0;
	position[] = {-10,-10,3};
	positionVar[] = {20,20,7};
	rotationVelocityVar = 0;
	sizeVar = 0.1;
	colorVar[] = {0,0,0,0};
	randomDirectionPeriodVar = 0;
	randomDirectionIntensityVar = 0;
	coreIntensity = 0;
	coreDistance = 0;
	damageTime = 0;
	damageType = "";
	angle = 0;

	coefSpeedHeli = 3;
	coefSpeed = 2;
	coefWind = 1.5;

	offsetHeight = 10;

};

class GVAR(Snow_25) : GVAR(Snow)
{
	circleRadius = 25;
};