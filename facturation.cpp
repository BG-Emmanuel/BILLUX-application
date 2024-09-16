#include "facturation.h"
#include "ui_facturation.h"
#include <QMessageBox>
#include <QDate>
#include <QRegularExpression>
#include <QIcon>
#include <QDesktopServices>

Facturation::Facturation(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Facturation)
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

Facturation::~Facturation()
{
    delete ui;
}

void Facturation::setText(const QString &text) {
    dataText = text;
}


void Facturation::loadStyle(){
    if(!appdb.open()){
        qDebug()<<"Connection Failed";

        return;
    }

    this->setWindowIcon(QIcon("C:/Users/Dell/Documents/BILLUX_/image/images(5).png"));
    this->setWindowTitle("Billing");

   ui->groupBox_4->setStyleSheet("QGroupBox { background-color:rgb(237, 237, 237); }");
    ui->groupBox_3->setStyleSheet("QGroupBox { background-color: rgb(66, 158, 245); }");
   ui->groupBox_7->setStyleSheet("QGroupBox { background-color: rgb(66, 158, 245); }");
   ui->groupBox->setStyleSheet("QGroupBox { background-color: rgb(244, 244, 244); }");
   ui->label_7->setStyleSheet("QLabel { color: rgb(84, 80, 80); }");
   ui->label_10->setStyleSheet("QLabel { color: rgb(84, 80, 80); }");
   ui->label_8->setStyleSheet("QLabel { color: rgb(84, 80, 80); }");
   ui->label_9->setStyleSheet("QLabel { color: rgb(84, 80, 80); }");

    QIcon buttonIcon("C:/Users/Dell/Documents/BILLUX_/image/images(5).jpeg");
    ui->pushButton_3->setIcon(buttonIcon);
    QIcon buttonIcon2("C:/Users/Dell/Documents/BILLUX_/image/images(5).png");
    ui->pushButton_13->setIcon(buttonIcon2);
    QIcon buttonIcon3("C:/Users/Dell/Documents/BILLUX_/image/12449018.png");
    ui->pushButton_7->setIcon(buttonIcon3);
    QIcon buttonIcon4("C:/Users/Dell/Documents/BILLUX_/image/images(3).png");
    ui->pushButton_9->setIcon(buttonIcon4);
    QIcon buttonIcon7("C:/Users/Dell/Documents/BILLUX_/image/realprofile2.png");
    ui->pushButton_12->setIcon(buttonIcon7);
    QIcon buttonIcon8("C:/Users/Dell/Documents/BILLUX_/image/item2.png");
    ui->pushButton_5->setIcon(buttonIcon8);
    //QIcon buttonIcon9("C:/Users/Dell/Documents/BILLUX_/image/images(9).png");
    //ui->pushButton_14->setIcon(buttonIcon9);

    QIcon buttonIcon5("C:/Users/Dell/Documents/BILLUX_/image/9385289.png");
    ui->pushButton_4->setIcon(buttonIcon5);
    QIcon buttonIcon6("C:/Users/Dell/Documents/BILLUX_/image/help4.png");
    ui->pushButton_11->setIcon(buttonIcon6);

    QIcon buttonIcon10("C:/Users/Dell/Documents/BILLUX_/image/search-137.png");
    ui->pushButton->setIcon(buttonIcon10);
    QIcon buttonIcon11("C:/Users/Dell/Documents/BILLUX_/image/send.png");
    ui->pushButton_2->setIcon(buttonIcon11);
    QIcon buttonIcon12("C:/Users/Dell/Documents/BILLUX_/image/plus.png");
    ui->pushButton_8->setIcon(buttonIcon12);


    ui->pushButton_7->setIconSize(QSize(27, 27));
    //ui->pushButton_14->setIconSize(QSize(43, 43));
    ui->pushButton_5->setIconSize(QSize(25, 25));
    ui->pushButton_13->setIconSize(QSize(23, 23));
    ui->pushButton_4->setIconSize(QSize(20, 20));
    ui->pushButton_9->setIconSize(QSize(34, 34));
    ui->pushButton_12->setIconSize(QSize(47, 47));
    ui->pushButton_3->setIconSize(QSize(27, 27));
    ui->pushButton_11->setIconSize(QSize(27, 27));
    ui->pushButton->setIconSize(QSize(18, 18));
    ui->pushButton_2->setIconSize(QSize(16, 16));

    ui->pushButton_13->setStyleSheet(
        "QPushButton {"
        "    background-color: white;"
        "    border: 1px solid white;"
        "    border-left: 2px solid rgb(66, 158, 245);"
        "    border-radius: 5px;"
        "    color: rgb(40, 41, 46);"
        //"    margin-top: 1.5em;"  // Space for the title
        "}"
        "QPushButton::title {"
        "    subcontrol-origin: margin;"
        "    subcontrol-position: top left;"  // Position the title to the top left
        "    padding: 0 3px;"
        "    color: lightblue;"
        "    background-color: lightgray;"  // Title background
        "}"
        );

    ui->pushButton_3->setStyleSheet(
        "QPushButton {"
        "    background-color: rgb(237, 237, 237);"
        "    border: 1px solid rgb(237, 237, 237);"
        //"    border-radius: 3px;"
        "    color: rgb(88, 88, 92);"
        //"    margin-top: 1.5em;"  // Space for the title
        "}"
        );
    ui->pushButton_7->setStyleSheet(
        "QPushButton {"
        "    background-color: rgb(237, 237, 237);"
        "    border: 1px solid rgb(237, 237, 237);"
        //"    border-radius: 3px;"
        "    color: rgb(88, 88, 92);"
        //"    margin-top: 1.5em;"  // Space for the title
        "}"
        );
    ui->pushButton_9->setStyleSheet(
        "QPushButton {"
        "    background-color: rgb(237, 237, 237);"
        "    border: 1px solid rgb(237, 237, 237);"
        //"    border-radius: 3px;"
        "    color: rgb(88, 88, 92);"
        //"    margin-top: 1.5em;"  // Space for the title
        "}"
        );
    ui->pushButton_12->setStyleSheet(
        "QPushButton {"
        "    background-color: rgb(237, 237, 237);"
        "    border: 1px solid rgb(237, 237, 237);"
        //"    border-radius: 3px;"
        "    color: rgb(88, 88, 92);"
        //"    margin-top: 1.5em;"  // Space for the title
        "}"
        );
    /*ui->pushButton_14->setStyleSheet(
        "QPushButton {"
        "    background-color: rgb(237, 237, 237);"
        "    border: 1px solid rgb(237, 237, 237);"
        //"    border-radius: 3px;"
        "    color: rgb(88, 88, 92);"
        //"    margin-top: 1.5em;"  // Space for the title
        "}"
        );*/

    ui->pushButton_8->setStyleSheet(
        "QPushButton {"
        "    background-color: rgb(242, 244, 245);"
        "    border: 1px solid rgb(242, 244, 245);"
        //"    border-radius: 3px;"
        "    color: rgb(40, 41, 46);"
        //"    margin-top: 1.5em;"  // Space for the title
        "}"
        );
    ui->pushButton_6->setStyleSheet(
        "QPushButton {"
        "    background-color: rgb(242, 244, 245);"
        "    border: 1px solid rgb(242, 244, 245);"
        "    border-right: 1px solid rgb(66, 158, 245);"
        "    border-left: 1px solid rgb(66, 158, 245);"
        "    border-radius: 5px;"
        "    color: rgb(84, 80, 80);"
        //"    margin-top: 1.5em;"  // Space for the title
        "}"
        );
    ui->pushButton->setStyleSheet(
        "QPushButton {"
        "    background-color: white;"
        //"    border: 1px solid white;"
        "border-top: 1px solid rgb(242, 244, 245);"      // Rounding the top-left corner
        "border-right: 1px solid rgb(242, 244, 245);"
        //"    border-radius: 3px;"
        "    color: rgb(40, 41, 46);"
        //"    margin-top: 1.5em;"  // Space for the title
        "}"
        );
    ui->pushButton_2->setStyleSheet(
        "QPushButton {"
        "    background-color: white;"
        "    border: 1px solid rgb(242, 244, 245);"
        //"    border-radius: 3px;"
        "    color: rgb(40, 41, 46);"
        //"    margin-top: 1.5em;"  // Space for the title
        "}"
        );

    ui->pushButton_4->setStyleSheet(
        "QPushButton {"
        "    background-color: rgb(66, 158, 245);"
        "    border: 4px solid rgb(237, 237, 237);"
        "    border-radius: 7px;"
        "    color: white;"
        //"    margin-top: 1.5em;"  // Space for the title
        "}"
        "QPushButton::title {"
        "    subcontrol-origin: margin;"
        "    subcontrol-position: top left;"  // Position the title to the top left
        //"    background-image: url(:/path/to/image.png);"
        "    background-color: lightgray;"  // Title background
        "}"
        );

    ui->groupBox_5->setStyleSheet(
        "QGroupBox {"           // General border around the group box
        "border-top-left-radius: 10px;"      // Rounding the top-left corner
        "border-top-right-radius: 10px;"     // Rounding the top-right corner
        "background-color: rgb(247, 247, 247);"
        "}"
        );

    ui->groupBox_6->setStyleSheet(
        "QGroupBox {"           // General border around the group box
        //"border: 2px solid lightblue;"
        "background-color: rgb(254, 254, 254);"
        //"background-image: url(C:/Users/Dell/Documents/BILLUX_/image/9385289.png);"
        "}"
        );

    ui->groupBox_2->setStyleSheet(
        "QGroupBox {"           // General border around the group box
        //"border: 2px solid lightblue;"
        "background-color: rgb(237, 237, 237);"
        "    color: blue;"
        //"background-image: url(C:/Users/Dell/Documents/BILLUX_/image/9385289.png);"
        "}"
        );

    ui->comboBox->setStyleSheet(
        "QComboBox {"
        "    background-color: rgb(242, 244, 245);"
        "    border: 1px solid rgb(242, 244, 245);"
        //"    border-radius: 3px;"
        "    color: rgb(40, 41, 46);"
        //"    margin-top: 1.5em;"  // Space for the title
        "}"
        );

    ui->listView_13->setStyleSheet(
        "QListView {"
        "    background-color: rgb(247, 247, 247);"
        "    border: 2px solid white;"      // Rounding the top-left corner
        "border-top-left-radius: 13px;"
        "    color: rgb(84, 80, 80);"
        //"    margin-top: 1.5em;"  // Space for the title
        "}"
        );
    ui->listView_14->setStyleSheet(
        "QListView  {"
        "    background-color: rgb(247, 247, 247);"
        "    border: 2px solid white;"     // Rounding the top-left corner
        "border-top-right-radius: 13px;"
        "    color: rgb(84, 80, 80);"
        //"    margin-top: 1.5em;"  // Space for the title
        "}"
        );
    ui->listView->setStyleSheet(
        "QListView {"
        "    background-color: rgb(247, 247, 247);"
        "    border: 2px solid white;"      // Rounding the top-left corner
        //"border-top-left-radius: 13px;"
        "    color: rgb(84, 80, 80);"
        //"    margin-top: 1.5em;"  // Space for the title
        "}"
        );
    ui->listView_2->setStyleSheet(
        "QListView  {"
        "    background-color: rgb(247, 247, 247);"
        "    border: 2px solid white;"     // Rounding the top-left corner
        //"border-top-right-radius: 13px;"
        "    color: rgb(84, 80, 80);"
        //"    margin-top: 1.5em;"  // Space for the title
        "}"
        );
    ui->listView_3->setStyleSheet(
        "QListView {"
        "    background-color: rgb(247, 247, 247);"
        "    border: 2px solid white;"      // Rounding the top-left corner
        //"border-top-left-radius: 13px;"
        "    color: rgb(84, 80, 80);"
        //"    margin-top: 1.5em;"  // Space for the title
        "}"
        );
    ui->listView_4->setStyleSheet(
        "QListView  {"
        "    background-color: rgb(248, 248, 248);"
        "    border: 2px solid white;"     // Rounding the top-left corner
        //"border-top-right-radius: 13px;"
        "    color: rgb(84, 80, 80);"
        //"    margin-top: 1.5em;"  // Space for the title
        "}"
        );
    ui->listView_5->setStyleSheet(
        "QListView {"
        "    background-color: rgb(247, 247, 247);"
        "    border: 2px solid white;"      // Rounding the top-left corner
        //"border-top-left-radius: 13px;"
        "    color: rgb(84, 80, 80);"
        //"    margin-top: 1.5em;"  // Space for the title
        "}"
        );
    ui->listView_6->setStyleSheet(
        "QListView  {"
        "    background-color: rgb(247, 247, 247);"
        "    border: 2px solid white;"     // Rounding the top-left corner
        //"border-top-right-radius: 13px;"
        "    color: rgb(84, 80, 80);"
        //"    margin-top: 1.5em;"  // Space for the title
        "}"
        );

    ui->label->setStyleSheet(
        "QLabel  {"
        "    background-color: rgb(248, 248, 248);"
        "    border: 2px solid white;"     // Rounding the top-left corner
        //"border-top-right-radius: 13px;"
        "    color:rgb(84, 80, 80);"
        //"    margin-top: 1.5em;"  // Space for the title
        "}"
        );
    ui->label_2->setStyleSheet(
        "QLabel  {"
        "    background-color: rgb(248, 248, 248);"
        "    border: 2px solid white;"     // Rounding the top-left corner
        //"border-top-right-radius: 13px;"
        "    color:rgb(84, 80, 80);"
        //"    margin-top: 1.5em;"  // Space for the title
        "}"
        );
    ui->label_3->setStyleSheet(
        "QLabel  {"
        "    background-color: rgb(248, 248, 248);"
        "    border: 2px solid white;"     // Rounding the top-left corner
        //"border-top-right-radius: 13px;"
        "    color:rgb(84, 80, 80);"
        //"    margin-top: 1.5em;"  // Space for the title
        "}"
        );
    ui->label_4->setStyleSheet(
        "QLabel  {"
        "    background-color: rgb(248, 248, 248);"
        "    border: 2px solid white;"     // Rounding the top-left corner
        //"border-top-right-radius: 13px;"
        "    color:rgb(84, 80, 80);"
        //"    margin-top: 1.5em;"  // Space for the title
        "}"
        );
    ui->label_5->setStyleSheet(
        "QLabel  {"
        "    background-color: rgb(248, 248, 248);"
        "    border: 2px solid white;"     // Rounding the top-left corner
        //"border-top-right-radius: 13px;"
        "    color:rgb(84, 80, 80);"
        //"    margin-top: 1.5em;"  // Space for the title
        "}"
        );
    ui->label->setStyleSheet(
        "QLabel  {"
        "    background-color: rgb(248, 248, 248);"
        "    border: 2px solid white;"     // Rounding the top-left corner
        //"border-top-right-radius: 13px;"
        "    color:rgb(84, 80, 80);"
        //"    margin-top: 1.5em;"  // Space for the title
        "}"
        );
    ui->label_6->setStyleSheet(
        "QLabel  {"
        "    background-color: rgb(248, 248, 248);"
        "    border: 2px solid white;"     // Rounding the top-left corner
        //"border-top-right-radius: 13px;"
        "border-top-color: rgb(248, 248, 248);"
        "    color:rgb(84, 80, 80);"
        //"    margin-top: 1.5em;"  // Space for the title
        "}"
        );

    ui->lineEdit->setStyleSheet(
        "QLineEdit {"
        //"    background-color: white;"
        "    border: 2px solid rgb(242, 244, 245);"
        //"    border-radius: 5px;"
        "    color: rgb(84, 80, 80);"
        //"    margin-top: 1.5em;"  // Space for the title
        "}"
        );
    ui->lineEdit_2->setStyleSheet(
        "QLineEdit {"
        //"    background-color: white;"
        "    border: 2px solid rgb(242, 244, 245);"
        //"    border-radius: 5px;"
        "    color: rgb(84, 80, 80);"
        //"    margin-top: 1.5em;"  // Space for the title
        "}"
        );
    ui->lineEdit_3->setStyleSheet(
        "QLineEdit {"
        //"    background-color: white;"
        "    border: 2px solid rgb(242, 244, 245);"
        //"    border-radius: 5px;"
        "    color: rgb(84, 80, 80);"
        //"    margin-top: 1.5em;"  // Space for the title
        "}"
        );
    ui->lineEdit_4->setStyleSheet(
        "QLineEdit {"
        //"    background-color: white;"
        "    border: 2px solid rgb(242, 244, 245);"
        //"    border-radius: 5px;"
        "    color: rgb(84, 80, 80);"
        //"    margin-top: 1.5em;"  // Space for the title
        "}"
        );
    ui->lineEdit_5->setStyleSheet(
        "QLineEdit {"
        //"    background-color: white;"
        "    border: 2px solid rgb(242, 244, 245);"
        //"    border-radius: 5px;"
        "    color: rgb(84, 80, 80);"
        //"    margin-top: 1.5em;"  // Space for the title
        "}"
        );
    ui->lineEdit_6->setStyleSheet(
        "QLineEdit {"
        //"    background-color: white;"
        "    border: 2px solid rgb(242, 244, 245);"
        //"    border-radius: 5px;"
        "    color: rgb(84, 80, 80);"
        //"    margin-top: 1.5em;"  // Space for the title
        "}"
        );

}

void Facturation::loadData()
{
    if(!appdb.open()){
        qDebug()<<"Connection Failed";

        return;
    }




    QString name = dataText;
    ui->label_11->setText(name);

    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery(appdb);
    qry->prepare("select reference from itemdt ORDER BY reference ASC");
    qry->exec();
    modal->setQuery(*qry);
    ui->listView_13->setModel(modal);

    QSqlQueryModel * modal2 = new QSqlQueryModel();
    QSqlQuery* qry2 = new QSqlQuery(appdb);
    qry2->prepare("select designation from itemdt ORDER BY reference ASC");
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


    //testing the datatype of input entered
    QString input = ui->lineEdit->text();
    // Check if the input is empty
    if (input.isEmpty()) {
        // Input is empty, show an error message
        QMessageBox::warning(nullptr, "Invalid Input", "The input field cannot be empty.");
        // Prevent saving to the database
        return;
    }// Define a regular expression that allows only letters (upper and lowercase)
    QRegularExpression regex("^[A-Za-z]+$");
    QRegularExpressionMatch match = regex.match(input);
    // Check if the input matches the regex
    if (!match.hasMatch()) {
        QMessageBox::warning(nullptr, "Invalid Input", "Please enter alphabetic characters only.");
        ui->lineEdit->clear();
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
            ui->lineEdit->setText(qry2.value(1).toString());
            ui->lineEdit_3->setText(qry2.value(3).toString());
            ui->lineEdit_2->setText(qry2.value(2).toString());
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
            ui->lineEdit->setText(qry1.value(1).toString());
            ui->lineEdit_3->setText(qry1.value(3).toString());
            ui->lineEdit_2->setText(qry1.value(2).toString());
        }

    }else{
        QMessageBox::critical(this,tr("error::"),qry1.lastError().text());
    }
}





//                       Inserting the custommers Items to the Bill dadabase
void Facturation::on_pushButton_2_clicked()
{

    QString input4 = ui->lineEdit_5->text();
    // Check if the input is empty
    if (input4.isEmpty()) {
        // Input is empty, show an error message
        QMessageBox::warning(nullptr, "Invalid Input", "The input field cannot be empty.");
        // Prevent saving to the database
        return;
    }
    bool ok3;
    int value3 = ui->lineEdit_5->text().toInt(&ok3); // Try to convert input to an integer
    if (!ok3) {
        // Input is not a valid integer, show an error message
        QMessageBox::warning(nullptr, "Invalid Input", "Please enter a valid integer.");
        // Clear the invalid input
        ui->lineEdit_5->clear();
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

    //testing the datatype of input entered
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


    //Inserting the current date into the database
    QDate currentDate = QDate::currentDate();
    QSqlQuery d_query;
    d_query.prepare("INSERT INTO datedt (date) VALUES (:currentDate)");
    d_query.bindValue(":currentDate", currentDate.toString("dd-MM-yyyy"));
    // Execute the query
    if (d_query.exec()) {
        QMessageBox::critical(this,tr("SAVED"),tr("DATA SAVED"));
    }
    else{
        QMessageBox::critical(this,tr("error"),d_query.lastError().text());
    }


    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
}


void Facturation::on_pushButton_9_clicked()
{
    QString setString = ui->label_11->text();
    Customer c;
    c.setText(setString);
    c.loadData();
    c.setModal(true);
    c.exec();
    if(c.close()){
        this->hide();
    }
}


void Facturation::on_pushButton_7_clicked()
{
    Addcustomer a;
    QString setString = ui->label_11->text();

    a.setText(setString);
    a.loadData();
    a.setModal(true);
    a.exec();
    if(a.close()){
        this->hide();
    }
}


void Facturation::on_pushButton_8_clicked()
{
    Addcustomer a;
    QString setString = ui->label_11->text();

    a.setText(setString);
    a.loadData();
    a.setModal(true);
    a.exec();
    if(a.close()){
        this->hide();
    }
}


void Facturation::on_pushButton_5_clicked()
{
    Modif m;
    QString setString = ui->label_11->text();
    m.setText(setString);
    m.loadData();
    m.setModal(true);
    m.exec();
    if(m.close()){
        this->hide();
    }
}


void Facturation::on_pushButton_4_clicked()
{
    Newowner n;
    QString setString = ui->label_11->text();
    n.setText(setString);
    n.loadData();
    n.setModal(true);

    n.exec();


}


void Facturation::on_pushButton_3_clicked()
{
    Additem ai;
    QString setString = ui->label_11->text();

    ai.setText(setString);
    ai.loadData();
    ai.setModal(true);
    ai.exec();
    if(ai.close()){
        this->hide();
    }
}


void Facturation::on_pushButton_12_clicked()
{
    Profile p;
    QString setString = ui->label_11->text();
    p.setText(setString);
    p.loadData();
    p.setModal(true);
    p.exec();
    //Profile *p = new Profile(setString, this);

    // Call the load function in the SecondWindow to use the passed text
    //p->loadData();
    //p->setModal(true);
    //p->exec();
}


void Facturation::on_pushButton_6_clicked()
{


    // Preparing the SQL query for deletion


    QString setString = ui->lineEdit_6->text();
    QString setString2 = ui->label_11->text();
    QString setString3 = ui->label_7->text();
    QString setString4 = ui->label_10->text();
    Preview pe;
    pe.setText(setString2);
    pe.setText2(setString);    // Set the text
    pe.setText3(setString3);
    pe.setText4(setString4);
    pe.loadData();
    pe.setModal(true);
    pe.exec();
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


void Facturation::on_pushButton_11_clicked()
{
    QDesktopServices::openUrl(QUrl("https://billux.tiiny.site/"));
}

