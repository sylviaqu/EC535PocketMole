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
static int remainT = 10;
QTimer *run = new QTimer();


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
        mybutton = new QPushButton(this);
        gameover = new QPushButton(this);
        over = new QLabel(this);
        //QTimer *run = new QTimer(this);
        run ->singleShot(1000,this,SLOT(TimeCount()));
        //remainT = run->remainingTime();
        //qDebug() << remainT;
        //setWindowTitle("whack-a-mole     time："+QString::number(remainT)+"        score:"+QString::number(score)+"");
        showButton();
        connect(mybutton, SIGNAL (released()), this, SLOT (handleButton()));
        connect(gameover, SIGNAL (released()), this, SLOT (again()));
        gameover->hide();
        over ->hide();
        connect(run, SIGNAL(timeout()), this, SLOT(TimeCount()));
        //timer->start(10000);

}


void Dialog::showButton(){
    if(end_flag == 0){
        int x = qrand()%9;
        int y = qrand()%9;

    QPixmap mole("/Users/liyihan//Downloads/mole1.png");
    QIcon ButtonIcon(mole);
    //mybutton = new QPushButton(this);
    mybutton -> setIcon(ButtonIcon);
    mybutton -> setIconSize(QSize(100,100));
    mybutton -> setGeometry(position_x[x],position_y[y],100,100);
    QCursor cursor;
    QPixmap pixmap("/Users/liyihan/Downloads/hammer.png");
    QPixmap scaled = pixmap.scaled(QSize(74,62));
    cursor=QCursor(scaled,-1,-1);
    setCursor(cursor);
    score ++;
    //setWindowTitle("whack-a-mole     time：         score:"+QString::number(score)+"");
    }
}
void Dialog::TimeCount(){
        if (remainT>0){
        remainT--;
        run->singleShot(1000,this,SLOT(TimeCount()));
        setWindowTitle("whack-a-mole     time："+QString::number(remainT)+"        score:"+QString::number(score)+"");}
        else{

            QPixmap mole("/Users/liyihan//Downloads/mole.png");
            QIcon ICON(mole);
            gameover -> setIcon(ICON);
            gameover ->setGeometry(200,300,50,50);
            gameover ->show();


            over -> setText("Game Over");
            over ->setGeometry(200,200,100,50);
            over->show();

            end_flag = 1;
        }


}


void Dialog::handleButton(){
    QTimer::singleShot(200,this,SLOT(showButton()));


    //QPixmap after("/Users/liyihan//Downloads/mole.png");
    //QIcon Butt(after);
    //mybutton -> setIcon(Butt);
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
