#-------------------------------------------------
#
# Project created by QtCreator 2016-11-20T20:32:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MedicalCenter
TEMPLATE = app


SOURCES += main.cpp\
        loginfrm.cpp \
    user.cpp \
    mainwindow.cpp \
    makeappointmentwindow.cpp \
    patient.cpp \
    addpatient.cpp \
    doctor.cpp \
    appointment.cpp \
    viewappointments.cpp \
    doctorsview.cpp \
    docavailability.cpp \
    splash.cpp \
    viewpatient.cpp

HEADERS  += loginfrm.h \
    user.h \
    mainwindow.h \
    makeappointmentwindow.h \
    patient.h \
    addpatient.h \
    doctor.h \
    appointment.h \
    viewappointments.h \
    doctorsview.h \
    docavailability.h \
    splash.h \
    viewpatient.h

FORMS    += loginfrm.ui \
    mainwindow.ui \
    makeappointmentwindow.ui \
    addpatient.ui \
    viewappointments.ui \
    doctorsview.ui \
    docavailability.ui \
    splash.ui \
    viewpatient.ui

RESOURCES += \
    images.qrc

DISTFILES += \
    ../../../../Medi/Imgs/Key Logo.png \
    ../../../../Medi/Imgs/Key Logo 3.png
