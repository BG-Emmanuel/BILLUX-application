#ifndef ADDCUSTOMERS_H
#define ADDCUSTOMERS_H

#include <QMainWindow>
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include <QDialog>

#include<customer.h>


QT_BEGIN_NAMESPACE
namespace Ui {
class Addcustomers;
}
QT_END_NAMESPACE

class Addcustomers : public QDialog
{
    Q_OBJECT

public:
    explicit Addcustomers(QWidget *parent = nullptr);
    ~Addcustomers();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Addcustomers *ui;
    void loadData();
    QSqlDatabase appdb;

};
#endif // ADDCUSTOMERS_H
