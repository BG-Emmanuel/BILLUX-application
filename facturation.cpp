#include "facturation.h"
#include "ui_facturation.h"

Facturation::Facturation(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Facturation)
{
    ui->setupUi(this);
    appdb = QSqlDatabase::addDatabase("QSQLITE");
    appdb.setDatabaseName("C:/Users/Dell/Desktop/database/appdb.db");
    if (!appdb.open()) {
        qDebug() << "Failed to connect to factdb: " << appdb.lastError().text();
    }
}

Facturation::~Facturation()
{
    delete ui;
}

void Facturation::on_pushButton_clicked()
{

    if(!appdb.isOpen()){
        qDebug()<<"Connections Failed";
        return;
    }
    QString searchText = ui->lineEdit->text();

    if (searchText.isEmpty()) {
        qDebug() << "Search text is empty";
        return;
    }

    QSqlQuery query;

    if (!query.prepare("SELECT reference FROM itemdt WHERE reference = :searchText")) {
        qDebug() << "Query preparation failed:" << query.lastError().text();
        return;
    }

    query.bindValue(":searchText", searchText);
    if(query.exec()){
        QStringList resultList;
        while (query.next()) {
            resultList << query.value(0).toString();
        }

        if (!resultList.isEmpty()) {
            QStringListModel *model = new QStringListModel(resultList, this);
            ui->listView_13->setModel(model);
            ui->listView_13->setEditTriggers(QAbstractItemView::NoEditTriggers);
        } else {
            qDebug() << "No match found.";
        }
    }

    QSqlQuery query2;
    if (!query2.prepare("SELECT designation FROM itemdt WHERE reference = :searchText")) {
        qDebug() << "Query preparation failed:" << query2.lastError().text();
        return;
    }

    query2.bindValue(":searchText", searchText);
    if(query2.exec()){
        QStringList resultList_2;
        while (query2.next()) {
            resultList_2 << query2.value(0).toString();
        }

        if (!resultList_2.isEmpty()) {
            QStringListModel *model2 = new QStringListModel(resultList_2, this);
            ui->listView_14->setModel(model2);
            ui->listView_14->setEditTriggers(QAbstractItemView::NoEditTriggers);
        } else {
            qDebug() << "No match found.";
        }
    }

    if (!query.exec()) {
        qDebug() << "Query execution failed:" << query.lastError().text();
        return;
    }
}

