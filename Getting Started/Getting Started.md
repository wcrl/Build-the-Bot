# Getting Started
## Overview

This document will give you everything you need to know about designing your own combat robot for the Watson Combat Robotics League!

---
## Conceptual Design
The best way to get ideas for your design if you are new to the concept of combat robotics is to draw inspiration from bots that already exist. Some important things to look for when watching videos are:

- The type of bot (Spinner, flipper, etc)
- Number of competition attachments
- Number of wheels
- Unique design features
- Performance

Once you have some general ideas, sketch them out on a piece of paper, design software, or even on the back of a napkin! Some key things to remember when brainstorming a design of your own:
The type of bot (Spinner, flipper, etc)
Number of competition attachments
Number of wheels
Where will the electronics go?
Where will screws go?

Here are some links to get you started:
- [WCRL YouTube Channel](https://www.youtube.com/channel/UCIaK69JDDWl9wAELpbH6m2w)
- [Team Panic](https://www.youtube.com/c/TeamPanicRobotics)
- [Adelaide Robot Combat](https://www.youtube.com/user/FrydDog)
- [Raptor Robots](https://www.youtube.com/channel/UCBQbgLWFmt3UULC7kQ891VA)
- [3D Power Prints](https://www.youtube.com/channel/UCgO0GEN4iXCauXte8O-5n2w)
- [Maker's Muse](https://youtu.be/YWOqAwXmvJU)

---
## CAD Design and Part Ordering
Now that you have a conceptual design, you are ready to start designing your bot in CAD (Computer Aided Design)! Just kidding, you’re not quite there yet. You first need to know what is going inside your bot!

### Electronics
#### Microcontroller (Brain of the Bot)
The microcontroller is responsible for sending commands to other components of your robot, (i.e. telling the wheels to spin). Some possible options include:
Arduino

- Nano – Recommended for this project due to the small size
- Uno – Useful for debugging due to built-in header pins, but not necessary
- Mega – Overkill for this project
- Teensy 3.4/4.0/4.1
- Raspberry Pi

#### Bluetooth Transceiver (Communicate with the Bot)
There are many different models of transceiver for this project, however we recommend the [HM-10](https://www.amazon.com/dp/B06WGZB2N4/?coliid=I2803XF5QJ56I&colid=2HZ7F15TNBDGH&psc=1&ref_=lv_ov_lig_dp_it) for this competition as you can use your phone to control the bot via bluetooth. We also recommend using the [Dabble](https://www.arduino.cc/reference/en/libraries/dabble/) phone application for ease of control.

You can use a variety of different transceivers for either remote or bluetooth control, but make sure you select one with good documentation. Our executive team solely uses HM-10’s, so if you think you may need assistance, we recommend selecting that one as well.

#### Controllers (Control the Bot)
Controllers can be as simple as configuring the Dabble app to control motors via your smartphone, or as complicated as designing your own PCB – it is completely up to you and your team!

##### Physical controller requirements/suggestions
- Microcontroller
- Bluetooth module
- Joysticks
- Buttons
- Potentiometers (Useful for controlling CA speed)
- Battery

#### Motors (Move the Bot)

- DC Motors (Recommended for powering wheels)
  - Can be used for powering competition attachments
  - Requires a motor driver board to connect the motors to the microcontroller.
  - When picking your motors be sure to do some calculations to make sure you will have enough voltage and current from the WCRL provided battery.
- Brushless Motors
  - Recommended for Competition Attachments
  - Different from DC motors as they operate with magnetic coils on the inside which turn off and on quickly to spin the motor much faster than a common DC motor can.
  - Requires an Electronic Speed Controller (ESC) rather than a motor driver
- Servos
  - Motor-like device that will act to rotate an arm to a certain position (angle).
  - Many do not allow continuous rotation

These are only some examples – do some research and find all the cool motors you can use!

#### Battery (Power the Bot)
It is recommended that each team use the [WCRL provided battery](https://www.amazon.com/Zeee-Graphene-Quadcopter-Helicopter-Airplane/dp/B07Y67CHJT/ref=sr_1_17?crid=18U94VR4VHA16&keywords=3s%2Blipo%2Bbattery&qid=1580166046&sprefix=3s%2B%2Caps%2C159&sr=8-17&th=1)
A team may use their own battery if:

- The Battery is a LiPo (Lithium Polymer)
- The Battery does not exceed 14.8 V (4s) nominally
- The Battery comes with a proper battery bag
- The Battery comes with a charger
- A power switch must cut off power directly from the battery

---
## Hardware
There are also many miscellaneous parts that are required to build a robot, such as heat-shrink and screws. Please refer to the Build-the-bot BOM for more information.

---

## CAD Designs
### CAD Software
Now that you know what is going in the bot, you can officially start designing it in CAD. This guide is not going to dive into the intricacies of different CAD softwares or the merits of one CAD software over another. That being said, there are several CAD softwares that you can use:

- Fusion 360 – Recommended by WCRL due to ease of use and student plan
- Creo
- SolidWorks
- SolidEdge
- TinkerCAD

We will be using Fusion360 as a basis for our recommendations. Some useful Fusion360 Resources:
- [Fusion 360 download link](https://www.autodesk.com/campaigns/education/student-design)
- [Fusion 360 tutorials](https://www.youtube.com/watch?v=WKb3mRkgTwg&list=PLrZ2zKOtC_-DR2ZkMaK3YthYLErPxCnT-)
  - We recommend following tutorials prior to attempting to design your bot. This will allow you to familiarize yourself with the interface, and will make designing your bot considerably easier.

## Design Recommendations
- Use parameters to make changing hole sizes for clearance later on easier
- Walls thickness of 2-5 mm
- Use heat-set inserts whenever a screw is going to be inserted
- If you model threads directly into the print, or screw directly into a hole, the plastic will wear out after multiple uses
These are generally a 1-2mm larger than the screw size, but vary based on manufacturer
- A good size for the provided 3mm heat-set inserts is a 4.4mm diameter hole
- Provide clearance for screw heads in the print
- Button vs socket heads are different sizes, and would need different amounts of clearance
Model all components that will go into your bot and create an assembly, so you will know if any parts won’t align properly or will have difficulty fitting in the robot

## 3D Printing Setting Overview

The 3D printer setting overview is found within a different document, [here](https://docs.google.com/document/d/1x-k-k0dfrq4NDOPhjnmKSc4RKWbllCxLYFbABFv0URE/edit?usp=sharing).

- Bot Body Print Settings
- PLA recommended
- Use a 0.3mm layer height if possible to speed up print times
- Use 10-15% Triangle or Honeycomb infill
- Anything above 20% has insignificant strength gain but adds a lot of weight
- 100% infill isn’t as great as it seems
- Print using 4 vertical shells
- Bot Competition Attachment Print Settings
- PETG recommended
- Use a 0.3mm layer height if possible to speed up print times
- Use 25-30% Triangle or Honeycomb infill
- Allow for testing to determine optimum weight balance.
- Heavier CA may actually be a good thing
- Print using 4+ vertical shells
