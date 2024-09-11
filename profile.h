#ifndef PROFILE_H
#define PROFILE_H

#include <QDialog>
#include<QtDebug>
#include<QFileInfo>
#include <QDialog>


#include<login.h>
#include"login.h"

class login;

namespace Ui {
class Profile;
}

class Profile : public QDialog
{
    Q_OBJECT

public:
    explicit Profile(QWidget *parent = nullptr);
    ~Profile();
    void loadData();
    //void setlogin(login *login);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Profile *ui;
    QSqlDatabase appdb;
    QString receivedText;
    //login *login;
};

#endif // PROFILE_H
