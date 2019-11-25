#include <Stepper.h>
  
  #define STEPS 2048 // the number of steps in one revolution of your motor (28BYJ-48)
  
  Stepper stepper(STEPS, 9, 11, 10, 12);
  Stepper stepperONE(STEPS, 1, 3, 2, 4);
  int cool = 0;
  
  void setup() {
  // nothing to do
  }
  void loop() {

    
 stepper.setSpeed(13); 
 //stepperONE.setSpeed(12); 
 stepper.step(2048); // do 2038 steps -- corresponds to one revolution in one minute
 //stepperONE.step(2038);
 delay(200); // wait for one second
    
    }
 
 
