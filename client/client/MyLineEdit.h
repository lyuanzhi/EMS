#pragma once

//���������������
#ifdef WIN32
#pragma  execution_character_set("utf-8")
#endif

#include <QtWidgets>

class MyLineEdit : public QLineEdit
{
	Q_OBJECT

public:
	MyLineEdit(QWidget *parent);
	~MyLineEdit();
	virtual void keyPressEvent(QKeyEvent *event);
};
