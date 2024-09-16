#include "additem.h"
#include "ui_additem.h"
#include <QMessageBox>
#include <QRegularExpression>

Additem::Additem(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Additem)
{
    ui->setupUi(this);
    appdb = QSqlDatabase::addDatabase("QSQLITE");
    appdb.setDatabaseName("C:/Users/Dell/Documents/BILLUX_/database/appdb.db");
    loadStyle();
    loadData();
    if (!appdb.open()) {
        qDebug() << "Failed to connect to factdb: " << appdb.lastError().text();
    }


}

Additem::~Additem()
{
    delete ui;
}
void Additem::setText(const QString &text) {
    dataText = text;
}

void Additem::loadData()
{
    if(!appdb.open()){
        qDebug()<<"Connection Failed";

        return;
    }

    QString name = dataText;
    ui->label->setText(name);
}

void Additem::loadStyle(){
    if(!appdb.open()){
        qDebug()<<"Connection Failed";

        return;
    }

    ui->label->setStyleSheet("QLabel { color: rgb(110, 105, 105); }");
    ui->label_2->setStyleSheet("QLabel { color: rgb(110, 105, 105); }");
    ui->label_3->setStyleSheet("QLabel { color: rgb(110, 105, 105); }");
    ui->label_4->setStyleSheet("QLabel { color: rgb(110, 105, 105); }");
    ui->label_5->setStyleSheet("QLabel { color: rgb(110, 105, 105); }");

    ui->pushButton->setStyleSheet(
        "QPushButton {"
        "    background-color: rgb(66, 158, 245);"
        //"    border: 1px solid white;"
        "    border-radius: 5px;"
        "    color: white;"
        //"    margin-top: 1.5em;"  // Space for the title
        "}"
        );
    ui->pushButton_2->setStyleSheet(
        "QPushButton {"
        "    background-color: rgb(242, 244, 245);"
        //"    border: 1px solid white;"
        "    border-radius: 5px;"
        "    color: rgb(66, 158, 245);"
        //"    margin-top: 1.5em;"  // Space for the title
        "}"
        );

    ui->lineEdit_5->setStyleSheet(
        "QLineEdit {"
        //"    background-color: rgb(242, 244, 245);"
        //"    border: 1px solid white;"
        "    border-radius: 5px;"
        "    color: rgb(141, 142, 143);"
        //"    margin-top: 1.5em;"  // Space for the title
        "}"
        );
    ui->lineEdit_2->setStyleSheet(
        "QLineEdit {"
        //"    background-color: rgb(242, 244, 245);"
        //"    border: 1px solid white;"
        "    border-radius: 5px;"
        "    color: rgb(141, 142, 143);"
        //"    margin-top: 1.5em;"  // Space for the title
        "}"
        );
    ui->lineEdit_3->setStyleSheet(
        "QLineEdit {"
        //"    background-color: rgb(242, 244, 245);"
        //"    border: 1px solid white;"
        "    border-radius: 5px;"
        "    color: rgb(141, 142, 143);"
        //"    margin-top: 1.5em;"  // Space for the title
        "}"
        );
    ui->lineEdit_4->setStyleSheet(
        "QLineEdit {"
        //"    background-color: rgb(242, 244, 245);"
        //"    border: 1px solid white;"
        "    border-radius: 5px;"
        "    color: rgb(141, 142, 143);"
        //"    margin-top: 1.5em;"  // Space for the title
        "}"
        );

    ui->groupBox_3->setStyleSheet(
        "QGroupBox {"           // General border around the group box
        //"border: 2px solid grey;"
        "background-color: rgb(242, 244, 245);"
        "    border-radius: 9px;"
        //"background-image: url(C:/Users/Dell/Documents/BILLUX_/image/blue-and-grey-glossy-corporate-abstract-background-vector.jpg);"
        "}"
        );
    ui->groupBox->setStyleSheet(
        "QGroupBox {"           // General border around the group box
        //"border: 2px solid grey;"
        //"background-color: rgb(242, 244, 245);"
        "    border-radius: 7px;"
        //"background-image: url(C:/Users/Dell/Documents/BILLUX_/image/blue-and-grey-glossy-corporate-abstract-background-vector.jpg);"
        "}"
        );
    ui->groupBox_2->setStyleSheet(
        "QGroupBox {"           // General border around the group box
        //"border: 2px solid lightblue;"
        "background-color: rgb(66, 158, 245);"
        //"background-image: url(C:/Users/Dell/Documents/BILLUX_/image/blue-and-grey-glossy-corporate-abstract-background-vector.jpg);"
        "}"
        );
}


void Additem::on_pushButton_clicked()
{
    if(!appdb.open()){
        qDebug()<<"Connection Failed";

        return;
    }


    //testing the datatype of input entered
    QString input4 = ui->lineEdit_2->text();
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
        ui->lineEdit_2->clear();
        return;
    }

    QString input = ui->lineEdit_3->text();
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
        ui->lineEdit_3->clear();
        return;
    }

    QString input2 = ui->lineEdit_4->text();
    // Check if the input is empty
    if (input2.isEmpty()) {
        // Input is empty, show an error message
        QMessageBox::warning(nullptr, "Invalid Input", "The input field cannot be empty.");
        // Prevent saving to the database
        return;
    }
    bool ok;
    int value = ui->lineEdit_4->text().toInt(&ok); // Try to convert input to an integer
    if (!ok) {
        // Input is not a valid integer, show an error message
        QMessageBox::warning(nullptr, "Invalid Input", "Please enter a valid integer.");
        // Clear the invalid input
        ui->lineEdit_4->clear();
        // Prevent saving to the database (you can return or stop here)
        return;
    }

    QString input3 = ui->lineEdit_5->text();
    // Check if the input is empty
    if (input3.isEmpty()) {
        // Input is empty, show an error message
        QMessageBox::warning(nullptr, "Invalid Input", "The input field cannot be empty.");
        // Prevent saving to the database
        return;
    }
    bool ok2;
    int value2 = ui->lineEdit_5->text().toInt(&ok2); // Try to convert input to an integer
    if (!ok2) {
        // Input is not a valid integer, show an error message
        QMessageBox::warning(nullptr, "Invalid Input", "Please enter a valid integer.");
        // Clear the invalid input
        ui->lineEdit_5->clear();
        // Prevent saving to the database (you can return or stop here)
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
}

void Additem::on_pushButton_2_clicked()
{
    this->hide();
    Facturation f;
    QString setString = ui->label->text();
    f.setText(setString);  // Set the text
    f.loadData();          // Load data using the text
    //profile.setModal(true);
    //profile.exec();

    f.setModal(true);
    f.exec();
}

