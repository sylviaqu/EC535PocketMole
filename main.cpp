#include "dialog.h"
#include <QApplication>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.setWindowTitle("whack-a-mole     time：60       score：0");
    w.setFixedSize(500,500);
    w.show();

    return a.exec();
}
