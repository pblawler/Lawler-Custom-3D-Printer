/*
*			DropIn example sketch!
*
*	Pin connections:
*	-----------------------------
*	| Controller | uStepperS Lite|
*	|----------------------------|
*	|	Enable   |		D2		 |
*	|	Step     |		D3		 |
*	|	Dir      |		D4		 |
*	|	GND      |		GND		 |
*	------------------------------	
*/

#include <uStepperSLite.h>
uStepperSLite stepper;

//* @param[in]  mode               Default is normal mode. Pass the constant 
//772    *                                "DROPIN" to configure the uStepper S-lite to act as 
//773    *                                dropin compatible to the stepstick. Pass the 
//774    *                                constant "PID", to enable PID feature for 
//775    *                                regular movement functions, such as 
//776    *                                moveSteps() 
//777    * @param[in]  stepsPerRevolution   This parameter should be set to 
//778    *                                the steps/revolution which is 16 * steppper steps/revolution. 
//779    *                  For a 1.8deg stepper this is 16 * 200 = 3200. 
//780    *                  In Drop-in this number should be set to the microstep setting 
//781    *                  of the controller (e.g. 16). 
//782    * @param[in]  pTerm              The proportional coefficent of the PID 
//783    *                                controller 
//784    * @param[in]  iTerm              The integral coefficent of the PID 
//785    *                                controller 
//786    * @param[in]  dTerm              The differential coefficent of the PID 
//787    *                                controller 
//788    * @param[in]  setHome            When set to true, the encoder position is 
//789    *                  Reset. When set to false, the encoder 
//790    *                  position is not reset. 
//791    * @param[in]  invert             Inverts the motor direction for dropin 
//792    *                  feature. 0 = NOT invert, 1 = invert. 
//793    *                  this has no effect for other modes than dropin 
//794    * @param[in]  runCurrent         Sets the current (in percent) to use while motor is running. 
//795    * @param[in]  holdCurrent        Sets the current (in percent) to use while motor is NOT running 
//796    */ 
//797   void setup( uint8_t mode = NORMAL,  
//798         float stepsPerRevolution = 3200.0,  
//799         float pTerm = 0.75,  
//800         float iTerm = 3.0,  
//801         float dTerm = 0.0, 
//802         bool setHome = true, 
//803         uint8_t invert = 0, 
//804         uint8_t runCurrent = 50, 
//805         uint8_t holdCurrent = 30);   

void setup(void)
{
	stepper.setup(DROPIN,3200.0,800,150,3.5,true,1,110,15);
 //Must use uStepperS board even with uStepper S-lite physical board.  03/16/2020.
}

void loop() {
  // put your main code here, to run repeatedly:
  stepper.dropinCli();
}
