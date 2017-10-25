#include "viewappointments.h"
#include "ui_viewappointments.h"
#include"makeappointmentwindow.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QMessageBox>

ViewAppointments::ViewAppointments(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewAppointments)
{
    ui->setupUi(this);
    loadData();
}

void ViewAppointments::loadData(){

    QFile file("C:\\Medi\\Appointments.txt");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "File Error", file.errorString());
    }

    QTextStream in(&file);

    ui->dataTable->setRowCount(0);
    ui->dataTable->setColumnCount(5);

    QStringList headers;

    headers<<"Appointment ID"<<"Patient Name"<<"Doctor Name"<<"Date"<<"Time";

    ui->dataTable->setHorizontalHeaderLabels(headers);

    while(!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");

        QTableWidgetItem *id=new QTableWidgetItem(fields.at(0));
        QTableWidgetItem *nm=new QTableWidgetItem(fields.at(1));
        QTableWidgetItem *doc=new QTableWidgetItem(fields.at(2));
        QTableWidgetItem *date=new QTableWidgetItem(fields.at(3));
        QTableWidgetItem *time=new QTableWidgetItem(fields.at(4));

        ui->dataTable->insertRow(ui->dataTable->rowCount());
        ui->dataTable->setItem(ui->dataTable->rowCount()-1,0,id);
        ui->dataTable->setItem(ui->dataTable->rowCount()-1,1,nm);
        ui->dataTable->setItem(ui->dataTable->rowCount()-1,2,doc);
        ui->dataTable->setItem(ui->dataTable->rowCount()-1,3,date);
        ui->dataTable->setItem(ui->dataTable->rowCount()-1,4,time);
    }

    file.close();
}

ViewAppointments::~ViewAppointments()
{
    delete ui;
}

void ViewAppointments::on_makeApp_clicked()
{
    MakeAppointmentWindow *maw=new MakeAppointmentWindow;
    maw->show();
    loadData();
}

void ViewAppointments::on_searchApp_clicked()
{
    loadData();
    QFile file("C:\\Medi\\Appointments.txt");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "File Error", file.errorString());
    }

    QTextStream in(&file);
    QString id=ui->idTxt->text();

    int x=0;

    while(!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");

        if(id==fields.at(0)){
            ui->idText->setText(fields.at(0));
            ui->patTxt->setText(fields.at(1));
            ui->docTxt->setText(fields.at(2));
            ui->dateTxt->setText(fields.at(3));
            ui->timeTxt->setText(fields.at(4));
            x=10;
            break;
        }
    }

    if(x==0){
        QMessageBox::information(0, "Not Found", "Appointment Details Not Found.");
    }

    x=0;
    file.close();
}

void ViewAppointments::on_dataTable_clicked(const QModelIndex &index)
{
    int row=ui->dataTable->currentRow();

    ui->idText->setText(ui->dataTable->item(row,0)->text());
    ui->patTxt->setText(ui->dataTable->item(row,1)->text());
    ui->docTxt->setText(ui->dataTable->item(row,2)->text());
    ui->dateTxt->setText(ui->dataTable->item(row,3)->text());
    ui->timeTxt->setText(ui->dataTable->item(row,4)->text());

    row=index.column();
}
