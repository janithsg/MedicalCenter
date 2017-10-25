#include "makeappointmentwindow.h"
#include "ui_makeappointmentwindow.h"
#include "addpatient.h"
#include <patient.h>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QMessageBox>
#include <appointment.h>

MakeAppointmentWindow::MakeAppointmentWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MakeAppointmentWindow)
{
    ui->setupUi(this);

    QFile file("C:\\Medi\\Doctors.txt");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "File Error", file.errorString());
    }

    QTextStream in(&file);

    while(!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");

        ui->docListCmb->addItem(fields.at(1));
    }

    file.close();
}

MakeAppointmentWindow::~MakeAppointmentWindow()
{
    delete ui;
}

void MakeAppointmentWindow::on_searchBtn_clicked()
{
    Patient pt;
    QString res=pt.searchPatient(ui->patIdTxt->text());

    if(res=="yes"){
        QMessageBox::information(0, "Found.", "Patient Details Available.");
    }else if(res=="no"){
        QMessageBox::information(0, "Not Found.", "Patient Details Not Available.Please Register the Patient OR Check the ID again.");
    }
}

void MakeAppointmentWindow::on_addPatbtn_clicked()
{
    addPatient *ap=new addPatient;
    ap->show();
}

void MakeAppointmentWindow::on_docListCmb_currentIndexChanged(int index)
{
    QFile file("C:\\Medi\\Doctors.txt");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "File Error", file.errorString());
    }

    QTextStream in(&file);

    while(!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");

        ui->dateCmb->clear();
        ui->timeCmb->clear();
        ui->roomLbl->setText("");

        if(ui->docListCmb->itemText(index)==fields.at(1)){
            if(fields.at(3)=="y"){
                ui->dateCmb->addItem("Sunday");
            }
            if(fields.at(4)=="y"){
                ui->dateCmb->addItem("Monday");
            }
            if(fields.at(5)=="y"){
                ui->dateCmb->addItem("Tuesday");
            }
            if(fields.at(6)=="y"){
                ui->dateCmb->addItem("Wednesday");
            }
            if(fields.at(7)=="y"){
                ui->dateCmb->addItem("Thursday");
            }
            if(fields.at(8)=="y"){
                ui->dateCmb->addItem("Friday");
            }
            if(fields.at(9)=="y"){
                ui->dateCmb->addItem("Saturday");
            }
            ui->timeCmb->addItem(fields.at(10));
            ui->timeCmb->addItem(fields.at(11));
            ui->roomLbl->setText(fields.at(12));
            break;
        }
    }

}

void MakeAppointmentWindow::on_saveBtn_clicked()
{
    QFile file("C:\\Medi\\Appointments.txt");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "File Error", file.errorString());
    }

    QTextStream in(&file);
    int count=0;

    while(!in.atEnd()) {
        QString line = in.readLine();
        count=count+1;
    }
    file.close();

    QString appId="A00"+QString::number(count+1);

    if(ui->patIdTxt->text()!=""){
        Patient ptn;
        QString pn=ptn.getPatient(ui->patIdTxt->text());

        if(pn!=""){
            Appointment am;
            am.addAppointment(appId,pn,ui->docListCmb->itemText(0),ui->dateCmb->currentText(),ui->timeCmb->currentText());
            QMessageBox::information(0, "Success", "Appointment Made");
        }else{
            QMessageBox::information(0, "Failed.", "Appointment Failed.");
        }
    }else{
        QMessageBox::information(0, "Fill Details", "Please Complete All The Fields.");
    }
}
