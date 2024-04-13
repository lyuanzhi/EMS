/********************************************************************************
** Form generated from reading UI file 'set.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SET_H
#define UI_SET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Set
{
public:

    void setupUi(QWidget *Set)
    {
        if (Set->objectName().isEmpty())
            Set->setObjectName(QString::fromUtf8("Set"));
        Set->resize(851, 567);

        retranslateUi(Set);

        QMetaObject::connectSlotsByName(Set);
    } // setupUi

    void retranslateUi(QWidget *Set)
    {
        Set->setWindowTitle(QCoreApplication::translate("Set", "Set", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Set: public Ui_Set {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SET_H
