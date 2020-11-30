#include <Stepper.h>
#include <Servo.h>

const float STEPS_PER_REV = 32;
const float GEAR_RED = 64;
const float STEPS_PER_OUT_REV = STEPS_PER_REV * GEAR_RED; //Steps per Revolution

int StepsRequired, pos = 78;
int trig = 4;
int echo = 5; 
float duration, distance;

Stepper steppermotor(STEPS_PER_REV, 8, 10, 9, 12);
Servo MicroServo;

void setup() {
MicroServo.attach(3);
Serial.begin(9600);
MicroServo.write(pos);
pinMode(4, OUTPUT);
pinMode(5, INPUT);
}

void loop() {

  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  duration = pulseIn(echo,HIGH); // duration for pulse to reach detector (in microseconds)
  distance = 1000.0*(343.0*(duration/2.0))/1000000.0; // DISTANCE IN MM

  Serial.print(distance);
  Serial.println();

  if (distance > 120){
    StepsRequired = STEPS_PER_OUT_REV*0.1;
    steppermotor.setSpeed(900);
    steppermotor.step(StepsRequired);
  }

  if (distance <= 120){
    MicroServo.write(40);
    delay(1000);

    StepsRequired = STEPS_PER_OUT_REV*0.80;
    steppermotor.setSpeed(800);
    steppermotor.step(StepsRequired);

    delay(500);
    MicroServo.write(pos);
    delay(1000);
    
    StepsRequired = STEPS_PER_OUT_REV*0.80;
    steppermotor.setSpeed(900);
    steppermotor.step(StepsRequired);

    delay(500);
    MicroServo.write(140);
    delay(1000);

    StepsRequired = STEPS_PER_OUT_REV*0.58;
    steppermotor.setSpeed(800);
    steppermotor.step(StepsRequired);

    delay(500);
    MicroServo.write(pos);
    delay(1000);
    
    StepsRequired = STEPS_PER_OUT_REV*1.2;
    steppermotor.setSpeed(900);
    steppermotor.step(StepsRequired);

    delay(500);
    MicroServo.write(140);
    delay(1000);

    StepsRequired = STEPS_PER_OUT_REV*0.58;
    steppermotor.setSpeed(800);
    steppermotor.step(StepsRequired);

    delay(500);
    MicroServo.write(pos);
    delay(1000);

    StepsRequired = STEPS_PER_OUT_REV*0.80;
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

    StepsRequired = STEPS_PER_OUT_REV*3.875;
    steppermotor.setSpeed(900);
    steppermotor.step(StepsRequired);

    delay(10000);
  

  }


 
}
