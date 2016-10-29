#include "widget.h"
#include "ui_widget.h"
#include <QLCDNumber>
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    count = 0;
    ui->lcdNumber->display(count);
    QMessageBox::information(nullptr, "Vending Machine", "Put in some money, please.");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::chk_plus()
{
    if (count >= 300)
        ui->pushButton_aro->setEnabled(true);
    if (count >= 100)
        ui->pushButton_tea->setEnabled(true);
    if (count >= 50)
        ui->pushButton_cof->setEnabled(true);
}

void Widget::chk_minus()
{
    if (count < 50)
    {
        ui->pushButton_cof->setDisabled(true);
        ui->pushButton_tea->setDisabled(true);
        ui->pushButton_aro->setDisabled(true);
    }
    else if (count < 100)
    {
        ui->pushButton_tea->setDisabled(true);
        ui->pushButton_aro->setDisabled(true);
    }
    else if (count < 300)
        ui->pushButton_aro->setDisabled(true);
}

void Widget::on_pushButton_50_clicked()
{
    count += 50;
    ui->lcdNumber->display(count);
    chk_plus();
}

void Widget::on_pushButton_100_clicked()
{
    count += 100;
    ui->lcdNumber->display(count);
    chk_plus();
}

void Widget::on_pushButton_500_clicked()
{
    count += 500;
    ui->lcdNumber->display(count);
    chk_plus();
}

void Widget::on_pushButton_cof_clicked()
{
    count -= 50;
    ui->lcdNumber->display(count);
    chk_minus();
}

void Widget::on_pushButton_tea_clicked()
{
    count -= 100;
    ui->lcdNumber->display(count);
    chk_minus();
}

void Widget::on_pushButton_aro_clicked()
{
    count -= 300;
    ui->lcdNumber->display(count);
    chk_minus();
}
