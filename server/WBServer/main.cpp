#include "tcpconnect.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    a.setFont(QFont("SimSun", 9));
//    QTextCodec *codec = QTextCodec::codecForName("GBK");
//    qDebug() << codec;
//    QTextCodec::setCodecForLocale(codec);
    TcpConnect w;
    w.show();
    return a.exec();
}
