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
	tabWidget->setFont(QFont("�����п�����", 14));

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
	qStringList << "�ɹ����뵥��" << "״̬" << "�鿴";
	tableView = new QTableView(widgetLeft);
	tableView->setObjectName(QString::fromUtf8("tableView"));
	qItemModel_2 = new QStandardItemModel(tab_2);
	tableView->setGeometry(QRect(5, 525, 350, 420));
	tableView->setFocusPolicy(Qt::FocusPolicy::NoFocus);
	qItemModel_2->setHorizontalHeaderLabels(qStringList);
	tableView->horizontalHeader()->setFont(QFont("����", 7));
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
	tableView->verticalScrollBar()->setStyleSheet("QScrollBar:vertical{"//��ֱ��������  
		"width:15px;"          //���
		"background:#FFFFFF;"  //����ɫ  
		"padding-top:5px;"     //��Ԥ��λ�ã��������ϼ�ͷ��  
		"padding-bottom:5px;"  //��Ԥ��λ�ã��������¼�ͷ��  
		"padding-left:1px;"    //��Ԥ��λ�ã����ۣ�  
		"padding-right:1px;"   //��Ԥ��λ�ã����ۣ�  
		"border-left:0px;}"    //��ָ���  
		"QScrollBar::handle:vertical{"//������ʽ  
		"background:url(Resources/aurora1.png) center no-repeat;"  //������ɫ  
		"border-radius:6px;"   //�߽�Բ��  
		"min-height:80px;}"    //������С�߶�  
		"QScrollBar::handle:vertical:hover{"//��괥��������ʽ  
		"background:url(Resources/aurora2.png) center no-repeat;}" //������ɫ  
		"QScrollBar::add-line:vertical{"//���¼�ͷ��ʽ  
		"background:url() center no-repeat;}"
		"QScrollBar::sub-line:vertical{"//���ϼ�ͷ��ʽ  
		"background:url() center no-repeat;}");

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
	QStandardItemModel* qItemModel = NULL;
	qItemModel = qobject_cast<QStandardItemModel*>(comboBoxPro->model());
	for (int i = 0; i < 12; ++i) {
		qItemModel->item(i)->setBackground(QBrush(QColor(211, 211, 255)));
	}

	btnCreate = new QPushButton(widgetLeft);
	btnCreate->setObjectName(QString::fromUtf8("btnCreate"));
	btnCreate->setGeometry(QRect(0, 150, 360, 65));
	btnCreate->setFont(QFont("����", 12));
	btnCreate->setText("�½��ɹ����뵥  ");
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
	btnImport->setFont(QFont("����", 12));
	btnImport->setText("����Excel�ļ�   ");
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
	btnClose->setFont(QFont("����", 12));
	btnClose->setText("�رյ�ǰ�ɹ���  ");
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
	labelSearch->setFont(QFont("����", 13));
	labelSearch->setAlignment(Qt::AlignCenter);
	labelSearch->setText("��ʷ����¼");

	labelTime = new QLabel(widgetLeft);
	labelTime->setObjectName(QString::fromUtf8("labelTime"));
	labelTime->setGeometry(QRect(18, 430, 65, 30));
	labelTime->setFont(QFont("����", 10));
	labelTime->setText("ʱ�䣺");

	labelYear = new QLabel(widgetLeft);
	labelYear->setObjectName(QString::fromUtf8("labelYear"));
	labelYear->setGeometry(QRect(142, 430, 25, 30));
	labelYear->setFont(QFont("Arial", 9));
	labelYear->setText(QString("��"));
	labelYear->setStyleSheet("background-color: rgb(255, 255, 255);");

	lineYear = new QLineEdit(widgetLeft);
	lineYear->setObjectName(QString::fromUtf8("lineYear"));
	lineYear->setGeometry(QRect(85, 430, 57, 30));
	lineYear->setFont(QFont("Arial", 9));
	lineYear->setText(QString("%1").arg(date.year));
	lineYear->setValidator(new QIntValidator(0, 9999, this));
	lineYear->setStyleSheet("background-color: rgb(255, 255, 255);border: 0px;");

	comboBoxMonth = new QComboBox(widgetLeft);
	comboBoxMonth->addItem(QString("01��"));
	comboBoxMonth->addItem(QString("02��"));
	comboBoxMonth->addItem(QString("03��"));
	comboBoxMonth->addItem(QString("04��"));
	comboBoxMonth->addItem(QString("05��"));
	comboBoxMonth->addItem(QString("06��"));
	comboBoxMonth->addItem(QString("07��"));
	comboBoxMonth->addItem(QString("08��"));
	comboBoxMonth->addItem(QString("09��"));
	comboBoxMonth->addItem(QString("10��"));
	comboBoxMonth->addItem(QString("11��"));
	comboBoxMonth->addItem(QString("12��"));
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
		"image: url(Resources/����.png);"
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
	labelState->setFont(QFont("����", 10));
	labelState->setText("״̬��");

	comboBoxState = new QComboBox(widgetLeft);
	comboBoxState->addItem(QString("ȫ��"));
	comboBoxState->addItem(QString("�����"));
	comboBoxState->addItem(QString("һ��"));
	comboBoxState->addItem(QString("����"));
	comboBoxState->addItem(QString("����"));
	comboBoxState->addItem(QString("�Ѳɹ�"));
	comboBoxState->addItem(QString("������"));
	comboBoxState->addItem(QString("����"));
	comboBoxState->setObjectName(QString::fromUtf8("comboBoxState"));
	comboBoxState->setGeometry(QRect(85, 480, 120, 30));
	comboBoxState->setFont(QFont("����", 10));
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
		"image: url(Resources/����.png);"
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
	btnSearch->setFont(QFont("����", 9));
	btnSearch->setStyleSheet(
		"QPushButton{background-color: rgba( 0, 0, 0, 0);border: 0px;border-radius: 20px;}"
		"QPushButton:hover{background-color: rgba(255, 255, 255, 153);}"
		"QPushButton:pressed{background-color: rgba(255, 255, 255, 77);}"
	);
	QIcon icon1;
	icon1.addFile(QString::fromUtf8("Resources/search.png"), QSize(), QIcon::Normal, QIcon::Off);
	btnSearch->setIcon(icon1);
	btnSearch->setIconSize(QSize(25, 25));
	btnSearch->setText("��ѯ");

	labelTitle = new QLabel(widgetRight);
	labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
	labelTitle->setGeometry(QRect(479, 15, 600, 60));
	QFont font2;
	font2.setFamily(QString::fromUtf8("����"));
	font2.setPointSize(18);
	font2.setBold(true);
	labelTitle->setFont(font2);
	labelTitle->setAlignment(Qt::AlignCenter);
	labelTitle->setText("XXXX���ʲɹ����뵥");

	labelPro_2 = new QLabel(widgetRight);
	labelPro_2->setObjectName(QString::fromUtf8("labelPro_2"));
	labelPro_2->setGeometry(QRect(40, 105, 80, 30));
	labelPro_2->setFont(QFont("����", 12));
	labelPro_2->setText("��Ŀ��");

	linePro = new QLineEdit(widgetRight);
	linePro->setObjectName(QString::fromUtf8("linePro"));
	linePro->setGeometry(QRect(120, 100, 230, 40));
	linePro->setFont(QFont("����", 11));
	linePro->setStyleSheet("background-color: rgb(255, 255, 255);");

	labelApplyDate = new QLabel(widgetRight);
	labelApplyDate->setObjectName(QString::fromUtf8("labelApplyDate"));
	labelApplyDate->setGeometry(QRect(380, 105, 145, 30));
	labelApplyDate->setFont(QFont("����", 12));
	labelApplyDate->setText("�������ڣ�");

	calendarWidget = new QCalendarWidget(widgetRight);
	calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
	calendarWidget->setEnabled(true);
	calendarWidget->setFont(QFont("����", 8));
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
	labelApplyPerson->setFont(QFont("����", 12));
	labelApplyPerson->setText("�����ˣ�");

	lineApplyPerson = new QLineEdit(widgetRight);
	lineApplyPerson->setObjectName(QString::fromUtf8("lineApplyPerson"));
	lineApplyPerson->setGeometry(QRect(830, 100, 140, 40));
	lineApplyPerson->setFont(QFont("����", 11));
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
	btnSave->setFont(QFont("����", 11));
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
	btnSave->setText("����");

	btnSubmit = new QPushButton(widgetRight);
	btnSubmit->setObjectName(QString::fromUtf8("btnSubmit"));
	btnSubmit->setGeometry(QRect(1410, 100, 85, 40));
	btnSubmit->setFont(QFont("����", 11));
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
	btnSubmit->setText("�ύ");
	btnSubmit->setEnabled(false);

	btnPrint = new QPushButton(widgetRight);
	btnPrint->setObjectName(QString::fromUtf8("btnPrint"));
	btnPrint->setGeometry(QRect(1300, 100, 85, 40));
	btnPrint->setFont(QFont("����", 11));
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
	btnPrint->setText("��ӡ");

	labelRemind = new QLabel(widgetRight);
	labelRemind->setObjectName(QString::fromUtf8("labelRemind"));
	labelRemind->setGeometry(QRect(10, 150, 1530, 662));
	labelRemind->setFont(QFont("����", 30));
	labelRemind->setAlignment(Qt::Alignment::enum_type::AlignHCenter | Qt::Alignment::enum_type::AlignVCenter);
	labelRemind->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255); color: rgb(0, 200, 0);"));
	labelRemind->setFrameShape(QFrame::Shape::Box);
	labelRemind->setText("�½���򿪲ɹ����뵥��");

	label[0] = new QLabel(widgetRight);
	label[0]->setObjectName(QString::fromUtf8("labelxmjl"));
	label[0]->setGeometry(QRect(100, 870, 140, 30));
	label[0]->setFont(QFont("����", 12));
	label[0]->setText("��Ŀ����");

	label[1] = new QLabel(widgetRight);
	label[1]->setObjectName(QString::fromUtf8("labelzhb"));
	label[1]->setGeometry(QRect(600, 870, 110, 30));
	label[1]->setFont(QFont("����", 12));
	label[1]->setText("�ۺϲ���");

	label[2] = new QLabel(widgetRight);
	label[2]->setObjectName(QString::fromUtf8("labelzjb"));
	label[2]->setGeometry(QRect(1100, 870, 110, 30));
	label[2]->setFont(QFont("����", 12));
	label[2]->setText("�ܾ��죺");

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
		btnPass[index]->setFont(QFont("����", 9));
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
		btnPass[index]->setText("ͨ��");
		btnPass[index]->hide();

		btnReject[index] = new QPushButton(widgetRight);
		btnReject[index]->setObjectName(QString::fromUtf8("btnReject%1").arg(QString::number(index)));
		btnReject[index]->setGeometry(QRect(myLabel[index]->geometry().x() + myLabel[index]->geometry().width() + 110, 885, 80, 30));
		btnReject[index]->setFont(QFont("����", 9));
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
		btnReject[index]->setText("����");
		btnReject[index]->hide();

		btnUndo[index] = new QPushButton(widgetRight);
		btnUndo[index]->setObjectName(QString::fromUtf8("btnUndo%1").arg(QString::number(index)));
		btnUndo[index]->setGeometry(QRect(lineEditPwd[index]->geometry().x() - 30, 900, 55, 30));
		btnUndo[index]->setFont(QFont("����", 9));
		btnUndo[index]->setStyleSheet(
			"QPushButton{background-color: rgba( 0, 0, 0, 0);border: 0px;border-radius: 15px;color: rgb(170, 170, 255);}"
			"QPushButton:hover{background-color: rgba(255, 255, 255, 102);}"
			"QPushButton:pressed{background-color: rgba(255, 255, 255, 204);}"
		);
		btnUndo[index]->setText("����");
		btnUndo[index]->hide();

		labelName[index] = new QLabel(widgetRight);
		labelName[index]->setGeometry(QRect(lineEditPwd[index]->geometry().x() - 5, 865, 110, 30));
		labelName[index]->setFont(QFont("����", 12));
		labelName[index]->hide();

		connect(btnPass[index], &QAbstractButton::clicked, [=]
			{
				if (lineEditPwd[index]->text() != userInfo.user_password)
					return;
				QMessageBox box(QMessageBox::Question, "��ʾ", "ȷ��Ҫͨ����");
				box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
				box.setButtonText(QMessageBox::Ok, QString("ȷ ��"));
				box.setButtonText(QMessageBox::Cancel, QString("ȡ ��"));
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
				widgetForBtnReject->setWindowTitle("����");
				widgetForBtnReject->setFixedSize(1600, 962);
				widgetForBtnReject->setStyleSheet(QString::fromUtf8("QWidget{background:url(Resources/bkgrdfreject.png) center no-repeat;}"));
				widgetForBtnReject->show();

				QLabel* temp_label = new QLabel(widgetForBtnReject);
				temp_label->setGeometry(QRect(60, 70, 800, 70));
				temp_label->setFont(QFont("����", 18));
				temp_label->setText("�������������д�����������");
				temp_label->setStyleSheet("color: rgb(128, 0, 0);background-color: rgba(255, 255, 255, 0);");
				temp_label->show();

				QTableWidget* temp_table = new QTableWidget(widgetForBtnReject);
				temp_table->setGeometry(QRect(135, 150, 1330, 662));
				temp_table->setFont(QFont("����", 7));
				temp_table->setStyleSheet(
					"QTableWidget{background:url();background-color: rgb(224, 224, 224); gridline-color: rgb(0, 0, 0);}"
					"QTableWidget::item::selected{background:url();}"
				);
				temp_table->verticalScrollBar()->setStyleSheet("QScrollBar:vertical{"//��ֱ��������  
					"width:15px;"          //���
					"background:#FFFFFF;"  //����ɫ  
					"padding-top:2px;"     //��Ԥ��λ�ã��������ϼ�ͷ��  
					"padding-bottom:2px;"  //��Ԥ��λ�ã��������¼�ͷ��  
					"padding-left:1px;"    //��Ԥ��λ�ã����ۣ�  
					"padding-right:1px;"   //��Ԥ��λ�ã����ۣ�  
					"border-left:0px;}"    //��ָ���  
					"QScrollBar::handle:vertical{"//������ʽ  
					"background:url(Resources/aurora1_long.png) center no-repeat;"  //������ɫ  
					"border-radius:6px;"   //�߽�Բ��  
					"min-height:80px;}"    //������С�߶�  
					"QScrollBar::handle:vertical:hover{"//��괥��������ʽ  
					"background:url(Resources/aurora2_long.png) center no-repeat;}" //������ɫ  
					"QScrollBar::add-line:vertical{"//���¼�ͷ��ʽ  
					"background:url() center no-repeat;}"
					"QScrollBar::sub-line:vertical{"//���ϼ�ͷ��ʽ  
					"background:url() center no-repeat;}");
				temp_table->setFrameShape(QFrame::Shape::Box);
				temp_table->setEditTriggers(QAbstractItemView::CurrentChanged);//��д
				temp_table->setFocusPolicy(Qt::FocusPolicy::NoFocus);
				temp_table->verticalHeader()->hide();
				temp_table->horizontalHeader()->setFixedHeight(47);
				temp_table->setRowCount(v_v_forOpen_data.size());
				temp_table->setColumnCount(7);
				temp_table->setHorizontalHeaderLabels(QStringList() << "���" << "��Ʒ����" << "����" << "��λ"
					<< "�ͺŹ��" << "��;" << "�������");
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
				temp_btnY->setFont(QFont("����", 12));
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
				temp_btnY->setText("�ύ");
				temp_btnY->show();
				QPushButton* temp_btnN = new QPushButton(widgetForBtnReject);
				temp_btnN->setGeometry(QRect(1425, 852, 120, 50));
				temp_btnN->setFont(QFont("����", 12));
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
				temp_btnN->setText("ȡ��");
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
							QMessageBox box(QMessageBox::Information, "��ʾ", "�����������Ϊ�գ�");
							box.setStandardButtons(QMessageBox::Ok);
							box.setButtonText(QMessageBox::Ok, QString("ȷ ��"));
							box.setWindowIcon(QPixmap("Resources/logo.png"));
							int button = box.exec();
							return;
						}
						QMessageBox box(QMessageBox::Question, "��ʾ", "ȷ��Ҫ�ύ��");
						box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
						box.setButtonText(QMessageBox::Ok, QString("ȷ ��"));
						box.setButtonText(QMessageBox::Cancel, QString("ȡ ��"));
						box.setWindowIcon(QPixmap("Resources/logo.png"));
						int button = box.exec();
						if (button != QMessageBox::Ok)
							return;
						flagForCheck[index] = 2;
						state = State::����;
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
				QMessageBox box(QMessageBox::Question, "��ʾ", "ȷ��Ҫ������");
				box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
				box.setButtonText(QMessageBox::Ok, QString("ȷ ��"));
				box.setButtonText(QMessageBox::Cancel, QString("ȡ ��"));
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
				if (pro == userInfo.xm && state == State::�����) btnSubmit->setEnabled(true);
				else btnSubmit->setEnabled(false);
				for (int i = 0; i < tableWidget->rowCount(); ++i) {
					tableWidget->item(i, 6)->setText("");
				}
				emit sig_sendStateData(currentID, state, index, "", QVector<QString>());
			});
	}

	tabWidget->setAttribute(Qt::WA_StyledBackground);
	tabWidget->addTab(tab, QString("  �ɹ�  "));
	tabWidget->addTab(tab_2, QString("  ���  "));
	tabWidget->addTab(tab_3, QString("  ����  "));
	tabWidget->addTab(tab_4, QString("  �̴�  "));
	tabWidget->addTab(tab_5, QString("  ����  "));
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
	state = State::�����;
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
			QMessageBox box(QMessageBox::Information, "��ʾ", "�����½���򿪲ɹ����뵥��");
			box.setStandardButtons(QMessageBox::Ok);
			box.setButtonText(QMessageBox::Ok, QString("ȷ ��"));
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
	state = State::�����;
	lineApplyPerson->setText(userInfo.user_real_name);
	linePro->setText(userInfo.xm);
	dateEditApplyDate->setDate(QDate::currentDate());
	currentID = "";
	for (int i = 0; i < qItemModel_2->rowCount(); ++i) {
		qItemModel_2->item(i, 0)->setFont(QFont("����", 7));
		qItemModel_2->item(i, 1)->setFont(QFont("����", 7));
		v_btnOpen[i]->setFont(QFont("����", 7));
	}

	if (tableWidget == NULL) {
		tableWidget = new MyTableWidget(widgetRight);
		tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
		tableWidget->setGeometry(QRect(10, 150, 1530, 662));
		tableWidget->setFont(QFont("����", 7));
		tableWidget->setStyleSheet("background-color: rgb(255, 255, 255); gridline-color: rgb(0, 0, 0);");
		tableWidget->verticalScrollBar()->setStyleSheet("QScrollBar:vertical{"//��ֱ��������  
			"width:15px;"          //���
			"background:#FFFFFF;"  //����ɫ  
			"padding-top:2px;"     //��Ԥ��λ�ã��������ϼ�ͷ��  
			"padding-bottom:2px;"  //��Ԥ��λ�ã��������¼�ͷ��  
			"padding-left:1px;"    //��Ԥ��λ�ã����ۣ�  
			"padding-right:1px;"   //��Ԥ��λ�ã����ۣ�  
			"border-left:0px;}"    //��ָ���  
			"QScrollBar::handle:vertical{"//������ʽ  
			"background:url(Resources/aurora1_long.png) center no-repeat;"  //������ɫ  
			"border-radius:6px;"   //�߽�Բ��  
			"min-height:80px;}"    //������С�߶�  
			"QScrollBar::handle:vertical:hover{"//��괥��������ʽ  
			"background:url(Resources/aurora2_long.png) center no-repeat;}" //������ɫ  
			"QScrollBar::add-line:vertical{"//���¼�ͷ��ʽ  
			"background:url() center no-repeat;}"
			"QScrollBar::sub-line:vertical{"//���ϼ�ͷ��ʽ  
			"background:url() center no-repeat;}");
		tableWidget->setFrameShape(QFrame::Shape::Box);
		tableWidget->setEditTriggers(QAbstractItemView::CurrentChanged);//��д
		tableWidget->setFocusPolicy(Qt::FocusPolicy::NoFocus);
		tableWidget->verticalHeader()->hide();
		tableWidget->horizontalHeader()->setFixedHeight(47);
		tableWidget->setRowCount(13);
		tableWidget->setColumnCount(9);
		tableWidget->setHorizontalHeaderLabels(QStringList() << "���" << "��Ʒ����" << "����" << "��λ"
			<< "�ͺŹ��" << "��;" << "�������" << "���(Ԫ)" << "�ɹ�����");
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
		btnAddRow->setFont(QFont("����", 8));
		btnAddRow->setText("����һ��");
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

	QString strFile = QFileDialog::getOpenFileName(tableWidget, "ѡ���ļ�", "./", "�ı��ļ�(*.xls;*.xlsx;)");
	if (strFile.isEmpty())
		return;
	Book* book = NULL;
	if (strFile.endsWith("xls", Qt::CaseInsensitive))//�ж��Ƿ���.xls�ļ��������ִ�Сд
	{
		book = xlCreateBook(); // xlCreateBook() for xls
	}
	else if (strFile.endsWith("xlsx", Qt::CaseInsensitive))//�ж��Ƿ���.xlsx�ļ��������ִ�Сд
	{
		book = xlCreateXMLBook(); // xlCreateXMLBook() for xlsx
	}
	const wchar_t* wstr = reinterpret_cast<const wchar_t*>(strFile.utf16());//QStringתwchar_t
	bool f = book->load(wstr);//����excel�ļ�

	onBtnCreateClicked();

	CellType ct;
	if (book) {
		Sheet* sheet = book->getSheet(0);//��1
		//������
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
				ct = sheet->cellType(i, j);//��Ԫ�����������

				if (ct == CELLTYPE_STRING)
					tableWidget->setItem(i - 1, j, new QTableWidgetItem(QString::fromWCharArray(sheet->readStr(i, j))));//wchar_tתQString
				else if (ct == CELLTYPE_NUMBER)
					tableWidget->setItem(i - 1, j, new QTableWidgetItem(QString::number((int)sheet->readNum(i, j))));
			}
		}
		delete book;
		book = NULL;
	}
	else {
		QMessageBox box(QMessageBox::Information, "��ʾ", "�ļ���ʧ�ܣ�");
		box.setStandardButtons(QMessageBox::Ok);
		box.setButtonText(QMessageBox::Ok, QString("ȷ ��"));
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
	state = State::�����;
	lineApplyPerson->setText(userInfo.user_real_name);
	linePro->setText(userInfo.xm);
	dateEditApplyDate->setDate(QDate::currentDate());
	currentID = "";
	for (int i = 0; i < qItemModel_2->rowCount(); ++i) {
		qItemModel_2->item(i, 0)->setFont(QFont("����", 7));
		qItemModel_2->item(i, 1)->setFont(QFont("����", 7));
		v_btnOpen[i]->setFont(QFont("����", 7));
	}
	btnSubmit->setEnabled(false);
	btnDelete->hide();

}

void WidgetWZGL::onBtnSaveClicked() {

	if (tableIsOpen == false) {
		emit sig_tableIsNotOpen();
		return;
	}

	QString fileName = QFileDialog::getSaveFileName(tableWidget, "����",
		QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation), "Excel �ļ�(*.xlsx *.xls)");
	if (fileName.isEmpty())
		return;

	QXlsx::Document xlsx;

	QXlsx::Format cell_format;
	cell_format.setFontSize(11);
	cell_format.setPatternBackgroundColor(QColor(182, 182, 182));
	cell_format.setBorderStyle(QXlsx::Format::BorderThin);
	cell_format.setHorizontalAlignment(QXlsx::Format::AlignHCenter);
	cell_format.setVerticalAlignment(QXlsx::Format::AlignVCenter);

	xlsx.write(1, 1, "���", cell_format);
	xlsx.write(1, 2, "��Ʒ����", cell_format);
	xlsx.write(1, 3, "����", cell_format);
	xlsx.write(1, 4, "��λ", cell_format);
	xlsx.write(1, 5, "�ͺŹ��", cell_format);
	xlsx.write(1, 6, "��;", cell_format);
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
	QMessageBox box(QMessageBox::Question, "��ʾ", " �ļ������ɹ����Ƿ�򿪣�");
	box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	box.setButtonText(QMessageBox::Ok, QString("ȷ ��"));
	box.setButtonText(QMessageBox::Cancel, QString("ȡ ��"));
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
		QMessageBox box(QMessageBox::Information, "��ʾ", "��Ŀ������������");
		box.setStandardButtons(QMessageBox::Ok);
		box.setButtonText(QMessageBox::Ok, QString("ȷ ��"));
		box.setWindowIcon(QPixmap("Resources/logo.png"));
		int button = box.exec();
		linePro->setText(userInfo.xm);
		return;
	}

	if (lineApplyPerson->text() != userInfo.user_real_name) {
		QMessageBox box(QMessageBox::Information, "��ʾ", "������������������");
		box.setStandardButtons(QMessageBox::Ok);
		box.setButtonText(QMessageBox::Ok, QString("ȷ ��"));
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
		QMessageBox box(QMessageBox::Information, "��ʾ", "�����ύ�ձ�");
		box.setStandardButtons(QMessageBox::Ok);
		box.setButtonText(QMessageBox::Ok, QString("ȷ ��"));
		box.setWindowIcon(QPixmap("Resources/logo.png"));
		int button = box.exec();
		return;
	}

	int f = 0;
	for (int i = 0; i <= curRow; ++i) {
		if (tableWidget->item(i, 1)->text() == "" || tableWidget->item(i, 2)->text() == ""
			|| tableWidget->item(i, 3)->text() == "" || tableWidget->item(i, 4)->text() == "") {
			f = 1;
			if (tableWidget->item(i, 1)->text() == "") tableWidget->item(i, 1)->setText("������");
			if (tableWidget->item(i, 2)->text() == "") tableWidget->item(i, 2)->setText("������");
			if (tableWidget->item(i, 3)->text() == "") tableWidget->item(i, 3)->setText("������");
			if (tableWidget->item(i, 4)->text() == "") tableWidget->item(i, 4)->setText("������");
		}
	}
	if (f == 1) {
		QMessageBox box(QMessageBox::Information, "��ʾ", "��Ѳɹ����뵥��д������");
		box.setStandardButtons(QMessageBox::Ok);
		box.setButtonText(QMessageBox::Ok, QString("ȷ ��"));
		box.setWindowIcon(QPixmap("Resources/logo.png"));
		int button = box.exec();
		return;
	}

	for (int i = 0; i <= curRow; ++i) {
		for (auto c : tableWidget->item(i, 2)->text()) {
			if (!c.isDigit()) {
				QMessageBox box(QMessageBox::Information, "��ʾ", "������������д���֣�");
				box.setStandardButtons(QMessageBox::Ok);
				box.setButtonText(QMessageBox::Ok, QString("ȷ ��"));
				box.setWindowIcon(QPixmap("Resources/logo.png"));
				int button = box.exec();
				return;
			}
		}
	}

	QMessageBox box(QMessageBox::Question, "��ʾ", "�ύ��������������ȷ��Ҫ�ύ��");
	box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	box.setButtonText(QMessageBox::Ok, QString("ȷ ��"));
	box.setButtonText(QMessageBox::Cancel, QString("ȡ ��"));
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
		v_tableDate.push_back(QString::number(State::�����));
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
	preview.setWindowTitle("��ӡԤ��");
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

	//����
	if (printer->orientation() == QPrinter::Landscape) {
		QString text = "�˱��֧�ֺ����ӡ^_^";
		painter.setFont(QFont("����", 60));
		painter.drawText(550, 2500, text);
	}

	//����
	if (printer->orientation() == QPrinter::Portrait) {
		int tatalPageCount = 0;
		if (tableWidget->rowCount() % 20 == 0) tatalPageCount = tableWidget->rowCount() / 20;
		else  tatalPageCount = tableWidget->rowCount() / 20 + 1;
		for (int page_index = 0; page_index < tatalPageCount; ++page_index) {
			painter.setPen(QColor(40, 40, 40));// ���û�����ɫ
			painter.drawPixmap(200, 100, QPixmap("Resources/logo.png"));
			QString text = "�㽭XXXX�������޹�˾                         "
				"                                 �ɹ�����ţ�WBWY-KF-2014-11";
			painter.setFont(QFont("����", 9));
			painter.drawText(440, 230, text);
			painter.drawLine(QPointF(0, 400), QPointF(5000, 400));	// ����ֱ��
			painter.setPen(QColor(0, 0, 0));
			text = "XXXX���ʲɹ����뵥";
			painter.setFont(QFont("����", 30));
			painter.drawText(1000, 800, text);
			painter.setFont(QFont("����", 18));
			text = QString("%1 %2    �����ˣ�%3").arg(linePro->text()).arg(dateEditApplyDate->text()).arg(lineApplyPerson->text());
			painter.drawText(100, 1200, text);
			QPixmap pixmap = tableWidget->grab(QRect(QPoint(0, 0), QSize(954, 48)));
			QRect rect = painter.viewport();
			QSize size = pixmap.size();
			size.scale(rect.size(), Qt::KeepAspectRatio);//���ֳ����
			painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
			painter.setWindow(pixmap.rect());
			painter.drawPixmap(0, 255, pixmap); //��ͼ
			int c = 0;
			for (int i = page_index * 20; i < (page_index + 1) * 20; ++i) {
				if (i > tableWidget->rowCount() - 1) break;
				QPixmap pixmap = tableWidget->grab(QRect(QPoint(0, 48), QSize(954, 48)));
				painter.drawPixmap(0, 303 + c * 48, pixmap);
				tableWidget->hideRow(i);
				++c;
			}
			painter.setFont(QFont("����", 3));
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
			tableWidget->item(i, j)->setFlags((Qt::ItemFlags)63); //63Ϊ��ʼ״̬
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
	font.setFamily("����");
	font.setPointSize(7);
	QFont font_temp;
	font_temp.setBold(true);
	font_temp.setFamily("����");
	font_temp.setPointSize(7);
	QFont font_temp_2;
	font_temp_2.setBold(true);
	font_temp_2.setFamily("����");
	font_temp_2.setPointSize(7);
	for (auto it = v_v_forPurchase.cbegin(); it != v_v_forPurchase.cend(); ++it) {

		item = new QStandardItem(QString("%1").arg((*it)[0]));
		qItemModel_2->setItem(num_row, 0, item);
		qItemModel_2->item(num_row, 0)->setFlags(item->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
		qItemModel_2->item(num_row, 0)->setFont(QFont("����", 7));
		qItemModel_2->item(num_row, 0)->setForeground(QBrush(QColor(0, 0, 0)));
		v_item.push_back(item);

		btnOpen = new QPushButton(this);
		btnOpen->setText("��");
		btnOpen->setCursor(Qt::CursorShape::PointingHandCursor);
		btnOpen->setFont(QFont("����", 7));
		tableView->setIndexWidget(qItemModel_2->index(num_row, 2), btnOpen);
		v_btnOpen.push_back(btnOpen);

		item = new QStandardItem();
		qItemModel_2->setItem(num_row, 1, item);
		switch ((*it)[1].toInt())
		{
		case State::�����:state = "�����"; setTableViewColor(btnOpen, num_row, 234, 234, 229, 255); break;
		case State::һ��:state = "һ��"; setTableViewColor(btnOpen, num_row, 251, 177, 17, 200); break;
		case State::����:state = "����"; setTableViewColor(btnOpen, num_row, 251, 177, 17, 200); break;
		case State::����:state = "����"; setTableViewColor(btnOpen, num_row, 255, 230, 0, 150); break;
		case State::�Ѳɹ�:state = "�Ѳɹ�"; setTableViewColor(btnOpen, num_row, 216, 215, 2, 200); break;
		case State::������:state = "������"; setTableViewColor(btnOpen, num_row, 112, 183, 72, 200); break;
		case State::����:state = "����"; setTableViewColor(btnOpen, num_row, 128, 0, 0, 150); break;
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
				if (pro != userInfo.xm || (qItemModel_2->item(num_row, 1)->text() != "�����"
					&& qItemModel_2->item(num_row, 1)->text() != "����")) btnSubmit->setEnabled(false);

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
			if (pro != userInfo.xm || (qItemModel_2->item(i, 1)->text() != "�����"
				&& qItemModel_2->item(i, 1)->text() != "����")) btnSubmit->setEnabled(false);
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

	if (qItemModel_2->item(currentRowIndex, 1)->text() == "�����") {
		this->state = State::�����;
	}
	if (qItemModel_2->item(currentRowIndex, 1)->text() == "һ��") {
		this->state = State::һ��;
		flagForCheck[0] = 2;
		btnUndo[0]->show();
		myLabel[0]->setPixmap(QPixmap("Resources/pass.png"));
		labelName[0]->setText(name_1); labelName[0]->show();
	}
	if (qItemModel_2->item(currentRowIndex, 1)->text() == "����") {
		this->state = State::����;
		flagForCheck[1] = 2;
		btnUndo[1]->show();
		myLabel[0]->setPixmap(QPixmap("Resources/pass.png"));
		myLabel[1]->setPixmap(QPixmap("Resources/pass.png"));
		labelName[0]->setText(name_1); labelName[0]->show();
		labelName[1]->setText(name_2); labelName[1]->show();
	}
	if (qItemModel_2->item(currentRowIndex, 1)->text() == "����") {
		this->state = State::����;
		flagForCheck[2] = 2;
		btnUndo[2]->show();
		myLabel[0]->setPixmap(QPixmap("Resources/pass.png"));
		myLabel[1]->setPixmap(QPixmap("Resources/pass.png"));
		myLabel[2]->setPixmap(QPixmap("Resources/pass.png"));
		labelName[0]->setText(name_1); labelName[0]->show();
		labelName[1]->setText(name_2); labelName[1]->show();
		labelName[2]->setText(name_3); labelName[2]->show();
	}
	if (qItemModel_2->item(currentRowIndex, 1)->text() == "�Ѳɹ�") {
		this->state = State::�Ѳɹ�;
		myLabel[0]->setPixmap(QPixmap("Resources/pass.png"));
		myLabel[1]->setPixmap(QPixmap("Resources/pass.png"));
		myLabel[2]->setPixmap(QPixmap("Resources/pass.png"));
		labelName[0]->setText(name_1); labelName[0]->show();
		labelName[1]->setText(name_2); labelName[1]->show();
		labelName[2]->setText(name_3); labelName[2]->show();
	}
	if (qItemModel_2->item(currentRowIndex, 1)->text() == "������") {
		this->state = State::������;
		myLabel[0]->setPixmap(QPixmap("Resources/pass.png"));
		myLabel[1]->setPixmap(QPixmap("Resources/pass.png"));
		myLabel[2]->setPixmap(QPixmap("Resources/pass.png"));
		labelName[0]->setText(name_1); labelName[0]->show();
		labelName[1]->setText(name_2); labelName[1]->show();
		labelName[2]->setText(name_3); labelName[2]->show();
	}
	if (qItemModel_2->item(currentRowIndex, 1)->text() == "����") {
		this->state = State::����;
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

	QMessageBox box(QMessageBox::Information, "��ʾ", "�ύ�ɹ���");
	box.setStandardButtons(QMessageBox::Ok);
	box.setButtonText(QMessageBox::Ok, QString("ȷ ��"));
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

	if (state != State::���� && state != State::�Ѳɹ�) return;
	if (index != 7 && index != 8) return;
	emit sig_CreateWCostAndDate();

}

void WidgetWZGL::onDoubleClicked(int row, int col) {

	if (state != State::���� && state != State::�Ѳɹ�) return;
	if (col != 7 && col != 8) return;
	emit sig_CreateWCostAndDate();

}

void WidgetWZGL::onsig_CreateWCostAndDate() {

	widgetForCostAndDate = new QWidget();
	widgetForCostAndDate->setWindowModality(Qt::ApplicationModal);
	widgetForCostAndDate->setAttribute(Qt::WA_DeleteOnClose);
	widgetForCostAndDate->setWindowIcon(QPixmap("Resources/logo.png"));
	widgetForCostAndDate->setWindowTitle("�ɹ��");
	widgetForCostAndDate->setFixedSize(1600, 962);
	widgetForCostAndDate->setStyleSheet(QString::fromUtf8("QWidget{background:url(Resources/bkgrdfreject.png) center no-repeat;}"));
	widgetForCostAndDate->show();

	QLabel* temp_label = new QLabel(widgetForCostAndDate);
	temp_label->setGeometry(QRect(550, 35, 1000, 100));
	temp_label->setFont(QFont("����", 30));
	temp_label->setText("�ɹ������");
	temp_label->setStyleSheet("color: rgb(0, 0, 0);background-color: rgba(255, 255, 255, 0);");
	temp_label->show();

	QTableWidget* temp_table = new QTableWidget(widgetForCostAndDate);
	temp_table->setGeometry(QRect(135, 154, 1330, 662));
	temp_table->setFont(QFont("����", 8));
	temp_table->setStyleSheet(
		"QTableWidget{background:url();background-color: rgb(224, 224, 224); gridline-color: rgb(0, 0, 0);}"
		"QTableWidget::item::selected{background:url();}"
	);
	temp_table->verticalScrollBar()->setStyleSheet("QScrollBar:vertical{"//��ֱ��������  
		"width:15px;"          //���
		"background:#FFFFFF;"  //����ɫ  
		"padding-top:2px;"     //��Ԥ��λ�ã��������ϼ�ͷ��  
		"padding-bottom:2px;"  //��Ԥ��λ�ã��������¼�ͷ��  
		"padding-left:1px;"    //��Ԥ��λ�ã����ۣ�  
		"padding-right:1px;"   //��Ԥ��λ�ã����ۣ�  
		"border-left:0px;}"    //��ָ���  
		"QScrollBar::handle:vertical{"//������ʽ  
		"background:url(Resources/aurora1_long.png) center no-repeat;"  //������ɫ  
		"border-radius:6px;"   //�߽�Բ��  
		"min-height:80px;}"    //������С�߶�  
		"QScrollBar::handle:vertical:hover{"//��괥��������ʽ  
		"background:url(Resources/aurora2_long.png) center no-repeat;}" //������ɫ  
		"QScrollBar::add-line:vertical{"//���¼�ͷ��ʽ  
		"background:url() center no-repeat;}"
		"QScrollBar::sub-line:vertical{"//���ϼ�ͷ��ʽ  
		"background:url() center no-repeat;}");
	temp_table->setFrameShape(QFrame::Shape::Box);
	temp_table->setEditTriggers(QAbstractItemView::DoubleClicked);//�������¿��Դ���˫���¼���
	temp_table->setFocusPolicy(Qt::FocusPolicy::NoFocus);
	temp_table->verticalHeader()->hide();
	temp_table->horizontalHeader()->setFixedHeight(47);
	temp_table->setRowCount(v_v_forOpen_data.size());
	temp_table->setColumnCount(9);
	temp_table->setHorizontalHeaderLabels(QStringList() << "���" << "��Ʒ����" << "����" << "��λ"
		<< "�ͺŹ��" << "���(Ԫ)" << "�ɹ�����");
	QTableWidgetItem* item_ = new QTableWidgetItem("�ύ");
	item_->setFont(QFont("����", 11));
	temp_table->setHorizontalHeaderItem(7, item_);
	item_ = new QTableWidgetItem("����");
	item_->setFont(QFont("����", 11));
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
				//�ж��Ƿ�Ϊ��
				if (temp_table->item(i, 5)->text().isEmpty() || temp_table->item(i, 6)->text().isEmpty()) {
					QMessageBox box(QMessageBox::Information, "��ʾ", "���Ͳɹ����ڲ���Ϊ�գ�");
					box.setStandardButtons(QMessageBox::Ok);
					box.setButtonText(QMessageBox::Ok, QString("ȷ ��"));
					box.setWindowIcon(QPixmap("Resources/logo.png"));
					int button = box.exec();
					return;
				}
				//�ж��Ƿ�Ϊ���
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
					QMessageBox box(QMessageBox::Information, "��ʾ", "��������ȷ�Ľ���ʽ!");
					box.setStandardButtons(QMessageBox::Ok);
					box.setButtonText(QMessageBox::Ok, QString("ȷ ��"));
					box.setWindowIcon(QPixmap("Resources/logo.png"));
					int button = box.exec();
					return;
				}

				//��������
				double a = temp_table->item(i, 5)->text().toDouble();
				a = (a * 100 + 0.5);
				int b = a;
				double c = b;
				c = c / 100;
				temp_table->item(i, 5)->setText(QString::number(c));

				//С��������λ����0
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
					this->state = State::�Ѳɹ�;
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
				QMessageBox box(QMessageBox::Question, "��ʾ", "ȷ��Ҫ������");
				box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
				box.setButtonText(QMessageBox::Ok, QString("ȷ ��"));
				box.setButtonText(QMessageBox::Cancel, QString("ȡ ��"));
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
				if (this->state == State::�Ѳɹ�) {
					this->state = State::����;
					v_forCostAndDate.push_back(QString::number(State::����));
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
	temp_btnY->setFont(QFont("����", 20));
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
	temp_btnY->setText("ȷ��");
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

	if (state != State::����� && state != State::����) {
		QString c_state = "";
		switch (state)
		{
		case State::һ��:c_state = "һ��"; break;
		case State::����:c_state = "����"; break;
		case State::����:case State::�Ѳɹ�:case State::������:c_state = "����"; break;
		default:break;
		}
		QString temp = QString("�˲ɹ�����ͨ��%1������ɾ��!").arg(c_state);
		QMessageBox box(QMessageBox::Information, "��ʾ", temp);
		box.setStandardButtons(QMessageBox::Ok);
		box.setButtonText(QMessageBox::Ok, QString("ȷ ��"));
		box.setWindowIcon(QPixmap("Resources/logo.png"));
		int button = box.exec();
		return;
	}

	QMessageBox box(QMessageBox::Question, "��ʾ", "ɾ���󽫲��ɻָ���ȷ��Ҫɾ����");
	box.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	box.setButtonText(QMessageBox::Ok, QString("ȷ ��"));
	box.setButtonText(QMessageBox::Cancel, QString("ȡ ��"));
	box.setWindowIcon(QPixmap("Resources/logo.png"));
	int button = box.exec();
	if (button != QMessageBox::Ok)
		return;

	emit sig_forDelete(currentID);

}

void WidgetWZGL::onsig_forSuccessfulDelete() {

	QMessageBox box(QMessageBox::Information, "��ʾ", "ɾ���ɹ���");
	box.setStandardButtons(QMessageBox::Ok);
	box.setButtonText(QMessageBox::Ok, QString("ȷ ��"));
	box.setWindowIcon(QPixmap("Resources/logo.png"));
	int button = box.exec();
	emit sig_sendPurchaseData(comboBoxPro->currentText(), lineYear->text().toInt(),
		comboBoxMonth->currentText().mid(0, 2).toInt(), comboBoxState->currentIndex());
	onBtnCloseClicked();

}