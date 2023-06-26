#include "changelabel.h"
#include "ui_changelabel.h"

Changelabel::Changelabel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Changelabel)
{
    ui->setupUi(this);
    this->setFixedSize(400,300);//设置固定大小
    this->setWindowFlags (Qt::WindowTitleHint | Qt::CustomizeWindowHint);//关闭最大化最小化窗口，还有关闭窗口
    ui->widget->setStyleSheet(QString("background-image:url(:/image/bb.png)"));

    //设置窗口标题
    setWindowTitle("动态壁纸");

}

Changelabel::~Changelabel()
{
    qDebug()<<"执行了";
    delete ui;
}
//实现拖拽功能给路径赋值
void Changelabel::drodfilenamechange(QString f)
{
    Bkstar::bk()->label->getfilename(f);
    if(f.contains(".gif"))
    {
        Bkstar::bk()->label->update();
        Bkstar::bk()->playmovie();
        Bkstar::bk()->show();
    }
    else{

        Bkstar::bk()->label->update();
        Bkstar::bk()->playvedio();
        Bkstar::bk()->show();
    }
}


void Changelabel::on_pushButton_clicked()
{
    filename= QFileDialog::getOpenFileName(this,"选择视频","./");
    if(filename=="")
    {
        return;
    }
    Bkstar::bk()->label->getfilename(filename);
    if(filename.contains(".gif"))
    {
        Bkstar::bk()->label->update();
        Bkstar::bk()->playmovie();
        Bkstar::bk()->show();
    }
    else{

        Bkstar::bk()->label->update();
        Bkstar::bk()->playvedio();
        Bkstar::bk()->show();
    }

}

void Changelabel::on_pushButton_2_clicked()//隐藏窗口
{
    this->hide();
}
