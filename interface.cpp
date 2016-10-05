/*----------------------------------------------------------------------------  
  This code is part of the following publication and was subject
  to peer review:
  "Multiscale line segment detector for robust and accurate SfM" by
  Yohann Salaun, Renaud Marlet, and Pascal Monasse
  ICPR 2016
  
  Copyright (c) 2016 Yohann Salaun <yohann.salaun@imagine.enpc.fr>
  
  This program is free software: you can redistribute it and/or modify
  it under the terms of the Mozilla Public License as
  published by the Mozilla Foundation, either version 2.0 of the
  License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  Mozilla Public License for more details.
  
  You should have received a copy of the Mozilla Public License
  along with this program. If not, see <https://www.mozilla.org/en-US/MPL/2.0/>.

  ----------------------------------------------------------------------------*/

#include "interface.hpp"
using namespace std;
using namespace cv;

// for color randomization
vector<Scalar> rgb = {Scalar(255,0,0), Scalar(0,255,0), Scalar(0,0,255), Scalar(255,255,0), Scalar(0,255,255), Scalar(255,0,255), 
		      Scalar(0,150,0), Scalar(150,0,0), Scalar(0,0,150), Scalar(150,150,0), Scalar(0,150,150), Scalar(150,0,150)};
int countRandomRGB = 0;

/*=================== SEGMENT ===================*/
Segment::Segment(const double X1, const double Y1, const double X2, const double Y2,
  const double w, const double p, const double nfa, const double s){
  x1 = X1; y1 = Y1;
  x2 = X2; y2 = Y2;
  width = w;
  prec = p;
  log_nfa = nfa;
  angle = atan2(y2 - y1, x2 - x1);
  scale = s;
}

// FOR MULTISCALE LSD
void Segment::upscale(const double k){
  x1 *= k; y1 *= k;
  x2 *= k; y2 *= k;
  width *= k;
  length *= k;
}

// I/O METHODS for segments
void Segment::readSegment(std::ifstream &file){
  file >> x1 >> y1 >> x2 >> y2 >> width >> prec >> log_nfa >> scale;
  scale = 0;
  angle = atan2(y2 - y1, x2 - x1);
}

void Segment::saveSegment(std::ofstream &file) const{
  file << x1 << "  " << y1 << "  " << x2 << "  " << y2 << " " << width << " " << prec << " " << log_nfa << " " << scale << std::endl;
}

/*=================== INPUT/OUTPUT ===================*/
inline
int thicknessFromImage(const Mat &im){
  return max((im.cols + im.rows/2)/400, 2);
}

void readPictureFile(const string path, vector<string> &picName, vector<string> &picPath){
  ifstream picListTxt(path , ifstream::in);
  int nPictures;
  picListTxt >> nPictures;
  cout << nPictures << endl;
  picName.resize(nPictures);
  picPath.resize(nPictures);
  for(int i = 0; i < nPictures; i++){
    picListTxt >> picName[i] >> picPath[i];
    cout << picName[i] << "         " << picPath[i] << endl;
  }
}

PictureSegments readLines(const string path, const string name){
  PictureSegments lines;

  ifstream linesTxt((path + name + "_lines.txt").c_str(), ifstream::in);
  int nLines;
  linesTxt >> nLines;
  lines.resize(nLines);

  for (int i = 0; i < nLines; ++i) {
    // read segment informations
    lines[i].readSegment(linesTxt);
  }
  return lines;
}

void saveLines(const PictureSegments &lines, const string path, const string name){
  ofstream linesTxt((path + name + "_lines.txt").c_str(), ofstream::out);
  linesTxt << lines.size() << endl;

  for (int i = 0; i < lines.size(); ++i) {
    // add coordinates to txt file
    lines[i].saveSegment(linesTxt);
  }
}

void saveLinesPicture(const PictureSegments &lines, const Mat &im, const string path, const string name, const bool withNumber){
  Mat image;
  im.copyTo(image);

  int thickness = thicknessFromImage(im);

  for (int i = 0; i < lines.size(); ++i) {
    // random colors for each segment
    countRandomRGB = (countRandomRGB+1)%rgb.size();

    Point2f p1(lines[i].x1, lines[i].y1);
    Point2f p2(lines[i].x2, lines[i].y2);
    line(image, p1, p2, rgb[countRandomRGB], thickness);
    circle(image, p1, thickness, rgb[countRandomRGB]);

    // to add the segment number into the picture
    if (withNumber){
      ostringstream ss;
      ss << i;
      putText(image, ss.str(), Point2f(0.5*(p1.x + p2.x), 0.5*(p1.y + p2.y)),
        FONT_HERSHEY_SCRIPT_SIMPLEX, 5, rgb[countRandomRGB], 3);
    }
  }
  imwrite(path + "pictures/" + name + "_lines.jpg", image);
}