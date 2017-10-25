#ifndef DOCTORSVIEW_H
#define DOCTORSVIEW_H

#include <QMainWindow>

namespace Ui {
class DoctorsView;
}

class DoctorsView : public QMainWindow
{
    Q_OBJECT

public:
    explicit DoctorsView(QWidget *parent = 0);
    void loadData();
    ~DoctorsView();

private slots:
    void on_docTable_clicked(const QModelIndex &index);

private:
    Ui::DoctorsView *ui;
};

#endif // DOCTORSVIEW_H
