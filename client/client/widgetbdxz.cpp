#include "widgetbdxz.h"

WidgetBDXZ::WidgetBDXZ(QWidget *parent)
	: QWidget(parent)
{
	setWindowModality(Qt::ApplicationModal);
	setAttribute(Qt::WA_DeleteOnClose);
	ui.setupUi(this);
	this->resize(600, 300);
	this->setWindowIcon(QPixmap("Resources/logo.png"));
}

WidgetBDXZ::~WidgetBDXZ()
{
}
