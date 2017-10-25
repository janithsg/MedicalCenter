#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "makeappointmentwindow.h"
#include "viewappointments.h"
#include "doctorsview.h"
#include "addpatient.h"
#include "viewpatient.h"
#include "loginfrm.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_makeAppBtn_clicked()
{
    MakeAppointmentWindow *maw=new MakeAppointmentWindow;
    maw->show();
}

void MainWindow::on_viewApps_clicked()
{
    ViewAppointments *va=new ViewAppointments;
    va->show();
}

void MainWindow::on_viewDocs_clicked()
{
    DoctorsView *dv=new DoctorsView;
    dv->show();
}

void MainWindow::on_addPat_clicked()
{
    addPatient *ap=new addPatient;
    ap->show();
}

void MainWindow::on_viewPat_clicked()
{
    ViewPatient *vp=new ViewPatient;
    vp->show();
}

void MainWindow::on_logBtn_clicked()
{
    this->hide();
    LoginFrm *lf=new LoginFrm;
    lf->show();
}
