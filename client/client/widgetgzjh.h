#pragma once

#include <QWidget>
#include "ui_widgetgzjh.h"

class WidgetGZJH : public QWidget
{
	Q_OBJECT

public:
	WidgetGZJH(QWidget *parent = Q_NULLPTR);
	~WidgetGZJH();

private:
	Ui::WidgetGZJH ui;
};
