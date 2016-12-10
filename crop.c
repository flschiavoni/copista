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

int canny_threshold = 180;
int max_thresh = 255;
void thresh_callback(int, void* );

// ----------------------------------------------------------------------------
void thresh_callback(int, void* data){
    Mat src = *(Mat*)data;
    Mat output = crop_score(src, canny_threshold);

    vector<vector<Point> > contours = get_contours(src, canny_threshold);
    vector<Point> contour = find_biggest_contour(contours);
    Rect rect = boundingRect(contour);
    rectangle(src, rect.tl(), rect.br(), Scalar(0,0,255), 10, 8, 0 );

    namedWindow("Source", WINDOW_NORMAL);
    imshow("Source", src);

    if (output.cols > 0 && output.rows > 0)
        imshow("Cropped", output);
}

// ----------------------------------------------------------------------------
void crop_file(const char * file){
    Mat src = open_image(file);
    if (src.empty()){
        cerr << "No image supplied ..." << endl;
        return;
    }

    namedWindow("Cropped", WINDOW_NORMAL);
    createTrackbar(" Canny thresh:", "Cropped", &canny_threshold, max_thresh, thresh_callback, (void *)&src);
    thresh_callback(0, (void *)&src);
    waitKey(0);
}


// ----------------------------------------------------------------------------
void crop_directory(const char * directory){
    vector<string> filelist = list_files(directory);
    for (int i = 0 ; i < filelist.size() ; i++){
        std::stringstream ss;
        ss << directory << filelist[i];
        Mat score = open_image(ss.str());
        if (score.empty()){
            cerr << "No image supplied ... "<<  filelist[i] << endl;
            continue;
        }
        score = crop_score(score, 100);
        cout << "Cropping " << ss.str();
        ss.str(std::string());
        ss.clear();
        ss << directory << "cropped/" << filelist[i];
        cout << " Saving to " << ss.str() << endl;
        imwrite(ss.str().c_str(), score);
    }
    cout << " -----------------------------------" << endl;
    cout << "Finished!\n";
}


// ----------------------------------------------------------------------------
int main(int, char** argv){
    if (is_file(argv[1]))
        crop_file(argv[1]);
    else
        crop_directory(argv[1]);
    return(0);
}

