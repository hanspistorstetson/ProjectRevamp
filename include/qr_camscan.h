#ifndef QR_CAMSCAN_H
#define QR_CAMSCAN_H

#include <string>

using namespace std;

class QR_CamScan {
	private:
		bool killSwitch;
	public:
		QR_CamScan(){ killSwitch = false; }
		~QR_CamScan();
		string scan();
};

#endif
