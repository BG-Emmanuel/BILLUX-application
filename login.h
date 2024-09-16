#ifndef LOGIN_H
#define LOGIN_H

#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include <QMainWindow>

#include<facturation.h>
#include<newowner.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class Login;
}
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();
    void loadStyle();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Login *ui;
    QSqlDatabase appdb;
};
#endif // LOGIN_H
