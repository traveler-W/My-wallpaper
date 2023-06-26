#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置无标题栏，窗口背景透明
    setWindowFlag(Qt::FramelessWindowHint);
    setWindowIcon(QIcon(":/image/Mr.ico"));
    setAttribute(Qt::WA_TranslucentBackground);
    ui->pushButton_3->setAttribute(Qt::WA_TranslucentBackground);

    //设置可拖拽功能
    this->setAcceptDrops(true);

//    ui->widget->setStyleSheet(QString("background-image:url(://g.png);"));
    //设置鼠标变化功能
    QPixmap mycursepix(":/image/magic.png");
    QPixmap ii= mycursepix.scaled(65,65);
    QCursor mycurse(ii,0,-1);

    setCursor(mycurse);
    //设置背景为grif图片
    ui->label->setAttribute(Qt::WA_TranslucentBackground);//设置lable为透明背景
    movie=new QMovie(this);
    movie->setFileName(":/image/Scene1.gif");

    movie->setScaledSize(QSize(430,555));//设置播放大小
    ui->label->setMovie(movie);
    movie->setCacheMode(QMovie::CacheAll);
    movie->setSpeed(55);//设置grif图片的播放速度，这个函数是百分制的，55就是55%的播放速度，200就是两倍的播放速度
    movie->start();//开始播放

    //静态壁纸窗口创建
    norm=new normal;
    //动态壁纸窗口创建
    change=new Changelabel;

    //初始化播放界面
    Bkstar::bk()->chushihua();
    //越界处理
    movebsidetime=new QTimer(this);
    movebsidetime->start(50);

    fontM =new QTimer(this);
    fontM->start(50);


    //信号连接
    connect(movebsidetime,&QTimer::timeout,this,&Widget::movebeside);
    connect(fontM,&QTimer::timeout,this,&Widget::fontmove);

}

Widget::~Widget()
{
    qDebug()<<"释放";
    change->~Changelabel();
    change=nullptr;
    delete change;
    norm->~normal();
    norm=nullptr;
    OpenClose::infor()->~OpenClose();
    delete norm;
    delete ui;
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{

    QPoint movepos=event->pos()-nowpos;
    this->move(this->pos()+movepos);
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    nowpos=event->pos();
}

void Widget::movebeside()//判断主窗口是否越界
{
    y=this->pos().y();
    x=this->pos().x();
    if(y>=534)
    {
        this->move(this->pos().x(),534);
    }
    if(y<=0)
    {
        this->move(this->pos().x(),0);
    }
    if(x<=0)
    {
        this->move(0,this->pos().y());
    }
    if(x>=1621)
    {
        this->move(1621,this->pos().y());
    }

}

void Widget::fontmove()//控制窗口向前移动
{
    if(this->pos().y()==534)
    {
        this->move(this->pos().x()-1,534);
        ui->pushButton->hide();
        ui->pushButton_2->hide();
        ui->pushButton_3->hide();
        ui->pushButton_4->hide();
        ui->pushButton_5->hide();
    }else{
        ui->pushButton->show();
        ui->pushButton_2->show();
        ui->pushButton_3->show();
        ui->pushButton_4->show();
        ui->pushButton_5->show();
    }
}


void Widget::on_pushButton_3_clicked()//退出应用程序
{
    app->quit();
}

void Widget::on_pushButton_clicked()//静态壁纸
{

    OpenClose::infor()->selectquit=true;

    norm->show();

}

void Widget::on_pushButton_2_clicked()//动态壁纸
{

    OpenClose::infor()->selectquit=false;

    change->show();
}

void Widget::on_pushButton_4_clicked()//撤销壁纸操作
{
    Bkstar::bk()->mwidget->hide();

}

void Widget::on_pushButton_5_clicked()
{
    this->showMinimized();
}

//拖拽处理获取文件并判断
void Widget::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->hasUrls())
    {
        movie->setPaused(true);
        event->acceptProposedAction();
    }
    else
    {
        event->ignore();
    }
}
//拖拽出去处理
void Widget::dragLeaveEvent(QDragLeaveEvent *event)
{
    movie->start();
}
//拖拽处理
void Widget::dropEvent(QDropEvent *event)
{
    QList<QUrl> filenames =event->mimeData()->urls();
    if(filenames.empty())
    {
        return;
    }
    movie->start();
    QString filename = filenames.first().toLocalFile();
    if(filename.contains(".png")||filename.contains(".jpg"))
    {
        OpenClose::infor()->selectquit=true;
        normal::dragfilename(filename);

    }else
    {
        OpenClose::infor()->selectquit=false;
        Changelabel::drodfilenamechange(filename);
    }

}


