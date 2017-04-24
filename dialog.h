#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

class Dialog : public QDialog
{
    Q_OBJECT

private:
   QPushButton *mybutton;

private slots:
   void handleButton();

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
};

#endif // DIALOG_H
