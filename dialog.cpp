#include "dialog.h"
#include <QFile>
#include <QImage>
#include <QPixmap>
#include <QRgb>
#include <QPushButton>
#include <QSize>
#include <Qlabel>
#include <QtGlobal>
#include <Qdebug>
#include <QTimer>
#include <QFont>


static int score = 0;
static int position_x[9] = {50,200,350,50,200,350,50,200,350};
static int position_y[9] = {50,200,350,50,200,350,50,200,350};
static int end_flag = 0;
static int remainT = 10;
static int interval = 1000;
static int hit = 0;

QTimer *run = new QTimer();
QTimer *miss = new QTimer();

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
        mybutton = new QPushButton(this);
        gameover = new QPushButton(this);
        over = new QLabel(this);
        run ->singleShot(1000,this,SLOT(TimeCount()));
        showButton();
        connect(mybutton, SIGNAL (released()), this, SLOT (handleButton()));
        connect(gameover, SIGNAL (released()), this, SLOT (again()));
        gameover->hide();
        over ->hide();
}


void Dialog::showButton(){
    if(end_flag == 0){
        hit = 0;
        int x = qrand()%9;
        int y = qrand()%9;

        QPixmap mole("/Users/xogoss/Desktop/EC535PocketMole/mole1.png");
        QIcon ButtonIcon(mole);
        mybutton -> setIcon(ButtonIcon);
        mybutton -> setIconSize(QSize(100,100));
        mybutton -> setGeometry(position_x[x],position_y[y],100,100);
        QCursor cursor;
        QPixmap pixmap("/Users/xogoss/Desktop/EC535PocketMole/hammer.png");
        QPixmap scaled = pixmap.scaled(QSize(74,62));
        cursor=QCursor(scaled,-1,-1);
        setCursor(cursor);
        //if(hit == 0){
        //    miss->singleShot(1000,this,SLOT(missmole()));
        //}
    }
}
void Dialog::TimeCount(){
    if (remainT>0){
        remainT--;
        run->singleShot(1000,this,SLOT(TimeCount()));
        setWindowTitle("whack-a-mole     time："+QString::number(remainT)+"        score:"+QString::number(score)+"");}
    else{
        QFont font = this->gameover->font();
        font.setPointSize(16);
        gameover ->setText("AGAIN!");
        gameover ->setFont(font);
        gameover ->setGeometry(180,300,150,50);
        gameover ->show();

        QString end = "      Game Over\n \n Your Score is:   ";
        over -> setText(end + QString::number(score));
        over -> setFont(font);
        over -> setAutoFillBackground(true);
        over ->setGeometry(180,200,200,100);
        over->show();

        end_flag = 1;
    }
}


void Dialog::handleButton(){
    //hit = 1;
    score++;
    //interval = interval-1;
    QTimer::singleShot(200,this,SLOT(showButton()));
}

void Dialog::missmole(){
    //score--;
    showButton();
}

void Dialog::again(){
    gameover->hide();
    over ->hide();
    end_flag = 0;
    remainT = 10;
    score = 0;
    run->singleShot(1000,this,SLOT(TimeCount()));
    showButton();
}

Dialog::~Dialog()
{

}
