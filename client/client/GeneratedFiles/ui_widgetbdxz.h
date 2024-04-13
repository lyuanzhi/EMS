/********************************************************************************
** Form generated from reading UI file 'widgetbdxz.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETBDXZ_H
#define UI_WIDGETBDXZ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetBDXZ
{
public:
    QLabel *label;

    void setupUi(QWidget *WidgetBDXZ)
    {
        if (WidgetBDXZ->objectName().isEmpty())
            WidgetBDXZ->setObjectName(QString::fromUtf8("WidgetBDXZ"));
        WidgetBDXZ->resize(400, 300);
        label = new QLabel(WidgetBDXZ);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, 130, 171, 81));

        retranslateUi(WidgetBDXZ);

        QMetaObject::connectSlotsByName(WidgetBDXZ);
    } // setupUi

    void retranslateUi(QWidget *WidgetBDXZ)
    {
        WidgetBDXZ->setWindowTitle(QCoreApplication::translate("WidgetBDXZ", "WidgetBDXZ", nullptr));
        label->setText(QCoreApplication::translate("WidgetBDXZ", "\350\241\250\345\215\225\344\270\213\350\275\275", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetBDXZ: public Ui_WidgetBDXZ {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETBDXZ_H
