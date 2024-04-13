#include "widgetpbcq.h"

WidgetPBCQ::WidgetPBCQ(QWidget* parent)
	: QWidget(parent)
{
	setAttribute(Qt::WA_DeleteOnClose);
	this->setObjectName(QString::fromUtf8("WidgetPBCQ"));
	this->resize(1920, 1000);
	QMetaObject::connectSlotsByName(this);

	date = dateClass.getCurrentDate();

	tabWidget = new QTabWidget(this);
	tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
	tabWidget->setGeometry(QRect(0, 0, 1920, 1000));
	tabWidget->setFont(QFont("�����п�����", 14));

	tab = new QWidget();
	tab->setObjectName(QString::fromUtf8("tab"));
	tab->setStyleSheet(QString::fromUtf8("background-color: rgb(239, 237, 255);"));

	tab_2 = new QWidget();
	tab_2->setObjectName(QString::fromUtf8("tab_2"));
	tab_2->setStyleSheet(QString::fromUtf8("background-color: rgb(239, 237, 255);"));

	widgetLeft = new QWidget(tab);
	widgetLeft->setObjectName(QString::fromUtf8("widgetLeft"));
	widgetLeft->setGeometry(QRect(0, 0, 360, 970));
	widgetLeft->setStyleSheet(QString::fromUtf8("background-color: rgb(239, 237, 255);"));

	widgetRight = new QWidget(tab);
	widgetRight->setObjectName(QString::fromUtf8("widgetRight"));
	widgetRight->setGeometry(QRect(363, 0, 1557, 970));
	widgetRight->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 239, 171);"));

	comboBoxPro = new QComboBox(widgetLeft);
	comboBoxPro->addItem(QString("��˾�ܲ�"));
	comboBoxPro->addItem(QString("�Ķ���Ԣ"));
	comboBoxPro->addItem(QString("������԰"));
	comboBoxPro->addItem(QString("���һ��"));
	comboBoxPro->addItem(QString("����С��"));
	comboBoxPro->addItem(QString("�������ʴ�"));
	comboBoxPro->addItem(QString("�κ軪ͥ"));
	comboBoxPro->addItem(QString("���ⶼ��"));
	comboBoxPro->addItem(QString("����֤ȯ"));
	comboBoxPro->addItem(QString("���Ϲ�Ԣ"));
	comboBoxPro->addItem(QString("�Ļ����ξ�"));
	comboBoxPro->addItem(QString("���ù��ʱ���"));
	comboBoxPro->setObjectName(QString::fromUtf8("comboBoxPro"));
	comboBoxPro->setGeometry(QRect(60, 50, 240, 50));
	comboBoxPro->setFont(QFont("����", 12));
	comboBoxPro->setFocusPolicy(Qt::NoFocus);
	comboBoxPro->setMaxVisibleItems(15);
	comboBoxPro->setStyleSheet(QString::fromUtf8(" QComboBox {"
		"      border: 1px solid grey;"
		"      border-radius: 20px;"
		"      padding: 1px 0px 1px 3px;"
		"      background-color: rgb(211, 211, 255);"
		"  }"
		"  QComboBox:on {"
		"      padding-top: 3px;"
		"      padding-left: 4px;"
		"  }"
		"  QComboBox::drop-down {"
		"      subcontrol-origin: padding;"
		"      subcontrol-position: top right;"
		"      border-top-right-radius: 3px;"
		"      border-bottom-right-radius: 3px;"
		"  }"
	));
	comboBoxPro->setCurrentIndex(-1);
	qItemModel = qobject_cast<QStandardItemModel*>(comboBoxPro->model());
	for (int i = 0; i < 12; ++i) {
		qItemModel->item(i)->setBackground(QBrush(QColor(211, 211, 255)));
	}

	listViewForw = new QListView(widgetLeft);
	listViewForw->setObjectName(QString::fromUtf8("listViewForw"));
	listViewForw->setGeometry(QRect(3, 380, 354, 490));
	listViewForw->setFrameShadow(QFrame::Plain);

	calendarWidget = new QCalendarWidget(widgetLeft);
	calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
	calendarWidget->setEnabled(true);
	calendarWidget->setGeometry(QRect(4, 470, 352, 380));
	calendarWidget->setFont(QFont("����", 8));
	calendarWidget->setFocusPolicy(Qt::NoFocus);
	calendarWidget->setStyleSheet(QString::fromUtf8(
		"QCalendarWidget QTableView{alternate-background-color: rgb(239, 237, 255);background-color: rgb(239, 237, 255);"
		"selection-background-color: rgb(200, 200, 255);selection-color: rgb(255, 255, 255);}"
		"QToolButton#qt_calendar_monthbutton, #qt_calendar_yearbutton{color: black; font: 8pt simHei;}"
		"QCalendarWidget QWidget#qt_calendar_navigationbar{background-color: rgb(239, 237, 255);}"
	));
	calendarWidget->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
	calendarWidget->setDateEditEnabled(false);
	calendarWidget->setMaximumDate(QDate(date.year.toInt(), date.month.toInt(), dateClass.getDayMaxOfMonth(date.year.toInt(), date.month.toInt())));
	calendarWidget->setMinimumDate(QDate(date.year.toInt(), date.month.toInt(), 1));
	QToolButton* prevBtn = calendarWidget->findChild<QToolButton*>(QLatin1String("qt_calendar_prevmonth"));
	QToolButton* nextBtn = calendarWidget->findChild<QToolButton*>(QLatin1String("qt_calendar_nextmonth"));
	QToolButton* yearBtn = calendarWidget->findChild<QToolButton*>(QLatin1String("qt_calendar_yearbutton"));
	QToolButton* monthBtn = calendarWidget->findChild<QToolButton*>(QLatin1String("qt_calendar_monthbutton"));
	prevBtn->hide();
	nextBtn->hide();
	yearBtn->setEnabled(false);
	yearBtn->setStyleSheet("background-color: rgb(239, 237, 255);");
	monthBtn->setEnabled(false);
	monthBtn->setStyleSheet("QToolButton{background-color: rgb(239, 237, 255);}QToolButton::menu-indicator{image:none;}");

	labelcalendar = new QLabel(widgetLeft);
	labelcalendar->setObjectName(QString::fromUtf8("labelcalendar"));
	labelcalendar->setGeometry(QRect(10, 400, 340, 40));
	labelcalendar->setFont(QFont("����", 14));
	labelcalendar->setAlignment(Qt::AlignCenter);
	labelcalendar->setText("��ʷ���ڼ�¼");

	btnCreate = new QPushButton(widgetLeft);
	btnCreate->setObjectName(QString::fromUtf8("btnCreate"));
	btnCreate->setGeometry(QRect(0, 160, 360, 80));
	btnCreate->setFont(QFont("����", 12));
	btnCreate->setText("�½����ڱ�      ");
	QIcon iconadd;
	iconadd.addFile(QString::fromUtf8("Resources/addnewpage.png"), QSize(35, 35), QIcon::Normal, QIcon::Off);
	btnCreate->setIcon(iconadd);
	btnCreate->setStyleSheet(
		"QPushButton{background-color: rgba(255, 255, 255, 0);color: rgb(80, 80, 121); border: 0px;}"
		"QPushButton:hover{background-color: rgba(255, 255, 255, 153);}"
		"QPushButton:pressed{background-color: rgba(255, 255, 255, 230);}"
	);

	btnRefer = new QPushButton(widgetLeft);
	btnRefer->setObjectName(QString::fromUtf8("btnRefer"));
	btnRefer->setGeometry(QRect(0, 240, 360, 80));
	btnRefer->setFont(QFont("����", 12));
	btnRefer->setText("�ο���һ����ڱ�");
	QIcon iconrefer;
	iconrefer.addFile(QString::fromUtf8("Resources/reference.png"), QSize(35, 35), QIcon::Normal, QIcon::Off);
	btnRefer->setIcon(iconrefer);
	btnRefer->setStyleSheet(
		"QPushButton{background-color: rgba(255, 255, 255, 0);color: rgb(80, 80, 121); border: 0px;}"
		"QPushButton:hover{background-color: rgba(255, 255, 255, 153);}"
		"QPushButton:pressed{background-color: rgba(255, 255, 255, 230);}"
	);

	labelAttend = new QLabel(widgetRight);
	labelAttend->setObjectName(QString::fromUtf8("labelAttend"));
	labelAttend->setGeometry(QRect(70, 0, 850, 90));
	labelAttend->setFont(QFont("����", 20));

	btnSave = new QPushButton(widgetRight);
	btnSave->setObjectName(QString::fromUtf8("btnSave"));
	btnSave->setGeometry(QRect(1310, 15, 170, 70));
	btnSave->setFont(QFont("����", 14));
	btnSave->setCursor(QCursor(Qt::PointingHandCursor));
	btnSave->setStyleSheet(QString::fromUtf8(
		"QPushButton{				             "
		"  background-color: rgb(254, 226, 255); "
		"  border-style: outset;				 "
		"  border-width: 1px;					 "
		"  border-radius: 30px;				     "
		"  border-color: grey;				     "
		"  padding: 6px;						 "
		"}										 "
		"QPushButton:hover{                      "
		"  background-color: rgb(254, 242, 255); "
		"}                                       "
		"QPushButton:pressed{		             "
		"  border-style: inset;				     "
		"  background-color: rgba(254, 242, 255, 128); "
		"}										 "
	));
	QIcon icon1;
	icon1.addFile(QString::fromUtf8("Resources/save.png"), QSize(), QIcon::Normal, QIcon::Off);
	btnSave->setIcon(icon1);
	btnSave->setIconSize(QSize(50, 50));
	btnSave->setText("����");

	listViewOut = new QListView(widgetRight);
	listViewOut->setObjectName(QString::fromUtf8("listViewOut"));
	listViewOut->setGeometry(QRect(5, 90, 1530, 830));
	listViewOut->setFrameShadow(QFrame::Plain);

	labelxmjl = new QLabel(widgetRight);
	labelxmjl->setObjectName(QString::fromUtf8("labelxmjl"));
	labelxmjl->setGeometry(QRect(10, 95, 180, 90));
	labelxmjl->setFont(QFont("����", 9));
	labelxmjl->setFrameShape(QFrame::Box);
	labelxmjl->setFrameShadow(QFrame::Sunken);
	labelxmjl->setAlignment(Qt::AlignCenter);
	labelxmjl->setText("��Ŀ����");

	labelxz = new QLabel(widgetRight);
	labelxz->setObjectName(QString::fromUtf8("labelxz"));
	labelxz->setGeometry(QRect(10, 190, 180, 90));
	labelxz->setFont(QFont("����", 9));
	labelxz->setFrameShape(QFrame::Box);
	labelxz->setFrameShadow(QFrame::Sunken);
	labelxz->setAlignment(Qt::AlignCenter);
	labelxz->setText("�� �� ��");

	labelkf = new QLabel(widgetRight);
	labelkf->setObjectName(QString::fromUtf8("labelkf"));
	labelkf->setGeometry(QRect(10, 285, 180, 90));
	labelkf->setFont(QFont("����", 9));
	labelkf->setFrameShape(QFrame::Box);
	labelkf->setFrameShadow(QFrame::Sunken);
	labelkf->setAlignment(Qt::AlignCenter);
	labelkf->setText("�� �� ��");

	labelgc = new QLabel(widgetRight);
	labelgc->setObjectName(QString::fromUtf8("labelgc"));
	labelgc->setGeometry(QRect(10, 380, 180, 90));
	labelgc->setFont(QFont("����", 9));
	labelgc->setFrameShape(QFrame::Box);
	labelgc->setFrameShadow(QFrame::Sunken);
	labelgc->setAlignment(Qt::AlignCenter);
	labelgc->setText("�� �� ��");

	labelwh = new QLabel(widgetRight);
	labelwh->setObjectName(QString::fromUtf8("labelwh"));
	labelwh->setGeometry(QRect(10, 475, 180, 90));
	labelwh->setFont(QFont("����", 9));
	labelwh->setFrameShape(QFrame::Box);
	labelwh->setFrameShadow(QFrame::Sunken);
	labelwh->setAlignment(Qt::AlignCenter);
	labelwh->setText("����ά����");

	labellh = new QLabel(widgetRight);
	labellh->setObjectName(QString::fromUtf8("labellh"));
	labellh->setGeometry(QRect(10, 570, 180, 90));
	labellh->setFont(QFont("����", 9));
	labellh->setFrameShape(QFrame::Box);
	labellh->setFrameShadow(QFrame::Sunken);
	labellh->setAlignment(Qt::AlignCenter);
	labellh->setText("�������̻�");

	labelbj = new QLabel(widgetRight);
	labelbj->setObjectName(QString::fromUtf8("labelbj"));
	labelbj->setGeometry(QRect(10, 665, 180, 90));
	labelbj->setFont(QFont("����", 9));
	labelbj->setFrameShape(QFrame::Box);
	labelbj->setFrameShadow(QFrame::Sunken);
	labelbj->setAlignment(Qt::AlignCenter);
	labelbj->setText("����������");

	labelhq = new QLabel(widgetRight);
	labelhq->setObjectName(QString::fromUtf8("labelhq"));
	labelhq->setGeometry(QRect(10, 760, 180, 90));
	labelhq->setFont(QFont("����", 9));
	labelhq->setFrameShape(QFrame::Box);
	labelhq->setFrameShadow(QFrame::Sunken);
	labelhq->setAlignment(Qt::AlignCenter);
	labelhq->setText("�� �� ��");

	labelbad = new QLabel(widgetRight);
	labelbad->setObjectName(QString::fromUtf8("labelbad"));
	labelbad->setGeometry(QRect(10, 855, 180, 60));
	labelbad->setFont(QFont("����", 9));
	labelbad->setFrameShape(QFrame::Box);
	labelbad->setFrameShadow(QFrame::Sunken);
	labelbad->setAlignment(Qt::AlignCenter);
	labelbad->setText("��Ϣ/���/����");

	labelShow = new QLabel(widgetRight);
	labelShow->setObjectName(QString::fromUtf8("labelShow"));
	labelShow->setGeometry(QRect(195, 855, 1336, 60));
	QFont font10;
	font10.setFamily(QString::fromUtf8("����"));
	font10.setPointSize(12);
	font10.setBold(true);
	font10.setWeight(75);
	labelShow->setFont(font10);
	labelShow->setFrameShape(QFrame::StyledPanel);

	tabWidget->addTab(tab, QString());

	labelTitle = new QLabel(tab_2);
	labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
	labelTitle->setGeometry(QRect(600, 60, 720, 70));
	QFont font11;
	font11.setFamily(QString::fromUtf8("����"));
	font11.setPointSize(24);
	font11.setBold(true);
	font11.setWeight(75);
	labelTitle->setFont(font11);
	labelTitle->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
	labelTitle->setText("�㽭XXXX�¶��Ű��");

	labelLine = new QLabel(tab_2);
	labelLine->setObjectName(QString::fromUtf8("labelLine"));
	labelLine->setGeometry(QRect(0, 250, 1920, 2));
	labelLine->setStyleSheet(QString::fromUtf8("background-color: rgb(205, 205, 205);"));

	labelProNm = new QLabel(tab_2);
	labelProNm->setObjectName(QString::fromUtf8("labelProNm"));
	labelProNm->setGeometry(QRect(0, 170, 170, 60));
	labelProNm->setFont(QFont("����", 12));
	labelProNm->setAlignment(Qt::AlignRight | Qt::AlignTrailing | Qt::AlignVCenter);
	labelProNm->setText("��Ŀ���ƣ�");

	comboBoxPro_2 = new QComboBox(tab_2);
	comboBoxPro_2->addItem(QString("��˾�ܲ�"));
	comboBoxPro_2->addItem(QString("�Ķ���Ԣ"));
	comboBoxPro_2->addItem(QString("������԰"));
	comboBoxPro_2->addItem(QString("���һ��"));
	comboBoxPro_2->addItem(QString("����С��"));
	comboBoxPro_2->addItem(QString("�������ʴ�"));
	comboBoxPro_2->addItem(QString("�κ軪ͥ"));
	comboBoxPro_2->addItem(QString("���ⶼ��"));
	comboBoxPro_2->addItem(QString("����֤ȯ"));
	comboBoxPro_2->addItem(QString("���Ϲ�Ԣ"));
	comboBoxPro_2->addItem(QString("�Ļ����ξ�"));
	comboBoxPro_2->addItem(QString("���ù��ʱ���"));
	comboBoxPro_2->setObjectName(QString::fromUtf8("comboBoxPro_2"));
	comboBoxPro_2->setGeometry(QRect(170, 170, 240, 60));
	comboBoxPro_2->setFont(QFont("����", 12));
	comboBoxPro_2->setFocusPolicy(Qt::NoFocus);
	comboBoxPro_2->setMaxVisibleItems(15);
	comboBoxPro_2->setStyleSheet(QString::fromUtf8(" QComboBox {"
		"      border: 1px solid grey;"
		"      border-radius: 30px;"
		"      padding: 1px 0px 1px 3px;"
		"  }"
		"  QComboBox:on {"
		"      padding-top: 3px;"
		"      padding-left: 4px;"
		"  }"
		"  QComboBox::drop-down {"
		"      subcontrol-origin: padding;"
		"      subcontrol-position: top right;"
		"      border-top-right-radius: 3px;"
		"      border-bottom-right-radius: 3px;"
		"  }"
	));
	comboBoxPro_2->setCurrentIndex(-1);

	labelMonth = new QLabel(tab_2);
	labelMonth->setObjectName(QString::fromUtf8("labelMonth"));
	labelMonth->setGeometry(QRect(620, 170, 40, 60));
	labelMonth->setFont(QFont("����", 12));
	labelMonth->setText("��");

	comboBoxMonth = new QComboBox(tab_2);
	comboBoxMonth->addItem(QString("1"));
	comboBoxMonth->addItem(QString("2"));
	comboBoxMonth->addItem(QString("3"));
	comboBoxMonth->addItem(QString("4"));
	comboBoxMonth->addItem(QString("5"));
	comboBoxMonth->addItem(QString("6"));
	comboBoxMonth->addItem(QString("7"));
	comboBoxMonth->addItem(QString("8"));
	comboBoxMonth->addItem(QString("9"));
	comboBoxMonth->addItem(QString("10"));
	comboBoxMonth->addItem(QString("11"));
	comboBoxMonth->addItem(QString("12"));
	comboBoxMonth->setObjectName(QString::fromUtf8("comboBoxMonth"));
	comboBoxMonth->setGeometry(QRect(540, 170, 70, 60));
	comboBoxMonth->setFont(QFont("Arial"));
	comboBoxMonth->setFocusPolicy(Qt::NoFocus);
	comboBoxMonth->setMaxVisibleItems(12);
	comboBoxMonth->setStyleSheet(QString::fromUtf8(" QComboBox {"
		"      border: 1px solid grey;"
		"      border-radius: 25px;"
		"      padding: 1px 0px 1px 3px;"
		"  }"
		"  QComboBox:on {"
		"      padding-top: 3px;"
		"      padding-left: 4px;"
		"  }"
		"  QComboBox::drop-down {"
		"      subcontrol-origin: padding;"
		"      subcontrol-position: top right;"
		"      border-top-right-radius: 3px;"
		"      border-bottom-right-radius: 3px;"
		"  }"
	));
	comboBoxMonth->setCurrentIndex(date.month.toInt() - 1);

	labelYear = new QLabel(tab_2);
	labelYear->setObjectName(QString::fromUtf8("labelYear"));
	labelYear->setGeometry(QRect(420, 170, 110, 60));
	labelYear->setFont(QFont("Arial", 12));
	labelYear->setText(QString("%1 ��").arg(date.year));

	btnLoadIn = new QPushButton(tab_2);
	btnLoadIn->setObjectName(QString::fromUtf8("btnLoadIn"));
	btnLoadIn->setGeometry(QRect(670, 170, 150, 60));
	btnLoadIn->setFont(QFont("����", 12));			 
	btnLoadIn->setStyleSheet(
		"QPushButton{border-width: 1px;border-color: grey;border-style: outset;background-color: rgba(255, 255, 255, 0);border-radius: 30px;}"
		"QPushButton:hover{background-color: rgb(250, 250, 250);}"
		"QPushButton:pressed{border-style: inset;background-color: rgba(250, 250, 250, 128);}"
	);
	QIcon iconload;
	iconload.addFile(QString::fromUtf8("Resources/loadin.png"), QSize(), QIcon::Normal, QIcon::Off);
	btnLoadIn->setIcon(iconload);
	btnLoadIn->setText("����");

	btnSave_2 = new QPushButton(tab_2);
	btnSave_2->setObjectName(QString::fromUtf8("btnSave_2"));
	btnSave_2->setGeometry(QRect(1590, 140, 210, 90));
	btnSave_2->setFont(QFont("����", 18));
	btnSave_2->setCursor(QCursor(Qt::PointingHandCursor));
	btnSave_2->setIcon(icon1);
	btnSave_2->setIconSize(QSize(64, 64));
	btnSave_2->setStyleSheet(QString::fromUtf8(
		"QPushButton{				             "
		"  background-color: rgb(239, 237, 255); "
		"  border-style: outset;				 "
		"  border-width: 1px;					 "
		"  border-radius: 40px;				     "
		"  border-color: grey;				     "
		"  min-width: 10em;					     "
		"  padding: 6px;						 "
		"}										 "
		"QPushButton:hover{                      "
		"  background-color: rgb(250, 250, 250); "
		"}                                       "
		"QPushButton:pressed{		             "
		"  background-color: rgba(250, 250, 250, 128); "
		"  border-style: inset;				     "
		"}										 "
	));
	btnSave_2->setText("����");
	
	tabWidget->addTab(tab_2, QString());
	tabWidget->setCurrentIndex(0);
	tabWidget->setTabText(0, "  �ճ��ڱ�  ");
	tabWidget->setTabText(1, "  ���Ű��  ");
	tabWidget->setAttribute(Qt::WA_StyledBackground);
	tabWidget->setStyleSheet(QString::fromUtf8(
		"QTabWidget{"
		"background-color: rgb(239, 237, 255);"
		"}"
		"QTabWidget::pane{"
		"border-top: 1px solid #C2C7CB;"
		"}"
		"QTabBar::tab{"
		"background-color: rgb(239, 237, 255);"
		"border: 1px solid #C4C4C3;"
		"border-bottom-color: #C2C7CB;"
		"border-top-left-radius: 4px;"
		"border-top-right-radius: 4px;"
		"padding: 2px;"
		"}"
		"QTabBar::tab:selected, QTabBar::tab:hover {"
		"background:rgb(216, 234, 249);"
		"}"
		"QTabBar::tab:selected {"
		"border-color: #9B9B9B;"
		"border-bottom-color: #C2C7CB;"
		"}"
		"QTabBar::tab:!selected {"
		"margin-top: 2px;"
		"}"
		"QTabBar::tab:selected {"
		"background:rgb(216, 234, 249);"
		"margin-left: -4px;"
		"margin-right: -4px;"
		"}"
		"QTabBar::tab:first:selected {"
		"margin-left: 0;"
		"}"
		"QTabBar::tab:last:selected{"
		"margin-right: 0;"
		"}"
		"QTabWidget::tab-bar{"
		"left: 10px;"
		"}"
	));
	//����ui

	//���Ƴ��ڽ���ķ���
	QWidget* widget_temp = NULL;
	QScrollArea* scrollArea_temp = NULL;
	for (int i = 1; i <= 8; ++i) {
		widget_temp = new QWidget(widgetRight);
		widget_temp->setObjectName(QString::fromUtf8("widget%1").arg(QString(i - 1)));
		widget_temp->setGeometry(QRect(195, 95 * i, 1334, 88));
		widget_temp->setStyleSheet("border: 0px;");
		widget.push_back(widget_temp);

		scrollArea_temp = new QScrollArea(widgetRight);
		scrollArea_temp->setGeometry(QRect(195, 95 * i, 1336, 90));
		scrollArea_temp->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
		scrollArea_temp->horizontalScrollBar()->setStyleSheet("QScrollBar:horizontal{"
			"height:12px;"
			"background:rgb(255, 239, 171);"
			"padding-top:1px;"
			"padding-bottom:1px;"
			"padding-left:3px;"
			"padding-right:3px;}"
			"QScrollBar::handle:horizontal{"
			"background:#dbdbdb;"
			"border-radius:5px;"
			"min-width:80px;}"
			"QScrollBar::handle:horizontal:hover{"
			"background:#d0d0d0;}"
			"QScrollBar::add-line:horizontal{"
			"background:url() center no-repeat;}"
			"QScrollBar::sub-line:horizontal{"
			"background:url() center no-repeat;}");
		scrollArea_temp->setWidget(widget_temp);
		scrollArea.push_back(scrollArea_temp);
	}

	//�������Ű��ı��
	tableView = new QTableView(tab_2);
	qItemModel = new QStandardItemModel(tab_2);
	tableView->setGeometry(QRect(20, 270, 1880, 660));
	tableView->setFocusPolicy(Qt::FocusPolicy::NoFocus);
	tableView->horizontalHeader()->setFont(QFont("����", 7));
	tableView->horizontalHeader()->setFixedHeight(55);
	tableView->setGridStyle(Qt::PenStyle::DashDotDotLine);
	tableView->setModel(qItemModel);
	tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//����Ӧ���
	tableView->verticalScrollBar()->setStyleSheet("QScrollBar:vertical{"        //��ֱ��������  
		"width:30px;"
		"background:#FFFFFF;"  //����ɫ  
		"padding-top:5px;"    //��Ԥ��λ�ã��������ϼ�ͷ��  
		"padding-bottom:5px;" //��Ԥ��λ�ã��������¼�ͷ��  
		"padding-left:3px;"    //��Ԥ��λ�ã����ۣ�  
		"padding-right:3px;"   //��Ԥ��λ�ã����ۣ�  
		"border-left:0px;}"//��ָ���  
		"QScrollBar::handle:vertical{"//������ʽ  
		"background:#dbdbdb;"  //������ɫ  
		"border-radius:10px;"   //�߽�Բ��  
		"min-height:80px;}"    //������С�߶�  
		"QScrollBar::handle:vertical:hover{"//��괥��������ʽ  
		"background:#d0d0d0;}" //������ɫ  
		"QScrollBar::add-line:vertical{"//���¼�ͷ��ʽ  
		"background:url() center no-repeat;}"
		"QScrollBar::sub-line:vertical{"//���ϼ�ͷ��ʽ  
		"background:url() center no-repeat;}");

	//�ճ��ڱ��ʵ��
	connect(comboBoxPro, &QComboBox::currentTextChanged, [=]
		{
			labelAttend->setText(QString("%1 %2��%3��%4�ճ��ڱ�").arg(comboBoxPro->currentText()).arg(date.year).arg(date.month).arg(date.day));
			emit sig_sendAttendData(comboBoxPro->currentText(), calendarWidget->selectedDate().day());
		});

	connect(calendarWidget, &QCalendarWidget::selectionChanged, [=]
		{
			emit sig_sendAttendData(comboBoxPro->currentText(), calendarWidget->selectedDate().day());
		});

	//�ճ��ڱ�ҳ�汣�水ť��ʵ�� btnSave
	connect(btnSave, &QAbstractButton::clicked, this, &WidgetPBCQ::onBtnSaveClicked);

	//�½����ճ��ڱ� 
	connect(btnCreate, &QPushButton::clicked, [=] {
		labelShow->clear();
		for (auto it = cbx.cbegin(); it != cbx.cend(); ++it)
			(*it)->setCurrentIndex(0);
		});

	//�ο���һ����ڱ� label_7
	connect(btnRefer, &QPushButton::clicked, [=] {
		if (calendarWidget->selectedDate().day() == 1)
			return;
		emit sig_sendAttendData(comboBoxPro->currentText(), calendarWidget->selectedDate().day() - 1);
		});

	//���Ű�����밴ť��ʵ��
	connect(btnLoadIn, &QAbstractButton::clicked, [=]
		{
			QMessageBox box(QMessageBox::Question, "��ʾ", "ȷ��Ҫ������");
			box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
			box.setButtonText(QMessageBox::Ok, QString("ȷ ��"));
			box.setButtonText(QMessageBox::Cancel, QString("ȡ ��"));
			box.setWindowIcon(QPixmap("Resources/logo.png"));
			int button = box.exec();
			if (button != QMessageBox::Ok)
				return;
			emit sig_sendScheduleData(comboBoxPro_2->currentText());
		});

	//���Ű��ҳ�汣�水ť��ʵ�� btnSave_2
	connect(btnSave_2, &QAbstractButton::clicked, this, &WidgetPBCQ::onBtnSave_2Clicked);

	//��˫��ȫѡ
	connect(tableView->horizontalHeader(), &QHeaderView::sectionDoubleClicked, this, &WidgetPBCQ::onsectionDoubleClicked);

}

WidgetPBCQ::~WidgetPBCQ()
{
	delete tab;
	delete tab_2;
	tab = NULL;
	tab_2 = NULL;
}

void WidgetPBCQ::onsig_forpbcq(UserInfo& userInfo) {

	comboBoxPro->setCurrentText(userInfo.xm);
	comboBoxPro_2->setCurrentText(userInfo.xm);
	labelAttend->setText(QString("%1 %2��%3��%4�ճ��ڱ�").arg(userInfo.xm).arg(date.year).arg(date.month).arg(date.day));

}

void WidgetPBCQ::onBtnSaveClicked() {

	QVector<QVector<QString>> v_v_BtnSaveClicked;
	QVector<QString> v_BtnSaveClicked;

	labelShow->clear();

	auto it2 = lbl.cbegin();
	for (auto it = cbx.cbegin(); it != cbx.cend(); ++it, ++it2) {
		v_BtnSaveClicked.push_back((*it2)->text());
		v_BtnSaveClicked.push_back(QString::number(calendarWidget->selectedDate().day()));
		v_BtnSaveClicked.push_back(QString::number((*it)->currentIndex()));
		v_v_BtnSaveClicked.push_back(v_BtnSaveClicked);
		v_BtnSaveClicked.clear();

		if ((*it)->currentIndex() == ��Ϣ || (*it)->currentIndex() == ��� || (*it)->currentIndex() == ����)
			labelShow->setText(labelShow->text() + (*it2)->text() + " ");
	}

	emit sig_save(v_v_BtnSaveClicked);
}

void WidgetPBCQ::onBtnSave_2Clicked() {

	QVector<QVector<QString>> v_v_forSche;
	QVector<QString> v_forSche;

	auto it = v_v_checkBox.cbegin();
	for (int i = 0; i < qItemModel->rowCount() && it != v_v_checkBox.cend(); ++i, ++it) {
		v_forSche.push_back(qItemModel->item(i, 0)->text());
		for (auto it_2 = it->cbegin(); it_2 != it->cend(); ++it_2) {
			v_forSche.push_back(QString::number((*it_2)->checkState()));
		}
		v_v_forSche.push_back(v_forSche);
		v_forSche.clear();
	}

	emit sig_save_2(v_v_forSche);

}

void WidgetPBCQ::receiveAttendData(QMap<QString, QVector<QVector<QString>>> map_forAttndnce) {

	//����cbx�ؼ�����
	for (auto i = cbx.begin(); i != cbx.end(); ++i) {
		delete (*i); *i = NULL;
	}
	cbx.clear();

	//����lbl�ؼ�����
	for (auto i = lbl.begin(); i != lbl.end(); ++i) {
		delete (*i); *i = NULL;
	}
	lbl.clear();

	//��� ���һ���� ��Ϣ/���/����
	labelShow->clear();

	for (int j = 0; j < NUM_DEPARTMENT; ++j) {
		int num = -1;
		QComboBox* cbx_temp_too = NULL;
		QStandardItemModel* qItemModel = NULL;
		QLabel* lbl_temp_too = NULL;
		QString dep = "";
		switch (j)
		{
		case 0:dep = "��Ŀ����"; break;
		case 1:dep = "������"; break;
		case 2:dep = "�ͷ���"; break;
		case 3:dep = "���̲�"; break;
		case 4:dep = "����ά����"; break;
		case 5:dep = "�������̻�"; break;
		case 6:dep = "����������"; break;
		case 7:dep = "���ڲ�"; break;
		default:break;
		}

		int height_lbl = 44;
		int height_cbx = 42;
		//�ж�widget�����Ƿ���
		if (2 + 80 * map_forAttndnce[dep].size() >= widget[j]->size().width()) {
			widget[j]->resize(2 + 80 * map_forAttndnce[dep].size(), 76);
			height_lbl = 36;
			height_cbx = 38;
		}
		else {
			widget[j]->resize(1334, 88);
		}

		for (auto it = map_forAttndnce[dep].cbegin(); it != map_forAttndnce[dep].cend(); ++it) {
			++num;

			//����comboBox�ؼ�
			cbx_temp_too = new QComboBox(widget[j]);
			qItemModel = qobject_cast<QStandardItemModel*>(cbx_temp_too->model());
			cbx_temp_too->setGeometry(1 + 80 * num, height_lbl + 1, 80, height_cbx);
			cbx_temp_too->setFrame(false);
			cbx_temp_too->setFocusPolicy(Qt::FocusPolicy::NoFocus);
			cbx_temp_too->setFont(QFont("����", 9));
			cbx_temp_too->addItem("");     //0
			cbx_temp_too->addItem("�װ�"); //1
			cbx_temp_too->addItem("���"); //2
			cbx_temp_too->addItem("�Ӱ�"); //3
			cbx_temp_too->addItem("����"); //4
			cbx_temp_too->addItem("����"); //5
			cbx_temp_too->addItem("��Ϣ"); //6
			cbx_temp_too->addItem("���"); //7 
			cbx_temp_too->addItem("����"); //8
			qItemModel->item(NONE_STATE)->setBackground(Qt::GlobalColor::darkRed);
			qItemModel->item(�װ�)->setForeground(Qt::GlobalColor::darkGreen);
			qItemModel->item(���)->setForeground(Qt::GlobalColor::darkGreen);
			qItemModel->item(�Ӱ�)->setForeground(Qt::GlobalColor::darkGreen);
			qItemModel->item(����)->setForeground(Qt::GlobalColor::darkYellow);
			qItemModel->item(����)->setForeground(Qt::GlobalColor::darkYellow);
			qItemModel->item(��Ϣ)->setForeground(Qt::GlobalColor::darkYellow);
			qItemModel->item(���)->setForeground(Qt::GlobalColor::darkYellow);
			qItemModel->item(����)->setForeground(Qt::GlobalColor::darkRed);
			cbx_temp_too->setStyleSheet(QString::fromUtf8(" QComboBox {"
				"      border: 1px solid gray;"
				"      border-radius: 3px;"
				"      padding: 1px 0px 1px 3px;"
				"  }"
				"QComboBox:!editable, QComboBox::drop-down:editable {"
				"       background: rgb(255, 255, 191);"
				"  }"
				"  QComboBox:!editable:on, QComboBox::drop-down:editable:on {"
				"      background: rgb(255, 255, 191);"
				"  }"
				"  QComboBox:on {"
				"      padding-top: 3px;"
				"      padding-left: 4px;"
				"  }"
				"  QComboBox::drop-down {"
				"      subcontrol-origin: padding;"
				"      subcontrol-position: top right;"
				"      border-top-right-radius: 3px;"
				"      border-bottom-right-radius: 3px;"
				"  }"
			));
			cbx.push_back(cbx_temp_too);
			cbx_temp_too->show();

			//cbx����ɫ�仯
			connect(cbx_temp_too, SIGNAL(currentIndexChanged(int)), this, SLOT(onsig_tempCbxIndexChange(int)));
			cbx_temp_too->setCurrentIndex((*it)[1].toInt());

			//����label�ؼ�
			lbl_temp_too = new QLabel(widget[j]);
			lbl_temp_too->setGeometry(1 + 80 * num, 1, 80, height_lbl);
			lbl_temp_too->setFrameShape(QFrame::Shape::StyledPanel);
			lbl_temp_too->setFont(QFont("����", 9));
			lbl_temp_too->setAlignment(Qt::Alignment::enum_type::AlignHCenter | Qt::Alignment::enum_type::AlignVCenter);
			lbl_temp_too->setStyleSheet("background-color: rgb(236, 255, 217);border:1px solid grey;");
			lbl_temp_too->setText((*it)[0]);
			lbl.push_back(lbl_temp_too);
			lbl_temp_too->show();

			//���һ���� ��Ϣ/���/����
			if (cbx_temp_too->currentIndex() == ��Ϣ || cbx_temp_too->currentIndex() == ��� || cbx_temp_too->currentIndex() == ����) {
				labelShow->setText(labelShow->text() + lbl_temp_too->text() + " ");
			}
		}
	}

}

void WidgetPBCQ::receiveScheduleData(QMap<QString, QVector<QVector<QString>>> map_forSchedule) {

	//���
	qItemModel->clear();
	v_flagForCbx.clear();

	//�ͷ��ڴ�
	v_item.clear();

	for (auto it = v_btn.begin(); it != v_btn.end(); ++it) {
		delete (*it);
		*it = NULL;
	}
	v_btn.clear();

	for (auto it = v_v_checkBox.begin(); it != v_v_checkBox.end(); ++it) {
		for (auto it2 = it->begin(); it2 != it->end(); ++it2) {
			delete (*it2);
			*it2 = NULL;
		}
	}
	v_v_checkBox.clear();

	for (auto it = v_layout.begin(); it != v_layout.end(); ++it) {
		delete (*it);
		*it = NULL;
	}
	v_layout.clear();

	for (auto it = v_widget.begin(); it != v_widget.end(); ++it) {
		delete (*it);
		*it = NULL;
	}
	v_widget.clear();

	QStandardItem* item = NULL;
	int day_max_of_selectedMonth = dateClass.getDayMaxOfMonth(date.year.toInt(), comboBoxMonth->currentIndex() + 1);
	int weekOf1st = dateClass.getWeekOfMonth(date.year.toInt(), comboBoxMonth->currentIndex() + 1);
	item = new QStandardItem("����");
	qItemModel->setHorizontalHeaderItem(0, item);
	v_item.push_back(item);
	item = new QStandardItem("����");
	qItemModel->setHorizontalHeaderItem(1, item);
	v_item.push_back(item);
	int week_temp = weekOf1st;
	int i = 1;
	for (; i <= day_max_of_selectedMonth; ++i) {
		v_flagForCbx.push_back(0);
		if (week_temp > 7)
			week_temp = week_temp % 7;
		switch (week_temp)
		{
		case 1:item = new QStandardItem(QString("%1\n��һ").arg(QString::number(i))); break;
		case 2:item = new QStandardItem(QString("%1\n�ܶ�").arg(QString::number(i))); break;
		case 3:item = new QStandardItem(QString("%1\n����").arg(QString::number(i))); break;
		case 4:item = new QStandardItem(QString("%1\n����").arg(QString::number(i))); break;
		case 5:item = new QStandardItem(QString("%1\n����").arg(QString::number(i))); break;
		case 6:item = new QStandardItem(QString("%1\n����").arg(QString::number(i))); item->setForeground(QColor(255, 0, 0)); break;
		case 7:item = new QStandardItem(QString("%1\n����").arg(QString::number(i))); item->setForeground(QColor(255, 0, 0)); break;
		default:break;
		}
		qItemModel->setHorizontalHeaderItem(i + 1, item);
		v_item.push_back(item);
		++week_temp;
	}
	item = new QStandardItem("");
	qItemModel->setHorizontalHeaderItem(i + 1, item);
	v_item.push_back(item);

	tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);//���ù̶��п�
	tableView->setColumnWidth(1, 120);
	tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
	tableView->setColumnWidth(0, 75);

	int num_col = tableView->horizontalHeader()->count();
	QString dep = "";
	int num_row = -1;

	QVector<QCheckBox*> v_checkBox;
	QCheckBox* cb = NULL;
	QWidget* widget = NULL;
	QHBoxLayout* layout = NULL;
	QPushButton* btnSelectAll = NULL;
	for (int i = 0; i < NUM_DEPARTMENT; ++i) {
		switch (i)
		{
		case 0:dep = "��Ŀ����"; break;
		case 1:dep = "������"; break;
		case 2:dep = "�ͷ���"; break;
		case 3:dep = "���̲�"; break;
		case 4:dep = "����ά����"; break;
		case 5:dep = "�������̻�"; break;
		case 6:dep = "����������"; break;
		case 7:dep = "���ڲ�"; break;
		default:break;
		}
		for (auto it = map_forSchedule[dep].cbegin(); it != map_forSchedule[dep].cend(); ++it) {
			num_row++;

			item = new QStandardItem(QString("%1").arg((*it)[0]));
			qItemModel->setItem(num_row, 0, item);
			qItemModel->item(num_row, 0)->setFont(QFont("����", 8));
			qItemModel->item(num_row, 0)->setTextAlignment(Qt::Alignment::enum_type::AlignCenter);
			v_item.push_back(item);

			item = new QStandardItem(QString("%1").arg(dep));
			qItemModel->setItem(num_row, 1, item);
			qItemModel->item(num_row, 1)->setFont(QFont("����", 7));
			qItemModel->item(num_row, 1)->setTextAlignment(Qt::Alignment::enum_type::AlignCenter);
			v_item.push_back(item);

			//������ѡ��
			int week_temp2 = weekOf1st;
			for (int i = 2; i < num_col - 1; ++i) {
				if (week_temp2 > 7)
					week_temp2 = week_temp2 % 7;
				cb = new QCheckBox(this);
				widget = new QWidget(this);
				layout = new QHBoxLayout(tab_2);
				if (week_temp2 == 7 || week_temp2 == 6) {
					widget->setStyleSheet("background-color: rgba(255, 185, 175, 122);");
				}
				//ע�⣺checked��2��unchecked��0
				cb->setCheckState(Qt::CheckState((*it)[i - 1].toInt()));
				layout->addWidget(cb);
				layout->setMargin(0);
				layout->setAlignment(cb, Qt::AlignCenter);
				widget->setLayout(layout);
				tableView->setIndexWidget(qItemModel->index(num_row, i), widget);
				v_checkBox.push_back(cb);
				v_layout.push_back(layout);
				v_widget.push_back(widget);

				++week_temp2;
			}
			v_v_checkBox.push_back(v_checkBox);

			btnSelectAll = new QPushButton(this);
			btnSelectAll->setText("ȫѡ");
			btnSelectAll->setCursor(Qt::CursorShape::PointingHandCursor);
			btnSelectAll->setFont(QFont("����", 8));
			btnSelectAll->setStyleSheet(
				"QPushButton{border: 0px;color: rgb(52, 0, 79);}"
				"QPushButton:hover{color: red;text-decoration:underline;}");
			connect(btnSelectAll, &QPushButton::clicked, [=] {
				if (btnSelectAll->text() == "ȫѡ") {
					for (auto it = v_checkBox.begin(); it != v_checkBox.end(); ++it) {
						(*it)->setCheckState(Qt::CheckState::Checked);
					}
					btnSelectAll->setText("����");
				}
				else if (btnSelectAll->text() == "����") {
					for (auto it = v_checkBox.begin(); it != v_checkBox.end(); ++it) {
						(*it)->setCheckState(Qt::CheckState::Unchecked);
					}
					btnSelectAll->setText("ȫѡ");
				}
				});

			v_checkBox.clear();

			tableView->setIndexWidget(qItemModel->index(num_row, num_col - 1), btnSelectAll);
			v_btn.push_back(btnSelectAll);

			tableView->verticalHeader()->setSectionResizeMode(num_row, QHeaderView::Fixed);//���ù̶��и�
			tableView->setRowHeight(num_row, 30);
		}
	}
}

void WidgetPBCQ::onsectionDoubleClicked(int logicalIndex) {

	if (logicalIndex == 0 || logicalIndex == 1 || logicalIndex == tableView->horizontalHeader()->count() - 1)
		return;

	if (v_flagForCbx[logicalIndex - 2] == 0) {
		for (auto it = v_v_checkBox.begin(); it != v_v_checkBox.end(); ++it) {
			(*it)[logicalIndex - 2]->setCheckState(Qt::CheckState::Unchecked);
		}
		v_flagForCbx[logicalIndex - 2] = 1;
	}
	else if (v_flagForCbx[logicalIndex - 2] == 1) {
		for (auto it = v_v_checkBox.begin(); it != v_v_checkBox.end(); ++it) {
			(*it)[logicalIndex - 2]->setCheckState(Qt::CheckState::Checked);
		}
		v_flagForCbx[logicalIndex - 2] = 0;
	}

}

void WidgetPBCQ::onsig_tempCbxIndexChange(int index) {

	QObject* obj = this->sender();
	QComboBox* cbx_temp_too = qobject_cast<QComboBox*>(obj);

	switch (index)
	{
	case �װ�:case ���:case �Ӱ�:
		cbx_temp_too->setStyleSheet(QString::fromUtf8(" QComboBox {"
			"      border: 1px solid gray;"
			"      color: darkgreen;"
			"      border-radius: 3px;"
			"      padding: 1px 0px 1px 3px;"
			"  }"
			"QComboBox:!editable, QComboBox::drop-down:editable {"
			"       background: rgb(255, 255, 191);"
			"  }"
			"  QComboBox:!editable:on, QComboBox::drop-down:editable:on {"
			"      background: rgb(255, 255, 191);"
			"  }"
			"  QComboBox:on {"
			"      padding-top: 3px;"
			"      padding-left: 4px;"
			"  }"
			"  QComboBox::drop-down {"
			"      subcontrol-origin: padding;"
			"      subcontrol-position: top right;"
			"      border-top-right-radius: 3px;"
			"      border-bottom-right-radius: 3px;"
			"  }"
		));
		break;
	case ����:case ����:case ��Ϣ:case ���:
		cbx_temp_too->setStyleSheet(QString::fromUtf8(" QComboBox {"
			"      border: 1px solid gray;"
			"      color: rgb(128,128,0);"
			"      border-radius: 3px;"
			"      padding: 1px 0px 1px 3px;"
			"  }"
			"QComboBox:!editable, QComboBox::drop-down:editable {"
			"       background: rgb(255, 255, 191);"
			"  }"
			"  QComboBox:!editable:on, QComboBox::drop-down:editable:on {"
			"      background: rgb(255, 255, 191);"
			"  }"
			"  QComboBox:on {"
			"      padding-top: 3px;"
			"      padding-left: 4px;"
			"  }"
			"  QComboBox::drop-down {"
			"      subcontrol-origin: padding;"
			"      subcontrol-position: top right;"
			"      border-top-right-radius: 3px;"
			"      border-bottom-right-radius: 3px;"
			"  }"
		));
		break;
	case ����:
		cbx_temp_too->setStyleSheet(QString::fromUtf8(" QComboBox {"
			"      border: 1px solid gray;"
			"      color: darkred;"
			"      border-radius: 3px;"
			"      padding: 1px 0px 1px 3px;"
			"  }"
			"QComboBox:!editable, QComboBox::drop-down:editable {"
			"       background: rgb(255, 255, 191)"
			"  }"
			"  QComboBox:!editable:on, QComboBox::drop-down:editable:on {"
			"      background: rgb(255, 255, 191)"
			"  }"
			"  QComboBox:on {"
			"      padding-top: 3px;"
			"      padding-left: 4px;"
			"  }"
			"  QComboBox::drop-down {"
			"      subcontrol-origin: padding;"
			"      subcontrol-position: top right;"
			"      border-top-right-radius: 3px;"
			"      border-bottom-right-radius: 3px;"
			"  }"
		));
		break;
	default:break;
	}

}