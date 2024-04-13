#pragma once

#include <QtWidgets>
#include "set.h"
#include "widgetzy.h"
#include "widgetpbcq.h"
#include "widgetgzjh.h"
#include "widgetwzgl.h"
#include "widgetyggl.h"
#include "widgetjczg.h"
#include "widgetsfgl.h"
#include "widgetbdxz.h"
#include <QtConcurrent>
#include "mywidget.h"


class Homepage : public QWidget
{
	Q_OBJECT

public:
	Homepage(QWidget* parent = Q_NULLPTR);
	~Homepage();

	// µœ÷Õœ∂Ø
	bool m_bPressed = true;
	QPoint m_point;
	void mouseReleaseEvent(QMouseEvent* event);
	void mousePressEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);

private:
	void init(QPushButton*, QWidget*);

private:
	Set* set;
	WidgetZY* zy;
	WidgetPBCQ* pbcq;
	WidgetGZJH* gzjh;
	WidgetWZGL* wzgl;
	WidgetYGGL* yggl;
	WidgetJCZG* jczg;
	WidgetSFGL* sfgl;
	WidgetBDXZ* bdxz;

private:
	QWidget* widgetMenu;
	QPushButton* btn1;
	QPushButton* btn2;
	QPushButton* btn3;
	QPushButton* btn4;
	QPushButton* btn5;
	QPushButton* btn6;
	QPushButton* btn7;
	QPushButton* btnbdxz;
	QPushButton* btnExit;
	QPushButton* btnMinimize;
	QPushButton* btnmaximize;
	QPushButton* btnmaximize_return;
	QPushButton* btnSet;
	QWidget* widgetLine;

	QWidget* widget1;
	QWidget* widget2;
	QWidget* widget3;
	QWidget* widget4;
	QWidget* widget5;
	QWidget* widget6;
	QWidget* widget7;

private:
	UserInfo userInfo;
	QString style1;
	QString style2;
	QPushButton* cur_btn;
	QWidget* cur_widget;
	QWidget* cur_mainWidget;

public slots:
	void onsig_forPwdTrue(UserInfo);
	void receiveAttendData(QMap<QString, QVector<QVector<QString>>>);
	void receiveScheduleData(QMap<QString, QVector<QVector<QString>>>);
	void onsig_save(QVector<QVector<QString>>);
	void onsig_save_2(QVector<QVector<QString>>);
	void receivePurchaseData(QVector<QVector<QString>>);
	void onsig_forSubmit(QVector<QVector<QString>>);
	void onsig_sendPurchaseData(const QString&, int, int, int);
	void onsig_sendAttendData(const QString&, int);
	void onsig_sendScheduleData(const QString&);
	void onsig_btnOpenClicked(const QString&);
	void receiveOpenDate(QVector<QVector<QString>>);
	void onsig_forSuccessfulSubmit();
	void onsig_sendStateData(const QString&, int, int, const QString&, QVector<QString>);
	void onsig_forState();
	void onsig_forCostAndDate(QVector<QString>);
	void onsig_forDelete(const QString&);
	void onsig_forSuccessfulDelete();
	//yggl
	void onsig_sendEntryData(QVector<QString>, const QByteArray&);
	void onsig_sendChangeData(QVector<QString>);
	void onsig_sendChangeName(const QString&);
	void receiveChangeName(const QString&);
	void onsig_sendOutData(QVector<QString>);
	void onsig_forSuccessful_YGGL(const QString&);
	void onsig_forGetEmployeeInfoData(QVector<QString>);
	void receiveEmployeeInfo(QVector<QVector<QString>>);
	void onsig_sendImageData(const QString&);
	void receiveImageData(const QString&, const QByteArray&, const QString&);
	void onsig_saveEmployeeInfo(QMap<QString, QString>, const QByteArray&);
	void onsig_forGetInsuranceInfo(QVector<QString>);
	void receiveInsuranceInfo(QVector<QVector<QString>>);
	void onsig_saveInsuranceInfo(QVector<QString>);
	void onsig_sendtotal(QVector<QString>);
	void receiveTotalData(QVector<QVector<QString>>);
	void onsig_menuTriggered(const QString&);
	void receiveMenuTotalData(QVector<QString>, int);

signals:
	void sig_forpbcq(UserInfo&);
	void sig_forwzgl(UserInfo&);
	void sig_foryggl(UserInfo&);
	void signalFor_solutionForAttendanceInit(QMap<QString, QVector<QVector<QString>>>);
	void signalFor_solutionForScheduleInit(QMap<QString, QVector<QVector<QString>>>);
	void sig_save(QVector<QVector<QString>>);
	void sig_save_2(QVector<QVector<QString>>);
	void sig_forSubmit(QVector<QVector<QString>>);
	void sig_sendPurchaseData(const QString&, int, int, int);
	void signalFor_solutionForPurchaseInit(QVector<QVector<QString>>);
	void sig_sendAttendData(const QString&, int);
	void sig_sendScheduleData(const QString&);
	void sig_btnOpenClicked(const QString&);
	void signalFor_solutionForBtnOpen(QVector<QVector<QString>>);
	void sig_forSuccessfulSubmit();
	void sig_sendStateData(const QString&, int, int, const QString&, QVector<QString>);
	void sig_forState();
	void sig_forCostAndDate(QVector<QString>);
	void sig_forDelete(const QString&);
	void sig_forSuccessfulDelete();
	//yggl
	void sig_sendEntryData(QVector<QString>, const QByteArray&);
	void sig_sendChangeData(QVector<QString>);
	void sig_sendChangeName(const QString&);
	void signalFor_solutionForChangeName(const QString&);
	void sig_sendOutData(QVector<QString>);
	void sig_forSuccessful_YGGL(const QString&);
	void sig_forGetEmployeeInfoData(QVector<QString>);
	void signalFor_solutionForEmployeeInfo(QVector<QVector<QString>>);
	void sig_sendImageData(const QString&);
	void signalFor_solutionForImageData(const QString&, const QByteArray&, const QString&);
	void sig_saveEmployeeInfo(QMap<QString, QString>, const QByteArray&);
	void sig_forGetInsuranceInfo(QVector<QString>);
	void signalFor_solutionForInsuranceInfo(QVector<QVector<QString>>);
	void sig_saveInsuranceInfo(QVector<QString>);
	void sig_sendtotal(QVector<QString>);
	void signalFor_solutionForTotalData(QVector<QVector<QString>>);
	void sig_menuTriggered(const QString&);
	void signalFor_solutionForMenuTotalData(QVector<QString>, int);

};
