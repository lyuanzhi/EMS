#pragma once

#include <QWidget>
#include "ui_widgetsfgl.h"

class WidgetSFGL : public QWidget
{
	Q_OBJECT

public:
	WidgetSFGL(QWidget *parent = Q_NULLPTR);
	~WidgetSFGL();

private:
	Ui::WidgetSFGL ui;
};
