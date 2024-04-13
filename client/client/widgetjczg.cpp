#include "widgetjczg.h"

WidgetJCZG::WidgetJCZG(QWidget *parent)
	: QWidget(parent)
{
	setAttribute(Qt::WA_DeleteOnClose);
	ui.setupUi(this);
}

WidgetJCZG::~WidgetJCZG()
{
}
