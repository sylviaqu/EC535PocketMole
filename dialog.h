#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTimer>
#include <QLabel>

class Dialog : public QDialog
{
    Q_OBJECT

private:
   QPushButton *mybutton;
   QPushButton *gameover;
   QPushButton *pic1;
   QPushButton *pic2;
   QPushButton *pic3;
   QTimer *timer;
   QTimer *miss;
   QLabel *over;

private slots:
   void handleButton();
   void showButton();
   void TimeCount();
   void again();
   void missmole();
   void pict1();
   void pict2();
   void pict3();
   void choosepic();

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
};

#endif // DIALOG_H
