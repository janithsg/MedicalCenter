#include "loginfrm.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginFrm w;
    w.show();

    return a.exec();
}
