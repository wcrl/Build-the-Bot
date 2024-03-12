#include <Servo.h>
#include <Dabble.h>
Servo myservoA;  // create servo object to control a servo
Servo myservoB;  // create servo object to control a servo

#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE

void setup() {
  Serial.begin(250000);       // make sure your Serial Monitor is also set at this baud rate.
  Dabble.begin(9600, 0, 1);   //(Baudrate, rx,tx) Enter baudrate of your bluetooth. Connect bluetooth on Bluetooth port present on evive (in Dabble Library Example).
  myservoA.attach(5, 1000, 2000);  // Initializes the servo  ---- Pin 5 = servo A;
  myservoB.attach(6, 1000, 2000);  // Initializes the servo  ---- Pin 6 = servo B;
  myservoA.write(180);              // tell servo to go to position in variable 'pos'
  myservoB.write(0);              // tell servo to go to position in variable 'pos'
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
}
