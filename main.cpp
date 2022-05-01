#include <QCoreApplication>
#include <QDebug>
class EMPTY{};//1 = sizeof(EMPTY())
struct BASE{
    virtual void first(){qDebug()<<"BASE::first";};
    virtual void second(){qDebug()<<"BASE::second";};
    virtual void third(){qDebug()<<"BASE::third";};
};
struct DERIVE1 : public BASE{
    virtual void first1(){qDebug()<<"DERIVE1::first1";};
    virtual void second1(){qDebug()<<"DERIVE1::second1";};
    virtual void third1(){qDebug()<<"DERIVE1::third1";};
};
struct DERIVE2 : public BASE{
    virtual void first(){qDebug()<<"DERIVE2::first";};
    virtual void second2(){qDebug()<<"DERIVE2::second2";};
    virtual void third2(){qDebug()<<"DERIVE2::third2";};
};
struct DERIVE3 : public DERIVE2{
    virtual void first(){qDebug()<<"DERIVE3::first";};
    virtual void second2(){qDebug()<<"DERIVE3::second2";};
    virtual void third3(){qDebug()<<"DERIVE3::third2";};
};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    BASE* pb = new BASE();
    BASE* pb1 = new DERIVE1();
    BASE* pb2 = new DERIVE2();
    BASE* pb3 = new DERIVE3();
    qDebug()<<"hello world"<<Qt::endl;
    qDebug()<<"hello world"<<Qt::endl;

    return a.exec();
}
