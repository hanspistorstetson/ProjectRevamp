#ifndef QRNOTFOUND_H
#define QRNOTFOUND_H

#include <QDialog>

namespace Ui {
class QrnotFound;
}

class QrnotFound : public QDialog
{
    Q_OBJECT

public:
    explicit QrnotFound(QWidget *parent = 0);
    ~QrnotFound();

private:
    Ui::QrnotFound *ui;
};

#endif // QRNOTFOUND_H
