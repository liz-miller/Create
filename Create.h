/*
  Create.h - Create library for Wiring - description
  Copyright (c) 2017 Liz Miller.  All rights reserved.
*/

// ensure this library description is only included once
#ifndef Create_h
#define Create_h

// include types & constants of Wiring core API
#include "WConstants.h"

//motors
//left motors
#define ENL 10
#define INL1 9
#define INL2 8
//right motors
#define ENR 5
#define INR1 7
#define INR2 6

// infrared sensors
#define LI1 A1
#define RIR A2

//digital pins

#define DP0 0
#define DP1 1
#define DP2 2
#define DP3 3
#define DP4 4
#define DP11 11
#define DP12 12

//#define DEBUG
//#define DEBUG_SPEED

/*struct SpeedPair{
  int speed1;
  int speed2;
};*/

class Create {
  public:
    Create();
    void begin();
    void go(int speedLeft,int speedRight, int duration);
    void stop(bool isDisabled);
    
    int getIRArray(int pin);
    int getAnalog(int pin);
    int getDigital(int pin);
    void writeAnalog(int pin, int value);
    void writeDigital(int pin, int value);
  
  private:
    void initMotors();
    void enableMotors();
    void disableMotors();
    void autoMotors(int speedL, int speedR);
   

};

extern Create robot;
//extern void stopServo();
#endif

