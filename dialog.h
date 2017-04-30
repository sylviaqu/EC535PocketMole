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
   QTimer *timer;
   QTimer *miss;
   QLabel *over;
private slots:
   void handleButton();
   void showButton();
   void TimeCount();
   void again();
   void missmole();
public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
};

#endif // DIALOG_H
