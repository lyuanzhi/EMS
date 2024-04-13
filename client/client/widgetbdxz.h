#pragma once

#include <QtWidgets>
#include "ui_widgetbdxz.h"

class WidgetBDXZ : public QWidget
{
	Q_OBJECT

public:
	WidgetBDXZ(QWidget *parent = Q_NULLPTR);
	~WidgetBDXZ();

private:
	Ui::WidgetBDXZ ui;
};
