#pragma once

#include "mysql.h"
#include <qdebug.h>
#include <QFile>
#include "structure.h"
#include <QDate>
#include <QDir>

//#ifdef WIN64
//#pragma  execution_character_set("GB18030")
//#endif

class MysqlError {};

class Database
{
private:
    MYSQL* mysql;
    MYSQL_RES* res;
    MYSQL_ROW* column;
    QString query;
    QVector<QString> project;
    QVector<QString> department;
    QString dir_str;
    void execute(MYSQL*, const QString&);

public:
    Database();
    ~Database();
    ForMap_db getAttendanceDate(const QString& pro, int day);
    ForMap_db getScheduleDate(const QString& pro);
    UsedWhenLogin_db doLogin_db(UsernmPwd& usernmPwd);
    int doRegister_db(RegisterInfo& registerInfo);
    int doChgPwd_db(ChgPwdInfo& chgPwdInfo);
    int doForAttndnce_db(QVector<QVector<QString>> v_v_BtnSaveClicked);
    int doForSchedule_db(QVector<QVector<QString>> v_forAttndnce);
    Forv_v_str_db getPurchaseDate(const QString&, int, int, int);
    int doForSubmit_db(QVector<QVector<QString>> v_v_tableDate);
    Forv_v_str_db doForOpen_db(const QString&);
    int doForState(const QString&, int, int, const QString&, QVector<QString>);
    int doForCostAndDate(QVector<QString>);
    int doForDelete_db(const QString&);
    int doForEntryData_db(QVector<QString> v_sendEntryData, const QByteArray& data);
    int doForChangeData_db(QVector<QString> v_sendChangeData);
    QVector<QString> doForChangeName_db(const QString& name);
    int doForOutData_db(QVector<QString> v_sendOutData);
    Forv_v_str_db doForGetEmployeeInfoData_db(QVector<QString>);
    QString doForGetImageData_db(const QString&);
    int doForSaveEmployeeInfo_db(QMap<QString, QString> map_saveEmployeeInfo, const QByteArray& data);
    Forv_v_str_db doForInsuranceInfo_db(QVector<QString>);
    int doForSaveInsuranceInfo_db(QVector<QString>);
    Forv_v_str_db doForSendTotal_db(QVector<QString>);
    ForMenuTriggered_db doForMenuTriggered_db(const QString&);

private:
    void connectDatabase();
    bool isTableExist(QString);
    void createTable_user_info();
    void createTable_employee_attendance();
    void createTable_employee_info();
    void createTable_employee_schedule();
    void createTable_purchase();
    void initVecProAndDep();
    //void putInTestDateForEmployee();

};

