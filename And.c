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
#include "copista.h"

using namespace cv;
using namespace std;
int thresh = 50;
int max_thresh = 255;
RNG rng(12345);
void thresh_callback(int, void* );

Mat src;
Mat src_gray;

int main( int, char** argv ){
  src = open_image(argv[1]);
  if (src.empty())
  {
    cerr << "No image supplied ..." << endl;
    return -1;
  }

  cvtColor( src, src_gray, COLOR_BGR2GRAY );
  blur( src_gray, src_gray, Size(3,3) );
  const char* source_window = "Source";
  namedWindow( source_window, WINDOW_AUTOSIZE );
  imshow( source_window, src );
  createTrackbar( " Canny thresh:", "Source", &thresh, max_thresh, thresh_callback );
  thresh_callback( 0, 0 );
  waitKey(0);
  return(0);
}

void thresh_callback(int, void* )
{
  Mat canny_output;
  vector<vector<Point> > contours;
  vector<Vec4i> hierarchy;
  Canny( src_gray, canny_output, thresh, thresh*2, 3 );
  findContours( canny_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0) );

    double area = 0;
    Rect rect;

    for( size_t i = 0; i< contours.size(); i++ ){
        double temp_area = contourArea(contours[i], false);
        if (area < temp_area){
            area = temp_area;
            rect = boundingRect(contours[i]);
        }
    }

    Mat croppedImage = crop_image(rect, src);

  namedWindow( "Contours", WINDOW_AUTOSIZE );
  if (croppedImage.cols > 0 && croppedImage.rows > 0)
      imshow( "Contours", croppedImage);
}
