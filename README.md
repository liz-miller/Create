Arduino Library for Learn Robotics Create Robot
===========================================
This library is compatible with the Learn Robotics Create Robot (Presale launches in Spring 2018). 
Contact me if you'd like to beta test this robot kit.

**You must download the Arduino IDE from the [Arduino website](http://www.arduino.cc/en/main/software) before installing this library.**

## Wiring
The Create robot must be wired as follows:

### Motors:

- EN1 (left enable): 10
- IN1 (left input 1): 9
- IN2 (left input 2): 8
- EN2 (right enable): 5
- IN3 (right input 1): 7
- IN4 (right input 2): 6

### Infrared Line Trackers:

- IR1 (left IR): A0
- IR2 (right IR): A5

* More sensors to be added *

## Available Commands

Note: A *robot* object is already generated by the library. You **do not** need to create an instance of Create().

### Initialize
In the `setup()` method, you must call `robot.begin()` to initialize the robot.

### Move
`robot.go(int x,int y, int z);`
*Turns on the motors*
Where x = left speed, y = right speed, z = duration
x & y > 0 : forward
x & y < 0 : backward
x > 0 & y <=0 : right turn
x <=0 & y > 0 : left turn
x & y = 0 : stop
z > 0 : robot runs for specified duration
z <= 0 : robot runs UNLIMITED duration (must be stopped using another method)

### Stop
`robot.stop(bool isDisabled);`
When isDisabled is TRUE the stop method will disable the motors. 
The motors are automatically re-enabled in the `robot.go(...)` method.

### Sensors 
You can use the build-in Arduino `digitalRead()`, `analogRead()`, `digitalWrite()`, and `analogWrite()` methods. 
For ease, we've also included robot-specific methods that you can use to read and write values from the sensors.

#### IR Sensors (Line Trackers)
`int getIRArray(int pin);`
Get the value from an IR Sensor using pre-defined IR pins (LIR = left IR or RIR = right IR)

`int getAnalog(int pin);`
Get the value from any Analog Pin

`int getDigital(int pin);`
Get the value from any Digital Pin

 `void writeAnalog(int pin, int value);`
 Write a given value to an Analog Pin

`void writeDigital(int pin, int value);`
Write a given value to a Digital Pin

### Future Contributions
Contact me (Liz) if you have contribution requests or features you'd like added to the Create robot. 
I will be contributing to this library to add more features and sensors, but it's a starting framework to a simple Arduino-compatible robot.


