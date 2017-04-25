#include "dialog.h"
#include <QFile>
#include <QImage>
#include <QPixmap>
#include <QRgb>
#include <QPushButton>
#include <QSize>
#include <QTimer>
#include <QLabel>
#include <QtGlobal>
#include <QDebug>


static int score = 0;
static int position_x[9] = {50,200,350,50,200,350,50,200,350};
static int position_y[9] = {50,50,50,200,200,200,350,350,350};

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
     //QLabel *scorelabel = new QLabel(this);
     mybutton = new QPushButton(this);
     //mychange = new QPushButton(this);

     //mychange->setGeometry(10,10,100,50);
     //connect(mychange, SIGNAL (released()), this, SLOT (show_b()));
     showButton();

     //QTimer *mytimer1 = new QTimer(this);
     //QObject::connect(mytimer1, SIGNAL(timeout()), this, SLOT(showButton()));
     //mytimer1 -> start(3000);

}

void Dialog::showButton(){
    //int i;

    //for(i = 0; i<16; i++){
    int x = qrand()%9;
    int y = qrand()%9;
    //int x=200;
    //int y=50;

    QPixmap mole("/Users/xogoss/Desktop/535pro/pmole/mole.png");
    QIcon ButtonIcon(mole);
    mybutton -> setIcon(ButtonIcon);
    mybutton -> setIconSize(QSize(100,90));
    mybutton->setGeometry(position_x[x],position_y[y],100,100);
    //}
    connect(mybutton, SIGNAL (released()), this, SLOT (handleButton()));

}


void Dialog::handleButton(){
    QPixmap after("/Users/xogoss/Desktop/535pro/pmole/afterduang.png");
    QIcon Butt(after);
    mybutton -> setIcon(Butt);
    score ++;
    qDebug() << score;
    QTimer::singleShot(1000, this, SLOT(showButton()));
    //QTimer *mytimer = new QTimer(this);
    //QObject::connect(mytimer, SIGNAL(timeout()), this, SLOT(showButton()));
    //mytimer -> start(1000);
    //setVisible(true);
    //showButton();
    //QLabel *label = new QLabel(this);
    //label->setText("wth");
    //label->showFullScreen();
}

Dialog::~Dialog()
{

}
