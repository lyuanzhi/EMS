#include "widgetwzgl.h"

WidgetWZGL::WidgetWZGL(QWidget* parent)
	: QWidget(parent)
{
	setAttribute(Qt::WA_DeleteOnClose);
	this->setObjectName(QString::fromUtf8("WidgetWZGL"));
	this->resize(1920, 1000);
	QMetaObject::connectSlotsByName(this);

	date = dateClass.getCurrentDate();

	tabWidget = new QTabWidget(this);
	tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
	tabWidget->setGeometry(QRect(0, 0, 1920, 1000));
	tabWidget->setFont(QFont("方正行楷简体", 14));

	tab = new QWidget();
	tab->setObjectName(QString::fromUtf8("tab"));
	tab->setStyleSheet(QString::fromUtf8("background-color: rgb(239, 237, 255);"));

	tab_2 = new QWidget();
	tab_2->setObjectName(QString::fromUtf8("tab_2"));
	tab_2->setStyleSheet(QString::fromUtf8("background-color: rgb(239, 237, 255);"));

	tab_3 = new QWidget();
	tab_3->setObjectName(QString::fromUtf8("tab_3"));
	tab_3->setStyleSheet(QString::fromUtf8("background-color: rgb(239, 237, 255);"));

	tab_4 = new QWidget();
	tab_4->setObjectName(QString::fromUtf8("tab_4"));
	tab_4->setStyleSheet(QString::fromUtf8("background-color: rgb(239, 237, 255);"));

	tab_5 = new QWidget();
	tab_5->setObjectName(QString::fromUtf8("tab_5"));
	tab_5->setStyleSheet(QString::fromUtf8("background-color: rgb(239, 237, 255);"));

	widgetLeft = new QWidget(tab);
	widgetLeft->setObjectName(QString::fromUtf8("widgetLeft"));
	widgetLeft->setGeometry(QRect(0, 0, 360, 970));
	widgetLeft->setStyleSheet(QString::fromUtf8("background-color: rgb(239, 237, 255);"));

	widgetRight = new QWidget(tab);
	widgetRight->setObjectName(QString::fromUtf8("widgetRight"));
	widgetRight->setGeometry(QRect(363, 0, 1557, 970));
	widgetRight->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 239, 171);"));

	QStringList qStringList;
	qStringList << "采购申请单号" << "状态" << "查看";
	tableView = new QTableView(widgetLeft);
	tableView->setObjectName(QString::fromUtf8("tableView"));
	qItemModel_2 = new QStandardItemModel(tab_2);
	tableView->setGeometry(QRect(5, 525, 350, 420));
	tableView->setFocusPolicy(Qt::FocusPolicy::NoFocus);
	qItemModel_2->setHorizontalHeaderLabels(qStringList);
	tableView->horizontalHeader()->setFont(QFont("宋体", 7));
	tableView->horizontalHeader()->setFixedHeight(35);
	tableView->setModel(qItemModel_2);
	tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
	tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
	tableView->setColumnWidth(1, 70);
	tableView->setColumnWidth(2, 55);
	tableView->verticalHeader()->setVisible(false);
	tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
	tableView->verticalHeader()->setMinimumSectionSize(30);
	tableView->verticalHeader()->setMaximumSectionSize(30);
	tableView->verticalHeader()->setDefaultSectionSize(30);
	tableView->setGridStyle(Qt::PenStyle::DashDotDotLine);
	tableView->setAttribute(Qt::WA_StyledBackground);
	tableView->setStyleSheet(QString::fromUtf8("background-color: rgb(239, 237, 255);"));
	tableView->verticalScrollBar()->setStyleSheet("QScrollBar:vertical{"//垂直滑块整体  
		"width:15px;"          //宽度
		"background:#FFFFFF;"  //背景色  
		"padding-top:5px;"     //上预留位置（放置向上箭头）  
		"padding-bottom:5px;"  //下预留位置（放置向下箭头）  
		"padding-left:1px;"    //左预留位置（美观）  
		"padding-right:1px;"   //右预留位置（美观）  
		"border-left:0px;}"    //左分割线  
		"QScrollBar::handle:vertical{"//滑块样式  
		"background:url(Resources/aurora1.png) center no-repeat;"  //滑块颜色  
		"border-radius:6px;"   //边角圆润  
		"min-height:80px;}"    //滑块最小高度  
		"QScrollBar::handle:vertical:hover{"//鼠标触及滑块样式  
		"background:url(Resources/aurora2.png) center no-repeat;}" //滑块颜色  
		"QScrollBar::add-line:vertical{"//向下箭头样式  
		"background:url() center no-repeat;}"
		"QScrollBar::sub-line:vertical{"//向上箭头样式  
		"background:url() center no-repeat;}");

	comboBoxPro = new QComboBox(widgetLeft);
	comboBoxPro->addItem(QString("公司总部"));
	comboBoxPro->addItem(QString("文鼎公寓"));
	comboBoxPro->addItem(QString("望湖家园"));
	comboBoxPro->addItem(QString("金城一区"));
	comboBoxPro->addItem(QString("江南小区"));
	comboBoxPro->addItem(QString("东方国际村"));
	comboBoxPro->addItem(QString("嘉鸿华庭"));
	comboBoxPro->addItem(QString("阳光都市"));
	comboBoxPro->addItem(QString("银河证券"));
	comboBoxPro->addItem(QString("春晗公寓"));
	comboBoxPro->addItem(QString("文化旅游局"));
	comboBoxPro->addItem(QString("中厦国际保安"));
	comboBoxPro->setObjectName(QString::fromUtf8("comboBoxPro"));
	comboBoxPro->setGeometry(QRect(60, 50, 240, 50));
	comboBoxPro->setFont(QFont("宋体", 12));
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
	QStandardItemModel* qItemModel = NULL;
	qItemModel = qobject_cast<QStandardItemModel*>(comboBoxPro->model());
	for (int i = 0; i < 12; ++i) {
		qItemModel->item(i)->setBackground(QBrush(QColor(211, 211, 255)));
	}

	btnCreate = new QPushButton(widgetLeft);
	btnCreate->setObjectName(QString::fromUtf8("btnCreate"));
	btnCreate->setGeometry(QRect(0, 150, 360, 65));
	btnCreate->setFont(QFont("宋体", 12));
	btnCreate->setText("新建采购申请单  ");
	QIcon iconadd;
	iconadd.addFile(QString::fromUtf8("Resources/addnewpage.png"), QSize(35, 35), QIcon::Normal, QIcon::Off);
	btnCreate->setIcon(iconadd);
	btnCreate->setStyleSheet(
		"QPushButton{background-color: rgba(255, 255, 255, 0);color: rgb(80, 80, 121); border: 0px;}"
		"QPushButton:hover{background-color: rgba(255, 255, 255, 153);}"
		"QPushButton:pressed{background-color: rgba(255, 255, 255, 230);}"
	);

	btnImport = new QPushButton(widgetLeft);
	btnImport->setObjectName(QString::fromUtf8("btnImport"));
	btnImport->setGeometry(QRect(0, 215, 360, 65));
	btnImport->setFont(QFont("宋体", 12));
	btnImport->setText("导入Excel文件   ");
	QIcon iconimport;
	iconimport.addFile(QString::fromUtf8("Resources/import.png"), QSize(35, 35), QIcon::Normal, QIcon::Off);
	btnImport->setIcon(iconimport);
	btnImport->setStyleSheet(
		"QPushButton{background-color: rgba(255, 255, 255, 0);color: rgb(80, 80, 121); border: 0px;}"
		"QPushButton:hover{background-color: rgba(255, 255, 255, 153);}"
		"QPushButton:pressed{background-color: rgba(255, 255, 255, 230);}"
	);

	btnClose = new QPushButton(widgetLeft);
	btnClose->setObjectName(QString::fromUtf8("btnClose"));
	btnClose->setGeometry(QRect(0, 280, 360, 65));
	btnClose->setFont(QFont("宋体", 12));
	btnClose->setText("关闭当前采购单  ");
	QIcon iconclose;
	iconclose.addFile(QString::fromUtf8("Resources/close.png"), QSize(35, 35), QIcon::Normal, QIcon::Off);
	btnClose->setIcon(iconclose);
	btnClose->setStyleSheet(
		"QPushButton{background-color: rgba(255, 255, 255, 0);color: rgb(80, 80, 121); border: 0px;}"
		"QPushButton:hover{background-color: rgba(255, 255, 255, 153);}"
		"QPushButton:pressed{background-color: rgba(255, 255, 255, 230);}"
	);

	labelSearch = new QLabel(widgetLeft);
	labelSearch->setObjectName(QString::fromUtf8("labelSearch"));
	labelSearch->setGeometry(QRect(0, 370, 360, 40));
	labelSearch->setFont(QFont("宋体", 13));
	labelSearch->setAlignment(Qt::AlignCenter);
	labelSearch->setText("历史表单记录");

	labelTime = new QLabel(widgetLeft);
	labelTime->setObjectName(QString::fromUtf8("labelTime"));
	labelTime->setGeometry(QRect(18, 430, 65, 30));
	labelTime->setFont(QFont("宋体", 10));
	labelTime->setText("时间：");

	labelYear = new QLabel(widgetLeft);
	labelYear->setObjectName(QString::fromUtf8("labelYear"));
	labelYear->setGeometry(QRect(142, 430, 25, 30));
	labelYear->setFont(QFont("Arial", 9));
	labelYear->setText(QString("年"));
	labelYear->setStyleSheet("background-color: rgb(255, 255, 255);");

	lineYear = new QLineEdit(widgetLeft);
	lineYear->setObjectName(QString::fromUtf8("lineYear"));
	lineYear->setGeometry(QRect(85, 430, 57, 30));
	lineYear->setFont(QFont("Arial", 9));
	lineYear->setText(QString("%1").arg(date.year));
	lineYear->setValidator(new QIntValidator(0, 9999, this));
	lineYear->setStyleSheet("background-color: rgb(255, 255, 255);border: 0px;");

	comboBoxMonth = new QComboBox(widgetLeft);
	comboBoxMonth->addItem(QString("01月"));
	comboBoxMonth->addItem(QString("02月"));
	comboBoxMonth->addItem(QString("03月"));
	comboBoxMonth->addItem(QString("04月"));
	comboBoxMonth->addItem(QString("05月"));
	comboBoxMonth->addItem(QString("06月"));
	comboBoxMonth->addItem(QString("07月"));
	comboBoxMonth->addItem(QString("08月"));
	comboBoxMonth->addItem(QString("09月"));
	comboBoxMonth->addItem(QString("10月"));
	comboBoxMonth->addItem(QString("11月"));
	comboBoxMonth->addItem(QString("12月"));
	comboBoxMonth->setObjectName(QString::fromUtf8("comboBoxMonth"));
	comboBoxMonth->setGeometry(QRect(167, 430, 87, 30));
	comboBoxMonth->setFont(QFont("Arial"));
	comboBoxMonth->setFocusPolicy(Qt::NoFocus);
	comboBoxMonth->setMaxVisibleItems(12);
	comboBoxMonth->setStyleSheet(QString::fromUtf8(" QComboBox {"
		"      border: 0px;"
		"      padding: 1px 0px 1px 3px;"
		"      background-color: rgb(255, 255, 255);"
		"  }"
		"  QComboBox:on {"
		"      padding-top: 3px;"
		"      padding-left: 4px;"
		"  }"
		"  QComboBox::drop-down {"
		"      subcontrol-origin: padding;"
		"      subcontrol-position: top right;"
		"      width: 30px;"
		"      background-color: rgba(0, 0, 0, 0);"
		"      border: 0px;"
		"  }"
		"QComboBox::down-arrow{"
		"image: url(Resources/下拉.png);"
		"  }"
		"QComboBox::down-arrow:hover{"
		"background-color: rgba(0, 0, 0, 26);"
		"  }"
	));
	comboBoxMonth->setFrame(false);
	comboBoxMonth->setCurrentIndex(date.month.toInt() - 1);
	qItemModel = qobject_cast<QStandardItemModel*>(comboBoxMonth->model());
	for (int i = 0; i < 12; ++i) {
		qItemModel->item(i)->setBackground(Qt::GlobalColor::white);
	}

	labelState = new QLabel(widgetLeft);
	labelState->setObjectName(QString::fromUtf8("labelState"));
	labelState->setGeometry(QRect(18, 480, 65, 30));
	labelState->setFont(QFont("宋体", 10));
	labelState->setText("状态：");

	comboBoxState = new QComboBox(widgetLeft);
	comboBoxState->addItem(QString("全部"));
	comboBoxState->addItem(QString("待审核"));
	comboBoxState->addItem(QString("一审"));
	comboBoxState->addItem(QString("二审"));
	comboBoxState->addItem(QString("三审"));
	comboBoxState->addItem(QString("已采购"));
	comboBoxState->addItem(QString("已领用"));
	comboBoxState->addItem(QString("驳回"));
	comboBoxState->setObjectName(QString::fromUtf8("comboBoxState"));
	comboBoxState->setGeometry(QRect(85, 480, 120, 30));
	comboBoxState->setFont(QFont("宋体", 10));
	comboBoxState->setFocusPolicy(Qt::NoFocus);
	comboBoxState->setMaxVisibleItems(8);
	comboBoxState->setStyleSheet(QString::fromUtf8(" QComboBox {"
		"      border: 0px;"
		"      padding: 1px 0px 1px 3px;"
		"      background-color: rgb(255, 255, 255);"
		"  }"
		"  QComboBox:on {"
		"      padding-top: 3px;"
		"      padding-left: 4px;"
		"  }"
		"  QComboBox::drop-down {"
		"      subcontrol-origin: padding;"
		"      subcontrol-position: top right;"
		"      width: 30px;"
		"      background-color: rgba(0, 0, 0, 0);"
		"      border: 0px;"
		"  }"
		"QComboBox::down-arrow{"
		"image: url(Resources/下拉.png);"
		"}"
		"QComboBox::down-arrow:hover{"
		"background-color: rgba(0, 0, 0, 26);"
		"  }"
	));
	comboBoxState->setFrame(false);
	comboBoxState->setCurrentIndex(0);
	qItemModel = qobject_cast<QStandardItemModel*>(comboBoxState->model());
	for (int i = 0; i < 8; ++i) {
		qItemModel->item(i)->setBackground(Qt::GlobalColor::white);
	}

	btnSearch = new QPushButton(widgetLeft);
	btnSearch->setObjectName(QString::fromUtf8("btnSearch"));
	btnSearch->setGeometry(QRect(260, 455, 85, 50));
	btnSearch->setFont(QFont("宋体", 9));
	btnSearch->setStyleSheet(
		"QPushButton{background-color: rgba( 0, 0, 0, 0);border: 0px;border-radius: 20px;}"
		"QPushButton:hover{background-color: rgba(255, 255, 255, 153);}"
		"QPushButton:pressed{background-color: rgba(255, 255, 255, 77);}"
	);
	QIcon icon1;
	icon1.addFile(QString::fromUtf8("Resources/search.png"), QSize(), QIcon::Normal, QIcon::Off);
	btnSearch->setIcon(icon1);
	btnSearch->setIconSize(QSize(25, 25));
	btnSearch->setText("查询");

	labelTitle = new QLabel(widgetRight);
	labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
	labelTitle->setGeometry(QRect(479, 15, 600, 60));
	QFont font2;
	font2.setFamily(QString::fromUtf8("楷体"));
	font2.setPointSize(18);
	font2.setBold(true);
	labelTitle->setFont(font2);
	labelTitle->setAlignment(Qt::AlignCenter);
	labelTitle->setText("XXXX物资采购申请单");

	labelPro_2 = new QLabel(widgetRight);
	labelPro_2->setObjectName(QString::fromUtf8("labelPro_2"));
	labelPro_2->setGeometry(QRect(40, 105, 80, 30));
	labelPro_2->setFont(QFont("宋体", 12));
	labelPro_2->setText("项目：");

	linePro = new QLineEdit(widgetRight);
	linePro->setObjectName(QString::fromUtf8("linePro"));
	linePro->setGeometry(QRect(120, 100, 230, 40));
	linePro->setFont(QFont("宋体", 11));
	linePro->setStyleSheet("background-color: rgb(255, 255, 255);");

	labelApplyDate = new QLabel(widgetRight);
	labelApplyDate->setObjectName(QString::fromUtf8("labelApplyDate"));
	labelApplyDate->setGeometry(QRect(380, 105, 145, 30));
	labelApplyDate->setFont(QFont("宋体", 12));
	labelApplyDate->setText("申请日期：");

	calendarWidget = new QCalendarWidget(widgetRight);
	calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
	calendarWidget->setEnabled(true);
	calendarWidget->setFont(QFont("宋体", 8));
	calendarWidget->setFocusPolicy(Qt::NoFocus);
	calendarWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
	calendarWidget->setGridVisible(true);
	calendarWidget->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
	calendarWidget->setDateEditEnabled(false);
	QToolButton* prevBtn = calendarWidget->findChild<QToolButton*>(QLatin1String("qt_calendar_prevmonth"));
	QToolButton* nextBtn = calendarWidget->findChild<QToolButton*>(QLatin1String("qt_calendar_nextmonth"));
	QToolButton* yearBtn = calendarWidget->findChild<QToolButton*>(QLatin1String("qt_calendar_yearbutton"));
	QToolButton* monthBtn = calendarWidget->findChild<QToolButton*>(QLatin1String("qt_calendar_monthbutton"));
	QIcon icon2;
	icon2.addFile(QString::fromUtf8("Resources/prev.png"), QSize(), QIcon::Normal, QIcon::Off);
	QIcon icon3;
	icon3.addFile(QString::fromUtf8("Resources/next.png"), QSize(), QIcon::Normal, QIcon::Off);
	prevBtn->setIcon(icon2);
	nextBtn->setIcon(icon3);
	yearBtn->setStyleSheet("color: rgb(0, 0, 0);");
	monthBtn->setStyleSheet("QToolButton{color: rgb(0, 0, 0);}QToolButton::menu-indicator{image:none;}");

	dateEditApplyDate = new QDateEdit(widgetRight);
	dateEditApplyDate->setObjectName(QString::fromUtf8("dateEditApplyDate"));
	dateEditApplyDate->setGeometry(QRect(525, 100, 165, 40));
	dateEditApplyDate->setFont(QFont("Arial", 9));
	dateEditApplyDate->setFocusPolicy(Qt::NoFocus);
	dateEditApplyDate->setCalendarPopup(true);
	dateEditApplyDate->setCalendarWidget(calendarWidget);
	dateEditApplyDate->setStyleSheet("background-color: rgb(255, 255, 255);");
	dateEditApplyDate->setDate(QDate::currentDate());

	labelApplyPerson = new QLabel(widgetRight);
	labelApplyPerson->setObjectName(QString::fromUtf8("labelApplyPerson"));
	labelApplyPerson->setGeometry(QRect(720, 105, 110, 30));
	labelApplyPerson->setFont(QFont("宋体", 12));
	labelApplyPerson->setText("申请人：");

	lineApplyPerson = new QLineEdit(widgetRight);
	lineApplyPerson->setObjectName(QString::fromUtf8("lineApplyPerson"));
	lineApplyPerson->setGeometry(QRect(830, 100, 140, 40));
	lineApplyPerson->setFont(QFont("宋体", 11));
	lineApplyPerson->setStyleSheet("background-color: rgb(255, 255, 255);");

	btnDelete = new QPushButton(widgetRight);
	btnDelete->setObjectName(QString::fromUtf8("btnDelete"));
	btnDelete->setGeometry(QRect(980, 95, 50, 50));
	QIcon icondelete;
	icondelete.addFile(QString::fromUtf8("Resources/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
	btnDelete->setIcon(icondelete);
	btnDelete->setStyleSheet(
		"QPushButton{background-color: rgba(255, 255, 255, 0);border: 0px;border-radius: 20px;}"
		"QPushButton:hover{background-color: rgba(255, 255, 255, 153);}"
		"QPushButton:pressed{background-color: rgba(255, 255, 255, 230);}"
	);
	btnDelete->hide();

	btnSave = new QPushButton(widgetRight);
	btnSave->setObjectName(QString::fromUtf8("btnSave"));
	btnSave->setGeometry(QRect(1190, 100, 85, 40));
	btnSave->setFont(QFont("宋体", 11));
	btnSave->setCursor(QCursor(Qt::PointingHandCursor));
	btnSave->setStyleSheet(QString::fromUtf8(
		"QPushButton{				             "
		"  background-color: rgb(254, 226, 255); "
		"  border-style: outset;				 "
		"  border-width: 1px;					 "
		"  border-radius: 15px;				     "
		"  border-color: grey;				     "
		"}										 "
		"QPushButton:hover{                      "
		"  background-color: rgb(254, 242, 255); "
		"}                                       "
		"QPushButton:pressed{		             "
		"  border-style: inset;				     "
		"  background-color: rgba(254, 242, 255, 128); "
		"}										 "
	));
	btnSave->setText("保存");

	btnSubmit = new QPushButton(widgetRight);
	btnSubmit->setObjectName(QString::fromUtf8("btnSubmit"));
	btnSubmit->setGeometry(QRect(1410, 100, 85, 40));
	btnSubmit->setFont(QFont("宋体", 11));
	btnSubmit->setCursor(QCursor(Qt::PointingHandCursor));
	btnSubmit->setStyleSheet(QString::fromUtf8(
		"QPushButton{				             "
		"  background-color: rgb(254, 226, 255); "
		"  border-style: outset;				 "
		"  border-width: 1px;					 "
		"  border-radius: 15px;				     "
		"  border-color: grey;				     "
		"}										 "
		"QPushButton:hover{                      "
		"  background-color: rgb(254, 242, 255); "
		"}                                       "
		"QPushButton:pressed{		             "
		"  border-style: inset;				     "
		"  background-color: rgba(254, 242, 255, 128); "
		"}										 "
	));
	btnSubmit->setText("提交");
	btnSubmit->setEnabled(false);

	btnPrint = new QPushButton(widgetRight);
	btnPrint->setObjectName(QString::fromUtf8("btnPrint"));
	btnPrint->setGeometry(QRect(1300, 100, 85, 40));
	btnPrint->setFont(QFont("宋体", 11));
	btnPrint->setCursor(QCursor(Qt::PointingHandCursor));
	btnPrint->setStyleSheet(QString::fromUtf8(
		"QPushButton{				             "
		"  background-color: rgb(254, 226, 255); "
		"  border-style: outset;				 "
		"  border-width: 1px;					 "
		"  border-radius: 15px;				     "
		"  border-color: grey;				     "
		"}										 "
		"QPushButton:hover{                      "
		"  background-color: rgb(254, 242, 255); "
		"}                                       "
		"QPushButton:pressed{		             "
		"  border-style: inset;				     "
		"  background-color: rgba(254, 242, 255, 128); "
		"}										 "
	));
	btnPrint->setText("打印");

	labelRemind = new QLabel(widgetRight);
	labelRemind->setObjectName(QString::fromUtf8("labelRemind"));
	labelRemind->setGeometry(QRect(10, 150, 1530, 662));
	labelRemind->setFont(QFont("宋体", 30));
	labelRemind->setAlignment(Qt::Alignment::enum_type::AlignHCenter | Qt::Alignment::enum_type::AlignVCenter);
	labelRemind->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255); color: rgb(0, 200, 0);"));
	labelRemind->setFrameShape(QFrame::Shape::Box);
	labelRemind->setText("新建或打开采购申请单！");

	label[0] = new QLabel(widgetRight);
	label[0]->setObjectName(QString::fromUtf8("labelxmjl"));
	label[0]->setGeometry(QRect(100, 870, 140, 30));
	label[0]->setFont(QFont("宋体", 12));
	label[0]->setText("项目经理：");

	label[1] = new QLabel(widgetRight);
	label[1]->setObjectName(QString::fromUtf8("labelzhb"));
	label[1]->setGeometry(QRect(600, 870, 110, 30));
	label[1]->setFont(QFont("宋体", 12));
	label[1]->setText("综合部：");

	label[2] = new QLabel(widgetRight);
	label[2]->setObjectName(QString::fromUtf8("labelzjb"));
	label[2]->setGeometry(QRect(1100, 870, 110, 30));
	label[2]->setFont(QFont("宋体", 12));
	label[2]->setText("总经办：");

	myLabel[0] = new Mylabel(widgetRight);
	myLabel[0]->setObjectName(QString::fromUtf8("myLabelxmjl"));
	myLabel[0]->setGeometry(QRect(250, 830, 100, 100));
	myLabel[0]->setPixmap(QPixmap("Resources/waitforpass.png"));
	myLabel[0]->setEnabled(false);

	myLabel[1] = new Mylabel(widgetRight);
	myLabel[1]->setObjectName(QString::fromUtf8("myLabelzhb"));
	myLabel[1]->setGeometry(QRect(720, 830, 100, 100));
	myLabel[1]->setPixmap(QPixmap("Resources/waitforpass.png"));
	myLabel[1]->setEnabled(false);

	myLabel[2] = new Mylabel(widgetRight);
	myLabel[2]->setObjectName(QString::fromUtf8("myLabelzjb"));
	myLabel[2]->setGeometry(QRect(1220, 830, 100, 100));
	myLabel[2]->setPixmap(QPixmap("Resources/waitforpass.png"));
	myLabel[2]->setEnabled(false);

	widgetForBtnReject = NULL;

	for (int index = 0; index < 3; ++index) {
		lineEditPwd[index] = new MyLineEdit(widgetRight);
		lineEditPwd[index]->setObjectName(QString::fromUtf8("lineEditPwd%1").arg(QString::number(index)));
		lineEditPwd[index]->setGeometry(QRect(myLabel[index]->geometry().x() + myLabel[index]->geometry().width() + 10, 845, 180, 30));
		lineEditPwd[index]->setFont(QFont("Arial"));
		lineEditPwd[index]->setMaxLength(11);
		lineEditPwd[index]->setEchoMode(QLineEdit::Password);
		lineEditPwd[index]->hide();

		btnPass[index] = new QPushButton(widgetRight);
		btnPass[index]->setObjectName(QString::fromUtf8("btnPass%1").arg(QString::number(index)));
		btnPass[index]->setGeometry(QRect(myLabel[index]->geometry().x() + myLabel[index]->geometry().width() + 10, 885, 80, 30));
		btnPass[index]->setFont(QFont("宋体", 9));
		btnPass[index]->setCursor(QCursor(Qt::PointingHandCursor));
		btnPass[index]->setStyleSheet(QString::fromUtf8(
			"QPushButton{				             "
			"  background-color: rgb(239, 237, 255); "
			"  color: rgb(85, 170, 0);               "
			"  border-style: outset;				 "
			"  border-width: 2px;					 "
			"  border-radius: 10px;				     "
			"  border-color: grey;				     "
			"}										 "
			"QPushButton:hover{                      "
			"  background-color: rgb(250, 250, 250); "
			"}                                       "
			"QPushButton:pressed{		             "
			"  background-color: rgba(250, 250, 250, 128); "
			"  border-style: inset;				     "
			"}										 "
		));
		btnPass[index]->setText("通过");
		btnPass[index]->hide();

		btnReject[index] = new QPushButton(widgetRight);
		btnReject[index]->setObjectName(QString::fromUtf8("btnReject%1").arg(QString::number(index)));
		btnReject[index]->setGeometry(QRect(myLabel[index]->geometry().x() + myLabel[index]->geometry().width() + 110, 885, 80, 30));
		btnReject[index]->setFont(QFont("宋体", 9));
		btnReject[index]->setCursor(QCursor(Qt::PointingHandCursor));
		btnReject[index]->setStyleSheet(QString::fromUtf8(
			"QPushButton{				             "
			"  background-color: rgb(239, 237, 255); "
			"  color: rgb(255, 0, 0);                "
			"  border-style: outset;				 "
			"  border-width: 2px;					 "
			"  border-radius: 10px;				     "
			"  border-color: grey;				     "
			"}										 "
			"QPushButton:hover{                      "
			"  background-color: rgb(250, 250, 250); "
			"}                                       "
			"QPushButton:pressed{		             "
			"  background-color: rgba(250, 250, 250, 128); "
			"  border-style: inset;				     "
			"}										 "
		));
		btnReject[index]->setText("驳回");
		btnReject[index]->hide();

		btnUndo[index] = new QPushButton(widgetRight);
		btnUndo[index]->setObjectName(QString::fromUtf8("btnUndo%1").arg(QString::number(index)));
		btnUndo[index]->setGeometry(QRect(lineEditPwd[index]->geometry().x() - 30, 900, 55, 30));
		btnUndo[index]->setFont(QFont("宋体", 9));
		btnUndo[index]->setStyleSheet(
			"QPushButton{background-color: rgba( 0, 0, 0, 0);border: 0px;border-radius: 15px;color: rgb(170, 170, 255);}"
			"QPushButton:hover{background-color: rgba(255, 255, 255, 102);}"
			"QPushButton:pressed{background-color: rgba(255, 255, 255, 204);}"
		);
		btnUndo[index]->setText("撤销");
		btnUndo[index]->hide();

		labelName[index] = new QLabel(widgetRight);
		labelName[index]->setGeometry(QRect(lineEditPwd[index]->geometry().x() - 5, 865, 110, 30));
		labelName[index]->setFont(QFont("宋体", 12));
		labelName[index]->hide();

		connect(btnPass[index], &QAbstractButton::clicked, [=]
			{
				if (lineEditPwd[index]->text() != userInfo.user_password)
					return;
				QMessageBox box(QMessageBox::Question, "提示", "确认要通过吗？");
				box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
				box.setButtonText(QMessageBox::Ok, QString("确 定"));
				box.setButtonText(QMessageBox::Cancel, QString("取 消"));
				box.setWindowIcon(QPixmap("Resources/logo.png"));
				int button = box.exec();
				if (button != QMessageBox::Ok)
					return;
				flagForCheck[index] = 2;
				state = index + 2;
				myLabel[index]->setPixmap(QPixmap("Resources/pass.png"));
				lineEditPwd[index]->hide();
				btnPass[index]->hide();
				btnReject[index]->hide();
				if (index != 0) btnUndo[index - 1]->hide();
				btnUndo[index]->show();
				labelName[index]->setText(userInfo.user_real_name); labelName[index]->show();
				QString pro = ""; int count = 0;
				btnSubmit->setEnabled(false);
				emit sig_sendStateData(currentID, state, index, userInfo.user_real_name, QVector<QString>());
			});

		connect(btnReject[index], &QAbstractButton::clicked, [=]
			{
				if (lineEditPwd[index]->text() != userInfo.user_password)
					return;

				widgetForBtnReject = new QWidget();
				widgetForBtnReject->setWindowModality(Qt::ApplicationModal);
				widgetForBtnReject->setAttribute(Qt::WA_DeleteOnClose);
				widgetForBtnReject->setWindowIcon(QPixmap("Resources/logo.png"));
				widgetForBtnReject->setWindowTitle("驳回");
				widgetForBtnReject->setFixedSize(1600, 962);
				widgetForBtnReject->setStyleSheet(QString::fromUtf8("QWidget{background:url(Resources/bkgrdfreject.png) center no-repeat;}"));
				widgetForBtnReject->show();

				QLabel* temp_label = new QLabel(widgetForBtnReject);
				temp_label->setGeometry(QRect(60, 70, 800, 70));
				temp_label->setFont(QFont("宋体", 18));
				temp_label->setText("请在审批意见区写下您的意见：");
				temp_label->setStyleSheet("color: rgb(128, 0, 0);background-color: rgba(255, 255, 255, 0);");
				temp_label->show();

				QTableWidget* temp_table = new QTableWidget(widgetForBtnReject);
				temp_table->setGeometry(QRect(135, 150, 1330, 662));
				temp_table->setFont(QFont("宋体", 7));
				temp_table->setStyleSheet(
					"QTableWidget{background:url();background-color: rgb(224, 224, 224); gridline-color: rgb(0, 0, 0);}"
					"QTableWidget::item::selected{background:url();}"
				);
				temp_table->verticalScrollBar()->setStyleSheet("QScrollBar:vertical{"//垂直滑块整体  
					"width:15px;"          //宽度
					"background:#FFFFFF;"  //背景色  
					"padding-top:2px;"     //上预留位置（放置向上箭头）  
					"padding-bottom:2px;"  //下预留位置（放置向下箭头）  
					"padding-left:1px;"    //左预留位置（美观）  
					"padding-right:1px;"   //右预留位置（美观）  
					"border-left:0px;}"    //左分割线  
					"QScrollBar::handle:vertical{"//滑块样式  
					"background:url(Resources/aurora1_long.png) center no-repeat;"  //滑块颜色  
					"border-radius:6px;"   //边角圆润  
					"min-height:80px;}"    //滑块最小高度  
					"QScrollBar::handle:vertical:hover{"//鼠标触及滑块样式  
					"background:url(Resources/aurora2_long.png) center no-repeat;}" //滑块颜色  
					"QScrollBar::add-line:vertical{"//向下箭头样式  
					"background:url() center no-repeat;}"
					"QScrollBar::sub-line:vertical{"//向上箭头样式  
					"background:url() center no-repeat;}");
				temp_table->setFrameShape(QFrame::Shape::Box);
				temp_table->setEditTriggers(QAbstractItemView::CurrentChanged);//可写
				temp_table->setFocusPolicy(Qt::FocusPolicy::NoFocus);
				temp_table->verticalHeader()->hide();
				temp_table->horizontalHeader()->setFixedHeight(47);
				temp_table->setRowCount(v_v_forOpen_data.size());
				temp_table->setColumnCount(7);
				temp_table->setHorizontalHeaderLabels(QStringList() << "序号" << "物品名称" << "数量" << "单位"
					<< "型号规格" << "用途" << "审批意见");
				for (int i = 0; i < temp_table->rowCount(); ++i) {
					QTableWidgetItem* item = new QTableWidgetItem(QString::number(i + 1));
					temp_table->setItem(i, 0, item);
					item->setFlags(item->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
					temp_table->item(i, 0)->setForeground(QBrush(QColor(0, 0, 0)));
					temp_table->item(i, 0)->setTextAlignment(Qt::Alignment::enum_type::AlignCenter);
					for (int j = 1; j < 6; ++j) {
						temp_table->setItem(i, j, new QTableWidgetItem(""));
						temp_table->item(i, j)->setFlags(temp_table->item(i, j)->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
						temp_table->item(i, j)->setForeground(QBrush(QColor(0, 0, 0)));
					}
					temp_table->setItem(i, 6, new QTableWidgetItem(""));
					temp_table->item(i, 6)->setBackground(QBrush(QColor(255, 255, 255)));
					temp_table->setRowHeight(i, 47);
				}
				temp_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
				temp_table->horizontalHeader()->setSectionResizeMode(5, QHeaderView::Stretch);
				temp_table->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(22, 82, 173); color:rgb(240, 240, 240);}");
				temp_table->setColumnWidth(0, 70);
				temp_table->setColumnWidth(1, 250);
				temp_table->setColumnWidth(2, 80);
				temp_table->setColumnWidth(3, 80);
				temp_table->setColumnWidth(4, 200);
				temp_table->setColumnWidth(6, 400);
				temp_table->show();
				int rowIndex = 0;
				for (auto it = v_v_forOpen_data.cbegin(); it != v_v_forOpen_data.cend(); ++it) {
					for (int i = 1; i < 6; ++i) {
						temp_table->item(rowIndex, i)->setText((*it)[i]);
					}
					++rowIndex;
				}

				QPushButton* temp_btnY = new QPushButton(widgetForBtnReject);
				temp_btnY->setGeometry(QRect(1280, 852, 120, 50));
				temp_btnY->setFont(QFont("楷体", 12));
				temp_btnY->setStyleSheet(QString::fromUtf8(
					"QPushButton{				             "
					"  border-style: outset;				 "
					"  border-width: 2px;					 "
					"  border-radius: 10px;				     "
					"  border-color: grey;				     "
					"}										 "
					"QPushButton:hover{                      "
					"  background-color: rgba(255, 255, 255, 102);"
					"}                                       "
					"QPushButton:pressed{		             "
					"  border-style: inset;				     "
					"  background-color: rgba(255, 255, 255, 204);"
					"}										 "
				));
				temp_btnY->setText("提交");
				temp_btnY->show();
				QPushButton* temp_btnN = new QPushButton(widgetForBtnReject);
				temp_btnN->setGeometry(QRect(1425, 852, 120, 50));
				temp_btnN->setFont(QFont("楷体", 12));
				temp_btnN->setStyleSheet(QString::fromUtf8(
					"QPushButton{				             "
					"  border-style: outset;				 "
					"  border-width: 2px;					 "
					"  border-radius: 10px;				     "
					"  border-color: grey;				     "
					"}										 "
					"QPushButton:hover{"
					"  background-color: rgba(255, 255, 255, 102);"
					"}"
					"QPushButton:pressed{		             "
					"  border-style: inset;				     "
					"  background-color: rgba(255, 255, 255, 204);"
					"}										 "
				));
				temp_btnN->setText("取消");
				temp_btnN->show();

				connect(temp_btnN, &QPushButton::clicked, [=] {widgetForBtnReject->close(); });
				connect(temp_btnY, &QPushButton::clicked, [=]
					{
						int f = 0;
						for (int i = 0; i < temp_table->rowCount(); ++i) {
							if (!temp_table->item(i, 6)->text().isEmpty()) {
								f = 1;
								break;
							}
						}
						if (f == 0) {
							QMessageBox box(QMessageBox::Information, "提示", "审批意见不可为空！");
							box.setStandardButtons(QMessageBox::Ok);
							box.setButtonText(QMessageBox::Ok, QString("确 定"));
							box.setWindowIcon(QPixmap("Resources/logo.png"));
							int button = box.exec();
							return;
						}
						QMessageBox box(QMessageBox::Question, "提示", "确认要提交吗？");
						box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
						box.setButtonText(QMessageBox::Ok, QString("确 定"));
						box.setButtonText(QMessageBox::Cancel, QString("取 消"));
						box.setWindowIcon(QPixmap("Resources/logo.png"));
						int button = box.exec();
						if (button != QMessageBox::Ok)
							return;
						flagForCheck[index] = 2;
						state = State::驳回;
						myLabel[index]->setPixmap(QPixmap("Resources/fail.png"));
						lineEditPwd[index]->hide();
						btnPass[index]->hide();
						btnReject[index]->hide();
						if (index != 0) btnUndo[index - 1]->hide();
						btnUndo[index]->show();
						labelName[index]->setText(userInfo.user_real_name); labelName[index]->show();
						QString pro = ""; int count = 0;
						for (auto c : currentID) {
							if (c == '#' || c == '/') ++count;
							if (count == 0) pro += c;
						}
						if (pro == userInfo.xm) btnSubmit->setEnabled(true);
						QVector<QString> temp_advice;
						for (int i = 0; i < temp_table->rowCount(); ++i) {
							tableWidget->item(i, 6)->setText(temp_table->item(i, 6)->text());
							temp_advice.push_back(temp_table->item(i, 6)->text());
						}
						emit sig_sendStateData(currentID, state, index, userInfo.user_real_name, temp_advice);
						widgetForBtnReject->close();
					});
			});

		connect(btnUndo[index], &QAbstractButton::clicked, [=]
			{
				QMessageBox box(QMessageBox::Question, "提示", "确认要撤销吗？");
				box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
				box.setButtonText(QMessageBox::Ok, QString("确 定"));
				box.setButtonText(QMessageBox::Cancel, QString("取 消"));
				box.setWindowIcon(QPixmap("Resources/logo.png"));
				int button = box.exec();
				if (button != QMessageBox::Ok)
					return;
				state = index + 1;
				myLabel[index]->setPixmap(QPixmap("Resources/waitforpass.png"));
				flagForCheck[index] = 0;
				btnUndo[index]->hide();
				if (index != 0) btnUndo[index - 1]->show();
				if (index != 2) {
					lineEditPwd[index + 1]->hide();
					btnPass[index + 1]->hide();
					btnReject[index + 1]->hide();
					flagForCheck[index + 1] = 0;
				}
				labelName[index]->setText(""); labelName[index]->hide();
				QString pro = ""; int count = 0;
				for (auto c : currentID) {
					if (c == '#' || c == '/') ++count;
					if (count == 0) pro += c;
				}
				if (pro == userInfo.xm && state == State::待审核) btnSubmit->setEnabled(true);
				else btnSubmit->setEnabled(false);
				for (int i = 0; i < tableWidget->rowCount(); ++i) {
					tableWidget->item(i, 6)->setText("");
				}
				emit sig_sendStateData(currentID, state, index, "", QVector<QString>());
			});
	}

	tabWidget->setAttribute(Qt::WA_StyledBackground);
	tabWidget->addTab(tab, QString("  采购  "));
	tabWidget->addTab(tab_2, QString("  入库  "));
	tabWidget->addTab(tab_3, QString("  领用  "));
	tabWidget->addTab(tab_4, QString("  盘存  "));
	tabWidget->addTab(tab_5, QString("  报废  "));
	tabWidget->setCurrentIndex(0);
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

	tableWidget = NULL;
	btnAddRow = NULL;
	tableIsOpen = false;
	state = State::待审核;
	widgetForCostAndDate = NULL;
	flagForCheck[0] = 0; flagForCheck[1] = 0; flagForCheck[2] = 0;

	connect(comboBoxPro, &QComboBox::currentTextChanged, this, &WidgetWZGL::oncurrentTextChanged);
	connect(btnSearch, &QPushButton::clicked, [=]
		{emit sig_sendPurchaseData(comboBoxPro->currentText(), lineYear->text().toInt(),
			comboBoxMonth->currentText().mid(0, 2).toInt(), comboBoxState->currentIndex()); });

	connect(btnCreate, &QPushButton::clicked, this, &WidgetWZGL::onBtnCreateClicked);
	connect(btnImport, &QPushButton::clicked, this, &WidgetWZGL::onBtnImportClicked);

	connect(btnClose, &QAbstractButton::clicked, this, &WidgetWZGL::onBtnCloseClicked);
	connect(btnDelete, &QAbstractButton::clicked, this, &WidgetWZGL::onBtnDeleteClicked);
	connect(btnSave, &QAbstractButton::clicked, this, &WidgetWZGL::onBtnSaveClicked);
	connect(btnSubmit, &QAbstractButton::clicked, this, &WidgetWZGL::onBtnSubmitClicked);
	connect(btnPrint, &QAbstractButton::clicked, this, &WidgetWZGL::onBtnPrintClicked);

	connect(myLabel[0], &Mylabel::clicked, [=] {emit sig_myLabelClicked(0); });
	connect(myLabel[1], &Mylabel::clicked, [=] {emit sig_myLabelClicked(1); });
	connect(myLabel[2], &Mylabel::clicked, [=] {emit sig_myLabelClicked(2); });
	connect(this, &WidgetWZGL::sig_myLabelClicked, this, &WidgetWZGL::onsig_myLabelClicked);

	connect(this, &WidgetWZGL::sig_tableIsNotOpen, [=]
		{
			QMessageBox box(QMessageBox::Information, "提示", "请先新建或打开采购申请单！");
			box.setStandardButtons(QMessageBox::Ok);
			box.setButtonText(QMessageBox::Ok, QString("确 定"));
			box.setWindowIcon(QPixmap("Resources/logo.png"));
			int button = box.exec();
		});

	connect(this, &WidgetWZGL::sig_CreateWCostAndDate, this, &WidgetWZGL::onsig_CreateWCostAndDate);

}

WidgetWZGL::~WidgetWZGL()
{
	delete tab;
	delete tab_2;
	delete tab_3;
	delete tab_4;
	delete tab_5;
	tab = NULL;
	tab_2 = NULL;
	tab_3 = NULL;
	tab_4 = NULL;
	tab_5 = NULL;
}

void WidgetWZGL::onsig_forwzgl(UserInfo& userInfo) {

	comboBoxPro->setCurrentText(userInfo.xm);
	lineApplyPerson->setText(userInfo.user_real_name);
	linePro->setText(userInfo.xm);
	this->userInfo = userInfo;

}

void WidgetWZGL::onBtnCreateClicked() {

	btnDelete->hide();
	btnSubmit->setEnabled(true);
	labelRemind->hide();
	for (int i = 0; i < 3; ++i) {
		flagForCheck[i] = 0;
		lineEditPwd[i]->hide();
		btnPass[i]->hide();
		btnReject[i]->hide();
		btnUndo[i]->hide();
		myLabel[i]->setPixmap(QPixmap("Resources/waitforpass.png"));
		myLabel[i]->setEnabled(false);
		labelName[i]->hide();
	}
	state = State::待审核;
	lineApplyPerson->setText(userInfo.user_real_name);
	linePro->setText(userInfo.xm);
	dateEditApplyDate->setDate(QDate::currentDate());
	currentID = "";
	for (int i = 0; i < qItemModel_2->rowCount(); ++i) {
		qItemModel_2->item(i, 0)->setFont(QFont("宋体", 7));
		qItemModel_2->item(i, 1)->setFont(QFont("楷体", 7));
		v_btnOpen[i]->setFont(QFont("宋体", 7));
	}

	if (tableWidget == NULL) {
		tableWidget = new MyTableWidget(widgetRight);
		tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
		tableWidget->setGeometry(QRect(10, 150, 1530, 662));
		tableWidget->setFont(QFont("宋体", 7));
		tableWidget->setStyleSheet("background-color: rgb(255, 255, 255); gridline-color: rgb(0, 0, 0);");
		tableWidget->verticalScrollBar()->setStyleSheet("QScrollBar:vertical{"//垂直滑块整体  
			"width:15px;"          //宽度
			"background:#FFFFFF;"  //背景色  
			"padding-top:2px;"     //上预留位置（放置向上箭头）  
			"padding-bottom:2px;"  //下预留位置（放置向下箭头）  
			"padding-left:1px;"    //左预留位置（美观）  
			"padding-right:1px;"   //右预留位置（美观）  
			"border-left:0px;}"    //左分割线  
			"QScrollBar::handle:vertical{"//滑块样式  
			"background:url(Resources/aurora1_long.png) center no-repeat;"  //滑块颜色  
			"border-radius:6px;"   //边角圆润  
			"min-height:80px;}"    //滑块最小高度  
			"QScrollBar::handle:vertical:hover{"//鼠标触及滑块样式  
			"background:url(Resources/aurora2_long.png) center no-repeat;}" //滑块颜色  
			"QScrollBar::add-line:vertical{"//向下箭头样式  
			"background:url() center no-repeat;}"
			"QScrollBar::sub-line:vertical{"//向上箭头样式  
			"background:url() center no-repeat;}");
		tableWidget->setFrameShape(QFrame::Shape::Box);
		tableWidget->setEditTriggers(QAbstractItemView::CurrentChanged);//可写
		tableWidget->setFocusPolicy(Qt::FocusPolicy::NoFocus);
		tableWidget->verticalHeader()->hide();
		tableWidget->horizontalHeader()->setFixedHeight(47);
		tableWidget->setRowCount(13);
		tableWidget->setColumnCount(9);
		tableWidget->setHorizontalHeaderLabels(QStringList() << "序号" << "物品名称" << "数量" << "单位"
			<< "型号规格" << "用途" << "审批意见" << "金额(元)" << "采购日期");
		for (int i = 0; i < tableWidget->rowCount(); ++i) {
			QTableWidgetItem* item = new QTableWidgetItem(QString::number(i + 1));
			tableWidget->setItem(i, 0, item);
			item->setFlags(item->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
			tableWidget->item(i, 0)->setForeground(QBrush(QColor(0, 0, 0)));
			tableWidget->item(i, 0)->setTextAlignment(Qt::Alignment::enum_type::AlignCenter);
			for (int j = 1; j < 6; ++j) {
				tableWidget->setItem(i, j, new QTableWidgetItem(""));
			}
			tableWidget->setItem(i, 6, new QTableWidgetItem(""));
			tableWidget->item(i, 6)->setFlags(tableWidget->item(i, 6)->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
			tableWidget->item(i, 6)->setForeground(QBrush(QColor(0, 0, 0)));
			tableWidget->item(i, 6)->setBackground(QBrush(QColor(255, 244, 240, 188)));
			for (int j = 7; j <= 8; ++j) {
				tableWidget->setItem(i, j, new QTableWidgetItem(""));
				tableWidget->item(i, j)->setFlags(tableWidget->item(i, j)->flags() & ~Qt::ItemIsEditable);
				tableWidget->item(i, j)->setForeground(QBrush(QColor(0, 0, 0)));
				tableWidget->item(i, j)->setBackground(QBrush(QColor(244, 255, 240, 188)));
			}
			tableWidget->setRowHeight(i, 47);
		}
		tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
		tableWidget->horizontalHeader()->setSectionResizeMode(5, QHeaderView::Stretch);
		tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(22, 82, 173); color:rgb(240, 240, 240);}");
		tableWidget->setColumnWidth(0, 70);
		tableWidget->setColumnWidth(1, 250);
		tableWidget->setColumnWidth(2, 80);
		tableWidget->setColumnWidth(3, 80);
		tableWidget->setColumnWidth(4, 200);
		tableWidget->setColumnWidth(6, 300);
		tableWidget->setColumnWidth(7, 125);
		tableWidget->setColumnWidth(8, 150);
		tableWidget->show();
		tableIsOpen = true;

		if (btnAddRow != NULL) { delete btnAddRow; btnAddRow = NULL; }
		btnAddRow = new QPushButton(widgetRight);
		btnAddRow->setObjectName(QString::fromUtf8("btnAddRow"));
		btnAddRow->setGeometry(QRect(25, 820, 130, 30));
		btnAddRow->setFont(QFont("宋体", 8));
		btnAddRow->setText("新增一行");
		btnAddRow->setStyleSheet(
			"QPushButton{background-color: rgba( 0, 0, 0, 0);border: 0px;border-radius: 10px;color: rgb(22, 82, 173);}"
			"QPushButton:hover{background-color: rgba(255, 255, 255, 128);}"
			"QPushButton:pressed{background-color: rgba(255, 255, 255, 230);}"
		);
		QIcon icon;
		icon.addFile(QString::fromUtf8("Resources/addnewrow.png"), QSize(), QIcon::Normal, QIcon::Off);
		btnAddRow->setIcon(icon);
		btnAddRow->setIconSize(QSize(30, 30));
		btnAddRow->show();

		connect(btnAddRow, &QPushButton::clicked, [=]
			{
				tableWidget->insertRow(tableWidget->rowCount());
				QTableWidgetItem* item = new QTableWidgetItem(QString::number(tableWidget->rowCount()));
				tableWidget->setItem(tableWidget->rowCount() - 1, 0, item);
				item->setFlags(item->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
				tableWidget->item(tableWidget->rowCount() - 1, 0)->setForeground(QBrush(QColor(0, 0, 0)));
				tableWidget->item(tableWidget->rowCount() - 1, 0)->setTextAlignment(Qt::Alignment::enum_type::AlignCenter);
				for (int j = 1; j < 6; ++j) {
					tableWidget->setItem(tableWidget->rowCount() - 1, j, new QTableWidgetItem(""));
				}
				tableWidget->setItem(tableWidget->rowCount() - 1, 6, new QTableWidgetItem(""));
				tableWidget->item(tableWidget->rowCount() - 1, 6)->
					setFlags(tableWidget->item(tableWidget->rowCount() - 1, 6)->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
				tableWidget->item(tableWidget->rowCount() - 1, 6)->setForeground(QBrush(QColor(0, 0, 0)));
				tableWidget->item(tableWidget->rowCount() - 1, 6)->setBackground(QBrush(QColor(255, 244, 240, 188)));
				for (int j = 7; j <= 8; ++j) {
					tableWidget->setItem(tableWidget->rowCount() - 1, j, new QTableWidgetItem(""));
					tableWidget->item(tableWidget->rowCount() - 1, j)->
						setFlags(tableWidget->item(tableWidget->rowCount() - 1, j)->flags() & ~Qt::ItemIsEditable);
					tableWidget->item(tableWidget->rowCount() - 1, j)->setForeground(QBrush(QColor(0, 0, 0)));
					tableWidget->item(tableWidget->rowCount() - 1, j)->setBackground(QBrush(QColor(244, 255, 240, 188)));
				}
				tableWidget->setRowHeight(tableWidget->rowCount() - 1, 47);
				tableWidget->scrollToBottom();
			});

		connect(tableWidget->horizontalHeader(), SIGNAL(sectionDoubleClicked(int)), this, SLOT(onDoubleClicked(int)));
		connect(tableWidget, SIGNAL(cellDoubleClicked(int, int)), this, SLOT(onDoubleClicked(int, int)));

	}
	else {
		tableWidget->clearContents();
		tableWidget->setRowCount(13);
		for (int i = 0; i < tableWidget->rowCount(); ++i) {
			QTableWidgetItem* item = new QTableWidgetItem(QString::number(i + 1));
			tableWidget->setItem(i, 0, item);
			item->setFlags(item->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
			tableWidget->item(i, 0)->setForeground(QBrush(QColor(0, 0, 0)));
			tableWidget->item(i, 0)->setTextAlignment(Qt::Alignment::enum_type::AlignCenter);
			for (int j = 1; j < 6; ++j) {
				tableWidget->setItem(i, j, new QTableWidgetItem(""));
			}
			tableWidget->setItem(i, 6, new QTableWidgetItem(""));
			tableWidget->item(i, 6)->setFlags(tableWidget->item(i, 6)->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
			tableWidget->item(i, 6)->setForeground(QBrush(QColor(0, 0, 0)));
			tableWidget->item(i, 6)->setBackground(QBrush(QColor(255, 244, 240, 188)));
			for (int j = 7; j <= 8; ++j) {
				tableWidget->setItem(i, j, new QTableWidgetItem(""));
				tableWidget->item(i, j)->setFlags(tableWidget->item(i, j)->flags() & ~Qt::ItemIsEditable);
				tableWidget->item(i, j)->setForeground(QBrush(QColor(0, 0, 0)));
				tableWidget->item(i, j)->setBackground(QBrush(QColor(244, 255, 240, 188)));
			}
		}
	}

}

void WidgetWZGL::onBtnImportClicked() {

	QString strFile = QFileDialog::getOpenFileName(tableWidget, "选择文件", "./", "文本文件(*.xls;*.xlsx;)");
	if (strFile.isEmpty())
		return;
	Book* book = NULL;
	if (strFile.endsWith("xls", Qt::CaseInsensitive))//判断是否是.xls文件，不区分大小写
	{
		book = xlCreateBook(); // xlCreateBook() for xls
	}
	else if (strFile.endsWith("xlsx", Qt::CaseInsensitive))//判断是否是.xlsx文件，不区分大小写
	{
		book = xlCreateXMLBook(); // xlCreateXMLBook() for xlsx
	}
	const wchar_t* wstr = reinterpret_cast<const wchar_t*>(strFile.utf16());//QString转wchar_t
	bool f = book->load(wstr);//加载excel文件

	onBtnCreateClicked();

	CellType ct;
	if (book) {
		Sheet* sheet = book->getSheet(0);//表1
		//读数据
		for (int i = 1; i < sheet->lastRow(); i++)
		{
			if (i > 13) {
				tableWidget->insertRow(i - 1);
				QTableWidgetItem* item = new QTableWidgetItem(QString::number(i));
				tableWidget->setItem(i - 1, 0, item);
				item->setFlags(item->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
				tableWidget->item(i - 1, 0)->setForeground(QBrush(QColor(0, 0, 0)));
				tableWidget->item(i - 1, 0)->setTextAlignment(Qt::Alignment::enum_type::AlignCenter);
				for (int j = 1; j < 6; ++j) {
					tableWidget->setItem(i - 1, j, new QTableWidgetItem(""));
				}
				tableWidget->setItem(i - 1, 6, new QTableWidgetItem(""));
				tableWidget->item(i - 1, 6)->setFlags(tableWidget->item(i - 1, 6)->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
				tableWidget->item(i - 1, 6)->setForeground(QBrush(QColor(0, 0, 0)));
				tableWidget->item(i - 1, 6)->setBackground(QBrush(QColor(255, 244, 240, 188)));
				for (int j = 7; j <= 8; ++j) {
					tableWidget->setItem(i - 1, j, new QTableWidgetItem(""));
					tableWidget->item(i - 1, j)->setFlags(tableWidget->item(i - 1, j)->flags() & ~Qt::ItemIsEditable);
					tableWidget->item(i - 1, j)->setForeground(QBrush(QColor(0, 0, 0)));
					tableWidget->item(i - 1, j)->setBackground(QBrush(QColor(244, 255, 240, 188)));
				}
				tableWidget->setRowHeight(i - 1, 47);
			}
			for (int j = 1; j < 6; j++)
			{
				ct = sheet->cellType(i, j);//单元格的数据类型

				if (ct == CELLTYPE_STRING)
					tableWidget->setItem(i - 1, j, new QTableWidgetItem(QString::fromWCharArray(sheet->readStr(i, j))));//wchar_t转QString
				else if (ct == CELLTYPE_NUMBER)
					tableWidget->setItem(i - 1, j, new QTableWidgetItem(QString::number((int)sheet->readNum(i, j))));
			}
		}
		delete book;
		book = NULL;
	}
	else {
		QMessageBox box(QMessageBox::Information, "提示", "文件打开失败！");
		box.setStandardButtons(QMessageBox::Ok);
		box.setButtonText(QMessageBox::Ok, QString("确 定"));
		box.setWindowIcon(QPixmap("Resources/logo.png"));
		int button = box.exec();
	}

	//QElapsedTimer timer;
	//timer.start();
	//qDebug() << "cost:" << timer.elapsed() << "ms"; timer.restart();

}

void WidgetWZGL::onBtnCloseClicked() {

	if (tableIsOpen == false) {
		emit sig_tableIsNotOpen();
		return;
	}

	tableWidget->clearContents();
	delete tableWidget;
	tableWidget = NULL;
	delete btnAddRow;
	btnAddRow = NULL;
	tableIsOpen = false;
	labelRemind->show();

	for (int i = 0; i < 3; ++i) {
		flagForCheck[i] = 0;
		lineEditPwd[i]->hide();
		btnPass[i]->hide();
		btnReject[i]->hide();
		btnUndo[i]->hide();
		myLabel[i]->setPixmap(QPixmap("Resources/waitforpass.png"));
		myLabel[i]->setEnabled(false);
		labelName[i]->hide();
	}
	state = State::待审核;
	lineApplyPerson->setText(userInfo.user_real_name);
	linePro->setText(userInfo.xm);
	dateEditApplyDate->setDate(QDate::currentDate());
	currentID = "";
	for (int i = 0; i < qItemModel_2->rowCount(); ++i) {
		qItemModel_2->item(i, 0)->setFont(QFont("宋体", 7));
		qItemModel_2->item(i, 1)->setFont(QFont("楷体", 7));
		v_btnOpen[i]->setFont(QFont("宋体", 7));
	}
	btnSubmit->setEnabled(false);
	btnDelete->hide();

}

void WidgetWZGL::onBtnSaveClicked() {

	if (tableIsOpen == false) {
		emit sig_tableIsNotOpen();
		return;
	}

	QString fileName = QFileDialog::getSaveFileName(tableWidget, "保存",
		QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation), "Excel 文件(*.xlsx *.xls)");
	if (fileName.isEmpty())
		return;

	QXlsx::Document xlsx;

	QXlsx::Format cell_format;
	cell_format.setFontSize(11);
	cell_format.setPatternBackgroundColor(QColor(182, 182, 182));
	cell_format.setBorderStyle(QXlsx::Format::BorderThin);
	cell_format.setHorizontalAlignment(QXlsx::Format::AlignHCenter);
	cell_format.setVerticalAlignment(QXlsx::Format::AlignVCenter);

	xlsx.write(1, 1, "序号", cell_format);
	xlsx.write(1, 2, "物品名称", cell_format);
	xlsx.write(1, 3, "数量", cell_format);
	xlsx.write(1, 4, "单位", cell_format);
	xlsx.write(1, 5, "型号规格", cell_format);
	xlsx.write(1, 6, "用途", cell_format);
	for (int i = 2; i < tableWidget->rowCount() + 2; ++i) {
		xlsx.write(i, 1, i - 1);
	}
	xlsx.setColumnWidth(1, 10);
	xlsx.setColumnWidth(2, 20);
	xlsx.setColumnWidth(3, 10);
	xlsx.setColumnWidth(4, 10);
	xlsx.setColumnWidth(5, 20);
	xlsx.setColumnWidth(6, 35);

	for (int i = 0; i < tableWidget->rowCount(); i++) {
		for (int j = 1; j < 6; j++) {
			xlsx.write(i + 2, j + 1, tableWidget->item(i, j)->text());
		}
	}
	xlsx.saveAs(fileName);
	QMessageBox box(QMessageBox::Question, "提示", " 文件创建成功，是否打开？");
	box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	box.setButtonText(QMessageBox::Ok, QString("确 定"));
	box.setButtonText(QMessageBox::Cancel, QString("取 消"));
	box.setWindowIcon(QPixmap("Resources/logo.png"));
	int button = box.exec();
	if (button == QMessageBox::Ok)
		QDesktopServices::openUrl(QUrl("file:///" + fileName));

}

void WidgetWZGL::onBtnSubmitClicked() {

	if (tableIsOpen == false) {
		emit sig_tableIsNotOpen();
		return;
	}

	if (linePro->text() != userInfo.xm) {
		QMessageBox box(QMessageBox::Information, "提示", "项目名称输入有误！");
		box.setStandardButtons(QMessageBox::Ok);
		box.setButtonText(QMessageBox::Ok, QString("确 定"));
		box.setWindowIcon(QPixmap("Resources/logo.png"));
		int button = box.exec();
		linePro->setText(userInfo.xm);
		return;
	}

	if (lineApplyPerson->text() != userInfo.user_real_name) {
		QMessageBox box(QMessageBox::Information, "提示", "申请人姓名输入有误！");
		box.setStandardButtons(QMessageBox::Ok);
		box.setButtonText(QMessageBox::Ok, QString("确 定"));
		box.setWindowIcon(QPixmap("Resources/logo.png"));
		int button = box.exec();
		lineApplyPerson->setText(userInfo.user_real_name);
		return;
	}

	int curRow = -1;
	for (curRow = tableWidget->rowCount() - 1; curRow >= 0; --curRow) {
		for (int j = 1; j < 6; ++j) {
			if (!tableWidget->item(curRow, j)->text().isEmpty()) {
				goto X;
			}
		}
	}
X:
	if (curRow == -1) {
		QMessageBox box(QMessageBox::Information, "提示", "不可提交空表！");
		box.setStandardButtons(QMessageBox::Ok);
		box.setButtonText(QMessageBox::Ok, QString("确 定"));
		box.setWindowIcon(QPixmap("Resources/logo.png"));
		int button = box.exec();
		return;
	}

	int f = 0;
	for (int i = 0; i <= curRow; ++i) {
		if (tableWidget->item(i, 1)->text() == "" || tableWidget->item(i, 2)->text() == ""
			|| tableWidget->item(i, 3)->text() == "" || tableWidget->item(i, 4)->text() == "") {
			f = 1;
			if (tableWidget->item(i, 1)->text() == "") tableWidget->item(i, 1)->setText("！！！");
			if (tableWidget->item(i, 2)->text() == "") tableWidget->item(i, 2)->setText("！！！");
			if (tableWidget->item(i, 3)->text() == "") tableWidget->item(i, 3)->setText("！！！");
			if (tableWidget->item(i, 4)->text() == "") tableWidget->item(i, 4)->setText("！！！");
		}
	}
	if (f == 1) {
		QMessageBox box(QMessageBox::Information, "提示", "请把采购申请单填写完整！");
		box.setStandardButtons(QMessageBox::Ok);
		box.setButtonText(QMessageBox::Ok, QString("确 定"));
		box.setWindowIcon(QPixmap("Resources/logo.png"));
		int button = box.exec();
		return;
	}

	for (int i = 0; i <= curRow; ++i) {
		for (auto c : tableWidget->item(i, 2)->text()) {
			if (!c.isDigit()) {
				QMessageBox box(QMessageBox::Information, "提示", "请在数量区填写数字！");
				box.setStandardButtons(QMessageBox::Ok);
				box.setButtonText(QMessageBox::Ok, QString("确 定"));
				box.setWindowIcon(QPixmap("Resources/logo.png"));
				int button = box.exec();
				return;
			}
		}
	}

	QMessageBox box(QMessageBox::Question, "提示", "提交后需重新审批，确认要提交吗？");
	box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	box.setButtonText(QMessageBox::Ok, QString("确 定"));
	box.setButtonText(QMessageBox::Cancel, QString("取 消"));
	box.setWindowIcon(QPixmap("Resources/logo.png"));
	int button = box.exec();
	if (button != QMessageBox::Ok)
		return;

	QVector<QVector<QString>> v_v_tableDate;
	QVector<QString> v_tableDate;
	for (int i = 0; i <= curRow; ++i) {
		v_tableDate.push_back(QString("%1#%2#%3").arg(linePro->text()).arg(dateEditApplyDate->text()).arg(QString::number(i + 1)));
		v_tableDate.push_back(lineApplyPerson->text());
		for (int j = 1; j < 6; ++j) {
			v_tableDate.push_back(tableWidget->item(i, j)->text());
		}
		v_tableDate.push_back(QString::number(State::待审核));
		v_v_tableDate.push_back(v_tableDate);
		v_tableDate.clear();
	}

	emit sig_forSubmit(v_v_tableDate);

}

void WidgetWZGL::onBtnPrintClicked() {

	if (tableIsOpen == false) {
		emit sig_tableIsNotOpen();
		return;
	}

	QPrinter printer(QPrinter::HighResolution);
	printer.setPageSize(QPrinter::Custom);
	QPrintPreviewDialog preview(&printer, this);
	int nFullWidth = GetSystemMetrics(SM_CXSCREEN);
	int nFullHeight = GetSystemMetrics(SM_CYSCREEN);
	preview.setMinimumSize(nFullWidth, nFullHeight);
	preview.setWindowTitle("打印预览");
	connect(&preview, &QPrintPreviewDialog::paintRequested, this, &WidgetWZGL::printPreviewSlot);
	preview.exec();

}

void WidgetWZGL::onsig_myLabelClicked(int index) {

	if (state != index + 1 && state != index + 2) return;
	flagForCheck[index] = 1 - flagForCheck[index];

	if (flagForCheck[index] == 1) {
		lineEditPwd[index]->show();
		btnPass[index]->show();
		btnReject[index]->show();
	}
	else if (flagForCheck[index] == 0) {
		lineEditPwd[index]->hide();
		btnPass[index]->hide();
		btnReject[index]->hide();
	}

}

void WidgetWZGL::printPreviewSlot(QPrinter* printer) {

	for (int i = 0; i < tableWidget->rowCount(); ++i) {
		for (int j = 1; j < 6; ++j) {
			tableWidget->item(i, j)->setFlags(tableWidget->item(i, j)->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
			tableWidget->item(i, j)->setForeground(QBrush(QColor(0, 0, 0)));
		}
	}
	tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(255, 255, 255); color:rgb(0, 0, 0);}");
	tableWidget->scrollToTop();
	tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	QPainter painter;
	painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
	painter.begin(printer);

	//横向
	if (printer->orientation() == QPrinter::Landscape) {
		QString text = "此表格不支持横向打印^_^";
		painter.setFont(QFont("宋体", 60));
		painter.drawText(550, 2500, text);
	}

	//纵向
	if (printer->orientation() == QPrinter::Portrait) {
		int tatalPageCount = 0;
		if (tableWidget->rowCount() % 20 == 0) tatalPageCount = tableWidget->rowCount() / 20;
		else  tatalPageCount = tableWidget->rowCount() / 20 + 1;
		for (int page_index = 0; page_index < tatalPageCount; ++page_index) {
			painter.setPen(QColor(40, 40, 40));// 设置画笔颜色
			painter.drawPixmap(200, 100, QPixmap("Resources/logo.png"));
			QString text = "浙江XXXX管理有限公司                         "
				"                                 采购单编号：WBWY-KF-2014-11";
			painter.setFont(QFont("宋体", 9));
			painter.drawText(440, 230, text);
			painter.drawLine(QPointF(0, 400), QPointF(5000, 400));	// 绘制直线
			painter.setPen(QColor(0, 0, 0));
			text = "XXXX物资采购申请单";
			painter.setFont(QFont("宋体", 30));
			painter.drawText(1000, 800, text);
			painter.setFont(QFont("宋体", 18));
			text = QString("%1 %2    申请人：%3").arg(linePro->text()).arg(dateEditApplyDate->text()).arg(lineApplyPerson->text());
			painter.drawText(100, 1200, text);
			QPixmap pixmap = tableWidget->grab(QRect(QPoint(0, 0), QSize(954, 48)));
			QRect rect = painter.viewport();
			QSize size = pixmap.size();
			size.scale(rect.size(), Qt::KeepAspectRatio);//保持长宽比
			painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
			painter.setWindow(pixmap.rect());
			painter.drawPixmap(0, 255, pixmap); //画图
			int c = 0;
			for (int i = page_index * 20; i < (page_index + 1) * 20; ++i) {
				if (i > tableWidget->rowCount() - 1) break;
				QPixmap pixmap = tableWidget->grab(QRect(QPoint(0, 48), QSize(954, 48)));
				painter.drawPixmap(0, 303 + c * 48, pixmap);
				tableWidget->hideRow(i);
				++c;
			}
			painter.setFont(QFont("宋体", 3));
			text = QString("%1").arg(QString::number(page_index + 1));
			painter.drawText(477, 1320, text);
			painter.setViewport(QRect(0, 0, 4758, 6817));
			painter.setWindow(QRect(0, 0, 4758, 6817));
			if (page_index != tatalPageCount - 1) printer->newPage();
		}
	}

	painter.end();
	for (int i = 0; i < tableWidget->rowCount(); ++i) {
		for (int j = 1; j < 6; ++j) {
			tableWidget->item(i, j)->setFlags((Qt::ItemFlags)63); //63为初始状态
		}
	}
	for (int i = 0; i < tableWidget->rowCount(); ++i) {
		tableWidget->showRow(i);
	}
	tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(22, 82, 173); color:rgb(240, 240, 240);}");
	tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
}

void WidgetWZGL::setTableViewColor(QPushButton* btnOpen, int num_row, int r, int g, int b, int a) {

	qItemModel_2->item(num_row, 0)->setBackground(QBrush(QColor(r, g, b, a)));
	qItemModel_2->item(num_row, 1)->setBackground(QBrush(QColor(r, g, b, a)));
	btnOpen->setStyleSheet(QString(
		"QPushButton{background-color: rgba(%1, %2, %3, %4);border: 0px;color: rgb(52, 0, 79);}"
		"QPushButton:hover{color: red;text-decoration:underline;}").arg(r).arg(g).arg(b).arg(a)
	);

}

void WidgetWZGL::oncurrentTextChanged(const QString& pro) {

	if (tableIsOpen == true) onBtnCloseClicked();
	emit sig_sendPurchaseData(pro, lineYear->text().toInt(), comboBoxMonth->currentText().mid(0, 2).toInt(), comboBoxState->currentIndex());
}

void WidgetWZGL::receivePurchaseData(QVector<QVector<QString>> v_v_forPurchase) {

	qItemModel_2->removeRows(0, qItemModel_2->rowCount());

	v_item.clear();

	for (auto it = v_btnOpen.begin(); it != v_btnOpen.end(); ++it) {
		delete (*it); (*it) = NULL;
	}
	v_btnOpen.clear();

	QStandardItem* item = NULL;
	int num_row = 0;
	QString state = "";
	QPushButton* btnOpen = NULL;
	QFont font;
	font.setFamily("楷体");
	font.setPointSize(7);
	QFont font_temp;
	font_temp.setBold(true);
	font_temp.setFamily("宋体");
	font_temp.setPointSize(7);
	QFont font_temp_2;
	font_temp_2.setBold(true);
	font_temp_2.setFamily("楷体");
	font_temp_2.setPointSize(7);
	for (auto it = v_v_forPurchase.cbegin(); it != v_v_forPurchase.cend(); ++it) {

		item = new QStandardItem(QString("%1").arg((*it)[0]));
		qItemModel_2->setItem(num_row, 0, item);
		qItemModel_2->item(num_row, 0)->setFlags(item->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
		qItemModel_2->item(num_row, 0)->setFont(QFont("宋体", 7));
		qItemModel_2->item(num_row, 0)->setForeground(QBrush(QColor(0, 0, 0)));
		v_item.push_back(item);

		btnOpen = new QPushButton(this);
		btnOpen->setText("打开");
		btnOpen->setCursor(Qt::CursorShape::PointingHandCursor);
		btnOpen->setFont(QFont("宋体", 7));
		tableView->setIndexWidget(qItemModel_2->index(num_row, 2), btnOpen);
		v_btnOpen.push_back(btnOpen);

		item = new QStandardItem();
		qItemModel_2->setItem(num_row, 1, item);
		switch ((*it)[1].toInt())
		{
		case State::待审核:state = "待审核"; setTableViewColor(btnOpen, num_row, 234, 234, 229, 255); break;
		case State::一审:state = "一审"; setTableViewColor(btnOpen, num_row, 251, 177, 17, 200); break;
		case State::二审:state = "二审"; setTableViewColor(btnOpen, num_row, 251, 177, 17, 200); break;
		case State::三审:state = "三审"; setTableViewColor(btnOpen, num_row, 255, 230, 0, 150); break;
		case State::已采购:state = "已采购"; setTableViewColor(btnOpen, num_row, 216, 215, 2, 200); break;
		case State::已领用:state = "已领用"; setTableViewColor(btnOpen, num_row, 112, 183, 72, 200); break;
		case State::驳回:state = "驳回"; setTableViewColor(btnOpen, num_row, 128, 0, 0, 150); break;
		default:break;
		}
		qItemModel_2->item(num_row, 1)->setText(QString("%1").arg(state));
		qItemModel_2->item(num_row, 1)->setFlags(item->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
		qItemModel_2->item(num_row, 1)->setFont(font);
		qItemModel_2->item(num_row, 1)->setForeground(QBrush(QColor(0, 0, 0)));
		qItemModel_2->item(num_row, 1)->setTextAlignment(Qt::Alignment::enum_type::AlignCenter);
		v_item.push_back(item);

		connect(btnOpen, &QPushButton::clicked, [=]
			{
				onBtnCreateClicked();
				currentRowIndex = num_row;
				currentID = qItemModel_2->item(currentRowIndex, 0)->text();
				emit sig_btnOpenClicked(qItemModel_2->item(num_row, 0)->text());
				QString pro = ""; QString year = ""; QString month = ""; QString day = ""; int count = 0;
				for (auto c : qItemModel_2->item(num_row, 0)->text()) {
					if (count == 1 && c != '/') year += c;
					if (count == 3) day += c;
					if (c == '#' || c == '/') ++count;
					if (count == 0) pro += c;
					if (count == 2 && c != '/') month += c;
				}
				linePro->setText(pro);
				dateEditApplyDate->setDate(QDate(year.toInt(), month.toInt(), day.toInt()));
				if (pro != userInfo.xm || (qItemModel_2->item(num_row, 1)->text() != "待审核"
					&& qItemModel_2->item(num_row, 1)->text() != "驳回")) btnSubmit->setEnabled(false);

				for (int i = 0; i < 3; ++i)
					myLabel[i]->setEnabled(true);

				qItemModel_2->item(num_row, 0)->setFont(font_temp);
				qItemModel_2->item(num_row, 1)->setFont(font_temp_2);
				v_btnOpen[num_row]->setFont(font_temp);

			});

		++num_row;
	}

	QString pro = ""; int count = 0;
	for (auto c : currentID) {
		if (c == '#' || c == '/') ++count;
		if (count == 0) pro += c;
	}
	for (int i = 0; i < qItemModel_2->rowCount(); ++i) {
		if (currentID == qItemModel_2->item(i, 0)->text()) {
			if (pro != userInfo.xm || (qItemModel_2->item(i, 1)->text() != "待审核"
				&& qItemModel_2->item(i, 1)->text() != "驳回")) btnSubmit->setEnabled(false);
			else btnSubmit->setEnabled(true);
			qItemModel_2->item(i, 0)->setFont(font_temp);
			qItemModel_2->item(i, 1)->setFont(font_temp_2);
			v_btnOpen[i]->setFont(font_temp);
		}
	}

}

void WidgetWZGL::receiveOpenDate(QVector<QVector<QString>> v_v_forOpen) {

	v_v_forOpen_data = v_v_forOpen;
	int rowIndex = 0;
	auto it = v_v_forOpen.cbegin();
	QString name_1 = (*it)[9];
	QString name_2 = (*it)[10];
	QString name_3 = (*it)[11];
	lineApplyPerson->setText((*it)[0]);
	for (; it != v_v_forOpen.cend(); ++it) {
		if (rowIndex > 12) {
			tableWidget->insertRow(rowIndex);
			QTableWidgetItem* item = new QTableWidgetItem(QString::number(rowIndex + 1));
			tableWidget->setItem(rowIndex, 0, item);
			item->setFlags(item->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
			tableWidget->item(rowIndex, 0)->setForeground(QBrush(QColor(0, 0, 0)));
			tableWidget->item(rowIndex, 0)->setTextAlignment(Qt::Alignment::enum_type::AlignCenter);
			for (int j = 1; j < 6; ++j) {
				tableWidget->setItem(rowIndex, j, new QTableWidgetItem(""));
			}
			tableWidget->setItem(rowIndex, 6, new QTableWidgetItem(""));
			tableWidget->item(rowIndex, 6)->setFlags(tableWidget->item(rowIndex, 6)->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
			tableWidget->item(rowIndex, 6)->setForeground(QBrush(QColor(0, 0, 0)));
			tableWidget->item(rowIndex, 6)->setBackground(QBrush(QColor(255, 244, 240, 188)));
			for (int j = 7; j < 9; ++j) {
				tableWidget->setItem(rowIndex, j, new QTableWidgetItem(""));
				tableWidget->item(rowIndex, j)->setFlags(tableWidget->item(rowIndex, j)->flags() & ~Qt::ItemIsEditable);
				tableWidget->item(rowIndex, j)->setForeground(QBrush(QColor(0, 0, 0)));
				tableWidget->item(rowIndex, j)->setBackground(QBrush(QColor(244, 255, 240, 188)));
			}
			tableWidget->setRowHeight(rowIndex, 47);
		}
		for (int i = 1; i < 9; ++i) {
			tableWidget->item(rowIndex, i)->setText((*it)[i]);
		}
		++rowIndex;
	}

	if (qItemModel_2->item(currentRowIndex, 1)->text() == "待审核") {
		this->state = State::待审核;
	}
	if (qItemModel_2->item(currentRowIndex, 1)->text() == "一审") {
		this->state = State::一审;
		flagForCheck[0] = 2;
		btnUndo[0]->show();
		myLabel[0]->setPixmap(QPixmap("Resources/pass.png"));
		labelName[0]->setText(name_1); labelName[0]->show();
	}
	if (qItemModel_2->item(currentRowIndex, 1)->text() == "二审") {
		this->state = State::二审;
		flagForCheck[1] = 2;
		btnUndo[1]->show();
		myLabel[0]->setPixmap(QPixmap("Resources/pass.png"));
		myLabel[1]->setPixmap(QPixmap("Resources/pass.png"));
		labelName[0]->setText(name_1); labelName[0]->show();
		labelName[1]->setText(name_2); labelName[1]->show();
	}
	if (qItemModel_2->item(currentRowIndex, 1)->text() == "三审") {
		this->state = State::三审;
		flagForCheck[2] = 2;
		btnUndo[2]->show();
		myLabel[0]->setPixmap(QPixmap("Resources/pass.png"));
		myLabel[1]->setPixmap(QPixmap("Resources/pass.png"));
		myLabel[2]->setPixmap(QPixmap("Resources/pass.png"));
		labelName[0]->setText(name_1); labelName[0]->show();
		labelName[1]->setText(name_2); labelName[1]->show();
		labelName[2]->setText(name_3); labelName[2]->show();
	}
	if (qItemModel_2->item(currentRowIndex, 1)->text() == "已采购") {
		this->state = State::已采购;
		myLabel[0]->setPixmap(QPixmap("Resources/pass.png"));
		myLabel[1]->setPixmap(QPixmap("Resources/pass.png"));
		myLabel[2]->setPixmap(QPixmap("Resources/pass.png"));
		labelName[0]->setText(name_1); labelName[0]->show();
		labelName[1]->setText(name_2); labelName[1]->show();
		labelName[2]->setText(name_3); labelName[2]->show();
	}
	if (qItemModel_2->item(currentRowIndex, 1)->text() == "已领用") {
		this->state = State::已领用;
		myLabel[0]->setPixmap(QPixmap("Resources/pass.png"));
		myLabel[1]->setPixmap(QPixmap("Resources/pass.png"));
		myLabel[2]->setPixmap(QPixmap("Resources/pass.png"));
		labelName[0]->setText(name_1); labelName[0]->show();
		labelName[1]->setText(name_2); labelName[1]->show();
		labelName[2]->setText(name_3); labelName[2]->show();
	}
	if (qItemModel_2->item(currentRowIndex, 1)->text() == "驳回") {
		this->state = State::驳回;
		if (name_2.isEmpty()) {
			flagForCheck[0] = 2;
			btnUndo[0]->show();
			myLabel[0]->setPixmap(QPixmap("Resources/fail.png"));
			labelName[0]->setText(name_1); labelName[0]->show();
		}
		else if (name_3.isEmpty()) {
			flagForCheck[1] = 2;
			btnUndo[1]->show();
			myLabel[0]->setPixmap(QPixmap("Resources/pass.png"));
			myLabel[1]->setPixmap(QPixmap("Resources/fail.png"));
			labelName[0]->setText(name_1); labelName[0]->show();
			labelName[1]->setText(name_2); labelName[1]->show();
		}
		else {
			flagForCheck[2] = 2;
			btnUndo[2]->show();
			myLabel[0]->setPixmap(QPixmap("Resources/pass.png"));
			myLabel[1]->setPixmap(QPixmap("Resources/pass.png"));
			myLabel[2]->setPixmap(QPixmap("Resources/fail.png"));
			labelName[0]->setText(name_1); labelName[0]->show();
			labelName[1]->setText(name_2); labelName[1]->show();
			labelName[2]->setText(name_3); labelName[2]->show();
		}
	}

	bool f = 0;
	for (int i = 0; i < tableWidget->rowCount(); ++i) {
		if ((!tableWidget->item(i, 7)->text().isEmpty()) || (!tableWidget->item(i, 8)->text().isEmpty())) {
			f = 1;
			break;
		}
	}
	if (f == 1) {
		btnUndo[2]->hide();
	}

	btnDelete->show();

}

void WidgetWZGL::onsig_forSuccessfulSubmit() {

	QMessageBox box(QMessageBox::Information, "提示", "提交成功！");
	box.setStandardButtons(QMessageBox::Ok);
	box.setButtonText(QMessageBox::Ok, QString("确 定"));
	box.setWindowIcon(QPixmap("Resources/logo.png"));
	int button = box.exec();
	emit sig_sendPurchaseData(comboBoxPro->currentText(), lineYear->text().toInt(),
		comboBoxMonth->currentText().mid(0, 2).toInt(), comboBoxState->currentIndex());
	onBtnCloseClicked();

}

void WidgetWZGL::onsig_forState() {

	emit sig_sendPurchaseData(comboBoxPro->currentText(), lineYear->text().toInt(),
		comboBoxMonth->currentText().mid(0, 2).toInt(), comboBoxState->currentIndex());

}

void WidgetWZGL::onDoubleClicked(int index) {

	if (state != State::三审 && state != State::已采购) return;
	if (index != 7 && index != 8) return;
	emit sig_CreateWCostAndDate();

}

void WidgetWZGL::onDoubleClicked(int row, int col) {

	if (state != State::三审 && state != State::已采购) return;
	if (col != 7 && col != 8) return;
	emit sig_CreateWCostAndDate();

}

void WidgetWZGL::onsig_CreateWCostAndDate() {

	widgetForCostAndDate = new QWidget();
	widgetForCostAndDate->setWindowModality(Qt::ApplicationModal);
	widgetForCostAndDate->setAttribute(Qt::WA_DeleteOnClose);
	widgetForCostAndDate->setWindowIcon(QPixmap("Resources/logo.png"));
	widgetForCostAndDate->setWindowTitle("采购填报");
	widgetForCostAndDate->setFixedSize(1600, 962);
	widgetForCostAndDate->setStyleSheet(QString::fromUtf8("QWidget{background:url(Resources/bkgrdfreject.png) center no-repeat;}"));
	widgetForCostAndDate->show();

	QLabel* temp_label = new QLabel(widgetForCostAndDate);
	temp_label->setGeometry(QRect(550, 35, 1000, 100));
	temp_label->setFont(QFont("楷体", 30));
	temp_label->setText("采购人填报区");
	temp_label->setStyleSheet("color: rgb(0, 0, 0);background-color: rgba(255, 255, 255, 0);");
	temp_label->show();

	QTableWidget* temp_table = new QTableWidget(widgetForCostAndDate);
	temp_table->setGeometry(QRect(135, 154, 1330, 662));
	temp_table->setFont(QFont("宋体", 8));
	temp_table->setStyleSheet(
		"QTableWidget{background:url();background-color: rgb(224, 224, 224); gridline-color: rgb(0, 0, 0);}"
		"QTableWidget::item::selected{background:url();}"
	);
	temp_table->verticalScrollBar()->setStyleSheet("QScrollBar:vertical{"//垂直滑块整体  
		"width:15px;"          //宽度
		"background:#FFFFFF;"  //背景色  
		"padding-top:2px;"     //上预留位置（放置向上箭头）  
		"padding-bottom:2px;"  //下预留位置（放置向下箭头）  
		"padding-left:1px;"    //左预留位置（美观）  
		"padding-right:1px;"   //右预留位置（美观）  
		"border-left:0px;}"    //左分割线  
		"QScrollBar::handle:vertical{"//滑块样式  
		"background:url(Resources/aurora1_long.png) center no-repeat;"  //滑块颜色  
		"border-radius:6px;"   //边角圆润  
		"min-height:80px;}"    //滑块最小高度  
		"QScrollBar::handle:vertical:hover{"//鼠标触及滑块样式  
		"background:url(Resources/aurora2_long.png) center no-repeat;}" //滑块颜色  
		"QScrollBar::add-line:vertical{"//向下箭头样式  
		"background:url() center no-repeat;}"
		"QScrollBar::sub-line:vertical{"//向上箭头样式  
		"background:url() center no-repeat;}");
	temp_table->setFrameShape(QFrame::Shape::Box);
	temp_table->setEditTriggers(QAbstractItemView::DoubleClicked);//这个情况下可以触发双击事件！
	temp_table->setFocusPolicy(Qt::FocusPolicy::NoFocus);
	temp_table->verticalHeader()->hide();
	temp_table->horizontalHeader()->setFixedHeight(47);
	temp_table->setRowCount(v_v_forOpen_data.size());
	temp_table->setColumnCount(9);
	temp_table->setHorizontalHeaderLabels(QStringList() << "序号" << "物品名称" << "数量" << "单位"
		<< "型号规格" << "金额(元)" << "采购日期");
	QTableWidgetItem* item_ = new QTableWidgetItem("提交");
	item_->setFont(QFont("楷体", 11));
	temp_table->setHorizontalHeaderItem(7, item_);
	item_ = new QTableWidgetItem("重置");
	item_->setFont(QFont("楷体", 11));
	temp_table->setHorizontalHeaderItem(8, item_);
	for (int i = 0; i < temp_table->rowCount(); ++i) {
		QTableWidgetItem* item = new QTableWidgetItem(QString::number(i + 1));
		temp_table->setItem(i, 0, item);
		item->setFlags(item->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
		temp_table->item(i, 0)->setForeground(QBrush(QColor(0, 0, 0)));
		temp_table->item(i, 0)->setTextAlignment(Qt::Alignment::enum_type::AlignCenter);
		for (int j = 1; j < 5; ++j) {
			temp_table->setItem(i, j, new QTableWidgetItem(""));
			temp_table->item(i, j)->setFlags(temp_table->item(i, j)->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
			temp_table->item(i, j)->setForeground(QBrush(QColor(0, 0, 0)));
		}
		temp_table->setItem(i, 5, new QTableWidgetItem(""));//cost
		temp_table->item(i, 5)->setBackground(QBrush(QColor(255, 255, 255)));
		temp_table->setItem(i, 6, new QTableWidgetItem(""));//date
		temp_table->item(i, 6)->setBackground(QBrush(QColor(255, 255, 255)));

		QPushButton* temp_btnHand = new QPushButton(widgetForCostAndDate);
		temp_btnHand->setCursor(Qt::CursorShape::PointingHandCursor);
		temp_btnHand->setStyleSheet(
			"QPushButton{image:url(Resources/handup.png);background:url();background-color: rgb(224, 224, 224);border: 0px;}"
			"QPushButton:hover{image:url(Resources/handup_red.png);}"
			"QPushButton:pressed{image:url(Resources/handup_darkred.png);}");
		connect(temp_btnHand, &QPushButton::clicked, [=]
			{
				//判断是否为空
				if (temp_table->item(i, 5)->text().isEmpty() || temp_table->item(i, 6)->text().isEmpty()) {
					QMessageBox box(QMessageBox::Information, "提示", "金额和采购日期不可为空！");
					box.setStandardButtons(QMessageBox::Ok);
					box.setButtonText(QMessageBox::Ok, QString("确 定"));
					box.setWindowIcon(QPixmap("Resources/logo.png"));
					int button = box.exec();
					return;
				}
				//判断是否为金额
				bool f = false;
				int c_count = 0;
				for (auto c : temp_table->item(i, 5)->text()) {
					if (c == '.') ++c_count;
					if ((!c.isDigit()) && (c != '.')) { c_count = 2; break; }
				}
				if (c_count > 1) {
					f = false;
				}
				else if (c_count == 0) {
					f = true;
				}
				else if (c_count == 1) {
					if (temp_table->item(i, 5)->text()[temp_table->item(i, 5)->text().count() - 1] == '.'
						|| temp_table->item(i, 5)->text()[0] == '.') {
						f = false;
					}
					else {
						f = true;
					}
				}

				if (f == false) {
					QMessageBox box(QMessageBox::Information, "提示", "请输入正确的金额格式!");
					box.setStandardButtons(QMessageBox::Ok);
					box.setButtonText(QMessageBox::Ok, QString("确 定"));
					box.setWindowIcon(QPixmap("Resources/logo.png"));
					int button = box.exec();
					return;
				}

				//四舍五入
				double a = temp_table->item(i, 5)->text().toDouble();
				a = (a * 100 + 0.5);
				int b = a;
				double c = b;
				c = c / 100;
				temp_table->item(i, 5)->setText(QString::number(c));

				//小数不够两位的添0
				c_count = 0;
				for (auto c : temp_table->item(i, 5)->text()) {
					if (c == '.') ++c_count;
				}
				if (c_count == 0) {
					temp_table->item(i, 5)->setText(temp_table->item(i, 5)->text() + ".00");
				}
				else if (c_count == 1) {
					if (temp_table->item(i, 5)->text()[temp_table->item(i, 5)->text().count() - 2] == '.') {
						temp_table->item(i, 5)->setText(temp_table->item(i, 5)->text() + "0");
					}
				}

				if (!btnUndo[2]->isHidden()) btnUndo[2]->hide();

				tableWidget->item(i, 7)->setText(temp_table->item(i, 5)->text());
				tableWidget->item(i, 8)->setText(temp_table->item(i, 6)->text());
				temp_table->item(i, 5)->setFlags(temp_table->item(i, 5)->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
				temp_table->item(i, 6)->setFlags(temp_table->item(i, 6)->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
				temp_table->item(i, 5)->setBackground(QBrush(QColor(224, 224, 224)));
				temp_table->item(i, 6)->setBackground(QBrush(QColor(224, 224, 224)));
				temp_table->item(i, 5)->setForeground(QBrush(QColor(0, 0, 0)));
				temp_table->item(i, 6)->setForeground(QBrush(QColor(0, 0, 0)));
				temp_btnHand->setEnabled(false);
				temp_btnHand->setStyleSheet(
					"QPushButton{image:url(Resources/havehandedup.png);background:url();background-color: rgb(224, 224, 224);border: 0px;}");
				QVector<QString> v_forCostAndDate;
				v_forCostAndDate.push_back(temp_table->item(i, 5)->text());
				v_forCostAndDate.push_back(temp_table->item(i, 6)->text());
				v_forCostAndDate.push_back(QString("%1#%2").arg(currentID).arg(QString::number(i + 1)));
				v_forCostAndDate.push_back(currentID);
				f = 0;
				for (int i = 0; i < temp_table->rowCount(); ++i) {
					if (tableWidget->item(i, 7)->text().isEmpty() || tableWidget->item(i, 8)->text().isEmpty()) {
						f = 1;
						break;
					}
				}
				if (f == 0) {
					this->state = State::已采购;
					v_forCostAndDate.push_back(QString::number(this->state));
				}
				else if (f == 1) {
					v_forCostAndDate.push_back(QString::number(0));
				}
				emit sig_forCostAndDate(v_forCostAndDate);
			});
		temp_table->setCellWidget(i, 7, temp_btnHand);

		QPushButton* temp_btnReturn = new QPushButton(widgetForCostAndDate);
		temp_btnReturn->setCursor(Qt::CursorShape::PointingHandCursor);
		temp_btnReturn->setStyleSheet(
			"QPushButton{image:url(Resources/return.png);background:url();background-color: rgb(224, 224, 224);border: 0px;}"
			"QPushButton:hover{image:url(Resources/return_red.png);}"
			"QPushButton:pressed{image:url(Resources/return_darkred.png);}");
		connect(temp_btnReturn, &QPushButton::clicked, [=]
			{
				QMessageBox box(QMessageBox::Question, "提示", "确认要重置吗？");
				box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
				box.setButtonText(QMessageBox::Ok, QString("确 定"));
				box.setButtonText(QMessageBox::Cancel, QString("取 消"));
				box.setWindowIcon(QPixmap("Resources/logo.png"));
				int button = box.exec();
				if (button != QMessageBox::Ok)
					return;
				temp_table->item(i, 5)->setText("");
				temp_table->item(i, 6)->setText("");
				tableWidget->item(i, 7)->setText("");
				tableWidget->item(i, 8)->setText("");

				bool f = 0;
				for (int i = 0; i < temp_table->rowCount(); ++i) {
					if ((!tableWidget->item(i, 7)->text().isEmpty()) || (!tableWidget->item(i, 8)->text().isEmpty())) {
						f = 1;
						break;
					}
				}
				if (f == 0) {
					btnUndo[2]->show();
				}

				temp_table->item(i, 5)->setFlags((Qt::ItemFlags)63);
				temp_table->item(i, 6)->setFlags((Qt::ItemFlags)63);
				temp_table->item(i, 5)->setBackground(QBrush(QColor(255, 255, 255)));
				temp_table->item(i, 6)->setBackground(QBrush(QColor(255, 255, 255)));
				temp_btnHand->setEnabled(true);
				temp_btnHand->setStyleSheet(
					"QPushButton{image:url(Resources/handup.png);background:url();background-color: rgb(224, 224, 224);border: 0px;}"
					"QPushButton:hover{image:url(Resources/handup_red.png);}"
					"QPushButton:pressed{image:url(Resources/handup_darkred.png);}");
				QVector<QString> v_forCostAndDate;
				v_forCostAndDate.push_back("NULL");
				v_forCostAndDate.push_back("");
				v_forCostAndDate.push_back(QString("%1#%2").arg(currentID).arg(QString::number(i + 1)));
				v_forCostAndDate.push_back(currentID);
				if (this->state == State::已采购) {
					this->state = State::三审;
					v_forCostAndDate.push_back(QString::number(State::三审));
				}
				else {
					v_forCostAndDate.push_back(QString::number(0));
				}
				emit sig_forCostAndDate(v_forCostAndDate);
			});
		temp_table->setCellWidget(i, 8, temp_btnReturn);

		temp_table->setRowHeight(i, 47);
	}
	temp_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
	temp_table->horizontalHeader()->setSectionResizeMode(6, QHeaderView::Stretch);
	temp_table->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(22, 82, 173); color:rgb(240, 240, 240);}");
	temp_table->setColumnWidth(0, 70);
	temp_table->setColumnWidth(1, 250);
	temp_table->setColumnWidth(2, 100);
	temp_table->setColumnWidth(3, 100);
	temp_table->setColumnWidth(4, 200);
	temp_table->setColumnWidth(5, 200);
	temp_table->setColumnWidth(7, 70);
	temp_table->setColumnWidth(8, 70);
	temp_table->show();
	int rowIndex = 0;
	for (auto it = v_v_forOpen_data.cbegin(); it != v_v_forOpen_data.cend(); ++it) {
		for (int i = 1; i < 5; ++i) {
			temp_table->item(rowIndex, i)->setText((*it)[i]);
		}
		for (int i = 7; i < 9; ++i) {
			temp_table->item(rowIndex, i - 2)->setText((*it)[i]);
			if (!temp_table->item(rowIndex, i - 2)->text().isEmpty()) {
				temp_table->item(rowIndex, i - 2)->setFlags(temp_table->item(rowIndex, i - 2)->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
				temp_table->item(rowIndex, i - 2)->setBackground(QBrush(QColor(224, 224, 224)));
				temp_table->item(rowIndex, i - 2)->setForeground(QBrush(QColor(0, 0, 0)));
				temp_table->cellWidget(rowIndex, 7)->setEnabled(false);
				temp_table->cellWidget(rowIndex, 7)->setStyleSheet(
					"QPushButton{image:url(Resources/havehandedup.png);background:url();background-color: rgb(224, 224, 224);border: 0px;}");
			}
		}
		++rowIndex;
	}

	QPushButton* temp_btnY = new QPushButton(widgetForCostAndDate);
	temp_btnY->setGeometry(QRect(620, 850, 360, 70));
	temp_btnY->setFont(QFont("楷体", 20));
	temp_btnY->setStyleSheet(QString::fromUtf8(
		"QPushButton{				             "
		"  border-style: outset;				 "
		"  border-width: 2px;					 "
		"  border-radius: 20px;				     "
		"  border-color: grey;				     "
		"}										 "
		"QPushButton:hover{"
		"  background-color: rgba(255, 255, 255, 102);"
		"}"
		"QPushButton:pressed{		             "
		"  border-style: inset;				     "
		"  background-color: rgba(255, 255, 255, 204);"
		"}										 "
	));
	temp_btnY->setText("确定");
	temp_btnY->show();

	connect(temp_btnY, &QPushButton::clicked, [=] {widgetForCostAndDate->close(); });
	connect(temp_table, &QTableWidget::cellDoubleClicked, this, &WidgetWZGL::oncellDoubleClicked);

}

void WidgetWZGL::oncellDoubleClicked(int row, int col) {

	if (col != 6) return;
	QObject* obj = this->sender();
	QTableWidget* temp_table = qobject_cast<QTableWidget*>(obj);
	temp_table->item(row, col)->setText(QString("%1/%2/%3").arg(QString::number(QDate::currentDate().year()))
		.arg(QString::number(QDate::currentDate().month())).arg(QString::number(QDate::currentDate().day())));

}

void WidgetWZGL::onBtnDeleteClicked() {

	if (state != State::待审核 && state != State::驳回) {
		QString c_state = "";
		switch (state)
		{
		case State::一审:c_state = "一审"; break;
		case State::二审:c_state = "二审"; break;
		case State::三审:case State::已采购:case State::已领用:c_state = "三审"; break;
		default:break;
		}
		QString temp = QString("此采购单已通过%1，不可删除!").arg(c_state);
		QMessageBox box(QMessageBox::Information, "提示", temp);
		box.setStandardButtons(QMessageBox::Ok);
		box.setButtonText(QMessageBox::Ok, QString("确 定"));
		box.setWindowIcon(QPixmap("Resources/logo.png"));
		int button = box.exec();
		return;
	}

	QMessageBox box(QMessageBox::Question, "提示", "删除后将不可恢复，确认要删除吗？");
	box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	box.setButtonText(QMessageBox::Ok, QString("确 定"));
	box.setButtonText(QMessageBox::Cancel, QString("取 消"));
	box.setWindowIcon(QPixmap("Resources/logo.png"));
	int button = box.exec();
	if (button != QMessageBox::Ok)
		return;

	emit sig_forDelete(currentID);

}

void WidgetWZGL::onsig_forSuccessfulDelete() {

	QMessageBox box(QMessageBox::Information, "提示", "删除成功！");
	box.setStandardButtons(QMessageBox::Ok);
	box.setButtonText(QMessageBox::Ok, QString("确 定"));
	box.setWindowIcon(QPixmap("Resources/logo.png"));
	int button = box.exec();
	emit sig_sendPurchaseData(comboBoxPro->currentText(), lineYear->text().toInt(),
		comboBoxMonth->currentText().mid(0, 2).toInt(), comboBoxState->currentIndex());
	onBtnCloseClicked();

}