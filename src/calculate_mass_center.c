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

Point2f calculate_mass_center(vector<Point> contour){
    Point2f mc(0,0);
    for(int i = 0; i < contour.size(); i++){
        mc.x += contour[i].x;
        mc.y += contour[i].y;
        }
    mc.x /= contour.size();
    mc.y /= contour.size();
    return mc;
}

