#pragma once

#include <QWidget>
#include "ui_widgetzy.h"

class WidgetZY : public QWidget
{
	Q_OBJECT

public:
	WidgetZY(QWidget *parent = Q_NULLPTR);
	~WidgetZY();

private:
	Ui::WidgetZY ui;
};
