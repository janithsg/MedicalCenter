#include "doctor.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QMessageBox>

Doctor::Doctor()
{

}

void Doctor::getAvailability(){

}

QString Doctor::getDoctor(QString id){
    QFile file("C:\\Medi\\Doctors.txt");
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

void Doctor::addDoctor(){

}
