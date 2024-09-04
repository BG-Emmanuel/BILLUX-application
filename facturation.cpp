#include "facturation.h"
#include "ui_facturation.h"

Facturation::Facturation(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Facturation)
{
    ui->setupUi(this);
}

Facturation::~Facturation()
{
    delete ui;
}
