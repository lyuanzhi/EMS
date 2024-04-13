#pragma once

#include <QTableWidget>
#include <QtWidgets>

class MyTableWidget : public QTableWidget
{
	Q_OBJECT

public:
	MyTableWidget(QWidget* parent);
	~MyTableWidget();

protected:
	 void keyPressEvent(QKeyEvent* event);

};
