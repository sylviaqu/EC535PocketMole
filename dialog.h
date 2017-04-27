#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTimer>

class Dialog : public QDialog
{
    Q_OBJECT

private:
   QPushButton *mybutton;
   QTimer *timer;

private slots:
   void handleButton();
   void showButton(QTimer *);
   void TimeCount();

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
};

#endif // DIALOG_H
