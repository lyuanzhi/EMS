#pragma once

#include <QWidget>
#include "Mylabel.h"
#include "mytablewidget.h"
#include "MyLineEdit.h"
#include "dfn.h"
#include <libxl.h>
#include <QtXlsx/xlsxdocument.h>
#include <QPrinter>
#include <QPrintDialog>
#include <QPrintPreviewDialog>

using namespace libxl;

class WidgetWZGL : public QWidget
{
	Q_OBJECT

public:
	WidgetWZGL(QWidget* parent = Q_NULLPTR);
	~WidgetWZGL();

private:
	QTabWidget* tabWidget;
	QWidget* tab;
	QWidget* tab_2;
	QWidget* tab_3;
	QWidget* tab_4;
	QWidget* tab_5;
	QWidget* widgetLeft;
	QWidget* widgetRight;
	QComboBox* comboBoxPro;
	QPushButton* btnCreate;
	QPushButton* btnImport;
	QLabel* labelSearch;
	QLabel* labelTime;
	QLineEdit* lineYear;
	QLabel* labelYear;
	QComboBox* comboBoxMonth;
	QLabel* labelState;
	QComboBox* comboBoxState;
	QPushButton* btnSearch;
	QTableView* tableView;
	QLabel* labelTitle;
	QLabel* labelPro_2;
	QLineEdit* linePro;
	QLabel* labelApplyDate;
	QCalendarWidget* calendarWidget;
	QDateEdit* dateEditApplyDate;
	QLabel* labelApplyPerson;
	QLineEdit* lineApplyPerson;
	QPushButton* btnDelete;
	QPushButton* btnClose;
	QPushButton* btnSave;
	QPushButton* btnSubmit;
	QPushButton* btnPrint;
	QLabel* labelRemind;
	MyTableWidget* tableWidget;//表格
	QLabel* label[3];
	Mylabel* myLabel[3];
	MyLineEdit* lineEditPwd[3];
	QPushButton* btnPass[3];
	QPushButton* btnReject[3];
	QPushButton* btnUndo[3];
	QLabel* labelName[3];
	QPushButton* btnAddRow;
	QWidget* widgetForBtnReject;
	QWidget* widgetForCostAndDate;

private:
	DateClass dateClass;
	Date date;
	bool tableIsOpen; //false为关闭，true为打开
	int state;
	UserInfo userInfo;
	int flagForCheck[3];
	QStandardItemModel* qItemModel_2;
	QVector<QStandardItem*> v_item;              //用于释放内存
	QVector<QPushButton*> v_btnOpen;             //用于释放内存
	void setTableViewColor(QPushButton*, int, int, int, int, int);
	int currentRowIndex = -1;
	QString currentID = "";
	QVector<QVector<QString>> v_v_forOpen_data;

signals:
	void sig_tableIsNotOpen();
	void sig_myLabelClicked(int);
	void sig_forSubmit(QVector<QVector<QString>>);
	void sig_sendPurchaseData(const QString&, int, int, int);
	void sig_btnOpenClicked(const QString&);
	void sig_sendStateData(const QString&, int, int, const QString&, QVector<QString>);
	void sig_CreateWCostAndDate();
	void sig_forCostAndDate(QVector<QString>);
	void sig_forDelete(const QString&);

public slots:
	void onsig_forwzgl(UserInfo&);
	void onBtnCreateClicked();
	void onBtnImportClicked();
	void onBtnCloseClicked();
	void onBtnDeleteClicked();
	void onBtnSaveClicked();
	void onBtnSubmitClicked();
	void onBtnPrintClicked();
	void onsig_myLabelClicked(int);
	void printPreviewSlot(QPrinter*);
	void receivePurchaseData(QVector<QVector<QString>>);
	void oncurrentTextChanged(const QString&);
	void receiveOpenDate(QVector<QVector<QString>>);
	void onsig_forSuccessfulSubmit();
	void onsig_forState();
	void onDoubleClicked(int, int);
	void onDoubleClicked(int);
	void onsig_CreateWCostAndDate();
	void oncellDoubleClicked(int, int);
	void onsig_forSuccessfulDelete();

};
