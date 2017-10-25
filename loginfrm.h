#ifndef LOGINFRM_H
#define LOGINFRM_H

#include <QMainWindow>

namespace Ui {
class LoginFrm;
}

class LoginFrm : public QMainWindow
{
    Q_OBJECT

public:
    int x=0;
    explicit LoginFrm(QWidget *parent = 0);
    ~LoginFrm();

private slots:
    void on_pushButton_clicked();

    void on_loginBtn_clicked();

private:
    Ui::LoginFrm *ui;
};

#endif // LOGINFRM_H
