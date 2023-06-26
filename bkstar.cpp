#include "bkstar.h"
Bkstar * Bkstar::into=nullptr;
Bkstar::Bkstar(QWidget * parent )
{
   //获取屏幕大小
   x=GetSystemMetrics(SM_CXSCREEN);
   y=GetSystemMetrics(SM_CYSCREEN);
   //创建白班背景
   mwidget=new QWidget;

   label=new Biglabel;
   label->setGeometry(0,0, x,y);

   label2 =new QLabel;
   label->setGeometry(0,0,x,y);


   //创建播放grif类图片
   movie=new QMovie(mwidget);
   movie->setScaledSize(label->size());




   //创建播放视频一大堆操作
   player=new QMediaPlayer(this);
   Playlist=new QMediaPlaylist(this);
   player->setPlaylist(Playlist);
   wall=new QVideoWidget;

   QSize si(label->size());
   wall->resize(si);

}

Bkstar::~Bkstar()
{ 

    mwidget=nullptr;
    into=nullptr;
    label=nullptr;
    label2=nullptr;
    delete label2;
    delete label;
    delete [] mwidget;
    delete into;

}

BOOL CALLBACK EnumWindowsProc(_In_ HWND   hwnd,_In_ LPARAM lParam)//枚举windows窗口的回调函数
{
    HWND Defivew = FindWindowEx(hwnd, 0, L"SHELLDLL_DefView", 0);
        if (Defivew != 0)
        {
            HWND Worke = FindWindowEx(0, hwnd, L"WorkerW", 0);
            ShowWindow(Worke,SW_HIDE);
            return FALSE;
        }
        return true;
}

void Bkstar::chushihua()
{
    //找到桌面窗口，并且向它发送消息(0x52c)使其裂变出WorkerW窗口
    Window=FindWindowEx(NULL,NULL,L"Progman",NULL);
    SendMessage(Window,0X52c,0,0);

    //调用回调函数找到Work窗口并且将其隐藏
    EnumWindows(EnumWindowsProc,0);
    //为我的视频窗口创建父类窗
    label->setParent(mwidget);
    label2->setParent(mwidget);
    //设置播放大小

    if(Window)
    {
        SetParent((HWND)mwidget->winId(),Window);
    }
    mwidget->setWindowFlag(Qt::FramelessWindowHint);


}

void Bkstar::show()
{
    mwidget->showFullScreen();
}

void Bkstar::playvedio()
{
    movie->stop();
    label2->hide();
    wall->setParent(label);
    Playlist->clear();
    QUrl url(label->filename);
    Playlist->addMedia(url);
    Playlist->addMedia(url);

    Playlist->setCurrentIndex(1);
    //循环播放设置
    Playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);

    player->setVideoOutput(wall);//设置父类窗口
    wall->show();
    player->setMuted(true);
    player->play();

}

void Bkstar::closeplay()
{
    player->stop();
    wall->hide();
}

void Bkstar::playmovie()
{
    movie->setFileName(label->filename);
    movie->setSpeed(50);
    label2->setMovie(movie);
    movie->start();
    label2->show();  
}

void Bkstar::closemovie()
{
    movie->stop();
    label2->hide();
}



