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

vector<string> list_files(const char* dirname);
int is_file(const char *path);

Mat open_image(const string& filename);
Mat crop_image(Mat src, Rect rect);

string print_points(vector<Point> points);
string print_points(vector<Point2f> points);
string print_points(Point2f points[], int length);

vector<vector<Point> > get_contours(Mat src, int canny_threshold);
vector<Point> find_biggest_contour(vector<vector<Point> > contours);
Mat crop_to_contour(Mat src, vector<vector<Point> >contours);
Point2f calculate_mass_center(vector<Point> contour);
void find_corners(vector<Point> contour, Point2f corners[4]);
void get_rect_corners(RotatedRect min_rect, Point2f dst[4]);
Mat crop_score(Mat src, int canny_threshold);

string inspect_countour(vector<Point> contour);
string inspect_image(Mat image);

