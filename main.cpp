#include "database.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    database w;
    w.show();

    return a.exec();


}


