#include "MyLineEdit.h"

MyLineEdit::MyLineEdit(QWidget *parent)
	: QLineEdit(parent)
{
}

MyLineEdit::~MyLineEdit()
{
}

void MyLineEdit::keyPressEvent(QKeyEvent* event) {
	//�������ⰴ����/����,����.����#����\����*����'����"����:��
	//qDebug("0x%x", event->key());
	 switch (event->key())
	{
	case Qt::Key_Slash:
	case Qt::Key_Apostrophe:
	case Qt::Key_QuoteDbl:
	case Qt::Key_Asterisk:
	case Qt::Key_Comma:
	case Qt::Key_Period:
	case Qt::Key_NumberSign:
	case Qt::Key_Backslash:
	case Qt::Key_Colon:
		QToolTip::showText(this->mapToGlobal(this->pos()), "����ʹ�������ַ���", this);
		break;
	default:
		QLineEdit::keyPressEvent(event);
		break;
	}
}
