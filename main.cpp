#include "dialog.h"
#include <QApplication>
#include <QStackedLayout>
#include <QListWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    //QWidget *welcomepage = new QWidget;
    //QStackedLayout *stackedLayout = new QStackedLayout;

    //stackedLayout->addWidget(welcomepage);
    w.setFixedSize(500,500);
    w.show();

    return a.exec();
}
