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

string inspect_image(Mat image){

    std::stringstream ss;
    ss << "Elements Size: " << image.elemSize() << " ";
    ss << "Element Size:" << image.elemSize1() << " ";
    ss << "Type:" << image.type() << " ";
    ss << "Depth:" << image.depth() << " ";
    ss << "Channels:" << image.channels() << " ";
    ss << "Step1:" << image.step1() << " ";
    ss << "Size:" << image.size() << " ";
    ss << "Empty:" << image.empty() << " ";

    std::string s = ss.str();
    return s;
}
