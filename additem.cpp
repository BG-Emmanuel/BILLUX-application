#include "additem.h"
#include "ui_additem.h"
#include <QMessageBox>

AddItem::AddItem(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Additem)
{
    ui->setupUi(this);
    appdb = QSqlDatabase::addDatabase("QSQLITE");
    appdb.setDatabaseName("C:/Users/Dell/Desktop/database/appdb.db");
    if (!appdb.open()) {
        qDebug() << "Failed to connect to factdb: " << appdb.lastError().text();
    }
}
AddItem::~Additem()
{
    delete ui;
}


void AddItem::on_pushButton_clicked()
{
    if(!appdb.open()){
        qDebug()<<"Connection Failed";

        return;
    }

    QString reference,designation,unitPrice,quantity;
    reference = ui->lineEdit_2->text();
    designation = ui->lineEdit_3->text();
    unitPrice = ui->lineEdit_4->text();
    quantity = ui->lineEdit_5->text();

    QSqlQuery qry;
    qry.prepare("INSERT INTO itemdt(reference,designation,unitPrice,quantity) VALUES (:reference,:designation,:unitPrice,:quantity)");
    qry.bindValue(":reference",reference);
    qry.bindValue(":designation",designation);
    qry.bindValue(":unitPrice",unitPrice);
    qry.bindValue(":quantity",quantity);

    if(qry.exec()){

        QMessageBox::critical(this,tr("SAVED"),tr("DATA SAVED"));
    }
    else{
        QMessageBox::critical(this,tr("error"),qry.lastError().text());
    }
    this->hide();
    Modif m;
    m.setModal(true);
    m.exec();
    appdb.close();
}
