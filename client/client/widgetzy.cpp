#include "widgetzy.h"

WidgetZY::WidgetZY(QWidget *parent)
	: QWidget(parent)
{
	setAttribute(Qt::WA_DeleteOnClose);
	this->setObjectName(QString::fromUtf8("WidgetZY"));
	this->resize(1920, 1000);
	QMetaObject::connectSlotsByName(this);
	ui.setupUi(this);

}

WidgetZY::~WidgetZY()
{
}
