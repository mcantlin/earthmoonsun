#include <AccelStepper.h>

#include <MultiStepper.h>

 
AccelStepper stepper1(AccelStepper::DRIVER, 11, 10); 
AccelStepper stepper2(AccelStepper::DRIVER, 9, 8); // works great
AccelStepper stepper3(AccelStepper::DRIVER, 6, 7);

long pos = 3600;
void setup() {
  stepper1.setMaxSpeed(5000);
  stepper2.setMaxSpeed(7000);
  stepper3.setMaxSpeed(7000);
}

void loop() {
  // put your main code here, to run repeatedly:

  stepper1.setSpeed(130);//0.44rps ==> ~2.27 second moon cycle
  stepper2.setSpeed(110);//0.032rps ==> ~31 second year
  stepper3.setSpeed(6000);//11.8rps ==> ~0.084 second day
  
  stepper1.runSpeed();
  stepper2.runSpeed();
  stepper3.runSpeed();

}
