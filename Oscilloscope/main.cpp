#include "mainwindow.h"
#include <QApplication>
#include <QScreen>

int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    app.setPalette(Qt::darkCyan);
    const QScreen* screen = QGuiApplication::primaryScreen();
    const QRect screenGeometry = screen->geometry();

    MainWindow window;
    window.resize(screenGeometry.width(), screenGeometry.height());
    window.show();
    return app.exec();
}
