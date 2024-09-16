#ifndef PREVIEW_H
#define PREVIEW_H

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
class Preview;
}

class Preview : public QDialog
{
    Q_OBJECT

public:
    explicit Preview(QWidget *parent = nullptr);
    ~Preview();
    void loadListFromDatabase();
    void loadData();
    void loadStyle();
    void setText2(const QString &text);
    void setText3(const QString &text);
    void setText4(const QString &text);
    void setText(const QString &text);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Preview *ui;
    QSqlDatabase appdb;
    QString dataText2;
    QString dataText;
    QString dataText3;
    QString dataText4;
};

#endif // PREVIEW_H
