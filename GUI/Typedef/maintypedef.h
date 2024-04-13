#ifndef MAINTYPEDEF_H
#define MAINTYPEDEF_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainTypedef; }
QT_END_NAMESPACE

class MainTypedef : public QMainWindow
{
    Q_OBJECT

public:
    MainTypedef(QWidget *parent = nullptr);
    ~MainTypedef();

private:
    Ui::MainTypedef *ui;
};
#endif // MAINTYPEDEF_H
