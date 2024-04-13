/********************************************************************************
** Form generated from reading UI file 'tcpconnect.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPCONNECT_H
#define UI_TCPCONNECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TcpConnect
{
public:

    void setupUi(QWidget *TcpConnect)
    {
        if (TcpConnect->objectName().isEmpty())
            TcpConnect->setObjectName(QString::fromUtf8("TcpConnect"));
        TcpConnect->resize(800, 600);

        retranslateUi(TcpConnect);

        QMetaObject::connectSlotsByName(TcpConnect);
    } // setupUi

    void retranslateUi(QWidget *TcpConnect)
    {
        TcpConnect->setWindowTitle(QApplication::translate("TcpConnect", "TcpConnect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TcpConnect: public Ui_TcpConnect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPCONNECT_H
