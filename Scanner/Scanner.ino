#include <Servo.h>

int IR_read = A0; // analog pin to read infrared sensor
Servo pan;
Servo tilt;
int pan_pin = 9;
int tilt_pin = 10;

int start_pan = 0;
int start_tilt = 0;
int end_pan = 180;
int end_tilt = 180;
int pan_inc = 1;
int tilt_inc = 1;

int num_readings = 5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(IR_read, INPUT);
  pan.attach(pan_pin);
  tilt.attach(tilt_pin);
}

void loop() {
  for(int pan_ang = start_pan; pan_ang <= end_pan; pan_ang += pan_inc){
    pan.write(pan_ang);
    for(int tilt_ang = start_tilt; tilt_ang <= end_tilt; tilt_ang += tilt_inc){
      // move to next position
      tilt.write(tilt_ang);
      Serial.print(pan_ang);
      Serial.print(",");
      Serial.print(tilt_ang);
      delay(15);
      // take several readings
      for(int i = 0; i < num_readings; i+=1){
        Serial.print(",");
        Serial.print(analogRead(IR_read));
        delay(15);
      }
      Serial.println();
    }
    pan_ang = pan_ang + pan_inc;
    pan.write(pan_ang);
    for(int tilt_ang = end_tilt; tilt_ang >= start_tilt; tilt_ang -= tilt_inc){
      // move to next position
      tilt.write(tilt_ang);
      Serial.print(pan_ang);
      Serial.print(",");
      Serial.print(tilt_ang);
      delay(15);
      // take several readings
      for(int i = 0; i < num_readings; i+=1){
        Serial.print(",");
        Serial.print(analogRead(IR_read));
        delay(15);
      }
      Serial.println();
    }
  }
}
