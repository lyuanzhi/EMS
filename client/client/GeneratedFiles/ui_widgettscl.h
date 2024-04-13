/********************************************************************************
** Form generated from reading UI file 'widgettscl.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETTSCL_H
#define UI_WIDGETTSCL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetTSCL
{
public:

    void setupUi(QWidget *WidgetTSCL)
    {
        if (WidgetTSCL->objectName().isEmpty())
            WidgetTSCL->setObjectName(QString::fromUtf8("WidgetTSCL"));
        WidgetTSCL->resize(400, 300);

        retranslateUi(WidgetTSCL);

        QMetaObject::connectSlotsByName(WidgetTSCL);
    } // setupUi

    void retranslateUi(QWidget *WidgetTSCL)
    {
        WidgetTSCL->setWindowTitle(QCoreApplication::translate("WidgetTSCL", "WidgetTSCL", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetTSCL: public Ui_WidgetTSCL {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETTSCL_H
