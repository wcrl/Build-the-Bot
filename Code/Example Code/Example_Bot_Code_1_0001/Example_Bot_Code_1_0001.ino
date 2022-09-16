
#include <SoftwareSerial.h>
SoftwareSerial HM10(2, 3); // RX = 2, TX = 3
char appData;  
String inData = "";
char Joystick[17];
  int j =0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  Serial.println("HM10 serial started at 9600");
  HM10.begin(9600); // set HM10 serial at 9600 baud rate
  pinMode(13, OUTPUT); // onboard LED
  digitalWrite(13, LOW); // switch OFF LED
}

void loop() {


  // put your main code here, to run repeatedly:
    HM10.listen();  // listen the HM10 port
//  while (HM10.available() > 0) {   // if HM10 sends something then read
//          Joystick_readL();       
//       }

  if (HM10.available() > 0) && HM10.read() =){
          Joystick_readL(); 
      }else if (HM10.available() > 0){
        appData = HM10.read();
        Serial.print(appData);
        Serial.print('\n');
      }else{}
      
 
  
}//loop 
void Joystick_readL() {
  //Serial.print("FUNCTION");
  Joystick[j] = HM10.read();
      j = j+1;
      if(j==14){
        Serial.print ("Joystick Value: ");
        Serial.print("L");
        for (j = 0; j < 15; j++ ) {
          Serial.print( Joystick[j]);
          }
        //Serial.print(Joystick);
        Serial.print('\n');
         j=0;
      }

}
    //Serial.write('\n');

//    if (HM10.read() == 'L') {           // Read user input if available.
//        for (j = 0; j < 15; j++ ) {
//          appData = HM10.read();
//        //Joystick[j] = appData;
//        Serial.write(appData);
//   }
//   //j=0;
//      Serial.write('\n');
//      Serial.print ("Joystick Value: ");
//      
//      
////      for (j = 0; j < 15; j++ ) {
////        Serial.print( char(Joystick[j]));
////   } 
////   j=0;
//  }
  
