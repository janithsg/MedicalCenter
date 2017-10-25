#ifndef ADDPATIENT_H
#define ADDPATIENT_H

#include <QMainWindow>

namespace Ui {
class addPatient;
}

class addPatient : public QMainWindow
{
    Q_OBJECT

public:
    explicit addPatient(QWidget *parent = 0);
    ~addPatient();

private slots:
    void on_saveBtn_clicked();

private:
    Ui::addPatient *ui;
};

#endif // ADDPATIENT_H
