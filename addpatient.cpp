#include "addpatient.h"
#include "ui_addpatient.h"
#include "patient.h"
#include <QMessageBox>

addPatient::addPatient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::addPatient)
{
    ui->setupUi(this);
}

addPatient::~addPatient()
{
    delete ui;
}

void addPatient::on_saveBtn_clicked()
{
    if(ui->nicTxt->text()!="" && ui->nameTxt->text()!="" && ui->phoneTxt->text()!="" && ui->addressTxt->text()!=""){
        Patient ptn;
        if(ptn.searchPatient(ui->nicTxt->text())=="no"){
            ptn.addPatient(ui->nicTxt->text(),ui->nameTxt->text(),ui->phoneTxt->text(),ui->addressTxt->text());
            QMessageBox::information(0, "Success", "Patient Registered.");
        }else{
            QMessageBox::information(0, "NIC Available.", "This NIC number already registered. Please check again.");
        }
    }else{
        QMessageBox::information(0, "Fill Details", "Please Complete All The Fields.");
    }
}
