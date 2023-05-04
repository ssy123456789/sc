
#include "dialog.h"
#include "ui_dialog.h"
#include<QPlainTextEdit>
#include <QFont>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->radioButton,SIGNAL(clicked()),this,SLOT(do_setFontColour()));
    connect(ui->radioButton_2,SIGNAL(clicked()),this,SLOT(do_setFontColour()));
    connect(ui->radioButton_3,SIGNAL(clicked()),this,SLOT(do_setFontColour()));
}

Dialog::~Dialog()
{
    delete ui;
}



void Dialog::on_checkBox_clicked(bool checked)
{
    QFont font=ui->textEdit->font();
    font.setUnderline(checked);
    ui->textEdit->setFont(font);
}


void Dialog::on_checkBox_3_clicked(bool checked)
{
    QFont font=ui->textEdit->font();
    font.setBold(checked);
    ui->textEdit->setFont(font);
}


void Dialog::on_checkBox_2_clicked(bool checked)
{

    QFont font=ui->textEdit->font();
    font.setItalic(checked);
    ui->textEdit->setFont(font);
}

void Dialog::do_setFontColour()
{
    //自定义槽函数，设置文本颜色
    QPalette plet=ui->textEdit->palette();
    if(ui->radioButton->isChecked()){
        plet.setColor(QPalette::Text,Qt::red);
    }else if(ui->radioButton_2->isChecked()){
        plet.setColor(QPalette::Text,Qt::black);
    }else if(ui->radioButton_3->isChecked()){
        plet.setColor(QPalette::Text,Qt::blue);
    }else{
        plet.setColor(QPalette::Text,Qt::blue);
    }
    ui->textEdit->setPalette(plet);
}

void Dialog::on_pushButton_clicked(bool checked)
{
    ui->textEdit->clear();
}
void Dialog::on_pushButton_3_clicked(bool checked)
{
    this->close();
}


void Dialog::on_pushButton_2_clicked(bool checked)
{
    this->close();
}

