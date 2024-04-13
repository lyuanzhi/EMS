#pragma once

#include <QWidget>
#include <QComboBox>
#include <QStandardItemModel>
#include <QLabel>
#include <QPushButton>
#include <QStackedWidget>
#include <QDebug>
#include <QScrollArea>
#include <QScrollBar>
#include <QFormLayout>
#include <QLineEdit>
#include <QDateEdit>
#include <QCalendarWidget>
#include <QToolButton>
#include <QMap>
#include <QTextEdit>
#include <QCheckBox>
#include <QTableView>
#include <QHeaderView>
#include <QMenu>
#include <QFileDialog>
#include "dfn.h"
#include "mycombobox.h"
#include "Mylabel.h"
#include "MyLineEdit.h"

union Write_entry
{
	QLineEdit* line_entry;
	MyComboBox* cbx_entry;
};

class WidgetYGGL : public QWidget
{
	Q_OBJECT

public:
	WidgetYGGL(QWidget* parent = Q_NULLPTR);
	~WidgetYGGL();

private:
	QWidget* widgetLeft;
	QComboBox* comboBoxPro;
	QLabel* labelSelect;
	QLabel* labelHR;
	QPushButton* btnSelect[3]; //档案查询  保险查询  统计报表
	QPushButton* btnHR[3];     //入职办理  人事调动  离职办理
	QTabWidget* tabWidget;
	QWidget* tab;
	QWidget* tab2;
	QStackedWidget* stackedWidget;
	QWidget* page_0;
	QWidget* page_1;
	QWidget* page_2;
	QWidget* page_3;
	QWidget* page_4;
	QWidget* page_5;
	QScrollArea* scrollArea_0;
	QScrollArea* scrollArea_1;
	QScrollArea* scrollArea_2;
	QScrollArea* scrollArea_3;
	QScrollArea* scrollArea_4;
	QScrollArea* scrollArea_5;
	//档案查询界面
	QLabel* label_0;
	QComboBox* cbx1_da;
	QComboBox* cbx2_da;
	MyLineEdit* line3_da;
	QPushButton* btn4_da;
	QTableView* tableView_da;
	QStandardItemModel* qItemModel_da;
	QLineEdit* line_1_in_widgetForPeople;
	QLineEdit* line_2_in_widgetForPeople;
	QComboBox* cbx_3_in_widgetForPeople;
	QComboBox* cbx_4_in_widgetForPeople;
	QLineEdit* line_5_in_widgetForPeople;
	QLineEdit* line_6_in_widgetForPeople;
	QLineEdit* line_7_in_widgetForPeople;
	QLineEdit* line_8_in_widgetForPeople;
	QLineEdit* line_9_in_widgetForPeople;
	QLineEdit* line_10_in_widgetForPeople;
	QLineEdit* line_11_in_widgetForPeople;
	QLineEdit* line_12_in_widgetForPeople;
	QLineEdit* line_13_in_widgetForPeople;
	QComboBox* cbx_14_in_widgetForPeople;
	QLineEdit* line_15_in_widgetForPeople;
	QLineEdit* line_16_in_widgetForPeople;
	QLineEdit* line_17_in_widgetForPeople;
	QLineEdit* line_18_in_widgetForPeople;
	QLineEdit* line_19_in_widgetForPeople;
	QComboBox* cbx_20_in_widgetForPeople;
	QLineEdit* line_21_in_widgetForPeople;
	QLineEdit* line_22_in_widgetForPeople;
	QLabel* label_pic_in_widgetForPeople;
	//保险查询界面
	QLabel* label_1;
	QComboBox* cbx1_bx;
	QComboBox* cbx2_bx;
	QComboBox* cbx3_bx;
	QPushButton* btn4_bx;
	QTableView* tableView_bx;
	QStandardItemModel* qItemModel_bx;
	QComboBox* cbxsb;
	QComboBox* cbxgsx;
	QComboBox* cbxywx;
	//统计报表界面
	QLabel* label_2;
	QTableView* tableView_total;
	QStandardItemModel* qItemModel_total;
	QToolButton* toolBtn12_total;
	QToolButton* toolBtn13_total;
	QToolButton* toolBtn14_total;
	QToolButton* toolBtn15_total;
	QToolButton* toolBtn16_total;
	QToolButton* toolBtn17_total;
	QToolButton* toolBtn18_total;
	QToolButton* toolBtn23_total;
	//入职办理界面
	QString imagePath;
	QLabel* label_3;
	QMap<QString, Write_entry> map_write_entry;
	QPushButton* btnEntry;
	QPushButton* btnChoseImage;
	QPushButton* btnReturn;
	Mylabel* labelForBtnChoseImage;
	//人事调动界面
	QLineEdit* line_name_change;
	QLineEdit* line_time_change;
	QComboBox* cbx_pro_bef_change;
	QComboBox* cbx_pro_aft_change;
	QTextEdit* text_reason_change;
	QPushButton* btn_change;
	//离职办理界面
	QLineEdit* line_name_out;
	QLineEdit* line_time_out;
	QCheckBox* cb_clothes_out;
	QCheckBox* cb_IDcard_out;
	QCheckBox* cb_tool_out;
	QCheckBox* cb_form_out;
	QCheckBox* cb_wage_out;
	QLineEdit* line_wage_out;
	QTextEdit* text_reason_out;
	QPushButton* btn_out;

private:
	void setBtnColor(int);
	QString style1;
	QString style2;
	int currentPage;
	QString curTextOfLine_name_change;
	QVector<QPushButton*> v_btnpeople;   //用于释放内存
	QVector<QPushButton*> v_btnchg;      //用于释放内存
	QString imagePath_in_widgetForPeople;
	int cur_indexRow_da;
	int cur_indexRow_bx;
	bool checkTime(const QString&, QChar);

signals:
	void sig_btnPress(int);
	void sig_sendEntryData(QVector<QString>, const QByteArray&);
	void sig_sendChangeData(QVector<QString>);
	void sig_sendChangeName(const QString&);
	void sig_sendOutData(QVector<QString>);
	void sig_forGetEmployeeInfoData(QVector<QString>);
	void sig_sendImageData(const QString&);
	void sig_saveEmployeeInfo(QMap<QString, QString>, const QByteArray&);
	void sig_forGetInsuranceInfo(QVector<QString>);
	void sig_saveInsuranceInfo(QVector<QString>);
	void sig_sendtotal(QVector<QString>);
	void sig_menuTriggered(const QString&);

public slots:
	void onsig_foryggl(UserInfo&);
	void oncb_wage_out_toggled(bool);
	void onPage_0_scrollbar(int);
	void onPage_1_scrollbar(int);
	void onPage_2_scrollbar(int);
	void onPage_3_scrollbar(int);
	void onQMenuTriggered(QAction*);
	void receiveChangeName(const QString&);
	void onsig_forSuccessful_YGGL(const QString&);
	void onCbxPro_currentTextChanged(const QString&);
	void receiveEmployeeInfo(QVector<QVector<QString>>);
	void receiveImageData(const QString&, const QByteArray&, const QString&);
	void receiveInsuranceInfo(QVector<QVector<QString>>);
	void receiveTotalData(QVector<QVector<QString>>);
	void receiveMenuTotalData(QVector<QString>, int);

};
