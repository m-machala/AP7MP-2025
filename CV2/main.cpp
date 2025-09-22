#include <QCoreApplication>
#include <QObject>
#include <QTimer>
#include <iostream>

class Counter : public QObject {
    Q_OBJECT

public:
    Counter(QObject *parent = nullptr) : QObject(parent) {
        counter = 0;
    }

public slots:
    void increment() {
        counter++;
        std::cout << counter << std::endl;

        if(counter >= 20) {
            emit finished();
        }
    }

signals:
    void finished();

private:
    int counter;
};

class Ender : public QObject {
    Q_OBJECT

public:
    Ender(QObject *parent = nullptr) : QObject(parent) {

    }

public slots:
    void exit() {
        QCoreApplication::quit();
    }

};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Counter counter;
    Counter counter2;
    Ender ender;
    QTimer timer;
    QTimer timer2;

    QObject::connect(&timer, &QTimer::timeout, &counter, &Counter::increment);
    QObject::connect(&timer2, &QTimer::timeout, &counter, &Counter::increment);
    QObject::connect(&timer2, &QTimer::timeout, &counter2, &Counter::increment);
    QObject::connect(&counter, &Counter::finished, &ender, &Ender::exit);
    QObject::connect(&counter2, &Counter::finished, &ender, &Ender::exit);

    timer.start(1000);
    timer2.start(900);

    counter.increment();

    return a.exec();
}

#include "main.moc"
