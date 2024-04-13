#pragma once

#include <QWidget>
#include "rgstr.h"
#include "chgpwd.h"
#include "md5ZZ.h"

class Login : public QWidget
{
	Q_OBJECT

public:
	Login(QWidget *parent = Q_NULLPTR);
	~Login();

public:
	Rgstr* rgstr;
	ChgPwd* chgPwd;

	// µœ÷Õœ∂Ø
	bool m_bPressed = true;
	QPoint m_point;
	void mouseReleaseEvent(QMouseEvent* event);
	void mousePressEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);

private:
	MyLineEdit* lineUser;
	MyLineEdit* linePwd;
	QPushButton* btnLgn;
	QPushButton* btnRgst;
	QPushButton* btnChg;
	QPushButton* btnMinimize;
	QPushButton* btnExit;
	QPropertyAnimation* animation;

protected:
	virtual void keyPressEvent(QKeyEvent* event);

signals:
	void sig_register(RegisterInfo);
	void sig_change(ChgPwdInfo);
	void sig_login(UsernmPwd);

public slots:
	void onsig_register(RegisterInfo);
	void onsig_change(ChgPwdInfo);
	void onBtnLgnClicked();

};
