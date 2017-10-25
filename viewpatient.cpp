#include "viewpatient.h"
#include "ui_viewpatient.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QMessageBox>

ViewPatient::ViewPatient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ViewPatient)
{
    ui->setupUi(this);
    loadData();
}

ViewPatient::~ViewPatient()
{
    delete ui;
}

void ViewPatient::loadData(){

    QFile file("C:\\Medi\\Patients.txt");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "File Error", file.errorString());
    }

    QTextStream in(&file);

    ui->dataTable->setRowCount(0);
    ui->dataTable->setColumnCount(4);

    QStringList headers;

    headers<<"Patient ID"<<"Patient Name"<<"Phone"<<"Address";

    ui->dataTable->setHorizontalHeaderLabels(headers);

    while(!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");

        QTableWidgetItem *id=new QTableWidgetItem(fields.at(0));
        QTableWidgetItem *nm=new QTableWidgetItem(fields.at(1));
        QTableWidgetItem *phone=new QTableWidgetItem(fields.at(2));
        QTableWidgetItem *addr=new QTableWidgetItem(fields.at(3));

        ui->dataTable->insertRow(ui->dataTable->rowCount());
        ui->dataTable->setItem(ui->dataTable->rowCount()-1,0,id);
        ui->dataTable->setItem(ui->dataTable->rowCount()-1,1,nm);
        ui->dataTable->setItem(ui->dataTable->rowCount()-1,2,phone);
        ui->dataTable->setItem(ui->dataTable->rowCount()-1,3,addr);

    }

    file.close();
}
