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

vector<Point> find_biggest_contour(vector<vector<Point> > contours){
    double perimeter = 0;
    vector<Point> contour;
    for(int i = 0; i< contours.size(); i++ ){
        double local_perimeter = arcLength(contours[i], true);
        if(local_perimeter > perimeter){
            perimeter = local_perimeter;
            contour = contours[i];
            }
    }
    return contour;
}

