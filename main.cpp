#include <QCoreApplication>
#include "mylist.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyList mylist(100000);

    mylist.initialize();
    mylist.trim1();
    mylist.initialize();
    mylist.trim2();
    mylist.initialize();
    mylist.trim3();
    mylist.initialize();
    mylist.trim4();
    mylist.initialize();
    mylist.trim5();
    mylist.initialize();
    mylist.trim6();
    mylist.initialize();
    mylist.trim7();

    return 0;//a.exec();
}
