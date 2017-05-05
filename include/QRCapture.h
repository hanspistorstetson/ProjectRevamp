#ifndef CAMERA_H
#define CAMERA_H

#include <QCamera>
#include <QCameraImageCapture>
#include <QMediaRecorder>
#include "database/activity.h"
#include "gui/activitywindow.h"

#include <QMainWindow>

namespace Ui { class Camera; }

class Camera : public QMainWindow
{
	Q_OBJECT

	public:
        Camera(QWidget*, Activity*, ActivityWindow*);
		~Camera();

	private slots:
		void setCamera(const QCameraInfo &cameraInfo);

		void startCamera();
		void stopCamera();

		void record();
		void pause();
		void stop();
		void setMuted(bool);

		void toggleLock();
		void takeImage();
		void displayCaptureError(int, QCameraImageCapture::Error, const QString &errorString);

		void configureCaptureSettings();
		void configureVideoSettings();
		void configureImageSettings();

		void displayRecorderError();
		void displayCameraError();

		void updateCameraDevice(QAction *action);

		void updateCameraState(QCamera::State);
		void updateCaptureMode();
		void updateRecorderState(QMediaRecorder::State state);
		void setExposureCompensation(int index);

		void updateRecordTime();

		void processCapturedImage(int requestId, const QImage &img);
		void updateLockStatus(QCamera::LockStatus, QCamera::LockChangeReason);

		void displayViewfinder();
		void displayCapturedImage();

		void readyForCapture(bool ready);
		void imageSaved(int id, const QString &fileName);

        void on_Cancel_released();

protected:
		void keyPressEvent(QKeyEvent *event);
		void keyReleaseEvent(QKeyEvent *event);
		void closeEvent(QCloseEvent *event);

	private:
		Ui::Camera *ui;
        Activity* current;
        ActivityWindow* win;

		QCamera *camera;
		QCameraImageCapture *imageCapture;
		QMediaRecorder* mediaRecorder;

		QImageEncoderSettings imageSettings;
		QAudioEncoderSettings audioSettings;
		QVideoEncoderSettings videoSettings;
		QString videoContainerFormat;
		bool isCapturingImage;
		bool applicationExiting;
};

#endif
