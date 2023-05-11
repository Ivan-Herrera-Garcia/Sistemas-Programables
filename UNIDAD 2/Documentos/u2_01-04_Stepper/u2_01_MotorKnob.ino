/*
 * MotorKnob
 *
 * A stepper motor follows the turns of a potentiometer
 * (or other sensor) on analog input 0.
 *f
 * http://www.arduino.cc/en/Reference/Stepper
 * This example code is in the public domain.
 */

#include <Stepper.h>

// change this to the number of steps on your motor
#define STEPS 200

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
Stepper stepper(STEPS, 8, 9, 10, 11);

// the previous reading from the analog input
int previous = 0;
int potVal = 0;
int pVal = 0;

void setup() {
  // set the speed of the motor to 30 RPMs
  stepper.setSpeed(100);
}

void loop() {
  // get the sensor value
//  int val = analogRead(0);
  potVal = map(analogRead(A0),0,1024,0,500);
  if(potVal > pVal)
  {
    stepper.step(10);
    }
   if(potVal < pVal)
   {
    stepper.step(-10);
    }Serial
    pVal = potVal;
    Serial.println(pVal);

  /*
  // move a number of steps equal to the change in the
  // sensor reading
  stepper.step(val - previous);

  // remember the previous value of the sensor
  previous = val;*/
}
