#ifndef ADDITEM_H
#define ADDITEM_H

#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include <QDialog>

#include<modif.h>
#include<facturation.h>
#include<customer.h>
#include<preview.h>
#include<additem.h>
#include<addcustomer.h>
#include<modif.h>
#include<newowner.h>
#include<profile.h>

namespace Ui {
class Additem;
}

class Additem : public QDialog
{
    Q_OBJECT

public:
    explicit Additem(QWidget *parent = nullptr);
    ~Additem();
    void loadStyle();
    void loadData();
    void setText(const QString &text);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Additem *ui;
    QSqlDatabase appdb;
    QString dataText;
};

#endif // ADDITEM_H
