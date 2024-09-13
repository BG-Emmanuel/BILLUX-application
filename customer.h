#ifndef CUSTOMER_H
#define CUSTOMER_H

#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include <QDialog>

#include<addcustomer.h>
#include<facturation.h>

namespace Ui {
class Customer;
}

class Customer : public QDialog
{
    Q_OBJECT

public:
    explicit Customer(QWidget *parent = nullptr);
    ~Customer();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Customer *ui;
    QSqlDatabase appdb;
    void loadData();
};

#endif // CUSTOMER_H
