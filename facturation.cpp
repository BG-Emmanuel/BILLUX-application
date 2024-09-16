#include "facturation.h"
#include "ui_facturation.h"
#include <QMessageBox>

Facturation::Facturation(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Facturation)
{
    ui->setupUi(this);

    factdb =  QSqlDatabase::addDatabase("QSQLITE");
    factdb.setDatabaseName("C:/Users/Dell/Desktop/database/factdb.db");
    itemdb =  QSqlDatabase::addDatabase("QSQLITE");
    itemdb.setDatabaseName("C:/Users/Dell/Desktop/database/itemdb.db");
   //loadData();

}

Facturation::~Facturation()
{
    delete ui;
}
/*void Facturation::loadData()
{
    if(!itemdb.open()){
        qDebug()<<"Connection Failed";

        return;
    }

    QSqlQueryModel * modal2 = new QSqlQueryModel();
    QSqlQuery* qry2 = new QSqlQuery(itemdb);
    qry2->prepare("select designation from itemdt");
    qry2->exec();
    modal2->setQuery(*qry2);
    ui->listView_14->setModel(modal2);

    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery(itemdb);
    qry->prepare("select reference from itemdt");
    qry->exec();
    modal->setQuery(*qry);
    ui->listView_13->setModel(modal);
}*/

void Facturation::setLineEditText(const QString &text) {
    ui->lineEdit->setText(text);
}

void Facturation::on_pushButton_2_clicked()
{

    int unit = ui->lineEdit_3->text().toInt();
    int quant = ui->lineEdit_5->text().toInt();
    int dis = ui->lineEdit_4->text().toInt();
    int tot = (((unit*quant)/100.0)*dis);
    int totalPrice = (((unit*quant)-tot));

    QString reference,designation,unitPrice,discount,quantity;
    reference = ui->lineEdit->text();
    designation = ui->lineEdit_2->text();
    unitPrice = ui->lineEdit_3->text();
    discount = ui->lineEdit_4->text();
    quantity = ui->lineEdit_5->text();

    if(!factdb.open()){
        qDebug()<<"Connections Failed";

        return;
    }

    QSqlQuery qry;
    qry.prepare("INSERT INTO factdt(reference,designation,unitPrice,discount,quantity,totalPrice) VALUES (:reference,:designation,:unitPrice,:discount,:quantity,:totalPrice)");
    qry.bindValue(":reference",reference);
    qry.bindValue(":designation",designation);
    qry.bindValue(":unitPrice",unitPrice);
    qry.bindValue(":discount",discount);
    qry.bindValue(":quantity",quantity);
    qry.bindValue(":totalPrice",totalPrice);




    if(qry.exec()){

        QMessageBox::critical(this,tr("SAVED"),tr("DATA SAVED"));
    }
    else{
        QMessageBox::critical(this,tr("error"),qry.lastError().text());
    }

    QSqlQueryModel * modal1 = new QSqlQueryModel();
    QSqlQuery* qry1 = new QSqlQuery(factdb);
    qry1->prepare("select reference from factdt");
    qry1->exec();
    modal1->setQuery(*qry1);
    ui->listView->setModel(modal1);

    QSqlQueryModel * modal2 = new QSqlQueryModel();
    QSqlQuery* qry2 = new QSqlQuery(factdb);
    qry2->prepare("select designation from factdt");
    qry2->exec();
    modal2->setQuery(*qry2);
    ui->listView_2->setModel(modal2);

    QSqlQueryModel * modal3 = new QSqlQueryModel();
    QSqlQuery* qry3 = new QSqlQuery(factdb);
    qry3->prepare("select unitPrice from factdt");
    qry3->exec();
    modal3->setQuery(*qry3);
    ui->listView_3->setModel(modal3);

    QSqlQueryModel * modal4 = new QSqlQueryModel();
    QSqlQuery* qry4 = new QSqlQuery(factdb);
    qry4->prepare("select discount from factdt");
    qry4->exec();
    modal4->setQuery(*qry4);
    ui->listView_4->setModel(modal4);

    QSqlQueryModel * modal5 = new QSqlQueryModel();
    QSqlQuery* qry5 = new QSqlQuery(factdb);
    qry5->prepare("select quantity from factdt");
    qry5->exec();
    modal5->setQuery(*qry5);
    ui->listView_5->setModel(modal5);

    QSqlQueryModel * modal6 = new QSqlQueryModel();
    QSqlQuery* qry6 = new QSqlQuery(factdb);
    qry6->prepare("select totalPrice from factdt");
    qry6->exec();
    modal6->setQuery(*qry6);
    ui->listView_6->setModel(modal6);

   /* QSqlQuery query;
    query.prepare("SELECT SUM(totalPrice) FROM factdt");

    if (query.exec() && query.next()) {
        // Retrieve the sum from the query result
        int sum = query.value(0).toInt();

        // Display the sum on the QLabel
        ui->label_7->setText("Sum: " + QString::number(sum));
    } else {
        qDebug() << "Failed to execute the query: " << query.lastError().text();
    }*/




    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
}


void Facturation::on_pushButton_clicked()
{



    Item item;
    item.setModal(true);
    item.exec();


}





void Facturation::on_pushButton_3_clicked()
{
    AddItem additem;
    additem.setModal(true);
    additem.exec();
}
/*Facturation::lineEdit_1(){
    return ui->lineEdit;
}*/


void Facturation::on_pushButton_4_clicked()
{
    Newuser newuser;
    newuser.setModal(true);
    newuser.exec();
}


void Facturation::on_pushButton_5_clicked()
{

}

