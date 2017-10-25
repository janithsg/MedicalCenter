#include "appointment.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QMessageBox>
Appointment::Appointment()
{

}

void Appointment::addAppointment(QString id,QString pname,QString doc,QString day,QString time){
    QFile file("C:\\Medi\\Appointments.txt");
    if(!file.open(QIODevice::Append | QIODevice::Text)) {
        QMessageBox::information(0, "File Error", file.errorString());
    }
    QTextStream writer(&file);

    writer<<"\n"<<id<<","<<pname<<","<<doc<<","<<day<<","<<time<<",";

    file.close();
}
