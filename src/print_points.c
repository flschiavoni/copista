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

string print_points(vector<Point> points){
    std::stringstream ss;
    for(size_t i = 0 ; i < points.size(); i++){
        ss << "(" << points[i].x << "," << points[i].y << ")";
    }
    std::string s = ss.str();
    return s;
}

string print_points(vector<Point2f> points){
    std::stringstream ss;
    for(size_t i = 0 ; i < points.size(); i++){
        ss << "(" << points[i].x << "," << points[i].y << ")";
    }
    std::string s = ss.str();
    return s;
}

string print_points(Point2f points[], int length){
    std::stringstream ss;
    for(size_t i = 0 ; i < length; i++){
        ss << "(" << points[i].x << "," << points[i].y << ")";
    }
    std::string s = ss.str();
    return s;
}
