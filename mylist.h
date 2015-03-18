#ifndef MYLIST_H
#define MYLIST_H

#include <QStringList>
#include <QDateTime>

class MyList
{
public:
    MyList(int count);
    ~MyList();
    void initialize();
    void trim1();
    void trim2();
    void trim3();
    void trim4();
    void trim5();
    void trim6();
    void trim7();
    void print();
    void start();
    void end(const QString &name);
private:
    int m_count;
    QStringList m_list;
    QDateTime m_startTime;
};

#endif // MYLIST_H
