#include "facturation.h"
#include "ui_facturation.h"
#include <QMessageBox>

Facturation::Facturation(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Facturation)
{
    ui->setupUi(this);

    appdb = QSqlDatabase::addDatabase("QSQLITE");
    appdb.setDatabaseName("C:/Users/Dell/Desktop/database/appdb.db");
    loadData();
    if (!appdb.open()) {
        qDebug() << "Failed to connect to factdb: " << appdb.lastError().text();
    }

}

Facturation::~Facturation()
{
    delete ui;
}

// Loading the item list data to the listviews 13 and 14
void Facturation::loadData()
{
    if(!appdb.open()){
        qDebug()<<"Connection Failed";

        return;
    }

    ui->groupBox->setStyleSheet("QGroupBox { background-color: lightblue; }");
    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery(appdb);
    qry->prepare("select reference from itemdt");
    qry->exec();
    modal->setQuery(*qry);
    ui->listView_13->setModel(modal);

    QSqlQueryModel * modal2 = new QSqlQueryModel();
    QSqlQuery* qry2 = new QSqlQuery(appdb);
    qry2->prepare("select designation from itemdt");
    qry2->exec();
    modal2->setQuery(*qry2);
    ui->listView_14->setModel(modal2);

    QSqlQueryModel * modal3 = new QSqlQueryModel();
    QSqlQuery* qry3 = new QSqlQuery(appdb);
    qry3->prepare("select firstName from customerinfodt");
    qry3->exec();
    modal3->setQuery(*qry3);
    ui->comboBox->setModel(modal3);

    ui->lineEdit_6->setText("Mrs. Filomene");
}

//          Implementing the search function for searching items listviews 13 and 14

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
void Facturation::on_label_linkActivated(const QString &link)
{

}


void Facturation::on_pushButton_6_clicked()
{

}

//           pusting selectected item from listView to Line Edits fields
void Facturation::on_listView_14_activated(const QModelIndex &index)
{
    if(!appdb.open()){
        qDebug()<<"Connection Failed";

        return;
    }

    QString val = ui->listView_14->model()->data(index).toString();
    QSqlQuery qry2;
    qry2.prepare("select * from itemdt where designation='"+val+"'");
    if(qry2.exec()){
        while (qry2.next()) {
            ui->lineEdit->setText(qry2.value(0).toString());
            ui->lineEdit_3->setText(qry2.value(2).toString());
            ui->lineEdit_2->setText(qry2.value(1).toString());
        }

    }else{
        QMessageBox::critical(this,tr("error::"),qry2.lastError().text());
    }
}

//           puting selectected item from listView to Line Edits fields
void Facturation::on_listView_13_activated(const QModelIndex &index)
{
    if(!appdb.open()){
        qDebug()<<"Connection Failed";

        return;
    }

    QString val = ui->listView_13->model()->data(index).toString();
    QSqlQuery qry1;
    qry1.prepare("select * from itemdt where reference='"+val+"'");
    if(qry1.exec()){
        while (qry1.next()) {
            ui->lineEdit->setText(qry1.value(0).toString());
            ui->lineEdit_3->setText(qry1.value(2).toString());
            ui->lineEdit_2->setText(qry1.value(1).toString());
        }

    }else{
        QMessageBox::critical(this,tr("error::"),qry1.lastError().text());
    }
}





//                       Inserting the custommers Items to the Bill dadabase
void Facturation::on_pushButton_2_clicked()
{

    int unit = ui->lineEdit_3->text().toInt();
    int quant = ui->lineEdit_5->text().toInt();
    int dis = ui->lineEdit_4->text().toInt();
    int tot = (((unit*quant)/100.0)*dis);
    int totalPriceWD = (((unit*quant)-tot));
    int totalPriceND = (unit*quant);

    QString reference,designation,unitPrice,discount,quantity;
    reference = ui->lineEdit->text();
    designation = ui->lineEdit_2->text();
    unitPrice = ui->lineEdit_3->text();
    discount = ui->lineEdit_4->text();
    quantity = ui->lineEdit_5->text();

    if(!appdb.open()){
        qDebug()<<"Connections Failed";

        return;
    }

    QSqlQuery qry;
    qry.prepare("INSERT INTO factdt(reference,designation,unitPrice,discount,quantity,totalPriceWD,totalPriceND) VALUES (:reference,:designation,:unitPrice,:discount,:quantity,:totalPriceWD,:totalPriceND)");
    qry.bindValue(":reference",reference);
    qry.bindValue(":designation",designation);
    qry.bindValue(":unitPrice",unitPrice);
    qry.bindValue(":discount",discount);
    qry.bindValue(":quantity",quantity);
    qry.bindValue(":totalPriceWD",totalPriceWD);
    qry.bindValue(":totalPriceND",totalPriceND);




    if(qry.exec()){

        QMessageBox::critical(this,tr("SAVED"),tr("DATA SAVED"));
    }
    else{
        QMessageBox::critical(this,tr("error"),qry.lastError().text());
    }

    QSqlQueryModel * modal1 = new QSqlQueryModel();
    QSqlQuery* qry1 = new QSqlQuery(appdb);
    qry1->prepare("select reference from factdt");
    qry1->exec();
    modal1->setQuery(*qry1);
    ui->listView->setModel(modal1);

    QSqlQueryModel * modal2 = new QSqlQueryModel();
    QSqlQuery* qry2 = new QSqlQuery(appdb);
    qry2->prepare("select designation from factdt");
    qry2->exec();
    modal2->setQuery(*qry2);
    ui->listView_2->setModel(modal2);

    QSqlQueryModel * modal3 = new QSqlQueryModel();
    QSqlQuery* qry3 = new QSqlQuery(appdb);
    qry3->prepare("select unitPrice from factdt");
    qry3->exec();
    modal3->setQuery(*qry3);
    ui->listView_3->setModel(modal3);

    QSqlQueryModel * modal4 = new QSqlQueryModel();
    QSqlQuery* qry4 = new QSqlQuery(appdb);
    qry4->prepare("select discount from factdt");
    qry4->exec();
    modal4->setQuery(*qry4);
    ui->listView_4->setModel(modal4);

    QSqlQueryModel * modal5 = new QSqlQueryModel();
    QSqlQuery* qry5 = new QSqlQuery(appdb);
    qry5->prepare("select quantity from factdt");
    qry5->exec();
    modal5->setQuery(*qry5);
    ui->listView_5->setModel(modal5);

    QSqlQueryModel * modal6 = new QSqlQueryModel();
    QSqlQuery* qry6 = new QSqlQuery(appdb);
    qry6->prepare("select totalPriceWD from factdt");
    qry6->exec();
    modal6->setQuery(*qry6);
    ui->listView_6->setModel(modal6);



    QSqlQuery query;
    QString columnName = "totalPriceWD";  // Replace with your actual column name
    QString tableName = "factdt";    // Replace with your actual table name

    // Construct the SQL query
    QString queryString = QString("SELECT SUM(%1) FROM %2").arg(columnName).arg(tableName);

    if (query.exec(queryString)) {
        if (query.next()) {
            double sum = query.value(0).toDouble();  // Use index 0 to get the sum from the result
            ui->label_7->setText(QString::number(sum)+" FCFA");
              // Set the sum to the label
        }
    } else {
        // Handle SQL error
        qDebug() << "Query failed:" << query.lastError();
        ui->label_7->setText("Error");
    }


    QSqlQuery query2;
    QString columnName2 = "totalPriceND";  // Replace with your actual column name
    QString tableName2 = "factdt";    // Replace with your actual table name

    // Construct the SQL query
    QString queryString2 = QString("SELECT SUM(%1) FROM %2").arg(columnName2).arg(tableName2);

    if (query2.exec(queryString2)) {
        if (query2.next()) {
            double sum2 = query2.value(0).toDouble();  // Use index 0 to get the sum from the result
            ui->label_10->setText(QString::number(sum2)+" FCFA");
                // Set the sum to the label
        }
    } else {
        // Handle SQL error
        qDebug() << "Query failed:" << query2.lastError();
        ui->label_10->setText("Error");
    }


    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
}


void Facturation::on_pushButton_9_clicked()
{
    Customer c;
    c.setModal(true);
    c.exec();
}


void Facturation::on_pushButton_8_clicked()
{
    Addcustomer a;
    a.setModal(true);
    a.exec();
}


void Facturation::on_pushButton_7_clicked()
{
    Addcustomer a;
    a.setModal(true);
    a.exec();
}


void Facturation::on_pushButton_5_clicked()
{
    Modif m;
    m.setModal(true);
    m.exec();
}


void Facturation::on_pushButton_3_clicked()
{
    Additem ai;
    ai.setModal(true);
    ai.exec();
}


void Facturation::on_pushButton_4_clicked()
{
    Newowner n;
    n.setModal(true);
    n.exec();
}


void Facturation::on_pushButton_12_clicked()
{
    Profile *profile = new Profile(setString, this);
    profile->loadData();

    profile->setModal(true);
    profile->exec();
}


void Facturation::on_pushButton_10_clicked()
{
    Signin s;
    s.setModal(true);
    s.exec();
}


void Facturation::on_comboBox_activated(int index)
{
    if(!appdb.open()){
        qDebug()<<"Connection Failed";

        return;
    }
    QString val = ui->comboBox->currentText();
    QSqlQuery qry1;
    qry1.prepare("select * from customerInfodt where firstName='"+val+"'");
    if(qry1.exec()){
        while (qry1.next()) {
            ui->lineEdit_6->setText(qry1.value(0).toString());
        }

    }else{
        QMessageBox::critical(this,tr("error::"),qry1.lastError().text());
    }
}

