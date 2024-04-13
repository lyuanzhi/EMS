#include "widgetsfgl.h"

WidgetSFGL::WidgetSFGL(QWidget *parent)
	: QWidget(parent)
{
	setAttribute(Qt::WA_DeleteOnClose);
	ui.setupUi(this);
}

WidgetSFGL::~WidgetSFGL()
{
}
