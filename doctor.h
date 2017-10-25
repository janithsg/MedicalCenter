#ifndef DOCTOR_H
#define DOCTOR_H
#include <QString>

class Doctor
{
public:
    Doctor();
    void getAvailability();
    void addDoctor();
    QString getDoctor(QString);
};

#endif // DOCTOR_H
