#include "mylist.h"
#include <QDebug>
#include <QtConcurrent>
#include <algorithm>
#include <QThread>

// 繰り返し処理が時間かかかることをエミュレートする場合は、以下のdefineを有効にする
//#define EMULATE_TIME_CONSUMING

#ifdef EMULATE_TIME_CONSUMING
#define SLEEP QThread::usleep(100);
#else
#define SLEEP
#endif

MyList::MyList(int count): m_count(count)
{

}

MyList::~MyList()
{

}

void MyList::initialize()
{
    m_list.clear();
    for (int i = 0; i < m_count; i++) {
        m_list.append(QString("   %1   ").arg(i));
    }
}

/*
 * Qtのforeach版(constになってしまうため、trimできない)
 */
void MyList::trim1()
{
    start();
    foreach (const QString &data, m_list) {
        (void) data.trimmed();
        SLEEP
    }
    end("trim1");
}

/*
 * Qtのiterator版
 */
void MyList::trim2()
{
    start();
    for (QStringList::iterator it = m_list.begin(); it != m_list.end(); it++) {
        *it = it->trimmed();
        SLEEP
    }
    end("trim2");
}

/*
 * Qtのjava-style iterator版
 */
void MyList::trim3()
{
    start();
    for (QMutableStringListIterator it(m_list); it.hasNext();) {
        QString &data = it.next();
        data = data.trimmed();
        SLEEP
    }
    end("trim3");
}

/*
 * index access版
 */
void MyList::trim4()
{
    start();
    for (int i = 0; i < m_list.size(); i++) {
        QString &data = m_list[i];
        data = data.trimmed();
        SLEEP
    }
    end("trim4");
}

/*
 * QtConcurrent::blockingMap版
 */
void MyList::trim5()
{
    start();
    //qDebug() << QThread::currentThreadId();
    QtConcurrent::blockingMap(m_list, [](QString &data) {
        //qDebug() << QThread::currentThreadId() << ":" << data;
        data = data.trimmed();
        SLEEP
    });
    end("trim5");
}

/*
 * STLのfor_each版
 */
void MyList::trim6()
{
    start();
    std::for_each(m_list.begin(), m_list.end(), [](QString &data) {
        data = data.trimmed();
        SLEEP
    });
    end("trim6");
}

/*
 * c++11のfor版
 */
void MyList::trim7()
{
    start();
    for (QString &data : m_list) {
        data = data.trimmed();
        SLEEP
    }
    end("trim7");
}

void MyList::print()
{
    foreach (const QString &data, m_list) {
        qDebug() << data;
    }
}

void MyList::start()
{
    m_startTime = QDateTime::currentDateTime();
}

void MyList::end(const QString &name)
{
    qDebug() << qPrintable(name) << ":" << m_startTime.msecsTo(QDateTime::currentDateTime());
}

