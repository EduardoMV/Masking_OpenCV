#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;
using namespace std;

void Binary() {
    Mat ori = imread("../flower.jpg", IMREAD_GRAYSCALE);
    //Mat ori2 = imread("../pear.jpg", IMREAD_GRAYSCALE);
    Mat msk(ori.rows, ori.cols, CV_8U, Scalar(0));

    for(int row = 0; row < ori.rows; row++){
        for(int col = 0; col < ori.cols; col++){
            if(ori.at<uchar>(row, col) > 125){
                msk.at<uchar>(row,col) = uchar(255);
            }
            else{
                msk.at<uchar>(row,col) = uchar(0);
            }
        }

    }

    namedWindow("PhotoFrame", WINDOW_NORMAL);
    imshow("PhotoFrame", msk);
    imwrite("Mask.jpg", msk);
    waitKey(0);
}

void Binary_Inv(){
    Mat ori = imread("../flower.jpg", IMREAD_GRAYSCALE);
    Mat msk_inv(ori.rows, ori.cols, CV_8U, Scalar(0));

    for(int row = 0; row < ori.rows; row++){
        for(int col = 0; col < ori.cols; col++){
            if(ori.at<uchar>(row, col) > 125){
                msk_inv.at<uchar>(row,col) = uchar(0);
            }
            else{
                msk_inv.at<uchar>(row,col) = uchar(255);
            }
        }

    }

    namedWindow("PhotoFrame", WINDOW_NORMAL);
    imshow("PhotoFrame", msk_inv);
    imwrite("Mask_Inv.jpg", msk_inv);
    waitKey(0);
}

void ToZero(){
    Mat ori = imread("../flower.jpg", IMREAD_GRAYSCALE);
    Mat msk_Z(ori.rows, ori.cols, CV_8U, Scalar(0));

    for(int row = 0; row < ori.rows; row++){
        for(int col = 0; col < ori.cols; col++){
            if(ori.at<uchar>(row, col) > 125){
                msk_Z.at<uchar>(row,col) = uchar(ori.at<uchar>(row,col));
            }
            else{
                msk_Z.at<uchar>(row,col) = uchar(0);
            }
        }

    }

    namedWindow("PhotoFrame", WINDOW_NORMAL);
    imshow("PhotoFrame", msk_Z);
    imwrite("MaskZ.jpg", msk_Z);
    waitKey(0);
}

void ToZero_Inv(){
    Mat ori = imread("../flower.jpg", IMREAD_GRAYSCALE);
    Mat msk_Z(ori.rows, ori.cols, CV_8U, Scalar(0));

    for(int row = 0; row < ori.rows; row++){
        for(int col = 0; col < ori.cols; col++){
            if(ori.at<uchar>(row, col) > 125){
                msk_Z.at<uchar>(row,col) = uchar(0);
            }
            else{
                msk_Z.at<uchar>(row,col) = uchar(ori.at<uchar>(row,col));
            }
        }

    }

    namedWindow("PhotoFrame", WINDOW_NORMAL);
    imshow("PhotoFrame", msk_Z);
    imwrite("MaskZ_Inv.jpg", msk_Z);
    waitKey(0);
}

void Trunc(){
    Mat ori = imread("../flower.jpg", IMREAD_GRAYSCALE);
    Mat msk_Trunc(ori.rows, ori.cols, CV_8U, Scalar(0));

    int thresholdValue = 125;

    for (int row = 0; row < ori.rows; row++) {
        for (int col = 0; col < ori.cols; col++) {
            if (ori.at<uchar>(row, col) > thresholdValue) {
                msk_Trunc.at<uchar>(row, col) = ori.at<uchar>(row, col);
            }
            else {
                msk_Trunc.at<uchar>(row, col) = thresholdValue;
            }
        }
    }

    namedWindow("PhotoFrame", WINDOW_NORMAL);
    imshow("PhotoFrame", msk_Trunc);
    imwrite("MaskTrunc.jpg", msk_Trunc);
    waitKey(0);
}

void Trunc2(){
    Mat ori = imread("../flower.jpg", IMREAD_GRAYSCALE);
    Mat msk_Trunc(ori.rows, ori.cols, CV_8U, Scalar(0));

    int thresholdValue = 128;

    for (int row = 0; row < ori.rows; row++) {
        for (int col = 0; col < ori.cols; col++) {
            if (ori.at<uchar>(row, col) < thresholdValue) {
                msk_Trunc.at<uchar>(row, col) = ori.at<uchar>(row, col);
            }
            else {
                msk_Trunc.at<uchar>(row, col) = 255;
            }
        }
    }

    namedWindow("PhotoFrame", WINDOW_NORMAL);
    imshow("PhotoFrame", msk_Trunc);
    imwrite("MaskTrunc2.jpg", msk_Trunc);
    waitKey(0);
}

int main() {
    Trunc2();
    return 0;
}
