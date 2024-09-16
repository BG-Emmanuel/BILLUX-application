#include "modif.h"
#include "ui_modif.h"
#include <QMessageBox>
#include <QRegularExpression>

Modif::Modif(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Modif)
{
    ui->setupUi(this);
    appdb = QSqlDatabase::addDatabase("QSQLITE");
    appdb.setDatabaseName("C:/Users/Dell/Documents/BILLUX_/database/appdb.db");
    loadData();
    if (!appdb.open()) {
        qDebug() << "Failed to connect to factdb: " << appdb.lastError().text();
    }
}

Modif::~Modif()
{
    delete ui;
}

void Modif::setText(const QString &text) {
    dataText = text;
}


void Modif::loadData()
{
    if(!appdb.open()){
        qDebug()<<"Connection Failed";

        return;
    }

    QString name = dataText;
    ui->label_5->setText(name);

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

    QSqlQueryModel * modal5 = new QSqlQueryModel();
    QSqlQuery* qry5 = new QSqlQuery(appdb);
    qry5->prepare("select id from itemdt");
    qry5->exec();
    modal5->setQuery(*qry5);
    ui->listView_5->setModel(modal5);


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
            ui->lineEdit->setText(qry1.value(1).toString());
            ui->lineEdit_2->setText(qry1.value(2).toString());
            ui->lineEdit_3->setText(qry1.value(3).toString());
            ui->lineEdit_4->setText(qry1.value(4).toString());
            ui->lineEdit_5->setText(qry1.value(0).toString());
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
            ui->lineEdit->setText(qry1.value(1).toString());
            ui->lineEdit_2->setText(qry1.value(2).toString());
            ui->lineEdit_3->setText(qry1.value(3).toString());
            ui->lineEdit_4->setText(qry1.value(4).toString());
            ui->lineEdit_5->setText(qry1.value(0).toString());
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
            ui->lineEdit->setText(qry1.value(1).toString());
            ui->lineEdit_2->setText(qry1.value(2).toString());
            ui->lineEdit_3->setText(qry1.value(3).toString());
            ui->lineEdit_4->setText(qry1.value(4).toString());
            ui->lineEdit_5->setText(qry1.value(0).toString());
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
            ui->lineEdit->setText(qry1.value(1).toString());
            ui->lineEdit_2->setText(qry1.value(2).toString());
            ui->lineEdit_3->setText(qry1.value(3).toString());
            ui->lineEdit_4->setText(qry1.value(4).toString());
            ui->lineEdit_5->setText(qry1.value(0).toString());
        }

    }else{
        QMessageBox::critical(this,tr("error::"),qry1.lastError().text());
    }
}

void Modif::on_listView_5_activated(const QModelIndex &index)
{
    if(!appdb.open()){
        qDebug()<<"Connection Failed";

        return;
    }
    QString val = ui->listView_5->model()->data(index).toString();
    QSqlQuery qry1;
    qry1.prepare("select * from itemdt where id='"+val+"'");
    if(qry1.exec()){
        while (qry1.next()) {
            ui->lineEdit->setText(qry1.value(1).toString());
            ui->lineEdit_2->setText(qry1.value(2).toString());
            ui->lineEdit_3->setText(qry1.value(3).toString());
            ui->lineEdit_4->setText(qry1.value(4).toString());
            ui->lineEdit_5->setText(qry1.value(0).toString());
        }

    }else{
        QMessageBox::critical(this,tr("error::"),qry1.lastError().text());
    }
}

void Modif::on_pushButton_4_clicked()
{
    this->hide();
    Facturation f;
    QString setString = ui->label_5->text();
    f.setText(setString);  // Set the text
    f.loadData();          // Load data using the text
    //profile.setModal(true);
    //profile.exec();

    f.setModal(true);
    f.exec();
}


void Modif::on_pushButton_2_clicked()
{

    if(!appdb.open()){
        qDebug()<<"Connection Failed";

        return;
    }

    //testing the datatype of input entered
    QString input4 = ui->lineEdit->text();
    // Check if the input is empty
    if (input4.isEmpty()) {
        QMessageBox::warning(nullptr, "Invalid Input", "The input field cannot be empty.");
        return;
    }
    // Define a regular expression that allows only letters (upper and lowercase)
    QRegularExpression regex2("^[A-Za-z]+$");
    QRegularExpressionMatch match2 = regex2.match(input4);
    // Check if the input matches the regex
    if (!match2.hasMatch()) {
        QMessageBox::warning(nullptr, "Invalid Input", "Please enter alphabetic characters only.");
        ui->lineEdit->clear();
        return;
    }

    QString input = ui->lineEdit_2->text();
    // Check if the input is empty
    if (input.isEmpty()) {
        QMessageBox::warning(nullptr, "Invalid Input", "The input field cannot be empty.");
        return;
    }
    // Define a regular expression that allows only letters (upper and lowercase)
    QRegularExpression regex("^[A-Za-z0-9 ]+$");
    QRegularExpressionMatch match = regex.match(input);
    // Check if the input matches the regex
    if (!match.hasMatch()) {
        QMessageBox::warning(nullptr, "Invalid Input", "Please enter alphabetic characters only.");
        ui->lineEdit_2->clear();
        return;
    }

    QString input2 = ui->lineEdit_3->text();
    // Check if the input is empty
    if (input2.isEmpty()) {
        // Input is empty, show an error message
        QMessageBox::warning(nullptr, "Invalid Input", "The input field cannot be empty.");
        // Prevent saving to the database
        return;
    }
    bool ok;
    int value = ui->lineEdit_3->text().toInt(&ok); // Try to convert input to an integer
    if (!ok) {
        // Input is not a valid integer, show an error message
        QMessageBox::warning(nullptr, "Invalid Input", "Please enter a valid integer.");
        // Clear the invalid input
        ui->lineEdit_3->clear();
        // Prevent saving to the database (you can return or stop here)
        return;
    }

    QString input3 = ui->lineEdit_4->text();
    // Check if the input is empty
    if (input3.isEmpty()) {
        // Input is empty, show an error message
        QMessageBox::warning(nullptr, "Invalid Input", "The input field cannot be empty.");
        // Prevent saving to the database
        return;
    }
    bool ok2;
    int value2 = ui->lineEdit_4->text().toInt(&ok2); // Try to convert input to an integer
    if (!ok2) {
        // Input is not a valid integer, show an error message
        QMessageBox::warning(nullptr, "Invalid Input", "Please enter a valid integer.");
        // Clear the invalid input
        ui->lineEdit_4->clear();
        // Prevent saving to the database (you can return or stop here)
        return;
    }





    QString id,reference,designation,unitPrice,quantity;
    reference = ui->lineEdit->text();
    id = ui->lineEdit_5->text();
    designation = ui->lineEdit_2->text();
    unitPrice = ui->lineEdit_3->text();
    quantity = ui->lineEdit_4->text();

    QSqlQuery query;
    query.prepare("UPDATE itemdt SET id = :id,reference = :reference, designation = :designation, unitPrice = :unitPrice, quantity = :quantity WHERE id = :oldid");
    query.bindValue(":id", id);
    query.bindValue(":reference", reference);
    query.bindValue(":designation", designation);
    query.bindValue(":unitPrice", unitPrice);
    query.bindValue(":quantity", quantity);

    // Using a different placeholder for the WHERE clause
    query.bindValue(":oldid", id);

    if (!query.exec()) {
        qDebug() << "Failed to update record:" << query.lastError();
    } else {
        qDebug() << "Record updated successfully.";
    }
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    loadData();
}





void Modif::on_pushButton_clicked()
{

    if(!appdb.open()){
        qDebug()<<"Connection Failed";

        return;
    }
    // Retrieving the id from QLineEdit to delete the row
    QString id = ui->lineEdit_5->text();  // Assuming id is in lineEdit_5

    // Preparing the SQL query for deletion
    QSqlQuery query;
    query.prepare("DELETE FROM itemdt WHERE id = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Failed to delete record:" << query.lastError();
    } else {
        qDebug() << "Record deleted successfully.";
    }

    // Clearing the input fields after deletion
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();

    // Optionally reload the data in your view
    loadData();
}


void Modif::on_pushButton_3_clicked()
{
    Additem ai;
    ai.setModal(true);
    ai.exec();
}

