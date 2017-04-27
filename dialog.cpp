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

static int score = 0;
static int position_x[9] = {50,200,350,50,200,350,50,200,350};
static int position_y[9] = {50,200,350,50,200,350,50,200,350};
static int end_flag = 0;
static int remainT = 0;



Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
        mybutton = new QPushButton(this);
        QTimer *run = new QTimer(this);
        run ->singleShot(60000,this,SLOT(TimeCount()));
        //remainT = run->remainingTime();
        showButton(run);
        connect(mybutton, SIGNAL (released()), this, SLOT (handleButton()));
        connect(timer, SIGNAL(timeout()), this, SLOT(TimeCount()));
        //timer->start(10000);

}


void Dialog::showButton(QTimer *x){
    if(end_flag == 0){
        int x = qrand()%9;
        int y = qrand()%9;
    QPixmap mole("/Users/liyihan//Downloads/mole.png");
    QIcon ButtonIcon(mole);
    //mybutton = new QPushButton(this);
    mybutton -> setIcon(ButtonIcon);
    mybutton -> setIconSize(QSize(100,100));
    mybutton -> setGeometry(position_x[x],position_y[y],100,100);
    remainT = run->remainingTime();
    score ++;
    setWindowTitle("whack-a-mole     time："+QString::number(remainT)+"          score:"+QString::number(score)+"");
    }
}
void Dialog::TimeCount(){
        qDebug("end!!!!!!");
        end_flag = 1;
        /*static int time = 60;
        time --;
        if(time==0){
        }
        else
        {
        timer->start(1000);
        }
     setWindowTitle("whack-a-mole     time："+QString::number(time)+"        score:");*/
    }

void Dialog::handleButton(){
    QTimer::singleShot(200,this,SLOT(showButton()));


    //QPixmap after("/Users/liyihan//Downloads/mole.png");
    //QIcon Butt(after);
    //mybutton -> setIcon(Butt);
}

Dialog::~Dialog()
{

}
