#ifndef COUNTER_H
#define COUNTER_H
#pragma once
#include <QObject>

class Counter : public QObject
{
    Q_OBJECT
private:
    int txt1 = 0;
    int txt2 = 0;
    int txt3 = 0;
public:
    explicit Counter();

public slots:
    void setTxt1(int);
    void setTxt2(int);
    void setTxt3(int);
    void slot1();
    void slot2();
    void slot3();
    void slotLs();
signals:
    void counterChanged(QString);
    void counterLsSignal(QString);
};

#endif // COUNTER_H
