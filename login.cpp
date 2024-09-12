#include "login.h"
#include "ui_login.h"
#include<QMessageBox>

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    appdb = QSqlDatabase::addDatabase("QSQLITE");
    appdb.setDatabaseName("C:/Users/EUROPEONLINE/Desktop/database/appdb.db");
    if (!appdb.open()) {
        qDebug() << "Failed to connect to factdb: " << appdb.lastError().text();
    }
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{

    QString username,password;
    username = ui->lineEdit->text();
    password = ui->lineEdit_2->text();

    if(!appdb.isOpen()){
        qDebug()<<"Connections Failed";
        return;
    }
    QSqlQuery qry;
    if(qry.exec("select * from newdt where name='"+username+"' and password='"+password+"'")){

        int count = 0;
        while(qry.next()){
            count++;
        }
        if(count==1){
            QMessageBox::information(this, tr("validation"), tr("password correct, welcome"));
            Profile profile;
            profile.setModal(true);
            profile.exec();


        }else
            if(count>1){
            ui->label->setText("Duplicate");
        }else
        if(count<1){
            QMessageBox::warning(this, tr("error"), tr("password not correct"));
        }


    }

}
