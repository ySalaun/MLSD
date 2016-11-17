=====================================
MLSD (Multiscale Line Segment Detector)
=====================================

------------
Introduction
------------


This code is linked of the following publication, which was subject to peer review: 

"Multiscale line segment detector for robust and accurate SfM" by Yohann Salaun, Renaud Marlet, and Pascal Monasse ICPR 2016

It generalizes the classical LSD algorithm avoiding oversegmentation and bad detection on high quality picture.
Its multiscale processing allow far better results for HQ images at a low/inexistant computation cost on most pictures.

------------
Building
------------

Requirement:

- CMake (available for free at https://cmake.org/download/)

- openCV (available for free at http://opencv.org/) > 2.x

- C++ compiler

We are currently trying to get rid of openCV for simplicity though it could be faster with it.

------------
Use
------------

The code works with the following arguments:

- -d: directory path where the line files will be store in [IMG_NAME]_lines.txt and the corresponding pictures in DIRECTORY_PATH/pictures/[IMG_NAME]_lines.jpg
(Note that you need to make the subdirectory pictures yourself, otherwise it won't store the pictures)
- -i: input file of the form

NB_OF_PICTURES

IMG0_NAME IMG0_FULL_PATH

IMG1_NAME IMG1_FULL_PATH

...

IMGn_NAME IMGn_FULL_PATH

- (optionnally) -m: to enable(1)/disable(0) the multiscale mode (DEFAULT: enabled)

- (optionnally) -t: threshold for segment detection in percentage of the image size (DEFAULT: 0)

------------
License
------------

[MPL2](https://github.com/ySalaun/MLSD/edit/master/LICENSE.mlsd) for MLSD

AGPL for LSD

------------
Authors
------------

Yohann Salaun <yohann.salaun@imagine.enpc.fr>

Renaud Marlet <renaud.marlet@enpc.fr>

Pascal Monasse <pascal.monasse@enpc.fr>

------------
Citations
------------

If you used our code in your publication, please cite the following:

[1] Yohann Salaun, Renaud Marlet, and Pascal Monasse, [Multiscale line segment detector for robust and accurate SfM](https://drive.google.com/file/d/0B96kyL2SBsmzOFY0b2hnSm54eTQ/view),  ICPR 2016

[2] Rafael Grompone von Gioi, Jérémie Jakubowicz, Jean-Michel Morel, and Gregory Randall, LSD: a Line Segment Detector, Image Processing On Line, 2 (2012), pp. 35–55. http://dx.doi.org/10.5201/ipol.2012.gjmr-lsd
