#include "biglabel.h"

Biglabel::Biglabel()
{
    painter=new QPainter(this);
    QRect screenRect = desktopWidget->screenGeometry();
    x=screenRect.width();
    y=screenRect.height();


}



void Biglabel::paintEvent(QPaintEvent *)//画图
{
  if(OpenClose::infor()->selectquit==true)
  {
    painter->begin(this);
    im.load(filename);
    painter->drawImage(QRect(0,0,x,y),im,QRect(0,0,im.width(),im.height()));
    painter->end();
  }

}


void Biglabel::getfilename(QString name)
{
    filename=name;
}
