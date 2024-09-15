#include "addcustomers.h"
#include "ui_addcustomers.h"
#include <QMessageBox>


Addcustomers::Addcustomers(QWidget *parent)
    :  QDialog(parent)
    , ui(new Ui::Addcustomers)
{
    ui->setupUi(this);
    appdb = QSqlDatabase::addDatabase("QSQLITE");
    appdb.setDatabaseName("C:/Users/Dell/Desktop/database/appdb.db");
    loadData();
    if (!appdb.open()) {
        qDebug() << "Failed to connect to factdb: " << appdb.lastError().text();
    }
}

Addcustomers::~Addcustomers()
{
    delete ui;
}
void Addcustomer::loadData(){
    ui->lineEdit->setText("Mice");
}
void Addcustomer::on_pushButton_clicked()
{
    QString firstName,lastName,mobile,storeName,location;
    firstName = ui->lineEdit->text();
    lastName = ui->lineEdit_2->text();
    mobile = ui->lineEdit_3->text();
    storeName = ui->lineEdit_4->text();
    location = ui->lineEdit_5->text();

    if(!appdb.open()){
        qDebug()<<"Connections Failed";

        return;
    }

    QSqlQuery qry;
    qry.prepare("INSERT INTO customerInfodt(firstName,lastName,mobile,storeName,location) VALUES (:firstName,:lastName,:mobile,:storeName,:location)");
    qry.bindValue(":firstName",firstName);
    qry.bindValue(":lastName",lastName);
    qry.bindValue(":mobile",mobile);
    qry.bindValue(":storeName",storeName);
    qry.bindValue(":location",location);

    if(qry.exec()){

        QMessageBox::critical(this,tr("SAVED"),tr("DATA SAVED"));
    }
    else{
        QMessageBox::critical(this,tr("error"),qry.lastError().text());
    }
    this->hide();
    Customer c;
    c.setModal(true);
    c.exec();
}


void Addcustomer::on_pushButton_2_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
}

