#ifndef ADDCUSTOMER_H
#define ADDCUSTOMER_H

#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include <QDialog>

#include<customer.h>

namespace Ui {
class Addcustomer;
}

class Addcustomer : public QDialog
{
    Q_OBJECT

public:
    explicit Addcustomer(QWidget *parent = nullptr);
    ~Addcustomer();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Addcustomer *ui;
    void loadData();
    QSqlDatabase appdb;
};

#endif // ADDCUSTOMER_H
