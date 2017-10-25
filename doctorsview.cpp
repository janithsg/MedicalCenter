#include "doctorsview.h"
#include "ui_doctorsview.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QMessageBox>

DoctorsView::DoctorsView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DoctorsView)
{
    ui->setupUi(this);
    loadData();
}

DoctorsView::~DoctorsView()
{
    delete ui;
}

void DoctorsView::loadData(){

    QFile file("C:\\Medi\\Doctors.txt");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "File Error", file.errorString());
    }

    QTextStream in(&file);

    ui->docTable->setRowCount(0);
    ui->docTable->setColumnCount(12);

    QStringList headers;

    headers<<"Doctor ID"<<"Name"<<"Field"<<"Sun"<<"Mon"<<"Tue"<<"Wed"<<"Thur"<<"Fri"<<"Sat"<<"Morning"<<"Evening";

    ui->docTable->setHorizontalHeaderLabels(headers);

    while(!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");

        QTableWidgetItem *id=new QTableWidgetItem(fields.at(0));
        QTableWidgetItem *nm=new QTableWidgetItem(fields.at(1));
        QTableWidgetItem *field=new QTableWidgetItem(fields.at(2));
        QTableWidgetItem *sun=new QTableWidgetItem(fields.at(3));
        QTableWidgetItem *mon=new QTableWidgetItem(fields.at(4));
        QTableWidgetItem *tue=new QTableWidgetItem(fields.at(5));
        QTableWidgetItem *wed=new QTableWidgetItem(fields.at(6));
        QTableWidgetItem *thur=new QTableWidgetItem(fields.at(7));
        QTableWidgetItem *fri=new QTableWidgetItem(fields.at(8));
        QTableWidgetItem *sat=new QTableWidgetItem(fields.at(9));
        QTableWidgetItem *morn=new QTableWidgetItem(fields.at(10));
        QTableWidgetItem *eve=new QTableWidgetItem(fields.at(11));

        ui->docTable->insertRow(ui->docTable->rowCount());
        ui->docTable->setItem(ui->docTable->rowCount()-1,0,id);
        ui->docTable->setItem(ui->docTable->rowCount()-1,1,nm);
        ui->docTable->setItem(ui->docTable->rowCount()-1,2,field);
        ui->docTable->setItem(ui->docTable->rowCount()-1,3,sun);
        ui->docTable->setItem(ui->docTable->rowCount()-1,4,mon);
        ui->docTable->setItem(ui->docTable->rowCount()-1,5,tue);
        ui->docTable->setItem(ui->docTable->rowCount()-1,6,wed);
        ui->docTable->setItem(ui->docTable->rowCount()-1,7,thur);
        ui->docTable->setItem(ui->docTable->rowCount()-1,8,fri);
        ui->docTable->setItem(ui->docTable->rowCount()-1,9,sat);
        ui->docTable->setItem(ui->docTable->rowCount()-1,10,morn);
        ui->docTable->setItem(ui->docTable->rowCount()-1,11,eve);
    }

    file.close();
}

void DoctorsView::on_docTable_clicked(const QModelIndex &index)
{
    ui->dates->clear();
    ui->times->clear();
    int row=ui->docTable->currentRow();

    ui->idText->setText(ui->docTable->item(row,0)->text());
    ui->nameTxt->setText(ui->docTable->item(row,1)->text());
    ui->fieldTxt->setText(ui->docTable->item(row,2)->text());

    if(ui->docTable->item(row,3)->text()=="y"){
        ui->dates->addItem("Sunday");
    }
    if(ui->docTable->item(row,4)->text()=="y"){
        ui->dates->addItem("Monday");
    }
    if(ui->docTable->item(row,5)->text()=="y"){
        ui->dates->addItem("Tuesday");
    }
    if(ui->docTable->item(row,6)->text()=="y"){
        ui->dates->addItem("Wednesday");
    }
    if(ui->docTable->item(row,7)->text()=="y"){
        ui->dates->addItem("Thursday");
    }
    if(ui->docTable->item(row,8)->text()=="y"){
        ui->dates->addItem("Friday");
    }
    if(ui->docTable->item(row,9)->text()=="y"){
        ui->dates->addItem("Saturday");
    }

    ui->times->addItem(ui->docTable->item(row,10)->text());
    ui->times->addItem(ui->docTable->item(row,11)->text());

    row=index.column();
}
