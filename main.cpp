#include <QtWidgets>
#include <QStandardItemModel>
#include "counter.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QLabel *lbl = new QLabel("");
    QLabel *lblOut = new QLabel("");
    QSpinBox *txt1 = new QSpinBox;
    txt1->setMaximum(20);
    txt1->setMinimum(0);
    QSpinBox *txt2 = new QSpinBox;
    txt2->setMaximum(20);
    txt2->setMinimum(0);
    QSpinBox *txt3 = new QSpinBox;
    txt3->setMaximum(20);
    txt3->setMinimum(0);

    Counter counter;

    QWidget *window = new QWidget;
    QGridLayout *layout = new QGridLayout;


    QPushButton *btn1 = new QPushButton("1");
    QPushButton *btn2 = new QPushButton("2");
    QPushButton *btn3 = new QPushButton("3");
    QPushButton *btnLs = new QPushButton("ls");
    QPushButton *btn5 = new QPushButton("5");
    QPushButton *btn6 = new QPushButton("6");
    QPushButton *btn7 = new QPushButton("7");
    QPushButton *btn8 = new QPushButton("8");
    QPushButton *btn9 = new QPushButton("9");
    QPushButton *btn10 = new QPushButton("10");

    QScrollArea *sAOut = new QScrollArea;
    sAOut->setWidgetResizable(true);
    sAOut->setMaximumSize(1000, 200);
    sAOut->setWidget(lblOut);

    QScrollArea *scrollArea = new QScrollArea;
    scrollArea->setWidgetResizable(true);
    scrollArea->setMaximumSize(1000, 100);
    QWidget *container = new QWidget;
    QVBoxLayout *containerLayout = new QVBoxLayout(container);
    containerLayout->addWidget(btn1);
    containerLayout->addWidget(btn2);
    containerLayout->addWidget(btn3);
    containerLayout->addWidget(btnLs);
    containerLayout->addWidget(btn5);
    containerLayout->addWidget(btn6);
    containerLayout->addWidget(btn7);
    containerLayout->addWidget(btn8);
    containerLayout->addWidget(btn9);
    containerLayout->addWidget(btn10);
    containerLayout->addStretch();
    scrollArea->setWidget(container);

    layout->addWidget(scrollArea, 0, 0, 2, 1);
    layout->addWidget(txt1, 0, 1);
    layout->addWidget(txt2, 0, 2);
    layout->addWidget(txt3, 0, 3);
    layout->addWidget(lbl, 1, 1, 1, 3);
    layout->addWidget(sAOut, 2, 1);
    window->setLayout(layout);
    window->show();

    QObject::connect(btn1, SIGNAL(clicked()),
                     &counter, SLOT(slot1())
                     );

    QObject::connect(btn2, SIGNAL(clicked()),
                     &counter, SLOT(slot2())
                     );

    QObject::connect(btn3, SIGNAL(clicked()),
                     &counter, SLOT(slot3())
                     );

    QObject::connect(btnLs, SIGNAL(clicked()),
                     &counter, SLOT(slotLs())
                     );

    QObject::connect(&counter, SIGNAL(counterLsSignal(QString)),
                     lblOut, SLOT(setText(QString))
                     );

    QObject::connect(&counter, SIGNAL(counterChanged(QString)),
                     lbl, SLOT(setText(QString))
                     );

    QObject::connect(txt1, SIGNAL(valueChanged(int)),
                     &counter, SLOT(setTxt1(int))
                     );

    QObject::connect(txt2, SIGNAL(valueChanged(int)),
                     &counter, SLOT(setTxt2(int))
                     );

    QObject::connect(txt3, SIGNAL(valueChanged(int)),
                     &counter, SLOT(setTxt3(int))
                     );

    return app.exec();
}
