#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void chk_plus();
    void chk_minus();

private slots:
    void on_pushButton_50_clicked();

    void on_pushButton_100_clicked();

    void on_pushButton_500_clicked();

    void on_pushButton_cof_clicked();

    void on_pushButton_tea_clicked();

    void on_pushButton_aro_clicked();

private:
    Ui::Widget *ui;
    int count;
};

#endif // WIDGET_H
