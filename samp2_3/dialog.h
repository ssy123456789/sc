
#ifndef DIALOG_H
#define DIALOG_H
#include <QDialog>
#include<QCheckBox>
#include<QRadioButton>
#include<QPushButton>
#include<QPlainTextEdit>


class Dialog : public QDialog

{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
private:
    //声明三个复选框
    QCheckBox *chUnderLine;
    QCheckBox *chItalic;
    QCheckBox *chBold;
    //声明三个单选按钮
    QRadioButton *radioRed;
    QRadioButton *radioGreen;
    QRadioButton *radioBlue;
    //声明三个按钮
    QPushButton *btnOK;
    QPushButton *btnCancel;
    QPushButton *btnExit;
    //声明文本框
    QPlainTextEdit *txtEdit;
    //ui创建与初始化
    void iniui();
    //初始化信号与槽的连接
    void iniSignalSlots();
private slots://槽
    //设置下划线
    void do_chUnderLine(bool checked);
    //设置字体加粗
    void do_chBold(bool checked);
    //设置字体倾斜
    void do_chItalic(bool checked);
    //设置字体颜色
    void do_setFontColor();

};

#endif // DIALOG_H
