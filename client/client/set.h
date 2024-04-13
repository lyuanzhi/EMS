#pragma once

#include <QtWidgets>
#include "ui_set.h"

class Set : public QWidget
{
	Q_OBJECT

public:
	Set(QWidget *parent = Q_NULLPTR);
	~Set();

private:
	Ui::Set ui;
	QScrollArea* m_ScrollArea;
};
