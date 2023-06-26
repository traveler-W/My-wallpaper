#include "normal.h"
#include "ui_normal.h"

normal::normal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::normal)
{
    ui->setupUi(this);
    //设置窗口固定大小
    this->setFixedSize(400,300);
//    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setWindowFlags (Qt::WindowTitleHint |Qt::CustomizeWindowHint);
    ui->widget->setStyleSheet(QString("background-image:url(:/image/shan.jpg)"));
//    this->setWindowFlag(Qt::CustomizeWindowHint);

    //设置窗口标题
    setWindowTitle("静态壁纸");
}

normal::~normal()
{
    qDebug()<<"释放函数";
    Bkstar::bk()->~Bkstar();
    delete ui;
}

//对于拖拽功能实现路径赋值
void normal::dragfilename(QString f)
{

    Bkstar::bk()->label->getfilename(f);
    Bkstar::bk()->label->update();
    Bkstar::bk()->closeplay();
    Bkstar::bk()->closemovie();
    Bkstar::bk()->show();
}


void normal::on_pushButton_2_clicked()
{

    this->hide();
}

void normal::on_pushButton_clicked()//选择壁纸
{

    filename=QFileDialog::getOpenFileName(this,"选择壁纸","./");
    if(filename=="")
    {
        return;
    }
    Bkstar::bk()->label->getfilename(filename);
    Bkstar::bk()->closeplay();
    Bkstar::bk()->closemovie();
    Bkstar::bk()->show();
}

