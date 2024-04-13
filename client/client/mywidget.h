#pragma once

#include <QtWidgets>

class MyWidget : public QWidget
{
	Q_OBJECT

public:
	MyWidget(QWidget *parent);
	~MyWidget();

protected:
	virtual void mouseDoubleClickEvent(QMouseEvent* event);


signals:
	void doubleClicked();

};
