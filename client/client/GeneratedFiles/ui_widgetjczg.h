/********************************************************************************
** Form generated from reading UI file 'widgetjczg.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETJCZG_H
#define UI_WIDGETJCZG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetJCZG
{
public:
    QLabel *label;

    void setupUi(QWidget *WidgetJCZG)
    {
        if (WidgetJCZG->objectName().isEmpty())
            WidgetJCZG->setObjectName(QString::fromUtf8("WidgetJCZG"));
        WidgetJCZG->resize(400, 300);
        label = new QLabel(WidgetJCZG);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 100, 181, 91));

        retranslateUi(WidgetJCZG);

        QMetaObject::connectSlotsByName(WidgetJCZG);
    } // setupUi

    void retranslateUi(QWidget *WidgetJCZG)
    {
        WidgetJCZG->setWindowTitle(QCoreApplication::translate("WidgetJCZG", "WidgetJCZG", nullptr));
        label->setText(QCoreApplication::translate("WidgetJCZG", "\346\243\200\346\237\245\346\225\264\346\224\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetJCZG: public Ui_WidgetJCZG {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETJCZG_H
