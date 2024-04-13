#include "mywidget.h"

MyWidget::MyWidget(QWidget *parent)
	: QWidget(parent)
{
}

MyWidget::~MyWidget()
{
}

void MyWidget::mouseDoubleClickEvent(QMouseEvent* event) {

	if (event->button() == Qt::LeftButton) {
		emit doubleClicked();
	}
	QWidget::mouseDoubleClickEvent(event);

}
