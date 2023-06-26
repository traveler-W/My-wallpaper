#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMovie>
#include <qt_windows.h>
#include <QLabel>
#include <QProcess>
#include <QApplication>
#include <QDebug>
#include <QMouseEvent>
#include <QTimer>
#include <normal.h>
#include <QLabel>
#include "bkstar.h"
#include "normal.h"
#include "changelabel.h"
#include "openclose.h"
#include <QCursor>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    //声明拖拽事件函数
    void dropEvent(QDropEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dragLeaveEvent(QDragLeaveEvent *event);
    void movebeside();
    void fontmove();

    normal * norm;
    Changelabel *change;
    //添加界面背景
    QMovie *movie;
private:
    Ui::Widget *ui;

    QApplication *app;
    QPoint nowpos;
    int y,x;//当前位置x与 y
    //定时器
    QTimer*movebsidetime;
    QTimer *getfilename;
    QTimer *fontM;

    QString namefile;
public :signals:


private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();


};
#endif // WIDGET_H
