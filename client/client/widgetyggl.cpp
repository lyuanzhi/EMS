#include "widgetyggl.h"

WidgetYGGL::WidgetYGGL(QWidget* parent)
	: QWidget(parent)
{
	setAttribute(Qt::WA_DeleteOnClose);
	this->setObjectName(QString::fromUtf8("WidgetYGGL"));
	this->resize(1920, 1000);
	QMetaObject::connectSlotsByName(this);

	style1 = QString::fromUtf8("QPushButton{background-color: rgba(0, 0, 0, 0);color: rgb(80, 80, 121); border: 0px;border-radius: 20px;}"
		"QPushButton:hover{background-color: rgba(0, 0, 0, 20);}");
	style2 = "QPushButton{background-color: rgba(80, 80, 121, 230);color: rgb(255, 255, 255); border: 0px;border-radius: 20px;}";

	line_1_in_widgetForPeople = NULL;
	line_2_in_widgetForPeople = NULL;
	cbx_3_in_widgetForPeople = NULL;
	cbx_4_in_widgetForPeople = NULL;
	line_5_in_widgetForPeople = NULL;
	line_6_in_widgetForPeople = NULL;
	line_7_in_widgetForPeople = NULL;
	line_8_in_widgetForPeople = NULL;
	line_9_in_widgetForPeople = NULL;
	line_10_in_widgetForPeople = NULL;
	line_11_in_widgetForPeople = NULL;
	line_12_in_widgetForPeople = NULL;
	line_13_in_widgetForPeople = NULL;
	cbx_14_in_widgetForPeople = NULL;
	line_15_in_widgetForPeople = NULL;
	line_16_in_widgetForPeople = NULL;
	line_17_in_widgetForPeople = NULL;
	line_18_in_widgetForPeople = NULL;
	line_19_in_widgetForPeople = NULL;
	cbx_20_in_widgetForPeople = NULL;
	line_21_in_widgetForPeople = NULL;
	line_22_in_widgetForPeople = NULL;
	label_pic_in_widgetForPeople = NULL;
	cbxsb = NULL;
	cbxgsx = NULL;
	cbxywx = NULL;
	cur_indexRow_da = 0;
	cur_indexRow_bx = 0;
	imagePath_in_widgetForPeople = "";

	tab = new QWidget();
	tab->setObjectName(QString::fromUtf8("tab"));
	tab->setStyleSheet(QString::fromUtf8("background-color: rgb(239, 237, 255);"));

	tab2 = new QWidget();
	tab2->setObjectName(QString::fromUtf8("tab2"));
	tab2->setStyleSheet(QString::fromUtf8("background-color: rgb(239, 237, 255);"));

	tabWidget = new QTabWidget(this);
	tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
	tabWidget->setGeometry(QRect(0, 0, 1920, 1000));
	tabWidget->setFont(QFont("方正行楷简体", 14));
	tabWidget->setAttribute(Qt::WA_StyledBackground);
	tabWidget->addTab(tab, QString("  员工管理  "));
	tabWidget->addTab(tab2, QString("  房屋信息  "));
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

	widgetLeft = new QWidget(tab);
	widgetLeft->setObjectName(QString::fromUtf8("widgetLeft"));
	widgetLeft->setGeometry(QRect(0, 0, 360, 970));
	widgetLeft->setStyleSheet(QString::fromUtf8("background-color: rgb(239, 237, 255);"));

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

	labelSelect = new QLabel(widgetLeft);
	labelSelect->setObjectName(QString::fromUtf8("labelSelect"));
	labelSelect->setGeometry(QRect(60, 180, 240, 40));
	labelSelect->setFont(QFont("宋体", 10));
	labelSelect->setStyleSheet("color:rgb(120,120,120);");
	labelSelect->setText("员工信息查询");

	for (int i = 0; i < 3; ++i) {
		btnSelect[i] = new QPushButton(widgetLeft);
		btnSelect[i]->setGeometry(QRect(30, 240 + i * 80, 300, 60));
		btnSelect[i]->setFont(QFont("宋体", 12));
		btnSelect[i]->setStyleSheet(style1);
		QIcon icon;
		icon.addFile(QString::fromUtf8("Resources/select_%1.png").arg(i), QSize(), QIcon::Normal, QIcon::Off);
		btnSelect[i]->setIcon(icon);
		btnSelect[i]->setIconSize(QSize(40, 40));
	}
	btnSelect[0]->setText(" 档案查询    ");
	btnSelect[1]->setText(" 保险查询    ");
	btnSelect[2]->setText(" 统计报表    ");

	labelHR = new QLabel(widgetLeft);
	labelHR->setObjectName(QString::fromUtf8("labelHR"));
	labelHR->setGeometry(QRect(60, 520, 240, 40));
	labelHR->setFont(QFont("宋体", 10));
	labelHR->setStyleSheet("color:rgb(120,120,120);");
	labelHR->setText("人事办理");

	for (int i = 0; i < 3; ++i) {
		btnHR[i] = new QPushButton(widgetLeft);
		btnHR[i]->setGeometry(QRect(30, 580 + i * 80, 300, 60));
		btnHR[i]->setFont(QFont("宋体", 12));
		btnHR[i]->setStyleSheet(style1);
		QIcon icon;
		icon.addFile(QString::fromUtf8("Resources/HR_%1.png").arg(i), QSize(), QIcon::Normal, QIcon::Off);
		btnHR[i]->setIcon(icon);
		btnHR[i]->setIconSize(QSize(40, 40));
	}
	btnHR[0]->setText(" 入职办理    ");
	btnHR[1]->setText(" 人事调动    ");
	btnHR[2]->setText(" 离职办理    ");

	stackedWidget = new QStackedWidget(tab);
	stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
	stackedWidget->setGeometry(QRect(360, 0, 1560, 950));

	QString scrollBarStyle1 = QString::fromUtf8(
		"QScrollBar:horizontal{"
		"height:30px;"
		"background:rgb(255, 239, 171);"
		"padding-top:1px;"
		"padding-bottom:7px;"
		"padding-left:40px;"
		"padding-right:40px;}"
		"QScrollBar::handle:horizontal{"
		"background:#dbdbdb;"
		"border-radius:10px;"
		"min-width:80px;}"
		"QScrollBar::handle:horizontal:hover{"
		"background:#d0d0d0;}"
		"QScrollBar::add-line:horizontal{"
		"background:url() center no-repeat;}"
		"QScrollBar::sub-line:horizontal{"
		"background:url() center no-repeat;}"
		"QScrollBar::add-page:horizontal{"
		"background-color:rgb(255, 239, 171);}"
		"QScrollBar::sub-page:horizontal{"
		"background-color:rgb(255, 239, 171);}"
	);

	QString scrollBarStyle2 = QString::fromUtf8(
		"QScrollBar:vertical{"
		"width:30px;"
		"background:rgb(255, 239, 171);"
		"padding-left:1px;"
		"padding-right:7px;"
		"padding-top:40px;"
		"padding-bottom:40px;}"
		"QScrollBar::handle:vertical{"
		"background:#dbdbdb;"
		"border-radius:10px;"
		"min-height:40px;}"
		"QScrollBar::handle:vertical:hover{"
		"background:#d0d0d0;}"
		"QScrollBar::add-line:vertical{"
		"background:url() center no-repeat;}"
		"QScrollBar::sub-line:vertical{"
		"background:url() center no-repeat;}"
		"QScrollBar::add-page:vertical{"
		"background-color:rgb(255, 239, 171);}"
		"QScrollBar::sub-page:vertical{"
		"background-color:rgb(255, 239, 171);}"
	);

	QFont font_1;
	font_1.setFamily("楷体");
	font_1.setPointSize(30);
	font_1.setBold(true);

	page_0 = new QWidget();
	page_0->setObjectName(QString::fromUtf8("page_0"));
	page_0->resize(4060, 920);
	page_0->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 239, 171);"));
	scrollArea_0 = new QScrollArea();
	scrollArea_0->setStyleSheet("border:0px;background-color: rgb(255, 239, 171);");
	scrollArea_0->horizontalScrollBar()->setStyleSheet(scrollBarStyle1);
	scrollArea_0->verticalScrollBar()->setStyleSheet(scrollBarStyle2);
	scrollArea_0->setWidget(page_0);
	label_0 = new QLabel(page_0);
	label_0->setGeometry(QRect(60, -30, 400, 200));
	label_0->setText("档案查询");
	label_0->setFont(font_1);
	connect(scrollArea_0->horizontalScrollBar(), &QScrollBar::valueChanged, this, &WidgetYGGL::onPage_0_scrollbar);

	page_1 = new QWidget();
	page_1->setObjectName(QString::fromUtf8("page_1"));
	page_1->resize(2190, 920);
	page_1->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 239, 171);"));
	scrollArea_1 = new QScrollArea();
	scrollArea_1->setStyleSheet("border:0px;background-color: rgb(255, 239, 171);");
	scrollArea_1->horizontalScrollBar()->setStyleSheet(scrollBarStyle1);
	scrollArea_1->verticalScrollBar()->setStyleSheet(scrollBarStyle2);
	scrollArea_1->setWidget(page_1);
	label_1 = new QLabel(page_1);
	label_1->setGeometry(QRect(60, -30, 400, 200));
	label_1->setText("保险查询");
	label_1->setFont(font_1);
	connect(scrollArea_1->horizontalScrollBar(), &QScrollBar::valueChanged, this, &WidgetYGGL::onPage_1_scrollbar);

	page_2 = new QWidget();
	page_2->setObjectName(QString::fromUtf8("page_2"));
	page_2->resize(2540, 920);
	page_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 239, 171);"));
	scrollArea_2 = new QScrollArea();
	scrollArea_2->setStyleSheet("border:0px;background-color: rgb(255, 239, 171);");
	scrollArea_2->horizontalScrollBar()->setStyleSheet(scrollBarStyle1);
	scrollArea_2->verticalScrollBar()->setStyleSheet(scrollBarStyle2);
	scrollArea_2->setWidget(page_2);
	label_2 = new QLabel(page_2);
	label_2->setGeometry(QRect(60, -30, 400, 200));
	label_2->setText("统计报表");
	label_2->setFont(font_1);
	connect(scrollArea_2->horizontalScrollBar(), &QScrollBar::valueChanged, this, &WidgetYGGL::onPage_2_scrollbar);

	page_3 = new QWidget();
	page_3->setObjectName(QString::fromUtf8("page_3"));
	page_3->resize(1530, 1950);
	page_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 239, 171);"));
	scrollArea_3 = new QScrollArea();
	scrollArea_3->setStyleSheet("border:0px;background-color: rgb(255, 239, 171);");
	scrollArea_3->horizontalScrollBar()->setStyleSheet(scrollBarStyle1);
	scrollArea_3->verticalScrollBar()->setStyleSheet(scrollBarStyle2);
	scrollArea_3->setWidget(page_3);
	label_3 = new QLabel(page_3);
	label_3->setGeometry(QRect(60, -30, 400, 200));
	label_3->setText("入职办理");
	label_3->setFont(font_1);
	connect(scrollArea_3->verticalScrollBar(), &QScrollBar::valueChanged, this, &WidgetYGGL::onPage_3_scrollbar);

	page_4 = new QWidget();
	page_4->setObjectName(QString::fromUtf8("page_4"));
	page_4->resize(1560, 950);
	page_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 239, 171);"));
	scrollArea_4 = new QScrollArea();
	scrollArea_4->setStyleSheet("border:0px;background-color: rgb(255, 239, 171);");
	scrollArea_4->horizontalScrollBar()->setStyleSheet(scrollBarStyle1);
	scrollArea_4->verticalScrollBar()->setStyleSheet(scrollBarStyle2);
	scrollArea_4->setWidget(page_4);
	QLabel* label_4 = new QLabel(page_4);
	label_4->setGeometry(QRect(60, -30, 400, 200));
	label_4->setText("人事调动");
	label_4->setFont(font_1);

	page_5 = new QWidget();
	page_5->setObjectName(QString::fromUtf8("page_5"));
	page_5->resize(1560, 950);
	page_5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 239, 171);"));
	scrollArea_5 = new QScrollArea();
	scrollArea_5->setStyleSheet("border:0px;background-color: rgb(255, 239, 171);");
	scrollArea_5->horizontalScrollBar()->setStyleSheet(scrollBarStyle1);
	scrollArea_5->verticalScrollBar()->setStyleSheet(scrollBarStyle2);
	scrollArea_5->setWidget(page_5);
	QLabel* label_5 = new QLabel(page_5);
	label_5->setGeometry(QRect(60, -30, 400, 200));
	label_5->setText("离职办理");
	label_5->setFont(font_1);

	//page_0
	cbx1_da = new QComboBox(page_0);
	cbx1_da->setFont(QFont("宋体", 13));
	cbx1_da->setGeometry(QRect(140, 150, 250, 60));
	cbx1_da->setFocusPolicy(Qt::NoFocus);
	cbx1_da->view()->verticalScrollBar()->setStyleSheet("QScrollBar:vertical{"//垂直滑块整体  
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
	cbx1_da->setStyleSheet(QString::fromUtf8(" QComboBox {"
		"      border: 1px solid rgb(200,200,200);"
		"      border-top-left-radius: 10px;"
		"      border-bottom-left-radius: 10px;"
		"      padding: 1px 0px 1px 3px;"
		"      background-color: rgb(255, 255, 255);"
		"  }"
		"  QComboBox:on {"
		"      border: 1px solid rgb(0, 170, 255);"
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
		"  QComboBox::down-arrow{"
		"      image: url(Resources/下拉.png);"
		"  }"
		"  QComboBox::down-arrow:on{"
		"      image: url(Resources/下拉_1.png);"
		"  }"
		"  QComboBox:hover{"
		"      background-color: rgb(245, 245, 245);"
		"  }"
	));
	cbx1_da->addItem(QString::fromUtf8("姓名"));
	cbx1_da->addItem(QString::fromUtf8("项目"));
	cbx1_da->addItem(QString::fromUtf8("性别"));
	cbx1_da->addItem(QString::fromUtf8("年龄"));
	cbx1_da->addItem(QString::fromUtf8("合同"));
	cbx1_da->addItem(QString::fromUtf8("职务"));
	cbx1_da->addItem(QString::fromUtf8("部门"));
	cbx1_da->addItem(QString::fromUtf8("工号牌"));
	cbx1_da->addItem(QString::fromUtf8("身份证号"));
	cbx1_da->addItem(QString::fromUtf8("籍贯"));
	cbx1_da->addItem(QString::fromUtf8("民族"));
	cbx1_da->addItem(QString::fromUtf8("电话"));
	cbx1_da->addItem(QString::fromUtf8("应急电话"));
	cbx1_da->addItem(QString::fromUtf8("入职时间"));
	cbx1_da->addItem(QString::fromUtf8("生日"));
	cbx1_da->addItem(QString::fromUtf8("学历"));
	cbx1_da->addItem(QString::fromUtf8("专业"));
	cbx1_da->addItem(QString::fromUtf8("证书"));
	cbx1_da->addItem(QString::fromUtf8("职称"));
	cbx1_da->addItem(QString::fromUtf8("特长"));
	cbx1_da->addItem(QString::fromUtf8("健康状况"));
	cbx1_da->addItem(QString::fromUtf8("婚姻状况"));
	cbx1_da->addItem(QString::fromUtf8("政治面貌"));
	cbx1_da->addItem(QString::fromUtf8("在职状态"));
	cbx1_da->addItem(QString::fromUtf8("离职时间"));
	qItemModel = qobject_cast<QStandardItemModel*>(cbx1_da->model());
	for (int i = 0; i < cbx1_da->count(); ++i) qItemModel->item(i)->setBackground(QBrush(QColor(255, 255, 255)));

	cbx2_da = new QComboBox(page_0);
	cbx2_da->setFont(QFont("宋体", 13));
	cbx2_da->setGeometry(QRect(390, 150, 250, 60));
	cbx2_da->setFocusPolicy(Qt::NoFocus);
	cbx2_da->view()->verticalScrollBar()->setStyleSheet("QScrollBar:vertical{"//垂直滑块整体  
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
	cbx2_da->setStyleSheet(QString::fromUtf8(" QComboBox {"
		"      border: 1px solid rgb(200,200,200);"
		"      padding: 1px 0px 1px 3px;"
		"      background-color: rgb(255, 255, 255);"
		"  }"
		"  QComboBox:on {"
		"      border: 1px solid rgb(0, 170, 255);"
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
		"  QComboBox::down-arrow{"
		"      image: url(Resources/下拉.png);"
		"  }"
		"  QComboBox::down-arrow:on{"
		"      image: url(Resources/下拉_1.png);"
		"  }"
		"  QComboBox:hover{"
		"      background-color: rgb(245, 245, 245);"
		"  }"
	));
	cbx2_da->addItem(QString::fromUtf8("全部"));
	cbx2_da->addItem(QString::fromUtf8("包含"));
	cbx2_da->addItem(QString::fromUtf8("不包含"));
	cbx2_da->addItem(QString::fromUtf8("等于"));
	cbx2_da->addItem(QString::fromUtf8("不等于"));
	QStandardItemModel* qItemModel_temp = qobject_cast<QStandardItemModel*>(cbx2_da->model());
	for (int i = 0; i < cbx2_da->count(); ++i) qItemModel_temp->item(i)->setBackground(QBrush(QColor(255, 255, 255)));

	connect(cbx1_da, &QComboBox::currentTextChanged, [=]
		{
			cbx2_da->clear();
			if (cbx1_da->currentText() == "年龄" || cbx1_da->currentText() == "入职时间" || cbx1_da->currentText() == "生日"
				|| cbx1_da->currentText() == "离职时间") {
				cbx2_da->addItem(QString::fromUtf8("全部"));
				cbx2_da->addItem(QString::fromUtf8("包含"));
				cbx2_da->addItem(QString::fromUtf8("不包含"));
				cbx2_da->addItem(QString::fromUtf8("等于"));
				cbx2_da->addItem(QString::fromUtf8("不等于"));
				cbx2_da->addItem(QString::fromUtf8("大于"));
				cbx2_da->addItem(QString::fromUtf8("大于或等于"));
				cbx2_da->addItem(QString::fromUtf8("小于"));
				cbx2_da->addItem(QString::fromUtf8("小于或等于"));
				QStandardItemModel* qItemModel_temp = qobject_cast<QStandardItemModel*>(cbx2_da->model());
				for (int i = 0; i < cbx2_da->count(); ++i) qItemModel_temp->item(i)->setBackground(QBrush(QColor(255, 255, 255)));
			}
			else {
				cbx2_da->addItem(QString::fromUtf8("全部"));
				cbx2_da->addItem(QString::fromUtf8("包含"));
				cbx2_da->addItem(QString::fromUtf8("不包含"));
				cbx2_da->addItem(QString::fromUtf8("等于"));
				cbx2_da->addItem(QString::fromUtf8("不等于"));
				QStandardItemModel* qItemModel_temp = qobject_cast<QStandardItemModel*>(cbx2_da->model());
				for (int i = 0; i < cbx2_da->count(); ++i) qItemModel_temp->item(i)->setBackground(QBrush(QColor(255, 255, 255)));
			}
		}
	);

	line3_da = new MyLineEdit(page_0);
	line3_da->setFont(QFont("宋体", 13));
	line3_da->setGeometry(QRect(640, 150, 400, 60));
	line3_da->setPlaceholderText("请输入相应的值");
	line3_da->setStyleSheet(QString::fromUtf8(
		"QLineEdit{ background-color:rgb(255,255,255);"
		"border: 1px solid rgb(200,200,200);}"
		"QLineEdit:hover{background-color: rgb(245, 245, 245);}"
		"QLineEdit:focus{border: 1px solid rgb(0, 170, 255);background-color:rgb(255,255,255);}"));

	btn4_da = new QPushButton(page_0);
	btn4_da->setGeometry(QRect(1040, 150, 70, 60));
	btn4_da->setStyleSheet(QString::fromUtf8(
		"QPushButton{				             "
		"  image:url(Resources/search_white.png);"
		"  background-color: rgb(3, 126, 243);   "
		"  border-width: 1px;					 "
		"  border-top-right-radius: 10px;	     "
		"  border-bottom-right-radius: 10px;     "
		"  border-color: rgb(200,200,200);	     "
		"}										 "
		"QPushButton:hover{                      "
		"  background-color: rgb(0, 170, 255);   "
		"}                                       "
		"QPushButton:pressed{		             "
		"  background-color: rgb(20, 190, 255);  "
		"}										 "
	));

	QStringList qStringList;
	qStringList << "" << "项目" << "姓名" << "性别" << "年龄" << "合同" << "职务" << "部门" << "工号牌"
		<< "身份证号" << "籍贯" << "民族" << "电话" << "应急电话" << "入职时间" << "生日" << "学历"
		<< "专业" << "证书" << "职称" << "特长" << "健康状况" << "婚姻状况" << "政治面貌" << "在职状态" << "离职时间";
	tableView_da = new QTableView(page_0);
	qItemModel_da = new QStandardItemModel(page_0);
	tableView_da->setGeometry(QRect(100, 230, 3900, 660));
	tableView_da->setFocusPolicy(Qt::FocusPolicy::NoFocus);
	tableView_da->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
	qItemModel_da->setHorizontalHeaderLabels(qStringList);
	tableView_da->horizontalHeader()->setFont(QFont("宋体", 9));
	tableView_da->horizontalHeader()->setFixedHeight(47);
	tableView_da->verticalHeader()->hide();
	tableView_da->setModel(qItemModel_da);
	tableView_da->setColumnWidth(0, 60);
	tableView_da->setColumnWidth(1, 200);
	tableView_da->setColumnWidth(2, 120);
	tableView_da->setColumnWidth(3, 80);
	tableView_da->setColumnWidth(4, 80);
	tableView_da->setColumnWidth(5, 220);
	tableView_da->setColumnWidth(6, 150);
	tableView_da->setColumnWidth(7, 180);
	tableView_da->setColumnWidth(8, 100);
	tableView_da->setColumnWidth(9, 280);
	tableView_da->setColumnWidth(10, 300);
	tableView_da->setColumnWidth(11, 80);
	tableView_da->setColumnWidth(12, 180);
	tableView_da->setColumnWidth(13, 180);
	tableView_da->setColumnWidth(14, 180);
	tableView_da->setColumnWidth(15, 180);
	tableView_da->setColumnWidth(16, 120);
	tableView_da->setColumnWidth(17, 120);
	tableView_da->setColumnWidth(18, 120);
	tableView_da->setColumnWidth(19, 120);
	tableView_da->setColumnWidth(20, 120);
	tableView_da->setColumnWidth(21, 120);
	tableView_da->setColumnWidth(22, 120);
	tableView_da->setColumnWidth(23, 150);
	tableView_da->setColumnWidth(24, 120);
	tableView_da->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::Fixed);
	tableView_da->horizontalHeader()->setSectionResizeMode(25, QHeaderView::ResizeMode::Stretch);
	tableView_da->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(22, 82, 173); color:rgb(240, 240, 240);}");
	tableView_da->horizontalHeader()->setHighlightSections(false);
	tableView_da->verticalHeader()->setMinimumSectionSize(47);
	tableView_da->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::ResizeToContents);
	tableView_da->setAttribute(Qt::WA_StyledBackground);
	tableView_da->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);border:1px solid grey;gridline-color: rgb(0, 0, 0);"));
	tableView_da->setFrameShape(QFrame::Shape::Box);
	tableView_da->verticalScrollBar()->setStyleSheet("QScrollBar:vertical{"//垂直滑块整体  
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

	//page_1
	cbx1_bx = new QComboBox(page_1);
	cbx1_bx->setFont(QFont("宋体", 13));
	cbx1_bx->setGeometry(QRect(140, 150, 250, 60));
	cbx1_bx->setFocusPolicy(Qt::NoFocus);
	cbx1_bx->view()->verticalScrollBar()->setStyleSheet("QScrollBar:vertical{"//垂直滑块整体  
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
	cbx1_bx->setStyleSheet(QString::fromUtf8(" QComboBox {"
		"      border: 1px solid rgb(200,200,200);"
		"      border-top-left-radius: 10px;"
		"      border-bottom-left-radius: 10px;"
		"      padding: 1px 0px 1px 3px;"
		"      background-color: rgb(255, 255, 255);"
		"  }"
		"  QComboBox:on {"
		"      border: 1px solid rgb(0, 170, 255);"
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
		"  QComboBox::down-arrow{"
		"      image: url(Resources/下拉.png);"
		"  }"
		"  QComboBox::down-arrow:on{"
		"      image: url(Resources/下拉_1.png);"
		"  }"
		"  QComboBox:hover{"
		"      background-color: rgb(245, 245, 245);"
		"  }"
	));
	cbx1_bx->addItem(QString::fromUtf8("全部人员"));
	cbx1_bx->addItem(QString::fromUtf8("全部离职人员"));
	cbx1_bx->addItem(QString::fromUtf8("全部在职人员"));
	cbx1_bx->addItem(QString::fromUtf8("本月离职人员"));
	qItemModel = qobject_cast<QStandardItemModel*>(cbx1_bx->model());
	for (int i = 0; i < cbx1_bx->count(); ++i) qItemModel->item(i)->setBackground(QBrush(QColor(255, 255, 255)));

	cbx2_bx = new QComboBox(page_1);
	cbx2_bx->setFont(QFont("宋体", 13));
	cbx2_bx->setGeometry(QRect(390, 150, 250, 60));
	cbx2_bx->setFocusPolicy(Qt::NoFocus);
	cbx2_bx->view()->verticalScrollBar()->setStyleSheet("QScrollBar:vertical{"//垂直滑块整体  
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
	cbx2_bx->setStyleSheet(QString::fromUtf8(" QComboBox {"
		"      border: 1px solid rgb(200,200,200);"
		"      padding: 1px 0px 1px 3px;"
		"      background-color: rgb(255, 255, 255);"
		"  }"
		"  QComboBox:on {"
		"      border: 1px solid rgb(0, 170, 255);"
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
		"  QComboBox::down-arrow{"
		"      image: url(Resources/下拉.png);"
		"  }"
		"  QComboBox::down-arrow:on{"
		"      image: url(Resources/下拉_1.png);"
		"  }"
		"  QComboBox:hover{"
		"      background-color: rgb(245, 245, 245);"
		"  }"
	));
	cbx2_bx->addItem(QString::fromUtf8("全部"));
	cbx2_bx->addItem(QString::fromUtf8("有社保"));
	cbx2_bx->addItem(QString::fromUtf8("有工伤险"));
	cbx2_bx->addItem(QString::fromUtf8("有意外险"));
	cbx2_bx->addItem(QString::fromUtf8("无三险"));
	qItemModel = qobject_cast<QStandardItemModel*>(cbx2_bx->model());
	for (int i = 0; i < cbx2_bx->count(); ++i) qItemModel->item(i)->setBackground(QBrush(QColor(255, 255, 255)));

	cbx3_bx = new QComboBox(page_1);
	cbx3_bx->setFont(QFont("宋体", 11));
	cbx3_bx->setGeometry(QRect(640, 150, 550, 60));
	cbx3_bx->setFocusPolicy(Qt::NoFocus);
	cbx3_bx->view()->verticalScrollBar()->setStyleSheet("QScrollBar:vertical{"//垂直滑块整体  
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
	cbx3_bx->setStyleSheet(QString::fromUtf8(" QComboBox {"
		"      border: 1px solid rgb(200,200,200);"
		"      padding: 1px 0px 1px 3px;"
		"      background-color: rgb(255, 255, 255);"
		"  }"
		"  QComboBox:on {"
		"      border: 1px solid rgb(0, 170, 255);"
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
		"  QComboBox::down-arrow{"
		"      image: url(Resources/下拉.png);"
		"  }"
		"  QComboBox::down-arrow:on{"
		"      image: url(Resources/下拉_1.png);"
		"  }"
		"  QComboBox:hover{"
		"      background-color: rgb(245, 245, 245);"
		"  }"
	));
	cbx3_bx->addItem(QString::fromUtf8("不限男女，不限年龄"));
	cbx3_bx->addItem(QString::fromUtf8("不限男女，65周岁以下"));
	cbx3_bx->addItem(QString::fromUtf8("年龄男在60周岁以下或女在50周岁以下"));
	qItemModel = qobject_cast<QStandardItemModel*>(cbx3_bx->model());
	for (int i = 0; i < cbx3_bx->count(); ++i) qItemModel->item(i)->setBackground(QBrush(QColor(255, 255, 255)));

	btn4_bx = new QPushButton(page_1);
	btn4_bx->setGeometry(QRect(1190, 150, 70, 60));
	btn4_bx->setStyleSheet(QString::fromUtf8(
		"QPushButton{				             "
		"  image:url(Resources/search_white.png);"
		"  background-color: rgb(3, 126, 243);   "
		"  border-width: 1px;					 "
		"  border-top-right-radius: 10px;	     "
		"  border-bottom-right-radius: 10px;     "
		"  border-color: rgb(200,200,200);	     "
		"}										 "
		"QPushButton:hover{                      "
		"  background-color: rgb(0, 170, 255);   "
		"}                                       "
		"QPushButton:pressed{		             "
		"  background-color: rgb(20, 190, 255);  "
		"}										 "
	));

	qStringList.clear();
	qStringList << "" << "项目" << "姓名" << "性别" << "年龄" << "社保" << "工伤险" << "意外险" << "身份证号" << "籍贯"
		<< "电话" << "在职状态" << "离职时间";
	tableView_bx = new QTableView(page_1);
	qItemModel_bx = new QStandardItemModel(page_1);
	tableView_bx->setGeometry(QRect(100, 230, 2010, 660));
	tableView_bx->setFocusPolicy(Qt::FocusPolicy::NoFocus);
	tableView_bx->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
	tableView_bx->horizontalHeader()->setHighlightSections(false);
	qItemModel_bx->setHorizontalHeaderLabels(qStringList);
	tableView_bx->horizontalHeader()->setFont(QFont("宋体", 9));
	tableView_bx->horizontalHeader()->setFixedHeight(47);
	tableView_bx->verticalHeader()->hide();
	tableView_bx->setModel(qItemModel_bx);
	tableView_bx->setColumnWidth(0, 60);
	tableView_bx->setColumnWidth(1, 200);
	tableView_bx->setColumnWidth(2, 120);
	tableView_bx->setColumnWidth(3, 80);
	tableView_bx->setColumnWidth(4, 80);
	tableView_bx->setColumnWidth(5, 120);
	tableView_bx->setColumnWidth(6, 120);
	tableView_bx->setColumnWidth(7, 120);
	tableView_bx->setColumnWidth(8, 280);
	tableView_bx->setColumnWidth(9, 300);
	tableView_bx->setColumnWidth(10, 180);
	tableView_bx->setColumnWidth(11, 150);
	tableView_bx->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::Fixed);
	tableView_bx->horizontalHeader()->setSectionResizeMode(12, QHeaderView::ResizeMode::Stretch);
	tableView_bx->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(22, 82, 173); color:rgb(240, 240, 240);}");
	tableView_bx->verticalHeader()->setMinimumSectionSize(47);
	tableView_bx->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::ResizeToContents);
	tableView_bx->setAttribute(Qt::WA_StyledBackground);
	tableView_bx->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);border:1px solid grey;gridline-color: rgb(0, 0, 0);"));
	tableView_bx->setFrameShape(QFrame::Shape::Box);
	tableView_bx->verticalScrollBar()->setStyleSheet("QScrollBar:vertical{"//垂直滑块整体  
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

	//page_2
	//这个表格来一个两行表头分下类
	qStringList.clear();
	qStringList << "项目" << "在岗" << "合同" << "超龄" << "客服" << "工程"
		<< "秩序" << "绿化" << "保洁" << "行政" << "经理" << "后勤"
		<< "籍贯" << "民族" << "性别" << "婚姻" << "学历" << "职称"
		<< "证书" << "党员" << "社保" << "工伤险" << "意外险" << "离职";
	tableView_total = new QTableView(page_2);
	qItemModel_total = new QStandardItemModel(page_2);
	tableView_total->setGeometry(QRect(100, 160, 2340, 702));
	tableView_total->setFocusPolicy(Qt::FocusPolicy::NoFocus);
	tableView_total->horizontalHeader()->setFont(QFont("宋体", 9));
	tableView_total->horizontalHeader()->setSectionsClickable(false);
	tableView_total->horizontalHeader()->setFixedHeight(50);
	tableView_total->verticalHeader()->hide();
	qItemModel_total->setHorizontalHeaderLabels(qStringList);
	tableView_total->setModel(qItemModel_total);
	tableView_total->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	tableView_total->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
	tableView_total->setColumnWidth(0, 200);
	tableView_total->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(22, 82, 173); color:rgb(240, 240, 240);}");
	tableView_total->setAttribute(Qt::WA_StyledBackground);
	tableView_total->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);border:1px solid grey;gridline-color: rgb(0, 0, 0);"));
	tableView_total->setFrameShape(QFrame::Shape::Box);
	tableView_total->verticalScrollBar()->setStyleSheet("QScrollBar:vertical{"//垂直滑块整体  
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
	qItemModel_total->setItem(0, 0, new QStandardItem("公司总部"));
	qItemModel_total->setItem(1, 0, new QStandardItem("文鼎公寓"));
	qItemModel_total->setItem(2, 0, new QStandardItem("望湖家园"));
	qItemModel_total->setItem(3, 0, new QStandardItem("金城一区"));
	qItemModel_total->setItem(4, 0, new QStandardItem("江南小区"));
	qItemModel_total->setItem(5, 0, new QStandardItem("东方国际村"));
	qItemModel_total->setItem(6, 0, new QStandardItem("嘉鸿华庭"));
	qItemModel_total->setItem(7, 0, new QStandardItem("阳光都市"));
	qItemModel_total->setItem(8, 0, new QStandardItem("银河证券"));
	qItemModel_total->setItem(9, 0, new QStandardItem("春晗公寓"));
	qItemModel_total->setItem(10, 0, new QStandardItem("文化旅游局"));
	qItemModel_total->setItem(11, 0, new QStandardItem("中厦国际保安"));
	qItemModel_total->setItem(12, 0, new QStandardItem("总计"));
	for (int i = 0; i < 13; ++i) {
		tableView_total->setRowHeight(i, 50);
		qItemModel_total->item(i, 0)->setTextAlignment(Qt::AlignCenter);
	}
	for (int cur_row = 0; cur_row < 13; ++cur_row) {
		for (int i = 0; i < 23; ++i) {
			qItemModel_total->setItem(cur_row, i + 1, new QStandardItem());
			qItemModel_total->item(cur_row, i + 1)->setFlags(qItemModel_total->item(cur_row, i + 1)->flags() & ~Qt::ItemIsEditable);
			qItemModel_total->item(cur_row, i + 1)->setTextAlignment(Qt::AlignCenter);
		}
	}

	int length = tableView_total->horizontalHeader()->sectionPosition(13) - tableView_total->horizontalHeader()->sectionPosition(12);
	toolBtn12_total = new QToolButton(tableView_total->horizontalHeader());
	toolBtn12_total->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonIconOnly);
	QMenu* menu12_total = new QMenu(toolBtn12_total);
	menu12_total->addAction(QString::fromUtf8("义乌本地"));
	menu12_total->actions()[0]->setIcon(QIcon("Resources/选中.png"));
	menu12_total->addSeparator();
	menu12_total->addAction(QString::fromUtf8("浙江省"));
	menu12_total->addSeparator();
	menu12_total->addAction(QString::fromUtf8("外省"));
	menu12_total->setStyleSheet(
		"QMenu {background-color:white;}"
		"QMenu::item {padding: 2px 25px 2px 25px;border: 1px solid transparent;}"
		"QMenu::item:selected:enabled {border-color: rgb(250, 170, 60);background: rgba(250, 170, 60, 50);}"
		"QMenu::separator {height: 2px;background: rgb(168, 216, 235);margin-left: 10px;margin-right: 10px;}"
		"QMenu::indicator {width: 13px;height: 13px;}"
	);
	toolBtn12_total->setPopupMode(QToolButton::InstantPopup);
	toolBtn12_total->setMenu(menu12_total);
	toolBtn12_total->setStyleSheet("QToolButton{background:transparent;border: 0px;}"
		"QToolButton::menu-indicator{image:url(Resources/下拉框.png);position: relative; bottom: 4px; right: 4px; }"
		"QToolButton::menu-indicator:pressed{image:url(Resources/反下拉框.png);position: relative; bottom: 2px; right: 2px; }"
	);
	toolBtn12_total->resize(length, 50);
	toolBtn12_total->move(tableView_total->horizontalHeader()->sectionPosition(12) - 2, 0);

	toolBtn13_total = new QToolButton(tableView_total->horizontalHeader());
	toolBtn13_total->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonIconOnly);
	QMenu* menu13_total = new QMenu(toolBtn13_total);
	menu13_total->addAction(QString::fromUtf8("汉族"));
	menu13_total->actions()[0]->setIcon(QIcon("Resources/选中.png"));
	menu13_total->addSeparator();
	menu13_total->addAction(QString::fromUtf8("少数民族"));
	menu13_total->setStyleSheet(
		"QMenu {background-color:white;}"
		"QMenu::item {padding: 2px 25px 2px 25px;border: 1px solid transparent;}"
		"QMenu::item:selected:enabled {border-color: rgb(250, 170, 60);background: rgba(250, 170, 60, 50);}"
		"QMenu::separator {height: 2px;background: rgb(168, 216, 235);margin-left: 10px;margin-right: 10px;}"
		"QMenu::indicator {width: 13px;height: 13px;}"
	);
	toolBtn13_total->setPopupMode(QToolButton::InstantPopup);
	toolBtn13_total->setMenu(menu13_total);
	toolBtn13_total->setStyleSheet("QToolButton{background:transparent;border: 0px;}"
		"QToolButton::menu-indicator{image:url(Resources/下拉框.png);position: relative; bottom: 4px; right: 4px; }"
		"QToolButton::menu-indicator:pressed{image:url(Resources/反下拉框.png);position: relative; bottom: 2px; right: 2px; }"
	);
	toolBtn13_total->resize(length, 50);
	toolBtn13_total->move(tableView_total->horizontalHeader()->sectionPosition(13) - 2, 0);

	toolBtn14_total = new QToolButton(tableView_total->horizontalHeader());
	toolBtn14_total->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonIconOnly);
	QMenu* menu14_total = new QMenu(toolBtn14_total);
	menu14_total->addAction(QString::fromUtf8("男"));
	menu14_total->actions()[0]->setIcon(QIcon("Resources/选中.png"));
	menu14_total->addSeparator();
	menu14_total->addAction(QString::fromUtf8("女"));
	menu14_total->setStyleSheet(
		"QMenu {background-color:white;}"
		"QMenu::item {padding: 2px 25px 2px 25px;border: 1px solid transparent;}"
		"QMenu::item:selected:enabled {border-color: rgb(250, 170, 60);background: rgba(250, 170, 60, 50);}"
		"QMenu::separator {height: 2px;background: rgb(168, 216, 235);margin-left: 10px;margin-right: 10px;}"
		"QMenu::indicator {width: 13px;height: 13px;}"
	);
	toolBtn14_total->setPopupMode(QToolButton::InstantPopup);
	toolBtn14_total->setMenu(menu14_total);
	toolBtn14_total->setStyleSheet("QToolButton{background:transparent;border: 0px;}"
		"QToolButton::menu-indicator{image:url(Resources/下拉框.png);position: relative; bottom: 4px; right: 4px; }"
		"QToolButton::menu-indicator:pressed{image:url(Resources/反下拉框.png);position: relative; bottom: 2px; right: 2px; }"
	);
	toolBtn14_total->resize(length, 50);
	toolBtn14_total->move(tableView_total->horizontalHeader()->sectionPosition(14) - 2, 0);

	toolBtn15_total = new QToolButton(tableView_total->horizontalHeader());
	toolBtn15_total->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonIconOnly);
	QMenu* menu15_total = new QMenu(toolBtn15_total);
	menu15_total->addAction(QString::fromUtf8("已婚"));
	menu15_total->actions()[0]->setIcon(QIcon("Resources/选中.png"));
	menu15_total->addSeparator();
	menu15_total->addAction(QString::fromUtf8("未婚"));
	menu15_total->setStyleSheet(
		"QMenu {background-color:white;}"
		"QMenu::item {padding: 2px 25px 2px 25px;border: 1px solid transparent;}"
		"QMenu::item:selected:enabled {border-color: rgb(250, 170, 60);background: rgba(250, 170, 60, 50);}"
		"QMenu::separator {height: 2px;background: rgb(168, 216, 235);margin-left: 10px;margin-right: 10px;}"
		"QMenu::indicator {width: 13px;height: 13px;}"
	);
	toolBtn15_total->setPopupMode(QToolButton::InstantPopup);
	toolBtn15_total->setMenu(menu15_total);
	toolBtn15_total->setStyleSheet("QToolButton{background:transparent;border: 0px;}"
		"QToolButton::menu-indicator{image:url(Resources/下拉框.png);position: relative; bottom: 4px; right: 4px; }"
		"QToolButton::menu-indicator:pressed{image:url(Resources/反下拉框.png);position: relative; bottom: 2px; right: 2px; }"
	);
	toolBtn15_total->resize(length, 50);
	toolBtn15_total->move(tableView_total->horizontalHeader()->sectionPosition(15) - 2, 0);

	toolBtn16_total = new QToolButton(tableView_total->horizontalHeader());
	toolBtn16_total->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonIconOnly);
	QMenu* menu16_total = new QMenu(toolBtn16_total);
	menu16_total->addAction(QString::fromUtf8("研究生"));
	menu16_total->actions()[0]->setIcon(QIcon("Resources/选中.png"));
	menu16_total->addSeparator();
	menu16_total->addAction(QString::fromUtf8("本科"));
	menu16_total->addSeparator();
	menu16_total->addAction(QString::fromUtf8("专科"));
	menu16_total->addSeparator();
	menu16_total->addAction(QString::fromUtf8("高中"));
	menu16_total->addSeparator();
	menu16_total->addAction(QString::fromUtf8("初中"));
	menu16_total->addSeparator();
	menu16_total->addAction(QString::fromUtf8("小学"));
	menu16_total->setStyleSheet(
		"QMenu {background-color:white;}"
		"QMenu::item {padding: 2px 25px 2px 25px;border: 1px solid transparent;}"
		"QMenu::item:selected:enabled {border-color: rgb(250, 170, 60);background: rgba(250, 170, 60, 50);}"
		"QMenu::separator {height: 2px;background: rgb(168, 216, 235);margin-left: 10px;margin-right: 10px;}"
		"QMenu::indicator {width: 13px;height: 13px;}"
	);
	toolBtn16_total->setPopupMode(QToolButton::InstantPopup);
	toolBtn16_total->setMenu(menu16_total);
	toolBtn16_total->setStyleSheet("QToolButton{background:transparent;border: 0px;}"
		"QToolButton::menu-indicator{image:url(Resources/下拉框.png);position: relative; bottom: 4px; right: 4px; }"
		"QToolButton::menu-indicator:pressed{image:url(Resources/反下拉框.png);position: relative; bottom: 2px; right: 2px; }"
	);
	toolBtn16_total->resize(length, 50);
	toolBtn16_total->move(tableView_total->horizontalHeader()->sectionPosition(16) - 2, 0);

	toolBtn17_total = new QToolButton(tableView_total->horizontalHeader());
	toolBtn17_total->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonIconOnly);
	QMenu* menu17_total = new QMenu(toolBtn17_total);
	menu17_total->addAction(QString::fromUtf8("初级工程师"));
	menu17_total->actions()[0]->setIcon(QIcon("Resources/选中.png"));
	menu17_total->addSeparator();
	menu17_total->addAction(QString::fromUtf8("中级工程师"));
	menu17_total->addSeparator();
	menu17_total->addAction(QString::fromUtf8("高级工程师"));
	menu17_total->setStyleSheet(
		"QMenu {background-color:white;}"
		"QMenu::item {padding: 2px 25px 2px 25px;border: 1px solid transparent;}"
		"QMenu::item:selected:enabled {border-color: rgb(250, 170, 60);background: rgba(250, 170, 60, 50);}"
		"QMenu::separator {height: 2px;background: rgb(168, 216, 235);margin-left: 10px;margin-right: 10px;}"
		"QMenu::indicator {width: 13px;height: 13px;}"
	);
	toolBtn17_total->setPopupMode(QToolButton::InstantPopup);
	toolBtn17_total->setMenu(menu17_total);
	toolBtn17_total->setStyleSheet("QToolButton{background:transparent;border: 0px;}"
		"QToolButton::menu-indicator{image:url(Resources/下拉框.png);position: relative; bottom: 4px; right: 4px; }"
		"QToolButton::menu-indicator:pressed{image:url(Resources/反下拉框.png);position: relative; bottom: 2px; right: 2px; }"
	);
	toolBtn17_total->resize(length, 50);
	toolBtn17_total->move(tableView_total->horizontalHeader()->sectionPosition(17) - 2, 0);

	toolBtn18_total = new QToolButton(tableView_total->horizontalHeader());
	toolBtn18_total->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonIconOnly);
	QMenu* menu18_total = new QMenu(toolBtn18_total);
	menu18_total->addAction(QString::fromUtf8("建(构)筑物消防员证"));
	menu18_total->actions()[0]->setIcon(QIcon("Resources/选中.png"));
	menu18_total->addSeparator();
	menu18_total->addAction(QString::fromUtf8("消防管理员证"));
	menu18_total->addSeparator();
	menu18_total->addAction(QString::fromUtf8("电工证"));
	menu18_total->addSeparator();
	menu18_total->addAction(QString::fromUtf8("特种设备证"));
	menu18_total->addSeparator();
	menu18_total->addAction(QString::fromUtf8("保安证"));
	menu18_total->setStyleSheet(
		"QMenu {background-color:white;}"
		"QMenu::item {padding: 2px 25px 2px 25px;border: 1px solid transparent;}"
		"QMenu::item:selected:enabled {border-color: rgb(250, 170, 60);background: rgba(250, 170, 60, 50);}"
		"QMenu::separator {height: 2px;background: rgb(168, 216, 235);margin-left: 10px;margin-right: 10px;}"
		"QMenu::indicator {width: 13px;height: 13px;}"
	);
	toolBtn18_total->setPopupMode(QToolButton::InstantPopup);
	toolBtn18_total->setMenu(menu18_total);
	toolBtn18_total->setStyleSheet("QToolButton{background:transparent;border: 0px;}"
		"QToolButton::menu-indicator{image:url(Resources/下拉框.png);position: relative; bottom: 4px; right: 4px; }"
		"QToolButton::menu-indicator:pressed{image:url(Resources/反下拉框.png);position: relative; bottom: 2px; right: 2px; }"
	);
	toolBtn18_total->resize(length, 50);
	toolBtn18_total->move(tableView_total->horizontalHeader()->sectionPosition(18) - 2, 0);

	toolBtn23_total = new QToolButton(tableView_total->horizontalHeader());
	toolBtn23_total->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonIconOnly);
	QMenu* menu23_total = new QMenu(toolBtn23_total);
	menu23_total->addAction(QString::fromUtf8("本月离职"));
	menu23_total->actions()[0]->setIcon(QIcon("Resources/选中.png"));
	menu23_total->addSeparator();
	menu23_total->addAction(QString::fromUtf8("本年离职"));
	menu23_total->setStyleSheet(
		"QMenu {background-color:white;}"
		"QMenu::item {padding: 2px 25px 2px 25px;border: 1px solid transparent;}"
		"QMenu::item:selected:enabled {border-color: rgb(250, 170, 60);background: rgba(250, 170, 60, 50);}"
		"QMenu::separator {height: 2px;background: rgb(168, 216, 235);margin-left: 10px;margin-right: 10px;}"
		"QMenu::indicator {width: 13px;height: 13px;}"
	);
	toolBtn23_total->setPopupMode(QToolButton::InstantPopup);
	toolBtn23_total->setMenu(menu23_total);
	toolBtn23_total->setStyleSheet("QToolButton{background:transparent;border: 0px;}"
		"QToolButton::menu-indicator{image:url(Resources/下拉框.png);position: relative; bottom: 4px; right: 4px; }"
		"QToolButton::menu-indicator:pressed{image:url(Resources/反下拉框.png);position: relative; bottom: 2px; right: 2px; }"
	);
	toolBtn23_total->resize(length, 50);
	toolBtn23_total->move(tableView_total->horizontalHeader()->sectionPosition(23) - 2, 0);

	connect(menu12_total, &QMenu::triggered, this, &WidgetYGGL::onQMenuTriggered);
	connect(menu13_total, &QMenu::triggered, this, &WidgetYGGL::onQMenuTriggered);
	connect(menu14_total, &QMenu::triggered, this, &WidgetYGGL::onQMenuTriggered);
	connect(menu15_total, &QMenu::triggered, this, &WidgetYGGL::onQMenuTriggered);
	connect(menu16_total, &QMenu::triggered, this, &WidgetYGGL::onQMenuTriggered);
	connect(menu17_total, &QMenu::triggered, this, &WidgetYGGL::onQMenuTriggered);
	connect(menu18_total, &QMenu::triggered, this, &WidgetYGGL::onQMenuTriggered);
	connect(menu23_total, &QMenu::triggered, this, &WidgetYGGL::onQMenuTriggered);

	//page_3
	QString str_entry[22];
	str_entry[0] = "真实姓名(10):";	str_entry[1] = "性别(1):"; str_entry[2] = "入职项目(10):";	str_entry[3] = "入职部门(10):";
	str_entry[4] = "身份证号(18):";	str_entry[5] = "籍贯(25):";	str_entry[6] = "工号牌(5):"; str_entry[7] = "入职时间(15):";
	str_entry[8] = "职务(10):";	str_entry[9] = "民族(5):";	str_entry[10] = "电话(20):"; str_entry[11] = "应急电话(20):";
	str_entry[12] = "住址(25):"; str_entry[13] = "学历(10):"; str_entry[14] = "专业(10):"; str_entry[15] = "证书(20):";
	str_entry[16] = "职称(10):"; str_entry[17] = "特长(15):"; str_entry[18] = "健康状况(15):"; str_entry[19] = "婚姻状况(2):";
	str_entry[20] = "政治面貌(5):"; str_entry[21] = "证件照:";

	QLabel* label_entry = NULL;
	QLabel* label_xx = NULL;
	Write_entry write_entry;
	for (int i = 0; i < 22; ++i) {
		label_entry = new QLabel(page_3);
		label_entry->setText(str_entry[i]);
		label_entry->setGeometry(QRect(300, 160 + i * 72, 200, 50));
		label_entry->setAlignment(Qt::AlignVCenter);
		label_entry->setFont(QFont("宋体", 11));

		if (i == 0 || i == 1 || i == 2 || i == 3 || i == 4 || i == 5 || i == 7 || i == 10 || i == 19 || i == 20) {
			label_xx = new QLabel(page_3);
			label_xx->setGeometry(QRect(285, 145 + i * 72, 50, 50));
			label_xx->setPixmap(QPixmap("Resources/星号.png"));
			label_xx->setStyleSheet("background:transparent;");
		}

		if (i == 1 || i == 3 || i == 19 || i == 20) {
			write_entry.cbx_entry = new MyComboBox(page_3);
			write_entry.cbx_entry->setFont(QFont("宋体", 11));
			write_entry.cbx_entry->setGeometry(QRect(520, 160 + i * 72, 600, 50));
			write_entry.cbx_entry->setFocusPolicy(Qt::NoFocus);
			write_entry.cbx_entry->setStyleSheet(QString::fromUtf8(" QComboBox {"
				"      border: 1px solid rgb(200,200,200);"
				"      border-radius: 10px;"
				"      padding: 1px 0px 1px 3px;"
				"      background-color: rgb(255, 255, 255);"
				"  }"
				"  QComboBox:on {"
				"      border: 1px solid grey;"
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
				"  QComboBox::down-arrow{"
				"      image: url(Resources/下拉.png);"
				"  }"
				"  QComboBox::down-arrow:on{"
				"      image: url(Resources/下拉_1.png);"
				"  }"
				"  QComboBox:hover{"
				"      background-color: rgb(245, 245, 245);"
				"  }"
			));
		}
		else if (i != 21) {
			write_entry.line_entry = new QLineEdit(page_3);
			write_entry.line_entry->setFont(QFont("宋体", 11));
			write_entry.line_entry->setGeometry(QRect(520, 160 + i * 72, 600, 50));
			QString temp = "";
			for (auto c : str_entry[i]) {
				if (c == '(') break;
				temp += c;
			}
			write_entry.line_entry->setPlaceholderText(temp);
			write_entry.line_entry->setStyleSheet(QString::fromUtf8(
				"QLineEdit{ background-color:rgb(255,255,255);color:black;"
				"border: 1px solid rgb(200,200,200); border-radius: 10px;}"
				"QLineEdit:hover{background-color: rgb(245, 245, 245);}"
				"QLineEdit:focus{border: 1px solid grey;background-color:rgb(255,255,255);}"));
		}
		map_write_entry.insert(str_entry[i], write_entry);
	}

	map_write_entry["性别(1):"].cbx_entry->addItem(QString::fromUtf8("男"));
	map_write_entry["性别(1):"].cbx_entry->addItem(QString::fromUtf8("女"));
	qItemModel = qobject_cast<QStandardItemModel*>(map_write_entry["性别(1):"].cbx_entry->model());
	for (int i = 0; i < 2; ++i) qItemModel->item(i)->setBackground(QBrush(QColor(255, 255, 255)));
	map_write_entry["入职部门(10):"].cbx_entry->addItem(QString::fromUtf8("项目经理"));
	map_write_entry["入职部门(10):"].cbx_entry->addItem(QString::fromUtf8("行政部"));
	map_write_entry["入职部门(10):"].cbx_entry->addItem(QString::fromUtf8("客服部"));
	map_write_entry["入职部门(10):"].cbx_entry->addItem(QString::fromUtf8("工程部"));
	map_write_entry["入职部门(10):"].cbx_entry->addItem(QString::fromUtf8("秩序维护部"));
	map_write_entry["入职部门(10):"].cbx_entry->addItem(QString::fromUtf8("环境部绿化"));
	map_write_entry["入职部门(10):"].cbx_entry->addItem(QString::fromUtf8("环境部保洁"));
	map_write_entry["入职部门(10):"].cbx_entry->addItem(QString::fromUtf8("后勤部"));
	qItemModel = qobject_cast<QStandardItemModel*>(map_write_entry["入职部门(10):"].cbx_entry->model());
	for (int i = 0; i < 8; ++i) qItemModel->item(i)->setBackground(QBrush(QColor(255, 255, 255)));
	map_write_entry["婚姻状况(2):"].cbx_entry->addItem(QString::fromUtf8("未婚"));
	map_write_entry["婚姻状况(2):"].cbx_entry->addItem(QString::fromUtf8("已婚"));
	qItemModel = qobject_cast<QStandardItemModel*>(map_write_entry["婚姻状况(2):"].cbx_entry->model());
	for (int i = 0; i < 2; ++i) qItemModel->item(i)->setBackground(QBrush(QColor(255, 255, 255)));
	map_write_entry["政治面貌(5):"].cbx_entry->addItem(QString::fromUtf8("群众"));
	map_write_entry["政治面貌(5):"].cbx_entry->addItem(QString::fromUtf8("共青团员"));
	map_write_entry["政治面貌(5):"].cbx_entry->addItem(QString::fromUtf8("共产党员"));
	qItemModel = qobject_cast<QStandardItemModel*>(map_write_entry["政治面貌(5):"].cbx_entry->model());
	for (int i = 0; i < 3; ++i) qItemModel->item(i)->setBackground(QBrush(QColor(255, 255, 255)));

	map_write_entry["入职时间(15):"].line_entry->setText(QString("%1/%2/%3")
		.arg(QDate::currentDate().year()).arg(QDate::currentDate().month()).arg(QDate::currentDate().day()));

	map_write_entry["入职项目(10):"].line_entry->setEnabled(false);
	//when comboBoxPro changes
	connect(comboBoxPro, &QComboBox::currentTextChanged, map_write_entry["入职项目(10):"].line_entry, &QLineEdit::setText);

	btnChoseImage = new QPushButton(page_3);
	btnChoseImage->setGeometry(QRect(520, 1672, 200, 50));
	btnChoseImage->setFont(QFont("楷体", 12));
	btnChoseImage->setStyleSheet(QString::fromUtf8(
		"QPushButton{				             "
		"  background-color: rgba(255, 255, 255, 102);"
		"  border-style: outset;				 "
		"  border-width: 2px;					 "
		"  border-radius: 10px;				     "
		"  border-color: grey;				     "
		"}										 "
		"QPushButton:hover{"
		"  background-color: rgba(255, 255, 255, 204);"
		"}"
		"QPushButton:pressed{		             "
		"  border-style: inset;				     "
		"  background-color: rgba(255, 255, 255, 255);"
		"}										 "
	));
	btnChoseImage->setText("选择图片文件");

	btnReturn = new QPushButton(page_3);
	btnReturn->setGeometry(QRect(730, 1672, 90, 50));
	btnReturn->setFont(QFont("楷体", 12));
	btnReturn->setStyleSheet(QString::fromUtf8(
		"QPushButton{				             "
		"  background-color: rgba(255, 255, 255, 102);"
		"  border-style: outset;				 "
		"  border-width: 2px;					 "
		"  border-radius: 10px;				     "
		"  border-color: grey;				     "
		"}										 "
		"QPushButton:hover{"
		"  background-color: rgba(255, 255, 255, 204);"
		"}"
		"QPushButton:pressed{		             "
		"  border-style: inset;				     "
		"  background-color: rgba(255, 255, 255, 255);"
		"}										 "
	));
	btnReturn->setText("撤销");

	labelForBtnChoseImage = new Mylabel(page_3);
	labelForBtnChoseImage->setGeometry(QRect(880, 1682, 500, 50));
	labelForBtnChoseImage->setFont(QFont("楷体"));
	labelForBtnChoseImage->setCursor(Qt::PointingHandCursor);
	labelForBtnChoseImage->setAlignment(Qt::AlignVCenter);
	labelForBtnChoseImage->setStyleSheet("color:rgb(90,90,90);");
	labelForBtnChoseImage->hide();

	imagePath = "";

	QLabel* labelImage = new QLabel(page_3);
	labelImage->setGeometry(QRect(830, 1672, 50, 50));
	labelImage->setStyleSheet("image:url(Resources/照片.png);");
	labelImage->hide();

	QLabel* labelForBtnChoseImage_ = new QLabel(page_3);
	labelForBtnChoseImage_->setGeometry(QRect(830, 1672, 600, 50));
	labelForBtnChoseImage_->setFont(QFont("楷体"));
	labelForBtnChoseImage_->setText("未选择任何文件");
	labelForBtnChoseImage_->setStyleSheet("color:rgb(90,90,90);");

	btnEntry = new QPushButton(page_3);
	btnEntry->setGeometry(QRect(600, 1790, 280, 80));
	btnEntry->setFont(QFont("楷体", 22));
	btnEntry->setStyleSheet(QString::fromUtf8(
		"QPushButton{				             "
		"  background-color: rgb(6, 197, 255);   "
		"  border-style: outset;				 "
		"  border-width: 2px;					 "
		"  border-radius: 30px;				     "
		"  border-color: grey;				     "
		"}										 "
		"QPushButton:hover{                      "
		"  background-color: rgb(0, 170, 255);   "
		"}                                       "
		"QPushButton:pressed{		             "
		"  border-style: inset;				     "
		"}										 "
	));
	btnEntry->setText("入职");

	connect(btnChoseImage, &QPushButton::clicked, [=]
		{
			imagePath = QFileDialog::getOpenFileName(NULL, "选择文件", ".", "Image Files (*.png *.jpg *.bmp)");
			if (imagePath.isEmpty())
				return;
			labelForBtnChoseImage->setText(imagePath.mid(imagePath.lastIndexOf('/') + 1));
			labelForBtnChoseImage->adjustSize();
			labelForBtnChoseImage->show();
			labelImage->show();
			labelForBtnChoseImage_->hide();
		}
	);
	connect(btnReturn, &QPushButton::clicked, [=]
		{
			labelForBtnChoseImage_->show();
			labelForBtnChoseImage->hide();
			labelImage->hide();
			imagePath = "";
		}
	);
	connect(labelForBtnChoseImage, &Mylabel::clicked, [=]
		{
			QDesktopServices::openUrl(QUrl("file:///" + imagePath));
		}
	);
	connect(btnEntry, &QPushButton::clicked, [=]
		{
			if (map_write_entry["真实姓名(10):"].line_entry->text().isEmpty()) {
				QMessageBox box(QMessageBox::Information, "提示", "姓名不可为空！");
				box.setStandardButtons(QMessageBox::Ok);
				box.setButtonText(QMessageBox::Ok, QString("确 定"));
				box.setWindowIcon(QPixmap("Resources/logo.png"));
				int button = box.exec();
				return;
			}
			//判断身份证号码是否有效begin
			if (map_write_entry["身份证号(18):"].line_entry->text().length() != 18) {
				QMessageBox box(QMessageBox::Information, "提示", "请输入18位有效身份证号码！");
				box.setStandardButtons(QMessageBox::Ok);
				box.setButtonText(QMessageBox::Ok, QString("确 定"));
				box.setWindowIcon(QPixmap("Resources/logo.png"));
				int button = box.exec();
				return;
			}
			for (int i = 0; i < 17; ++i) {
				if (!map_write_entry["身份证号(18):"].line_entry->text()[i].isDigit()) {
					QMessageBox box(QMessageBox::Information, "提示", "请输入18位有效身份证号码！");
					box.setStandardButtons(QMessageBox::Ok);
					box.setButtonText(QMessageBox::Ok, QString("确 定"));
					box.setWindowIcon(QPixmap("Resources/logo.png"));
					int button = box.exec();
					return;
				}
			}
			if ((!map_write_entry["身份证号(18):"].line_entry->text()[17].isDigit())
				&& map_write_entry["身份证号(18):"].line_entry->text()[17] != 'x'
				&& map_write_entry["身份证号(18):"].line_entry->text()[17] != 'X') {
				QMessageBox box(QMessageBox::Information, "提示", "请输入18位有效身份证号码！");
				box.setStandardButtons(QMessageBox::Ok);
				box.setButtonText(QMessageBox::Ok, QString("确 定"));
				box.setWindowIcon(QPixmap("Resources/logo.png"));
				int button = box.exec();
				return;
			}
			QString personalID = map_write_entry["身份证号(18):"].line_entry->text();
			QString y = personalID.mid(6, 4);
			QString m = personalID.mid(10, 2);
			QString d = personalID.mid(12, 2);
			if (m.toInt() < 1 || m.toInt() > 12 || d.toInt() < 1 || d.toInt() > DateClass::getDayMaxOfMonth(y.toInt(), m.toInt())) {
				QMessageBox box(QMessageBox::Information, "提示", "请输入18位有效身份证号码(注意出生日期)！");
				box.setStandardButtons(QMessageBox::Ok);
				box.setButtonText(QMessageBox::Ok, QString("确 定"));
				box.setWindowIcon(QPixmap("Resources/logo.png"));
				int button = box.exec();
				return;
			}
			//end
			if (map_write_entry["籍贯(25):"].line_entry->text().isEmpty()) {
				QMessageBox box(QMessageBox::Information, "提示", "籍贯不可为空！");
				box.setStandardButtons(QMessageBox::Ok);
				box.setButtonText(QMessageBox::Ok, QString("确 定"));
				box.setWindowIcon(QPixmap("Resources/logo.png"));
				int button = box.exec();
				return;
			}
			if (checkTime(map_write_entry["入职时间(15):"].line_entry->text(), '/') == false) {
				QMessageBox box(QMessageBox::Information, "提示", "时间格式不正确！");
				box.setStandardButtons(QMessageBox::Ok);
				box.setButtonText(QMessageBox::Ok, QString("确 定"));
				box.setWindowIcon(QPixmap("Resources/logo.png"));
				int button = box.exec();
				return;
			}
			if (map_write_entry["电话(20):"].line_entry->text().isEmpty()) {
				QMessageBox box(QMessageBox::Information, "提示", "电话不可为空！");
				box.setStandardButtons(QMessageBox::Ok);
				box.setButtonText(QMessageBox::Ok, QString("确 定"));
				box.setWindowIcon(QPixmap("Resources/logo.png"));
				int button = box.exec();
				return;
			}
			QVector<QString> v_sendEntryData;
			for (int i = 0; i < 22; ++i) {
				if (i == 1 || i == 3 || i == 19 || i == 20) {
					v_sendEntryData.push_back(map_write_entry[str_entry[i]].cbx_entry->currentText());
				}
				else if (i != 21) {
					v_sendEntryData.push_back(map_write_entry[str_entry[i]].line_entry->text());
				}
			}

			v_sendEntryData.push_back("");

			QString pic_format = "";
			for (int i = imagePath.lastIndexOf('.') + 1; i < imagePath.length(); ++i) {
				pic_format += imagePath[i];
			}
			v_sendEntryData.push_back(pic_format);

			QFile file(imagePath);
			file.open(QIODevice::ReadOnly);
			QByteArray data = file.readAll();
			file.close();

			emit sig_sendEntryData(v_sendEntryData, data);
		}
	);

	//page_4
	label_xx = new QLabel(page_4);
	label_xx->setGeometry(QRect(125, 165, 50, 50));
	label_xx->setPixmap(QPixmap("Resources/星号.png"));
	label_xx->setStyleSheet("background:transparent;");

	label_xx = new QLabel(page_4);
	label_xx->setGeometry(QRect(755, 165, 50, 50));
	label_xx->setPixmap(QPixmap("Resources/星号.png"));
	label_xx->setStyleSheet("background:transparent;");

	label_xx = new QLabel(page_4);
	label_xx->setGeometry(QRect(125, 285, 50, 50));
	label_xx->setPixmap(QPixmap("Resources/星号.png"));
	label_xx->setStyleSheet("background:transparent;");

	label_xx = new QLabel(page_4);
	label_xx->setGeometry(QRect(755, 285, 50, 50));
	label_xx->setPixmap(QPixmap("Resources/星号.png"));
	label_xx->setStyleSheet("background:transparent;");

	QLabel* name_change = new QLabel(page_4);
	name_change->setText("调动人员姓名:");
	name_change->setGeometry(QRect(140, 180, 250, 60));
	name_change->setAlignment(Qt::AlignVCenter);
	name_change->setFont(QFont("宋体", 13));

	line_name_change = new QLineEdit(page_4);
	line_name_change->setFont(QFont("宋体", 13));
	line_name_change->setGeometry(QRect(390, 180, 310, 60));
	line_name_change->setPlaceholderText("调动人员姓名");
	line_name_change->setStyleSheet(QString::fromUtf8(
		"QLineEdit{ background-color:rgb(255,255,255);"
		"border: 1px solid rgb(200,200,200); border-radius: 10px;}"
		"QLineEdit:hover{background-color: rgb(245, 245, 245);}"
		"QLineEdit:focus{border: 1px solid grey;background-color:rgb(255,255,255);}"));

	QLabel* time_change = new QLabel(page_4);
	time_change->setText("调动时间:");
	time_change->setGeometry(QRect(770, 180, 200, 60));
	time_change->setAlignment(Qt::AlignVCenter);
	time_change->setFont(QFont("宋体", 13));

	line_time_change = new QLineEdit(page_4);
	line_time_change->setFont(QFont("宋体", 13));
	line_time_change->setPlaceholderText("调动时间");
	line_time_change->setText(QString("%1/%2/%3")
		.arg(QDate::currentDate().year()).arg(QDate::currentDate().month()).arg(QDate::currentDate().day()));
	line_time_change->setGeometry(QRect(1000, 180, 370, 60));
	line_time_change->setStyleSheet(QString::fromUtf8(
		"QLineEdit{ background-color:rgb(255,255,255);"
		"border: 1px solid rgb(200,200,200); border-radius: 10px;}"
		"QLineEdit:hover{background-color: rgb(245, 245, 245);}"
		"QLineEdit:focus{border: 1px solid grey;background-color:rgb(255,255,255);}"));

	QLabel* pro_bef_change = new QLabel(page_4);
	pro_bef_change->setText("调动前项目:");
	pro_bef_change->setGeometry(QRect(140, 300, 250, 60));
	pro_bef_change->setAlignment(Qt::AlignVCenter);
	pro_bef_change->setFont(QFont("宋体", 13));

	cbx_pro_bef_change = new QComboBox(page_4);
	cbx_pro_bef_change->setFont(QFont("宋体", 13));
	cbx_pro_bef_change->setGeometry(QRect(390, 300, 310, 60));
	cbx_pro_bef_change->setFocusPolicy(Qt::NoFocus);
	cbx_pro_bef_change->setMaxVisibleItems(13);
	cbx_pro_bef_change->setStyleSheet(QString::fromUtf8(" QComboBox {"
		"      border: 1px solid rgb(200,200,200);"
		"      border-radius: 10px;"
		"      padding: 1px 0px 1px 3px;"
		"      background-color: rgb(255, 255, 255);"
		"      color: rgb(0, 0, 0);"
		"  }"
		"  QComboBox:on {"
		"      border: 1px solid grey;"
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
		"  QComboBox::down-arrow{"
		"      image: url(Resources/下拉.png);"
		"  }"
		"  QComboBox::down-arrow:on{"
		"      image: url(Resources/下拉_1.png);"
		"  }"
		"  QComboBox:hover{"
		"      background-color: rgb(245, 245, 245);"
		"  }"
	));
	cbx_pro_bef_change->addItem(QString(""));
	cbx_pro_bef_change->addItem(QString("公司总部"));
	cbx_pro_bef_change->addItem(QString("文鼎公寓"));
	cbx_pro_bef_change->addItem(QString("望湖家园"));
	cbx_pro_bef_change->addItem(QString("金城一区"));
	cbx_pro_bef_change->addItem(QString("江南小区"));
	cbx_pro_bef_change->addItem(QString("东方国际村"));
	cbx_pro_bef_change->addItem(QString("嘉鸿华庭"));
	cbx_pro_bef_change->addItem(QString("阳光都市"));
	cbx_pro_bef_change->addItem(QString("银河证券"));
	cbx_pro_bef_change->addItem(QString("春晗公寓"));
	cbx_pro_bef_change->addItem(QString("文化旅游局"));
	cbx_pro_bef_change->addItem(QString("中厦国际保安"));
	qItemModel = qobject_cast<QStandardItemModel*>(cbx_pro_bef_change->model());
	for (int i = 0; i < cbx_pro_bef_change->count(); ++i)
		qItemModel->item(i)->setBackground(QBrush(QColor(255, 255, 255)));
	cbx_pro_bef_change->setEnabled(false);

	QLabel* pro_aft_change = new QLabel(page_4);
	pro_aft_change->setText("调动后项目:");
	pro_aft_change->setGeometry(QRect(770, 300, 200, 60));
	pro_aft_change->setAlignment(Qt::AlignVCenter);
	pro_aft_change->setFont(QFont("宋体", 13));

	cbx_pro_aft_change = new QComboBox(page_4);
	cbx_pro_aft_change->setFont(QFont("宋体", 13));
	cbx_pro_aft_change->setGeometry(QRect(1000, 300, 370, 60));
	cbx_pro_aft_change->setFocusPolicy(Qt::NoFocus);
	cbx_pro_aft_change->setMaxVisibleItems(13);
	cbx_pro_aft_change->setStyleSheet(QString::fromUtf8(" QComboBox {"
		"      border: 1px solid rgb(200,200,200);"
		"      border-radius: 10px;"
		"      padding: 1px 0px 1px 3px;"
		"      background-color: rgb(255, 255, 255);"
		"  }"
		"  QComboBox:on {"
		"      border: 1px solid grey;"
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
		"  QComboBox::down-arrow{"
		"      image: url(Resources/下拉.png);"
		"  }"
		"  QComboBox::down-arrow:on{"
		"      image: url(Resources/下拉_1.png);"
		"  }"
		"  QComboBox:hover{"
		"      background-color: rgb(245, 245, 245);"
		"  }"
	));
	cbx_pro_aft_change->addItem(QString::fromUtf8(""));
	cbx_pro_aft_change->addItem(QString("公司总部"));
	cbx_pro_aft_change->addItem(QString("文鼎公寓"));
	cbx_pro_aft_change->addItem(QString("望湖家园"));
	cbx_pro_aft_change->addItem(QString("金城一区"));
	cbx_pro_aft_change->addItem(QString("江南小区"));
	cbx_pro_aft_change->addItem(QString("东方国际村"));
	cbx_pro_aft_change->addItem(QString("嘉鸿华庭"));
	cbx_pro_aft_change->addItem(QString("阳光都市"));
	cbx_pro_aft_change->addItem(QString("银河证券"));
	cbx_pro_aft_change->addItem(QString("春晗公寓"));
	cbx_pro_aft_change->addItem(QString("文化旅游局"));
	cbx_pro_aft_change->addItem(QString("中厦国际保安"));
	qItemModel = qobject_cast<QStandardItemModel*>(cbx_pro_aft_change->model());
	for (int i = 0; i < cbx_pro_aft_change->count(); ++i) qItemModel->item(i)->setBackground(QBrush(QColor(255, 255, 255)));

	QLabel* reason_change = new QLabel(page_4);
	reason_change->setText("调动原因(100):");
	reason_change->setGeometry(QRect(140, 540, 250, 60));
	reason_change->setAlignment(Qt::AlignVCenter);
	reason_change->setFont(QFont("宋体", 13));

	text_reason_change = new QTextEdit(page_4);
	text_reason_change->setFont(QFont("宋体", 13));
	text_reason_change->setGeometry(QRect(390, 420, 980, 300));
	text_reason_change->setStyleSheet(QString::fromUtf8(
		"QTextEdit{ background-color:rgb(255,255,255);"
		"border: 1px solid rgb(200,200,200); border-radius: 10px;}"
		"QTextEdit:hover{background-color: rgb(245, 245, 245);}"
		"QTextEdit:focus{border: 1px solid grey;background-color:rgb(255,255,255);}"));

	btn_change = new QPushButton(page_4);
	btn_change->setGeometry(QRect(600, 790, 360, 80));
	btn_change->setFont(QFont("楷体", 22));
	btn_change->setStyleSheet(QString::fromUtf8(
		"QPushButton{				             "
		"  background-color: rgb(6, 197, 255);   "
		"  border-style: outset;				 "
		"  border-width: 2px;					 "
		"  border-radius: 30px;				     "
		"  border-color: grey;				     "
		"}										 "
		"QPushButton:hover{                      "
		"  background-color: rgb(0, 170, 255);   "
		"}                                       "
		"QPushButton:pressed{		             "
		"  border-style: inset;				     "
		"}										 "
	));
	btn_change->setText("调动");

	curTextOfLine_name_change = "";
	connect(line_name_change, &QLineEdit::editingFinished, [=]
		{
			if (curTextOfLine_name_change != line_name_change->text()) {
				curTextOfLine_name_change = line_name_change->text();
				emit sig_sendChangeName(curTextOfLine_name_change);
			}
		}
	);

	connect(btn_change, &QPushButton::clicked, [=]
		{
			if (line_name_change->text().isEmpty()) {
				QMessageBox box(QMessageBox::Information, "提示", "姓名不可为空！");
				box.setStandardButtons(QMessageBox::Ok);
				box.setButtonText(QMessageBox::Ok, QString("确 定"));
				box.setWindowIcon(QPixmap("Resources/logo.png"));
				int button = box.exec();
				return;
			}
			if (checkTime(line_time_change->text(), '/') == false) {
				QMessageBox box(QMessageBox::Information, "提示", "时间格式不正确！");
				box.setStandardButtons(QMessageBox::Ok);
				box.setButtonText(QMessageBox::Ok, QString("确 定"));
				box.setWindowIcon(QPixmap("Resources/logo.png"));
				int button = box.exec();
				return;
			}
			if ((cbx_pro_bef_change->currentText() != comboBoxPro->currentText() && cbx_pro_aft_change->currentText() != comboBoxPro->currentText())
				|| cbx_pro_bef_change->currentText() == "" || cbx_pro_aft_change->currentText() == "") {
				QMessageBox box(QMessageBox::Information, "提示", "调动失败，请检查是否填写错误！");
				box.setStandardButtons(QMessageBox::Ok);
				box.setButtonText(QMessageBox::Ok, QString("确 定"));
				box.setWindowIcon(QPixmap("Resources/logo.png"));
				int button = box.exec();
				return;
			}
			QVector<QString> v_sendChangeData;
			v_sendChangeData.push_back(line_name_change->text());
			v_sendChangeData.push_back(line_time_change->text());
			v_sendChangeData.push_back(cbx_pro_aft_change->currentText());
			v_sendChangeData.push_back(text_reason_change->toPlainText());
			emit sig_sendChangeData(v_sendChangeData);
		}
	);

	//page_5
	label_xx = new QLabel(page_5);
	label_xx->setGeometry(QRect(125, 165, 50, 50));
	label_xx->setPixmap(QPixmap("Resources/星号.png"));
	label_xx->setStyleSheet("background:transparent;");

	label_xx = new QLabel(page_5);
	label_xx->setGeometry(QRect(755, 165, 50, 50));
	label_xx->setPixmap(QPixmap("Resources/星号.png"));
	label_xx->setStyleSheet("background:transparent;");

	label_xx = new QLabel(page_5);
	label_xx->setGeometry(QRect(125, 255, 50, 50));
	label_xx->setPixmap(QPixmap("Resources/星号.png"));
	label_xx->setStyleSheet("background:transparent;");

	label_xx = new QLabel(page_5);
	label_xx->setGeometry(QRect(440, 255, 50, 50));
	label_xx->setPixmap(QPixmap("Resources/星号.png"));
	label_xx->setStyleSheet("background:transparent;");

	label_xx = new QLabel(page_5);
	label_xx->setGeometry(QRect(895, 255, 50, 50));
	label_xx->setPixmap(QPixmap("Resources/星号.png"));
	label_xx->setStyleSheet("background:transparent;");

	label_xx = new QLabel(page_5);
	label_xx->setGeometry(QRect(125, 345, 50, 50));
	label_xx->setPixmap(QPixmap("Resources/星号.png"));
	label_xx->setStyleSheet("background:transparent;");

	label_xx = new QLabel(page_5);
	label_xx->setGeometry(QRect(475, 345, 50, 50));
	label_xx->setPixmap(QPixmap("Resources/星号.png"));
	label_xx->setStyleSheet("background:transparent;");

	QLabel* name_out = new QLabel(page_5);
	name_out->setText("离职人员姓名:");
	name_out->setGeometry(QRect(140, 180, 250, 60));
	name_out->setAlignment(Qt::AlignVCenter);
	name_out->setFont(QFont("宋体", 13));

	line_name_out = new QLineEdit(page_5);
	line_name_out->setFont(QFont("宋体", 13));
	line_name_out->setGeometry(QRect(390, 180, 310, 60));
	line_name_out->setPlaceholderText("离职人员姓名");
	line_name_out->setStyleSheet(QString::fromUtf8(
		"QLineEdit{ background-color:rgb(255,255,255);"
		"border: 1px solid rgb(200,200,200); border-radius: 10px;}"
		"QLineEdit:hover{background-color: rgb(245, 245, 245);}"
		"QLineEdit:focus{border: 1px solid grey;background-color:rgb(255,255,255);}"));

	QLabel* time_out = new QLabel(page_5);
	time_out->setText("离职时间:");
	time_out->setGeometry(QRect(770, 180, 200, 60));
	time_out->setAlignment(Qt::AlignVCenter);
	time_out->setFont(QFont("宋体", 13));

	line_time_out = new QLineEdit(page_5);
	line_time_out->setFont(QFont("宋体", 13));
	line_time_out->setPlaceholderText("离职时间");
	line_time_out->setText(QString("%1/%2/%3")
		.arg(QDate::currentDate().year()).arg(QDate::currentDate().month()).arg(QDate::currentDate().day()));
	line_time_out->setGeometry(QRect(1000, 180, 370, 60));
	line_time_out->setStyleSheet(QString::fromUtf8(
		"QLineEdit{ background-color:rgb(255,255,255);"
		"border: 1px solid rgb(200,200,200); border-radius: 10px;}"
		"QLineEdit:hover{background-color: rgb(245, 245, 245);}"
		"QLineEdit:focus{border: 1px solid grey;background-color:rgb(255,255,255);}"));

	QLabel* clothes_out = new QLabel(page_5);
	clothes_out->setText("服装是否已结清");
	clothes_out->setGeometry(QRect(140, 270, 255, 60));
	clothes_out->setAlignment(Qt::AlignVCenter);
	clothes_out->setFont(QFont("宋体", 13));

	cb_clothes_out = new QCheckBox(page_5);
	cb_clothes_out->setGeometry(QRect(395, 270, 60, 60));
	cb_clothes_out->setStyleSheet("background:transparent;");

	QLabel* IDcard_out = new QLabel(page_5);
	IDcard_out->setText("工号牌及钥匙是否已收回");
	IDcard_out->setGeometry(QRect(455, 270, 395, 60));
	IDcard_out->setAlignment(Qt::AlignVCenter);
	IDcard_out->setFont(QFont("宋体", 13));

	cb_IDcard_out = new QCheckBox(page_5);
	cb_IDcard_out->setGeometry(QRect(850, 270, 60, 60));
	cb_IDcard_out->setStyleSheet("background:transparent;");

	QLabel* tool_out = new QLabel(page_5);
	tool_out->setText("办公用品及工具是否已收回");
	tool_out->setGeometry(QRect(910, 270, 430, 60));
	tool_out->setAlignment(Qt::AlignVCenter);
	tool_out->setFont(QFont("宋体", 13));

	cb_tool_out = new QCheckBox(page_5);
	cb_tool_out->setGeometry(QRect(1340, 270, 60, 60));
	cb_tool_out->setStyleSheet("background:transparent;");

	QLabel* form_out = new QLabel(page_5);
	form_out->setText("离职单是否已签写");
	form_out->setGeometry(QRect(140, 360, 290, 60));
	form_out->setAlignment(Qt::AlignVCenter);
	form_out->setFont(QFont("宋体", 13));

	cb_form_out = new QCheckBox(page_5);
	cb_form_out->setGeometry(QRect(430, 360, 60, 60));
	cb_form_out->setStyleSheet("background:transparent;");

	QLabel* wage_out = new QLabel(page_5);
	wage_out->setText("工资是否已结清");
	wage_out->setGeometry(QRect(490, 360, 245, 60));
	wage_out->setAlignment(Qt::AlignVCenter);
	wage_out->setFont(QFont("宋体", 13));

	cb_wage_out = new QCheckBox(page_5);
	cb_wage_out->setGeometry(QRect(745, 360, 60, 60));
	cb_wage_out->setStyleSheet("background:transparent;");
	connect(cb_wage_out, &QCheckBox::toggled, this, &WidgetYGGL::oncb_wage_out_toggled);

	line_wage_out = new QLineEdit(page_5);
	line_wage_out->setFont(QFont("楷体", 13));
	line_wage_out->setGeometry(QRect(795, 355, 310, 60));
	line_wage_out->setPlaceholderText("金额");
	line_wage_out->setStyleSheet(QString::fromUtf8(
		"QLineEdit{ background-color:rgb(255,255,255);"
		"border: 1px solid rgb(200,200,200); border-radius: 10px;}"
		"QLineEdit:hover{background-color: rgb(245, 245, 245);}"
		"QLineEdit:focus{border: 1px solid grey;background-color:rgb(255,255,255);}"));

	QLabel* reason_out = new QLabel(page_5);
	reason_out->setText("离职原因(100):");
	reason_out->setGeometry(QRect(140, 555, 250, 60));
	reason_out->setAlignment(Qt::AlignVCenter);
	reason_out->setFont(QFont("宋体", 13));

	text_reason_out = new QTextEdit(page_5);
	text_reason_out->setFont(QFont("宋体", 13));
	text_reason_out->setGeometry(QRect(390, 450, 980, 270));
	text_reason_out->setStyleSheet(QString::fromUtf8(
		"QTextEdit{ background-color:rgb(255,255,255);"
		"border: 1px solid rgb(200,200,200); border-radius: 10px;}"
		"QTextEdit:hover{background-color: rgb(245, 245, 245);}"
		"QTextEdit:focus{border: 1px solid grey;background-color:rgb(255,255,255);}"));

	btn_out = new QPushButton(page_5);
	btn_out->setGeometry(QRect(600, 790, 360, 80));
	btn_out->setFont(QFont("楷体", 22));
	btn_out->setStyleSheet(QString::fromUtf8(
		"QPushButton{				             "
		"  background-color: rgb(6, 197, 255);   "
		"  border-style: outset;				 "
		"  border-width: 2px;					 "
		"  border-radius: 30px;				     "
		"  border-color: grey;				     "
		"}										 "
		"QPushButton:hover{                      "
		"  background-color: rgb(0, 170, 255);   "
		"}                                       "
		"QPushButton:pressed{		             "
		"  border-style: inset;				     "
		"}										 "
	));
	btn_out->setText("离职");

	connect(btn_out, &QPushButton::clicked, [=]
		{
			if (line_name_out->text().isEmpty()) {
				QMessageBox box(QMessageBox::Information, "提示", "姓名不可为空！");
				box.setStandardButtons(QMessageBox::Ok);
				box.setButtonText(QMessageBox::Ok, QString("确 定"));
				box.setWindowIcon(QPixmap("Resources/logo.png"));
				int button = box.exec();
				return;
			}
			if (checkTime(line_time_out->text(), '/') == false) {
				QMessageBox box(QMessageBox::Information, "提示", "时间格式不正确！");
				box.setStandardButtons(QMessageBox::Ok);
				box.setButtonText(QMessageBox::Ok, QString("确 定"));
				box.setWindowIcon(QPixmap("Resources/logo.png"));
				int button = box.exec();
				return;
			}
			QVector<QString> v_sendOutData;
			QString out_settlement = QString("%1%2%3%4%5").arg(cb_clothes_out->checkState()).arg(cb_IDcard_out->checkState())
				.arg(cb_tool_out->checkState()).arg(cb_form_out->checkState()).arg(cb_wage_out->checkState());
			if (cb_wage_out->isChecked()) {
				out_settlement += " 0.00";
			}
			else {
				out_settlement += QString(" %1").arg(line_wage_out->text());
			}
			v_sendOutData.push_back(line_name_out->text());
			v_sendOutData.push_back(line_time_out->text());
			v_sendOutData.push_back(out_settlement);
			v_sendOutData.push_back(text_reason_out->toPlainText());
			v_sendOutData.push_back(comboBoxPro->currentText());
			emit sig_sendOutData(v_sendOutData);
		}
	);

	//
	stackedWidget->addWidget(scrollArea_0);
	stackedWidget->addWidget(scrollArea_1);
	stackedWidget->addWidget(scrollArea_2);
	stackedWidget->addWidget(scrollArea_3);
	stackedWidget->addWidget(scrollArea_4);
	stackedWidget->addWidget(scrollArea_5);
	stackedWidget->setCurrentIndex(0);
	currentPage = 0;

	btnSelect[0]->setStyleSheet(style2);
	QIcon icon;
	icon.addFile(QString::fromUtf8("Resources/select_%1_white.png").arg(0), QSize(), QIcon::Normal, QIcon::Off);
	btnSelect[0]->setIcon(icon);
	btnSelect[0]->setIconSize(QSize(40, 40));

	connect(btnSelect[0], &QPushButton::pressed, [=] {if (currentPage == 0) return; emit sig_btnPress(0); });
	connect(btnSelect[1], &QPushButton::pressed, [=] {if (currentPage == 1) return; emit sig_btnPress(1); });
	connect(btnSelect[2], &QPushButton::pressed, [=]
		{
			if (currentPage == 2) return;
			emit sig_btnPress(2);
			QVector<QString> v_sendTotal;
			for (auto c : menu12_total->actions()) {
				if (!c->icon().isNull()) {
					v_sendTotal.push_back(c->text());
					break;
				}
			}
			for (auto c : menu13_total->actions()) {
				if (!c->icon().isNull()) {
					v_sendTotal.push_back(c->text());
					break;
				}
			}
			for (auto c : menu14_total->actions()) {
				if (!c->icon().isNull()) {
					v_sendTotal.push_back(c->text());
					break;
				}
			}
			for (auto c : menu15_total->actions()) {
				if (!c->icon().isNull()) {
					v_sendTotal.push_back(c->text());
					break;
				}
			}
			for (auto c : menu16_total->actions()) {
				if (!c->icon().isNull()) {
					v_sendTotal.push_back(c->text());
					break;
				}
			}
			for (auto c : menu17_total->actions()) {
				if (!c->icon().isNull()) {
					v_sendTotal.push_back(c->text());
					break;
				}
			}
			for (auto c : menu18_total->actions()) {
				if (!c->icon().isNull()) {
					v_sendTotal.push_back(c->text());
					break;
				}
			}
			for (auto c : menu23_total->actions()) {
				if (!c->icon().isNull()) {
					v_sendTotal.push_back(c->text());
					break;
				}
			}
			emit sig_sendtotal(v_sendTotal);
		}
	);
	connect(btnHR[0], &QPushButton::pressed, [=] {if (currentPage == 3) return; emit sig_btnPress(3); });
	connect(btnHR[1], &QPushButton::pressed, [=] {if (currentPage == 4) return; emit sig_btnPress(4); });
	connect(btnHR[2], &QPushButton::pressed, [=] {if (currentPage == 5) return; emit sig_btnPress(5); });
	connect(this, &WidgetYGGL::sig_btnPress, stackedWidget, &QStackedWidget::setCurrentIndex);
	connect(this, &WidgetYGGL::sig_btnPress, this, &WidgetYGGL::setBtnColor);

	connect(comboBoxPro, &QComboBox::currentTextChanged, this, &WidgetYGGL::onCbxPro_currentTextChanged);

	connect(btn4_da, &QPushButton::clicked, [=]
		{
			QVector<QString> v_forEmployeeInfoData;
			v_forEmployeeInfoData.push_back(comboBoxPro->currentText());
			v_forEmployeeInfoData.push_back(cbx1_da->currentText());
			v_forEmployeeInfoData.push_back(cbx2_da->currentText());
			v_forEmployeeInfoData.push_back(line3_da->text());
			emit sig_forGetEmployeeInfoData(v_forEmployeeInfoData);
		}
	);

	connect(btn4_bx, &QPushButton::clicked, [=]
		{
			QVector<QString> v_forInsuranceInfo;
			v_forInsuranceInfo.push_back(comboBoxPro->currentText());
			v_forInsuranceInfo.push_back(cbx1_bx->currentText());
			v_forInsuranceInfo.push_back(cbx2_bx->currentText());
			v_forInsuranceInfo.push_back(cbx3_bx->currentText());
			emit sig_forGetInsuranceInfo(v_forInsuranceInfo);
		}
	);

}

WidgetYGGL::~WidgetYGGL()
{
	delete page_0; page_0 = NULL;
	delete page_1; page_1 = NULL;
	delete page_2; page_2 = NULL;
	delete page_3; page_3 = NULL;
	delete page_4; page_4 = NULL;
	delete page_5; page_5 = NULL;
	delete scrollArea_0; scrollArea_0 = NULL;
	delete scrollArea_1; scrollArea_1 = NULL;
	delete scrollArea_2; scrollArea_2 = NULL;
	delete scrollArea_3; scrollArea_3 = NULL;
	delete scrollArea_4; scrollArea_4 = NULL;
	delete scrollArea_5; scrollArea_5 = NULL;
	delete tab; tab = NULL;
	delete tab2; tab2 = NULL;
}

void WidgetYGGL::onsig_foryggl(UserInfo& userInfo) {

	comboBoxPro->setCurrentText(userInfo.xm);

}

void WidgetYGGL::setBtnColor(int index) {

	if (currentPage < 3) {
		btnSelect[currentPage]->setStyleSheet(style1);
		QIcon icon;
		icon.addFile(QString::fromUtf8("Resources/select_%1.png").arg(currentPage), QSize(), QIcon::Normal, QIcon::Off);
		btnSelect[currentPage]->setIcon(icon);
		btnSelect[currentPage]->setIconSize(QSize(40, 40));
	}
	else {
		btnHR[currentPage - 3]->setStyleSheet(style1);
		QIcon icon;
		icon.addFile(QString::fromUtf8("Resources/HR_%1.png").arg(currentPage - 3), QSize(), QIcon::Normal, QIcon::Off);
		btnHR[currentPage - 3]->setIcon(icon);
		btnHR[currentPage - 3]->setIconSize(QSize(40, 40));
	}

	currentPage = index;

	if (index < 3) {
		btnSelect[index]->setStyleSheet(style2);
		QIcon icon;
		icon.addFile(QString::fromUtf8("Resources/select_%1_white.png").arg(index), QSize(), QIcon::Normal, QIcon::Off);
		btnSelect[index]->setIcon(icon);
		btnSelect[index]->setIconSize(QSize(40, 40));
	}
	else {
		btnHR[index - 3]->setStyleSheet(style2);
		QIcon icon;
		icon.addFile(QString::fromUtf8("Resources/HR_%1_white.png").arg(index - 3), QSize(), QIcon::Normal, QIcon::Off);
		btnHR[index - 3]->setIcon(icon);
		btnHR[index - 3]->setIconSize(QSize(40, 40));
	}

}

void WidgetYGGL::oncb_wage_out_toggled(bool checked) {

	if (checked == false) {
		line_wage_out->show();
	}
	else {
		line_wage_out->hide();
	}

}

void WidgetYGGL::onPage_0_scrollbar(int value) {

	label_0->setGeometry(QRect(60 + value, -30, 400, 200));
	cbx1_da->setGeometry(QRect(140 + value, 150, 250, 60));
	cbx2_da->setGeometry(QRect(390 + value, 150, 250, 60));
	line3_da->setGeometry(QRect(640 + value, 150, 400, 60));
	btn4_da->setGeometry(QRect(1040 + value, 150, 70, 60));

}

void WidgetYGGL::onPage_1_scrollbar(int value) {

	label_1->setGeometry(QRect(60 + value, -30, 400, 200));
	cbx1_bx->setGeometry(QRect(140 + value, 150, 250, 60));
	cbx2_bx->setGeometry(QRect(390 + value, 150, 250, 60));
	cbx3_bx->setGeometry(QRect(640 + value, 150, 550, 60));
	btn4_bx->setGeometry(QRect(1190 + value, 150, 70, 60));

}

void WidgetYGGL::onPage_2_scrollbar(int value) {

	label_2->setGeometry(QRect(60 + value, -30, 400, 200));

}

void WidgetYGGL::onPage_3_scrollbar(int value) {

	if (value >= 0 && value <= 200) {
		label_3->setFont(QFont("楷体", int(30 - value * 3 / 20)));
		label_3->setStyleSheet(QString("color:rgba(0,0,0,%1);").arg(255 - value));
	}

}

void WidgetYGGL::onQMenuTriggered(QAction* action) {

	QMenu* menu = qobject_cast<QMenu*>(this->sender());
	for (auto c : menu->actions()) {
		c->setIcon(QIcon());
	}
	action->setIcon(QIcon("Resources/选中.png"));
	emit sig_menuTriggered(action->text());

}

void WidgetYGGL::receiveChangeName(const QString& pro) {

	cbx_pro_bef_change->setCurrentText(pro);

}

void WidgetYGGL::onsig_forSuccessful_YGGL(const QString& operation) {

	if (operation == "entry" || operation == "out")
		emit sig_sendChangeName(curTextOfLine_name_change);

	if (operation == "entry" || operation == "out" || operation == "change") {
		emit btn4_da->clicked();
		emit btn4_bx->clicked();
	}

	if (operation == "save1") {
		QString birthday = QString("%1-%2-%3").arg(line_10_in_widgetForPeople->text().mid(6, 4))
			.arg(line_10_in_widgetForPeople->text().mid(10, 2)).arg(line_10_in_widgetForPeople->text().mid(12, 2));
		QString age = "";
		if (QDate::currentDate().month() > line_10_in_widgetForPeople->text().mid(10, 2) ||
			QDate::currentDate().month() == line_10_in_widgetForPeople->text().mid(10, 2) &&
			QDate::currentDate().day() >= line_10_in_widgetForPeople->text().mid(12, 2))
			age = QString::number(QDate::currentDate().year() - line_10_in_widgetForPeople->text().mid(6, 4).toInt());
		else age = QString::number(QDate::currentDate().year() - line_10_in_widgetForPeople->text().mid(6, 4).toInt() - 1);
		QString line_7_in_widgetForPeople_text = "";
		for (auto& c : line_7_in_widgetForPeople->text()) {
			if (c == '/') {
				c = '-';
			}
			line_7_in_widgetForPeople_text += c;
		}
		line_7_in_widgetForPeople->setText(line_7_in_widgetForPeople_text);
		qItemModel_da->item(cur_indexRow_da, 1)->setText(line_1_in_widgetForPeople->text());
		qItemModel_da->item(cur_indexRow_da, 2)->setText(line_2_in_widgetForPeople->text());
		qItemModel_da->item(cur_indexRow_da, 3)->setText(cbx_3_in_widgetForPeople->currentText());
		qItemModel_da->item(cur_indexRow_da, 4)->setText(age);
		qItemModel_da->item(cur_indexRow_da, 5)->setText(line_22_in_widgetForPeople->text());
		qItemModel_da->item(cur_indexRow_da, 6)->setText(line_5_in_widgetForPeople->text());
		qItemModel_da->item(cur_indexRow_da, 7)->setText(cbx_4_in_widgetForPeople->currentText());
		qItemModel_da->item(cur_indexRow_da, 8)->setText(line_6_in_widgetForPeople->text());
		qItemModel_da->item(cur_indexRow_da, 9)->setText(line_10_in_widgetForPeople->text());
		qItemModel_da->item(cur_indexRow_da, 10)->setText(line_12_in_widgetForPeople->text());
		qItemModel_da->item(cur_indexRow_da, 11)->setText(line_11_in_widgetForPeople->text());
		qItemModel_da->item(cur_indexRow_da, 12)->setText(line_8_in_widgetForPeople->text());
		qItemModel_da->item(cur_indexRow_da, 13)->setText(line_9_in_widgetForPeople->text());
		qItemModel_da->item(cur_indexRow_da, 14)->setText(line_7_in_widgetForPeople->text());
		qItemModel_da->item(cur_indexRow_da, 15)->setText(birthday);
		qItemModel_da->item(cur_indexRow_da, 16)->setText(line_16_in_widgetForPeople->text());
		qItemModel_da->item(cur_indexRow_da, 17)->setText(line_17_in_widgetForPeople->text());
		qItemModel_da->item(cur_indexRow_da, 18)->setText(line_19_in_widgetForPeople->text());
		qItemModel_da->item(cur_indexRow_da, 19)->setText(line_18_in_widgetForPeople->text());
		qItemModel_da->item(cur_indexRow_da, 20)->setText(line_15_in_widgetForPeople->text());
		qItemModel_da->item(cur_indexRow_da, 21)->setText(line_21_in_widgetForPeople->text());
		qItemModel_da->item(cur_indexRow_da, 22)->setText(cbx_14_in_widgetForPeople->currentText());
		qItemModel_da->item(cur_indexRow_da, 23)->setText(cbx_20_in_widgetForPeople->currentText());
	}

	if (operation == "save2") {
		qItemModel_bx->item(cur_indexRow_bx, 5)->setText(cbxsb->currentText());
		qItemModel_bx->item(cur_indexRow_bx, 6)->setText(cbxgsx->currentText());
		qItemModel_bx->item(cur_indexRow_bx, 7)->setText(cbxywx->currentText());
	}

}

void WidgetYGGL::onCbxPro_currentTextChanged(const QString& pro) {

	//档案查询
	cbx1_da->setCurrentIndex(0);
	cbx2_da->setCurrentIndex(0);
	line3_da->clear();
	QVector<QString> v_forEmployeeInfoData;
	v_forEmployeeInfoData.push_back(pro);
	v_forEmployeeInfoData.push_back(cbx1_da->currentText());
	v_forEmployeeInfoData.push_back(cbx2_da->currentText());
	v_forEmployeeInfoData.push_back(line3_da->text());
	emit sig_forGetEmployeeInfoData(v_forEmployeeInfoData);

	//保险查询
	cbx1_bx->setCurrentIndex(0);
	cbx2_bx->setCurrentIndex(0);
	cbx3_bx->setCurrentIndex(0);
	QVector<QString> v_forInsuranceInfoData;
	v_forInsuranceInfoData.push_back(pro);
	v_forInsuranceInfoData.push_back(cbx1_bx->currentText());
	v_forInsuranceInfoData.push_back(cbx2_bx->currentText());
	v_forInsuranceInfoData.push_back(cbx3_bx->currentText());
	emit sig_forGetInsuranceInfo(v_forInsuranceInfoData);

}

void WidgetYGGL::receiveEmployeeInfo(QVector<QVector<QString>> employeeInfoData) {

	qItemModel_da->removeRows(0, qItemModel_da->rowCount());

	for (auto it = v_btnpeople.begin(); it != v_btnpeople.end(); ++it) {
		delete (*it); (*it) = NULL;
	}
	v_btnpeople.clear();

	if (employeeInfoData.isEmpty()) return;

	int cur_row = 0;
	for (auto it = employeeInfoData.cbegin(); it != employeeInfoData.cend(); ++it) {
		for (int i = 0; i < 25; ++i) {
			qItemModel_da->setItem(cur_row, i + 1, new QStandardItem(it->at(i)));
			qItemModel_da->item(cur_row, i + 1)->setFlags(qItemModel_da->item(cur_row, i + 1)->flags() & ~Qt::ItemIsEditable);
			qItemModel_da->item(cur_row, i + 1)->setTextAlignment(Qt::AlignCenter);
		}
		QPushButton* btnpeople = new QPushButton(this);
		btnpeople->setCursor(Qt::CursorShape::PointingHandCursor);
		btnpeople->setFont(QFont("宋体", 7));
		btnpeople->setStyleSheet(
			"QPushButton{border: 0px;image:url(Resources/人.png);}"
			"QPushButton:hover{image:url(Resources/人_red.png);}"
		);
		tableView_da->setIndexWidget(qItemModel_da->index(cur_row, 0), btnpeople);
		connect(btnpeople, &QPushButton::clicked, [=]
			{
				imagePath_in_widgetForPeople = "";
				cur_indexRow_da = cur_row;
				emit sig_sendImageData(qItemModel_da->item(cur_row, 2)->text());
				QWidget* widgetForPeople = new QWidget();
				widgetForPeople->setWindowModality(Qt::ApplicationModal);
				widgetForPeople->setAttribute(Qt::WA_DeleteOnClose);
				widgetForPeople->setWindowIcon(QPixmap("Resources/logo.png"));
				widgetForPeople->setWindowTitle("员工个人信息");
				widgetForPeople->setFixedSize(1600, 1000);
				widgetForPeople->setStyleSheet(QString::fromUtf8("QWidget{background:url(Resources/bkgrdfreject.png) center no-repeat;}"));
				widgetForPeople->show();

				QLabel* label_1_in_widgetForPeople = new QLabel(widgetForPeople);
				label_1_in_widgetForPeople->setText("项目:");
				label_1_in_widgetForPeople->setGeometry(QRect(30, 100, 150, 50));
				label_1_in_widgetForPeople->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
				label_1_in_widgetForPeople->setFont(QFont("宋体", 10));
				label_1_in_widgetForPeople->show();

				QLabel* label_2_in_widgetForPeople = new QLabel(widgetForPeople);
				label_2_in_widgetForPeople->setText("姓名:");
				label_2_in_widgetForPeople->setGeometry(QRect(30, 180, 150, 50));
				label_2_in_widgetForPeople->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
				label_2_in_widgetForPeople->setFont(QFont("宋体", 10));
				label_2_in_widgetForPeople->show();

				QLabel* label_3_in_widgetForPeople = new QLabel(widgetForPeople);
				label_3_in_widgetForPeople->setText("性别:");
				label_3_in_widgetForPeople->setGeometry(QRect(30, 260, 150, 50));
				label_3_in_widgetForPeople->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
				label_3_in_widgetForPeople->setFont(QFont("宋体", 10));
				label_3_in_widgetForPeople->show();

				QLabel* label_4_in_widgetForPeople = new QLabel(widgetForPeople);
				label_4_in_widgetForPeople->setText("部门:");
				label_4_in_widgetForPeople->setGeometry(QRect(30, 340, 150, 50));
				label_4_in_widgetForPeople->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
				label_4_in_widgetForPeople->setFont(QFont("宋体", 10));
				label_4_in_widgetForPeople->show();

				QLabel* label_5_in_widgetForPeople = new QLabel(widgetForPeople);
				label_5_in_widgetForPeople->setText("职务:");
				label_5_in_widgetForPeople->setGeometry(QRect(30, 420, 150, 50));
				label_5_in_widgetForPeople->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
				label_5_in_widgetForPeople->setFont(QFont("宋体", 10));
				label_5_in_widgetForPeople->show();

				QLabel* label_6_in_widgetForPeople = new QLabel(widgetForPeople);
				label_6_in_widgetForPeople->setText("工号牌:");
				label_6_in_widgetForPeople->setGeometry(QRect(30, 500, 150, 50));
				label_6_in_widgetForPeople->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
				label_6_in_widgetForPeople->setFont(QFont("宋体", 10));
				label_6_in_widgetForPeople->show();

				QLabel* label_7_in_widgetForPeople = new QLabel(widgetForPeople);
				label_7_in_widgetForPeople->setText("入职时间:");
				label_7_in_widgetForPeople->setGeometry(QRect(30, 580, 150, 50));
				label_7_in_widgetForPeople->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
				label_7_in_widgetForPeople->setFont(QFont("宋体", 10));
				label_7_in_widgetForPeople->show();

				QLabel* label_8_in_widgetForPeople = new QLabel(widgetForPeople);
				label_8_in_widgetForPeople->setText("电话:");
				label_8_in_widgetForPeople->setGeometry(QRect(530, 100, 150, 50));
				label_8_in_widgetForPeople->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
				label_8_in_widgetForPeople->setFont(QFont("宋体", 10));
				label_8_in_widgetForPeople->show();

				QLabel* label_9_in_widgetForPeople = new QLabel(widgetForPeople);
				label_9_in_widgetForPeople->setText("应急电话:");
				label_9_in_widgetForPeople->setGeometry(QRect(530, 180, 150, 50));
				label_9_in_widgetForPeople->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
				label_9_in_widgetForPeople->setFont(QFont("宋体", 10));
				label_9_in_widgetForPeople->show();

				QLabel* label_10_in_widgetForPeople = new QLabel(widgetForPeople);
				label_10_in_widgetForPeople->setText("身份证号:");
				label_10_in_widgetForPeople->setGeometry(QRect(530, 260, 150, 50));
				label_10_in_widgetForPeople->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
				label_10_in_widgetForPeople->setFont(QFont("宋体", 10));
				label_10_in_widgetForPeople->show();

				QLabel* label_11_in_widgetForPeople = new QLabel(widgetForPeople);
				label_11_in_widgetForPeople->setText("民族:");
				label_11_in_widgetForPeople->setGeometry(QRect(530, 340, 150, 50));
				label_11_in_widgetForPeople->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
				label_11_in_widgetForPeople->setFont(QFont("宋体", 10));
				label_11_in_widgetForPeople->show();

				QLabel* label_12_in_widgetForPeople = new QLabel(widgetForPeople);
				label_12_in_widgetForPeople->setText("籍贯:");
				label_12_in_widgetForPeople->setGeometry(QRect(530, 420, 150, 50));
				label_12_in_widgetForPeople->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
				label_12_in_widgetForPeople->setFont(QFont("宋体", 10));
				label_12_in_widgetForPeople->show();

				QLabel* label_13_in_widgetForPeople = new QLabel(widgetForPeople);
				label_13_in_widgetForPeople->setText("住址:");
				label_13_in_widgetForPeople->setGeometry(QRect(530, 500, 150, 50));
				label_13_in_widgetForPeople->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
				label_13_in_widgetForPeople->setFont(QFont("宋体", 10));
				label_13_in_widgetForPeople->show();

				QLabel* label_14_in_widgetForPeople = new QLabel(widgetForPeople);
				label_14_in_widgetForPeople->setText("婚姻状况:");
				label_14_in_widgetForPeople->setGeometry(QRect(530, 580, 150, 50));
				label_14_in_widgetForPeople->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
				label_14_in_widgetForPeople->setFont(QFont("宋体", 10));
				label_14_in_widgetForPeople->show();

				QLabel* label_15_in_widgetForPeople = new QLabel(widgetForPeople);
				label_15_in_widgetForPeople->setText("特长:");
				label_15_in_widgetForPeople->setGeometry(QRect(530, 660, 150, 50));
				label_15_in_widgetForPeople->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
				label_15_in_widgetForPeople->setFont(QFont("宋体", 10));
				label_15_in_widgetForPeople->show();

				QLabel* label_16_in_widgetForPeople = new QLabel(widgetForPeople);
				label_16_in_widgetForPeople->setText("学历:");
				label_16_in_widgetForPeople->setGeometry(QRect(1030, 660, 150, 50));
				label_16_in_widgetForPeople->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
				label_16_in_widgetForPeople->setFont(QFont("宋体", 10));
				label_16_in_widgetForPeople->show();

				QLabel* label_17_in_widgetForPeople = new QLabel(widgetForPeople);
				label_17_in_widgetForPeople->setText("专业:");
				label_17_in_widgetForPeople->setGeometry(QRect(30, 740, 150, 50));
				label_17_in_widgetForPeople->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
				label_17_in_widgetForPeople->setFont(QFont("宋体", 10));
				label_17_in_widgetForPeople->show();

				QLabel* label_18_in_widgetForPeople = new QLabel(widgetForPeople);
				label_18_in_widgetForPeople->setText("职称:");
				label_18_in_widgetForPeople->setGeometry(QRect(530, 740, 150, 50));
				label_18_in_widgetForPeople->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
				label_18_in_widgetForPeople->setFont(QFont("宋体", 10));
				label_18_in_widgetForPeople->show();

				QLabel* label_19_in_widgetForPeople = new QLabel(widgetForPeople);
				label_19_in_widgetForPeople->setText("证书:");
				label_19_in_widgetForPeople->setGeometry(QRect(1030, 740, 150, 50));
				label_19_in_widgetForPeople->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
				label_19_in_widgetForPeople->setFont(QFont("宋体", 10));
				label_19_in_widgetForPeople->show();

				QLabel* label_20_in_widgetForPeople = new QLabel(widgetForPeople);
				label_20_in_widgetForPeople->setText("政治面貌:");
				label_20_in_widgetForPeople->setGeometry(QRect(1030, 500, 150, 50));
				label_20_in_widgetForPeople->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
				label_20_in_widgetForPeople->setFont(QFont("宋体", 10));
				label_20_in_widgetForPeople->show();

				QLabel* label_21_in_widgetForPeople = new QLabel(widgetForPeople);
				label_21_in_widgetForPeople->setText("健康状况:");
				label_21_in_widgetForPeople->setGeometry(QRect(1030, 580, 150, 50));
				label_21_in_widgetForPeople->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
				label_21_in_widgetForPeople->setFont(QFont("宋体", 10));
				label_21_in_widgetForPeople->show();

				QLabel* label_22_in_widgetForPeople = new QLabel(widgetForPeople);
				label_22_in_widgetForPeople->setText("合同:");
				label_22_in_widgetForPeople->setGeometry(QRect(30, 660, 150, 50));
				label_22_in_widgetForPeople->setAlignment(Qt::AlignVCenter | Qt::AlignRight);
				label_22_in_widgetForPeople->setFont(QFont("宋体", 10));
				label_22_in_widgetForPeople->show();

				line_1_in_widgetForPeople = new QLineEdit(widgetForPeople);
				line_1_in_widgetForPeople->setFont(QFont("宋体", 10));
				line_1_in_widgetForPeople->setGeometry(QRect(180, 100, 350, 50));
				line_1_in_widgetForPeople->setEnabled(false);
				line_1_in_widgetForPeople->setStyleSheet(QString::fromUtf8(
					"QLineEdit{ background-color:rgb(255,255,255);color:rgb(0,0,0);"
					"border: 1px solid rgb(200,200,200); border-radius: 10px;}"
					"QLineEdit:hover{background-color: rgb(245, 245, 245);}"
					"QLineEdit:focus{border: 1px solid grey;background-color:rgb(255,255,255);}"));
				line_1_in_widgetForPeople->show();

				line_2_in_widgetForPeople = new QLineEdit(widgetForPeople);
				line_2_in_widgetForPeople->setFont(QFont("宋体", 10));
				line_2_in_widgetForPeople->setGeometry(QRect(180, 180, 350, 50));
				line_2_in_widgetForPeople->setStyleSheet(QString::fromUtf8(
					"QLineEdit{ background-color:rgb(255,255,255);"
					"border: 1px solid rgb(200,200,200); border-radius: 10px;}"
					"QLineEdit:hover{background-color: rgb(245, 245, 245);}"
					"QLineEdit:focus{border: 1px solid grey;background-color:rgb(255,255,255);}"));
				line_2_in_widgetForPeople->show();

				cbx_3_in_widgetForPeople = new QComboBox(widgetForPeople);
				cbx_3_in_widgetForPeople->setFont(QFont("宋体", 10));
				cbx_3_in_widgetForPeople->setGeometry(QRect(180, 260, 350, 50));
				cbx_3_in_widgetForPeople->setFocusPolicy(Qt::NoFocus);
				cbx_3_in_widgetForPeople->setStyleSheet(QString::fromUtf8(" QComboBox {"
					"      border: 1px solid rgb(200,200,200);"
					"      border-radius: 10px;"
					"      padding: 1px 0px 1px 3px;"
					"      background-color: rgb(255, 255, 255);"
					"  }"
					"  QComboBox:on {"
					"      border: 1px solid grey;"
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
					"  QComboBox::down-arrow{"
					"      image: url(Resources/下拉.png);"
					"  }"
					"  QComboBox::down-arrow:on{"
					"      image: url(Resources/下拉_1.png);"
					"  }"
					"  QComboBox:hover{"
					"      background-color: rgb(245, 245, 245);"
					"  }"
				));
				cbx_3_in_widgetForPeople->addItem("男");
				cbx_3_in_widgetForPeople->addItem("女");
				QStandardItemModel* qItemModel = qobject_cast<QStandardItemModel*>(cbx_3_in_widgetForPeople->model());
				for (int i = 0; i < 2; ++i) qItemModel->item(i)->setBackground(QBrush(QColor(255, 255, 255)));
				cbx_3_in_widgetForPeople->show();

				cbx_4_in_widgetForPeople = new QComboBox(widgetForPeople);
				cbx_4_in_widgetForPeople->setFont(QFont("宋体", 10));
				cbx_4_in_widgetForPeople->setGeometry(QRect(180, 340, 350, 50));
				cbx_4_in_widgetForPeople->setFocusPolicy(Qt::NoFocus);
				cbx_4_in_widgetForPeople->setStyleSheet(QString::fromUtf8(" QComboBox {"
					"      border: 1px solid rgb(200,200,200);"
					"      border-radius: 10px;"
					"      padding: 1px 0px 1px 3px;"
					"      background-color: rgb(255, 255, 255);"
					"  }"
					"  QComboBox:on {"
					"      border: 1px solid grey;"
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
					"  QComboBox::down-arrow{"
					"      image: url(Resources/下拉.png);"
					"  }"
					"  QComboBox::down-arrow:on{"
					"      image: url(Resources/下拉_1.png);"
					"  }"
					"  QComboBox:hover{"
					"      background-color: rgb(245, 245, 245);"
					"  }"
				));
				cbx_4_in_widgetForPeople->addItem("项目经理");
				cbx_4_in_widgetForPeople->addItem("行政部");
				cbx_4_in_widgetForPeople->addItem("客服部");
				cbx_4_in_widgetForPeople->addItem("工程部");
				cbx_4_in_widgetForPeople->addItem("秩序维护部");
				cbx_4_in_widgetForPeople->addItem("环境部绿化");
				cbx_4_in_widgetForPeople->addItem("环境部保洁");
				cbx_4_in_widgetForPeople->addItem("后勤部");
				qItemModel = qobject_cast<QStandardItemModel*>(cbx_4_in_widgetForPeople->model());
				for (int i = 0; i < 8; ++i) qItemModel->item(i)->setBackground(QBrush(QColor(255, 255, 255)));
				cbx_4_in_widgetForPeople->show();

				line_5_in_widgetForPeople = new QLineEdit(widgetForPeople);
				line_5_in_widgetForPeople->setFont(QFont("宋体", 10));
				line_5_in_widgetForPeople->setGeometry(QRect(180, 420, 350, 50));
				line_5_in_widgetForPeople->setStyleSheet(QString::fromUtf8(
					"QLineEdit{ background-color:rgb(255,255,255);"
					"border: 1px solid rgb(200,200,200); border-radius: 10px;}"
					"QLineEdit:hover{background-color: rgb(245, 245, 245);}"
					"QLineEdit:focus{border: 1px solid grey;background-color:rgb(255,255,255);}"));
				line_5_in_widgetForPeople->show();

				line_6_in_widgetForPeople = new QLineEdit(widgetForPeople);
				line_6_in_widgetForPeople->setFont(QFont("宋体", 10));
				line_6_in_widgetForPeople->setGeometry(QRect(180, 500, 350, 50));
				line_6_in_widgetForPeople->setStyleSheet(QString::fromUtf8(
					"QLineEdit{ background-color:rgb(255,255,255);"
					"border: 1px solid rgb(200,200,200); border-radius: 10px;}"
					"QLineEdit:hover{background-color: rgb(245, 245, 245);}"
					"QLineEdit:focus{border: 1px solid grey;background-color:rgb(255,255,255);}"));
				line_6_in_widgetForPeople->show();

				line_7_in_widgetForPeople = new QLineEdit(widgetForPeople);
				line_7_in_widgetForPeople->setFont(QFont("宋体", 10));
				line_7_in_widgetForPeople->setGeometry(QRect(180, 580, 350, 50));
				line_7_in_widgetForPeople->setStyleSheet(QString::fromUtf8(
					"QLineEdit{ background-color:rgb(255,255,255);"
					"border: 1px solid rgb(200,200,200); border-radius: 10px;}"
					"QLineEdit:hover{background-color: rgb(245, 245, 245);}"
					"QLineEdit:focus{border: 1px solid grey;background-color:rgb(255,255,255);}"));
				line_7_in_widgetForPeople->show();

				line_8_in_widgetForPeople = new QLineEdit(widgetForPeople);
				line_8_in_widgetForPeople->setFont(QFont("宋体", 10));
				line_8_in_widgetForPeople->setGeometry(QRect(680, 100, 350, 50));
				line_8_in_widgetForPeople->setStyleSheet(QString::fromUtf8(
					"QLineEdit{ background-color:rgb(255,255,255);"
					"border: 1px solid rgb(200,200,200); border-radius: 10px;}"
					"QLineEdit:hover{background-color: rgb(245, 245, 245);}"
					"QLineEdit:focus{border: 1px solid grey;background-color:rgb(255,255,255);}"));
				line_8_in_widgetForPeople->show();

				line_9_in_widgetForPeople = new QLineEdit(widgetForPeople);
				line_9_in_widgetForPeople->setFont(QFont("宋体", 10));
				line_9_in_widgetForPeople->setGeometry(QRect(680, 180, 350, 50));
				line_9_in_widgetForPeople->setStyleSheet(QString::fromUtf8(
					"QLineEdit{ background-color:rgb(255,255,255);"
					"border: 1px solid rgb(200,200,200); border-radius: 10px;}"
					"QLineEdit:hover{background-color: rgb(245, 245, 245);}"
					"QLineEdit:focus{border: 1px solid grey;background-color:rgb(255,255,255);}"));
				line_9_in_widgetForPeople->show();

				line_10_in_widgetForPeople = new QLineEdit(widgetForPeople);
				line_10_in_widgetForPeople->setFont(QFont("宋体", 10));
				line_10_in_widgetForPeople->setGeometry(QRect(680, 260, 350, 50));
				line_10_in_widgetForPeople->setStyleSheet(QString::fromUtf8(
					"QLineEdit{ background-color:rgb(255,255,255);"
					"border: 1px solid rgb(200,200,200); border-radius: 10px;}"
					"QLineEdit:hover{background-color: rgb(245, 245, 245);}"
					"QLineEdit:focus{border: 1px solid grey;background-color:rgb(255,255,255);}"));
				line_10_in_widgetForPeople->show();

				line_11_in_widgetForPeople = new QLineEdit(widgetForPeople);
				line_11_in_widgetForPeople->setFont(QFont("宋体", 10));
				line_11_in_widgetForPeople->setGeometry(QRect(680, 340, 350, 50));
				line_11_in_widgetForPeople->setStyleSheet(QString::fromUtf8(
					"QLineEdit{ background-color:rgb(255,255,255);"
					"border: 1px solid rgb(200,200,200); border-radius: 10px;}"
					"QLineEdit:hover{background-color: rgb(245, 245, 245);}"
					"QLineEdit:focus{border: 1px solid grey;background-color:rgb(255,255,255);}"));
				line_11_in_widgetForPeople->show();

				line_12_in_widgetForPeople = new QLineEdit(widgetForPeople);
				line_12_in_widgetForPeople->setFont(QFont("宋体", 10));
				line_12_in_widgetForPeople->setGeometry(QRect(680, 420, 350, 50));
				line_12_in_widgetForPeople->setStyleSheet(QString::fromUtf8(
					"QLineEdit{ background-color:rgb(255,255,255);"
					"border: 1px solid rgb(200,200,200); border-radius: 10px;}"
					"QLineEdit:hover{background-color: rgb(245, 245, 245);}"
					"QLineEdit:focus{border: 1px solid grey;background-color:rgb(255,255,255);}"));
				line_12_in_widgetForPeople->show();

				line_13_in_widgetForPeople = new QLineEdit(widgetForPeople);
				line_13_in_widgetForPeople->setFont(QFont("宋体", 10));
				line_13_in_widgetForPeople->setGeometry(QRect(680, 500, 350, 50));
				line_13_in_widgetForPeople->setStyleSheet(QString::fromUtf8(
					"QLineEdit{ background-color:rgb(255,255,255);"
					"border: 1px solid rgb(200,200,200); border-radius: 10px;}"
					"QLineEdit:hover{background-color: rgb(245, 245, 245);}"
					"QLineEdit:focus{border: 1px solid grey;background-color:rgb(255,255,255);}"));
				line_13_in_widgetForPeople->show();

				cbx_14_in_widgetForPeople = new QComboBox(widgetForPeople);
				cbx_14_in_widgetForPeople->setFont(QFont("宋体", 10));
				cbx_14_in_widgetForPeople->setGeometry(QRect(680, 580, 350, 50));
				cbx_14_in_widgetForPeople->setFocusPolicy(Qt::NoFocus);
				cbx_14_in_widgetForPeople->setStyleSheet(QString::fromUtf8(" QComboBox {"
					"      border: 1px solid rgb(200,200,200);"
					"      border-radius: 10px;"
					"      padding: 1px 0px 1px 3px;"
					"      background-color: rgb(255, 255, 255);"
					"  }"
					"  QComboBox:on {"
					"      border: 1px solid grey;"
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
					"  QComboBox::down-arrow{"
					"      image: url(Resources/下拉.png);"
					"  }"
					"  QComboBox::down-arrow:on{"
					"      image: url(Resources/下拉_1.png);"
					"  }"
					"  QComboBox:hover{"
					"      background-color: rgb(245, 245, 245);"
					"  }"
				));
				cbx_14_in_widgetForPeople->addItem("已婚");
				cbx_14_in_widgetForPeople->addItem("未婚");
				qItemModel = qobject_cast<QStandardItemModel*>(cbx_14_in_widgetForPeople->model());
				for (int i = 0; i < 2; ++i) qItemModel->item(i)->setBackground(QBrush(QColor(255, 255, 255)));
				cbx_14_in_widgetForPeople->show();

				line_15_in_widgetForPeople = new QLineEdit(widgetForPeople);
				line_15_in_widgetForPeople->setFont(QFont("宋体", 10));
				line_15_in_widgetForPeople->setGeometry(QRect(680, 660, 350, 50));
				line_15_in_widgetForPeople->setStyleSheet(QString::fromUtf8(
					"QLineEdit{ background-color:rgb(255,255,255);"
					"border: 1px solid rgb(200,200,200); border-radius: 10px;}"
					"QLineEdit:hover{background-color: rgb(245, 245, 245);}"
					"QLineEdit:focus{border: 1px solid grey;background-color:rgb(255,255,255);}"));
				line_15_in_widgetForPeople->show();

				line_16_in_widgetForPeople = new QLineEdit(widgetForPeople);
				line_16_in_widgetForPeople->setFont(QFont("宋体", 10));
				line_16_in_widgetForPeople->setGeometry(QRect(1180, 660, 350, 50));
				line_16_in_widgetForPeople->setStyleSheet(QString::fromUtf8(
					"QLineEdit{ background-color:rgb(255,255,255);"
					"border: 1px solid rgb(200,200,200); border-radius: 10px;}"
					"QLineEdit:hover{background-color: rgb(245, 245, 245);}"
					"QLineEdit:focus{border: 1px solid grey;background-color:rgb(255,255,255);}"));
				line_16_in_widgetForPeople->show();

				line_17_in_widgetForPeople = new QLineEdit(widgetForPeople);
				line_17_in_widgetForPeople->setFont(QFont("宋体", 10));
				line_17_in_widgetForPeople->setGeometry(QRect(180, 740, 350, 50));
				line_17_in_widgetForPeople->setStyleSheet(QString::fromUtf8(
					"QLineEdit{ background-color:rgb(255,255,255);"
					"border: 1px solid rgb(200,200,200); border-radius: 10px;}"
					"QLineEdit:hover{background-color: rgb(245, 245, 245);}"
					"QLineEdit:focus{border: 1px solid grey;background-color:rgb(255,255,255);}"));
				line_17_in_widgetForPeople->show();

				line_18_in_widgetForPeople = new QLineEdit(widgetForPeople);
				line_18_in_widgetForPeople->setFont(QFont("宋体", 10));
				line_18_in_widgetForPeople->setGeometry(QRect(680, 740, 350, 50));
				line_18_in_widgetForPeople->setStyleSheet(QString::fromUtf8(
					"QLineEdit{ background-color:rgb(255,255,255);"
					"border: 1px solid rgb(200,200,200); border-radius: 10px;}"
					"QLineEdit:hover{background-color: rgb(245, 245, 245);}"
					"QLineEdit:focus{border: 1px solid grey;background-color:rgb(255,255,255);}"));
				line_18_in_widgetForPeople->show();

				line_19_in_widgetForPeople = new QLineEdit(widgetForPeople);
				line_19_in_widgetForPeople->setFont(QFont("宋体", 10));
				line_19_in_widgetForPeople->setGeometry(QRect(1180, 740, 350, 50));
				line_19_in_widgetForPeople->setStyleSheet(QString::fromUtf8(
					"QLineEdit{ background-color:rgb(255,255,255);"
					"border: 1px solid rgb(200,200,200); border-radius: 10px;}"
					"QLineEdit:hover{background-color: rgb(245, 245, 245);}"
					"QLineEdit:focus{border: 1px solid grey;background-color:rgb(255,255,255);}"));
				line_19_in_widgetForPeople->show();

				cbx_20_in_widgetForPeople = new QComboBox(widgetForPeople);
				cbx_20_in_widgetForPeople->setFont(QFont("宋体", 10));
				cbx_20_in_widgetForPeople->setGeometry(QRect(1180, 500, 350, 50));
				cbx_20_in_widgetForPeople->setFocusPolicy(Qt::NoFocus);
				cbx_20_in_widgetForPeople->setStyleSheet(QString::fromUtf8(" QComboBox {"
					"      border: 1px solid rgb(200,200,200);"
					"      border-radius: 10px;"
					"      padding: 1px 0px 1px 3px;"
					"      background-color: rgb(255, 255, 255);"
					"  }"
					"  QComboBox:on {"
					"      border: 1px solid grey;"
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
					"  QComboBox::down-arrow{"
					"      image: url(Resources/下拉.png);"
					"  }"
					"  QComboBox::down-arrow:on{"
					"      image: url(Resources/下拉_1.png);"
					"  }"
					"  QComboBox:hover{"
					"      background-color: rgb(245, 245, 245);"
					"  }"
				));
				cbx_20_in_widgetForPeople->addItem("群众");
				cbx_20_in_widgetForPeople->addItem("共青团员");
				cbx_20_in_widgetForPeople->addItem("共产党员");
				qItemModel = qobject_cast<QStandardItemModel*>(cbx_20_in_widgetForPeople->model());
				for (int i = 0; i < 3; ++i) qItemModel->item(i)->setBackground(QBrush(QColor(255, 255, 255)));
				cbx_20_in_widgetForPeople->show();

				line_21_in_widgetForPeople = new QLineEdit(widgetForPeople);
				line_21_in_widgetForPeople->setFont(QFont("宋体", 10));
				line_21_in_widgetForPeople->setGeometry(QRect(1180, 580, 350, 50));
				line_21_in_widgetForPeople->setStyleSheet(QString::fromUtf8(
					"QLineEdit{ background-color:rgb(255,255,255);"
					"border: 1px solid rgb(200,200,200); border-radius: 10px;}"
					"QLineEdit:hover{background-color: rgb(245, 245, 245);}"
					"QLineEdit:focus{border: 1px solid grey;background-color:rgb(255,255,255);}"));
				line_21_in_widgetForPeople->show();

				line_22_in_widgetForPeople = new QLineEdit(widgetForPeople);
				line_22_in_widgetForPeople->setFont(QFont("宋体", 10));
				line_22_in_widgetForPeople->setGeometry(QRect(180, 660, 350, 50));
				line_22_in_widgetForPeople->setStyleSheet(QString::fromUtf8(
					"QLineEdit{ background-color:rgb(255,255,255);"
					"border: 1px solid rgb(200,200,200); border-radius: 10px;}"
					"QLineEdit:hover{background-color: rgb(245, 245, 245);}"
					"QLineEdit:focus{border: 1px solid grey;background-color:rgb(255,255,255);}"));
				line_22_in_widgetForPeople->show();

				line_1_in_widgetForPeople->setText(qItemModel_da->item(cur_row, 1)->text());
				line_2_in_widgetForPeople->setText(qItemModel_da->item(cur_row, 2)->text());
				cbx_3_in_widgetForPeople->setCurrentText(qItemModel_da->item(cur_row, 3)->text());
				cbx_4_in_widgetForPeople->setCurrentText(qItemModel_da->item(cur_row, 7)->text());
				line_5_in_widgetForPeople->setText(qItemModel_da->item(cur_row, 6)->text());
				line_6_in_widgetForPeople->setText(qItemModel_da->item(cur_row, 8)->text());
				line_7_in_widgetForPeople->setText(qItemModel_da->item(cur_row, 14)->text());
				line_8_in_widgetForPeople->setText(qItemModel_da->item(cur_row, 12)->text());
				line_9_in_widgetForPeople->setText(qItemModel_da->item(cur_row, 13)->text());
				line_10_in_widgetForPeople->setText(qItemModel_da->item(cur_row, 9)->text());
				line_11_in_widgetForPeople->setText(qItemModel_da->item(cur_row, 11)->text());
				line_12_in_widgetForPeople->setText(qItemModel_da->item(cur_row, 10)->text());
				cbx_14_in_widgetForPeople->setCurrentText(qItemModel_da->item(cur_row, 22)->text());
				line_15_in_widgetForPeople->setText(qItemModel_da->item(cur_row, 20)->text());
				line_16_in_widgetForPeople->setText(qItemModel_da->item(cur_row, 16)->text());
				line_17_in_widgetForPeople->setText(qItemModel_da->item(cur_row, 17)->text());
				line_18_in_widgetForPeople->setText(qItemModel_da->item(cur_row, 19)->text());
				line_19_in_widgetForPeople->setText(qItemModel_da->item(cur_row, 18)->text());
				cbx_20_in_widgetForPeople->setCurrentText(qItemModel_da->item(cur_row, 23)->text());
				line_21_in_widgetForPeople->setText(qItemModel_da->item(cur_row, 21)->text());
				line_22_in_widgetForPeople->setText(qItemModel_da->item(cur_row, 5)->text());

				//证件照部分
				//begin
				label_pic_in_widgetForPeople = new QLabel(widgetForPeople);
				label_pic_in_widgetForPeople->setGeometry(QRect(1260, 100, 265, 370));
				label_pic_in_widgetForPeople->setStyleSheet("border:1px solid black;background-color:white;");
				label_pic_in_widgetForPeople->show();

				QPushButton* btn_pic_in_widgetForPeople = new QPushButton(widgetForPeople);
				btn_pic_in_widgetForPeople->setGeometry(QRect(1050, 100, 210, 370));
				btn_pic_in_widgetForPeople->setFont(QFont("楷体", 12));
				btn_pic_in_widgetForPeople->setStyleSheet(QString::fromUtf8(
					"QPushButton{				             "
					"  border-style: outset;				 "
					"  border-width: 1px;					 "
					"  border-color: black;				     "
					"}										 "
					"QPushButton:hover{"
					"  background-color: rgba(255, 255, 255, 102);"
					"}"
					"QPushButton:pressed{		             "
					"  border-style: inset;				     "
					"  background-color: rgba(255, 255, 255, 204);"
					"}										 "
				));
				btn_pic_in_widgetForPeople->setText("选择图片文件\n(支持bmp,jpg,\npng等格式)");
				btn_pic_in_widgetForPeople->show();
				connect(btn_pic_in_widgetForPeople, &QPushButton::clicked, [=]
					{
						imagePath_in_widgetForPeople = QFileDialog::getOpenFileName(NULL, "选择文件", ".", "Image Files (*.png *.jpg *.bmp)");
						if (imagePath_in_widgetForPeople.isEmpty())
							return;
						QPixmap pix(imagePath_in_widgetForPeople);
						pix.scaled(QSize(265, 370), Qt::IgnoreAspectRatio);
						label_pic_in_widgetForPeople->setPixmap(pix);
						label_pic_in_widgetForPeople->setScaledContents(true);
					}
				);
				//end

				QPushButton* temp_btnY = new QPushButton(widgetForPeople);
				temp_btnY->setGeometry(QRect(625, 850, 150, 80));
				temp_btnY->setFont(QFont("楷体", 16));
				temp_btnY->setStyleSheet(QString::fromUtf8(
					"QPushButton{				             "
					"  border-style: outset;				 "
					"  border-width: 2px;					 "
					"  border-radius: 30px;				     "
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
				temp_btnY->setText("保存");
				temp_btnY->show();

				QPushButton* temp_btnN = new QPushButton(widgetForPeople);
				temp_btnN->setGeometry(QRect(825, 850, 150, 80));
				temp_btnN->setFont(QFont("楷体", 16));
				temp_btnN->setStyleSheet(QString::fromUtf8(
					"QPushButton{				             "
					"  border-style: outset;				 "
					"  border-width: 2px;					 "
					"  border-radius: 30px;				     "
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
				temp_btnN->setText("退出");
				temp_btnN->show();

				connect(temp_btnN, &QPushButton::clicked, [=] {widgetForPeople->close(); });
				connect(temp_btnY, &QPushButton::clicked, [=]
					{
						if (line_2_in_widgetForPeople->text().isEmpty()) {
							QMessageBox box(QMessageBox::Information, "提示", "姓名不可为空！");
							box.setStandardButtons(QMessageBox::Ok);
							box.setButtonText(QMessageBox::Ok, QString("确 定"));
							box.setWindowIcon(QPixmap("Resources/logo.png"));
							int button = box.exec();
							return;
						}
						if (checkTime(line_7_in_widgetForPeople->text(), '-') == false) {
							QMessageBox box(QMessageBox::Information, "提示", "时间格式不正确！");
							box.setStandardButtons(QMessageBox::Ok);
							box.setButtonText(QMessageBox::Ok, QString("确 定"));
							box.setWindowIcon(QPixmap("Resources/logo.png"));
							int button = box.exec();
							return;
						}
						if (line_8_in_widgetForPeople->text().isEmpty()) {
							QMessageBox box(QMessageBox::Information, "提示", "电话不可为空！");
							box.setStandardButtons(QMessageBox::Ok);
							box.setButtonText(QMessageBox::Ok, QString("确 定"));
							box.setWindowIcon(QPixmap("Resources/logo.png"));
							int button = box.exec();
							return;
						}
						//判断身份证号码是否有效begin
						if (line_10_in_widgetForPeople->text().length() != 18) {
							QMessageBox box(QMessageBox::Information, "提示", "请输入18位有效身份证号码！");
							box.setStandardButtons(QMessageBox::Ok);
							box.setButtonText(QMessageBox::Ok, QString("确 定"));
							box.setWindowIcon(QPixmap("Resources/logo.png"));
							int button = box.exec();
							return;
						}
						for (int i = 0; i < 17; ++i) {
							if (!line_10_in_widgetForPeople->text()[i].isDigit()) {
								QMessageBox box(QMessageBox::Information, "提示", "请输入18位有效身份证号码！");
								box.setStandardButtons(QMessageBox::Ok);
								box.setButtonText(QMessageBox::Ok, QString("确 定"));
								box.setWindowIcon(QPixmap("Resources/logo.png"));
								int button = box.exec();
								return;
							}
						}
						if ((!line_10_in_widgetForPeople->text()[17].isDigit())
							&& line_10_in_widgetForPeople->text()[17] != 'x'
							&& line_10_in_widgetForPeople->text()[17] != 'X') {
							QMessageBox box(QMessageBox::Information, "提示", "请输入18位有效身份证号码！");
							box.setStandardButtons(QMessageBox::Ok);
							box.setButtonText(QMessageBox::Ok, QString("确 定"));
							box.setWindowIcon(QPixmap("Resources/logo.png"));
							int button = box.exec();
							return;
						}
						QString personalID = line_10_in_widgetForPeople->text();
						QString y = personalID.mid(6, 4);
						QString m = personalID.mid(10, 2);
						QString d = personalID.mid(12, 2);
						if (m.toInt() < 1 || m.toInt() > 12 || d.toInt() < 1 || d.toInt() > DateClass::getDayMaxOfMonth(y.toInt(), m.toInt())) {
							QMessageBox box(QMessageBox::Information, "提示", "请输入18位有效身份证号码(注意出生日期)！");
							box.setStandardButtons(QMessageBox::Ok);
							box.setButtonText(QMessageBox::Ok, QString("确 定"));
							box.setWindowIcon(QPixmap("Resources/logo.png"));
							int button = box.exec();
							return;
						}
						//end
						if (line_12_in_widgetForPeople->text().isEmpty()) {
							QMessageBox box(QMessageBox::Information, "提示", "籍贯不可为空！");
							box.setStandardButtons(QMessageBox::Ok);
							box.setButtonText(QMessageBox::Ok, QString("确 定"));
							box.setWindowIcon(QPixmap("Resources/logo.png"));
							int button = box.exec();
							return;
						}
						QMap<QString, QString> map_saveEmployeeInfo;
						map_saveEmployeeInfo.insert("xm", line_1_in_widgetForPeople->text());
						map_saveEmployeeInfo.insert("real_name", line_2_in_widgetForPeople->text());
						map_saveEmployeeInfo.insert("sex", cbx_3_in_widgetForPeople->currentText());
						map_saveEmployeeInfo.insert("bm", cbx_4_in_widgetForPeople->currentText());
						map_saveEmployeeInfo.insert("position", line_5_in_widgetForPeople->text());
						map_saveEmployeeInfo.insert("work_card", line_6_in_widgetForPeople->text());
						map_saveEmployeeInfo.insert("entry_time", line_7_in_widgetForPeople->text());
						map_saveEmployeeInfo.insert("contract", line_22_in_widgetForPeople->text());
						map_saveEmployeeInfo.insert("major", line_17_in_widgetForPeople->text());
						map_saveEmployeeInfo.insert("phone_num", line_8_in_widgetForPeople->text());
						map_saveEmployeeInfo.insert("emergency_phone_num", line_9_in_widgetForPeople->text());
						map_saveEmployeeInfo.insert("id_card", line_10_in_widgetForPeople->text());
						map_saveEmployeeInfo.insert("nation", line_11_in_widgetForPeople->text());
						map_saveEmployeeInfo.insert("hometown", line_12_in_widgetForPeople->text());
						map_saveEmployeeInfo.insert("address", line_13_in_widgetForPeople->text());
						map_saveEmployeeInfo.insert("marriage", cbx_14_in_widgetForPeople->currentText());
						map_saveEmployeeInfo.insert("speciality", line_15_in_widgetForPeople->text());
						map_saveEmployeeInfo.insert("job_title", line_18_in_widgetForPeople->text());
						map_saveEmployeeInfo.insert("political_status", cbx_20_in_widgetForPeople->currentText());
						map_saveEmployeeInfo.insert("state_of_health", line_21_in_widgetForPeople->text());
						map_saveEmployeeInfo.insert("degree", line_16_in_widgetForPeople->text());
						map_saveEmployeeInfo.insert("certificate", line_19_in_widgetForPeople->text());
						QString pic_format = "";
						for (int i = imagePath_in_widgetForPeople.lastIndexOf('.') + 1; i < imagePath_in_widgetForPeople.length(); ++i) {
							pic_format += imagePath_in_widgetForPeople[i];
						}
						map_saveEmployeeInfo.insert("pic_format", pic_format);
						map_saveEmployeeInfo.insert("prev_name", qItemModel_da->item(cur_row, 2)->text());

						QFile file(imagePath_in_widgetForPeople);
						file.open(QIODevice::ReadOnly);
						QByteArray data = file.readAll();
						file.close();

						emit sig_saveEmployeeInfo(map_saveEmployeeInfo, data);
					}
				);
			}
		);
		v_btnpeople.push_back(btnpeople);
		++cur_row;
	}

}

void WidgetYGGL::receiveImageData(const QString& pic_format, const QByteArray& data, const QString& address) {

	if (!data.isEmpty()) {
		QPixmap pix;
		pix.loadFromData(data, pic_format.toStdString().data());
		pix.scaled(QSize(265, 370), Qt::IgnoreAspectRatio);
		label_pic_in_widgetForPeople->setPixmap(pix);
		label_pic_in_widgetForPeople->setScaledContents(true);
	}
	else {
		label_pic_in_widgetForPeople->setPixmap(QPixmap("Resources/头像.png"));
	}

	line_13_in_widgetForPeople->setText(address);

}

void WidgetYGGL::receiveInsuranceInfo(QVector<QVector<QString>> insuranceInfoData) {

	if (qItemModel_bx->rowCount() != 0) qItemModel_bx->removeRows(0, qItemModel_bx->rowCount());

	for (auto it = v_btnchg.begin(); it != v_btnchg.end(); ++it) {
		delete (*it); (*it) = NULL;
	}
	v_btnchg.clear();

	if (insuranceInfoData.isEmpty()) return;

	int cur_row = 0;
	for (auto it = insuranceInfoData.cbegin(); it != insuranceInfoData.cend(); ++it) {
		for (int i = 0; i < 12; ++i) {
			qItemModel_bx->setItem(cur_row, i + 1, new QStandardItem(it->at(i)));
			qItemModel_bx->item(cur_row, i + 1)->setFlags(qItemModel_bx->item(cur_row, i + 1)->flags() & ~Qt::ItemIsEditable);
			qItemModel_bx->item(cur_row, i + 1)->setTextAlignment(Qt::AlignCenter);
		}
		QPushButton* btnchg = new QPushButton(this);
		btnchg->setCursor(Qt::CursorShape::PointingHandCursor);
		btnchg->setStyleSheet(
			"QPushButton{border: 0px;image:url(Resources/chg.png);}"
			"QPushButton:hover{image:url(Resources/chg_red.png);}"
		);
		tableView_bx->setIndexWidget(qItemModel_bx->index(cur_row, 0), btnchg);

		connect(btnchg, &QPushButton::clicked, [=]
			{
				cur_indexRow_bx = cur_row;
				QWidget* widgetForChg = new QWidget();
				widgetForChg->setWindowModality(Qt::ApplicationModal);
				widgetForChg->setAttribute(Qt::WA_DeleteOnClose);
				widgetForChg->setWindowIcon(QPixmap("Resources/logo.png"));
				widgetForChg->setWindowTitle("保险信息修改");
				widgetForChg->setFixedSize(800, 300);
				widgetForChg->setStyleSheet(QString::fromUtf8("QWidget{background:url(Resources/bkgrdfreject.png) center no-repeat;}"));
				widgetForChg->show();

				QLabel* labelName = new QLabel(widgetForChg);
				labelName->setGeometry(QRect(275, 40, 250, 50));
				labelName->setFont(QFont("楷体", 16));
				labelName->setText(QString("%1").arg(qItemModel_bx->item(cur_row, 2)->text()));
				labelName->setAlignment(Qt::AlignCenter);
				labelName->show();

				QLabel* labelsb = new QLabel(widgetForChg);
				labelsb->setGeometry(QRect(90, 120, 60, 50));
				labelsb->setFont(QFont("宋体", 11));
				labelsb->setText("社保");
				labelsb->show();

				cbxsb = new QComboBox(widgetForChg);
				cbxsb->setGeometry(QRect(150, 120, 120, 50));
				cbxsb->setFont(QFont("宋体", 11));
				cbxsb->setFocusPolicy(Qt::NoFocus);
				cbxsb->addItem("");
				cbxsb->addItem("统一交");
				cbxsb->addItem("自己交");
				cbxsb->setStyleSheet(QString::fromUtf8(" QComboBox {"
					"      border: 1px solid grey;"
					"      border-radius: 20px;"
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
					"      border-top-right-radius: 3px;"
					"      border-bottom-right-radius: 3px;"
					"  }"
				));
				cbxsb->show();

				QLabel* labelgsx = new QLabel(widgetForChg);
				labelgsx->setGeometry(QRect(280, 120, 90, 50));
				labelgsx->setFont(QFont("宋体", 11));
				labelgsx->setText("工伤险");
				labelgsx->show();

				cbxgsx = new QComboBox(widgetForChg);
				cbxgsx->setGeometry(QRect(370, 120, 120, 50));
				cbxgsx->setFont(QFont("宋体", 11));
				cbxgsx->setFocusPolicy(Qt::NoFocus);
				cbxgsx->addItem("");
				cbxgsx->addItem("已交");
				cbxgsx->setStyleSheet(QString::fromUtf8(" QComboBox {"
					"      border: 1px solid grey;"
					"      border-radius: 20px;"
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
					"      border-top-right-radius: 3px;"
					"      border-bottom-right-radius: 3px;"
					"  }"
				));
				cbxgsx->show();

				QLabel* labelywx = new QLabel(widgetForChg);
				labelywx->setGeometry(QRect(500, 120, 90, 50));
				labelywx->setFont(QFont("宋体", 11));
				labelywx->setText("意外险");
				labelywx->show();

				cbxywx = new QComboBox(widgetForChg);
				cbxywx->setGeometry(QRect(590, 120, 120, 50));
				cbxywx->setFont(QFont("宋体", 11));
				cbxywx->setFocusPolicy(Qt::NoFocus);
				cbxywx->addItem("");
				cbxywx->addItem("已交");
				cbxywx->setStyleSheet(QString::fromUtf8(" QComboBox {"
					"      border: 1px solid grey;"
					"      border-radius: 20px;"
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
					"      border-top-right-radius: 3px;"
					"      border-bottom-right-radius: 3px;"
					"  }"
				));
				cbxywx->show();

				cbxsb->setCurrentText(qItemModel_bx->item(cur_row, 5)->text());
				cbxgsx->setCurrentText(qItemModel_bx->item(cur_row, 6)->text());
				cbxywx->setCurrentText(qItemModel_bx->item(cur_row, 7)->text());

				QPushButton* temp_btnY = new QPushButton(widgetForChg);
				temp_btnY->setGeometry(QRect(265, 200, 120, 50));
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
				temp_btnY->setText("保存");
				temp_btnY->show();

				QPushButton* temp_btnN = new QPushButton(widgetForChg);
				temp_btnN->setGeometry(QRect(415, 200, 120, 50));
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
				temp_btnN->setText("退出");
				temp_btnN->show();

				connect(temp_btnN, &QPushButton::clicked, [=] {widgetForChg->close(); });
				connect(temp_btnY, &QPushButton::clicked, [=]
					{
						QVector<QString> v_saveInsuranceInfo;
						v_saveInsuranceInfo.push_back(labelName->text());
						v_saveInsuranceInfo.push_back(cbxsb->currentText());
						v_saveInsuranceInfo.push_back(cbxgsx->currentText());
						v_saveInsuranceInfo.push_back(cbxywx->currentText());
						emit sig_saveInsuranceInfo(v_saveInsuranceInfo);
					}
				);
			}
		);

		v_btnchg.push_back(btnchg);
		++cur_row;
	}

}

void WidgetYGGL::receiveTotalData(QVector<QVector<QString>> totalData) {

	if (totalData.isEmpty()) return;

	int sum[23];
	for (int i = 0; i < 23; ++i) {
		sum[i] = 0;
	}

	int cur_row = 0;
	for (auto it = totalData.cbegin(); it != totalData.cend(); ++it) {
		for (int i = 0; i < 23; ++i) {
			qItemModel_total->item(cur_row, i + 1)->setText(it->at(i));
			sum[i] += it->at(i).toInt();
		}
		++cur_row;
	}
	for (int i = 0; i < 23; ++i) {
		qItemModel_total->item(cur_row, i + 1)->setText(QString::number(sum[i]));
	}
}

void WidgetYGGL::receiveMenuTotalData(QVector<QString> totalData_oneCol, int col) {

	if (totalData_oneCol.isEmpty()) return;

	int sum = 0;
	int cur_row = 0;
	for (auto it = totalData_oneCol.cbegin(); it != totalData_oneCol.cend(); ++it) {
		qItemModel_total->item(cur_row, col)->setText(*it);
		sum += (*it).toInt();
		++cur_row;
	}
	qItemModel_total->item(cur_row, col)->setText(QString::number(sum));

}

bool WidgetYGGL::checkTime(const QString& time, QChar format) {

	QString y = "";
	QString m = "";
	QString d = "";
	int count = 0;
	for (auto c : time) {
		if ((!c.isDigit()) && (c != format)) return false;
		if (c == format) ++count;
		if (count == 0 && c != format) y += c;
		if (count == 1 && c != format) m += c;
		if (count == 2 && c != format) d += c;
	}
	if (count != 2 || y.length() != 4 || (m.length() != 1 && m.length() != 2) || (d.length() != 1 && d.length() != 2)
		|| m.toInt() < 1 || m.toInt() > 12 || d.toInt() < 1 || d.toInt() > DateClass::getDayMaxOfMonth(y.toInt(), m.toInt())) return false;

	return true;

}