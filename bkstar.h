#ifndef BKSTAR_H
#define BKSTAR_H

#include <QObject>
#include <QLabel>
#include <qt_windows.h>
#include <QMovie>
#include<windows.h>
#include "biglabel.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include <QUrl>
#include <QDebug>
#include <QCursor>
class Bkstar : public QObject
{
static Bkstar*into;
public:
   Bkstar(QWidget *parent = nullptr);
   ~Bkstar();
   static Bkstar* bk()
    {
       if(into==nullptr)
       {
           return into=new Bkstar();
       }
       return into;
    }
    void chushihua();
    void show();

    QWidget *mwidget;
    Biglabel *label;
    HWND Window;
    QLabel *label2;

    //播放视频类
    QMediaPlayer *player;
    QMediaPlaylist*Playlist;
    QVideoWidget *wall;
    void starplay();
    void playvedio();
    void closeplay();
    void playmovie();
    void closemovie();

    //播放grif图片
    QMovie *movie;
    int x;
    int y;


};

#endif // BKSTAR_H
