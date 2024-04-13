#include "mycombobox.h"

MyComboBox::MyComboBox(QWidget *parent)
	: QComboBox(parent)
{
}

MyComboBox::~MyComboBox()
{
}

void MyComboBox::wheelEvent(QWheelEvent* event)
{
	return;
}
