#ifndef BIGLABEL_H
#define BIGLABEL_H

#include <QLabel>
#include <QPainter>
#include <QPaintEvent>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include <QUrl>
#include <QImage>
#include "openclose.h"
#include <QDesktopWidget>
#include <QApplication>
class Biglabel:public QLabel
{
public:
    Biglabel();
    //定义画家
    QPainter *painter;
    void paintEvent(QPaintEvent *);

    //定义、获取文件名称
    QString filename;
    void getfilename(QString name);

    QImage im;
    ~Biglabel()
    {
        painter=nullptr;
        delete [] painter;
        delete [] desktopWidget;
    }
    //获取屏幕大小
    QDesktopWidget *desktopWidget = QApplication::desktop();
    int x;
    int y;

};

#endif // BIGLABEL_H
