# Overview
This document is to serve as a guide for designing parts for FDM 3D printing. This guide is by no means exhaustive, as there are many factors that go into successfully designed and printed parts. We will merely cover the most important aspects from a designing, slicing, and printing perspective.

---

# What is FDM 3D Printing?
Fused Deposition Modeling (FDM) – also called Fused Filament Fabrication (FFF) – 3D printing works by layering melted thermoplastic on top of previous layers to create a three dimensional object.

Common thermoplastics used for 3D printing can be found in the Filament Selection section below.

---

# Workflow
The general workflow for any 3D printed part is as follows:

1. Obtain dimensions
    1. If your part must interface with existing parts, take measurements of those parts using calipers. Keep in mind which dimensions are critical, meaning that they are required to have a good fit.
    2. If your part doesn’t interface with existing parts, have an idea of how large you want your parts to be. This may also be limited by 3D printer size, as we will discuss later in the document.
2. Design in CAD
3. Export .stl or .obj file into a Slicer
4. Slice the file using PrusaSlicer, Cura, Simplify3D, or another slicer software
5. Export G-Code to the printer

---

# CAD Design and Restrictions
This guide is not going to dive into the intricacies of different CAD softwares or the merits of one CAD software over another. That being said, there are several CAD softwares that you can use:

* Fusion 360 – Recommended by WCRL due to ease of use and student plan
* Creo
* SolidWorks
* SolidEdge
* Inventor
* TinkerCAD
* Onshape – Recommended if using a lower performance computer

We will not be covering how to design parts in CAD as there are plenty of resources available. We will instead be focusing on certain part features you will have to keep in mind while designing a part.

Some useful Fusion360 Resources:

* [Fusion 360 download link](https://www.autodesk.com/campaigns/education/student-design)
* [Fusion 360 tutorials](https://www.youtube.com/watch?v=WKb3mRkgTwg&list=PLrZ2zKOtC_-DR2ZkMaK3YthYLErPxCnT-)

We recommend following tutorials prior to attempting to design a part. This will allow you to familiarize yourself with the interface, and will make designing your part considerably easier.

## Printspace

Every 3D printer has a limitation of the size of the objects it can print. The range of each of the three axes determine what is known as the prinspace, or print volume. This means that any single body must fit in that printspace in order to be printed on that machine. Examples of common 3D printers and their printspaces include:

* Prusa i3 MK3S: (25x21x21) cm or (9.84x8.3x8.3) in
* Prusa Mini: (18x18x18) cm or (7x7x7) in

## Overhangs

## Bridging

## Exporting a Mesh

To export a Mesh from Fusion360, open the file for the bodies you want to export. On the left hand navigation panel, select the body you want to export, right click, and select “Save as Mesh”.

From the Save as Mesh navigation menu, select .3MF, .obj, or .stl (binary). Units should always be millimeters. From there, leave refinement as high and click export.

.stl are most commonly used, however, .3MF, .obj, or .stl (binary) can all be imported into a slicer.

[For more information on exporting meshes from Fusion 360, check out the Autodesk Info Page.](https://knowledge.autodesk.com/support/fusion-360/learn-explore/caas/sfdcarticles/sfdcarticles/How-to-export-an-STL-file-from-Fusion-360.html)

---

# Slicing Settings
## What is a slicer?
A slicer takes a mesh file and cuts it horizontally into many layers. The information on how to create each of these layers, including what the nozzle temperature and bed temperature need to be, is then saved into a G-Code file that can be sent to the printer.

## PrusaSlicer
PrusaSlicer is our recommended slicer, as it is designed to work exceptionally well with Prusa brand printers, specifically the Mk3S+ and Mini+. On campus, the Watson Fabrication Lab and the Emerging Technology Studio both have MK3S+ Printers.

PrusaSlicer is free to download, and we would recommend downloading and messing around with it. When you set up the printer profile via the installation wizard, select the MK3S+ with a 0.4mm nozzle.

[Download PrusaSlicer here!](https://www.prusa3d.com/page/prusaslicer_424/)

## Recommended Defaults in PrusaSlicer
## Layer Height
Layer height is the thickness of plastic deposited in each layer. These generally range between 0.15mm - 0.3mm but can go either smaller or larger. The smaller the layer height, the higher the quality in small details, but the longer the print will take.

For most standard prints with details, a 0.2mm layer height will work well. However, for larger or less detailed prints, a 0.3mm layer height will result in a similar quality print that is printed faster.

In the slicer, you can preview different layer heights to visualize how the different layer heights may impact quality on detailed parts.

## Infill
Infill refers both to the percentage of solid material inside of your 3D print as well as the geometric pattern that is present. Your slicer may offer many different pattern options so feel free to do your own experimentation, but generally speaking the strongest geometries are triangular, cubic or gyroidal.

By default most slicers will recommend an infill ranging between 10-20%. This is an ideal infill range as you are optimizing between strength and material usage. However, during early prototyping we would recommend using a very low infill, maybe between 5-10%, in order to provide quicker printing times and save on materials. For prints that your team plans to use for the competition we would recommend using anything between 10-30% infill depending on the application of the printed part. Contrary to what you may think, a higher infill percentage does not always correlate to a stronger part. Using any infill above 45% is almost always a big waste of material and time as the strength is usually maximized at a much lower percentage. The executive team has found that using 20-30% infill and editing the perimeter/walls setting to be 3 or 4 provides great results!

## Print Orientation
Print  orientation is the way in which the part will be printed. As previously mentioned, FDM printers work by printing one layer at a time and building from the bottom to top. Because of this it is important to orient your print in a way such that the bottom of the print is a large flat surface such that it can form a strong connection to the printer’s bed. Additionally you want to make sure that your print is oriented in a way that minimizes the amount of overhangs and bridges and also uses the minimal amount of support materials if any.

## Supports
Supports are 3D printed structures that a slicer will generate over any large bridges or overhangs. Supports can be useful for creating prints that have unique aesthetics but they can be avoided if your design is done well. Often it is best to design your parts to be printed without support materials because it is faster, you do not have to spend time removing the support materials after a print, and supports actually can create a weakened area on your 3D printed part. This is because the support material tends to have a very small gap of air between its last layer and the first layer of your printed part. This small gap allows for slight drooping in the layers directly above the support which provides a weakened section of the print.

In order to avoid needing support materials the executive team recommends the following:

* Any angled sections of your print should be between 90 and 45 degrees with reference to the print bed
* Avoid long bridge like sections, any bridging should be limited to 3 cm or less

## Raft/Skirt/Brim
Rafts, skirts and brims are some additional settings that slicers have to add additional material to the first few layers on the print bed. A raft is a flat surface that is generated between the print bed and your part. Rafts are usually a few layers thick and serve as a good way to stabilize your part if it has a small surface area. Additionally, rafts are great for preventing warping and ensuring good bed adhesion.

Skirts are a small loop that is printed around the perimeter of your part. The executive team always recommends using at least a skirt since it allows for the extruder to be primed and ensure that there is a good flow of filament out of the printer’s nozzle.

A brim is a special type of skirt that is actually connected to the edges of your part. Just like with a raft, a brim is a useful tool to help with bed adhesion. Brims are particularly useful for preventing any slight warping in the edges of parts that already have a large surface area.  

---

# Filament Selection
## PLA
PLA is the most commonly used 3D printing filament. It has outstanding aesthetic characteristics. Bridging and overhangs are much more forgiving with PLA than with any other filament type. Due to its popularity, there are many different variations available that are each optimized for different characteristics. However, in general, parts printed in PLA variants are very rigid, this comes at the expense of a low impact resistance, meaning PLA parts are more likely to shatter than parts printed in other filament types. In addition, parts printed in PLA have relatively poor layer adhesion.

## PETG
PETG is the second most common type of 3D printing filament, it is less rigid than PLA, but its impact resistance is significantly greater than that of any PLA variant.

## TPU
TPU is another common type of 3D printing filament. TPU is much more rubbery than other 3D printing materials. It is best suited for applications that require very high impact resistance and or flexibility.

## ABS
ABS is one of the most commonly used plastics for injection molding. It is more rigid than PETG, but slightly less rigid than PLA. It can be difficult to print, but when done correctly it’s impact resistance is also quite high.

(Note: ETS is not typically printing with ABS currently. Email ETS with any questions)

---

## Pricing
Cost of printing at Binghamton University ETS (Emerging Technology Center) is determined by the amount of material used. This includes support material in addition to your object if needed. For PLA and PETG the price of printing is 0.025 BUC$ (Note: BUC$ are different from meal plans). For reference the following 3d objects and prices are shown:

##### DemoBot:
<img width="419" alt="DemoBotJR" src="https://user-images.githubusercontent.com/113567684/191163658-2cde4d5b-8658-46b0-99e1-2d95b94781e1.png">

Material Used: 191 grams
Cost at ETS (PLA or PETG): 4.75 BUC$

##### Stump: 
<img width="308" alt="Stump(89 17g)" src="https://user-images.githubusercontent.com/113567684/191872950-0f95c600-7cb4-4eab-9b45-1eb8a07bfc9f.png">


Material Used: 89.17 grams
Cost at ETS (PLA or PETG): 2.23 BUC$

##### Vase:
<img width="317" alt="Vase(88 24g)" src="https://user-images.githubusercontent.com/113567684/191880903-2ee40e31-a952-4763-a718-01fd82a1c259.png">

Material Used: 88.24 grans
Cost at ETS (PLA or PETG): 2.21 BUC$

---

# Binghamton University Emerging Technology Studio

The [Binghamton University Emerging Technology Studio](https://www.binghamton.edu/its/about/organization/technology-support-services/innovation/ets/index.html) (ETS) is a makerspace available to all students. They are an excellent 3D printing resource for any questions for Binghamton University Students. 

General hours are:
- Mon-Thurs 10:00-6:00
- Fri 10:00-5:00
- Closed Weekends

Contact ETS for 3D printing help at ETSBing@binghamton.edu
