# Arduino FAQ
## My Arduino Nano won’t program?

- This problem typically occurs when incorrect settings are selected in the arduino programmer. Here are some quick checks you can follow to debug.
   - Is your arduino plugged in (always gotta double check that one)
   - Check that the proper COM port is selected under tools(Tools->Ports). This will depend on your computer
   - Check that you are selecting the proper Arduino that you are using for the project. This can be done by going to Tools->Board: In most cases, this will be an Arduino nano
   - Check which bootloader you have selected; many of the cheaper Arduinos (especially Arduino Nanos) on the market use the “Old Bootloader.” This can be accessed in Tools->Processor

## My Arduino Nano is not recognized on Windows?
- This is most likely due to the purchase of an off brand Arduino. The most common fix is to check if your Arduino uses a CH430 programming chip on the bottom of your board as the interface between the computer and the programmer. This can be simply fixed by installing the proper drivers from this website.
  - To install extract the .zip file and double click the SETUP application, click yes on the pop-up, and click install

## Installing Sparkfun TB6612 Drivers
- If you are using Sparkfun TB6612 then you will need to install the drivers for the motor driver. These drivers will simplify the implementation of the motor drivers significantly. To install the drivers visit the github website and click the green code button and download Zip.
- Open the Arduino IDE and navigate to the library manager: Sketch->Include library->Add .Zip Library. Find the file you downloaded, select it and click open. The library is now installed.
- For more information about the TB6612 drivers, check out sparkfun’s website.
