#pragma once

#include <QtWidgets>

class Mylabel : public QLabel
{
	Q_OBJECT

public:
	Mylabel(QWidget* parent);
	~Mylabel();
protected:
	virtual void mousePressEvent(QMouseEvent* event);
	void enterEvent(QEvent* event);
	void leaveEvent(QEvent* event);

signals:
	void clicked();




};
