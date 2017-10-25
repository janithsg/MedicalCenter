#ifndef APPOINTMENT_H
#define APPOINTMENT_H
#include <QString>

class Appointment
{
    QString id;
    QString pname;
    QString docName;
    QString date;
    QString time;

public:
    Appointment();
    void addAppointment(QString,QString,QString,QString,QString);

};

#endif // APPOINTMENT_H
