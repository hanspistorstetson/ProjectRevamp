CONFIG += console c++11
INCLUDEPATH += "C:/Users/DevelVM/Desktop/OpenCV/install/include/"
INCLUDEPATH += "C:/Program Files (x86)/ZBar/include/"

QT += core gui

TEMPLATE = app

LIBS += C:\Users\DevelVM\Desktop\OpenCV\install\x86\mingw\bin\libopencv_core320.dll
LIBS += C:\Users\DevelVM\Desktop\OpenCV\install\x86\mingw\bin\libopencv_highgui320.dll
LIBS += C:\Users\DevelVM\Desktop\OpenCV\install\x86\mingw\bin\libopencv_imgcodecs320.dll
LIBS += C:\Users\DevelVM\Desktop\OpenCV\install\x86\mingw\bin\libopencv_imgproc320.dll
LIBS += C:\Users\DevelVM\Desktop\OpenCV\install\x86\mingw\bin\libopencv_features2d320.dll
LIBS += C:\Users\DevelVM\Desktop\OpenCV\install\x86\mingw\bin\libopencv_calib3d320.dll
LIBS += C:\Users\DevelVM\Desktop\OpenCV\install\x86\mingw\bin\libopencv_videoio320.dll
LIBS += 'C:\Program Files (x86)\ZBar\bin\libzbar-0.dll'

SOURCES += \
    qr_handler.cpp \
    qr_camscan.cpp \
    test.cpp \
    BitBuffer.cpp \
    QrCode.cpp \
    QrSegment.cpp

INCLUDEPATH += include\

HEADERS += \
        include\qr_handler.h \
        include\qr_camscan.h

INCLUDEPATH += $$PWD/'../../../../../Program Files (x86)/ZBar/include'
DEPENDPATH += $$PWD/'../../../../../Program Files (x86)/ZBar/include'
