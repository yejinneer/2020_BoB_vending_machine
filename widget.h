#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    int money_status = 0;
    void modify_money(int money);
    void modify_money_caclulation();
    void changeBtn();


private slots:
    void on_ascend_10_clicked();

    void on_ascend_50_clicked();

    void on_ascend_100_clicked();

    void on_ascend_500_clicked();

    void on_descend_100_clicked();

    void on_descend_150_clicked();

    void on_descend_200_clicked();

    void on_Reset_btn_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
