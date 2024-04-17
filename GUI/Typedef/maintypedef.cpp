#include "maintypedef.h"
#include "ui_maintypedef.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>
#include <QTime>
#include <QDir>
#include <QFile>

MainTypedef::MainTypedef(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainTypedef)
{
//    QMessageBox::information(this,"信息","FILE:" __FILE__ "LINE:" SC_DEFINE_SHOW_ARG_STR(__LINE__) "[成功]");
    ui->setupUi(this);
}

MainTypedef::~MainTypedef()
{
    delete ui;
}


/* ------------------------- 生成 ------------------------- */

void MainTypedef::core(void )
{
    save=tr(
R"CCASDASD(
/*---------------------------------------------------------*\


                如果不配置 将假设环境为C89行为
            为了兼容性 将不进行编译器环境判断 防止误判


\*---------------------------------------------------------*/

)CCASDASD");

    if(ui->checkBox_SC_UNUSED->checkState()) {     
        save += tr("\n");
        save += tr("#define SC_CONFIG_UNUSED ");
        save += ui->lineEdit_SC_UNUSED->text();
        save += tr("\n\n");
    }

    if(ui->checkBox_SC_CONST->checkState()) {     
        save += tr("\n");
        save += tr("#define SC_CONFIG_CONST ");
        save += ui->lineEdit_SC_CONST->text();
        save += tr("\n\n");
    }

    if(ui->checkBox_SC_ADDRFUN->checkState() && (ui->comboBox_SC_ADDRFUN->currentText()== tr("(fun)"))) {
        save += tr("\n");
        save += tr("#define SC_CONFIG_ADDRFUN 1 ");
        save += tr("\n\n");
    }

    if(ui->checkBox_SC_ATT_XXXX->checkState() ) {
        save += tr("\n");
        save += tr("#define SC_CONFIG_ATT 1 ");
        save += tr("\n\n");
    }

    if(ui->checkBox_stddef->checkState() ) {
        save += tr("\n");
        save += ui->lineEdit_stddef->text();
        save += tr("\n\n");
    }

    if(ui->checkBox_stdarg->checkState() ) {
        save += tr("\n");
        save += ui->lineEdit_stdarg->text();
        save += tr("\n\n");
    }

    if(ui->checkBox_64BIT->checkState() && (ui->comboBox_64BIT->currentText()== tr("确定支持64"))) {
        save += tr("\n");
        save += tr("#define SC_CONFIG_64BIT_SUPPORT 1U ");
        save += tr("\n\n");
    }

    if(
        ui->checkBox_sc_use_mode->currentText() == tr("C89头文件 手动定义 + 自动判断") 
     ) {
        if(ui->checkBox_limits->checkState() ) {
            save += tr("\n");
            save += ui->lineEdit_limits->text();
            save += tr("\n\n");
        }
    }

    if(
        ui->checkBox_sc_use_mode->currentText() == tr("C99头文件 自动判断") 
     ) {
        if(ui->checkBox_stdint->checkState() ) {
            save += tr("\n");
            save += ui->lineEdit_stdint->text();
            save += tr("\n\n");
        }
        if(ui->checkBox_stdbool->checkState() ) {
            save += tr("\n");
            save += ui->lineEdit_stdbool->text();
            save += tr("\n\n");
        }
        if(ui->checkBox_var1_use_uint8->checkState() ) {
            save += tr("\n");
            save += tr("#define SC_CONFIG_TYPE_VAR1_BOOL 0 ");
            save += tr("\n\n");
        }
    }

    if(
        ui->checkBox_sc_use_mode->currentText() == tr("C89头文件 手动定义 + 自动判断") ||
        ui->checkBox_sc_use_mode->currentText() == tr("数据类型    手动定义")
       ) {

        if(ui->checkBox_VAR1->checkState()) {     
            save += tr("\n");
            save += tr("#define SC_CONFIG_TYPE_VAR1 ");
            save += ui->lineEdit_VAR1->text();
            save += tr("\n\n");
        }

        if(ui->checkBox_VAR8->checkState()) {     
            save += tr("\n");
            save += tr("#define SC_CONFIG_TYPE_VAR8 ");
            save += ui->lineEdit_VAR8->text();
            save += tr("\n\n");
        }

        if(ui->checkBox_SVAR8->checkState()) {     
            save += tr("\n");
            save += tr("#define SC_CONFIG_TYPE_SVAR8 ");
            save += ui->lineEdit_SVAR8->text();
            save += tr("\n\n");
        }

        if(ui->checkBox_VAR16->checkState()) {     
            save += tr("\n");
            save += tr("#define SC_CONFIG_TYPE_VAR16 ");
            save += ui->lineEdit_VAR16->text();
            save += tr("\n\n");
        }

        if(ui->checkBox_SVAR16->checkState()) {     
            save += tr("\n");
            save += tr("#define SC_CONFIG_TYPE_SVAR16 ");
            save += ui->lineEdit_SVAR16->text();
            save += tr("\n\n");
        }

        if(ui->checkBox_VAR32->checkState()) {     
            save += tr("\n");
            save += tr("#define SC_CONFIG_TYPE_VAR32 ");
            save += ui->lineEdit_VAR32->text();
            save += tr("\n\n");
        }

        if(ui->checkBox_SVAR32->checkState()) {     
            save += tr("\n");
            save += tr("#define SC_CONFIG_TYPE_SVAR32 ");
            save += ui->lineEdit_SVAR32->text();
            save += tr("\n\n");
        }

        if(ui->checkBox_VARMAX->checkState()) {     
            save += tr("\n");
            save += tr("#define SC_CONFIG_TYPE_VARMAX ");
            save += ui->lineEdit_VARMAX->text();
            save += tr("\n\n");
        }

        if(ui->checkBox_SVARMAX->checkState()) {     
            save += tr("\n");
            save += tr("#define SC_CONFIG_TYPE_SVARMAX ");
            save += ui->lineEdit_SVARMAX->text();
            save += tr("\n\n");
        }

        if(ui->checkBox_VARPTR->checkState()) {     
            save += tr("\n");
            save += tr("#define SC_CONFIG_TYPE_VARPTR ");
            save += ui->lineEdit_VARPTR->text();
            save += tr("\n\n");
        }

        if(ui->checkBox_SVARPTR->checkState()) {     
            save += tr("\n");
            save += tr("#define SC_CONFIG_TYPE_SVARPTR ");
            save += ui->lineEdit_SVARPTR->text();
            save += tr("\n\n");
        }

    }

    if(ui->comboBox_restrict->currentText()== tr("支持") ) {     
        save += tr("\n");
        save += tr("#define SC_CONFIG_RESTRICT 1");
        save += tr("\n\n");
    }
    else if(ui->comboBox_restrict->currentText()== tr("自定义")){
        save += tr("\n");
        save += tr("#define SC_CONFIG_RESTRICT_SET ");
        save += ui->lineEdit_restrict->text();
        save += tr("\n\n");
    }


    if(ui->comboBox_Static_assert->currentText()== tr("兼容模式") ) {     
        save += tr("\n");
        save += tr("#define SC_CONFIG_STATIC_ASSERT 1");
        save += tr("\n\n");
    }
    else if(ui->comboBox_Static_assert->currentText()== tr("LINE模式") ) {     
        save += tr("\n");
        save += tr("#define SC_CONFIG_STATIC_ASSERT 2");
        save += tr("\n\n");
    }
    else if(ui->comboBox_Static_assert->currentText()== tr("C11模式") ) {     
        save += tr("\n");
        save += tr("#define SC_CONFIG_STATIC_ASSERT 3");
        save += tr("\n\n");
    }
    else if(ui->comboBox_Static_assert->currentText()== tr("自定义")){
        save += tr("\n");
        save += tr("#define SC_STATIC_ASSERT ");
        save += ui->lineEdit_Static_assert->text();
        save += tr("\n\n");
    }


    if(ui->comboBox_TYPE_CAST->currentText()== tr("C++样式") ) {     
        save += tr("\n");
        save += tr("#define SC_CONFIG_TYPE_CAST 1");
        save += tr("\n\n");
    }
    if(ui->comboBox_CHECKLISTS->currentText()== tr("使用") ) {     
        save += tr("\n");
        save += tr("#define SC_CONFIG_USE_CHECKLISTS 1");
        save += tr("\n\n");
    }

}


void MainTypedef::on_pushButton_clicked()
{

        QString filePath;//存储保存路径
        filePath = QFileDialog::getSaveFileName(this,tr(""),tr("sc_typedef_config.h"));//获取文件夹路径
        QFile file(filePath);//创建文件对象
        bool tag = file.open(QIODevice::WriteOnly);//写内容到文件中
        if(!tag)
        {
            QMessageBox::information(this,"信息","保存失败");
            return;
        }

        if(filePath.isEmpty())
        {
            QMessageBox::information(this,"信息","保存失败");
        }
        else
        {
            core();
            file.write(save.toUtf8());//将text内容转化为字节数组
            file.close();
            QMessageBox::information(this,"信息","保存成功");
        }
}

