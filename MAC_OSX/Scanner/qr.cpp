#include <zbar.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


using namespace cv;
using namespace std;
using namespace zbar;

int main(int argc, char* argv[])
{

	ImageScanner scanner;
	if (argc == 2) {
		Mat image_test;
		image_test = imread(argv[1], CV_LOAD_IMAGE_COLOR);
		if (!image_test.data) {
			cout <<"COUDNT FIND" << endl;
			return 0;
		}
		Mat to_grey;
		cvtColor(image_test, to_grey, CV_BGR2GRAY);
		uchar *raw_data = (uchar *)to_grey.data;
		Image image_read(image_test.cols, image_test.rows, "Y800", raw_data, image_test.cols * image_test.rows);
		int n = scanner.scan(image_read);
		for (Image::SymbolIterator symbol = image_read.symbol_begin(); symbol != image_read.symbol_end(); ++symbol) {
			cout << symbol->get_data() << endl;
		}
		return 0;
	} else {

		VideoCapture cap(0);
		if (!cap.isOpened())
		{
			cout << "Failed to open video source 0!" << endl;
			return -1;
		}


		scanner.set_config(ZBAR_NONE, ZBAR_CFG_ENABLE, 1);
		double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH);
		double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT);


		cout << "Frame size : " << dWidth << " x " << dHeight << endl;
		namedWindow("BHDT QR Test",CV_WINDOW_AUTOSIZE);
		while (1)
		{
			Mat frame;
			bool read = cap.read(frame);
			if (!read) {
				cout << "Cannot read a frame from video stream" << endl;
				break;
			}
			Mat grey;
			cvtColor(frame,grey,CV_BGR2GRAY);
			int width = frame.cols;
			int height = frame.rows;
			uchar *raw = (uchar *)grey.data;
			Image image(width, height, "Y800", raw, width * height);
			int n = scanner.scan(image);
			for(Image::SymbolIterator symbol = image.symbol_begin(); symbol != image.symbol_end(); ++symbol) {
				vector<Point> vp;
				//print results for now
				cout << "Decoded " << symbol->get_type_name() << ". Data: " << symbol->get_data() << endl;
				int n = symbol->get_location_size();
				for(int i=0;i<n;i++) {
					vp.push_back(Point(symbol->get_location_x(i),symbol->get_location_y(i)));
				}
				RotatedRect r = minAreaRect(vp);
				Point2f pts[4];
				r.points(pts);
				for(int i=0;i<4;i++){
					line(frame,pts[i],pts[(i+1)%4],Scalar(255,0,0),3);
				}
			}
			imshow("BHDT QR Test", frame);
			if (waitKey(30) == 27) {
				cout << "Esc pressed. exiting..." << endl;
				break;
			}
		}
	}
	return 0;
}
