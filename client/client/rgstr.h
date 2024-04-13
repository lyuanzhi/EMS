#pragma once

#include <QWidget>
#include "MyLineEdit.h"
#include "dfn.h"
#include "md5ZZ.h"

class Rgstr : public QWidget
{
	Q_OBJECT

public:
	Rgstr(QWidget *parent = Q_NULLPTR);
	~Rgstr();

private:
    QLabel* labelTtl;
    QLabel* labelUser;
    QLabel* labelRlnm;
    QLabel* labelGhp;
    QLabel* labelZcxm;
    QLabel* labelSzbm;
    QLabel* labelPwd;
    QLabel* labelPwd_2;
    QLabel* label_user;
    QLabel* label_rlnm;
    QLabel* label_ghp;
    QLabel* label_zcxm;
    QLabel* label_szbm;
    QLabel* label_pwd;
    QLabel* label_pwd_2;
    MyLineEdit* lineUser;
    QLineEdit* lineRlnm;
    QLineEdit* lineGhp;
    MyLineEdit* linePwd;
    MyLineEdit* linePwd_2;
    QComboBox* cbxZcxm;
    QComboBox* cbxSzbm;
    QPushButton* btnIdtfy;
    QPushButton* btnRgst;
    QPushButton* btnRtn;

signals:
    void sig_return();
    void sig_register(RegisterInfo);

public slots:
    void onsig_forUserNameExist();
    void onsig_forSOrFCreated();

};
