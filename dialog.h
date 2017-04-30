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
   QLabel *over;
private slots:
   void handleButton();
   void showButton();
   void TimeCount();
   void again();
public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
};

#endif // DIALOG_H
