#ifndef PATIENT_H
#define PATIENT_H
#include<QString>

class Patient
{
    QString patientId;
    QString name;
    QString phone;
    QString address;
public:
    Patient();
    QString getId();
    QString getName();
    QString getPhone();
    QString getAddress();
    QString searchPatient(QString);
    void addPatient(QString,QString,QString,QString);
    QString getPatient(QString);
};

#endif // PATIENT_H
