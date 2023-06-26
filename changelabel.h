#ifndef CHANGELABEL_H
#define CHANGELABEL_H
#include<stdarg.h>
#include <QWidget>
#include <QPainter>
#include <QPaintEvent>

#include <QFileDialog>
#include "bkstar.h"
namespace Ui {
class Changelabel;
}

class Changelabel : public QWidget
{
    Q_OBJECT

public:
    explicit Changelabel(QWidget *parent = nullptr);
    ~Changelabel();


    //给动态壁纸路径赋值
    static void drodfilenamechange(QString f);


    QString filename;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Changelabel *ui;
};

#endif // CHANGELABEL_H
