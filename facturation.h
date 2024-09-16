#ifndef FACTURATION_H
#define FACTURATION_H

#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include <QDialog>

#include<customer.h>
#include<preview.h>
#include<additem.h>
#include<addcustomer.h>
#include<modif.h>
#include<newowner.h>
#include<profile.h>

namespace Ui {
class Facturation;
}

class Facturation : public QDialog
{
    Q_OBJECT

public:
    explicit Facturation(QWidget *parent = nullptr);
    ~Facturation();
    void setText(const QString &text);
    void loadData();
    void loadStyle();
private slots:
    void on_pushButton_clicked();

    void on_listView_13_activated(const QModelIndex &index);

    void on_listView_14_activated(const QModelIndex &index);

    void on_pushButton_2_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_6_clicked();

    void on_comboBox_activated(int index);

    void on_pushButton_11_clicked();

private:
    Ui::Facturation *ui;
    QSqlDatabase appdb;
    //QString setString;
    QString dataText;
    bool insertCurrentDate();
};

#endif // FACTURATION_H
