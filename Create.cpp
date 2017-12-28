/*
  Create.cpp - Create library for Mobile Robot - implementation
  Copyright (c) 2017 Liz Miller.  All rights reserved.
*/

// include core Wiring API
#include "WProgram.h"

// include this library's description file
#include "Create.h"

// include description files for other libraries used (if any)
#include "HardwareSerial.h"


Create::Create(){

}

/* Public
 * begin: begin the robot
 */
void Create::begin(){
  initMotors();
  //**TODO: initHand();
}

/* Public
 * Go: drive the motors at a given speed and direction
 * Negatitive #'s = backwards
 * Positive #'s = forwards
 * Left Turn: Left = Negative, Right = Positive 
 * Right Turn: Left = Positive, Right = Negative
 * Zero's = Stop
 * If duration is set to zero then the motors will run continuously
 * If duration is greater than zero the motors will run for that duration 
 */
void Create::go(int speedLeft,int speedRight, int duration){
  emableMotors();
  autoMotors(speedLeft, speedRight);
  while(duration > 0){
    delay(duration);
    stop();
  }
}

/* Public
 * stop: Stops the motors
 * Must be wrapped in a while loop to hold the stop
 */
void Create::stop(bool isDisabled){
  autoMotors(0,0);
  if (isDisabled){
    disableMotors();
  }
}

/* Public
 * getAnalog: Reads the value of an Analog Sensor
 */
int Create::getAnalog(int pin){
  return analogRead(pin);
}

/* Public
 * getDigital: Reads the value of a Digital Sensor
 */
int Create::getDigital(int pin){
  return digitalRead(pin);
}

/* Public
 * writeAnalog: Writes the value to a given Analog Device
 */
void Create::writeAnalog(int pin, int value){
  analogWrite(pin, value);
}

/* Public
 * writeDigital: Writes the value to a given Digital Device
 */
void Create::writeDigital(int pin, int value){
  digitalWrite(pin, value);
}


/* Public
 * getIRArray: gets the reading from a given IR pin
 */
int Create::getIRArray(int pin){
  //possible parameters: IR_1, IR_2, IR_3
  int IRPin;
  switch(pin){
    case 0:
      IRPin=LIR;
      break;
    case 1:
      IRPin=RIR;
      break;
  }

  return analogRead(IRPin);
}

/* Private
 * initMotors: Initializes the motors
 */
void Create::initMotors(){
    pinMode(ENL, OUTPUT);
    pinMode(INL1, OUTPUT);
    pinMode(INL2, OUTPUT);
  
    pinMode(ENR, OUTPUT);
    pinMode(INR1, OUTPUT);
    pinMode(INR2, OUTPUT);

    enableMotors();
}

/* Private
 * enableMotors: enables the EN pins
 */
void Create::enableMotors(){
  digitalWrite(EN1, HIGH);
  digitalWrite(EN2, HIGH);
}

/* Private
 * disableMotors: disables the EN pins
 */
void Create::disableMotors(){
  digitalWrite(EN1, LOW);
  digitalWrite(EN2, LOW);
}

/* Private
 * Controls the motors (no duration)
 * speedL and speedR support both pos and neg values
 *  -255 to 0 (backwards) and 0 to +255(forwards)
 */
void Create::autoMotors(int speedL, int speedR){
  //speed is negative (reverse direction)
  if(speedL < 0 && speedR < 0){
    Serial.println("back up");
    digitalWrite(INL1, LOW);
    digitalWrite(INL2, HIGH);
    analogWrite(ENL, speedL);
  
    digitalWrite(INR1, LOW);
    digitalWrite(INR2, HIGH);
    analogWrite(ENR, speedR);
  }
  else if (speedL > 0 && speedR > 0){ //move forward
    Serial.println("forward");
    digitalWrite(INL1, HIGH);
    digitalWrite(INL2, LOW);
    analogWrite(ENL, speedL);
    
    digitalWrite(INR1, HIGH);
    digitalWrite(INR2, LOW);
    analogWrite(ENR, speedR);
  }
  else if (speedL < speedR){ //left turn
    Serial.println("right turn");
    digitalWrite(INL1, LOW);
    digitalWrite(INL2, HIGH);
    analogWrite(ENL, speedL);
    
    digitalWrite(INR1, HIGH);
    digitalWrite(INR2, LOW);
    analogWrite(ENR,speedR);
  }
  else if (speedR < speedL){ //right turn
    Serial.println("left turn");
    digitalWrite(INL1, HIGH);
    digitalWrite(INL2, LOW);
    analogWrite(ENL, speedL);
    
    digitalWrite(INR1, LOW);
    digitalWrite(INR2, HIGH);
    analogWrite(ENR,speedR);
    
  }
  else if (speedL == 0 && speedR == 0){
    digitalWrite(INL1, LOW);
    digitalWrite(INL2, LOW);
    analogWrite(ENL, 0);
  
    digitalWrite(INR1, LOW);
    digitalWrite(INR2, LOW);
    analogWrite(ENR, 0);
  }

}

Create robot=Create();