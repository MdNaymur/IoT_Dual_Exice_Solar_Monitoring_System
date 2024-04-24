#include <Servo.h>

Servo horizontalServo;
Servo verticalServo;

int ldrPin1 = A0; 
int ldrPin2 = A1;
int ldrPin3 = A2;
int ldrPin4 = A3;

int ldr1Value, ldr2Value, ldr3Value, ldr4Value;
int horizontalAngle = 90;
int verticalAngle = 90;

void setup() {
  horizontalServo.attach(9); 
  verticalServo.attach(10); 
}

void loop() {
  
  ldr1Value = analogRead(ldrPin1);
  ldr2Value = analogRead(ldrPin2);
  ldr3Value = analogRead(ldrPin3);
  ldr4Value = analogRead(ldrPin4);

  // Calculate the difference between LDR values to adjust the servo angles for each servo
  int horizontalDiff1p = ldr1Value - ldr2Value;
   int horizontalDiff1n = ldr2Value - ldr1Value;
  int verticalDiffp = ldr3Value - ldr4Value;
 int verticalDiffn = ldr4Value - ldr3Value;
 
if(horizontalDiff1p>20){
  horizontalAngle=map(horizontalDiff1p,0,100,0,120);
  horizontalServo.write(horizontalAngle);
}
if(horizontalDiff1n>20){
  horizontalAngle=map(horizontalDiff1n,0,100,0,-120);
  horizontalServo.write(horizontalAngle);
}
if(verticalDiffp>20){
  verticalAngle=map(verticalDiffp,0,100,0,120);
  verticalServo.write(verticalAngle);
}
if(verticalDiffn>20){
  verticalAngle=map(verticalDiffn,0,100,0,-120);
  verticalServo.write(verticalAngle);
}

  delay(100); // Delay for stability
}
