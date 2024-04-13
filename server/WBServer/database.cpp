#include "database.h"

int getDayMaxOfMonth(int year, int month) {

    int day_max = 0;
    switch (month)
    {
    case 1:case 3:case 5: case 7:case 8:case 10:case 12: day_max = 31; break;
    case 4:case 6:case 9:case 11: day_max = 30; break;
    case 2:
        if ((year % 4 == 0 && year % 100 != 0)
            || (year % 400 == 0 && year % 3200 != 0)
            || year % 172800 == 0) {
            day_max = 29;
        }
        else {
            day_max = 28;
        }
        break;
    default:
        break;
    }
    return day_max;

}

Database::Database() {

    //init
    mysql = NULL;
    res = NULL;
    column = NULL;
    mysql = new MYSQL;
    res = new MYSQL_RES;
    column = new MYSQL_ROW;
    query = "";
    initVecProAndDep();
    connectDatabase();

    createTable_user_info();
    createTable_employee_info();
    createTable_employee_attendance();
    createTable_employee_schedule();
    createTable_purchase();
    dir_str = "employee_pic";
    QDir dir;
    if (!dir.exists(dir_str))
    {
        dir.mkpath(dir_str);
    }
}

Database::~Database() {
    mysql_close(mysql);
    delete mysql;
    mysql = NULL;
    delete column;
    column = NULL;
}

void Database::execute(MYSQL* mysql, const QString& query) {

    if (mysql_query(mysql, query.toUtf8().data())) {
        throw MysqlError();
    }

}

void Database::connectDatabase() {

    mysql_init(mysql);
    if (!(mysql_real_connect(mysql, "lyuanzhi.com", "root", "Eshxcpqw.123", NULL, 3306, NULL, 0))) {
        qDebug() << "failed";
        return;
    }
    qDebug() << "succeed";

    mysql_query(mysql, "create database if not exists wb");
    mysql_select_db(mysql, "wb");
    mysql_query(mysql, "set names utf8");

}

bool Database::isTableExist(QString tableName) {

    query = QString("select * from information_schema.TABLES "
        "where TABLE_SCHEMA ='wb' and TABLE_NAME ='%1'").arg(tableName);
    mysql_query(mysql, query.toUtf8().data());
    res = mysql_store_result(mysql);

    if (mysql_num_rows(res) == 0) {
        qDebug() << QString("TABLE %1 is not exist!").arg(tableName);
        return false;
    }
    qDebug() << QString("TABLE %1 is exist!").arg(tableName);
    return true;

}

void Database::createTable_user_info() {

    if (isTableExist("user_info")) {
        return;
    }

    try
    {
        mysql_query(mysql, "begin");
        query = "create table if not exists user_info ("
            "id int not null auto_increment primary key comment 'ID',"
            "user_name varchar(30) comment '用户名',"
            "user_real_name varchar(20) comment '真实姓名',"
            "user_password varchar(20) comment '密码',"
            "user_encrypted_password varchar(50) comment '加密后密码',"
            "xm varchar(20) comment '项目',"
            "bm varchar(20) comment '部门',"
            "work_card varchar(10) comment '工号牌',"
            "permission int(10) comment '权限',"
            "created_time datetime comment '记录创建时间'"
            ")";
        execute(mysql, query);

        query = "create index index_NmPwdCrd on user_info(user_name,user_encrypted_password,work_card)";
        execute(mysql, query);
        mysql_query(mysql, "commit");
    }
    catch (MysqlError)
    {
        mysql_query(mysql, "rollback");
    }

}

void Database::createTable_employee_info() {

    if (isTableExist("employee_info")) {
        return;
    }

    try
    {
        mysql_query(mysql, "begin");
        query = "create table if not exists employee_info ("
            "work_card varchar(10) comment '工号牌',"
            "real_name varchar(20) not null primary key comment '真实姓名',"
            "sex varchar(5) comment '性别',"
            "position varchar(20) comment '职务',"
            "xm varchar(20) comment '项目',"
            "bm varchar(20) comment '部门',"
            "entry_time date comment '入职时间',"
            "id_card varchar(20) comment '身份证',"
            "hometown varchar(50) comment '籍贯',"
            "nation varchar(10) comment '民族',"
            "phone_num varchar(20) comment '电话',"
            "emergency_phone_num varchar(20) comment '应急电话',"
            "address varchar(50) comment '住址',"
            "degree varchar(20) comment '学历',"
            "major varchar(20) comment '专业',"
            "certificate varchar(40) comment '证书',"
            "job_title varchar(20) comment '职称',"
            "speciality varchar(30) comment '特长',"
            "state_of_health varchar(30) comment '健康状况',"
            "marriage varchar(5) comment '婚姻状况',"
            "political_status varchar(10) comment '政治面貌',"
            "social_security varchar(10) comment '社保',"
            "indstrl_injry_insrnce varchar(10) comment '工伤险',"
            "accident_insrnce varchar(10) comment '意外险',"
            "basic_wage decimal comment '基本工资',"
            "overtime_wage decimal comment '超时工资',"
            "appraisal_wage decimal comment '考核工资',"
            "job_wage decimal comment '岗位工资',"
            "scl_scurty_subsidy decimal comment '社保补贴',"
            "accommodation_allowance decimal comment '食宿补贴',"
            "contract varchar(30) comment '合同',"
            "change_date date comment '调动时间',"
            "leave_date date comment '离职时间',"
            "change_reason varchar(200) comment '调动原因',"
            "leave_reason varchar(200) comment '离职原因',"
            "leave_settlement varchar(50) comment '离职结算',"
            "in_service varchar(5) comment '在职',"
            "birthday date comment '生日',"
            "bank_card_num varchar(30) comment '银行卡号',"
            "remark varchar(200) comment '备注',"
            "created_time datetime comment '记录创建时间'"
            ")";
        execute(mysql, query);

        query = "create index index_xm_bm on employee_info(xm,bm)";
        execute(mysql, query);
        mysql_query(mysql, "commit");
    }
    catch (MysqlError)
    {
        mysql_query(mysql, "rollback");
    }

}

void Database::createTable_employee_attendance() {

    if (isTableExist("employee_attendance")) {
        return;
    }

    query = "create table if not exists employee_attendance ("
        "real_name varchar(20) not null comment '真实姓名',"
        "d1th int(1) default 0,d2th int(1) default 0,d3th int(1) default 0,d4th int(1) default 0,"
        "d5th int(1) default 0,d6th int(1) default 0,d7th int(1) default 0,d8th int(1) default 0,"
        "d9th int(1) default 0,d10th int(1) default 0,d11th int(1) default 0,d12th int(1) default 0,"
        "d13th int(1) default 0,d14th int(1) default 0,d15th int(1) default 0,d16th int(1) default 0,"
        "d17th int(1) default 0,d18th int(1) default 0,d19th int(1) default 0,d20th int(1) default 0,"
        "d21th int(1) default 0,d22th int(1) default 0,d23th int(1) default 0,d24th int(1) default 0,"
        "d25th int(1) default 0,d26th int(1) default 0,d27th int(1) default 0,d28th int(1) default 0,"
        "d29th int(1) default 0,d30th int(1) default 0,d31th int(1) default 0,"
        "created_time datetime comment '记录创建时间',"
        "foreign key (real_name) references employee_info (real_name)"
        ")";
    mysql_query(mysql, query.toUtf8().data());

}

void Database::createTable_employee_schedule() {

    if (isTableExist("employee_schedule")) {
        return;
    }

    query = "create table if not exists employee_schedule ("
        "real_name varchar(20) not null comment '真实姓名',"
        "d1th int(1) default 2,d2th int(1) default 2,d3th int(1) default 2,d4th int(1) default 2,"
        "d5th int(1) default 2,d6th int(1) default 2,d7th int(1) default 2,d8th int(1) default 2,"
        "d9th int(1) default 2,d10th int(1) default 2,d11th int(1) default 2,d12th int(1) default 2,"
        "d13th int(1) default 2,d14th int(1) default 2,d15th int(1) default 2,d16th int(1) default 2,"
        "d17th int(1) default 2,d18th int(1) default 2,d19th int(1) default 2,d20th int(1) default 2,"
        "d21th int(1) default 2,d22th int(1) default 2,d23th int(1) default 2,d24th int(1) default 2,"
        "d25th int(1) default 2,d26th int(1) default 2,d27th int(1) default 2,d28th int(1) default 2,"
        "d29th int(1) default 2,d30th int(1) default 2,d31th int(1) default 2,"
        "created_time datetime comment '记录创建时间',"
        "foreign key (real_name) references employee_info (real_name)"
        ")";
    mysql_query(mysql, query.toUtf8().data());

}

void Database::createTable_purchase() {

    if (isTableExist("purchase")) {
        return;
    }

    try
    {
        mysql_query(mysql, "begin");
        query = "create table if not exists purchase ("
            "purchase_id varchar(40) not null primary key comment '采购单号',"
            "serial_number int(4) comment '序号',"
            "pro_date varchar(35) comment '项目和日期',"
            "app_date date comment '日期',"
            "applicant varchar(10) comment '申请人',"
            "thing_name varchar(50) comment '物品名称',"
            "number int(8) comment '数量',"
            "unit varchar(10) comment '单位',"
            "format varchar(30) comment '型号规格',"
            "application varchar(50) comment '用途',"
            "cost decimal(10,2) comment '金额',"
            "advice varchar(50) comment '审批意见',"
            "purchase_date varchar(35) comment '采购日期',"
            "xmjl_name varchar(10) comment '项目经理',"
            "zhb_name varchar(10) comment '综合部',"
            "zjb_name varchar(10) comment '总经办',"
            "state int(1) comment '状态',"
            "created_time datetime comment '记录创建时间'"
            ")";
        execute(mysql, query);

        query = "create index index_state on purchase(state)";
        execute(mysql, query);
        mysql_query(mysql, "commit");
    }
    catch (MysqlError)
    {
        mysql_query(mysql, "rollback");
    }

}

void Database::initVecProAndDep() {

    project.push_back("公司总部");
    project.push_back("文鼎公寓");
    project.push_back("望湖家园");
    project.push_back("金城一区");
    project.push_back("江南小区");
    project.push_back("东方国际村");
    project.push_back("嘉鸿华庭");
    project.push_back("阳光都市");
    project.push_back("银河证券");
    project.push_back("春晗公寓");
    project.push_back("文化旅游局");
    project.push_back("中厦国际保安");

    department.push_back("项目经理");
    department.push_back("行政部");
    department.push_back("客服部");
    department.push_back("工程部");
    department.push_back("秩序维护部");
    department.push_back("环境部绿化");
    department.push_back("环境部保洁");
    department.push_back("后勤部");

}

ForMap_db Database::getAttendanceDate(const QString& pro, int day) {

    struct ForMap_db forMap_db;

    forMap_db.flag = Flag::FOR_ATTENDANCE_INIT;
    QVector<QVector<QString>> v_v_temp;
    QVector<QString> v_temp;

    for (auto it_dep = department.cbegin(); it_dep != department.cend(); ++it_dep) {
        query = QString("select employee_attendance.real_name,employee_attendance.d%1th from employee_attendance "
            "join employee_info on(employee_info.real_name=employee_attendance.real_name) "
            "where employee_info.xm='%2' and employee_info.bm='%3'").arg(day).arg(pro).arg(*it_dep);
        mysql_query(mysql, query.toUtf8().data());
        res = mysql_store_result(mysql);
        while ((*column) = mysql_fetch_row(res)) {
            v_temp.push_back((*column)[0]);
            v_temp.push_back((*column)[1]);
            v_v_temp.push_back(v_temp);
            v_temp.clear();
        }
        forMap_db.map.insert(*it_dep, v_v_temp);
        v_v_temp.clear();
        mysql_free_result(res);
    }
    return forMap_db;

}

ForMap_db Database::getScheduleDate(const QString& pro) {

    struct ForMap_db forMap_db;

    forMap_db.flag = Flag::FOR_SCHEDULE_INIT;
    QVector<QVector<QString>> v_v_temp;
    QVector<QString> v_temp;

    for (auto it_dep = department.cbegin(); it_dep != department.cend(); ++it_dep) {
        query = QString("select employee_schedule.* from employee_schedule "
            "join employee_info on(employee_info.real_name=employee_schedule.real_name) "
            "where employee_info.xm='%1' and employee_info.bm='%2'").arg(pro).arg(*it_dep);
        mysql_query(mysql, query.toUtf8().data());
        res = mysql_store_result(mysql);
        while ((*column) = mysql_fetch_row(res)) {
            v_temp.push_back((*column)[0]);
            for (int i = 1; i < mysql_num_fields(res) - 1; ++i)
                v_temp.push_back((*column)[i]);
            v_v_temp.push_back(v_temp);
            v_temp.clear();
        }
        forMap_db.map.insert(*it_dep, v_v_temp);
        v_v_temp.clear();
        mysql_free_result(res);
    }
    return forMap_db;

}

UsedWhenLogin_db Database::doLogin_db(UsernmPwd& usernmPwd) {

    UsedWhenLogin_db usedWhenLogin_db;
    usedWhenLogin_db.flag = 0;
    usedWhenLogin_db.user_name = "";
    usedWhenLogin_db.user_real_name = "";
    usedWhenLogin_db.xm = "";
    usedWhenLogin_db.bm = "";
    usedWhenLogin_db.user_password = "";

    query = QString("select user_name,user_real_name,work_card,xm,bm,user_password from user_info "
        "where user_name='%1' and user_encrypted_password='%2'").arg(usernmPwd.username, usernmPwd.encrypted_password);
    mysql_query(mysql, query.toUtf8().data());
    res = mysql_store_result(mysql);

    if (mysql_num_rows(res) == 0) {
        usedWhenLogin_db.flag = Flag::FOR_PWD_FALSE;
    }
    else {
        usedWhenLogin_db.flag = Flag::FOR_PWD_TRUE;
        *column = mysql_fetch_row(res);
        usedWhenLogin_db.user_name = (*column)[0];
        usedWhenLogin_db.user_real_name = (*column)[1];
        usedWhenLogin_db.work_card = (*column)[2];
        usedWhenLogin_db.xm = (*column)[3];
        usedWhenLogin_db.bm = (*column)[4];
        usedWhenLogin_db.user_password = (*column)[5];
        qDebug() << usedWhenLogin_db.user_name << usedWhenLogin_db.user_real_name << usedWhenLogin_db.work_card
            << usedWhenLogin_db.xm << usedWhenLogin_db.bm << usedWhenLogin_db.user_password;
    }
    mysql_free_result(res);
    return usedWhenLogin_db;

}

int Database::doRegister_db(RegisterInfo& registerInfo) {

    int flag = 0;

    query = QString("select user_name from user_info where user_name='%1'").arg(registerInfo.newUserName);
    mysql_query(mysql, query.toUtf8().data());
    res = mysql_store_result(mysql);

    if (mysql_num_rows(res) != 0) {
        flag = Flag::FOR_USER_NAME_EXIST;
    }
    else {
        query = QString("insert into user_info (user_name,user_real_name,user_password,"
            "user_encrypted_password,xm,bm,work_card,created_time) values ('%1','%2','%3','%4','%5','%6','%7',now())")
            .arg(registerInfo.newUserName).arg(registerInfo.realName).arg(registerInfo.password)
            .arg(registerInfo.encrypted_password).arg(registerInfo.zcxm).arg(registerInfo.szbm).arg(registerInfo.ghp);
        if (!mysql_query(mysql, query.toUtf8().data()))
        {
            flag = Flag::FOR_SUCCESSFUL_CREATED;
        }
        else {
            flag = Flag::FOR_FAILED_CREATED;
        }
    }
    mysql_free_result(res);
    return flag;

}

int Database::doChgPwd_db(ChgPwdInfo& chgPwdInfo) {

    int flag = 0;

    query = QString("select user_name from user_info "
        "where user_name='%1' and user_encrypted_password='%2' and work_card='%3'")
        .arg(chgPwdInfo.UserName).arg(chgPwdInfo.encrypted_oldPassword).arg(chgPwdInfo.ghp);
    mysql_query(mysql, query.toUtf8().data());
    res = mysql_store_result(mysql);

    if (mysql_num_rows(res) == 0) {
        flag = Flag::FOR_WRONG_INFO;
    }
    else {
        query = QString("update user_info set user_password='%1',user_encrypted_password='%2' "
            "where user_name='%3'").arg(chgPwdInfo.newPassword)
            .arg(chgPwdInfo.encrypted_newPassword).arg(chgPwdInfo.UserName);
        if (!mysql_query(mysql, query.toUtf8().data()))
            flag = Flag::FOR_SUCCESSFUL_CHANGED;
    }
    mysql_free_result(res);
    return flag;

}

int Database::doForAttndnce_db(QVector<QVector<QString>> v_v_BtnSaveClicked) {

    int flag = 0;
    try
    {
        mysql_query(mysql, "begin");
        for (auto it = v_v_BtnSaveClicked.cbegin(); it != v_v_BtnSaveClicked.cend(); ++it) {
            query = QString("update employee_attendance set d%1th= %2 "
                "where real_name='%3'").arg((*it)[1]).arg((*it)[2]).arg((*it)[0]);
            execute(mysql, query);
        }
        mysql_query(mysql, "commit");
        flag = Flag::FOR_SUCCESSFUL_SAVED;
    }
    catch (MysqlError)
    {
        mysql_query(mysql, "rollback");
        flag = Flag::FOR_FAILED_SAVED;
    }

    return flag;

}

int Database::doForSchedule_db(QVector<QVector<QString>> v_v_forSche) {

    int flag = 0;
    try
    {
        mysql_query(mysql, "begin");
        for (auto it = v_v_forSche.cbegin(); it != v_v_forSche.cend(); ++it) {
            int day_index = 1;
            for (auto it_2 = it->cbegin(); it_2 != it->cend(); ++it_2) {
                if (it_2 == it->cbegin())
                    continue;
                query = QString("update employee_schedule set d%1th= %2 "
                    "where real_name='%3'").arg(QString::number(day_index)).arg(*it_2).arg((*it)[0]);
                execute(mysql, query);
                ++day_index;
            }
        }
        mysql_query(mysql, "commit");
        flag = Flag::FOR_SUCCESSFUL_SAVED;
    }
    catch (MysqlError)
    {
        mysql_query(mysql, "rollback");
        flag = Flag::FOR_FAILED_SAVED;
    }

    return flag;

}

Forv_v_str_db Database::getPurchaseDate(const QString& pro, int year, int month, int state) {

    struct Forv_v_str_db forv_v_str_db;
    QVector<QString> temp;
    uint64_t num_field = 0;
    forv_v_str_db.flag = Flag::FOR_PURCHASE_INIT;
    QString monthStr = QString::number(month);
    if(month < 10){
        monthStr = "0" + monthStr;
    }
    if (state == 0) {
        query = QString("select distinct pro_date,state from purchase "
            "where purchase_id like '%1#%2-%3-%'").arg(pro).arg(year).arg(monthStr);
    }
    else {
        query = QString("select distinct pro_date,state from purchase "
            "where purchase_id like '%1#%2-%3-%' and state=%4").arg(pro).arg(year).arg(monthStr).arg(state);
    }
    mysql_query(mysql, query.toUtf8().data());
    res = mysql_store_result(mysql);
    num_field = mysql_num_fields(res);

    while ((*column) = mysql_fetch_row(res)) {
        for (int i = 0; i < num_field; ++i) {
            temp.push_back((*column)[i]);
        }
        forv_v_str_db.v_v_str.push_back(temp);
        temp.clear();
    }
    mysql_free_result(res);

    return forv_v_str_db;

}

int Database::doForSubmit_db(QVector<QVector<QString>> v_v_tableDate) {

    int flag = 0;
    try
    {
        mysql_query(mysql, "begin");
        auto it = v_v_tableDate.cbegin();
        int count_t = 0;
        QString pro_date = "";
        QString app_date = "";
        for (auto c : (*it)[0]) {
            if (c == '#') ++count_t;
            if (count_t != 2) pro_date = pro_date + c;
            if (count_t == 1 && c != '#') app_date += c;
        }
        query = QString("delete from purchase where pro_date='%1'").arg(pro_date);
        execute(mysql, query);
        for (; it != v_v_tableDate.cend(); ++it) {
            count_t = 0;
            QString serial_number = "";
            for (auto c : (*it)[0]) {
                if (count_t == 2) serial_number = serial_number + c;
                if (c == '#') ++count_t;
            }
            query = QString("insert into purchase "
                "(purchase_id,applicant,thing_name,number,unit,format,application,advice,cost,purchase_date,state,"
                "created_time,serial_number,pro_date,app_date,xmjl_name,zhb_name,zjb_name) "
                "values ('%1','%2','%3',%4,'%5','%6','%7',NULL,NULL,NULL,%8,now(),%9,'%10','%11',NULL,NULL,NULL)")
                .arg((*it)[0]).arg((*it)[1]).arg((*it)[2]).arg((*it)[3]).arg((*it)[4]).arg((*it)[5])
                .arg((*it)[6]).arg((*it)[7]).arg(serial_number).arg(pro_date).arg(app_date);
            execute(mysql, query);
        }
        mysql_query(mysql, "commit");
        flag = Flag::FOR_SUCCESSFUL_SUBMIT;
    }
    catch (MysqlError)
    {
        mysql_query(mysql, "rollback");
        flag = Flag::FOR_FAILED_SUBMIT;
    }

    return flag;

}

Forv_v_str_db Database::doForOpen_db(const QString& purchase_id) {

    Forv_v_str_db forv_v_str_db;
    forv_v_str_db.flag = Flag::FOR_OPEN;
    QVector<QString> temp;

    query = QString("select applicant,thing_name,number,unit,format,application,advice,cost,purchase_date,"
        "xmjl_name,zhb_name,zjb_name from purchase where pro_date='%1' order by serial_number").arg(purchase_id);
    mysql_query(mysql, query.toUtf8().data());
    res = mysql_store_result(mysql);
    uint64_t num_field = mysql_num_fields(res);
    while ((*column) = mysql_fetch_row(res)) {
        for (int i = 0; i < num_field; ++i) {
            temp.push_back((*column)[i]);
        }
        forv_v_str_db.v_v_str.push_back(temp);
        temp.clear();
    }
    mysql_free_result(res);

    return forv_v_str_db;

}

int Database::doForState(const QString& pro_date, int state, int index, const QString& name, QVector<QString> advice) {

    int flag = 0;
    QString temp = "";
    switch (index)
    {
    case 0:temp = "xmjl_name"; break;
    case 1:temp = "zhb_name"; break;
    case 2:temp = "zjb_name"; break;
    default:break;
    }

    try
    {
        mysql_query(mysql, "begin");
        if (advice.isEmpty()) {
            query = QString("update purchase set state=%1,%2='%3',advice='' where pro_date='%4'")
                .arg(QString::number(state)).arg(temp).arg(name).arg(pro_date);
            execute(mysql, query);
        }
        else {
            for (int i = 0; i < advice.size(); ++i) {
                query = QString("update purchase set state=%1,%2='%3',advice='%4' where pro_date='%5' and serial_number=%6")
                    .arg(QString::number(state)).arg(temp).arg(name).arg(advice[i]).arg(pro_date).arg(i + 1);
                execute(mysql, query);
            }
        }
        mysql_query(mysql, "commit");
        flag = Flag::FOR_STATE;
    }
    catch (MysqlError)
    {
        mysql_query(mysql, "rollback");
        flag = Flag::DONOTHING;
    }

    return flag;

}

int Database::doForCostAndDate(QVector<QString> v_forCostAndDate) {

    try
    {
        mysql_query(mysql, "begin");
        if (v_forCostAndDate[4].toInt() == 5 || v_forCostAndDate[4].toInt() == 4) {
            query = QString("update purchase set state=%1 where pro_date='%2'")
                .arg(v_forCostAndDate[4]).arg(v_forCostAndDate[3]);
            execute(mysql, query);
        }
        query = QString("update purchase set cost=%1,purchase_date='%2' where purchase_id='%3'")
            .arg(v_forCostAndDate[0]).arg(v_forCostAndDate[1]).arg(v_forCostAndDate[2]);
        execute(mysql, query);
        mysql_query(mysql, "commit");
    }
    catch (MysqlError)
    {
        mysql_query(mysql, "rollback");
        return Flag::DONOTHING;
    }

    if (v_forCostAndDate[4].toInt() == 5 || v_forCostAndDate[4].toInt() == 4) {
        return Flag::FOR_STATE;
    }
    else {
        return Flag::DONOTHING;
    }

}

int Database::doForDelete_db(const QString& id) {

    query = QString("delete from purchase where pro_date='%1'").arg(id);
    if (!mysql_query(mysql, query.toUtf8().data()))
        return Flag::FOR_SUCCESSFUL_DELETE;

    return Flag::DONOTHING;

}

int Database::doForEntryData_db(QVector<QString> v_sendEntryData, const QByteArray& data) {

    int flag = 0;
    QVector<QString> temp;
    query = QString("select in_service from employee_info "
        "where real_name='%1'").arg(v_sendEntryData[0]);
    mysql_query(mysql, query.toUtf8().data());
    res = mysql_store_result(mysql);
    while ((*column) = mysql_fetch_row(res)) {
        for (int i = 0; i < mysql_num_fields(res); ++i) {
            temp.push_back((*column)[i]);
        }
    }
    if (mysql_num_rows(res) != 0) {
        flag = Flag::FOR_REAL_NAME_EXIST;
        if (mysql_num_rows(res) == 1 && temp[0] == "no") {
            try
            {
                mysql_query(mysql, "begin");
                query = QString(
                    "update employee_info set leave_date=NULL,leave_settlement=NULL,leave_reason=NULL,in_service=NULL where real_name='%1'"
                ).arg(v_sendEntryData[0]);
                execute(mysql, query);
                query = QString("insert into employee_attendance (real_name) values ('%1')").arg(v_sendEntryData[0]);
                execute(mysql, query);
                mysql_query(mysql, "commit");
                flag = Flag::FOR_SUCCESSFUL_ENTRY;
            }
            catch (MysqlError)
            {
                mysql_query(mysql, "rollback");
                flag = Flag::DONOTHING;
            }
        }
    }
    else {

        //保存图片
        if (!data.isEmpty()) {
            QDir tempDir;
            QString currentDir = tempDir.currentPath();
            QFile file(QString("%1.%2").arg(v_sendEntryData[0]).arg(v_sendEntryData[22]));
            tempDir.setCurrent(dir_str);
            file.open(QIODevice::WriteOnly);
            file.write(data);
            file.close();
            tempDir.setCurrent(currentDir);
        }

        try
        {
            mysql_query(mysql, "begin");
            QString birthday = QString("%1-%2-%3").arg(v_sendEntryData[4].mid(6, 4)).arg(v_sendEntryData[4].mid(10, 2)).arg(v_sendEntryData[4].mid(12, 2));
            query = QString(
                "insert into employee_info (real_name,sex,xm,bm,id_card,hometown,work_card,entry_time,position,nation,phone_num,"
                "emergency_phone_num,address,degree,major,certificate,job_title,speciality,state_of_health,marriage,political_status,contract,birthday) "
                "values ('%1','%2','%3','%4','%5','%6','%7','%8','%9','%10','%11','%12','%13','%14','%15',"
                "'%16','%17','%18','%19','%20','%21','%22','%23')"
            ).arg(v_sendEntryData[0]).arg(v_sendEntryData[1]).arg(v_sendEntryData[2]).arg(v_sendEntryData[3]).arg(v_sendEntryData[4]).arg(v_sendEntryData[5])
                .arg(v_sendEntryData[6]).arg(v_sendEntryData[7]).arg(v_sendEntryData[8]).arg(v_sendEntryData[9]).arg(v_sendEntryData[10]).arg(v_sendEntryData[11])
                .arg(v_sendEntryData[12]).arg(v_sendEntryData[13]).arg(v_sendEntryData[14]).arg(v_sendEntryData[15]).arg(v_sendEntryData[16]).arg(v_sendEntryData[17])
                .arg(v_sendEntryData[18]).arg(v_sendEntryData[19]).arg(v_sendEntryData[20]).arg(v_sendEntryData[21]).arg(birthday);
            execute(mysql, query);
            query = QString("insert into employee_attendance (real_name) values ('%1')").arg(v_sendEntryData[0]);
            execute(mysql, query);
            query = QString("insert into employee_schedule (real_name) values ('%1')").arg(v_sendEntryData[0]);
            execute(mysql, query);
            mysql_query(mysql, "commit");
            flag = Flag::FOR_SUCCESSFUL_ENTRY;
        }
        catch (MysqlError)
        {
            mysql_query(mysql, "rollback");
            flag = Flag::DONOTHING;
        }
    }

    mysql_free_result(res);
    return flag;

}

int Database::doForChangeData_db(QVector<QString> v_sendChangeData) {

    int flag = 0;
    query = QString("update employee_info set xm='%1',change_date='%2',change_reason='%3' "
        "where real_name='%4'").arg(v_sendChangeData[2]).arg(v_sendChangeData[1]).arg(v_sendChangeData[3]).arg(v_sendChangeData[0]);
    if (!mysql_query(mysql, query.toUtf8().data())) {
        flag = Flag::FOR_SUCCESSFUL_CHANGED_YGGL;
    }
    return flag;

}

QVector<QString> Database::doForChangeName_db(const QString& name) {

    QVector<QString> flag_pro;
    query = QString("select xm from employee_info where real_name='%1' and in_service is NULL").arg(name);
    if (!mysql_query(mysql, query.toUtf8().data())) {
        flag_pro.push_back(QString::number(Flag::FOR_CHANGE_NAME));
        res = mysql_store_result(mysql);
        while ((*column) = mysql_fetch_row(res)) {
            for (int i = 0; i < mysql_num_fields(res); ++i) {
                flag_pro.push_back((*column)[i]);
            }
        }
        flag_pro.push_back("");
        mysql_free_result(res);
        return flag_pro;
    }
    return QVector<QString>{"0", ""};

}

int Database::doForOutData_db(QVector<QString> v_sendOutData) {

    int flag = 0;
    QVector<QString> temp;
    query = QString("select in_service from employee_info "
        "where real_name='%1' and xm='%2'").arg(v_sendOutData[0]).arg(v_sendOutData[4]);
    mysql_query(mysql, query.toUtf8().data());
    res = mysql_store_result(mysql);
    while ((*column) = mysql_fetch_row(res)) {
        for (int i = 0; i < mysql_num_fields(res); ++i) {
            temp.push_back((*column)[i]);
        }
    }
    if (mysql_num_rows(res) == 0) {
        flag = Flag::FOR_REAL_NAME_NOT_EXIST;
    }
    else if (temp[0] == "no") {
        flag = Flag::FOR_OUT;
    }
    else {
        try
        {
            mysql_query(mysql, "begin");
            query = QString("update employee_info set leave_date='%1',leave_settlement='%2',leave_reason='%3',in_service='no' where real_name='%4'")
                .arg(v_sendOutData[1]).arg(v_sendOutData[2]).arg(v_sendOutData[3]).arg(v_sendOutData[0]);
            execute(mysql, query);
            query = QString("delete from employee_attendance where real_name='%1'").arg(v_sendOutData[0]);
            execute(mysql, query);
            mysql_query(mysql, "commit");
            flag = Flag::FOR_SUCCESSFUL_OUT;
        }
        catch (MysqlError)
        {
            mysql_query(mysql, "rollback");
            flag = Flag::DONOTHING;
        }
    }

    mysql_free_result(res);
    return flag;

}

Forv_v_str_db Database::doForGetEmployeeInfoData_db(QVector<QString> v_forEmployeeInfoData) { //项目，姓名，包含，内容

    Forv_v_str_db forv_v_str_db;
    QVector<QString> v_temp;
    QString sql_temp = "";
    if (v_forEmployeeInfoData[1] == "项目") v_forEmployeeInfoData[1] = "xm";
    if (v_forEmployeeInfoData[1] == "姓名") v_forEmployeeInfoData[1] = "real_name";
    if (v_forEmployeeInfoData[1] == "性别") v_forEmployeeInfoData[1] = "sex";
    if (v_forEmployeeInfoData[1] == "年龄") v_forEmployeeInfoData[1] = "TIMESTAMPDIFF(YEAR, birthday, CURDATE())";
    if (v_forEmployeeInfoData[1] == "合同") v_forEmployeeInfoData[1] = "contract";
    if (v_forEmployeeInfoData[1] == "职务") v_forEmployeeInfoData[1] = "position";
    if (v_forEmployeeInfoData[1] == "部门") v_forEmployeeInfoData[1] = "bm";
    if (v_forEmployeeInfoData[1] == "工号牌") v_forEmployeeInfoData[1] = "work_card";
    if (v_forEmployeeInfoData[1] == "身份证号") v_forEmployeeInfoData[1] = "id_card";
    if (v_forEmployeeInfoData[1] == "籍贯") v_forEmployeeInfoData[1] = "hometown";
    if (v_forEmployeeInfoData[1] == "民族") v_forEmployeeInfoData[1] = "nation";
    if (v_forEmployeeInfoData[1] == "电话") v_forEmployeeInfoData[1] = "phone_num";
    if (v_forEmployeeInfoData[1] == "应急电话") v_forEmployeeInfoData[1] = "emergency_phone_num";
    if (v_forEmployeeInfoData[1] == "入职时间") v_forEmployeeInfoData[1] = "entry_time";
    if (v_forEmployeeInfoData[1] == "生日") v_forEmployeeInfoData[1] = "birthday";
    if (v_forEmployeeInfoData[1] == "学历") v_forEmployeeInfoData[1] = "degree";
    if (v_forEmployeeInfoData[1] == "专业") v_forEmployeeInfoData[1] = "major";
    if (v_forEmployeeInfoData[1] == "证书") v_forEmployeeInfoData[1] = "certificate";
    if (v_forEmployeeInfoData[1] == "职称") v_forEmployeeInfoData[1] = "job_title";
    if (v_forEmployeeInfoData[1] == "特长") v_forEmployeeInfoData[1] = "speciality";
    if (v_forEmployeeInfoData[1] == "健康状况") v_forEmployeeInfoData[1] = "state_of_health";
    if (v_forEmployeeInfoData[1] == "婚姻状况") v_forEmployeeInfoData[1] = "marriage";
    if (v_forEmployeeInfoData[1] == "政治面貌") v_forEmployeeInfoData[1] = "political_status";
    if (v_forEmployeeInfoData[1] == "在职状态") v_forEmployeeInfoData[1] = "in_service";
    if (v_forEmployeeInfoData[1] == "离职时间") v_forEmployeeInfoData[1] = "leave_date";
    if (v_forEmployeeInfoData[2] == "全部")
        sql_temp = QString("where xm='%1'").arg(v_forEmployeeInfoData[0]);
    else if (v_forEmployeeInfoData[2] == "包含")
        sql_temp = QString("where xm='%1' and LOCATE('%2', %3)>0").arg(v_forEmployeeInfoData[0]).arg(v_forEmployeeInfoData[3]).arg(v_forEmployeeInfoData[1]);
    else if (v_forEmployeeInfoData[2] == "不包含")
        sql_temp = QString("where xm='%1' and LOCATE('%2', %3)=0").arg(v_forEmployeeInfoData[0]).arg(v_forEmployeeInfoData[3]).arg(v_forEmployeeInfoData[1]);
    else if (v_forEmployeeInfoData[2] == "等于")
        sql_temp = QString("where xm='%1' and %2='%3'").arg(v_forEmployeeInfoData[0]).arg(v_forEmployeeInfoData[1]).arg(v_forEmployeeInfoData[3]);
    else if (v_forEmployeeInfoData[2] == "不等于")
        sql_temp = QString("where xm='%1' and %2!='%3'").arg(v_forEmployeeInfoData[0]).arg(v_forEmployeeInfoData[1]).arg(v_forEmployeeInfoData[3]);
    else if (v_forEmployeeInfoData[2] == "大于")
        sql_temp = QString("where xm='%1' and %2>'%3'").arg(v_forEmployeeInfoData[0]).arg(v_forEmployeeInfoData[1]).arg(v_forEmployeeInfoData[3]);
    else if (v_forEmployeeInfoData[2] == "大于或等于")
        sql_temp = QString("where xm='%1' and %2>='%3'").arg(v_forEmployeeInfoData[0]).arg(v_forEmployeeInfoData[1]).arg(v_forEmployeeInfoData[3]);
    else if (v_forEmployeeInfoData[2] == "小于")
        sql_temp = QString("where xm='%1' and %2<'%3'").arg(v_forEmployeeInfoData[0]).arg(v_forEmployeeInfoData[1]).arg(v_forEmployeeInfoData[3]);
    else if (v_forEmployeeInfoData[2] == "小于或等于")
        sql_temp = QString("where xm='%1' and %2<='%3'").arg(v_forEmployeeInfoData[0]).arg(v_forEmployeeInfoData[1]).arg(v_forEmployeeInfoData[3]);

    query = QString("select xm,real_name,sex,TIMESTAMPDIFF(YEAR, birthday, CURDATE()),contract,position,bm,work_card,id_card,hometown,"
        "nation,phone_num,emergency_phone_num,entry_time,birthday,degree,major,certificate,job_title,"
        "speciality,state_of_health,marriage,political_status,in_service,leave_date from employee_info "
        "%1").arg(sql_temp);
    if (!mysql_query(mysql, query.toUtf8().data())) {
        res = mysql_store_result(mysql);
        while ((*column) = mysql_fetch_row(res)) {
            for (int i = 0; i < mysql_num_fields(res); ++i) {
                v_temp.push_back((*column)[i]);
            }
            forv_v_str_db.v_v_str.push_back(v_temp);
            v_temp.clear();
        }
        mysql_free_result(res);
    }
    forv_v_str_db.flag = Flag::FOR_EMPLOYEEINFO;
    return forv_v_str_db;

}

QString Database::doForGetImageData_db(const QString& name) {

    query = QString("select address from employee_info where real_name='%1'").arg(name);
    if (!mysql_query(mysql, query.toUtf8().data())) {
        QVector<QString> v_temp;
        res = mysql_store_result(mysql);
        while ((*column) = mysql_fetch_row(res)) {
            for (int i = 0; i < mysql_num_fields(res); ++i) {
                v_temp.push_back((*column)[i]);
            }
        }
        mysql_free_result(res);
        return v_temp[0];
    }
    return QString("");

}

int Database::doForSaveEmployeeInfo_db(QMap<QString, QString> map_saveEmployeeInfo, const QByteArray& data) {

    int flag = 0;

    QDir tempDir;
    QString currentDir = tempDir.currentPath();
    tempDir.setCurrent(dir_str);

    if (map_saveEmployeeInfo["real_name"] != map_saveEmployeeInfo["prev_name"]) {
        qDebug() << QFile::rename(QString("%1.jpg").arg(map_saveEmployeeInfo["prev_name"]), QString("%1.jpg").arg(map_saveEmployeeInfo["real_name"]));
        qDebug() << QFile::rename(QString("%1.png").arg(map_saveEmployeeInfo["prev_name"]), QString("%1.png").arg(map_saveEmployeeInfo["real_name"]));
        qDebug() << QFile::rename(QString("%1.bmp").arg(map_saveEmployeeInfo["prev_name"]), QString("%1.bmp").arg(map_saveEmployeeInfo["real_name"]));
    }

    //修改图片
    if (!data.isEmpty()) {
        qDebug() << QFile::remove(QString("%1.jpg").arg(map_saveEmployeeInfo["real_name"]));
        qDebug() << QFile::remove(QString("%1.png").arg(map_saveEmployeeInfo["real_name"]));
        qDebug() << QFile::remove(QString("%1.bmp").arg(map_saveEmployeeInfo["real_name"]));
        QFile file(QString("%1.%2").arg(map_saveEmployeeInfo["real_name"]).arg(map_saveEmployeeInfo["pic_format"]));
        file.open(QIODevice::WriteOnly);
        file.write(data);
        file.close();
    }

    tempDir.setCurrent(currentDir);

    try
    {
        mysql_query(mysql, "begin");
        execute(mysql, "SET FOREIGN_KEY_CHECKS = 0");
        query = QString("update employee_attendance set real_name='%1' where real_name='%2'")
            .arg(map_saveEmployeeInfo["real_name"]).arg(map_saveEmployeeInfo["prev_name"]);
        execute(mysql, query);
        query = QString("update employee_schedule set real_name='%1' where real_name='%2'")
            .arg(map_saveEmployeeInfo["real_name"]).arg(map_saveEmployeeInfo["prev_name"]);
        execute(mysql, query);

        QString birthday = QString("%1-%2-%3").arg(map_saveEmployeeInfo["id_card"].mid(6, 4))
            .arg(map_saveEmployeeInfo["id_card"].mid(10, 2)).arg(map_saveEmployeeInfo["id_card"].mid(12, 2));
        query = QString(
            "update employee_info set real_name='%1',sex='%2',xm='%3',bm='%4',id_card='%5',hometown='%6',work_card='%7',"
            "entry_time='%8',position='%9',nation='%10',phone_num='%11',emergency_phone_num='%12',address='%13',degree='%14',"
            "major='%15',certificate='%16',job_title='%17',speciality='%18',state_of_health='%19',marriage='%20',"
            "political_status='%21',contract='%22',birthday='%23' where real_name='%24'"
        ).arg(map_saveEmployeeInfo["real_name"]).arg(map_saveEmployeeInfo["sex"]).arg(map_saveEmployeeInfo["xm"]).arg(map_saveEmployeeInfo["bm"])
            .arg(map_saveEmployeeInfo["id_card"]).arg(map_saveEmployeeInfo["hometown"]).arg(map_saveEmployeeInfo["work_card"])
            .arg(map_saveEmployeeInfo["entry_time"]).arg(map_saveEmployeeInfo["position"]).arg(map_saveEmployeeInfo["nation"])
            .arg(map_saveEmployeeInfo["phone_num"]).arg(map_saveEmployeeInfo["emergency_phone_num"]).arg(map_saveEmployeeInfo["address"])
            .arg(map_saveEmployeeInfo["degree"]).arg(map_saveEmployeeInfo["major"]).arg(map_saveEmployeeInfo["certificate"])
            .arg(map_saveEmployeeInfo["job_title"]).arg(map_saveEmployeeInfo["speciality"]).arg(map_saveEmployeeInfo["state_of_health"])
            .arg(map_saveEmployeeInfo["marriage"]).arg(map_saveEmployeeInfo["political_status"]).arg(map_saveEmployeeInfo["contract"])
            .arg(birthday).arg(map_saveEmployeeInfo["prev_name"]);
        execute(mysql, query);
        execute(mysql, "SET FOREIGN_KEY_CHECKS = 1");
        mysql_query(mysql, "commit");
        flag = Flag::FOR_SUCCESSFUL_SAVED_YGGL;
    }
    catch (MysqlError)
    {
        mysql_query(mysql, "rollback");
        flag = Flag::FOR_FAILED_SAVED;
    }

    return flag;

}

Forv_v_str_db Database::doForInsuranceInfo_db(QVector<QString> v_forInsuranceInfo) {

    Forv_v_str_db forv_v_str_db;
    QVector<QString> v_temp;
    QString sql_1 = "";
    QString sql_2 = "";
    QString sql_3 = "";

    if (v_forInsuranceInfo[1] == "全部人员") sql_1 = "(in_service is null or in_service is not null)";
    if (v_forInsuranceInfo[1] == "全部离职人员") sql_1 = "in_service='no'";
    if (v_forInsuranceInfo[1] == "全部在职人员") sql_1 = "in_service is null";
    if (v_forInsuranceInfo[1] == "本月离职人员") sql_1 = QString("in_service='no' and MONTH(leave_date)=%1").arg(QString::number(QDate::currentDate().month()));

    if (v_forInsuranceInfo[2] == "全部") sql_2 = "";
    if (v_forInsuranceInfo[2] == "有社保") sql_2 = "and social_security is not null";
    if (v_forInsuranceInfo[2] == "有工伤险") sql_2 = "and indstrl_injry_insrnce is not null";
    if (v_forInsuranceInfo[2] == "有意外险") sql_2 = "and accident_insrnce is not null";
    if (v_forInsuranceInfo[2] == "无三险") sql_2 = "and social_security is null and indstrl_injry_insrnce is null and accident_insrnce is null";

    if (v_forInsuranceInfo[3] == "年龄男在60周岁以下或女在50周岁以下")
        sql_3 = "and ((sex='男' and TIMESTAMPDIFF(YEAR, birthday, CURDATE())<=60) or (sex='女' and TIMESTAMPDIFF(YEAR, birthday, CURDATE())<=50))";
    if (v_forInsuranceInfo[3] == "不限男女，65周岁以下") sql_3 = "and TIMESTAMPDIFF(YEAR, birthday, CURDATE())<=65";
    if (v_forInsuranceInfo[3] == "不限男女，不限年龄") sql_3 = "";

    query = QString("select xm,real_name,sex,TIMESTAMPDIFF(YEAR, birthday, CURDATE()),social_security,indstrl_injry_insrnce,accident_insrnce,"
        "id_card,hometown,phone_num,in_service,leave_date from employee_info "
        "where %1 %2 %3 and xm='%4'").arg(sql_1).arg(sql_2).arg(sql_3).arg(v_forInsuranceInfo[0]);
    if (!mysql_query(mysql, query.toUtf8().data())) {
        res = mysql_store_result(mysql);
        while ((*column) = mysql_fetch_row(res)) {
            for (int i = 0; i < mysql_num_fields(res); ++i) {
                v_temp.push_back((*column)[i]);
            }
            forv_v_str_db.v_v_str.push_back(v_temp);
            v_temp.clear();
        }
        mysql_free_result(res);
    }
    forv_v_str_db.flag = Flag::FOR_INSURANCEINFO;
    return forv_v_str_db;

}

int Database::doForSaveInsuranceInfo_db(QVector<QString> v_saveInsuranceInfo) {

    int flag = 0;
    query = QString("update employee_info set social_security='%1',indstrl_injry_insrnce='%2',accident_insrnce='%3' where real_name='%4'")
        .arg(v_saveInsuranceInfo[1]).arg(v_saveInsuranceInfo[2]).arg(v_saveInsuranceInfo[3]).arg(v_saveInsuranceInfo[0]);
    if (!mysql_query(mysql, query.toUtf8().data())) {
        flag = Flag::FOR_SUCCESSFUL_SAVED_2_YGGL;
    }
    else {
        flag = Flag::FOR_FAILED_SAVED;
    }
    return flag;

}

Forv_v_str_db Database::doForSendTotal_db(QVector<QString> v_sendTotal) {

    Forv_v_str_db forv_v_str_db;
    forv_v_str_db.flag = Flag::FOR_SENDTOTAL;
    QVector<QString> v_temp;

    QString str_sql1 = "";
    if (v_sendTotal[0] == "义乌本地") str_sql1 = "LOCATE('义乌', hometown) > 0 or null";
    if (v_sendTotal[0] == "浙江省") str_sql1 = "LOCATE('浙江', hometown) > 0 or LOCATE('义乌', hometown) > 0 or null";
    if (v_sendTotal[0] == "外省") str_sql1 = "(LOCATE('浙江', hometown) = 0 and LOCATE('义乌', hometown) = 0) or null";
    QString str_sql2 = "";
    if (v_sendTotal[1] == "汉族") str_sql2 = "LOCATE('汉', nation) > 0 or null";
    if (v_sendTotal[1] == "少数民族") str_sql2 = "LOCATE('汉', nation) = 0 or null";

    if (v_sendTotal[5] == "初级工程师") v_sendTotal[5] = "初级";
    if (v_sendTotal[5] == "中级工程师") v_sendTotal[5] = "中级";
    if (v_sendTotal[5] == "高级工程师") v_sendTotal[5] = "高级";

    if (v_sendTotal[6] == "建(构)筑物消防员证") v_sendTotal[5] = "物消防员";
    if (v_sendTotal[6] == "消防管理员证") v_sendTotal[5] = "消防管理员";
    if (v_sendTotal[6] == "电工证") v_sendTotal[5] = "电工";
    if (v_sendTotal[6] == "特种设备证") v_sendTotal[5] = "特种设备";
    if (v_sendTotal[6] == "保安证") v_sendTotal[5] = "保安";

    QString str_sql3 = "";
    if (v_sendTotal[7] == "本月离职") str_sql3 = QString("in_service='no' and month(leave_date)=%1 or null").arg(QString::number(QDate::currentDate().month()));
    if (v_sendTotal[7] == "本年离职") str_sql3 = QString("in_service='no' and year(leave_date)=%1 or null").arg(QString::number(QDate::currentDate().year()));

    for (auto it = project.cbegin(); it != project.cend(); ++it) {
        query = QString("select count(in_service is null or null),count(if(contract is not null and contract!='', 1, null)),"
            "count((TIMESTAMPDIFF(YEAR, birthday, CURDATE())>60 and sex='男') or (TIMESTAMPDIFF(YEAR, birthday, CURDATE())>50 and sex='女') or null),"
            "count(bm='客服部' or null),count(bm='工程部' or null),"
            "count(bm='秩序维护部' or null),count(bm='环境部绿化' or null),count(bm='环境部保洁' or null),count(bm='行政部' or null),"
            "count(bm='项目经理' or null),count(bm='后勤部' or null),count(%1),count(%2),count(sex='%3' or null),count(marriage='%4' or null),"
            "count(LOCATE('%5', degree) > 0 or null),count(LOCATE('%6', job_title) > 0 or null),count(LOCATE('%7', certificate) > 0 or null),"
            "count(political_status='共产党员' or null),count(social_security is not null and social_security!='' or null),"
            "count(indstrl_injry_insrnce is not null and indstrl_injry_insrnce!='' or null),"
            "count(accident_insrnce is not null and accident_insrnce!='' or null),count(%8) from employee_info where xm='%9'")
            .arg(str_sql1).arg(str_sql2).arg(v_sendTotal[2]).arg(v_sendTotal[3]).arg(v_sendTotal[4])
            .arg(v_sendTotal[5]).arg(v_sendTotal[6]).arg(str_sql3).arg(*it);
        if (!mysql_query(mysql, query.toUtf8().data())) {
            res = mysql_store_result(mysql);
            while ((*column) = mysql_fetch_row(res)) {
                for (int i = 0; i < mysql_num_fields(res); ++i) {
                    v_temp.push_back((*column)[i]);
                }
                forv_v_str_db.v_v_str.push_back(v_temp);
                v_temp.clear();
            }
            mysql_free_result(res);
        }
    }

    return forv_v_str_db;

}

ForMenuTriggered_db Database::doForMenuTriggered_db(const QString& actText) {

    ForMenuTriggered_db forMenuTriggered_db;
    forMenuTriggered_db.flag = Flag::FOR_MENU_TOTALDATA;

    QString str_sql = "";

    if (actText == "义乌本地") { forMenuTriggered_db.col = 12; str_sql = "count(LOCATE('义乌', hometown) > 0 or null)"; }
    if (actText == "浙江省") { forMenuTriggered_db.col = 12; str_sql = "count(LOCATE('浙江', hometown) > 0 or LOCATE('义乌', hometown) > 0 or null)"; }
    if (actText == "外省") { forMenuTriggered_db.col = 12; str_sql = "count((LOCATE('浙江', hometown) = 0 and LOCATE('义乌', hometown) = 0) or null)"; }

    if (actText == "汉族") { forMenuTriggered_db.col = 13; str_sql = "count(LOCATE('汉', nation) > 0 or null)"; }
    if (actText == "少数民族") { forMenuTriggered_db.col = 13;  str_sql = "count(LOCATE('汉', nation) = 0 or null)"; }

    if (actText == "男") { forMenuTriggered_db.col = 14; str_sql = "count(sex='男' or null)"; }
    if (actText == "女") { forMenuTriggered_db.col = 14;  str_sql = "count(sex='女' or null)"; }

    if (actText == "已婚") { forMenuTriggered_db.col = 15; str_sql = "count(marriage='已婚' or null)"; }
    if (actText == "未婚") { forMenuTriggered_db.col = 15; str_sql = "count(marriage='未婚' or null)"; }

    if (actText == "研究生") { forMenuTriggered_db.col = 16;  str_sql = "count(LOCATE('研究生', degree) > 0 or null)"; }
    if (actText == "本科") { forMenuTriggered_db.col = 16; str_sql = "count(LOCATE('本科', degree) > 0 or null)"; }
    if (actText == "专科") { forMenuTriggered_db.col = 16; str_sql = "count(LOCATE('专科', degree) > 0 or null)"; }
    if (actText == "高中") { forMenuTriggered_db.col = 16; str_sql = "count(LOCATE('高中', degree) > 0 or null)"; }
    if (actText == "初中") { forMenuTriggered_db.col = 16; str_sql = "count(LOCATE('初中', degree) > 0 or null)"; }
    if (actText == "小学") { forMenuTriggered_db.col = 16; str_sql = "count(LOCATE('小学', degree) > 0 or null)"; }

    if (actText == "初级工程师") { forMenuTriggered_db.col = 17;  str_sql = "count(LOCATE('初级', job_title) > 0 or null)"; }
    if (actText == "中级工程师") { forMenuTriggered_db.col = 17;  str_sql = "count(LOCATE('中级', job_title) > 0 or null)"; }
    if (actText == "高级工程师") { forMenuTriggered_db.col = 17;  str_sql = "count(LOCATE('高级', job_title) > 0 or null)"; }

    if (actText == "建(构)筑物消防员证") { forMenuTriggered_db.col = 18;  str_sql = "count(LOCATE('物消防员', certificate) > 0 or null)"; }
    if (actText == "消防管理员证") { forMenuTriggered_db.col = 18; str_sql = "count(LOCATE('消防管理员', certificate) > 0 or null)"; }
    if (actText == "电工证") { forMenuTriggered_db.col = 18;  str_sql = "count(LOCATE('电工', certificate) > 0 or null)"; }
    if (actText == "特种设备证") { forMenuTriggered_db.col = 18;  str_sql = "count(LOCATE('特种设备', certificate) > 0 or null)"; }
    if (actText == "保安证") { forMenuTriggered_db.col = 18; str_sql = "count(LOCATE('保安', certificate) > 0 or null)"; }

    if (actText == "本月离职") {
        forMenuTriggered_db.col = 23; str_sql = QString("count(in_service='no' and month(leave_date)=%1 or null)")
            .arg(QString::number(QDate::currentDate().month()));
    }
    if (actText == "本年离职") {
        forMenuTriggered_db.col = 23; str_sql = QString("count(in_service='no' and year(leave_date)=%1 or null)")
            .arg(QString::number(QDate::currentDate().year()));
    }

    for (auto it = project.cbegin(); it != project.cend(); ++it) {
        query = QString("select %1 from employee_info where xm='%2'").arg(str_sql).arg(*it);
        if (!mysql_query(mysql, query.toUtf8().data())) {
            res = mysql_store_result(mysql);
            while ((*column) = mysql_fetch_row(res)) {
                for (int i = 0; i < mysql_num_fields(res); ++i) {
                    forMenuTriggered_db.totalData_oneCol.push_back((*column)[i]);
                }
            }
            mysql_free_result(res);
        }
    }

    return forMenuTriggered_db;

}

//void Database::putInTestDateForEmployee() {
//
//	QString strFile = "C:/Users/HUAWEI/Desktop/员工.xlsx";
//	Book* book = NULL;
//	book = xlCreateXMLBook();
//	const wchar_t* wstr = reinterpret_cast<const wchar_t*>(strFile.utf16());
//	bool f = book->load(wstr);
//	if (book) {
//		Sheet* sheet = book->getSheet(0);
//		qDebug() << sheet->lastRow();
//		for (int i = 0; i < sheet->lastRow(); i++) {
//			query = QString("insert into employee_info(real_name, xm, bm) values('%1', '%2', '%3');")
//				.arg(QString::fromWCharArray(sheet->readStr(i, 0)))
//				.arg(QString::fromWCharArray(sheet->readStr(i, 1)))
//				.arg(QString::fromWCharArray(sheet->readStr(i, 2)));
//			mysql_query(mysql, query.toUtf8().data());
//
//			query = QString("insert into employee_schedule(real_name) values('%1');")
//				.arg(QString::fromWCharArray(sheet->readStr(i, 0)));
//			mysql_query(mysql, query.toUtf8().data());
//
//			query = QString("insert into employee_attendance(real_name) values('%1');")
//				.arg(QString::fromWCharArray(sheet->readStr(i, 0)));
//			mysql_query(mysql, query.toUtf8().data());
//		}
//		delete book; book = NULL;
//	}
//}

