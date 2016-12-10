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

vector<string> list_files(const char* dirname){
    DIR *dpdf;
    struct dirent *epdf;
    vector<string> file_list;
    dpdf = opendir(dirname);
    if (dpdf != NULL){
       while (epdf = readdir(dpdf)){
            std::stringstream ss;
            ss << epdf->d_name;
            std::string s = ss.str();
            file_list.push_back(s);
       }
    }
    return file_list;
}

