/********************************************************************************
** Form generated from reading UI file 'widgetgzjh.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETGZJH_H
#define UI_WIDGETGZJH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetGZJH
{
public:
    QLabel *label;

    void setupUi(QWidget *WidgetGZJH)
    {
        if (WidgetGZJH->objectName().isEmpty())
            WidgetGZJH->setObjectName(QString::fromUtf8("WidgetGZJH"));
        WidgetGZJH->resize(400, 300);
        label = new QLabel(WidgetGZJH);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 140, 191, 111));

        retranslateUi(WidgetGZJH);

        QMetaObject::connectSlotsByName(WidgetGZJH);
    } // setupUi

    void retranslateUi(QWidget *WidgetGZJH)
    {
        WidgetGZJH->setWindowTitle(QCoreApplication::translate("WidgetGZJH", "WidgetGZJH", nullptr));
        label->setText(QCoreApplication::translate("WidgetGZJH", "\345\267\245\344\275\234\350\256\241\345\210\222", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetGZJH: public Ui_WidgetGZJH {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETGZJH_H
