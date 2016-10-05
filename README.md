Introduction

This code is part of the following publication and was subject to peer review:
"Multiscale line segment detector for robust and accurate SfM" by Yohann Salaun, Renaud Marlet, and Pascal Monasse ICPR 2016

It generalizes the classical LSD algorithm avoiding oversegmentation and bad detection on high quality picture.
Its multiscale processing allow far better results for HQ images at a low/inexistant computation cost on most pictures.

Building

Use CMake in order to build the project. (available for free at https://cmake.org/)
The only requirement is openCV (3.x is ok and 2.x should be ok too). It is available for free at http://opencv.org/
We are currently trying to get rid of this library for simplicity though it could be faster with it.

License

MPL2 for MLSD
AGPL for LSD

Authors

Yohann Salaun <yohann.salaun@imagine.enpc.fr>
Renaud Marlet <renaud.marlet@enpc.fr>
Pascal Monasse <pascal.monasse@enpc.fr>

Citations

If you used our code in your publication, please cite 
"Multiscale line segment detector for robust and accurate SfM" by Yohann Salaun, Renaud Marlet, and Pascal Monasse ICPR 2016
