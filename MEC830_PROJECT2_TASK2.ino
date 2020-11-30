#include <Stepper.h>
#include <Servo.h>

const float STEPS_PER_REV = 32;
const float GEAR_RED = 64;
const float STEPS_PER_OUT_REV = STEPS_PER_REV * GEAR_RED; //Steps per Revolution

int StepsRequired, pos = 78;

Stepper steppermotor(STEPS_PER_REV, 8, 10, 9, 12);
Servo MicroServo;

void setup() {
MicroServo.attach(3);
Serial.begin(57600);
MicroServo.write(pos);
}

void loop() {

  StepsRequired = STEPS_PER_OUT_REV*4.65;
  steppermotor.setSpeed(900);
  steppermotor.step(StepsRequired);
  
  delay(500);
  MicroServo.write(140);
  delay(1000);

  StepsRequired = STEPS_PER_OUT_REV*0.53;
  steppermotor.setSpeed(800);
  steppermotor.step(StepsRequired);

  delay(500);
  MicroServo.write(pos);
  delay(1000);

  StepsRequired = STEPS_PER_OUT_REV*4.65;
  steppermotor.setSpeed(900);
  steppermotor.step(StepsRequired);
  
  delay(500);
  MicroServo.write(40);
  delay(1000);

  StepsRequired = STEPS_PER_OUT_REV*0.80;
  steppermotor.setSpeed(800);
  steppermotor.step(StepsRequired);
  
  delay(500);
  MicroServo.write(pos+4);
  delay(1000);

  StepsRequired = STEPS_PER_OUT_REV*4.65;
  steppermotor.setSpeed(900);
  steppermotor.step(StepsRequired);

  delay(10000);

}
