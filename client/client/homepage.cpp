#include "homepage.h"

Homepage::Homepage(QWidget* parent)
	: QWidget(parent)
{
	this->setObjectName(QString::fromUtf8("Homepage"));
	this->resize(1920, 1150);
	this->setWindowIcon(QPixmap("Resources/logo.png"));
	this->setWindowFlags(Qt::WindowFlags::enum_type::FramelessWindowHint | windowFlags());

	widgetMenu = new QWidget(this);
	widgetMenu->setObjectName(QString::fromUtf8("widgetMenu"));
	widgetMenu->setGeometry(QRect(0, 0, 1920, 150));
	widgetMenu->setStyleSheet(QString::fromUtf8("background-color: rgb(230, 231, 255);border-bottom: 1px solid rgb(214, 216, 221);"));
	int h_widgetMenu = widgetMenu->geometry().height();
	int w_widgetMenu = widgetMenu->geometry().width();

	QLabel* labelForLogo = new QLabel(widgetMenu);
	labelForLogo->setGeometry(QRect(35, 35, 80, 80));
	labelForLogo->setStyleSheet("QLabel{image:url(Resources/logo.png);border:none;}");

	QLabel* labelForLogoText = new QLabel(widgetMenu);
	labelForLogoText->setGeometry(QRect(130, 35, 80, 80));
	labelForLogoText->setText("XX\nXX");
	QFont fontlogo;
	fontlogo.setFamily("腾祥铁山楷书繁");
	fontlogo.setPointSize(14);
	fontlogo.setBold(true);
	labelForLogoText->setFont(fontlogo);
	labelForLogoText->setStyleSheet("QLabel{border:none;}");

	style1 = "QPushButton{border: 0px;}"
		"QPushButton:hover{color: rgb(57, 205, 247);}";
	style2 = "QPushButton{color: rgb(57, 205, 247);border: 0px;}";
	QFont font_1;
	font_1.setFamily("方正行楷简体");
	font_1.setPointSize(12);

	btn1 = new QPushButton(widgetMenu);
	btn1->setObjectName(QString::fromUtf8("btn1"));
	btn1->setGeometry(QRect(250, 45, 65, h_widgetMenu - 100));
	btn1->setFont(font_1);
	btn1->setStyleSheet(style1);
	btn1->setText(QString::fromUtf8("主页"));

	btn2 = new QPushButton(widgetMenu);
	btn2->setObjectName(QString::fromUtf8("btn2"));
	btn2->setGeometry(QRect(355, 45, 130, h_widgetMenu - 100));
	btn2->setFont(font_1);
	btn2->setStyleSheet(style1);
	btn2->setText(QString::fromUtf8("排班出勤"));

	btn3 = new QPushButton(widgetMenu);
	btn3->setObjectName(QString::fromUtf8("btn3"));
	btn3->setGeometry(QRect(525, 45, 130, h_widgetMenu - 100));
	btn3->setFont(font_1);
	btn3->setStyleSheet(style1);
	btn3->setText(QString::fromUtf8("工作计划"));

	btn4 = new QPushButton(widgetMenu);
	btn4->setObjectName(QString::fromUtf8("btn4"));
	btn4->setGeometry(QRect(695, 45, 130, h_widgetMenu - 100));
	btn4->setFont(font_1);
	btn4->setStyleSheet(style1);
	btn4->setText(QString::fromUtf8("物资管理"));

	btn5 = new QPushButton(widgetMenu);
	btn5->setObjectName(QString::fromUtf8("btn5"));
	btn5->setGeometry(QRect(865, 45, 130, h_widgetMenu - 100));
	btn5->setFont(font_1);
	btn5->setStyleSheet(style1);
	btn5->setText(QString::fromUtf8("人事管理"));

	btn6 = new QPushButton(widgetMenu);
	btn6->setObjectName(QString::fromUtf8("btn6"));
	btn6->setGeometry(QRect(1035, 45, 130, h_widgetMenu - 100));
	btn6->setFont(font_1);
	btn6->setStyleSheet(style1);
	btn6->setText(QString::fromUtf8("收费管理"));

	btn7 = new QPushButton(widgetMenu);
	btn7->setObjectName(QString::fromUtf8("btn7"));
	btn7->setGeometry(QRect(1205, 45, 130, h_widgetMenu - 100));
	btn7->setFont(font_1);
	btn7->setStyleSheet(style1);
	btn7->setText(QString::fromUtf8("检查整改"));

	btnMinimize = new QPushButton(widgetMenu);
	btnMinimize->setObjectName(QString::fromUtf8("btnMinimize"));
	btnMinimize->setGeometry(QRect(w_widgetMenu - 130, 60, 25, 25));
	btnMinimize->setToolTip(tr("最小化"));
	btnMinimize->setStyleSheet("QPushButton{image:url(Resources/最小化_1.png);border: 0px;}"
		"QPushButton:hover{image:url(Resources/最小化_1_blue.png);}");
	connect(btnMinimize, &QAbstractButton::clicked, [=] {this->showMinimized(); });

	btnmaximize = new QPushButton(widgetMenu);
	btnmaximize->setObjectName(QString::fromUtf8("btnmaximize"));
	btnmaximize->setGeometry(QRect(w_widgetMenu - 90, 60, 25, 25));
	btnmaximize->setToolTip(tr("最大化"));
	btnmaximize->setStyleSheet("QPushButton{image:url(Resources/最大化_1.png);border: 0px;}"
		"QPushButton:hover{image:url(Resources/最大化_1_blue.png);}");
	connect(btnmaximize, &QAbstractButton::clicked, [=]
		{
			btnmaximize->hide();
			btnmaximize_return->show();
			this->setGeometry(0, 0, GetSystemMetrics(SM_CXFULLSCREEN), GetSystemMetrics(SM_CYFULLSCREEN) + style()->pixelMetric(QStyle::PM_TitleBarHeight));
		}
	);

	btnmaximize_return = new QPushButton(widgetMenu);
	btnmaximize_return->setObjectName(QString::fromUtf8("btnmaximize_return"));
	btnmaximize_return->setGeometry(QRect(w_widgetMenu - 90, 60, 25, 25));
	btnmaximize_return->setStyleSheet("QPushButton{image:url(Resources/最大化_1_return.png);border: 0px;}"
		"QPushButton:hover{image:url(Resources/最大化_1_return_blue.png);}");
	btnmaximize_return->hide();
	connect(btnmaximize_return, &QAbstractButton::clicked, [=]
		{
			btnmaximize_return->hide();
			btnmaximize->show();
			this->setGeometry(
				(GetSystemMetrics(SM_CXFULLSCREEN) - 1920) / 2,
				(GetSystemMetrics(SM_CYFULLSCREEN) + style()->pixelMetric(QStyle::PM_TitleBarHeight) - 1155) / 2,
				1920, 1150);
		}
	);

	/*connect(widgetMenu, &MyWidget::doubleClicked, [=]
		{
			if (!btnmaximize->isHidden()) {
				emit btnmaximize->clicked();
			}
			else if(!btnmaximize_return->isHidden()){
				emit btnmaximize_return->clicked();
			}
		}
	);*/

	btnExit = new QPushButton(widgetMenu);
	btnExit->setObjectName(QString::fromUtf8("btnExit"));
	btnExit->setGeometry(QRect(w_widgetMenu - 50, 60, 25, 25));
	btnExit->setToolTip(tr("关闭"));
	btnExit->setStyleSheet("QPushButton{image:url(Resources/弹窗关闭_1.png);border: 0px;}"
		"QPushButton:hover{image:url(Resources/弹窗关闭_1_blue.png);}");
	connect(btnExit, &QAbstractButton::clicked, [=] {this->close(); });

	widgetLine = new QWidget(widgetMenu);
	widgetLine->setGeometry(QRect(w_widgetMenu - 146, 55, 2, 35));
	widgetLine->setStyleSheet("background-color:rgba(0,0,0,40);");

	btnSet = new QPushButton(widgetMenu);
	btnSet->setObjectName(QString::fromUtf8("btnSet"));
	btnSet->setGeometry(QRect(w_widgetMenu - 186, 60, 25, 25));
	btnSet->setStyleSheet(QString::fromUtf8(
		"QPushButton{border: 0px;image:url(Resources/set.png);}"
		"QPushButton:hover{image:url(Resources/set_blue.png);}"
	));

	btnbdxz = new QPushButton(widgetMenu);
	btnbdxz->setObjectName(QString::fromUtf8("btn8"));
	btnbdxz->setGeometry(QRect(w_widgetMenu - 226, 60, 25, 25));
	btnbdxz->setStyleSheet(QString::fromUtf8(
		"QPushButton{border: 0px;image:url(Resources/bdxz.png);}"
		"QPushButton:hover{image:url(Resources/bdxz_blue.png);}"
	));

	widget1 = new QWidget(widgetMenu);
	widget2 = new QWidget(widgetMenu);
	widget3 = new QWidget(widgetMenu);
	widget4 = new QWidget(widgetMenu);
	widget5 = new QWidget(widgetMenu);
	widget6 = new QWidget(widgetMenu);
	widget7 = new QWidget(widgetMenu);
	widget1->setGeometry(btn1->geometry().x(), h_widgetMenu - 40, 65, 5);
	widget2->setGeometry(btn2->geometry().x(), h_widgetMenu - 40, 130, 5);
	widget3->setGeometry(btn3->geometry().x(), h_widgetMenu - 40, 130, 5);
	widget4->setGeometry(btn4->geometry().x(), h_widgetMenu - 40, 130, 5);
	widget5->setGeometry(btn5->geometry().x(), h_widgetMenu - 40, 130, 5);
	widget6->setGeometry(btn6->geometry().x(), h_widgetMenu - 40, 130, 5);
	widget7->setGeometry(btn7->geometry().x(), h_widgetMenu - 40, 130, 5);
	widget1->setStyleSheet("background-color:rgb(57, 205, 247);");
	widget2->setStyleSheet("background-color:rgb(57, 205, 247);");
	widget3->setStyleSheet("background-color:rgb(57, 205, 247);");
	widget4->setStyleSheet("background-color:rgb(57, 205, 247);");
	widget5->setStyleSheet("background-color:rgb(57, 205, 247);");
	widget6->setStyleSheet("background-color:rgb(57, 205, 247);");
	widget7->setStyleSheet("background-color:rgb(57, 205, 247);");
	widget1->hide();
	widget2->hide();
	widget3->hide();
	widget4->hide();
	widget5->hide();
	widget6->hide();
	widget7->hide();

	//以上ui

	userInfo.user_name = "";
	userInfo.user_real_name = "";
	userInfo.work_card = "";
	userInfo.xm = "";
	userInfo.bm = "";
	userInfo.user_password = "";

	//实现按钮和窗口的连接及颜色变化
	btn1->setStyleSheet(style2);
	cur_btn = btn1;
	widget1->show();
	cur_widget = widget1;
	zy = new WidgetZY(this); zy->setGeometry(QRect(0, h_widgetMenu, 1920, 1000)); zy->show();
	cur_mainWidget = zy;

	connect(btnSet, &QAbstractButton::clicked, [=] {set = new Set(); set->show(); });
	connect(btnbdxz, &QAbstractButton::clicked, [=] {bdxz = new WidgetBDXZ(); bdxz->show(); });

	connect(btn1, &QAbstractButton::clicked, [=]() {if (cur_mainWidget == zy) return;
	init(btn1, widget1); zy = new WidgetZY(this); cur_mainWidget->hide(); cur_mainWidget->close(); cur_mainWidget = zy;
	zy->setGeometry(QRect(0, h_widgetMenu, 1920, 1000)); zy->show(); });

	connect(btn2, &QAbstractButton::clicked, [=]()
		{
			if (cur_mainWidget == pbcq) return;

			init(btn2, widget2);

			pbcq = new WidgetPBCQ(this); cur_mainWidget->hide(); cur_mainWidget->close(); cur_mainWidget = pbcq;
			pbcq->setGeometry(QRect(0, h_widgetMenu, 1920, 1000)); pbcq->show();

			connect(this, &Homepage::sig_forpbcq, pbcq, &WidgetPBCQ::onsig_forpbcq);
			connect(this, &Homepage::signalFor_solutionForAttendanceInit, pbcq, &WidgetPBCQ::receiveAttendData);
			connect(this, &Homepage::signalFor_solutionForScheduleInit, pbcq, &WidgetPBCQ::receiveScheduleData);
			connect(pbcq, &WidgetPBCQ::sig_sendAttendData, this, &Homepage::onsig_sendAttendData);
			connect(pbcq, &WidgetPBCQ::sig_save, this, &Homepage::onsig_save);
			connect(pbcq, &WidgetPBCQ::sig_sendScheduleData, this, &Homepage::onsig_sendScheduleData);
			connect(pbcq, &WidgetPBCQ::sig_save_2, this, &Homepage::onsig_save_2);
			emit sig_forpbcq(userInfo);
			emit sig_sendScheduleData(userInfo.xm);
		});

	connect(btn3, &QAbstractButton::clicked, [=]() {if (cur_mainWidget == gzjh) return;
	init(btn3, widget3); gzjh = new WidgetGZJH(this); cur_mainWidget->hide(); cur_mainWidget->close(); cur_mainWidget = gzjh;
	gzjh->setGeometry(QRect(0, h_widgetMenu, 1920, 1000)); gzjh->show(); });

	connect(btn4, &QAbstractButton::clicked, [=]()
		{
			if (cur_mainWidget == wzgl) return;

			init(btn4, widget4);

			wzgl = new WidgetWZGL(this); cur_mainWidget->hide(); cur_mainWidget->close(); cur_mainWidget = wzgl;
			wzgl->setGeometry(QRect(0, h_widgetMenu, 1920, 1000)); wzgl->show();

			connect(this, &Homepage::sig_forwzgl, wzgl, &WidgetWZGL::onsig_forwzgl);
			connect(this, &Homepage::signalFor_solutionForPurchaseInit, wzgl, &WidgetWZGL::receivePurchaseData);
			connect(this, &Homepage::signalFor_solutionForBtnOpen, wzgl, &WidgetWZGL::receiveOpenDate);
			connect(this, &Homepage::sig_forSuccessfulSubmit, wzgl, &WidgetWZGL::onsig_forSuccessfulSubmit);
			connect(this, &Homepage::sig_forState, wzgl, &WidgetWZGL::onsig_forState);
			connect(this, &Homepage::sig_forSuccessfulDelete, wzgl, &WidgetWZGL::onsig_forSuccessfulDelete);
			connect(wzgl, &WidgetWZGL::sig_sendPurchaseData, this, &Homepage::onsig_sendPurchaseData);
			connect(wzgl, &WidgetWZGL::sig_forSubmit, this, &Homepage::onsig_forSubmit);
			connect(wzgl, &WidgetWZGL::sig_btnOpenClicked, this, &Homepage::onsig_btnOpenClicked);
			connect(wzgl, &WidgetWZGL::sig_sendStateData, this, &Homepage::onsig_sendStateData);
			connect(wzgl, &WidgetWZGL::sig_forCostAndDate, this, &Homepage::onsig_forCostAndDate);
			connect(wzgl, &WidgetWZGL::sig_forDelete, this, &Homepage::onsig_forDelete);
			emit sig_forwzgl(userInfo);
		});

	connect(btn5, &QAbstractButton::clicked, [=]()
		{
			if (cur_mainWidget == yggl) return;

			init(btn5, widget5);

			yggl = new WidgetYGGL(this); cur_mainWidget->hide(); cur_mainWidget->close(); cur_mainWidget = yggl;
			yggl->setGeometry(QRect(0, h_widgetMenu, 1920, 1000)); yggl->show();

			connect(this, &Homepage::sig_foryggl, yggl, &WidgetYGGL::onsig_foryggl);
			connect(this, &Homepage::signalFor_solutionForChangeName, yggl, &WidgetYGGL::receiveChangeName);
			connect(this, &Homepage::sig_forSuccessful_YGGL, yggl, &WidgetYGGL::onsig_forSuccessful_YGGL);
			connect(this, &Homepage::signalFor_solutionForEmployeeInfo, yggl, &WidgetYGGL::receiveEmployeeInfo);
			connect(this, &Homepage::signalFor_solutionForImageData, yggl, &WidgetYGGL::receiveImageData);
			connect(this, &Homepage::signalFor_solutionForInsuranceInfo, yggl, &WidgetYGGL::receiveInsuranceInfo);
			connect(this, &Homepage::signalFor_solutionForTotalData, yggl, &WidgetYGGL::receiveTotalData);
			connect(this, &Homepage::signalFor_solutionForMenuTotalData, yggl, &WidgetYGGL::receiveMenuTotalData);
			connect(yggl, &WidgetYGGL::sig_sendEntryData, this, &Homepage::onsig_sendEntryData);
			connect(yggl, &WidgetYGGL::sig_sendChangeData, this, &Homepage::onsig_sendChangeData);
			connect(yggl, &WidgetYGGL::sig_sendChangeName, this, &Homepage::onsig_sendChangeName);
			connect(yggl, &WidgetYGGL::sig_sendOutData, this, &Homepage::onsig_sendOutData);
			connect(yggl, &WidgetYGGL::sig_forGetEmployeeInfoData, this, &Homepage::onsig_forGetEmployeeInfoData);
			connect(yggl, &WidgetYGGL::sig_sendImageData, this, &Homepage::onsig_sendImageData);
			connect(yggl, &WidgetYGGL::sig_saveEmployeeInfo, this, &Homepage::onsig_saveEmployeeInfo);
			connect(yggl, &WidgetYGGL::sig_forGetInsuranceInfo, this, &Homepage::onsig_forGetInsuranceInfo);
			connect(yggl, &WidgetYGGL::sig_saveInsuranceInfo, this, &Homepage::onsig_saveInsuranceInfo);
			connect(yggl, &WidgetYGGL::sig_sendtotal, this, &Homepage::onsig_sendtotal);
			connect(yggl, &WidgetYGGL::sig_menuTriggered, this, &Homepage::onsig_menuTriggered);
			emit sig_foryggl(userInfo);
		});

	connect(btn6, &QAbstractButton::clicked, [=]() {if (cur_mainWidget == sfgl) return;
	init(btn6, widget6); sfgl = new WidgetSFGL(this); cur_mainWidget->hide(); cur_mainWidget->close(); cur_mainWidget = sfgl;
	sfgl->setGeometry(QRect(0, h_widgetMenu, 1920, 1000)); sfgl->show(); });

	connect(btn7, &QAbstractButton::clicked, [=]() {if (cur_mainWidget == jczg) return;
	init(btn7, widget7); jczg = new WidgetJCZG(this); cur_mainWidget->hide(); cur_mainWidget->close(); cur_mainWidget = jczg;
	jczg->setGeometry(QRect(0, h_widgetMenu, 1920, 1000)); jczg->show(); });

}

Homepage::~Homepage()
{
}

void Homepage::init(QPushButton* btn, QWidget* widget) {

	cur_btn->setStyleSheet(style1);
	cur_btn = btn;
	cur_btn->setStyleSheet(style2);

	cur_widget->hide();
	cur_widget = widget;
	cur_widget->show();

}

void Homepage::onsig_forPwdTrue(UserInfo userInfo) {

	this->userInfo = userInfo;

}

void Homepage::mouseMoveEvent(QMouseEvent* event)
{

	if (m_point.y() > 150)
		return;

	//防止鼠标点在按钮上时窗体乱跑
	if (m_point == QPoint())
		return;

	if (m_bPressed && this->cursor().shape() == Qt::ArrowCursor)
		move(event->pos() - m_point + pos());
}

void Homepage::mouseReleaseEvent(QMouseEvent* event)
{
	Q_UNUSED(event);
	m_bPressed = false;
}

void Homepage::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		m_bPressed = true;
		m_point = event->pos();
	}
}

void Homepage::receiveAttendData(QMap<QString, QVector<QVector<QString>>> map_forAttndnce) {
	emit signalFor_solutionForAttendanceInit(map_forAttndnce);
}

void Homepage::receiveScheduleData(QMap<QString, QVector<QVector<QString>>> map_forSchedule) {
	emit signalFor_solutionForScheduleInit(map_forSchedule);
}

void Homepage::onsig_save(QVector<QVector<QString>> v_v_BtnSaveClicked) {
	emit sig_save(v_v_BtnSaveClicked);
}

void Homepage::onsig_save_2(QVector<QVector<QString>> v_v_forSche) {
	emit sig_save_2(v_v_forSche);
}

void Homepage::onsig_sendAttendData(const QString& pro, int day) {
	emit sig_sendAttendData(pro, day);
}

void Homepage::onsig_sendScheduleData(const QString& pro) {
	emit sig_sendScheduleData(pro);
}

void Homepage::receivePurchaseData(QVector<QVector<QString>> v_v_forPurchase) {
	emit signalFor_solutionForPurchaseInit(v_v_forPurchase);
}

void Homepage::onsig_forSubmit(QVector<QVector<QString>> v_v_tableDate) {
	emit sig_forSubmit(v_v_tableDate);
}

void Homepage::onsig_sendPurchaseData(const QString& pro, int year, int month, int state) {
	emit sig_sendPurchaseData(pro, year, month, state);
}

void Homepage::onsig_btnOpenClicked(const QString& purchase_id) {
	emit sig_btnOpenClicked(purchase_id);
}

void Homepage::receiveOpenDate(QVector<QVector<QString>> v_v_forOpen) {
	emit signalFor_solutionForBtnOpen(v_v_forOpen);
}

void Homepage::onsig_forSuccessfulSubmit() {
	emit sig_forSuccessfulSubmit();
}

void Homepage::onsig_sendStateData(const QString& pro_date, int state, int index, const QString& name, QVector<QString> advice) {
	emit sig_sendStateData(pro_date, state, index, name, advice);
}

void Homepage::onsig_forState() {
	emit sig_forState();
}

void Homepage::onsig_forCostAndDate(QVector<QString> v_forCostAndDate) {
	emit sig_forCostAndDate(v_forCostAndDate);
}

void Homepage::onsig_forDelete(const QString& id) {
	emit sig_forDelete(id);
}

void Homepage::onsig_forSuccessfulDelete() {
	emit sig_forSuccessfulDelete();
}

void Homepage::onsig_sendEntryData(QVector<QString> v_sendEntryData, const QByteArray& imageData) {
	emit sig_sendEntryData(v_sendEntryData, imageData);
}

void Homepage::onsig_sendChangeData(QVector<QString> v_sendChangeData) {
	emit sig_sendChangeData(v_sendChangeData);
}

void Homepage::onsig_sendChangeName(const QString& name) {
	emit sig_sendChangeName(name);
}

void Homepage::receiveChangeName(const QString& pro) {
	emit signalFor_solutionForChangeName(pro);
}

void Homepage::onsig_sendOutData(QVector<QString> v_sendOutData) {
	emit sig_sendOutData(v_sendOutData);
}

void Homepage::onsig_forSuccessful_YGGL(const QString& operation) {
	emit sig_forSuccessful_YGGL(operation);
}

void Homepage::onsig_forGetEmployeeInfoData(QVector<QString> v_forEmployeeInfoData) {
	emit sig_forGetEmployeeInfoData(v_forEmployeeInfoData);
}

void Homepage::receiveEmployeeInfo(QVector<QVector<QString>> employeeInfoData) {
	emit signalFor_solutionForEmployeeInfo(employeeInfoData);
}

void Homepage::onsig_sendImageData(const QString& name) {
	emit sig_sendImageData(name);
}

void Homepage::receiveImageData(const QString& pic_format, const QByteArray& data, const QString& address) {
	emit signalFor_solutionForImageData(pic_format, data, address);
}

void Homepage::onsig_saveEmployeeInfo(QMap<QString, QString> map_saveEmployeeInfo, const QByteArray& data) {
	emit sig_saveEmployeeInfo(map_saveEmployeeInfo, data);
}

void Homepage::onsig_forGetInsuranceInfo(QVector<QString> v_forInsuranceInfo) {
	emit sig_forGetInsuranceInfo(v_forInsuranceInfo);
}

void Homepage::receiveInsuranceInfo(QVector<QVector<QString>> insuranceInfoData) {
	emit signalFor_solutionForInsuranceInfo(insuranceInfoData);
}

void Homepage::onsig_saveInsuranceInfo(QVector<QString> v_saveInsuranceInfo) {
	emit sig_saveInsuranceInfo(v_saveInsuranceInfo);
}

void Homepage::onsig_sendtotal(QVector<QString> v_sendTotal) {
	emit sig_sendtotal(v_sendTotal);
}

void Homepage::receiveTotalData(QVector<QVector<QString>> totalData) {
	emit signalFor_solutionForTotalData(totalData);
}

void Homepage::onsig_menuTriggered(const QString& actText) {
	emit sig_menuTriggered(actText);
}

void Homepage::receiveMenuTotalData(QVector<QString> totalData_oneCol, int col) {
	emit signalFor_solutionForMenuTotalData(totalData_oneCol, col);
}