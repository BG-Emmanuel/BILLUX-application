#ifndef MODIF_H
#define MODIF_H

#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include <QDialog>

#include<facturation.h>
#include<customer.h>
#include<preview.h>
#include<additem.h>
#include<addcustomer.h>
#include<modif.h>
#include<newowner.h>
#include<profile.h>

namespace Ui {
class Modif;
}

class Modif : public QDialog
{
    Q_OBJECT

public:
    explicit Modif(QWidget *parent = nullptr);
    ~Modif();
    void loadData();
    void setText(const QString &text);


private slots:
    void on_listView_activated(const QModelIndex &index);

    void on_listView_2_activated(const QModelIndex &index);

    void on_listView_3_activated(const QModelIndex &index);

    void on_listView_4_activated(const QModelIndex &index);

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_listView_5_activated(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Modif *ui;
    QSqlDatabase appdb;
    QString dataText;
};

#endif // MODIF_H
