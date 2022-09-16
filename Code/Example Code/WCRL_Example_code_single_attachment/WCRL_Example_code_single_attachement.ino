/* This code is example for the Watson Combat Robotics League Robot
 *  Robot 1
   Code Written by: Zev Blumenthal
   Code Written: 10/01/2021
   Last Edit: 11/25/2021

   In order for this code to work, you must edit the dabble to set the serial to hardware serial.
   To this edit Dabble.cpp and set all Serial#.begin to Serial.begin. and DabbleSerial=&Serial# to DabbleSerial=&Serial
   Please reference the FAQ for instructions for how to do this. The file may also be provided
*/

#include <Servo.h>   //Runs the PWM for the ESC
Servo ESC;          // create servo object to control the ESC

#include <SparkFun_TB6612.h> // Motor Driver Library provided by Sparkfun: https://github.com/sparkfun/SparkFun_TB6612FNG_Arduino_Library/archive/master.zip

// The following is pin definitions represent the connections from the motor driver to the Arduino
// you may need to adjust these if you did not connect the arduino the same as the provided schematic
#define L_Wheel_in1 8 // D8 Change the integer to the value of the digital pin you are using
#define L_Wheel_in2 7 // D7
#define L_Wheel_PWM 11 // D11 if changed, it must be either pins 3, 5, 6, 9, 10, or 11 as they are the only pins that support PWM
#define R_Wheel_in1 6 // D6
#define R_Wheel_in2 5 // D5
#define R_Wheel_PWM 10 // D10 - if changed, it must be either pins 3, 5, 6, 9, 10, or 11 as they are the only pins that support PWM
#define STBY 4
const int motor_offset_R = -1;  // this offset allows you to change the direction a motor (should be 1 or 0)
const int motor_offset_L = -1;  // this offset allows you to change the direction a motor (should be 1 or 0)


Motor L_Wheel(L_Wheel_in1, L_Wheel_in2, L_Wheel_PWM, motor_offset_L, STBY);
Motor R_Wheel(R_Wheel_in1, R_Wheel_in2, R_Wheel_PWM, motor_offset_R, STBY);

// The following 3 lines are initializzations of the dabble app
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(250000);      // make sure your Serial Monitor is also set at this baud rate.
  Dabble.begin(9600, 0,1);      //(Baudrate, rx,tx) Enter baudrate of your bluetooth.Connect bluetooth on Bluetooth port present on evive.
  ESC.attach(9, 1000,2000);  // Initializes the ESC
    ESC.write(0);             // Sets the speed to 0
}

void loop() {
  // put your main code here, to run repeatedly:
  Dabble.processInput();             //this function is used to refresh data obtained from smartphone.Hence calling this function is mandatory in order to get data properly from your mobile.
  //Serial.print("KeyPressed: ");
  if (GamePad.isUpPressed())
  {
    L_Wheel.drive(255);
    R_Wheel.drive(-255);
  }
  else if (GamePad.isDownPressed())
  {
    L_Wheel.drive(-255);
    R_Wheel.drive(255);
  }
  else if (GamePad.isLeftPressed()){
    L_Wheel.drive(-255);
    R_Wheel.drive(-255);
    }
  else if (GamePad.isRightPressed()){
    L_Wheel.drive(255);
    R_Wheel.drive(255);
  }
  else {
    L_Wheel.drive(0);
    R_Wheel.drive(0);
  }
   if (GamePad.isTrianglePressed())
  {
    ESC.write(25);
    Serial.print("Triangle");
  }
  if (GamePad.isCirclePressed())
  {
    ESC.write(50);
    Serial.print("Circle");
  }
  if (GamePad.isCrossPressed())
  {
        ESC.write(0);
    Serial.print("Cross");
  }
  
  if (GamePad.isStartPressed())
  {
    
    Serial.print("Start");
    delay(100);
  }
  
  delay(100);
  
}
