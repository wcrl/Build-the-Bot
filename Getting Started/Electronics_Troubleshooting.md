# Electronics Troubleshooting
---

## Arduino Nano

### Issues Uploading Code

For instances of being unable to upload code to you arduino nano, here are some things to check:

1. Is your Arduino Plugged in (always gotta double check)
2. Ensure HM10 Bluetooth device is disconnected
3. Check that the proper COM port is selected under tools(Tools->Ports). This will depend on your computer
4. Check that you are selecting the proper Arduino that you are using for the project. This can be done by going to Tools->Board: In most cases, this will be an Arduino nano
5. Check which bootloader you have selected; many of the cheaper Arduinos (especially Arduino Nanos) on the market use the “Old Bootloader.” This can be accessed in Tools->Processor
6. You have the correct version of the Arduino IDE

### Windows Does not Recognize Arduino Nano

This may likely be due to the purchase of an off brand Arduino. The most common fix is to check if your Arduino uses a CH430 programming chip on the bottom of your board as the interface between the computer and the programmer. This can be simply fixed by installing the proper drivers from this website. 

http://www.wch-ic.com/downloads/CH341SER_ZIP.html

---

## HM10 Bluetooth Device

### Renaming Device

A WCRL custom PCB is in developement for easy renaming of the HM10 unit.

---

## Sparkfun TB6612 Motor Driver 

### Have the proper drivers

If you are using Sparkfun TB6612 then you will need to install the drivers for the motor driver. These drivers will simplify the implementation of the motor drivers significantly. To install the drivers visit the github website and click the green code button and download Zip.

https://github.com/sparkfun/SparkFun_TB6612FNG_Arduino_Library

Open the Arduino IDE and navigate to the library manager: Sketch->Include library->Add .Zip Library. Find the file you downloaded, select it and click open. The library is now installed.

For more information about the TB6612 drivers, check out sparkfun’s website.

https://learn.sparkfun.com/tutorials/tb6612fng-hookup-guide?_ga=2.77316117.1687938213.1637867360-170652134.1635896834

---
