#include "login.h"

Login::Login(QWidget* parent)
	: QWidget(parent)
{
	this->setObjectName(QString::fromUtf8("Login"));
	this->resize(600, 450);
	this->setMinimumSize(QSize(600, 450));
	this->setMaximumSize(QSize(600, 450));
	this->setWindowIcon(QPixmap("Resources/logo.png"));
	QPalette palette;
	palette.setBrush(this->backgroundRole(), QBrush(QPixmap("Resources/background.jpg")));
	this->setPalette(palette);
	this->setWindowFlags(Qt::WindowFlags::enum_type::FramelessWindowHint | windowFlags());

	//圆角
	QBitmap bmp(this->size());
	bmp.fill();
	QPainter p(&bmp);
	p.setRenderHint(QPainter::Antialiasing); // 反锯齿;
	p.setPen(Qt::transparent);
	p.setBrush(Qt::black);
	p.drawRoundedRect(bmp.rect(), 8, 8);
	setMask(bmp);

	//渐变出现
	animation = new QPropertyAnimation(this, "windowOpacity");
	animation->setDuration(400);
	animation->setStartValue(0);
	animation->setEndValue(1);
	animation->start();

	QLabel* labelForLogo = new QLabel(this);
	labelForLogo->setGeometry(QRect(20, 20, 50, 50));
	labelForLogo->setStyleSheet("QLabel{image:url(Resources/logo.png);border:none;}");

	lineUser = new MyLineEdit(this);
	lineUser->setObjectName(QString::fromUtf8("lineUser"));
	lineUser->setGeometry(QRect(150, 135, 300, 45));
	lineUser->setFont(QFont("Arial"));
	lineUser->setPlaceholderText(QString::fromUtf8("用户名"));
	lineUser->setStyleSheet(QString::fromUtf8("QLineEdit{ border: 1px solid black; border-radius: 5px;}"));
	QAction* actionUser = new QAction(lineUser);
	actionUser->setIcon(QIcon("Resources/user.png"));
	lineUser->addAction(actionUser, QLineEdit::LeadingPosition);

	linePwd = new MyLineEdit(this);
	linePwd->setObjectName(QString::fromUtf8("linePwd"));
	linePwd->setGeometry(QRect(150, 205, 300, 45));
	linePwd->setFont(QFont("Arial"));
	linePwd->setMaxLength(11);
	linePwd->setEchoMode(QLineEdit::Password);
	linePwd->setPlaceholderText(QString::fromUtf8("密码"));
	linePwd->setStyleSheet(QString::fromUtf8("QLineEdit{ border: 1px solid black; border-radius: 5px;}"));
	QAction* actionPwd = new QAction(linePwd);
	actionPwd->setIcon(QIcon("Resources/password.png"));
	linePwd->addAction(actionPwd, QLineEdit::LeadingPosition);
	QAction* actionEye = new QAction(linePwd);
	actionEye->setIcon(QIcon("Resources/eye-invisible.png"));
	linePwd->addAction(actionEye, QLineEdit::TrailingPosition);
	connect(actionEye, &QAction::triggered, [=]
		{
			if (linePwd->echoMode() == QLineEdit::Password) {
				linePwd->setEchoMode(QLineEdit::Normal);
				actionEye->setIcon(QIcon("Resources/eye.png"));
			}
			else if (linePwd->echoMode() == QLineEdit::Normal) {
				linePwd->setEchoMode(QLineEdit::Password);
				actionEye->setIcon(QIcon("Resources/eye-invisible.png"));
			}
		});

	btnLgn = new QPushButton(this);
	btnLgn->setObjectName(QString::fromUtf8("btnLgn"));
	btnLgn->setGeometry(QRect(170, 335, 260, 50));
	btnLgn->setFont(QFont("宋体", 14));
	btnLgn->setStyleSheet(QString::fromUtf8(
		"QPushButton{				              "
		"  background-color: rgb(0, 170, 255);	  "
		"  color: rgb(255, 255, 255);	          "
		"  border-style: outset;				  "
		"  border-width: 2px;					  "
		"  border-radius: 10px;				      "
		"  border-color: grey;				      "
		"  padding: 6px;						  "
		"}										  "
		"QPushButton:pressed{		              "
		"	border-style: inset;				  "
		"}										  "
		"QPushButton:hover{                       "
		"   background-color: rgb(6, 197, 255);   "
		"}                                        "
	));
	btnLgn->setText(QString::fromUtf8("登录"));

	btnRgst = new QPushButton(this);
	btnRgst->setObjectName(QString::fromUtf8("btnRgst"));
	btnRgst->setGeometry(QRect(190, 290, 100, 35));
	btnRgst->setFont(QFont("宋体", 8));
	btnRgst->setStyleSheet("QPushButton{background-color: rgba( 0, 0, 0, 0);color: rgb(120, 120, 120);border: 0px;}"
		"QPushButton:hover{color: rgb(80, 80, 80);}"
		"QPushButton:pressed{color: rgb(100, 180, 180);}");
	btnRgst->setCursor(QCursor(Qt::PointingHandCursor));
	btnRgst->setText(QString::fromUtf8("注册账号"));

	btnChg = new QPushButton(this);
	btnChg->setObjectName(QString::fromUtf8("btnChg"));
	btnChg->setGeometry(QRect(310, 290, 100, 35));
	btnChg->setFont(QFont("宋体", 8));
	btnChg->setStyleSheet("QPushButton{background-color: rgba( 0, 0, 0, 0);color: rgb(120, 120, 120);border: 0px;}"
		"QPushButton:hover{color: rgb(80, 80, 80);}"
		"QPushButton:pressed{color: rgb(100, 180, 180);}");
	btnChg->setCursor(QCursor(Qt::PointingHandCursor));
	btnChg->setText(QString::fromUtf8("修改密码"));

	btnMinimize = new QPushButton(this);
	btnMinimize->setObjectName(QString::fromUtf8("btnMinimize"));
	btnMinimize->setGeometry(QRect(500, 0, 50, 50));
	btnMinimize->setIcon(QIcon("Resources/最小化.png"));
	btnMinimize->setStyleSheet("QPushButton{background-color: rgba( 0, 0, 0, 0);border: 0px;}"
		"QPushButton:hover{background-color: rgba(255, 255, 255, 128);}"
		"QPushButton:pressed{background-color: rgba(0, 0, 0, 102);}");
	connect(btnMinimize, &QAbstractButton::clicked, [=]
		{
			animation = new QPropertyAnimation(this, "windowOpacity");
			animation->setDuration(100);
			animation->setStartValue(1);
			animation->setEndValue(0);
			animation->start();
			connect(animation, &QPropertyAnimation::finished, [=] {this->showMinimized(); this->setWindowOpacity(1); });
		});

	btnExit = new QPushButton(this);
	btnExit->setObjectName(QString::fromUtf8("btnExit"));
	btnExit->setGeometry(QRect(550, 0, 50, 50));
	btnExit->setIcon(QIcon("Resources/关闭.png"));
	btnExit->setToolTip(tr("关闭"));
	btnExit->setStyleSheet("QPushButton{background-color: rgba( 0, 0, 0, 0);border: 0px;}"
		"QPushButton:hover{background-color: rgb(255, 84, 41);}"
		"QPushButton:pressed{background-color: rgb(202, 64, 37);}");
	connect(btnExit, &QAbstractButton::clicked, [=]
		{
			animation = new QPropertyAnimation(this, "windowOpacity");
			animation->setDuration(100);
			animation->setStartValue(1);
			animation->setEndValue(0);
			animation->start();
			connect(animation, &QPropertyAnimation::finished, [=] {this->close(); });
		});

	//以上ui

	rgstr = NULL;
	chgPwd = NULL;
	rgstr = new Rgstr();
	chgPwd = new ChgPwd();

	connect(btnRgst, &QAbstractButton::clicked, [=] {this->hide(); lineUser->clear(); linePwd->clear(); rgstr->show(); });
	connect(btnChg, &QAbstractButton::clicked, [=] {this->hide();  lineUser->clear(); linePwd->clear(); chgPwd->show(); });
	connect(rgstr, &Rgstr::sig_return, [=] {rgstr->close(); this->show(); });
	connect(chgPwd, &ChgPwd::sig_return, [=] {chgPwd->close(); this->show(); });

	connect(rgstr, &Rgstr::sig_register, this, &Login::onsig_register);
	connect(chgPwd, &ChgPwd::sig_change, this, &Login::onsig_change);
	connect(btnLgn, &QAbstractButton::clicked, this, &Login::onBtnLgnClicked);

}

Login::~Login()
{
	delete rgstr;
	delete chgPwd;
	rgstr = NULL;
	chgPwd = NULL;
}

void Login::onsig_register(RegisterInfo registerInfo) { emit sig_register(registerInfo); }
void Login::onsig_change(ChgPwdInfo chgPwdInfo) { emit sig_change(chgPwdInfo); }

void Login::onBtnLgnClicked() {

	if (lineUser->text().isEmpty() || linePwd->text().isEmpty()) {
		QMessageBox box(QMessageBox::Information, "提示", "用户名与密码不匹配！");
		box.setStandardButtons(QMessageBox::Ok);
		box.setButtonText(QMessageBox::Ok, QString("确 定"));
		box.setWindowIcon(QPixmap("Resources/logo.png"));
		int button = box.exec();
		linePwd->clear();
		return;
	}
	struct UsernmPwd usernmPwd;
	usernmPwd.username = lineUser->text();

	//md5加密
	char md5_str[MD5_STR_LEN + 1];
	std::string str = linePwd->text().toStdString();
	linePwd->clear();
	Compute_string_md5((unsigned char*)str.c_str(), strlen(str.c_str()), md5_str);
	usernmPwd.encrypted_password = md5_str;
	emit sig_login(usernmPwd);

}

void Login::keyPressEvent(QKeyEvent* event) {

	//上：Key_Up，下：Key_Down，回车：Key_Return
	qDebug("0x%x", event->key());
	switch (event->key())
	{
	case Qt::Key_Return:onBtnLgnClicked(); break;
	case Qt::Key_Up:lineUser->setFocus(); break;
	case Qt::Key_Down:linePwd->setFocus(); break;
	default:QWidget::keyPressEvent(event); break;
	}

}

void Login::mouseMoveEvent(QMouseEvent* event)
{
	//防止鼠标点在按钮上时窗体乱跑
	if (m_point == QPoint())
		return;

	if (m_bPressed && this->cursor().shape() == Qt::ArrowCursor)
		move(event->pos() - m_point + pos());
}

void Login::mouseReleaseEvent(QMouseEvent* event)
{
	Q_UNUSED(event);
	m_bPressed = false;
}

void Login::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		m_bPressed = true;
		m_point = event->pos();
	}
}


