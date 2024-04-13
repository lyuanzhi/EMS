/********************************************************************************
** Form generated from reading UI file 'widgetzy.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETZY_H
#define UI_WIDGETZY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetZY
{
public:
    QLabel *label;

    void setupUi(QWidget *WidgetZY)
    {
        if (WidgetZY->objectName().isEmpty())
            WidgetZY->setObjectName(QString::fromUtf8("WidgetZY"));
        WidgetZY->resize(1920, 1000);
        label = new QLabel(WidgetZY);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 1920, 1000));
        label->setPixmap(QPixmap(QString::fromUtf8("Resources/\344\270\273\351\241\265.jpg")));

        retranslateUi(WidgetZY);

        QMetaObject::connectSlotsByName(WidgetZY);
    } // setupUi

    void retranslateUi(QWidget *WidgetZY)
    {
        WidgetZY->setWindowTitle(QCoreApplication::translate("WidgetZY", "WidgetZY", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WidgetZY: public Ui_WidgetZY {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETZY_H
