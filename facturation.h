#ifndef FACTURATION_H
#define FACTURATION_H

#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include <QMainWindow>

#include<addcustomer.h>
#include<additem.h>
#include<customer.h>
#include<newowner.h>
#include<modif.h>
#include<signin.h>
#include<profile.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class Facturation;
}
QT_END_NAMESPACE

class Facturation : public QMainWindow
{
    Q_OBJECT

public:
    Facturation(QWidget *parent = nullptr);
    ~Facturation();
    QString setString;

private slots:
    void on_label_linkActivated(const QString &link);

    void on_pushButton_clicked();

    void on_pushButton_6_clicked();

    void on_listView_14_activated(const QModelIndex &index);

    void on_listView_13_activated(const QModelIndex &index);

    void on_pushButton_2_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_10_clicked();

    void on_comboBox_activated(int index);

private:
    Ui::Facturation *ui;
    QSqlDatabase appdb;
    void loadData();
};
#endif // FACTURATION_H
