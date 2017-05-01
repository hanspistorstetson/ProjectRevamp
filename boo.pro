QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

boo {
    TARGET = boo
    TEMPLATE = app
    
SOURCES += main.cpp\
    gui/mainwindow.cpp \
    gui/eventcreatewindow.cpp \
    gui/eventadminwindow.cpp \
    gui/usercreatewindow.cpp \
    gui/activitycreatewindow.cpp \
    gui/listactivities.cpp \
    gui/activitysearch.cpp \
    gui/activitywindow.cpp \
    gui/checkinwindow.cpp \
    gui/qrcodefound.cpp \
    gui/qrnotfound.cpp \
	gui/user_list.cpp \
	gui/user_search.cpp \
	gui/user_view.cpp\
    database/activity.cpp \
    database/checkin.cpp \
    database/database.cpp \
    database/event.cpp \
    database/user.cpp \
    database/sqlite3.c \
    gui/prereqselectwindow.cpp
    database/dbtest.cpp \


HEADERS  += gui/mainwindow.h \
    gui/eventcreatewindow.h \
    gui/eventadminwindow.h \
    gui/usercreatewindow.h \
    gui/activitycreatewindow.h \
    gui/listactivities.h \
    gui/activitysearch.h \
    gui/activitywindow.h \
    gui/checkinwindow.h \
    gui/qrcodefound.h \
    gui/qrnotfound.h \
	gui/user_list.h \
	gui/user_search.h \
	gui/user_view.h \
    database/activity.h \
    database/checkin.h \
    database/database.h \
    database/event.h \
    database/user.h \
    database/sqlite3.h \
    database/dbtest.h \
    gui/prereqselectwindow.h

FORMS    += gui/mainwindow.ui \
    gui/eventcreatewindow.ui \
    gui/eventadminwindow.ui \
    gui/usercreatewindow.ui \
    gui/activitycreatewindow.ui \
    gui/listactivities.ui \
    gui/activitysearch.ui \
    gui/activitywindow.ui \
    gui/checkinwindow.ui \
    gui/qrcodefound.ui \
    gui/qrnotfound.ui \
	gui/user_list.ui \
	gui/user_search.ui \
	gui/user_view.ui \ 
    gui/prereqselectwindow.ui

DISTFILES += README.txt \
    boo.pro.user

}

test {
    TARGET = dbtest
    TEMPLATE = app
    
    SOURCES += test.cpp \
    database/database.cpp \
    database/event.cpp \
    database/user.cpp \
    database/checkin.cpp \
    database/activity.cpp \
    database/sqlite3.c \
    database/dbtest.cpp

    HEADERS += database/database.h \
    database/event.h \
    database/user.h \
    database/checkin.h \
    database/activity.h \
    database/sqlite3.h \
    database/dbtest.h

}

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    include/gen/BitBuffer.hpp \
    include/gen/QrCode.hpp \
    include/gen/QrSegment.hpp \
    include/QRHandler.h \
    include/QRScanner.h \
    scan/zxing/bigint/BigInteger.hh \
    scan/zxing/bigint/BigIntegerAlgorithms.hh \
    scan/zxing/bigint/BigIntegerLibrary.hh \
    scan/zxing/bigint/BigIntegerUtils.hh \
    scan/zxing/bigint/BigUnsigned.hh \
    scan/zxing/bigint/BigUnsignedInABase.hh \
    scan/zxing/bigint/NumberlikeArray.hh \
    scan/zxing/win32/zxing/msvc/stdint.h \
    scan/zxing/win32/zxing/iconv.h \
    scan/zxing/zxing/aztec/decoder/Decoder.h \
    scan/zxing/zxing/aztec/detector/Detector.h \
    scan/zxing/zxing/aztec/AztecDetectorResult.h \
    scan/zxing/zxing/aztec/AztecReader.h \
    scan/zxing/zxing/common/detector/JavaMath.h \
    scan/zxing/zxing/common/detector/MathUtils.h \
    scan/zxing/zxing/common/detector/MonochromeRectangleDetector.h \
    scan/zxing/zxing/common/detector/WhiteRectangleDetector.h \
    scan/zxing/zxing/common/reedsolomon/GenericGF.h \
    scan/zxing/zxing/common/reedsolomon/GenericGFPoly.h \
    scan/zxing/zxing/common/reedsolomon/ReedSolomonDecoder.h \
    scan/zxing/zxing/common/reedsolomon/ReedSolomonEncoder.h \
    scan/zxing/zxing/common/reedsolomon/ReedSolomonException.h \
    scan/zxing/zxing/common/Array.h \
    scan/zxing/zxing/common/BitArray.h \
    scan/zxing/zxing/common/BitMatrix.h \
    scan/zxing/zxing/common/BitSource.h \
    scan/zxing/zxing/common/CharacterSetECI.h \
    scan/zxing/zxing/common/Counted.h \
    scan/zxing/zxing/common/DecoderResult.h \
    scan/zxing/zxing/common/DetectorResult.h \
    scan/zxing/zxing/common/GlobalHistogramBinarizer.h \
    scan/zxing/zxing/common/GreyscaleLuminanceSource.h \
    scan/zxing/zxing/common/GreyscaleRotatedLuminanceSource.h \
    scan/zxing/zxing/common/GridSampler.h \
    scan/zxing/zxing/common/HybridBinarizer.h \
    scan/zxing/zxing/common/IllegalArgumentException.h \
    scan/zxing/zxing/common/PerspectiveTransform.h \
    scan/zxing/zxing/common/Point.h \
    scan/zxing/zxing/common/Str.h \
    scan/zxing/zxing/common/StringUtils.h \
    scan/zxing/zxing/common/Types.h \
    scan/zxing/zxing/datamatrix/decoder/BitMatrixParser.h \
    scan/zxing/zxing/datamatrix/decoder/DataBlock.h \
    scan/zxing/zxing/datamatrix/decoder/DecodedBitStreamParser.h \
    scan/zxing/zxing/datamatrix/decoder/Decoder.h \
    scan/zxing/zxing/datamatrix/detector/CornerPoint.h \
    scan/zxing/zxing/datamatrix/detector/Detector.h \
    scan/zxing/zxing/datamatrix/detector/DetectorException.h \
    scan/zxing/zxing/datamatrix/DataMatrixReader.h \
    scan/zxing/zxing/datamatrix/Version.h \
    scan/zxing/zxing/multi/qrcode/detector/MultiDetector.h \
    scan/zxing/zxing/multi/qrcode/detector/MultiFinderPatternFinder.h \
    scan/zxing/zxing/multi/qrcode/QRCodeMultiReader.h \
    scan/zxing/zxing/multi/ByQuadrantReader.h \
    scan/zxing/zxing/multi/GenericMultipleBarcodeReader.h \
    scan/zxing/zxing/multi/MultipleBarcodeReader.h \
    scan/zxing/zxing/oned/CodaBarReader.h \
    scan/zxing/zxing/oned/Code128Reader.h \
    scan/zxing/zxing/oned/Code39Reader.h \
    scan/zxing/zxing/oned/Code93Reader.h \
    scan/zxing/zxing/oned/EAN13Reader.h \
    scan/zxing/zxing/oned/EAN8Reader.h \
    scan/zxing/zxing/oned/ITFReader.h \
    scan/zxing/zxing/oned/MultiFormatOneDReader.h \
    scan/zxing/zxing/oned/MultiFormatUPCEANReader.h \
    scan/zxing/zxing/oned/OneDReader.h \
    scan/zxing/zxing/oned/OneDResultPoint.h \
    scan/zxing/zxing/oned/UPCAReader.h \
    scan/zxing/zxing/oned/UPCEANReader.h \
    scan/zxing/zxing/oned/UPCEReader.h \
    scan/zxing/zxing/pdf417/decoder/ec/ErrorCorrection.h \
    scan/zxing/zxing/pdf417/decoder/ec/ModulusGF.h \
    scan/zxing/zxing/pdf417/decoder/ec/ModulusPoly.h \
    scan/zxing/zxing/pdf417/decoder/BitMatrixParser.h \
    scan/zxing/zxing/pdf417/decoder/DecodedBitStreamParser.h \
    scan/zxing/zxing/pdf417/decoder/Decoder.h \
    scan/zxing/zxing/pdf417/detector/Detector.h \
    scan/zxing/zxing/pdf417/detector/LinesSampler.h \
    scan/zxing/zxing/pdf417/PDF417Reader.h \
    scan/zxing/zxing/qrcode/decoder/BitMatrixParser.h \
    scan/zxing/zxing/qrcode/decoder/DataBlock.h \
    scan/zxing/zxing/qrcode/decoder/DataMask.h \
    scan/zxing/zxing/qrcode/decoder/DecodedBitStreamParser.h \
    scan/zxing/zxing/qrcode/decoder/Decoder.h \
    scan/zxing/zxing/qrcode/decoder/Mode.h \
    scan/zxing/zxing/qrcode/detector/AlignmentPattern.h \
    scan/zxing/zxing/qrcode/detector/AlignmentPatternFinder.h \
    scan/zxing/zxing/qrcode/detector/Detector.h \
    scan/zxing/zxing/qrcode/detector/FinderPattern.h \
    scan/zxing/zxing/qrcode/detector/FinderPatternFinder.h \
    scan/zxing/zxing/qrcode/detector/FinderPatternInfo.h \
    scan/zxing/zxing/qrcode/encoder/BlockPair.h \
    scan/zxing/zxing/qrcode/encoder/ByteMatrix.h \
    scan/zxing/zxing/qrcode/encoder/Encoder.h \
    scan/zxing/zxing/qrcode/encoder/MaskUtil.h \
    scan/zxing/zxing/qrcode/encoder/MatrixUtil.h \
    scan/zxing/zxing/qrcode/encoder/QRCode.h \
    scan/zxing/zxing/qrcode/ErrorCorrectionLevel.h \
    scan/zxing/zxing/qrcode/FormatInformation.h \
    scan/zxing/zxing/qrcode/QRCodeReader.h \
    scan/zxing/zxing/qrcode/Version.h \
    scan/zxing/zxing/BarcodeFormat.h \
    scan/zxing/zxing/Binarizer.h \
    scan/zxing/zxing/BinaryBitmap.h \
    scan/zxing/zxing/ChecksumException.h \
    scan/zxing/zxing/DecodeHints.h \
    scan/zxing/zxing/EncodeHint.h \
    scan/zxing/zxing/Exception.h \
    scan/zxing/zxing/FormatException.h \
    scan/zxing/zxing/IllegalStateException.h \
    scan/zxing/zxing/InvertedLuminanceSource.h \
    scan/zxing/zxing/LuminanceSource.h \
    scan/zxing/zxing/MultiFormatReader.h \
    scan/zxing/zxing/NotFoundException.h \
    scan/zxing/zxing/Reader.h \
    scan/zxing/zxing/ReaderException.h \
    scan/zxing/zxing/Result.h \
    scan/zxing/zxing/ResultPoint.h \
    scan/zxing/zxing/ResultPointCallback.h \
    scan/zxing/zxing/UnsupportedEncodingException.h \
    scan/zxing/zxing/WriterException.h \
    scan/zxing/zxing/ZXing.h \
    scan/CameraImageWrapper.h \
    scan/ImageHandler.h \
    scan/QZXing.h \
    scan/QZXing_global.h \
    scan/QZXingFilter.h \
    scan/QZXingImageProvider.h

SOURCES += \
    gen/BitBuffer.cpp \
    gen/QrCode.cpp \
    gen/QrSegment.cpp \
    scan/zxing/bigint/BigInteger.cc \
    scan/zxing/bigint/BigIntegerAlgorithms.cc \
    scan/zxing/bigint/BigIntegerUtils.cc \
    scan/zxing/bigint/BigUnsigned.cc \
    scan/zxing/bigint/BigUnsignedInABase.cc \
    scan/zxing/zxing/aztec/decoder/AztecDecoder.cpp \
    scan/zxing/zxing/aztec/detector/AztecDetector.cpp \
    scan/zxing/zxing/aztec/AztecDetectorResult.cpp \
    scan/zxing/zxing/aztec/AztecReader.cpp \
    scan/zxing/zxing/common/detector/MonochromeRectangleDetector.cpp \
    scan/zxing/zxing/common/detector/WhiteRectangleDetector.cpp \
    scan/zxing/zxing/common/reedsolomon/GenericGF.cpp \
    scan/zxing/zxing/common/reedsolomon/GenericGFPoly.cpp \
    scan/zxing/zxing/common/reedsolomon/ReedSolomonDecoder.cpp \
    scan/zxing/zxing/common/reedsolomon/ReedSolomonEncoder.cpp \
    scan/zxing/zxing/common/reedsolomon/ReedSolomonException.cpp \
    scan/zxing/zxing/common/BitArray.cpp \
    scan/zxing/zxing/common/BitArrayIO.cpp \
    scan/zxing/zxing/common/BitMatrix.cpp \
    scan/zxing/zxing/common/BitSource.cpp \
    scan/zxing/zxing/common/CharacterSetECI.cpp \
    scan/zxing/zxing/common/DecoderResult.cpp \
    scan/zxing/zxing/common/DetectorResult.cpp \
    scan/zxing/zxing/common/GlobalHistogramBinarizer.cpp \
    scan/zxing/zxing/common/GreyscaleLuminanceSource.cpp \
    scan/zxing/zxing/common/GreyscaleRotatedLuminanceSource.cpp \
    scan/zxing/zxing/common/GridSampler.cpp \
    scan/zxing/zxing/common/HybridBinarizer.cpp \
    scan/zxing/zxing/common/IllegalArgumentException.cpp \
    scan/zxing/zxing/common/PerspectiveTransform.cpp \
    scan/zxing/zxing/common/Str.cpp \
    scan/zxing/zxing/common/StringUtils.cpp \
    scan/zxing/zxing/datamatrix/decoder/DataMatrixBitMatrixParser.cpp \
    scan/zxing/zxing/datamatrix/decoder/DataMatrixDataBlock.cpp \
    scan/zxing/zxing/datamatrix/decoder/DataMatrixDecodedBitStreamParser.cpp \
    scan/zxing/zxing/datamatrix/decoder/DataMatrixDecoder.cpp \
    scan/zxing/zxing/datamatrix/detector/DataMatrixCornerPoint.cpp \
    scan/zxing/zxing/datamatrix/detector/DataMatrixDetector.cpp \
    scan/zxing/zxing/datamatrix/detector/DataMatrixDetectorException.cpp \
    scan/zxing/zxing/datamatrix/DataMatrixReader.cpp \
    scan/zxing/zxing/datamatrix/DataMatrixVersion.cpp \
    scan/zxing/zxing/multi/qrcode/detector/MultiDetector.cpp \
    scan/zxing/zxing/multi/qrcode/detector/MultiFinderPatternFinder.cpp \
    scan/zxing/zxing/multi/qrcode/QRCodeMultiReader.cpp \
    scan/zxing/zxing/multi/ByQuadrantReader.cpp \
    scan/zxing/zxing/multi/GenericMultipleBarcodeReader.cpp \
    scan/zxing/zxing/multi/MultipleBarcodeReader.cpp \
    scan/zxing/zxing/oned/CodaBarReader.cpp \
    scan/zxing/zxing/oned/Code128Reader.cpp \
    scan/zxing/zxing/oned/Code39Reader.cpp \
    scan/zxing/zxing/oned/Code93Reader.cpp \
    scan/zxing/zxing/oned/EAN13Reader.cpp \
    scan/zxing/zxing/oned/EAN8Reader.cpp \
    scan/zxing/zxing/oned/ITFReader.cpp \
    scan/zxing/zxing/oned/MultiFormatOneDReader.cpp \
    scan/zxing/zxing/oned/MultiFormatUPCEANReader.cpp \
    scan/zxing/zxing/oned/OneDReader.cpp \
    scan/zxing/zxing/oned/OneDResultPoint.cpp \
    scan/zxing/zxing/oned/UPCAReader.cpp \
    scan/zxing/zxing/oned/UPCEANReader.cpp \
    scan/zxing/zxing/oned/UPCEReader.cpp \
    scan/zxing/zxing/pdf417/decoder/ec/ErrorCorrection.cpp \
    scan/zxing/zxing/pdf417/decoder/ec/ModulusGF.cpp \
    scan/zxing/zxing/pdf417/decoder/ec/ModulusPoly.cpp \
    scan/zxing/zxing/pdf417/decoder/PDF417BitMatrixParser.cpp \
    scan/zxing/zxing/pdf417/decoder/PDF417DecodedBitStreamParser.cpp \
    scan/zxing/zxing/pdf417/decoder/PDF417Decoder.cpp \
    scan/zxing/zxing/pdf417/detector/LinesSampler.cpp \
    scan/zxing/zxing/pdf417/detector/PDF417Detector.cpp \
    scan/zxing/zxing/pdf417/PDF417Reader.cpp \
    scan/zxing/zxing/qrcode/decoder/QRBitMatrixParser.cpp \
    scan/zxing/zxing/qrcode/decoder/QRDataBlock.cpp \
    scan/zxing/zxing/qrcode/decoder/QRDataMask.cpp \
    scan/zxing/zxing/qrcode/decoder/QRDecodedBitStreamParser.cpp \
    scan/zxing/zxing/qrcode/decoder/QRDecoder.cpp \
    scan/zxing/zxing/qrcode/decoder/QRMode.cpp \
    scan/zxing/zxing/qrcode/detector/QRAlignmentPattern.cpp \
    scan/zxing/zxing/qrcode/detector/QRAlignmentPatternFinder.cpp \
    scan/zxing/zxing/qrcode/detector/QRDetector.cpp \
    scan/zxing/zxing/qrcode/detector/QRFinderPattern.cpp \
    scan/zxing/zxing/qrcode/detector/QRFinderPatternFinder.cpp \
    scan/zxing/zxing/qrcode/detector/QRFinderPatternInfo.cpp \
    scan/zxing/zxing/qrcode/encoder/ByteMatrix.cpp \
    scan/zxing/zxing/qrcode/encoder/MaskUtil.cpp \
    scan/zxing/zxing/qrcode/encoder/MatrixUtil.cpp \
    scan/zxing/zxing/qrcode/encoder/QRCode.cpp \
    scan/zxing/zxing/qrcode/encoder/QREncoder.cpp \
    scan/zxing/zxing/qrcode/QRCodeReader.cpp \
    scan/zxing/zxing/qrcode/QRErrorCorrectionLevel.cpp \
    scan/zxing/zxing/qrcode/QRFormatInformation.cpp \
    scan/zxing/zxing/qrcode/QRVersion.cpp \
    scan/zxing/zxing/BarcodeFormat.cpp \
    scan/zxing/zxing/Binarizer.cpp \
    scan/zxing/zxing/BinaryBitmap.cpp \
    scan/zxing/zxing/ChecksumException.cpp \
    scan/zxing/zxing/DecodeHints.cpp \
    scan/zxing/zxing/EncodeHint.cpp \
    scan/zxing/zxing/Exception.cpp \
    scan/zxing/zxing/FormatException.cpp \
    scan/zxing/zxing/InvertedLuminanceSource.cpp \
    scan/zxing/zxing/LuminanceSource.cpp \
    scan/zxing/zxing/MultiFormatReader.cpp \
    scan/zxing/zxing/Reader.cpp \
    scan/zxing/zxing/Result.cpp \
    scan/zxing/zxing/ResultIO.cpp \
    scan/zxing/zxing/ResultPoint.cpp \
    scan/zxing/zxing/ResultPointCallback.cpp \
    scan/CameraImageWrapper.cpp \
    scan/ImageHandler.cpp \
    scan/QZXing.cpp \
    scan/QZXingFilter.cpp \
    scan/QZXingImageProvider.cpp \
    QRHandler.cpp \
    QRScanner.cpp \
    scan/zxing/win32/zxing/win_iconv.c


