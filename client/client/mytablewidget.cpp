#include "mytablewidget.h"

MyTableWidget::MyTableWidget(QWidget* parent)
	: QTableWidget(parent)
{
}

MyTableWidget::~MyTableWidget()
{
}

void MyTableWidget::keyPressEvent(QKeyEvent* event) {

	//qDebug("0x%x", event->key());
	int ColCnt = columnCount();
	int RowCnt = rowCount();
	int curRow = currentRow();
	int curColumn = currentColumn();
	switch (event->key())
	{
	case Qt::Key_Return:
	{
		if (curRow == RowCnt - 1 && curColumn == ColCnt - 1)
			break;
		else if (curColumn < ColCnt - 4) {
			++curColumn;
			setCurrentCell(curRow, curColumn);
		}
		else if (curColumn == ColCnt - 4) {
			curColumn = 1;
			++curRow;
			setCurrentCell(curRow, curColumn);
		}
	}
	break;
	default:
		QTableWidget::keyPressEvent(event);
		break;
	}

}