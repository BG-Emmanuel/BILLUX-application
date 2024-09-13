#include "modif.h"
#include "ui_modif.h"
#include <QMessageBox>

Modif::Modif(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Modif)
{
    ui->setupUi(this);
    appdb = QSqlDatabase::addDatabase("QSQLITE");
    appdb.setDatabaseName("C:/Users/Dell/Desktop/database/appdb.db");
    loadData();
    if (!appdb.open()) {
        qDebug() << "Failed to connect to factdb: " << appdb.lastError().text();
    }
}

Modif::~Modif()
{
    delete ui;
}


void Modif::loadData()
{
    if(!appdb.open()){
        qDebug()<<"Connection Failed";

        return;
    }

    QSqlQueryModel * modal2 = new QSqlQueryModel();
    QSqlQuery* qry2 = new QSqlQuery(appdb);
    qry2->prepare("select designation from itemdt");
    qry2->exec();
    modal2->setQuery(*qry2);
    ui->listView_2->setModel(modal2);

    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery(appdb);
    qry->prepare("select reference from itemdt");
    qry->exec();
    modal->setQuery(*qry);
    ui->listView->setModel(modal);

    QSqlQueryModel * modal3 = new QSqlQueryModel();
    QSqlQuery* qry3 = new QSqlQuery(appdb);
    qry3->prepare("select unitPrice from itemdt");
    qry3->exec();
    modal3->setQuery(*qry3);
    ui->listView_3->setModel(modal3);

    QSqlQueryModel * modal4 = new QSqlQueryModel();
    QSqlQuery* qry4 = new QSqlQuery(appdb);
    qry4->prepare("select quantity from itemdt");
    qry4->exec();
    modal4->setQuery(*qry4);
    ui->listView_4->setModel(modal4);


}

void Modif::on_listView_activated(const QModelIndex &index)
{
    if(!appdb.open()){
        qDebug()<<"Connection Failed";

        return;
    }
    QString val = ui->listView->model()->data(index).toString();
    QSqlQuery qry1;
    qry1.prepare("select * from itemdt where reference='"+val+"'");
    if(qry1.exec()){
        while (qry1.next()) {
            ui->lineEdit->setText(qry1.value(0).toString());
            ui->lineEdit_2->setText(qry1.value(1).toString());
            ui->lineEdit_3->setText(qry1.value(2).toString());
            ui->lineEdit_4->setText(qry1.value(4).toString());
        }

    }else{
        QMessageBox::critical(this,tr("error::"),qry1.lastError().text());
    }
}



void Modif::on_listView_2_activated(const QModelIndex &index)
{
    if(!appdb.open()){
        qDebug()<<"Connection Failed";

        return;
    }
    QString val = ui->listView_2->model()->data(index).toString();
    QSqlQuery qry1;
    qry1.prepare("select * from itemdt where designation='"+val+"'");
    if(qry1.exec()){
        while (qry1.next()) {
            ui->lineEdit->setText(qry1.value(0).toString());
            ui->lineEdit_2->setText(qry1.value(1).toString());
            ui->lineEdit_3->setText(qry1.value(2).toString());
            ui->lineEdit_4->setText(qry1.value(3).toString());
        }

    }else{
        QMessageBox::critical(this,tr("error::"),qry1.lastError().text());
    }
}


void Modif::on_listView_3_activated(const QModelIndex &index)
{
    if(!appdb.open()){
        qDebug()<<"Connection Failed";

        return;
    }
    QString val = ui->listView_3->model()->data(index).toString();
    QSqlQuery qry1;
    qry1.prepare("select * from itemdt where unitPrice='"+val+"'");
    if(qry1.exec()){
        while (qry1.next()) {
            ui->lineEdit->setText(qry1.value(0).toString());
            ui->lineEdit_2->setText(qry1.value(1).toString());
            ui->lineEdit_3->setText(qry1.value(2).toString());
            ui->lineEdit_4->setText(qry1.value(3).toString());
        }

    }else{
        QMessageBox::critical(this,tr("error::"),qry1.lastError().text());
    }
}


void Modif::on_listView_4_activated(const QModelIndex &index)
{
    if(!appdb.open()){
        qDebug()<<"Connection Failed";

        return;
    }
    QString val = ui->listView_4->model()->data(index).toString();
    QSqlQuery qry1;
    qry1.prepare("select * from itemdt where quantity='"+val+"'");
    if(qry1.exec()){
        while (qry1.next()) {
            ui->lineEdit->setText(qry1.value(0).toString());
            ui->lineEdit_2->setText(qry1.value(1).toString());
            ui->lineEdit_3->setText(qry1.value(2).toString());
            ui->lineEdit_4->setText(qry1.value(3).toString());
        }

    }else{
        QMessageBox::critical(this,tr("error::"),qry1.lastError().text());
    }
}

void Modif::on_pushButton_2_clicked()
{

}


void Modif::on_listView_indexesMoved(const QModelIndexList &indexes)
{

}


void Modif::on_pushButton_3_clicked()
{
    this->hide();
    Additem ai;
    ai.setModal(true);
    ai.exec();
}

