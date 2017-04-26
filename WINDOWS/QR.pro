CONFIG += console c++11
INCLUDEPATH += "C:/Users/DevelVM/Desktop/OpenCV/install/include/"
INCLUDEPATH += "C:/Program Files (x86)/ZBar/include/"
INCLUDEPATH += "C:/qrencode/include/"

TEMPLATE = app

LIBS += C:\Users\DevelVM\Desktop\OpenCV\install\x86\mingw\bin\libopencv_core320.dll
LIBS += C:\Users\DevelVM\Desktop\OpenCV\install\x86\mingw\bin\libopencv_highgui320.dll
LIBS += C:\Users\DevelVM\Desktop\OpenCV\install\x86\mingw\bin\libopencv_imgcodecs320.dll
LIBS += C:\Users\DevelVM\Desktop\OpenCV\install\x86\mingw\bin\libopencv_imgproc320.dll
LIBS += C:\Users\DevelVM\Desktop\OpenCV\install\x86\mingw\bin\libopencv_features2d320.dll
LIBS += C:\Users\DevelVM\Desktop\OpenCV\install\x86\mingw\bin\libopencv_calib3d320.dll
LIBS += C:\Users\DevelVM\Desktop\OpenCV\install\x86\mingw\bin\libopencv_videoio320.dll

LIBS += -LC:/qrencode/dll \
    -lqrcodelib

SOURCES += \
    qr_handler.cpp \
    qr_camscan.cpp \
    test.cpp

INCLUDEPATH += include\

HEADERS += \
        include\qr_handler.h \
        include\qr_camscan.h

LIBS += -L$$PWD/'../../../../../Program Files (x86)/ZBar/lib/' -llibzbar-0
INCLUDEPATH += $$PWD/'../../../../../Program Files (x86)/ZBar/include'
DEPENDPATH += $$PWD/'../../../../../Program Files (x86)/ZBar/include'



INCLUDEPATH += $$PWD/../../GnuWin32/GetGnuWin32/gnuwin32/include
DEPENDPATH += $$PWD/../../GnuWin32/GetGnuWin32/gnuwin32/include

LIBS += -L$$PWD/../../GnuWin32/GetGnuWin32/gnuwin32/lib/ -llibgd

INCLUDEPATH += $$PWD/../../GnuWin32/GetGnuWin32/gnuwin32/include
DEPENDPATH += $$PWD/../../GnuWin32/GetGnuWin32/gnuwin32/include
