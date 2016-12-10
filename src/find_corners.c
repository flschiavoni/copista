#include <opencv/cv.h>
#include <opencv/cxmisc.h>
#include <opencv/cxcore.h>
#include <opencv/ml.h>
#include <opencv/cvaux.h>
#include <opencv/cvwimage.h>
#include <opencv/highgui.h>
#include <opencv/highgui.h>

#include <dirent.h> // To list files in a directory
#include <string>
#include "copista.h"

using namespace cv;
using namespace std;

void find_corners(vector<Point> contour, Point2f corners[4]){
    // Calculate Mass center
    Point2f mc = calculate_mass_center(contour);

    corners[0] = mc;
    corners[1] = mc;
    corners[2] = mc;
    corners[3] = mc;

    Point2f temp;
    for (int i = 0 ; i < contour.size(); i++){
        //Top left quadrant
        if (contour[i].x > mc.x || contour[i].y > mc.y)
            continue;
        temp = Point2f(contour[i].x, contour[i].y);
        if (abs(norm(mc - temp)) > abs(norm(mc - corners[0])))
            corners[0] = temp;
    }

    for (int i = 0 ; i < contour.size(); i++){
        //top right quadrant
        if (contour[i].x < mc.x || contour[i].y > mc.y)
            continue;
        temp = Point2f(contour[i].x, contour[i].y);
        if(abs(norm(mc - temp)) > abs(norm(mc - corners[1])))
            corners[1] = temp;
    }

    for (int i = 0 ; i < contour.size(); i++){
        //Bottom right quadrant
        if (contour[i].x < mc.x || contour[i].y < mc.y)
            continue;
        temp = Point2f(contour[i].x, contour[i].y);
        if(abs(norm(mc - temp)) > abs(norm(mc - corners[2])))
            corners[2] = temp;
    }

    for (int i = 0 ; i < contour.size(); i++){
        //Bottom left quadrant
        if (contour[i].x > mc.x || contour[i].y < mc.y)
            continue;
        temp = Point2f(contour[i].x, contour[i].y);
        if(abs(norm(mc - temp)) > abs(norm(mc - corners[3])))
            corners[3] = temp;
    }
}
