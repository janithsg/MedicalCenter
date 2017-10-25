#include "docavailability.h"
#include "ui_docavailability.h"

DocAvailability::DocAvailability(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DocAvailability)
{
    ui->setupUi(this);
}

DocAvailability::~DocAvailability()
{
    delete ui;
}
