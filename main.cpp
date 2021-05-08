#include "mainwindow.h"
#include <QTimer>
#include <QApplication>
#include <QSplashScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap("C:\\Users\\VETAL\\Desktop\\Icons\\374052.svg").scaled(400, 400));
    splash->show();

    MainWindow w;
    QTimer::singleShot(1200, splash, SLOT(close()));
    QTimer::singleShot(1200, &w, SLOT(show()));
    return a.exec();
}
