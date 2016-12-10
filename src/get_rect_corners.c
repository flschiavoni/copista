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

void get_rect_corners(RotatedRect min_rect, Point2f dst[4]){
    dst[0] = Point(0, 0);
    dst[1] = Point(min_rect.boundingRect().width - 1, 0);
    dst[2] = Point(min_rect.boundingRect().width - 1, min_rect.boundingRect().height - 1);
    dst[3] = Point(0, min_rect.boundingRect().height - 1);
}

