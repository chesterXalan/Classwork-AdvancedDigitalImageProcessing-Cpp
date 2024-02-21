#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

Mat matControl_1(Mat srcMat) {
    Mat dstMat(srcMat.rows, srcMat.cols, srcMat.type());
    int nChannels = srcMat.channels();
    int nRows = srcMat.rows;
    int nCols = srcMat.cols;

    for (int j = 0; j < nRows; j++) {
        uchar* srcData = srcMat.ptr<uchar>(j);
        uchar* dstData = dstMat.ptr<uchar>(j);
        for (int i = 0; i < nCols; i++) {
            dstData[nChannels * i + 2] = srcData[nChannels * i + 2];
            dstData[nChannels * i + 1] = srcData[nChannels * i + 1];
            dstData[nChannels * i + 0] = srcData[nChannels * i + 0];
        }
    }
    return dstMat;
}
Mat matControl_2(Mat srcMat) {
    Mat dstMat(srcMat.rows, srcMat.cols, srcMat.type());
    int nChannels = srcMat.channels();
    int nRows = srcMat.rows;
    int nCols = srcMat.cols * nChannels;

    for (int j = 0; j < nRows; j++) {
        uchar* srcData = srcMat.ptr<uchar>(j);
        uchar* dstData = dstMat.ptr<uchar>(j);
        for (int i = 0; i < nCols; i++) {
            *dstData++ = *srcData++;
        }
    }
    return dstMat;
}
Mat matControl_3(Mat srcMat) {
    Mat dstMat(srcMat.rows, srcMat.cols, srcMat.type());
    int nChannels = srcMat.channels();
    int nRows = srcMat.rows;
    int nCols = srcMat.cols * nChannels;
    int nStep = srcMat.step;

    uchar* srcData = srcMat.data;
    uchar* dstData = dstMat.data;
    for (int j = 0; j < nRows; j++) {
        for (int i = 0; i < nCols; i++) {
            *(dstData + i) = *(srcData + i);
        }
        srcData += nStep;
        dstData += nStep;
    }
    return dstMat;
}
Mat matControl_4(Mat srcMat) {
    Mat dstMat(srcMat.rows, srcMat.cols, srcMat.type());

    int nChannels = srcMat.channels();
    int nRows = srcMat.rows;
    int nCols = srcMat.cols;
    for (int j = 0; j < nRows; j++) {
        uchar* dstData = dstMat.ptr<uchar>(j);
        for (int i = 0; i < nCols; i++) {
            Vec3b srcPixel = srcMat.at<Vec3b>(j, i);
            *dstData++ = srcPixel[0];
            *dstData++ = srcPixel[1];
            *dstData++ = srcPixel[2];
        }
    }
    return dstMat;
}
Mat matControl_5(Mat srcMat) {
    Mat dstMat(srcMat.rows, srcMat.cols, srcMat.type());
    int nChannels = srcMat.channels();
    int nRows = srcMat.rows;
    int nCols = srcMat.cols * nChannels;

    if (srcMat.isContinuous()) {
        nCols *= nRows;
        nRows = 1;
    }

    for (int j = 0; j < nRows; j++) {
        uchar* srcData = srcMat.ptr<uchar>(j);
        uchar* dstData = dstMat.ptr<uchar>(j);
        for (int i = 0; i < nCols; i++) {
            *dstData++ = *srcData++;
        }
    }
    return dstMat;
}
Mat matControl_6(Mat srcMat) {
    Mat dstMat(srcMat.rows, srcMat.cols, srcMat.type());
    Mat_<Vec3b>::iterator it = srcMat.begin<Vec3b>();
    Mat_<Vec3b>::iterator itend = srcMat.end<Vec3b>();
    Mat_<Vec3b>::iterator dstIter = dstMat.begin<Vec3b>();

    for (; it != itend; ++it, ++dstIter) {
        (*dstIter)[0] = (*it)[0];
        (*dstIter)[1] = (*it)[1];
        (*dstIter)[2] = (*it)[2];
    }
    return dstMat;
}

int main() {
    Mat image = imread("images/12345.png");

    double time00 = static_cast<double>(getTickCount());
    matControl_1(image);
    double time01 = (static_cast<double>(getTickCount()) - time00) / getTickFrequency();
    cout << "matControl_1 time = " << time01 << " second" << endl;

    double time10 = static_cast<double>(getTickCount());
    matControl_2(image);
    double time11 = (static_cast<double>(getTickCount()) - time10) / getTickFrequency();
    cout << "matControl_2 time = " << time11 << " second" << endl;

    double time20 = static_cast<double>(getTickCount());
    matControl_3(image);
    double time21 = (static_cast<double>(getTickCount()) - time20) / getTickFrequency();
    cout << "matControl_3 time = " << time21 << " second" << endl;

    double time30 = static_cast<double>(getTickCount());
    matControl_4(image);
    double time31 = (static_cast<double>(getTickCount()) - time30) / getTickFrequency();
    cout << "matControl_4 time = " << time31 << " second" << endl;

    double time40 = static_cast<double>(getTickCount());
    matControl_5(image);
    double time41 = (static_cast<double>(getTickCount()) - time40) / getTickFrequency();
    cout << "matControl_5 time = " << time41 << " second" << endl;

    double time50 = static_cast<double>(getTickCount());
    matControl_6(image);
    double time51 = (static_cast<double>(getTickCount()) - time50) / getTickFrequency();
    cout << "matControl_6 time = " << time51 << " second" << endl;

    imshow("image", image);
    waitKey(0);
    return 0;
}