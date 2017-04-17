#ifndef QR_HANDLER_H
#define QR_HANDLER_H
#include <opencv2/core/core.hpp>
#include <string>
#include <gd.h>

class QR_Handler{
	public:
		QR_Handler(){};
		gdImagePtr generate(std::string);
		std::string read(cv::Mat);
	private:
		gdImagePtr qrcode_png (QRcode*, int[], int[], int, int);	

};



#endif
