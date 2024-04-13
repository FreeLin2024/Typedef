#include "maintypedef.h"
#include "ui_maintypedef.h"

MainTypedef::MainTypedef(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainTypedef)
{
    ui->setupUi(this);
}

MainTypedef::~MainTypedef()
{
    delete ui;
}

