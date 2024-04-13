/********************************************************************************
** Form generated from reading UI file 'widgetsfgl.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETSFGL_H
#define UI_WIDGETSFGL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetSFGL
{
public:
    QLabel *label;

    void setupUi(QWidget *WidgetSFGL)
    {
        if (WidgetSFGL->objectName().isEmpty())
            WidgetSFGL->setObjectName(QString::fromUtf8("WidgetSFGL"));
        WidgetSFGL->resize(400, 300);
        label = new QLabel(WidgetSFGL);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 90, 151, 81));

        retranslateUi(WidgetSFGL);

        QMetaObject::connectSlotsByName(WidgetSFGL);
    } // setupUi

    void retranslateUi(QWidget *WidgetSFGL)
    {
        WidgetSFGL->setWindowTitle(QCoreApplication::translate("WidgetSFGL", "WidgetSFGL", nullptr));
        label->setText(QCoreApplication::translate("WidgetSFGL", "\346\224\266\350\264\271\347\256\241\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetSFGL: public Ui_WidgetSFGL {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETSFGL_H
