#ifndef VIEWAPPOINTMENTS_H
#define VIEWAPPOINTMENTS_H

#include <QDialog>

namespace Ui {
class ViewAppointments;
}

class ViewAppointments : public QDialog
{
    Q_OBJECT

public:
    explicit ViewAppointments(QWidget *parent = 0);
    void loadData();
    ~ViewAppointments();

private slots:
    void on_makeApp_clicked();

    void on_searchApp_clicked();

    void on_dataTable_clicked(const QModelIndex &index);

private:
    Ui::ViewAppointments *ui;
};

#endif // VIEWAPPOINTMENTS_H
