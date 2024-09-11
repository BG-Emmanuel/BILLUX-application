#include "profile.h"
#include "ui_profile.h"

Profile::Profile(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Profile)
     //login(new login())
{
    ui->setupUi(this);
    appdb = QSqlDatabase::addDatabase("QSQLITE");
    appdb.setDatabaseName("C:/Users/EUROPEONLINE/Desktop/database/appdb.db");
    loadData();
    if (!appdb.open()) {
        qDebug() << "Failed to connect to factdb: " << appdb.lastError().text();
    }
}

Profile::~Profile()
{
    delete ui;
}
void Profile::loadData(){

    if (!appdb.open()) {
        qDebug() << "Failed to connect to factdb: " << appdb.lastError().text();
    }
    // Prepare and execute the query
    QString queryStr = "SELECT name FROM newdt WHERE name = :name";
    QSqlQuery query;
    query.prepare(queryStr);
    QString name = receivedText;
    //QString name = signin->setString;
    query.bindValue(":name", name );  // Example: Get the name of the user with id 1
    if (query.exec()) {
        if (query.next()) {
            QString result = query.value(0).toString();
            ui->label_2->setText(result);
        } else {
            qDebug() << "No results found";
        }
    } else {
        qDebug() << "Query failed: " << query.lastError();
    }


    // Prepare and execute the query
    QString queryStr2 = "SELECT lastName FROM newdt WHERE name = :name";
    QSqlQuery query2;
    query2.prepare(queryStr2);
    query2.bindValue(":name", name);  // Example: Get the name of the user with id 1
    if (query2.exec()) {
        if (query2.next()) {
            QString result2 = query2.value(0).toString();
            ui->label_5->setText(result2);
        } else {
            qDebug() << "No results found";
        }
    } else {
        qDebug() << "Query failed: " << query2.lastError();
    }

    QString queryStr3 = "SELECT phone FROM newdt WHERE name = :name";
    QSqlQuery query3;
    query3.prepare(queryStr3);
    query3.bindValue(":name", name);  // Example: Get the name of the user with id 1
    if (query3.exec()) {
        if (query3.next()) {
            QString result3 = query3.value(0).toString();
            ui->label_6->setText(result3);
        } else {
            qDebug() << "No results found";
        }
    } else {
        qDebug() << "Query failed: " << query3.lastError();
    }

    QString queryStr4 = "SELECT emailAddress FROM newdt WHERE name = :name";
    QSqlQuery query4;
    query4.prepare(queryStr4);
    query4.bindValue(":name", name);  // Example: Get the name of the user with id 1
    if (query4.exec()) {
        if (query4.next()) {
            QString result4 = query4.value(0).toString();
            ui->label_7->setText(result4);
        } else {
            qDebug() << "No results found";
        }
    } else {
        qDebug() << "Query failed: " << query4.lastError();
    }

    QString queryStr5 = "SELECT enterpriseName FROM newdt WHERE name = :name";
    QSqlQuery query5;
    query5.prepare(queryStr5);
    query5.bindValue(":name", name);  // Example: Get the name of the user with id 1
    if (query5.exec()) {
        if (query5.next()) {
            QString result5 = query5.value(0).toString();
            ui->label_8->setText(result5);
        } else {
            qDebug() << "No results found";
        }
    } else {
        qDebug() << "Query failed: " << query5.lastError();
    }
}



void Profile::on_pushButton_clicked()
{
    this->hide();

}

