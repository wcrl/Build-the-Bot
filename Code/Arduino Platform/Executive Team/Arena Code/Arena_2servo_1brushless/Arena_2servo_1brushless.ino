// This is the code for the WCRL Arena by Luke Riddoch 03/15/24
// Modified from Bot_with_Two_Competition_Attachments.ino linked below
// https://github.com/wcrl/Build-the-Bot/blob/19f6ca3007785384c22e985b2c41b191f8b2961c/Code/Arduino%20Platform/Bot%20Control%20-%20Compatible%20with%20Dabble%20Application/Bot_with_Two_Competition_Attachments/Bot_with_Two_Competition_Attachments.ino


// Features:
//      (2x) servo control
//      (1x) esc brushless motor

// EXPLANATION of ESC adaptation to Build-A-Bot BCB:
// The ESC was assigned to pin 10 and can be accessed using the PWMB connection for the DC motor driver
// This was done because there is NOT any DC motors so the Build-A-Bot PCB could accomodate the 3rd digital pin here.
// Use a continuity test between locations on the board and pins on the arduino to verify

#include <Servo.h>
#include <Dabble.h>

Servo myservoA;  // create servo object to control a servo
Servo myservoB;  // create servo object to control a servo
Servo ESC;          // Create servo object to control the ESC

#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE

void setup() {
  Serial.begin(250000);       // make sure your Serial Monitor is also set at this baud rate.
  Dabble.begin(9600, 0, 1);   //(Baudrate, rx,tx) Enter baudrate of your bluetooth. Connect bluetooth on Bluetooth port present on evive (in Dabble Library Example).
  myservoA.attach(5, 1000, 2000);  // Initializes the servo  ---- Pin 5 = servo A;
  myservoB.attach(6, 1000, 2000);  // Initializes the servo  ---- Pin 6 = servo B;
  myservoA.write(180);              // tell servo to go to position in variable 'pos'
  myservoB.write(0);              // tell servo to go to position in variable 'pos'
  ESC.attach(10, 1000, 2000);  // Initializes the ESC  ---- Pin 10 = ESC A;
  ESC.write(0);               // Sets the speed to 0

}

void loop() {
  Dabble.processInput();  
  if (GamePad.isTrianglePressed()) {
    myservoA.write(180);              // tell servo to go to position in variable 'pos'
    delay(100);                       // waits 100ms for the servo to reach the position
  }
  if (GamePad.isSquarePressed()) {
    myservoA.write(90);              // tell servo to go to position in variable 'pos'
    delay(100);                       // waits 100ms for the servo to reach the position
  }
  if (GamePad.isCirclePressed()) {
    myservoB.write(180);              // tell servo to go to position in variable 'pos'
    delay(100);                       // waits 100ms for the servo to reach the position
  }
  if (GamePad.isCrossPressed()) {
    myservoB.write(0);              // tell servo to go to position in variable 'pos'
    delay(100);                       // waits 100ms for the servo to reach the position
  }

  if (GamePad.isUpPressed())  //Start up the Arena brushless motor attachment
  {
    ESC.write(35);
    Serial.print("Up");
  }
  if (GamePad.isRightPressed())  //Increase the speed of the Arena brushless motor attachment
  {
    ESC.write(60);
    Serial.print("Right");
  }
  if (GamePad.isDownPressed()) //Shut off the Arena brushless motor attachment
  {
    ESC.write(0);
    Serial.print("Down");
  }

  if (GamePad.isStartPressed()) //Idle
  {

    Serial.print("Start");
    delay(100);
  }

  delay(100);

}
