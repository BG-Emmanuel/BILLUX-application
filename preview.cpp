#include "preview.h"
#include "ui_preview.h"
#include <QIcon>

Preview::Preview(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Preview)
{
    ui->setupUi(this);
    appdb = QSqlDatabase::addDatabase("QSQLITE");
    appdb.setDatabaseName("C:/Users/Dell/Documents/BILLUX_/database/appdb.db");
    loadData();
    loadStyle();
    loadListFromDatabase();
    if (!appdb.open()) {
        qDebug() << "Failed to connect to factdb: " << appdb.lastError().text();
    }
}

Preview::~Preview()
{
    delete ui;
}

void Preview::loadStyle(){
    if(!appdb.open()){
        qDebug()<<"Connection Failed";

        return;
    }

    ui->groupBox->setStyleSheet(
        "QGroupBox {"           // General border around the group box
        "border-radius: 5px;"    // Rounding the top-right corner
        "    color: rgb(103, 104, 107);"
        "background-color:rgb(254, 254, 254);"
        "}"
        );
}

void Preview::setText2(const QString &text) {
    dataText2 = text;
}
void Preview::setText(const QString &text) {
    dataText = text;
}
void Preview::setText3(const QString &text) {
    dataText3 = text;
}
void Preview::setText4(const QString &text) {
    dataText4 = text;
}


void Preview::loadListFromDatabase(){

    if (!appdb.open()) {
        qDebug() << "Failed to connect to factdb: " << appdb.lastError().text();
    }

    QSqlQuery query("SELECT reference FROM factdt");  // Modify the query to fit your database schema
    QString result;
    while (query.next()) {
        QString name = query.value(0).toString();
        result += name + "\n";  // Append each item followed by a newline
    }
    ui->label->setText(result);

    QSqlQuery query2("SELECT designation FROM factdt");  // Modify the query to fit your database schema
    QString result2;
    while (query2.next()) {
        QString name2 = query2.value(0).toString();
        result2 += name2 + "\n";  // Append each item followed by a newline
    }
    ui->label_2->setText(result2);

    QSqlQuery query3("SELECT unitPrice FROM factdt");  // Modify the query to fit your database schema
    QString result3;
    while (query3.next()) {
        QString name3 = query3.value(0).toString();
        result3 += name3 + "\n";  // Append each item followed by a newline
    }
    ui->label_3->setText(result3);

    QSqlQuery query4("SELECT discount FROM factdt");  // Modify the query to fit your database schema
    QString result4;
    while (query4.next()) {
        QString name4 = query4.value(0).toString();
        result4 += name4+"%" + "\n";  // Append each item followed by a newline
    }
    ui->label_4->setText(result4);

    QSqlQuery query5("SELECT quantity FROM factdt");  // Modify the query to fit your database schema
    QString result5;
    while (query5.next()) {
        QString name5 = query5.value(0).toString();
        result5 += name5 + "\n";  // Append each item followed by a newline
    }
    ui->label_5->setText(result5);

    QSqlQuery query6("SELECT totalPriceND FROM factdt");  // Modify the query to fit your database schema
    QString result6;
    while (query6.next()) {
        QString name6 = query6.value(0).toString();
        result6 += name6 + "\n";  // Append each item followed by a newline
    }
    ui->label_6->setText(result6);
}





void Preview::loadData(){

    if (!appdb.open()) {
        qDebug() << "Failed to connect to factdb: " << appdb.lastError().text();
    }

    QString name2 = dataText2;
    ui->label_26->setText(name2);

    QString name3 = dataText3;
    ui->label_19->setText(name3);

    QString name4 = dataText4;
    ui->label_18->setText(name4);



    // Prepare and execute the query
    QString queryStr = "SELECT enterpriseName FROM newdt WHERE name = :name";
    QSqlQuery query;
    query.prepare(queryStr);
    QString name = dataText;
    ui->label_29->setText(name);
    //QString name = signin->setString;
    query.bindValue(":name", name );  // Example: Get the name of the user with id 1
    if (query.exec()) {
        if (query.next()) {
            QString result = query.value(0).toString();
            ui->label_21->setText(result);
        } else {
            qDebug() << "No results found";
        }
    } else {
        qDebug() << "Query failed: " << query.lastError();
    }


    // Prepare and execute the query
    QString queryStr2 = "SELECT emailAddress FROM newdt WHERE name = :name";
    QSqlQuery query2;
    query2.prepare(queryStr2);
    query2.bindValue(":name", name);  // Example: Get the name of the user with id 1
    if (query2.exec()) {
        if (query2.next()) {
            QString result2 = query2.value(0).toString();
            ui->label_22->setText(result2);
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
            ui->label_23->setText(result3);
        } else {
            qDebug() << "No results found";
        }
    } else {
        qDebug() << "Query failed: " << query3.lastError();
    }

    QString queryStr4 = "SELECT location FROM newdt WHERE name = :name";
    QSqlQuery query4;
    query4.prepare(queryStr4);
    query4.bindValue(":name", name);  // Example: Get the name of the user with id 1
    if (query4.exec()) {
        if (query4.next()) {
            QString result4 = query4.value(0).toString();
            ui->label_25->setText(result4);
        } else {
            qDebug() << "No results found";
        }
    } else {
        qDebug() << "Query failed: " << query4.lastError();
    }



    //Loading the date and time
    // Prepare and execute the query
    QString id_queryStr = "SELECT id FROM datedt ORDER BY id DESC LIMIT 1";
    QSqlQuery id_query;
    id_query.prepare(id_queryStr);
    //QString name = signin->setString;
    //id_query.bindValue(":id", 3 );  // Example: Get the name of the user with id 1
    if (id_query.exec()) {
        if (id_query.next()) {
            QString id_result = id_query.value(0).toString();
            ui->label_27->setText(id_result);
        } else {
            qDebug() << "No results found";
        }
    } else {
        qDebug() << "Query failed: " << id_query.lastError();
    }

    QString date_queryStr = "SELECT date FROM datedt ORDER BY id DESC LIMIT 1";
    QSqlQuery date_query;
    date_query.prepare(date_queryStr);
    //QString name = signin->setString;
    //date_query.bindValue(":id", 3 );  // Example: Get the name of the user with id 1
    if (date_query.exec()) {
        if (date_query.next()) {
            QString date_result = date_query.value(0).toString();
            ui->label_28->setText(date_result);
        } else {
            qDebug() << "No results found";
        }
    } else {
        qDebug() << "Query failed: " << date_query.lastError();
    }
}

void Preview::on_pushButton_clicked()
{
    Facturation f;  // Set the text
    f.loadData();          // Load data using the text
    //profile.setModal(true);
    //profile.exec();

    f.setModal(true);
    f.exec();
}

