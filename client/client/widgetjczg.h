#pragma once

#include <QWidget>
#include "ui_widgetjczg.h"

class WidgetJCZG : public QWidget
{
	Q_OBJECT

public:
	WidgetJCZG(QWidget *parent = Q_NULLPTR);
	~WidgetJCZG();

private:
	Ui::WidgetJCZG ui;
};
