
#include "dialog.h"
//#include<QFont>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QPlainTextEdit>
#include<QPalette>
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    //界面创建与布局
    iniui();
    //信与槽的关联
    iniSignalSlots();
    //设置窗口标题
    setWindowTitle("手工创建ui");
}

void Dialog::iniui(){
    //创建三个复选框，并水平对齐
    chUnderLine=new QCheckBox("underline");
    chBold=new QCheckBox("bold");
    chItalic=new QCheckBox("italic");
    QHBoxLayout *hy=new QHBoxLayout();
    hy->addWidget(chUnderLine);
    hy->addWidget(chBold);
    hy->addWidget(chItalic);
    //创建三个单选按钮并水平对齐
    radioRed=new QRadioButton("red");
    radioRed->setChecked(true);
    radioGreen=new QRadioButton("Green");
    radioBlue=new QRadioButton("Blue");
    QHBoxLayout *hy1=new  QHBoxLayout();
    hy1->addWidget(radioRed);
    hy1->addWidget(radioGreen);
    hy1->addWidget(radioBlue);
    //创建三个按钮并水平对齐
    btnOK=new QPushButton("确定");
    btnCancel=new QPushButton("取消");
    btnExit=new QPushButton("退出");
    QHBoxLayout *hy2=new  QHBoxLayout();
    hy2->addWidget(btnOK);
    hy2->addWidget(btnCancel);
    hy2->addWidget(btnExit);
    //创建文本框并初始化字体
    txtEdit=new QPlainTextEdit;
    txtEdit->setPlainText("hello word\n手工创建");
    //获取字体
    QFont font=txtEdit->font();
    //设置字体大小
    font.setPointSize(20);
    //设置字体
    txtEdit->setFont(font);
    //创建垂直布局并且设置成主布局
    QVBoxLayout *vy=new QVBoxLayout(this);
    vy->addLayout(hy);
    vy->addLayout(hy1);
    vy->addWidget(txtEdit);
    vy->addLayout(hy2);
    setLayout(vy);
}

void Dialog::iniSignalSlots(){
    //三个设置颜色的单选按钮
    connect(radioRed,SIGNAL(clicked()),this,SLOT(do_setFontColor()));
    connect(radioGreen,SIGNAL(clicked()),this,SLOT(do_setFontColor()));
    connect(radioBlue,SIGNAL(clicked()),this,SLOT(do_setFontColor()));
    //设置三个字体的复选框
    connect(chUnderLine,SIGNAL(clicked(bool)),this,SLOT(do_chUnderLine(bool)));
    connect(chBold,SIGNAL(clicked(bool)),this,SLOT(do_chBold(bool)));
    connect(chItalic,SIGNAL(clicked(bool)),this,SLOT(do_chItalic(bool)));
    //三个按钮与槽函数的关系
    connect(btnOK,SIGNAL(clicked()),this,SLOT(accept()));
    connect(btnCancel,SIGNAL(clicked()),this,SLOT(reject()));
    connect(btnExit,SIGNAL(clicked()),this,SLOT(close()));



}

//设置下划线
void Dialog::do_chUnderLine(bool checked){
    QFont font=txtEdit->font();
    font.setUnderline(checked);
    txtEdit->setFont(font);
}
//设置字体加粗
void Dialog::do_chBold(bool checked){
    QFont font=txtEdit->font();
    font.setBold(checked);
    txtEdit->setFont(font);
}
//设置字体倾斜
void Dialog::do_chItalic(bool checked){
    QFont font=txtEdit->font();
    font.setItalic(checked);
    txtEdit->setFont(font);
}
//设置字体颜色
void Dialog::do_setFontColor(){
    //自定义槽函数，设置文本颜色
    QPalette plet=txtEdit->palette();
    if(radioRed->isChecked()){
        plet.setColor(QPalette::Text,Qt::red);
    }else if(radioGreen->isChecked()){
        plet.setColor(QPalette::Text,Qt::green);
    }else if(radioBlue->isChecked()){
        plet.setColor(QPalette::Text,Qt::blue);
    }else{
        plet.setColor(QPalette::Text,Qt::blue);
    }
    txtEdit->setPalette(plet);

}
Dialog::~Dialog()
{
}


