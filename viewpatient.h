#ifndef VIEWPATIENT_H
#define VIEWPATIENT_H

#include <QMainWindow>

namespace Ui {
class ViewPatient;
}

class ViewPatient : public QMainWindow
{
    Q_OBJECT

public:
    explicit ViewPatient(QWidget *parent = 0);
    void loadData();
    ~ViewPatient();

private:
    Ui::ViewPatient *ui;
};

#endif // VIEWPATIENT_H
