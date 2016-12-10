#include <opencv/cv.h>
#include <opencv/cxmisc.h>
#include <opencv/cxcore.h>
#include <opencv/ml.h>
#include <opencv/cvaux.h>
#include <opencv/cvwimage.h>
#include <opencv/highgui.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h> // To list files in a directory

#include <sstream>
#include <string>

using namespace cv;
using namespace std;
Mat src;
Mat src_gray;
int thresh = 100;
int max_thresh = 255;
RNG rng(12345);
void thresh_callback(int, void* );


int main( int, char** argv ){

Mat src=imread(argv[1]);
Mat hsv_image;
Mat threshold;

inRange(hsv_image, Scalar(80,40,20), Scalar(160,100,100),threshold);
cvtColor(src,hsv_image,CV_BGR2HSV);
imshow("thr",threshold);

  waitKey(0);

  return(0);
}

