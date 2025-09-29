#include <QApplication>
#include <QPushButton>

void sayHello() {
    qDebug() << "hello";
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPushButton button("Hello");
    button.setGeometry(100, 100, 300, 200);
    button.show();

    QObject::connect(&button, &QPushButton::clicked, sayHello);

    return a.exec();
}


