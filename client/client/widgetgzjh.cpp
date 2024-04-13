#include "widgetgzjh.h"

WidgetGZJH::WidgetGZJH(QWidget *parent)
	: QWidget(parent)
{
	setAttribute(Qt::WA_DeleteOnClose);
	ui.setupUi(this);
}

WidgetGZJH::~WidgetGZJH()
{
}
