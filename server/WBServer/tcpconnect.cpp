#include "tcpconnect.h"

TcpConnect::TcpConnect(QWidget* parent)
	: QWidget(parent)
{

	this->setObjectName(QString::fromUtf8("ServerTCP"));
	this->resize(600, 400);

	horizontalLayout = new QHBoxLayout(this);
	horizontalLayout->setSpacing(6);
	horizontalLayout->setContentsMargins(11, 11, 11, 11);
	horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

	this->setLayout(horizontalLayout);

	textReadOnly = new QTextEdit(this);
	textReadOnly->setObjectName(QString::fromUtf8("textReadOnly"));
	textReadOnly->setReadOnly(true);
	textReadOnly->setFocusPolicy(Qt::FocusPolicy::NoFocus);

	horizontalLayout->addWidget(textReadOnly);

    database = NULL;
    database = new Database();
    server = NULL;
    server = new QTcpServer();
    host_info = "";
    sizePackLast = 0;

    connect(server, &QTcpServer::newConnection, this, &TcpConnect::onNewConnection);

    bool ok = server->listen(QHostAddress::Any, SERVER_PORT);
    qDebug() << "listen:" << ok;
}

TcpConnect::~TcpConnect()
{
    delete server;
    server = NULL;
    delete database;
    database = NULL;
}

void TcpConnect::onNewConnection() {

    QTcpSocket* socket = server->nextPendingConnection();
    clients.append(socket);

    host_info = QString("connected with Client(IP:[%1],PORT:[%2])").arg(socket->peerAddress().toString()).arg(socket->peerPort());
    textReadOnly->append("<p>" + host_info + "</p><br>");

    connect(socket, &QTcpSocket::readyRead, this, &TcpConnect::onReadyRead);
    connect(socket, &QTcpSocket::disconnected, this, &TcpConnect::onDisconnected);
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onError(QAbstractSocket::SocketError)));

}

void TcpConnect::onReadyRead() {

    QObject* obj = this->sender();
    QTcpSocket* socket = qobject_cast<QTcpSocket*>(obj);

    QByteArray dataFull;
    quint64 sizeNow = 0;

    do {
        sizeNow = socket->bytesAvailable();

        QDataStream stream(socket);

        if (sizePackLast == 0) {
            if (sizeNow < sizeof(quint32))
                return;

            stream >> sizePackLast;
        }

        if (sizeNow < sizePackLast - 4) {
            return;
        }

        qDebug() << "full pack";

        int className = 0;
        stream >> className;
        qDebug() << className;

        switch (className)
        {
        case ClassName::USERNMPWD:handleLogin_getData(socket, stream); break;
        case ClassName::REGISTERINFO:handleRegister_getData(socket, stream); break;
        case ClassName::CHGPWDINFO:handleChgPwd_getData(socket, stream); break;
        case ClassName::FORBTNATTNDNCE:handleForAttndnce_getData(socket, stream); break;
        case ClassName::FORBTNSCHEDULE:handleForSchedule_getData(socket, stream); break;
        case ClassName::ATTENDDATA:handleAttendData_getData(socket, stream); break;
        case ClassName::SCHEDULEDATA:handleScheduleData_getData(socket, stream); break;
        case ClassName::PURCHASEDATA:handlePurchaseData_getData(socket, stream); break;
        case ClassName::FORBTNSUBMIT:handleForSubmit_getData(socket, stream); break;
        case ClassName::FORBTNOPEN:handleForOpen_getData(socket, stream); break;
        case ClassName::FORSTATEDATA:handleForState_getData(socket, stream); break;
        case ClassName::COSTANDDATE:handleForCostAndDate_getData(socket, stream); break;
        case ClassName::FORBTNDELETE:handleForDelete_getData(socket, stream); break;
        case ClassName::FORSENDENTRYDATA:handleForEntryData_getData(socket, stream); break;
        case ClassName::FORSENDCHANGEDATA:handleForChangeData_getData(socket, stream); break;
        case ClassName::FORSENDCHANGENAME:handleForChangeName_getData(socket, stream); break;
        case ClassName::FORSENDOUTDATA:handleForOutData_getData(socket, stream); break;
        case ClassName::FORSENDEMPLOYEEINFODATA:handleForEmployeeInfo_getData(socket, stream); break;
        case ClassName::FORSENDIMAGEDATA:handleForImageData_getData(socket, stream); break;
        case ClassName::FORSAVEEMPLOYEEINFO:handleForSaveEmployeeInfo_getData(socket, stream); break;
        case ClassName::FORINSURANCEINFO:handleForInsuranceInfo_getData(socket, stream); break;
        case ClassName::FORSAVEINSURANCEINFO:handleForSaveInsuranceInfo_getData(socket, stream); break;
        case ClassName::FORSENDTOTAL:handleForSendTotal_getData(socket, stream); break;
        case ClassName::FORMENUTRIGGERED:handleForMenuTriggered_getData(socket, stream); break;
        default:break;
        }

        sizePackLast = 0;

        sizeNow = socket->bytesAvailable();

    } while (sizeNow > 0);

}

void TcpConnect::onDisconnected() {

    QObject* obj = this->sender();
    QTcpSocket* socket = qobject_cast<QTcpSocket*>(obj);

    clients.removeAll(socket);

    socket->deleteLater();
    socket = NULL;

    qDebug() << "disconnected";

}

void TcpConnect::onError(QAbstractSocket::SocketError socketError) {

    qDebug() << "error:" << socketError;

}

void TcpConnect::handleLogin_getData(QTcpSocket* socket, QDataStream& stream) {

    struct UsernmPwd usernmPwd;
    stream >> usernmPwd.username >> usernmPwd.encrypted_password;

    UsedWhenLogin_db usedWhenLogin_db = database->doLogin_db(usernmPwd);

    QByteArray dataSend;
    QDataStream stream_send(&dataSend, QIODevice::WriteOnly);
    stream_send << (quint32)0 << usedWhenLogin_db.flag;
    if (usedWhenLogin_db.flag == Flag::FOR_PWD_TRUE) {
        stream_send << usedWhenLogin_db.user_name << usedWhenLogin_db.user_real_name << usedWhenLogin_db.work_card
            << usedWhenLogin_db.xm << usedWhenLogin_db.bm << usedWhenLogin_db.user_password;
    }
    stream_send.device()->seek(0);
    stream_send << dataSend.size();
    socket->write(dataSend);
    socket->flush();

}

void TcpConnect::handleRegister_getData(QTcpSocket* socket, QDataStream& stream) {

    struct RegisterInfo registerInfo;
    stream >> registerInfo.newUserName >> registerInfo.realName >> registerInfo.ghp
        >> registerInfo.zcxm >> registerInfo.szbm >> registerInfo.password >> registerInfo.encrypted_password;

    int flag = database->doRegister_db(registerInfo);

    QByteArray dataSend;
    QDataStream stream_send(&dataSend, QIODevice::WriteOnly);
    stream_send << (quint32)0 << flag;
    stream_send.device()->seek(0);
    stream_send << dataSend.size();
    socket->write(dataSend);
    socket->flush();

}

void TcpConnect::handleChgPwd_getData(QTcpSocket* socket, QDataStream& stream) {

    struct ChgPwdInfo chgPwdInfo;
    stream >> chgPwdInfo.UserName >> chgPwdInfo.encrypted_oldPassword
        >> chgPwdInfo.ghp >> chgPwdInfo.newPassword >> chgPwdInfo.encrypted_newPassword;

    int flag = database->doChgPwd_db(chgPwdInfo);

    QByteArray dataSend;
    QDataStream stream_send(&dataSend, QIODevice::WriteOnly);
    stream_send << (quint32)0 << flag;
    stream_send.device()->seek(0);
    stream_send << dataSend.size();
    socket->write(dataSend);
    socket->flush();

}

void TcpConnect::handleForAttndnce_getData(QTcpSocket* socket, QDataStream& stream) {

    QVector<QVector<QString>> v_v_BtnSaveClicked;
    stream >> v_v_BtnSaveClicked;

    int flag = database->doForAttndnce_db(v_v_BtnSaveClicked);

    QByteArray dataSend;
    QDataStream stream_send(&dataSend, QIODevice::WriteOnly);
    stream_send << (quint32)0 << flag;
    stream_send.device()->seek(0);
    stream_send << dataSend.size();
    socket->write(dataSend);
    socket->flush();

}

void TcpConnect::handleForSchedule_getData(QTcpSocket* socket, QDataStream& stream) {

    QVector<QVector<QString>> v_v_forSche;
    stream >> v_v_forSche;

    int flag = database->doForSchedule_db(v_v_forSche);

    QByteArray dataSend;
    QDataStream stream_send(&dataSend, QIODevice::WriteOnly);
    stream_send << (quint32)0 << flag;
    stream_send.device()->seek(0);
    stream_send << dataSend.size();
    socket->write(dataSend);
    socket->flush();

}

void TcpConnect::handleAttendData_getData(QTcpSocket* socket, QDataStream& stream) {

    QString pro = "";
    int day = 0;
    stream >> pro >> day;

    ForMap_db forAttndnce_db = database->getAttendanceDate(pro, day);

    QByteArray dataSend;
    QDataStream stream_send(&dataSend, QIODevice::WriteOnly);
    stream_send << (quint32)0 << forAttndnce_db.flag << forAttndnce_db.map;
    stream_send.device()->seek(0);
    stream_send << dataSend.size();
    socket->write(dataSend);
    socket->flush();

}

void TcpConnect::handleScheduleData_getData(QTcpSocket* socket, QDataStream& stream) {

    QString pro = "";
    stream >> pro;

    ForMap_db forSchedule_db = database->getScheduleDate(pro);

    QByteArray dataSend;
    QDataStream stream_send(&dataSend, QIODevice::WriteOnly);
    stream_send << (quint32)0 << forSchedule_db.flag << forSchedule_db.map;
    stream_send.device()->seek(0);
    stream_send << dataSend.size();
    socket->write(dataSend);
    socket->flush();

}

void TcpConnect::handlePurchaseData_getData(QTcpSocket* socket, QDataStream& stream) {
    QString pro = ""; int year = 0; int month = 0; int state = 0;
    stream >> pro >> year >> month >> state;
    Forv_v_str_db forv_v_str_db = database->getPurchaseDate(pro, year, month, state);
    QByteArray dataSend;
    QDataStream stream_send(&dataSend, QIODevice::WriteOnly);
    stream_send << (quint32)0 << forv_v_str_db.flag << forv_v_str_db.v_v_str;
    stream_send.device()->seek(0);
    stream_send << dataSend.size();
    socket->write(dataSend);
    socket->flush();
}

void TcpConnect::handleForSubmit_getData(QTcpSocket* socket, QDataStream& stream) {
    QVector<QVector<QString>> v_v_tableDate;
    stream >> v_v_tableDate;

    int flag = database->doForSubmit_db(v_v_tableDate);

    QByteArray dataSend;
    QDataStream stream_send(&dataSend, QIODevice::WriteOnly);
    stream_send << (quint32)0 << flag;
    stream_send.device()->seek(0);
    stream_send << dataSend.size();
    socket->write(dataSend);
    socket->flush();

}

void TcpConnect::handleForOpen_getData(QTcpSocket* socket, QDataStream& stream) {
    QString purchase_id = "";
    stream >> purchase_id;

    Forv_v_str_db forv_v_str_db = database->doForOpen_db(purchase_id);

    QByteArray dataSend;
    QDataStream stream_send(&dataSend, QIODevice::WriteOnly);
    stream_send << (quint32)0 << forv_v_str_db.flag << forv_v_str_db.v_v_str;
    stream_send.device()->seek(0);
    stream_send << dataSend.size();
    socket->write(dataSend);
    socket->flush();

}

void TcpConnect::handleForState_getData(QTcpSocket* socket, QDataStream& stream) {

    QString pro_date = ""; int state = 0; int index = 0;  QString name = ""; QVector<QString> advice;
    stream >> pro_date >> state >> index >> name >> advice;

    int flag = database->doForState(pro_date, state, index, name, advice);

    QByteArray dataSend;
    QDataStream stream_send(&dataSend, QIODevice::WriteOnly);
    stream_send << (quint32)0 << flag;
    stream_send.device()->seek(0);
    stream_send << dataSend.size();
    socket->write(dataSend);
    socket->flush();

}

void TcpConnect::handleForCostAndDate_getData(QTcpSocket* socket, QDataStream& stream) {

    QVector<QString> v_forCostAndDate;
    stream >> v_forCostAndDate;

    int flag = database->doForCostAndDate(v_forCostAndDate);

    QByteArray dataSend;
    QDataStream stream_send(&dataSend, QIODevice::WriteOnly);
    stream_send << (quint32)0 << flag;
    stream_send.device()->seek(0);
    stream_send << dataSend.size();
    socket->write(dataSend);
    socket->flush();

}

void TcpConnect::handleForDelete_getData(QTcpSocket* socket, QDataStream& stream) {

    QString id = "";
    stream >> id;

    int flag = database->doForDelete_db(id);

    QByteArray dataSend;
    QDataStream stream_send(&dataSend, QIODevice::WriteOnly);
    stream_send << (quint32)0 << flag;
    stream_send.device()->seek(0);
    stream_send << dataSend.size();
    socket->write(dataSend);
    socket->flush();

}

void TcpConnect::handleForEntryData_getData(QTcpSocket* socket, QDataStream& stream) {

    QVector<QString> v_sendEntryData; QByteArray data;
    stream >> v_sendEntryData >> data;

    int flag = database->doForEntryData_db(v_sendEntryData, data);

    QByteArray dataSend;
    QDataStream stream_send(&dataSend, QIODevice::WriteOnly);
    stream_send << (quint32)0 << flag;
    stream_send.device()->seek(0);
    stream_send << dataSend.size();
    socket->write(dataSend);
    socket->flush();

}

void TcpConnect::handleForChangeData_getData(QTcpSocket* socket, QDataStream& stream) {

    QVector<QString> v_sendChangeData;
    stream >> v_sendChangeData;

    int flag = database->doForChangeData_db(v_sendChangeData);

    QByteArray dataSend;
    QDataStream stream_send(&dataSend, QIODevice::WriteOnly);
    stream_send << (quint32)0 << flag;
    stream_send.device()->seek(0);
    stream_send << dataSend.size();
    socket->write(dataSend);
    socket->flush();

}

void TcpConnect::handleForChangeName_getData(QTcpSocket* socket, QDataStream& stream) {

    QString name = "";
    stream >> name;

    QVector<QString> flag_pro = database->doForChangeName_db(name);

    QByteArray dataSend;
    QDataStream stream_send(&dataSend, QIODevice::WriteOnly);
    stream_send << (quint32)0 << flag_pro[0].toInt() << flag_pro[1];
    stream_send.device()->seek(0);
    stream_send << dataSend.size();
    socket->write(dataSend);
    socket->flush();

}

void TcpConnect::handleForOutData_getData(QTcpSocket* socket, QDataStream& stream) {

    QVector<QString> v_sendOutData;
    stream >> v_sendOutData;

    int flag = database->doForOutData_db(v_sendOutData);

    QByteArray dataSend;
    QDataStream stream_send(&dataSend, QIODevice::WriteOnly);
    stream_send << (quint32)0 << flag;
    stream_send.device()->seek(0);
    stream_send << dataSend.size();
    socket->write(dataSend);
    socket->flush();

}

void TcpConnect::handleForEmployeeInfo_getData(QTcpSocket* socket, QDataStream& stream) {

    QVector<QString> v_forEmployeeInfoData;
    stream >> v_forEmployeeInfoData;

    Forv_v_str_db forv_v_str_db = database->doForGetEmployeeInfoData_db(v_forEmployeeInfoData);

    QByteArray dataSend;
    QDataStream stream_send(&dataSend, QIODevice::WriteOnly);
    stream_send << (quint32)0 << forv_v_str_db.flag << forv_v_str_db.v_v_str;
    stream_send.device()->seek(0);
    stream_send << dataSend.size();
    socket->write(dataSend);
    socket->flush();

}

void TcpConnect::handleForImageData_getData(QTcpSocket* socket, QDataStream& stream) {

    QString name = "";
    stream >> name;

    QString address = database->doForGetImageData_db(name);

    int flag = Flag::IMAGEDATA;
    QFile file(QString("employee_pic/%1.png").arg(name));
    if (file.open(QIODevice::ReadOnly) == false) {
        file.close();
        file.setFileName(QString("employee_pic/%1.jpg").arg(name));
        if (file.open(QIODevice::ReadOnly) == false) {
            file.close();
            file.setFileName(QString("employee_pic/%1.bmp").arg(name));
            file.open(QIODevice::ReadOnly);
        }
    }
    QByteArray data = file.readAll();
    QString pic_format = "";
    for (int i = file.fileName().lastIndexOf('.') + 1; i < file.fileName().length(); ++i) {
        pic_format += file.fileName()[i];
    }
    file.close();

    QByteArray dataSend;
    QDataStream stream_send(&dataSend, QIODevice::WriteOnly);
    stream_send << (quint32)0 << flag << pic_format << data << address;
    stream_send.device()->seek(0);
    stream_send << dataSend.size();
    socket->write(dataSend);
    socket->flush();

}

void TcpConnect::handleForSaveEmployeeInfo_getData(QTcpSocket* socket, QDataStream& stream) {

    QMap<QString, QString> map_saveEmployeeInfo; QByteArray data;
    stream >> map_saveEmployeeInfo >> data;

    int flag = database->doForSaveEmployeeInfo_db(map_saveEmployeeInfo, data);

    QByteArray dataSend;
    QDataStream stream_send(&dataSend, QIODevice::WriteOnly);
    stream_send << (quint32)0 << flag;
    stream_send.device()->seek(0);
    stream_send << dataSend.size();
    socket->write(dataSend);
    socket->flush();

}

void TcpConnect::handleForInsuranceInfo_getData(QTcpSocket* socket, QDataStream& stream) {

    QVector<QString> v_forInsuranceInfo;
    stream >> v_forInsuranceInfo;

    Forv_v_str_db forv_v_str_db = database->doForInsuranceInfo_db(v_forInsuranceInfo);

    QByteArray dataSend;
    QDataStream stream_send(&dataSend, QIODevice::WriteOnly);
    stream_send << (quint32)0 << forv_v_str_db.flag << forv_v_str_db.v_v_str;
    stream_send.device()->seek(0);
    stream_send << dataSend.size();
    socket->write(dataSend);
    socket->flush();

}

void TcpConnect::handleForSaveInsuranceInfo_getData(QTcpSocket* socket, QDataStream& stream) {

    QVector<QString> v_saveInsuranceInfo;
    stream >> v_saveInsuranceInfo;

    int flag = database->doForSaveInsuranceInfo_db(v_saveInsuranceInfo);

    QByteArray dataSend;
    QDataStream stream_send(&dataSend, QIODevice::WriteOnly);
    stream_send << (quint32)0 << flag;
    stream_send.device()->seek(0);
    stream_send << dataSend.size();
    socket->write(dataSend);
    socket->flush();

}

void TcpConnect::handleForSendTotal_getData(QTcpSocket* socket, QDataStream& stream) {

    QVector<QString> v_sendTotal;
    stream >> v_sendTotal;

    Forv_v_str_db forv_v_str_db = database->doForSendTotal_db(v_sendTotal);

    QByteArray dataSend;
    QDataStream stream_send(&dataSend, QIODevice::WriteOnly);
    stream_send << (quint32)0 << forv_v_str_db.flag << forv_v_str_db.v_v_str;
    stream_send.device()->seek(0);
    stream_send << dataSend.size();
    socket->write(dataSend);
    socket->flush();

}

void TcpConnect::handleForMenuTriggered_getData(QTcpSocket* socket, QDataStream& stream) {

    QString actText = "";
    stream >> actText;

    ForMenuTriggered_db forMenuTriggered_db = database->doForMenuTriggered_db(actText);

    QByteArray dataSend;
    QDataStream stream_send(&dataSend, QIODevice::WriteOnly);
    stream_send << (quint32)0 << forMenuTriggered_db.flag << forMenuTriggered_db.totalData_oneCol << forMenuTriggered_db.col;
    stream_send.device()->seek(0);
    stream_send << dataSend.size();
    socket->write(dataSend);
    socket->flush();

}
