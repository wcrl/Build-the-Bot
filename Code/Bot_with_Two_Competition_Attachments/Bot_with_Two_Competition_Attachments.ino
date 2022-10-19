/*
    This example code was authored and/or compiled by the Watson Combat Robotics League for use on the Build-The-Bot Platform.
    This code is open source as per the MIT license found on the WCRL Github Page (https://github.com/wcrl/Build-the-Bot/blob/eadc81d94e1f041c1e13751ea7d3190f495dc393/LICENSE)
    Last Revised: 2022-10-18
*/

#include <Dabble.h>
/*
   This code utilizes the Dabble Library for bluetooth control of the robot.
   However, a modification must be made to the library to allow for hardware serial instead of software serial.
   1. Download the Dabble library via the Arduino IDE
   1. Open the Dabble.cpp file and change "Serial<#>.begin" to "Serial.begin"
   2. In the same .cpp file change "DabbleSerial=&Serial<#>" to "DabbleSerial=&Serial"
   3. NOTE: While Dabble bluetooth connection is active code may not be uploaded to the arduino
*/

#include <Servo.h>   //Runs the PWM for the ESC
Servo ESC1;          // Create servo object to control the ESC1
Servo ESC2;          // Create servo object to control the ESC2

#include <SparkFun_TB6612.h> // Motor Driver Library provided by Sparkfun

//Left Wheel is Motor A on the PCB
#define L_Wheel_in1 A5  //A4
#define L_Wheel_in2 A4  //A5
#define L_Wheel_PWM 11  //D11

//Left Wheel is Motor B on the PCB
#define R_Wheel_in1 4   //D4
#define R_Wheel_in2 8   //D8
#define R_Wheel_PWM 10  //D10

const int motor_offset = -1;
#define STBY 2
Motor L_Wheel(L_Wheel_in1, L_Wheel_in2, L_Wheel_PWM, motor_offset, STBY);
Motor R_Wheel(R_Wheel_in1, R_Wheel_in2, R_Wheel_PWM, motor_offset, STBY);

#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE


void setup() {

  Serial.begin(250000);       // make sure your Serial Monitor is also set at this baud rate.
  Dabble.begin(9600, 0, 1);   //(Baudrate, rx,tx) Enter baudrate of your bluetooth. Connect bluetooth on Bluetooth port present on evive (in Dabble Library Example).
  ESC1.attach(5, 1000, 2000);  // D4 
  ESC1.write(0);               // Sets the speed to 0
  ESC2.attach(6,1000,2000);     // D6
  ESC2.write(0);               // Sets speed to 0
}

void loop() {
  Dabble.processInput();      //this function is used to refresh data obtained from smartphone. Hence calling this function is mandatory in order to get data properly from your mobile.

  //Motion Control
  if (GamePad.isUpPressed())  //Move forward
  {
    L_Wheel.drive(255);
    R_Wheel.drive(-255);
  }
  else if (GamePad.isDownPressed()) //Move backward
  {
    L_Wheel.drive(-255);
    R_Wheel.drive(255);
  }
  else if (GamePad.isLeftPressed()) { //Move left
    L_Wheel.drive(-255);
    R_Wheel.drive(-255);
  }
  else if (GamePad.isRightPressed()) { //Move right
    L_Wheel.drive(255);
    R_Wheel.drive(255);
  }
  else {  //Idle
    L_Wheel.drive(0);
    R_Wheel.drive(0);
  }

  //Competition Attachment (Weapon) Control
  
  if (GamePad.isTrianglePressed())  //Start up Competition attachments. Low speed mode
  {
    ESC1.write(45);
    ESC2.write(45);
    Serial.print("Triangle");
  }
  if (GamePad.isCirclePressed())  //Increases the speed of the competition attachments. High speed mode
  {
    ESC1.write(70);
    ESC2.write(70);
    Serial.print("Circle");
  }
  if (GamePad.isCrossPressed()) //Shuts off the competition attachments
  {
    ESC1.write(0);
    ESC2.write(0);
    Serial.print("Cross");
  }

  if (GamePad.isStartPressed()) //Idle
  {

    Serial.print("Start");
    delay(100);
  }

  delay(100);

}
