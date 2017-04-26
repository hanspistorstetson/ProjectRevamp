#include "gui/activitycreatewindow.h"
#include "ui_activitycreatewindow.h"
#include "prereqselectwindow.h"
#include "database/activity.h"
<<<<<<< HEAD
=======
#include <iostream>
using namespace std;
>>>>>>> 89dba38977700c57be3237640ab0ed3469e363c5
#include "gui/prereqselectwindow.h"

ActivityCreateWindow::ActivityCreateWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ActivityCreateWindow)
{
    ui->setupUi(this);
}

ActivityCreateWindow::~ActivityCreateWindow()
{
    delete ui;
}

void ActivityCreateWindow::on_cancelButton_released()
{
    this->close();
}

void ActivityCreateWindow::on_createActivityButton_released()
{
    /* This will take data in textfields
     * and then pass to controller
     * then close window
     */
    std::string name = ui->actNameTF->text().toStdString();
    std::string status;
   //get activity status
   if(ui->activeRadioButton->isChecked())
   {
       status="active";
   }
   if(ui->upcomingRadioButton->isChecked())
   {
       status="upcoming";
   }
   Activity::createActivity(name,1,status);
    this->close();
}

void ActivityCreateWindow::on_preReqSelectButton_released()
{

    PrereqSelectWindow psw;
    psw.setModal(true);
    psw.exec();


}
