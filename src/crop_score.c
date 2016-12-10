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

Mat crop_score(Mat src, int canny_threshold){
    vector<vector<Point> > contours = get_contours(src, canny_threshold);
    Mat output = crop_to_contour(src, contours);
    return output;
}

