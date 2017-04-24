#include "dialog.h"
#include <QFile>
#include <QImage>
#include <QPixmap>
#include <QRgb>
#include <QPushButton>
#include <QSize>
#include <QTimer>
#include <QLabel>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    QPixmap mole("/Users/xogoss/Desktop/535pro/pmole/mole.png");
    QIcon ButtonIcon(mole);
    mybutton = new QPushButton(this);
    mybutton -> setIcon(ButtonIcon);
    mybutton -> setIconSize(QSize(100,90));

    mybutton -> setIcon(ButtonIcon);
    mybutton -> setIconSize(QSize(100,90));
    //mybutton -> setGeometry(QRect(QPoint(200,100),QSize(100,100)));
    mybutton->setGeometry(100,10,100,100);
    connect(mybutton, SIGNAL (released()), this, SLOT (handleButton()));
    QTimer *mytimer1 = new QTimer(this);
    QObject::connect(mytimer1, SIGNAL(timeout()), mybutton, SLOT(hide()));
    mytimer1 -> start(3000);


}


void Dialog::handleButton(){
    QPixmap after("/Users/xogoss/Desktop/535pro/pmole/afterduang.png");
    QIcon Butt(after);
    mybutton -> setIcon(Butt);
    QTimer *mytimer = new QTimer(this);
    QObject::connect(mytimer, SIGNAL(timeout()), mybutton, SLOT(hide()));
    mytimer -> start(1000);
    //QLabel *label = new QLabel(this);
    //label->setText("wth");
    //label->showFullScreen();
}

Dialog::~Dialog()
{

}
