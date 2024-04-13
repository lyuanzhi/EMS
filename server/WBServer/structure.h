#pragma once

#include <QVector>
#include <QMap>

//#ifdef WIN32
//#pragma  execution_character_set("utf-8")
//#endif

#define SERVER_PORT		8888
#define NUM_PROJECT 	12
#define NUM_DEPARTMENT	8


struct UsernmPwd
{
	QString username;
	QString encrypted_password;
};

struct RegisterInfo
{
	QString newUserName;
	QString realName;
	QString ghp;
	QString zcxm;
	QString szbm;
	QString password;
	QString encrypted_password;
};

struct ChgPwdInfo
{
	QString UserName;
	QString ghp;
	QString encrypted_oldPassword;
	QString newPassword;
	QString encrypted_newPassword;
};

struct ForMap_db
{
	QMap<QString, QVector<QVector<QString>>> map;
	int flag;
};

struct Forv_v_str_db
{
	QVector<QVector<QString>> v_v_str;
	int flag;
};

struct UsedWhenLogin_db
{
	int flag;
	QString user_name;
	QString user_real_name;
	QString work_card;
	QString xm;
	QString bm;
	QString user_password;
};

struct ForMenuTriggered_db
{
	QVector<QString> totalData_oneCol;
	int flag;
	int col;
};

enum Flag
{
	DONOTHING,
	FOR_PWD_FALSE = 1,
	FOR_PWD_TRUE,
	FOR_USER_NAME_EXIST,
	FOR_SUCCESSFUL_CREATED,
	FOR_FAILED_CREATED,
	FOR_WRONG_INFO,
	FOR_SUCCESSFUL_CHANGED,
	FOR_ATTENDANCE_INIT,
	FOR_SCHEDULE_INIT,
	FOR_SUCCESSFUL_SAVED,
	FOR_FAILED_SAVED,
	FOR_SUCCESSFUL_SUBMIT,
	FOR_FAILED_SUBMIT,
	FOR_PURCHASE_INIT,
	FOR_OPEN,
	FOR_STATE,
	FOR_SUCCESSFUL_DELETE,
	FOR_REAL_NAME_EXIST,
	FOR_SUCCESSFUL_ENTRY,
	FOR_SUCCESSFUL_CHANGED_YGGL,
	FOR_CHANGE_NAME,
	FOR_SUCCESSFUL_OUT,
	FOR_REAL_NAME_NOT_EXIST,
	FOR_OUT,
	FOR_EMPLOYEEINFO,
	IMAGEDATA,
	FOR_SUCCESSFUL_SAVED_YGGL,
	FOR_INSURANCEINFO,
	FOR_SUCCESSFUL_SAVED_2_YGGL,
	FOR_SENDTOTAL,
	FOR_MENU_TOTALDATA

};

enum ClassName
{
	USERNMPWD = 1,
	REGISTERINFO,
	CHGPWDINFO,
	FORBTNATTNDNCE,
	FORBTNSCHEDULE,
	ATTENDDATA,
	SCHEDULEDATA,
	FORBTNSUBMIT,
	PURCHASEDATA,
	FORBTNOPEN,
	FORSTATEDATA,
	COSTANDDATE,
	FORBTNDELETE,
	FORSENDENTRYDATA,
	FORSENDCHANGEDATA,
	FORSENDCHANGENAME,
	FORSENDOUTDATA,
	FORSENDEMPLOYEEINFODATA,
	FORSENDIMAGEDATA,
	FORSAVEEMPLOYEEINFO,
	FORINSURANCEINFO,
	FORSAVEINSURANCEINFO,
	FORSENDTOTAL,
	FORMENUTRIGGERED

};
