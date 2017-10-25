#include "loginfrm.h"
#include "ui_loginfrm.h"
#include "user.h"
#include <QMessageBox>
#include "mainwindow.h"
#include "splash.h"

LoginFrm::LoginFrm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginFrm)
{
    ui->setupUi(this);
}

LoginFrm::~LoginFrm()
{
    delete ui;
}

void LoginFrm::on_loginBtn_clicked()
{
    user usr;
    QString un=ui->unameTxt->text();
    QString pwd=ui->pwdTxt->text();

    if(ui->unameTxt->text()!="" && ui->pwdTxt->text()!=""){
        int x=usr.login(un,pwd);
        if(x==10){
            this->hide();
            MainWindow *mw=new MainWindow;
            mw->show();
        }else if(x==2){
            QMessageBox::information(0, "Login", "Wrong Username OR Password.");
        }
    }else{
        QMessageBox::information(0, "Login Details", "Please Enter the Username and Password Both to Log In.");
    }
}
