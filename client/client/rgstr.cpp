#include "rgstr.h"

Rgstr::Rgstr(QWidget* parent)
	: QWidget(parent)
{
	this->setObjectName(QString::fromUtf8("Rgstr"));
	QMetaObject::connectSlotsByName(this);
	this->resize(960, 650);
	this->setWindowTitle(QString::fromUtf8("���û�ע��"));
	this->setMinimumSize(QSize(960, 650));
	this->setMaximumSize(QSize(960, 650));
	this->setWindowIcon(QPixmap("Resources/logo.png"));

	labelTtl = new QLabel(this);
	labelTtl->setObjectName(QString::fromUtf8("labelTtl"));
	labelTtl->setGeometry(QRect(335, 12, 360, 120));
	labelTtl->setFont(QFont("����", 22));
	labelTtl->setText(QString::fromUtf8("���û�ע��"));

	labelUser = new QLabel(this);
	labelUser->setObjectName(QString::fromUtf8("labelUser"));
	labelUser->setGeometry(QRect(160, 130, 165, 30));
	labelUser->setFont(QFont("����", 12));
	labelUser->setText(QString::fromUtf8("���û�����"));
	labelUser->setAlignment(Qt::Alignment::enum_type::AlignRight);

	labelRlnm = new QLabel(this);
	labelRlnm->setObjectName(QString::fromUtf8("labelRlnm"));
	labelRlnm->setGeometry(QRect(160, 190, 165, 30));
	labelRlnm->setFont(QFont("����", 12));
	labelRlnm->setText(QString::fromUtf8("��ʵ������"));
	labelRlnm->setAlignment(Qt::Alignment::enum_type::AlignRight);

	labelGhp = new QLabel(this);
	labelGhp->setObjectName(QString::fromUtf8("labelGhp"));
	labelGhp->setGeometry(QRect(160, 250, 165, 30));
	labelGhp->setFont(QFont("����", 12));
	labelGhp->setText(QString::fromUtf8("�����ƣ�"));
	labelGhp->setAlignment(Qt::Alignment::enum_type::AlignRight);

	labelZcxm = new QLabel(this);
	labelZcxm->setObjectName(QString::fromUtf8("labelZcxm"));
	labelZcxm->setGeometry(QRect(160, 310, 165, 30));
	labelZcxm->setFont(QFont("����", 12));
	labelZcxm->setText(QString::fromUtf8("ע����Ŀ��"));
	labelZcxm->setAlignment(Qt::Alignment::enum_type::AlignRight);

	labelSzbm = new QLabel(this);
	labelSzbm->setObjectName(QString::fromUtf8("labelSzbm"));
	labelSzbm->setGeometry(QRect(160, 370, 165, 30));
	labelSzbm->setFont(QFont("����", 12));
	labelSzbm->setText(QString::fromUtf8("���ڲ��ţ�"));
	labelSzbm->setAlignment(Qt::Alignment::enum_type::AlignRight);

	labelPwd = new QLabel(this);
	labelPwd->setObjectName(QString::fromUtf8("labelPwd"));
	labelPwd->setGeometry(QRect(160, 430, 165, 30));
	labelPwd->setFont(QFont("����", 12));
	labelPwd->setText(QString::fromUtf8("�������룺"));
	labelPwd->setAlignment(Qt::Alignment::enum_type::AlignRight);

	labelPwd_2 = new QLabel(this);
	labelPwd_2->setObjectName(QString::fromUtf8("labelPwd_2"));
	labelPwd_2->setGeometry(QRect(160, 490, 165, 30));
	labelPwd_2->setFont(QFont("����", 12));
	labelPwd_2->setText(QString::fromUtf8("ȷ�����룺"));
	labelPwd_2->setAlignment(Qt::Alignment::enum_type::AlignRight);

	label_user = new QLabel(this);
	label_user->setObjectName(QString::fromUtf8("label_user"));
	label_user->setGeometry(QRect(335, 165, 360, 20));
	label_user->setFont(QFont("����", 5));
	label_user->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

	label_rlnm = new QLabel(this);
	label_rlnm->setObjectName(QString::fromUtf8("label_rlnm"));
	label_rlnm->setGeometry(QRect(335, 225, 360, 20));
	label_rlnm->setFont(QFont("����", 5));
	label_rlnm->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

	label_ghp = new QLabel(this);
	label_ghp->setObjectName(QString::fromUtf8("label_ghp"));
	label_ghp->setGeometry(QRect(335, 285, 360, 20));
	label_ghp->setFont(QFont("����", 5));
	label_ghp->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

	label_zcxm = new QLabel(this);
	label_zcxm->setObjectName(QString::fromUtf8("label_zcxm"));
	label_zcxm->setGeometry(QRect(335, 345, 360, 20));
	label_zcxm->setFont(QFont("����", 5));
	label_zcxm->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

	label_szbm = new QLabel(this);
	label_szbm->setObjectName(QString::fromUtf8("label_szbm"));
	label_szbm->setGeometry(QRect(335, 405, 360, 20));
	label_szbm->setFont(QFont("����", 5));
	label_szbm->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

	label_pwd = new QLabel(this);
	label_pwd->setObjectName(QString::fromUtf8("label_pwd"));
	label_pwd->setGeometry(QRect(335, 465, 360, 20));
	label_pwd->setFont(QFont("����", 5));
	label_pwd->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

	label_pwd_2 = new QLabel(this);
	label_pwd_2->setObjectName(QString::fromUtf8("label_pwd_2"));
	label_pwd_2->setGeometry(QRect(335, 525, 360, 20));
	label_pwd_2->setFont(QFont("����", 5));
	label_pwd_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

	lineUser = new MyLineEdit(this);
	lineUser->setObjectName(QString::fromUtf8("lineUser"));
	lineUser->setGeometry(QRect(335, 125, 360, 40));
	lineUser->setFont(QFont("Arial"));

	lineRlnm = new QLineEdit(this);
	lineRlnm->setObjectName(QString::fromUtf8("lineRlnm"));
	lineRlnm->setGeometry(QRect(335, 185, 360, 40));
	lineRlnm->setFont(QFont("Arial"));

	lineGhp = new QLineEdit(this);
	lineGhp->setObjectName(QString::fromUtf8("lineGhp"));
	lineGhp->setGeometry(QRect(335, 245, 360, 40));
	lineGhp->setFont(QFont("Arial"));

	linePwd = new MyLineEdit(this);
	linePwd->setObjectName(QString::fromUtf8("linePwd"));
	linePwd->setGeometry(QRect(335, 425, 360, 40));
	linePwd->setFont(QFont("Arial"));
	linePwd->setEchoMode(QLineEdit::Password);

	linePwd_2 = new MyLineEdit(this);
	linePwd_2->setObjectName(QString::fromUtf8("linePwd_2"));
	linePwd_2->setGeometry(QRect(335, 485, 360, 40));
	linePwd_2->setFont(QFont("Arial"));
	linePwd_2->setEchoMode(QLineEdit::Password);

	cbxZcxm = new QComboBox(this);
	cbxZcxm->setObjectName(QString::fromUtf8("cbxZcxm"));
	cbxZcxm->addItem(QString::fromUtf8(""));
	cbxZcxm->addItem(QString::fromUtf8("��˾�ܲ�"));
	cbxZcxm->addItem(QString::fromUtf8("�Ķ���Ԣ"));
	cbxZcxm->addItem(QString::fromUtf8("������԰"));
	cbxZcxm->addItem(QString::fromUtf8("���һ��"));
	cbxZcxm->addItem(QString::fromUtf8("����С��"));
	cbxZcxm->addItem(QString::fromUtf8("�������ʴ�"));
	cbxZcxm->addItem(QString::fromUtf8("�κ軪ͥ"));
	cbxZcxm->addItem(QString::fromUtf8("���ⶼ��"));
	cbxZcxm->addItem(QString::fromUtf8("����֤ȯ"));
	cbxZcxm->addItem(QString::fromUtf8("���Ϲ�Ԣ"));
	cbxZcxm->addItem(QString::fromUtf8("�Ļ����ξ�"));
	cbxZcxm->addItem(QString::fromUtf8("���ù��ʱ���"));
	cbxZcxm->setGeometry(QRect(335, 305, 360, 40));
	cbxZcxm->setFont(QFont("Arial"));
	cbxZcxm->setFocusPolicy(Qt::NoFocus);
	cbxZcxm->setCurrentIndex(0);
	cbxZcxm->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

	cbxSzbm = new QComboBox(this);
	cbxSzbm->addItem(QString::fromUtf8(""));
	cbxSzbm->addItem(QString::fromUtf8("��Ŀ����"));
	cbxSzbm->addItem(QString::fromUtf8("������"));
	cbxSzbm->addItem(QString::fromUtf8("�ͷ���"));
	cbxSzbm->addItem(QString::fromUtf8("���̲�"));
	cbxSzbm->addItem(QString::fromUtf8("����ά����"));
	cbxSzbm->addItem(QString::fromUtf8("�������̻�"));
	cbxSzbm->addItem(QString::fromUtf8("����������"));
	cbxSzbm->addItem(QString::fromUtf8("���ڲ�"));
	cbxSzbm->setObjectName(QString::fromUtf8("cbxSzbm"));
	cbxSzbm->setGeometry(QRect(335, 365, 360, 40));
	cbxSzbm->setFont(QFont("Arial"));
	cbxSzbm->setFocusPolicy(Qt::NoFocus);
	cbxSzbm->setCurrentIndex(0);
	cbxSzbm->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

	btnIdtfy = new QPushButton(this);
	btnIdtfy->setObjectName(QString::fromUtf8("btnIdtfy"));
	btnIdtfy->setGeometry(QRect(700, 130, 200, 70));
	btnIdtfy->setFont(QFont("����", 11));
	btnIdtfy->setCursor(QCursor(Qt::PointingHandCursor));
	btnIdtfy->setFlat(true);
	btnIdtfy->setText(QString::fromUtf8("�����֤"));

	btnRgst = new QPushButton(this);
	btnRgst->setObjectName(QString::fromUtf8("btnRgst"));
	btnRgst->setGeometry(QRect(330, 550, 360, 60));
	btnRgst->setFont(QFont("����", 20));
	btnRgst->setCursor(QCursor(Qt::PointingHandCursor));
	btnRgst->setText(QString::fromUtf8("ע��"));

	btnRtn = new QPushButton(this);
	btnRtn->setObjectName(QString::fromUtf8("btnRtn"));
	btnRtn->setGeometry(QRect(60, 545, 60, 60));
	btnRtn->setCursor(QCursor(Qt::PointingHandCursor));
	QIcon icon;
	icon.addFile(QString::fromUtf8("Resources/123.png"), QSize(), QIcon::Normal, QIcon::Off);
	btnRtn->setIcon(icon);
	btnRtn->setIconSize(QSize(50, 50));
	btnRtn->setFlat(true);
	//����ui

	connect(btnRtn, &QAbstractButton::clicked, [=]
		{
			emit sig_return();
			//��ʼ�������
			lineGhp->clear();
			linePwd->clear();
			linePwd_2->clear();
			cbxSzbm->setCurrentIndex(0);
			cbxZcxm->setCurrentIndex(0);
			lineRlnm->clear();
			lineUser->clear();
			//��ʼ����ʾ��
			label_ghp->clear();
			label_pwd->clear();
			label_pwd_2->clear();
			label_rlnm->clear();
			label_szbm->clear();
			label_user->clear();
			label_zcxm->clear();
		});

	connect(btnRgst, &QAbstractButton::clicked, [=]
		{
			if (lineUser->text().isEmpty())		            label_user->setText("*�û�������Ϊ�գ�");
			else								            label_user->clear();
			if (lineRlnm->text().isEmpty())                 label_rlnm->setText("*��ʵ��������Ϊ�գ�");
			else                                            label_rlnm->clear();
			if (lineGhp->text().isEmpty())		            label_ghp->setText("*���ƺŲ���Ϊ�գ�");
			else								            label_ghp->clear();
			if (cbxZcxm->currentText().isEmpty())	        label_zcxm->setText("*ע����Ŀ����Ϊ�գ�");
			else                                            label_zcxm->clear();
			if (cbxSzbm->currentText().isEmpty())	        label_szbm->setText("*���ڲ��Ų���Ϊ�գ�");
			else                                            label_szbm->clear();
			if (linePwd->text().isEmpty())                  label_pwd->setText("*���벻��Ϊ�գ�");
			else									        label_pwd->clear();
			if (linePwd_2->text().isEmpty())                label_pwd_2->setText("*���벻��Ϊ�գ�");
			else if (linePwd->text() != linePwd_2->text())  label_pwd_2->setText("*�����������벻ƥ�䣡");
			else 	                                        label_pwd_2->clear();

			if (lineUser->text().isEmpty() || lineRlnm->text().isEmpty() || lineGhp->text().isEmpty()
				|| cbxZcxm->currentText().isEmpty() || cbxSzbm->currentText().isEmpty()
				|| linePwd->text().isEmpty() || linePwd_2->text().isEmpty()
				|| linePwd->text() != linePwd_2->text())
				return;

			struct RegisterInfo registerInfo;
			registerInfo.newUserName = lineUser->text();
			registerInfo.realName = lineRlnm->text();
			registerInfo.ghp = lineGhp->text();
			registerInfo.zcxm = cbxZcxm->currentText();
			registerInfo.szbm = cbxSzbm->currentText();
			registerInfo.password = linePwd->text();

			//md5����
			char md5_str[MD5_STR_LEN + 1];
			std::string str = registerInfo.password.toStdString();
			Compute_string_md5((unsigned char*)str.c_str(), strlen(str.c_str()), md5_str);
			registerInfo.encrypted_password = md5_str;

			emit sig_register(registerInfo);
		});

}

Rgstr::~Rgstr()
{
}

void Rgstr::onsig_forUserNameExist() {

	lineUser->clear();
	linePwd->clear();
	linePwd_2->clear();
	label_user->setText("*�û�������Ϊ�գ�");
	label_pwd->setText("*���벻��Ϊ�գ�");
	label_pwd_2->setText("*���벻��Ϊ�գ�");

}

void Rgstr::onsig_forSOrFCreated() {

	//��ʼ�������
	lineGhp->clear();
	linePwd->clear();
	linePwd_2->clear();
	cbxSzbm->setCurrentIndex(0);
	cbxZcxm->setCurrentIndex(0);
	lineRlnm->clear();
	lineUser->clear();
	//��ʼ����ʾ��
	label_ghp->clear();
	label_pwd->clear();
	label_pwd_2->clear();
	label_rlnm->clear();
	label_szbm->clear();
	label_user->clear();
	label_zcxm->clear();

}

