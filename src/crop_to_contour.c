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

Mat crop_to_contour(Mat src, vector<vector<Point> >contours){
    Point2f corners[4];
    vector<Point> contour = find_biggest_contour(contours);
    find_corners(contour, corners);

    RotatedRect min_rect = minAreaRect(contour);
    Point2f dst[4];
    get_rect_corners(min_rect, dst);

    Mat output;
    Mat warpAffineMatrix = getPerspectiveTransform(corners, dst);
    warpPerspective(src, output, warpAffineMatrix, min_rect.boundingRect().size());
    return output;
}

