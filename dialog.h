#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTimer>

class Dialog : public QDialog
{
    Q_OBJECT

private:
   QPushButton *mybutton;
   QPushButton *mychange;
   //QTimer * posTimer;

private slots:
   void handleButton();
   void showButton();


public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
};

#endif // DIALOG_H
