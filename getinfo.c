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
#include <fstream> // to txt file

#include "copista.h"

using namespace cv;
using namespace std;

void file_info(const char * file_name){
    ofstream outputFile;
    string name = file_name;
    string ext = ".txt";
    name = name + ext;
    outputFile.open(name.c_str());
    Mat score = open_image(file_name);
    if (score.empty()){
        cerr << "No image supplied ... " << file_name << endl;
        return;
    }
    cout << "File: " << file_name << endl;
    outputFile << "File: " << file_name << endl;
    cout << inspect_image(score) << endl;
    outputFile << inspect_image(score) << endl;
    vector<vector<Point> > contours = get_contours(score, 100);
    vector<Point> contour = find_biggest_contour(contours);
    string s = inspect_countour(contour);
    cout << s << endl;
    outputFile << s << endl;
    outputFile.close();
    cout << "Output on file: " << name << endl;
    cout << "------------------------------------------" << endl;
}

int main(int, char** argv){
    cout << "------------------------------------------" << endl;
    if (is_file(argv[1]))
        file_info(argv[1]);
    else{
        vector<string> filelist = list_files(argv[1]);
        for (int i = 0 ; i < filelist.size() ; i++){
            std::stringstream ss;
            ss << argv[1] << filelist[i];
            file_info(ss.str().c_str());
        }
    }
    cout << "Finished!\n";
    return(0);
}

