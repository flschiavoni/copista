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

using namespace cv;
using namespace std;

string inspect_countour(vector<Point> contour){
    RotatedRect min_area = minAreaRect(contour);
    Rect rect = boundingRect(contour);
    Rect rect2 = min_area.boundingRect();
//    RotatedRect min_ellipse = fitEllipse(Mat(contour));

    Point2f mc(0,0);
    for(int i = 0; i < contour.size(); i++){
        mc.x += contour[i].x;
        mc.y += contour[i].y;
        }
    mc.x /= contour.size();
    mc.y /= contour.size();

    std::stringstream ss;
    ss << "Perimeter: " << arcLength(contour, true) << " ";
    ss << "Angle:" << min_area.angle << " ";
    ss << "Center:" << min_area.center << " ";
    ss << "Size:" << min_area.size << " ";

    ss << "| Rect x:" << rect2.x << " ";
    ss << "y:" << rect2.y << " ";
    ss << "width:" << rect2.width << " ";
    ss << "height:" << rect2.height << " ";
    ss << "area:" << rect2.area() << " ";

    ss << "| Rect x:" << rect.x << " ";
    ss << "y:" << rect.y << " ";
    ss << "width:" << rect.width << " ";
    ss << "height:" << rect.height << " ";
    ss << "area:" << rect.area() << " ";
    ss << "| Points x:" << contour.size() << " ";
 
//    ss << "| Moments:" << mu << " ";

    ss << "| Mass Center:" << mc << " ";

    std::string s = ss.str();
    return s;
}
