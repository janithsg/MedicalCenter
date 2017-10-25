#ifndef DOCAVAILABILITY_H
#define DOCAVAILABILITY_H

#include <QMainWindow>

namespace Ui {
class DocAvailability;
}

class DocAvailability : public QMainWindow
{
    Q_OBJECT

public:
    explicit DocAvailability(QWidget *parent = 0);
    ~DocAvailability();

private:
    Ui::DocAvailability *ui;
};

#endif // DOCAVAILABILITY_H
