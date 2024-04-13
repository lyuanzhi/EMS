#pragma once

#include <QComboBox>

class MyComboBox : public QComboBox
{
	Q_OBJECT

public:
	MyComboBox(QWidget* parent);
	~MyComboBox();
private:
	void wheelEvent(QWheelEvent* event);
};
