#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_makeAppBtn_clicked();

    void on_pushButton_7_clicked();

    void on_viewApps_clicked();

    void on_viewDocs_clicked();

    void on_addPat_clicked();

    void on_viewPat_clicked();

    void on_logBtn_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
