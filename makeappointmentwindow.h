#ifndef MAKEAPPOINTMENTWINDOW_H
#define MAKEAPPOINTMENTWINDOW_H

#include <QMainWindow>

namespace Ui {
class MakeAppointmentWindow;
}

class MakeAppointmentWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MakeAppointmentWindow(QWidget *parent = 0);
    ~MakeAppointmentWindow();

private slots:
    void on_searchBtn_clicked();

    void on_addPatbtn_clicked();

    void on_docListCmb_currentIndexChanged(int index);

    void on_saveBtn_clicked();

private:
    Ui::MakeAppointmentWindow *ui;
};

#endif // MAKEAPPOINTMENTWINDOW_H
