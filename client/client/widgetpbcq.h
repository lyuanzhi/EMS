#pragma once

#include <QWidget>
#include "Mylabel.h"
#include "dfn.h"

class WidgetPBCQ : public QWidget
{
	Q_OBJECT

public:
	WidgetPBCQ(QWidget* parent = Q_NULLPTR);
	~WidgetPBCQ();

private:
	QTabWidget* tabWidget;
	QWidget* tab;
	QWidget* widgetLeft;
	QLabel* labelPro;
	QComboBox* comboBoxPro;
	QCalendarWidget* calendarWidget;
	QLabel* labelcalendar;
	QPushButton* btnCreate;
	QPushButton* btnRefer;
	QWidget* widgetRight;
	QLabel* labelAttend;
	QPushButton* btnSave;
	QListView* listViewOut;
	QListView* listViewForw;
	QLabel* labelxmjl;
	QLabel* labelxz;
	QLabel* labelkf;
	QLabel* labelgc;
	QLabel* labelwh;
	QLabel* labellh;
	QLabel* labelbj;
	QLabel* labelhq;
	QLabel* labelbad;
	QLabel* labelShow;
	QWidget* tab_2;
	QLabel* labelTitle;
	QLabel* labelLine;
	QLabel* labelProNm;
	QComboBox* comboBoxPro_2;
	QLabel* labelMonth;
	QComboBox* comboBoxMonth;
	QLabel* labelYear;
	QPushButton* btnLoadIn;
	QPushButton* btnSave_2;
	QVector<QWidget*> widget;
	QVector<QScrollArea*> scrollArea;
	QStandardItemModel* qItemModel;
	QTableView* tableView;

private:
	DateClass dateClass;
	Date date;
	QVector<QComboBox*> cbx;
	QVector<QLabel*> lbl;
	QVector<QVector<QCheckBox*>> v_v_checkBox;
	QVector<int> v_flagForCbx;
	QVector<QStandardItem*> v_item;              //用于释放内存
	QVector<QHBoxLayout*> v_layout;              //用于释放内存
	QVector<QWidget*> v_widget;                  //用于释放内存
	QVector<QPushButton*> v_btn;                 //用于释放内存

public slots:
	void onsig_forpbcq(UserInfo&);
	void receiveAttendData(QMap<QString, QVector<QVector<QString>>>);
	void receiveScheduleData(QMap<QString, QVector<QVector<QString>>>);
	void onBtnSaveClicked();
	void onBtnSave_2Clicked();
	void onsectionDoubleClicked(int);
	void onsig_tempCbxIndexChange(int);

signals:
	void sig_sendAttendData(const QString&, int);
	void sig_sendScheduleData(const QString&);
	void sig_save(QVector<QVector<QString>>);
	void sig_save_2(QVector<QVector<QString>>);

};
