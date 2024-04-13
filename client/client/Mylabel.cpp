#include "Mylabel.h"

Mylabel::Mylabel(QWidget* parent)
	: QLabel(parent)
{
}

Mylabel::~Mylabel()
{
}

void Mylabel::mousePressEvent(QMouseEvent* event) {
	if (event->button() == Qt::LeftButton) {
		emit clicked();
	}
	QLabel::mousePressEvent(event);
}

void Mylabel::enterEvent(QEvent* event) {
	if (event->type() == QEvent::Enter) {
		this->setStyleSheet("color:red;");
	}
	QLabel::enterEvent(event);
}

void Mylabel::leaveEvent(QEvent* event) {
	if (event->type() == QEvent::Leave) {
		this->setStyleSheet("color: rgb(90,90,90);");
	}
	QLabel::leaveEvent(event);
}

