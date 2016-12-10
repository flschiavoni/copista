#include <opencv/cv.h>
#include <opencv/cxmisc.h>
#include <opencv/cxcore.h>
#include <opencv/ml.h>
#include <opencv/cvaux.h>
#include <opencv/cvwimage.h>
#include <opencv/highgui.h>

#include <dirent.h> // To list files in a directory
#include <string>

using namespace cv;
using namespace std;

Mat crop_image(Mat src, Rect rect){
    Rect myROI(rect);
    Mat cropped_image = src(myROI);
    Mat(src, myROI).copyTo(cropped_image);
    return cropped_image;
}

