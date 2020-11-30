#include <IRremote.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

#include <Stepper.h>
#include <Servo.h>

const float STEPS_PER_REV = 32;
const float GEAR_RED = 64;
const float STEPS_PER_OUT_REV = STEPS_PER_REV * GEAR_RED; //Steps per Revolution

int StepsRequired, repeat, pos = 78;
const int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);   
decode_results results;

Stepper steppermotor(STEPS_PER_REV, 8, 10, 9, 12);
Servo MicroServo;


void setup() {

MicroServo.attach(3);
Serial.begin(9600);
MicroServo.write(pos);
irrecv.enableIRIn();

}

void loop() {

  if (irrecv.decode(&results)){
    switch(results.value){
      case 0xFF629D:
      repeat = 1;
      break;

      case 0xFFA857:
      repeat = 0;
      break;

      case 0xFFC23D:
      pos = pos+10;
      delay(200);
      MicroServo.write(pos);
      delay(200);
      break;

      case 0xFF22DD:
      pos = pos-10;
      delay(200);
      MicroServo.write(pos);
      delay(200);
      break;

    }
    irrecv.resume();
  }

  if (repeat == 1){
    StepsRequired = STEPS_PER_OUT_REV*0.2;
    steppermotor.setSpeed(900);
    steppermotor.step(StepsRequired);
  }
  

}
