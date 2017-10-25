#include "user.h"
#include "string.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QMessageBox>

user::user()
{

}

int user::login(QString uname,QString pswd){
    QFile file("C:\\Medi\\Admins.txt");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "File Error", file.errorString());
    }

    QTextStream in(&file);
    QString un=uname;
    QString pwd=pswd;

    while(!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");

        if(un==fields.at(0)){
            if(pwd==fields.at(1)){
                return 10;
            }
        }
    }

    file.close();

    return 2;
}
