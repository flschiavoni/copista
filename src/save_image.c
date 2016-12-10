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

int save_image(Mat src, char** image_name){
    if (src.cols > 0 && src.rows > 0){
        imwrite(image_name.c_str(), src );
        return 1;
    }else
        return 0;
}

