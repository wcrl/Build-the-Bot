/* Danny Iacobacci | Watson Combat Robotics League | 2023-02-14
* This code is compatible with the "BitBlue" app
*
* Note: Pressing and holding does NOT function properly. This is a design conflict in the 
* BitBlue application. Instead, pressing the button once will trigger an action. Pressing
* the button again will end that action.
* 
* Controls:
* Forward Arrow: Move Bot Forward
* Back Arrow: Move Bot in Reverse
* Left Arrow: Move Bot to the Left
* Right Arrow: Move Bot to the Right
* A: Competition Attachment at Low Speed (Defined Below)
* X: Competition Attachment at High Speed (Defined Below)
* B: Not Used
* Y: Not Used
* Start: Not Used
* Select: Not Used
*/

//Software Serial for BT Control Setup and Variable Declarations
#include <SoftwareSerial.h>
SoftwareSerial BTserial(0, 1);
char lastInput;

//Servo initialization for BLDC motors
#include <Servo.h>  //Runs the PWM for the ESC
Servo ESC;          // Create servo object to control the ESC

//Change these to modify your BLDC speed
#define BLDC1_Speed_Low 35
#define BLDC1_Speed_High 70

//Drive motor declarations
#include <SparkFun_TB6612.h>  // Motor Driver Library provided by Sparkfun

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

//Toggles for button presses. Turns on with the first press, turns off with the second press
bool forwardCheck = true;
bool reverseCheck = true;
bool rightCheck = true;
bool leftCheck = true;
bool ca1CheckLow = true;
bool ca1CheckHigh = true;

void setup() {
  Serial.begin(9600);
  BTserial.begin(9600);       // make sure your Serial Monitor is also set at this baud rate.  //(Baudrate, rx,tx) Enter baudrate of your bluetooth. Connect bluetooth on Bluetooth port present on evive (in Dabble Library Example).
  ESC.attach(5, 1000, 2000);  // Initializes the ESC  ---- Pin 5 = ESC A; Pin 6 = ESC B
  ESC.write(0);               // Sets the speed to 0
}

void loop() {
  //Motion Control

  //Checks to see if the BT serial is available, and if it is, takes the lastInput from the buffer
  if (BTserial.available()) {
    lastInput = BTserial.read();
    Serial.println(lastInput);
    delay(5);
  }

  if (lastInput == 'F')  //Move forward
  {
    if (forwardCheck) {
      L_Wheel.drive(255);
      R_Wheel.drive(-255);
      forwardCheck = false;  //Switches the toggle
      lastInput = "";        //Resets the last input to not get stuck repeatedly toggling on/off
    } else {
      L_Wheel.drive(0);
      R_Wheel.drive(0);
      forwardCheck = true;
      lastInput = "";
    }
  } else if (lastInput == 'B')  //Move backward
  {
    if (reverseCheck) {
      L_Wheel.drive(-255);
      R_Wheel.drive(255);
      reverseCheck = false;
      lastInput = "";
    } else {
      L_Wheel.drive(0);
      R_Wheel.drive(0);
      reverseCheck = true;
      lastInput = "";
    }
  } else if (lastInput == 'L') {
    if (leftCheck) {
      L_Wheel.drive(-255);
      R_Wheel.drive(-255);
      leftCheck = false;
      lastInput = "";
    } else {
      L_Wheel.drive(0);
      R_Wheel.drive(0);
      leftCheck = true;
      lastInput = "";
    }
  } else if (lastInput == 'R') {
    if (rightCheck) {
      L_Wheel.drive(255);
      R_Wheel.drive(255);
      rightCheck = false;
      lastInput = "";
    } else {
      L_Wheel.drive(0);
      R_Wheel.drive(0);
      rightCheck = true;
      lastInput = "";
    }
  }

  //Competition Attachment(Weapon) Control
  if (lastInput == 'A')  //Competiton Attachment on low speed
  {
    if (ca1CheckLow) {
      ESC.write(BLDC1_Speed_Low);
      ca1CheckLow = false;
      lastInput = "";
    } else {
      ESC.write(0);
      ca1CheckLow = true;
      lastInput = "";
    }
  }
  if (lastInput == 'X')  //Competiton Attachment on High speed
  {
    if (ca1CheckHigh) {
      ESC.write(BLDC1_Speed_High);
      ca1CheckHigh = false;
      lastInput = "";
    } else {
      ESC.write(0);
      ca1CheckHigh = true;
      lastInput = "";
    }
  }
}
