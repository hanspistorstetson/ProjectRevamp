#ifndef QR_CAMSCAN_H
#define QR_CAMSCAN_H

#include <string>

using namespace std;

class QR_CamScan
{
	public:
		QR_CamScan(){}
		~QR_CamScan();
		string scan();
};

#endif // QR_CAMSCAN_H
