#ifndef FACTURATION_H
#define FACTURATION_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Facturation;
}
QT_END_NAMESPACE

class Facturation : public QMainWindow
{
    Q_OBJECT

public:
    Facturation(QWidget *parent = nullptr);
    ~Facturation();

private:
    Ui::Facturation *ui;
};
#endif // FACTURATION_H
