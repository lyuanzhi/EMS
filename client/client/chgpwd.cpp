#include "chgpwd.h"

ChgPwd::ChgPwd(QWidget* parent)
	: QWidget(parent)
{
	this->setObjectName(QString::fromUtf8("ChgPwd"));
	QMetaObject::connectSlotsByName(this);
	this->resize(960, 600);
	this->setWindowTitle(QString::fromUtf8("修改密码"));
	this->setMinimumSize(QSize(960, 600));
	this->setMaximumSize(QSize(960, 600));
	this->setWindowIcon(QPixmap("Resources/logo.png"));

	labelTtl = new QLabel(this);
	labelTtl->setObjectName(QString::fromUtf8("labelTtl"));
	labelTtl->setGeometry(QRect(370, 20, 360, 120));
	labelTtl->setFont(QFont("宋体", 22));
	labelTtl->setText(QString::fromUtf8("修改密码"));

	labelUser = new QLabel(this);
	labelUser->setObjectName(QString::fromUtf8("labelUser"));
	labelUser->setGeometry(QRect(190, 160, 200, 30));
	labelUser->setFont(QFont("宋体", 12));
	labelUser->setText(QString::fromUtf8("用户名："));
	labelUser->setAlignment(Qt::Alignment::enum_type::AlignRight);

	labelOldPwd = new QLabel(this);
	labelOldPwd->setObjectName(QString::fromUtf8("labelOldPwd"));
	labelOldPwd->setGeometry(QRect(190, 220, 200, 30));
	labelOldPwd->setFont(QFont("宋体", 12));
	labelOldPwd->setText(QString::fromUtf8("原密码："));
	labelOldPwd->setAlignment(Qt::Alignment::enum_type::AlignRight);

	labelGhp = new QLabel(this);
	labelGhp->setObjectName(QString::fromUtf8("labelGhp"));
	labelGhp->setGeometry(QRect(190, 280, 200, 30));
	labelGhp->setFont(QFont("宋体", 12));
	labelGhp->setText(QString::fromUtf8("工号牌："));
	labelGhp->setAlignment(Qt::Alignment::enum_type::AlignRight);

	labelNewPwd = new QLabel(this);
	labelNewPwd->setObjectName(QString::fromUtf8("labelNewPwd"));
	labelNewPwd->setGeometry(QRect(190, 340, 200, 30));
	labelNewPwd->setFont(QFont("宋体", 12));
	labelNewPwd->setText(QString::fromUtf8("输入新密码："));
	labelNewPwd->setAlignment(Qt::Alignment::enum_type::AlignRight);

	labelNewPwd_2 = new QLabel(this);
	labelNewPwd_2->setObjectName(QString::fromUtf8("labelNewPwd_2"));
	labelNewPwd_2->setGeometry(QRect(190, 400, 200, 30));
	labelNewPwd_2->setFont(QFont("宋体", 12));
	labelNewPwd_2->setText(QString::fromUtf8("确认新密码："));
	labelNewPwd_2->setAlignment(Qt::Alignment::enum_type::AlignRight);

	label_user = new QLabel(this);
	label_user->setObjectName(QString::fromUtf8("label_user"));
	label_user->setGeometry(QRect(395, 195, 360, 20));
	label_user->setFont(QFont("宋体", 5));
	label_user->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

	label_old_pwd = new QLabel(this);
	label_old_pwd->setObjectName(QString::fromUtf8("label_old_pwd"));
	label_old_pwd->setGeometry(QRect(395, 255, 360, 20));
	label_old_pwd->setFont(QFont("宋体", 5));
	label_old_pwd->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

	label_ghp = new QLabel(this);
	label_ghp->setObjectName(QString::fromUtf8("label_ghp"));
	label_ghp->setGeometry(QRect(395, 315, 360, 20));
	label_ghp->setFont(QFont("宋体", 5));
	label_ghp->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

	label_new_pwd = new QLabel(this);
	label_new_pwd->setObjectName(QString::fromUtf8("label_new_pwd"));
	label_new_pwd->setGeometry(QRect(395, 375, 360, 20));
	label_new_pwd->setFont(QFont("宋体", 5));
	label_new_pwd->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

	label_new_pwd_2 = new QLabel(this);
	label_new_pwd_2->setObjectName(QString::fromUtf8("label_new_pwd_2"));
	label_new_pwd_2->setGeometry(QRect(395, 435, 360, 20));
	label_new_pwd_2->setFont(QFont("宋体", 5));
	label_new_pwd_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

	lineUser = new MyLineEdit(this);
	lineUser->setObjectName(QString::fromUtf8("lineUser"));
	lineUser->setGeometry(QRect(395, 155, 360, 40));
	lineUser->setFont(QFont("Arial"));

	lineOldPwd = new MyLineEdit(this);
	lineOldPwd->setObjectName(QString::fromUtf8("lineOldPwd"));
	lineOldPwd->setGeometry(QRect(395, 215, 360, 40));
	lineOldPwd->setFont(QFont("Arial"));
	lineOldPwd->setEchoMode(QLineEdit::Password);

	lineGhp = new QLineEdit(this);
	lineGhp->setObjectName(QString::fromUtf8("lineGhp"));
	lineGhp->setGeometry(QRect(395, 275, 360, 40));
	lineGhp->setFont(QFont("Arial"));

	lineNewPwd = new MyLineEdit(this);
	lineNewPwd->setObjectName(QString::fromUtf8("lineNewPwd"));
	lineNewPwd->setGeometry(QRect(395, 335, 360, 40));
	lineNewPwd->setFont(QFont("Arial"));
	lineNewPwd->setEchoMode(QLineEdit::Password);

	lineNewPwd_2 = new MyLineEdit(this);
	lineNewPwd_2->setObjectName(QString::fromUtf8("lineNewPwd_2"));
	lineNewPwd_2->setGeometry(QRect(395, 395, 360, 40));
	lineNewPwd_2->setFont(QFont("Arial"));
	lineNewPwd_2->setEchoMode(QLineEdit::Password);

	btnChg = new QPushButton(this);
	btnChg->setObjectName(QString::fromUtf8("btnChg"));
	btnChg->setGeometry(QRect(320, 490, 360, 60));
	btnChg->setFont(QFont("宋体", 20));
	btnChg->setCursor(QCursor(Qt::PointingHandCursor));
	btnChg->setText(QString::fromUtf8("修改"));

	btnRtn = new QPushButton(this);
	btnRtn->setObjectName(QString::fromUtf8("btnRtn"));
	btnRtn->setGeometry(QRect(30, 510, 60, 60));
	btnRtn->setCursor(QCursor(Qt::PointingHandCursor));
	QIcon icon;
	icon.addFile(QString::fromUtf8("Resources/123.png"), QSize(), QIcon::Normal, QIcon::Off);
	btnRtn->setIcon(icon);
	btnRtn->setIconSize(QSize(50, 50));
	btnRtn->setFlat(true);
	//以上ui

	connect(btnRtn, &QAbstractButton::clicked, [=]
		{
			emit sig_return();
			//初始化输入框
			lineUser->clear();
			lineOldPwd->clear();
			lineGhp->clear();
			lineNewPwd->clear();
			lineNewPwd_2->clear();
			//初始化提示框
			label_user->clear();
			label_old_pwd->clear();
			label_ghp->clear();
			label_new_pwd->clear();
			label_new_pwd_2->clear();
		});

	connect(btnChg, &QAbstractButton::clicked, [=]
		{
			if (lineUser->text().isEmpty())	                        label_user->setText("*用户名不可为空！");
			else                                                    label_user->clear();
			if (lineOldPwd->text().isEmpty())                       label_old_pwd->setText("*原密码不可为空！");
			else	                                                label_old_pwd->clear();
			if (lineGhp->text().isEmpty())         	                label_ghp->setText("*工牌号不可为空！");
			else	                                                label_ghp->clear();
			if (lineNewPwd->text().isEmpty())	                    label_new_pwd->setText("*新密码不可为空！");
			else	                                                label_new_pwd->clear();
			if (lineNewPwd_2->text().isEmpty())                     label_new_pwd_2->setText("*新密码不可为空！");
			else if (lineNewPwd->text() != lineNewPwd_2->text())	label_new_pwd_2->setText("*两次密码输入不匹配！");
			else                                                 	label_new_pwd_2->clear();

			if (lineUser->text().isEmpty() || lineOldPwd->text().isEmpty() || lineGhp->text().isEmpty()
				|| lineNewPwd->text().isEmpty() || lineNewPwd_2->text().isEmpty()
				|| lineNewPwd->text() != lineNewPwd_2->text())
				return;

			struct ChgPwdInfo chgPwdInfo;
			chgPwdInfo.UserName = lineUser->text();
			chgPwdInfo.ghp = lineGhp->text();
			chgPwdInfo.newPassword = lineNewPwd->text();

			//md5加密 oldPassword
			char md5_str_1[MD5_STR_LEN + 1];
			std::string str1 = lineOldPwd->text().toStdString();
			Compute_string_md5((unsigned char*)str1.c_str(), strlen(str1.c_str()), md5_str_1);
			chgPwdInfo.encrypted_oldPassword = md5_str_1;

			//md5加密 newPassword
			char md5_str_2[MD5_STR_LEN + 1];
			std::string str2 = chgPwdInfo.newPassword.toStdString();
			Compute_string_md5((unsigned char*)str2.c_str(), strlen(str2.c_str()), md5_str_2);
			chgPwdInfo.encrypted_newPassword = md5_str_2;

			emit sig_change(chgPwdInfo);
		});

}

ChgPwd::~ChgPwd()
{
}

void ChgPwd::onsig_forWrongOrSuccess() {

	lineUser->clear();
	lineOldPwd->clear();
	lineGhp->clear();
	lineNewPwd->clear();
	lineNewPwd_2->clear();

}


