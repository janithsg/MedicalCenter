#include "patient.h"
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QStringList>
#include <QMessageBox>

Patient::Patient()
{

}

QString Patient::getAddress(){
    return address;
}

QString Patient::getId(){
    return patientId;
}

QString Patient::getName(){
    return name;
}

QString Patient::getPhone(){
    return phone;
}

QString Patient::searchPatient(QString id){
    QFile file("C:\\Medi\\Patients.txt");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "File Error", file.errorString());
    }

    QTextStream in(&file);

    while(!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");

        if(id==fields.at(0)){
            return "yes";
        }
    }

    file.close();

    return "no";
}

void Patient::addPatient(QString id,QString name,QString phone,QString address){
    QFile file("C:\\Medi\\Patients.txt");
    if(!file.open(QIODevice::Append | QIODevice::Text)) {
        QMessageBox::information(0, "File Error", file.errorString());
    }
    QTextStream writer(&file);

    writer<<"\n"<<id<<","<<name<<","<<phone<<","<<address<<",";

    file.close();
}

QString Patient::getPatient(QString id){
    QFile file("C:\\Medi\\Patients.txt");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "File Error", file.errorString());
    }

    QTextStream in(&file);

    while(!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");

        if(id==fields.at(0)){
            return fields.at(1);
        }
    }

    file.close();

    return " ";
}
