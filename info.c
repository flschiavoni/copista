#include <opencv/cv.h>
#include <opencv/cxmisc.h>
#include <opencv/cxcore.h>
#include <opencv/ml.h>
#include <opencv/cvaux.h>
#include <opencv/cvwimage.h>
#include <opencv/highgui.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h> // To list files in a directory

#include <sstream>
#include <string>

#include "copista.h"

using namespace cv;
using namespace std;



int main(int, char** argv){
    vector<string> filelist = list_files(argv[1]);
    for (int i = 0 ; i < filelist.size() ; i++){
        std::stringstream ss;
        ss << argv[1] << filelist[i];
        Mat score = open_image(ss.str());
        if (score.empty()){
            cerr << "No image supplied ... " << filelist[i] << endl;
            continue;
        }
        vector<vector<Point> > contours = get_contours(score, 100);
        vector<Point> contour = find_biggest_contour(contours);
        string s = inspect_countour(contour);
        cout << filelist[i] << ": " << s << endl;
    }
    cout << " -----------------------------------\n";
    cout << "Finished!\n";
    return(0);
}

