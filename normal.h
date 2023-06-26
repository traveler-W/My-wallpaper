#ifndef NORMAL_H
#define NORMAL_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QFileDialog>
#include <QTimer>
#include <QDebug>
#include <QLabel>
#include <QPushButton>
#include "bkstar.h"
namespace Ui {
class normal;
}

class normal : public QWidget
{
    Q_OBJECT

public:
    normal(QWidget *parent = nullptr);
    ~normal();


    QString filename;
    static void dragfilename(QString f);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();


private:
    Ui::normal *ui;

};

#endif // NORMAL_H
