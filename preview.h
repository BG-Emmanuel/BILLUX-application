#ifndef PREVIEW_H
#define PREVIEW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Preview;
}
QT_END_NAMESPACE

class Preview : public QMainWindow
{
    Q_OBJECT

public:
    Preview(QWidget *parent = nullptr);
    ~Preview();

private:
    Ui::Preview *ui;
};
#endif // PREVIEW_H
