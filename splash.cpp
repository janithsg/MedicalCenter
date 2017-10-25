#include "splash.h"
#include "ui_splash.h"
#include <windows.h>
#include "loginfrm.h"

Splash::Splash(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Splash)
{
    ui->setupUi(this);
    showTxt();
}

Splash::~Splash()
{
    delete ui;
}

void Splash::showTxt(){
    ui->logTxt->setText("Loading");
    Sleep(uint(1000));
    ui->progBar->setValue(10);
    Sleep(uint(250));
    ui->logTxt->setText("Initializing UI");
    Sleep(uint(250));
    ui->progBar->setValue(35);
    Sleep(uint(250));
    ui->progBar->setValue(45);
    Sleep(uint(250));
    ui->progBar->setValue(55);
    ui->logTxt->setText("Checking Data Files");
    Sleep(uint(100));
    ui->progBar->setValue(55);
    Sleep(uint(100));
    ui->progBar->setValue(65);
    Sleep(uint(100));
    ui->progBar->setValue(75);
    Sleep(uint(1000));
    ui->logTxt->setText("Done!");
    Sleep(uint(500));
    LoginFrm *lf=new LoginFrm;
    this->hide();
    lf->show();
}
