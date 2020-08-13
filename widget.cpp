#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QString>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::modify_money(int money){
    money_status += money;
    ui->lcdNumber->display(money_status);
    changeBtn();
};
void Widget::modify_money_caclulation(){
    int changes=money_status;

    int ch_500 = changes/500;
    changes-= ch_500*500;
    QString msg_500 = "Num of 500 : " + QString::number(ch_500) +"\n";

    int ch_100 = changes/100;
    changes-= ch_100*100;
    QString msg_100 = "Num of 100 : " + QString::number(ch_100) +"\n";

    int ch_50 = changes/50;
    changes-= ch_50*50;
    QString msg_50 = "Num of 50 : " + QString::number(ch_50) +"\n";

    int ch_10 = changes/10;
    changes-= ch_10*10;
    QString msg_10 = "Num of 10 : " + QString::number(ch_10) +"\n";

    QMessageBox::information(this, "Changes", msg_10 + msg_50 + msg_100 + msg_500);
};
void Widget::changeBtn(){
    if(money_status<100){
        ui->descend_100->setEnabled(false);
        ui->descend_150->setEnabled(false);
        ui->descend_200->setEnabled(false);
    }
    else if(money_status<150){
        ui->descend_100->setEnabled(true);
        ui->descend_150->setEnabled(false);
        ui->descend_200->setEnabled(false);
    }
    else if(money_status<200){
        ui->descend_100->setEnabled(true);
        ui->descend_150->setEnabled(true);
        ui->descend_200->setEnabled(false);
    }
    else{
        ui->descend_100->setEnabled(true);
        ui->descend_150->setEnabled(true);
        ui->descend_200->setEnabled(true);
    }

};

void Widget::on_ascend_10_clicked()
{
    modify_money(10);
}

void Widget::on_ascend_50_clicked()
{
    modify_money(50);
}

void Widget::on_ascend_100_clicked()
{
    modify_money(100);
}

void Widget::on_ascend_500_clicked()
{
    modify_money(500);
}

void Widget::on_descend_100_clicked()
{
    modify_money(-100);
}

void Widget::on_descend_150_clicked()
{
    modify_money(-150);
}

void Widget::on_descend_200_clicked()
{
    modify_money(-200);
}

void Widget::on_Reset_btn_clicked()
{
    modify_money_caclulation();
    modify_money(-money_status);
}
