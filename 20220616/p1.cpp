#include <opencv2/objdetect.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
using namespace cv; using namespace std;

void display(Mat & im, Mat & bbox) {
	int n = bbox.rows;
	for (int i = 0; i < n; i++) {
		line(im, Point2i(bbox.at<float>(i, 0), bbox.at<float>(i, 1)),
			Point2i(bbox.at<float>((i + 1) % n, 0), bbox.at<float>((i + 1) % n, 1)),
			Scalar(0, 0, 255), 3);
	}
}
int main(int argc, char* argv[]) {
	Mat inputImage = imread("images/qrcode.jpg");
	QRCodeDetector qrDecoder = QRCodeDetector::QRCodeDetector();
	Mat bbox, rectifiedImage;
	string data = qrDecoder.detectAndDecode(inputImage, bbox, rectifiedImage);

	if (data.length() > 0) {
		cout << "Decoded Data : " << data << endl;
		display(inputImage, bbox);
		rectifiedImage.convertTo(rectifiedImage, CV_8UC3);
		imshow("Rectified QRCode", rectifiedImage);
		waitKey(0);
	}
	else cout << "QR Code not detected" << endl;
}