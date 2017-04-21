#include <string>
#include <iostream>
#include <gd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/lexical_cast.hpp>
#include <zbar.h>
#include <qrencode.h>
#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "qr_handler.h"
using namespace std;
using namespace zbar;
using namespace cv;

gdImagePtr QR_Handler::generate(string message) {
	int version = 3;
	QRecLevel level = QR_ECLEVEL_Q;
	QRencodeMode hint = QR_MODE_8;
	int casesensitive =1;
	int int_bg_color[3] = {255,255,255};
	int int_fg_color [3] = {0,0,0};
	int size = 100;
	int margin = 2;
	QRcode* code = QRcode_encodeString(message.c_str(),version,level,hint,casesensitive);
	if (code == NULL) {
		printf("An unknown error occured when encoding the string.\n");
		return NULL;
	}
	gdImagePtr im = qrcode_png(code,int_fg_color,int_bg_color,size,margin);
	QRcode_free(code);
	return im;
}

gdImagePtr QR_Handler::qrcode_png(QRcode* code, int fg_color[3], int bg_color[3], int size, int margin) {
	int code_size = size / code->width;
	code_size = (code_size == 0)  ? 1 : code_size;
	int img_width = code->width * code_size + 2 * margin;
	gdImagePtr img = gdImageCreate(img_width,img_width);
	int img_fgcolor = gdImageColorAllocate(img, fg_color[0],fg_color[1], fg_color[2]);
	int img_bgcolor = gdImageColorAllocate(img, bg_color[0], bg_color[1], bg_color[2]);
	gdImageFill(img, 0, 0, img_bgcolor);
	unsigned char *p = code->data;
	int x, y, posx, posy;
	for (y = 0; y < code->width; y++) {
		for (x = 0; x < code->width; x++) {
			if (*p & 1) {
				posx = x * code_size + margin;
				posy = y * code_size + margin;
				gdImageFilledRectangle(img,posx,posy,posx + code_size,posy + code_size,img_fgcolor);
			}
			p++;
		}
	}
	return img;
}

string QR_Handler::read(Mat img) {
	zbar::ImageScanner scanner;
	if (!img.data) {
		cout << "COULDN'T FIND FILE" << endl;
		return NULL;
	}
	Mat grey;
	cvtColor(img, grey, CV_BGR2GRAY);
	uchar* raw = (uchar*) grey.data;
	zbar::Image image(img.cols, img.rows, "Y800", raw, img.cols * img.rows);
	scanner.scan(image);
	for (zbar::Image::SymbolIterator symbol = image.symbol_begin(); symbol != image.symbol_end(); ++symbol) {
		return symbol->get_data();
	}
	return NULL;
}

string QR_Handler::readFromFile(string dir) {
	// NOT IMPLEMENTED
	return "not implemented";
}

bool generateToFile(string dir) {
	// NOT IMPLEMENTED
	return false;
}
