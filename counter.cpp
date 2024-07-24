#include "counter.h"
#include <QProcess>
Counter::Counter() : QObject()
{}

void Counter::slot1(){
    emit counterChanged("button 1 pressed: " + QString::number(txt1));
}

void Counter::slot2(){
    emit counterChanged("button 2 pressed: " + QString::number(txt2));
}

void Counter::slot3(){
    emit counterChanged("button 3 pressed: " +  QString::number(txt3));
}

void Counter::slotLs(){
    const int NO_TIMEOUT = -1;

    QProcess proc;

    proc.start("/home/markelov/myfile", QStringList() << "");
    proc.waitForFinished(NO_TIMEOUT);

    QString proc_stdout = proc.readAllStandardOutput();
    QString proc_stderr = proc.readAllStandardError();
    emit counterLsSignal(proc_stdout);
}

void Counter::setTxt1(int str){
    txt1 = str;
}

void Counter::setTxt2(int str){
    txt2 = str;
}

void Counter::setTxt3(int str){
    txt3 = str;
}
