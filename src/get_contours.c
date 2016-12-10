#include <opencv/cv.h>
#include <opencv/cxmisc.h>
#include <opencv/cxcore.h>
#include <opencv/ml.h>
#include <opencv/cvaux.h>
#include <opencv/cvwimage.h>
#include <opencv/highgui.h>

#include <dirent.h> // To list files in a directory
#include <string>

#include "copista.h"


using namespace cv;
using namespace std;

vector<vector<Point> > get_contours(Mat src, int canny_threshold){
    Mat tmp;
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;
    // Convert image to B&W enhancing the Green background color
    inRange(src, Scalar(0,0,0), Scalar(255,255,100), tmp);
    blur(tmp, tmp, Size(3,3) );
    // Canny filter and contour Area
    Canny(tmp, tmp, canny_threshold,  canny_threshold*2, 3 );
    findContours(tmp, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0) );
    return contours;
}

