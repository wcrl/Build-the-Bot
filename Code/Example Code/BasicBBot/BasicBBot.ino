/* This code is example for the Watson Combat Robotics League Robot
 *  Robot 1
   Code Written by: Zev Blumenthal
   Code Written: 10/01/2021
   Last Edit: 10/13/2021

   In order for this code to work, you must edit the dabble to set the serial to hardware serial.
   To this edit Dabble.cpp and set all Serial#.begin to Serial.begin. and DabbleSerial=&Serial# to DabbleSerial=&Serial
*/

#include <Servo.h>   //Runs the PWM for the ESC
Servo ESC;          // create servo object to control the ESC

#include <SparkFun_TB6612.h> // Motor Driver Library provided by Sparkfun
#define L_Wheel_in1 8 //D8
#define L_Wheel_in2 7 //D7
#define L_Wheel_PWM 11 //D
#define R_Wheel_in1 6 //D6
#define R_Wheel_in2 5 //D5
#define R_Wheel_PWM 10 //D10
const int motor_offset = -1;
#define STBY 4
Motor L_Wheel(L_Wheel_in1, L_Wheel_in2, L_Wheel_PWM, motor_offset, STBY);
Motor R_Wheel(R_Wheel_in1, R_Wheel_in2, R_Wheel_PWM, motor_offset, STBY);


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
