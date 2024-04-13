#pragma once

#include <QWidget>
#include "MyLineEdit.h"
#include "dfn.h"
#include "md5ZZ.h"

class ChgPwd : public QWidget
{
	Q_OBJECT

public:
	ChgPwd(QWidget* parent = Q_NULLPTR);
	~ChgPwd();

private:
	QLabel* labelTtl;
	QLabel* labelUser;
	QLabel* labelOldPwd;
	QLabel* labelGhp;
	QLabel* labelNewPwd;
	QLabel* labelNewPwd_2;
	QLabel* label_user;
	QLabel* label_old_pwd;
	QLabel* label_ghp;
	QLabel* label_new_pwd;
	QLabel* label_new_pwd_2;
	MyLineEdit* lineUser;
	MyLineEdit* lineOldPwd;
	QLineEdit* lineGhp;
	MyLineEdit* lineNewPwd;
	MyLineEdit* lineNewPwd_2;
	QPushButton* btnChg;
	QPushButton* btnRtn;

signals:
	void sig_return();
	void sig_change(ChgPwdInfo);

public slots:
	void onsig_forWrongOrSuccess();

};
