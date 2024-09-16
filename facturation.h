#ifndef FACTURATION_H
#define FACTURATION_H
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include <QDialog>
#include<additem.h>
#include<item.h>

#include<newuser.h>

namespace Ui {
class Facturation;
}

class Facturation : public QDialog
{
    Q_OBJECT

public:
    explicit Facturation(QWidget *parent = nullptr);
    ~Facturation();
    void setLineEditText(const QString &text);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::Facturation *ui;
    void loadData();
    QSqlDatabase itemdb;
    QSqlDatabase factdb;
};

#endif // FACTURATION_H
