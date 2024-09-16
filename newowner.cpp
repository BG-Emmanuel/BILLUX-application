#include "newowner.h"
#include "ui_newowner.h"
#include <QMessageBox>
#include <QApplication>
#include <QRegularExpression>

Newowner::Newowner(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Newowner)
{
    ui->setupUi(this);
    appdb = QSqlDatabase::addDatabase("QSQLITE");
    appdb.setDatabaseName("C:/Users/Dell/Documents/BILLUX_/database/appdb.db");
    loadData();
    loadStyle();
    if (!appdb.open()) {
        qDebug() << "Failed to connect to factdb: " << appdb.lastError().text();
    }
}

Newowner::~Newowner()
{
    delete ui;
}

void Newowner::loadStyle(){
    if(!appdb.open()){
        qDebug()<<"Connection Failed";

        return;
    }

    ui->groupBox_4->setStyleSheet("QGroupBox { background-color: rgb(66, 158, 245); }");

    ui->label->setStyleSheet("QLabel { color: rgb(110, 105, 105); }");
    ui->label_2->setStyleSheet("QLabel { color: rgb(110, 105, 105); }");
    ui->label_3->setStyleSheet("QLabel { color: rgb(110, 105, 105); }");
    ui->label_4->setStyleSheet("QLabel { color: rgb(110, 105, 105); }");
    ui->label_5->setStyleSheet("QLabel { color: rgb(110, 105, 105); }");
    ui->label_6->setStyleSheet("QLabel { color: rgb(110, 105, 105); }");
    ui->label_7->setStyleSheet("QLabel { color: rgb(110, 105, 105); }");
    ui->label_8->setStyleSheet("QLabel { color: rgb(110, 105, 105); }");

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
        "    background-color: white;"
        //"    border: 1px solid white;"
        "    border-radius: 5px;"
        "    color: rgb(66, 158, 245);"
        //"    margin-top: 1.5em;"  // Space for the title
        "}"
        );

    ui->lineEdit->setStyleSheet(
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
    ui->lineEdit_5->setStyleSheet(
        "QLineEdit {"
        //"    background-color: rgb(242, 244, 245);"
        //"    border: 1px solid white;"
        "    border-radius: 5px;"
        "    color: rgb(141, 142, 143);"
        //"    margin-top: 1.5em;"  // Space for the title
        "}"
        );
    ui->lineEdit_6->setStyleSheet(
        "QLineEdit {"
        //"    background-color: rgb(242, 244, 245);"
        //"    border: 1px solid white;"
        "    border-radius: 5px;"
        "    color: rgb(141, 142, 143);"
        //"    margin-top: 1.5em;"  // Space for the title
        "}"
        );
    ui->lineEdit_7->setStyleSheet(
        "QLineEdit {"
        //"    background-color: rgb(242, 244, 245);"
        //"    border: 1px solid white;"
        "    border-radius: 5px;"
        "    color: rgb(141, 142, 143);"
        //"    margin-top: 1.5em;"  // Space for the title
        "}"
        );

    ui->groupBox->setStyleSheet(
        "QGroupBox {"           // General border around the group box
        //"border: 2px solid grey;"
        "background-color: rgb(247, 247, 247);"
        "    border-radius: 7px;"
        //"background-image: url(C:/Users/Dell/Documents/BILLUX_/image/blue-and-grey-glossy-corporate-abstract-background-vector.jpg);"
        "}"
        );
    ui->groupBox_2->setStyleSheet(
        "QGroupBox {"           // General border around the group box
        //"border: 2px solid grey;"
        //"background-color: rgb(242, 244, 243);"
        "    border-radius: 7px;"
        //"background-image: url(C:/Users/Dell/Documents/BILLUX_/image/blue-and-grey-glossy-corporate-abstract-background-vector.jpg);"
        "}"
        );
    ui->groupBox_3->setStyleSheet(
        "QGroupBox {"           // General border around the group box
        //"border: 2px solid lightblue;"
        "background-color: rgb(242, 244, 243);"
        //"background-image: url(C:/Users/Dell/Documents/BILLUX_/image/blue-and-grey-glossy-corporate-abstract-background-vector.jpg);"
        "}"
        );
}

void Newowner::loadData(){

}
void Newowner::on_pushButton_clicked()
{
    //testing the datatype of input entered
    QString input = ui->lineEdit->text();
    // Check if the input is empty
    if (input.isEmpty()) {
        QMessageBox::warning(nullptr, "Invalid Input", "The input field cannot be empty.");
        return;
    }
    // Define a regular expression that allows only letters (upper and lowercase)
    QRegularExpression regex("^[A-Za-z ]+$");
    QRegularExpressionMatch match = regex.match(input);
    // Check if the input matches the regex
    if (!match.hasMatch()) {
        QMessageBox::warning(nullptr, "Invalid Input", "Please enter alphabetic characters only.");
        ui->lineEdit->clear();
        return;
    }

    //testing the datatype of input entered
    QString input2 = ui->lineEdit_2->text();
    // Check if the input is empty
    if (input2.isEmpty()) {
        QMessageBox::warning(nullptr, "Invalid Input", "The input field cannot be empty.");
        return;
    }
    // Define a regular expression that allows only letters (upper and lowercase)
    QRegularExpression regex2("^[A-Za-z ]+$");
    QRegularExpressionMatch match2 = regex2.match(input2);
    // Check if the input matches the regex
    if (!match2.hasMatch()) {
        QMessageBox::warning(nullptr, "Invalid Input", "Please enter alphabetic characters only.");
        ui->lineEdit_2->clear();
        return;
    }

    //testing the datatype of input entered
    QString input3 = ui->lineEdit_3->text();
    // Check if the input is empty
    if (input3.isEmpty()) {
        QMessageBox::warning(nullptr, "Invalid Input", "The input field cannot be empty.");
        return;
    }
    // Define a regular expression that allows only letters (upper and lowercase)
    QRegularExpression regex3("^[A-Za-z ]+$");
    QRegularExpressionMatch match3 = regex3.match(input3);
    // Check if the input matches the regex
    if (!match3.hasMatch()) {
        QMessageBox::warning(nullptr, "Invalid Input", "Please enter alphabetic characters only.");
        ui->lineEdit_3->clear();
        return;
    }

    //testing the datatype of input entered
    QString input4 = ui->lineEdit_4->text();
    // Check if the input is empty
    if (input4.isEmpty()) {
        QMessageBox::warning(nullptr, "Invalid Input", "The input field cannot be empty.");
        return;
    }
    // Define a regular expression that allows only letters (upper and lowercase)
    QRegularExpression regex4("^[A-Za-z0-9 ,.\\-_]+$");
    QRegularExpressionMatch match4 = regex4.match(input4);
    // Check if the input matches the regex
    if (!match4.hasMatch()) {
        QMessageBox::warning(nullptr, "Invalid Input", "Please enter alphabetic characters only.");
        ui->lineEdit_4->clear();
        return;
    }

    QString input5 = ui->lineEdit_5->text();
    // Check if the input is empty
    if (input5.isEmpty()) {
        // Input is empty, show an error message
        QMessageBox::warning(nullptr, "Invalid Input", "The input field cannot be empty.");
        // Prevent saving to the database
        return;
    }
    bool ok;
    int value = ui->lineEdit_5->text().toInt(&ok); // Try to convert input to an integer
    if (!ok) {
        // Input is not a valid integer, show an error message
        QMessageBox::warning(nullptr, "Invalid Input", "Please enter a valid integer.");
        // Clear the invalid input
        ui->lineEdit_5->clear();
        // Prevent saving to the database (you can return or stop here)
        return;
    }

    //testing the datatype of input entered
    QString input6 = ui->lineEdit_6->text();
    // Check if the input is empty
    if (input6.isEmpty()) {
        QMessageBox::warning(nullptr, "Invalid Input", "The input field cannot be empty.");
        return;
    }
    // Define a regular expression that allows only letters (upper and lowercase)
    QRegularExpression regex6("^[A-Za-z0-9 ,.\\-_]+$");
    QRegularExpressionMatch match6 = regex6.match(input6);
    // Check if the input matches the regex
    if (!match6.hasMatch()) {
        QMessageBox::warning(nullptr, "Invalid Input", "Please enter alphabetic characters only.");
        ui->lineEdit_6->clear();
        return;
    }

    //testing the datatype of input entered
    QString input7 = ui->lineEdit_7->text();
    // Check if the input is empty
    if (input7.isEmpty()) {
        QMessageBox::warning(nullptr, "Invalid Input", "The input field cannot be empty.");
        return;
    }
    // Define a regular expression that allows only letters (upper and lowercase)
    QRegularExpression regex7("^[A-Za-z0-9 ,.\\-_]+$");
    QRegularExpressionMatch match7 = regex7.match(input7);
    // Check if the input matches the regex
    if (!match7.hasMatch()) {
        QMessageBox::warning(nullptr, "Invalid Input", "Please enter alphabetic characters only.");
        ui->lineEdit_7->clear();
        return;
    }


    QString name,lastName,enterpriseName,emailAddress,phone,password,confirmPassword;
    name = ui->lineEdit->text();
    lastName = ui->lineEdit_2->text();
    enterpriseName = ui->lineEdit_3->text();
    emailAddress = ui->lineEdit_4->text();
    phone = ui->lineEdit_5->text();
    password = ui->lineEdit_6->text();
    confirmPassword = ui->lineEdit_7->text();

    if(!appdb.open()){
        qDebug()<<"Connections Failed";

        return;
    }

    QSqlQuery qry;
    qry.prepare("INSERT INTO newdt(name,lastName,enterpriseName,emailAddress,phone,password,confirmPassword) VALUES (:name,:lastName,:enterpriseName,:emailAddress,:phone,:password,:confirmPassword)");
    qry.bindValue(":name",name);
    qry.bindValue(":lastName",lastName);
    qry.bindValue(":enterpriseName",enterpriseName);
    qry.bindValue(":emailAddress",emailAddress);
    qry.bindValue(":phone",phone);
    qry.bindValue(":password",password);
    qry.bindValue(":confirmPassword",confirmPassword);

    if(qry.exec()){

        QMessageBox::critical(this,tr("SAVED"),tr("DATA SAVED"));
    }
    else{
        QMessageBox::critical(this,tr("error"),qry.lastError().text());
    }

    //this->hide();
    Login l;
    l.show();
}


void Newowner::on_pushButton_2_clicked()
{

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_7->clear();
    this->hide();
}
