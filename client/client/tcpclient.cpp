#include "tcpclient.h"

TcpClient::TcpClient(QWidget* parent)
	: QWidget(parent)
{
	this->setObjectName(QString::fromUtf8("TcpClientClass"));
	QMetaObject::connectSlotsByName(this);
	this->resize(600, 400);
	this->setWindowTitle(QString::fromUtf8("作者"));

	horizontalLayout = new QHBoxLayout(this);
	horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
	horizontalLayout->setSpacing(6);
	horizontalLayout->setContentsMargins(11, 11, 11, 11);
	this->setLayout(horizontalLayout);

	label = new QLabel(this);
	label->setObjectName(QString::fromUtf8("label"));
	label->setText(QString::fromUtf8("Zihuatanejo"));
	label->setAlignment(Qt::Alignment::enum_type::AlignCenter);
	label->setFont(QFont("Arial", 30));

	horizontalLayout->addWidget(label);
	//以上ui

	login = NULL;
	homepage = NULL;
	login = new Login();
	homepage = new Homepage();
	tcpSocket = NULL;
	tcpSocket = new QTcpSocket(this);
	sizePackLast = 0;

	//连接到服务器(server)
	tcpSocket->connectToHost(QHostAddress(SERVER_IP), SERVER_PORT);

	//用于连接的信号和槽
	connect(tcpSocket, &QTcpSocket::readyRead, this, &TcpClient::onReadyRead);
	connect(tcpSocket, &QTcpSocket::connected, this, &TcpClient::onConnected);
	connect(tcpSocket, &QTcpSocket::disconnected, this, &TcpClient::onDisconnected);
	connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onError(QAbstractSocket::SocketError)));

	login->show();

	connect(login, &Login::sig_register, this, &TcpClient::onsig_register);
	connect(login, &Login::sig_change, this, &TcpClient::onsig_change);
	connect(login, &Login::sig_login, this, &TcpClient::onsig_login);

	connect(this, &TcpClient::sig_forUserNameExist, login->rgstr, &Rgstr::onsig_forUserNameExist);
	connect(this, &TcpClient::sig_forSOrFCreated, login->rgstr, &Rgstr::onsig_forSOrFCreated);
	connect(this, &TcpClient::sig_forWrongOrSuccess, login->chgPwd, &ChgPwd::onsig_forWrongOrSuccess);
	connect(this, &TcpClient::sig_forPwdTrue, homepage, &Homepage::onsig_forPwdTrue);

	connect(homepage, &Homepage::sig_sendAttendData, this, &TcpClient::onsig_sendAttendData);
	connect(homepage, &Homepage::sig_sendScheduleData, this, &TcpClient::onsig_sendScheduleData);
	connect(this, &TcpClient::signalFor_solutionForAttendanceInit, homepage, &Homepage::receiveAttendData);
	connect(this, &TcpClient::signalFor_solutionForScheduleInit, homepage, &Homepage::receiveScheduleData);
	connect(homepage, &Homepage::sig_save, this, &TcpClient::onsig_save);
	connect(homepage, &Homepage::sig_save_2, this, &TcpClient::onsig_save_2);

	connect(homepage, &Homepage::sig_sendPurchaseData, this, &TcpClient::onsig_sendPurchaseData);
	connect(this, &TcpClient::signalFor_solutionForPurchaseInit, homepage, &Homepage::receivePurchaseData);
	connect(homepage, &Homepage::sig_forSubmit, this, &TcpClient::onsig_forSubmit);
	connect(homepage, &Homepage::sig_btnOpenClicked, this, &TcpClient::onsig_btnOpenClicked);
	connect(this, &TcpClient::signalFor_solutionForBtnOpen, homepage, &Homepage::receiveOpenDate);
	connect(this, &TcpClient::sig_forSuccessfulSubmit, homepage, &Homepage::onsig_forSuccessfulSubmit);
	connect(homepage, &Homepage::sig_sendStateData, this, &TcpClient::onsig_sendStateData);
	connect(this, &TcpClient::sig_forState, homepage, &Homepage::onsig_forState);
	connect(homepage, &Homepage::sig_forCostAndDate, this, &TcpClient::onsig_forCostAndDate);
	connect(homepage, &Homepage::sig_forDelete, this, &TcpClient::onsig_forDelete);
	connect(this, &TcpClient::sig_forSuccessfulDelete, homepage, &Homepage::onsig_forSuccessfulDelete);

	connect(homepage, &Homepage::sig_sendEntryData, this, &TcpClient::onsig_sendEntryData);
	connect(homepage, &Homepage::sig_sendChangeData, this, &TcpClient::onsig_sendChangeData);
	connect(homepage, &Homepage::sig_sendChangeName, this, &TcpClient::onsig_sendChangeName);
	connect(this, &TcpClient::signalFor_solutionForChangeName, homepage, &Homepage::receiveChangeName);
	connect(homepage, &Homepage::sig_sendOutData, this, &TcpClient::onsig_sendOutData);
	connect(this, &TcpClient::sig_forSuccessful_YGGL, homepage, &Homepage::onsig_forSuccessful_YGGL);
	connect(homepage, &Homepage::sig_forGetEmployeeInfoData, this, &TcpClient::onsig_forGetEmployeeInfoData);
	connect(this, &TcpClient::signalFor_solutionForEmployeeInfo, homepage, &Homepage::receiveEmployeeInfo);
	connect(homepage, &Homepage::sig_sendImageData, this, &TcpClient::onsig_sendImageData);
	connect(this, &TcpClient::signalFor_solutionForImageData, homepage, &Homepage::receiveImageData);
	connect(homepage, &Homepage::sig_saveEmployeeInfo, this, &TcpClient::onsig_saveEmployeeInfo);
	connect(homepage, &Homepage::sig_forGetInsuranceInfo, this, &TcpClient::onsig_forGetInsuranceInfo);
	connect(this, &TcpClient::signalFor_solutionForInsuranceInfo, homepage, &Homepage::receiveInsuranceInfo);
	connect(homepage, &Homepage::sig_saveInsuranceInfo, this, &TcpClient::onsig_saveInsuranceInfo);
	connect(homepage, &Homepage::sig_sendtotal, this, &TcpClient::onsig_sendtotal);
	connect(this, &TcpClient::signalFor_solutionForTotalData, homepage, &Homepage::receiveTotalData);
	connect(homepage, &Homepage::sig_menuTriggered, this, &TcpClient::onsig_menuTriggered);
	connect(this, &TcpClient::signalFor_solutionForMenuTotalData, homepage, &Homepage::receiveMenuTotalData);

}

TcpClient::~TcpClient() {
	if (login != NULL) { delete login; login = NULL; }
	delete homepage; homepage = NULL;
}

void TcpClient::onReadyRead() {

	QObject* obj = this->sender();
	QTcpSocket* socket = qobject_cast<QTcpSocket*>(obj);

	QByteArray dataFull;
	qint64 sizeNow = 0;

	do {
		//当前缓冲区内数据大小（收到的数据的大小）
		sizeNow = socket->bytesAvailable();

		QDataStream stream(socket);

		if (sizePackLast == 0) {
			if (sizeNow < sizeof(quint32))
				return;

			stream >> sizePackLast;
		}

		//如果包不完整
		if (sizeNow < sizePackLast - 4) {
			return;
		}

		qDebug() << "full pack";

		int flag = 0;
		stream >> flag;
		qDebug() << flag;

		switch (flag)
		{
		case Flag::FOR_PWD_FALSE:forPwdFalse();                     break;
		case Flag::FOR_PWD_TRUE:forPwdTrue(stream);                 break;
		case Flag::FOR_USER_NAME_EXIST:forUserNameExist();          break;
		case Flag::FOR_SUCCESSFUL_CREATED:forSuccessfulCreated();   break;
		case Flag::FOR_FAILED_CREATED:forFailedCreated();           break;  //以防万一出错
		case Flag::FOR_WRONG_INFO:forWrongInfo();                   break;
		case Flag::FOR_SUCCESSFUL_CHANGED:forSuccessfulChanged();   break;
		case Flag::FOR_ATTENDANCE_INIT:forAttendanceInit(stream);   break;
		case Flag::FOR_SCHEDULE_INIT:forScheduleInit(stream);       break;
		case Flag::FOR_SUCCESSFUL_SAVED:forSuccessfulSaved();       break;
		case Flag::FOR_FAILED_SAVED:forFailedSaved();               break;
		case Flag::FOR_SUCCESSFUL_SUBMIT:forSuccessfulSubmit();     break;
		case Flag::FOR_FAILED_SUBMIT:forFailedSubmit();             break;
		case Flag::FOR_PURCHASE_INIT:forPurchaseInit(stream);       break;
		case Flag::FOR_OPEN:forBtnOpen(stream);                     break;
		case Flag::FOR_STATE:forState();                            break;
		case Flag::FOR_SUCCESSFUL_DELETE:forSuccessfulDelete();     break;
		case Flag::FOR_REAL_NAME_EXIST:forRealNameExist();          break;
		case Flag::FOR_SUCCESSFUL_ENTRY:forSuccessfulEntry();       break;
		case Flag::FOR_SUCCESSFUL_CHANGED_YGGL:forSuccessfulChanged_YGGL();  break;
		case Flag::FOR_CHANGE_NAME:forChangeName_YGGL(stream);      break;
		case Flag::FOR_SUCCESSFUL_OUT:forSuccessfulOut();           break;
		case Flag::FOR_REAL_NAME_NOT_EXIST:forRealNameNotExist();   break;
		case Flag::FOR_OUT:forOut();                                break;
		case Flag::FOR_EMPLOYEEINFO:forEmployeeInfo(stream);        break;
		case Flag::IMAGEDATA:forImageData(stream);                  break;
		case Flag::FOR_SUCCESSFUL_SAVED_YGGL:forSuccessfulSaved_YGGL();      break;
		case Flag::FOR_INSURANCEINFO:forInsuranceInfo(stream);      break;
		case Flag::FOR_SUCCESSFUL_SAVED_2_YGGL:forSuccessfulSaved_2_YGGL();  break;
		case Flag::FOR_SENDTOTAL:forSendTotal(stream);              break;
		case Flag::FOR_MENU_TOTALDATA:forMenuTotalData(stream);     break;
		default:break;
		}

		sizePackLast = 0;//重置

		//判断剩下的字节数是否会有粘包的情况
		sizeNow = socket->bytesAvailable();

	} while (sizeNow > 0);

}

void TcpClient::onConnected() {

	qDebug() << QString("connected with Server(IP:[%1],PORT:[%2])").
		arg(tcpSocket->peerAddress().toString()).arg(tcpSocket->peerPort());

}

void TcpClient::onDisconnected() {

	tcpSocket = NULL;
	qDebug() << "disconnected";

}

void TcpClient::onError(QAbstractSocket::SocketError socketError) {

	qDebug() << "error:" << socketError;

}

void TcpClient::onsig_register(RegisterInfo registerInfo) {

	if (tcpSocket == NULL)
		return;

	QByteArray dataSend;
	QDataStream stream(&dataSend, QIODevice::WriteOnly);
	int className = ClassName::REGISTERINFO;
	stream << (quint32)0 << className << registerInfo.newUserName << registerInfo.realName << registerInfo.ghp
		<< registerInfo.zcxm << registerInfo.szbm << registerInfo.password << registerInfo.encrypted_password;
	stream.device()->seek(0);
	stream << dataSend.size();
	tcpSocket->write(dataSend);
	tcpSocket->flush();

}

void TcpClient::onsig_change(ChgPwdInfo chgPwdInfo) {

	if (tcpSocket == NULL)
		return;

	QByteArray dataSend;
	QDataStream stream(&dataSend, QIODevice::WriteOnly);
	int className = ClassName::CHGPWDINFO;
	stream << (quint32)0 << className << chgPwdInfo.UserName << chgPwdInfo.encrypted_oldPassword
		<< chgPwdInfo.ghp << chgPwdInfo.newPassword << chgPwdInfo.encrypted_newPassword;
	stream.device()->seek(0);
	stream << dataSend.size();
	tcpSocket->write(dataSend);
	tcpSocket->flush();

}

void TcpClient::onsig_login(UsernmPwd usernmPwd) {

	//md5加密
	char md5_str[MD5_STR_LEN + 1];
	std::string str = QString("Zihuatanejo").toStdString();
	Compute_string_md5((unsigned char*)str.c_str(), strlen(str.c_str()), md5_str);

	if ((usernmPwd.username == QString("Zihuatanejo"))
		&& (usernmPwd.encrypted_password == QString(md5_str))) {
		this->show();
		login->close();
		delete login; login = NULL;
		return;
	}
	if (tcpSocket == NULL)
		return;

	QByteArray dataSend;
	QDataStream stream(&dataSend, QIODevice::WriteOnly);
	int className = ClassName::USERNMPWD;
	stream << (quint32)0 << className << usernmPwd.username << usernmPwd.encrypted_password;
	stream.device()->seek(0);
	stream << dataSend.size();
	tcpSocket->write(dataSend);
	tcpSocket->flush();

}

void TcpClient::onsig_sendAttendData(const QString& pro, int day) {

	if (tcpSocket == NULL)
		return;

	QByteArray dataSend;
	QDataStream stream(&dataSend, QIODevice::WriteOnly);
	int className = ClassName::ATTENDDATA;
	stream << (quint32)0 << className << pro << day;
	stream.device()->seek(0);
	stream << dataSend.size();
	tcpSocket->write(dataSend);
	tcpSocket->flush();

}

void TcpClient::onsig_sendScheduleData(const QString& pro) {

	if (tcpSocket == NULL)
		return;

	QByteArray dataSend;
	QDataStream stream(&dataSend, QIODevice::WriteOnly);
	int className = ClassName::SCHEDULEDATA;
	stream << (quint32)0 << className << pro;
	stream.device()->seek(0);
	stream << dataSend.size();
	tcpSocket->write(dataSend);
	tcpSocket->flush();

}

void TcpClient::forPwdFalse() {
	QMessageBox box(QMessageBox::Information, "提示", "用户名与密码不匹配！");
	box.setStandardButtons(QMessageBox::Ok);
	box.setButtonText(QMessageBox::Ok, QString("确 定"));
	box.setWindowIcon(QPixmap("Resources/logo.png"));
	int button = box.exec();
}
void TcpClient::forUserNameExist() {
	QMessageBox box(QMessageBox::Information, "提示", "用户名已存在！");
	box.setStandardButtons(QMessageBox::Ok);
	box.setButtonText(QMessageBox::Ok, QString("确 定"));
	box.setWindowIcon(QPixmap("Resources/logo.png"));
	int button = box.exec();
	emit sig_forUserNameExist();
}
void TcpClient::forSuccessfulCreated() {
	QMessageBox box(QMessageBox::Information, "提示", "用户创建成功！");
	box.setStandardButtons(QMessageBox::Ok);
	box.setButtonText(QMessageBox::Ok, QString("确 定"));
	box.setWindowIcon(QPixmap("Resources/logo.png"));
	int button = box.exec();
	emit sig_forSOrFCreated();
}
void TcpClient::forFailedCreated() {
	QMessageBox box(QMessageBox::Information, "提示", "用户创建失败，请重试！");
	box.setStandardButtons(QMessageBox::Ok);
	box.setButtonText(QMessageBox::Ok, QString("确 定"));
	box.setWindowIcon(QPixmap("Resources/logo.png"));
	int button = box.exec();
	emit sig_forSOrFCreated();
}
void TcpClient::forWrongInfo() {
	QMessageBox box(QMessageBox::Information, "提示", "用户信息填写错误！");
	box.setStandardButtons(QMessageBox::Ok);
	box.setButtonText(QMessageBox::Ok, QString("确 定"));
	box.setWindowIcon(QPixmap("Resources/logo.png"));
	int button = box.exec();
	emit sig_forWrongOrSuccess();
}
void TcpClient::forSuccessfulChanged() {
	QMessageBox box(QMessageBox::Information, "提示", "用户密码修改成功！");
	box.setStandardButtons(QMessageBox::Ok);
	box.setButtonText(QMessageBox::Ok, QString("确 定"));
	box.setWindowIcon(QPixmap("Resources/logo.png"));
	int button = box.exec();
	emit sig_forWrongOrSuccess();
}
void TcpClient::forSuccessfulSaved() {
	QMessageBox box(QMessageBox::Information, "提示", "保存成功！");
	box.setStandardButtons(QMessageBox::Ok);
	box.setButtonText(QMessageBox::Ok, QString("确 定"));
	box.setWindowIcon(QPixmap("Resources/logo.png"));
	int button = box.exec();
}
void TcpClient::forFailedSaved() {
	QMessageBox box(QMessageBox::Information, "提示", "保存失败！");
	box.setStandardButtons(QMessageBox::Ok);
	box.setButtonText(QMessageBox::Ok, QString("确 定"));
	box.setWindowIcon(QPixmap("Resources/logo.png"));
	int button = box.exec();
}
void TcpClient::forSuccessfulSubmit() {
	emit sig_forSuccessfulSubmit();
}
void TcpClient::forFailedSubmit() {
	QMessageBox box(QMessageBox::Information, "提示", "提交失败！");
	box.setStandardButtons(QMessageBox::Ok);
	box.setButtonText(QMessageBox::Ok, QString("确 定"));
	box.setWindowIcon(QPixmap("Resources/logo.png"));
	int button = box.exec();
}
void TcpClient::forState() {
	emit sig_forState();
}
void TcpClient::forSuccessfulDelete() {
	emit sig_forSuccessfulDelete();
}
void TcpClient::forRealNameExist() {
	QMessageBox box(QMessageBox::Information, "提示", "请勿重复入职！");
	box.setStandardButtons(QMessageBox::Ok);
	box.setButtonText(QMessageBox::Ok, QString("确 定"));
	box.setWindowIcon(QPixmap("Resources/logo.png"));
	int button = box.exec();
}

void TcpClient::forSuccessfulEntry() {
	QMessageBox box(QMessageBox::Information, "提示", "恭喜入职成功！");
	box.setStandardButtons(QMessageBox::Ok);
	box.setButtonText(QMessageBox::Ok, QString("确 定"));
	box.setWindowIcon(QPixmap("Resources/logo.png"));
	int button = box.exec();
	emit sig_forSuccessful_YGGL("entry");
}

void TcpClient::forSuccessfulChanged_YGGL() {
	QMessageBox box(QMessageBox::Information, "提示", "调动成功！");
	box.setStandardButtons(QMessageBox::Ok);
	box.setButtonText(QMessageBox::Ok, QString("确 定"));
	box.setWindowIcon(QPixmap("Resources/logo.png"));
	int button = box.exec();
	emit sig_forSuccessful_YGGL("change");
}

void TcpClient::forSuccessfulOut() {
	QMessageBox box(QMessageBox::Information, "提示", "离职成功！");
	box.setStandardButtons(QMessageBox::Ok);
	box.setButtonText(QMessageBox::Ok, QString("确 定"));
	box.setWindowIcon(QPixmap("Resources/logo.png"));
	int button = box.exec();
	emit sig_forSuccessful_YGGL("out");
}

void TcpClient::forRealNameNotExist() {
	QMessageBox box(QMessageBox::Information, "提示", "本项目没有这个员工！");
	box.setStandardButtons(QMessageBox::Ok);
	box.setButtonText(QMessageBox::Ok, QString("确 定"));
	box.setWindowIcon(QPixmap("Resources/logo.png"));
	int button = box.exec();
}

void TcpClient::forOut() {
	QMessageBox box(QMessageBox::Information, "提示", "此员工已离职，不可重复操作！");
	box.setStandardButtons(QMessageBox::Ok);
	box.setButtonText(QMessageBox::Ok, QString("确 定"));
	box.setWindowIcon(QPixmap("Resources/logo.png"));
	int button = box.exec();
}

void TcpClient::forSuccessfulSaved_YGGL() {
	QMessageBox box(QMessageBox::Information, "提示", "保存成功！");
	box.setStandardButtons(QMessageBox::Ok);
	box.setButtonText(QMessageBox::Ok, QString("确 定"));
	box.setWindowIcon(QPixmap("Resources/logo.png"));
	int button = box.exec();
	emit sig_forSuccessful_YGGL("save1");
}

void TcpClient::forSuccessfulSaved_2_YGGL() {
	QMessageBox box(QMessageBox::Information, "提示", "保存成功！");
	box.setStandardButtons(QMessageBox::Ok);
	box.setButtonText(QMessageBox::Ok, QString("确 定"));
	box.setWindowIcon(QPixmap("Resources/logo.png"));
	int button = box.exec();
	emit sig_forSuccessful_YGGL("save2");
}

void TcpClient::forPwdTrue(QDataStream& stream) {

	login->close();
	delete login; login = NULL;
	homepage->show();

	//从数据库中取出用户信息
	UserInfo userInfo;
	userInfo.user_name = "";
	userInfo.user_real_name = "";
	userInfo.work_card = "";
	userInfo.xm = "";
	userInfo.bm = "";
	userInfo.user_password = "";
	stream >> userInfo.user_name >> userInfo.user_real_name >> userInfo.work_card >>
		userInfo.xm >> userInfo.bm >> userInfo.user_password;
	qDebug() << userInfo.user_name << userInfo.user_real_name << userInfo.work_card <<
		userInfo.xm << userInfo.bm << userInfo.user_password;

	emit sig_forPwdTrue(userInfo);

}

void TcpClient::forAttendanceInit(QDataStream& stream) {

	QMap<QString, QVector<QVector<QString>>> map_forAttndnce;
	stream >> map_forAttndnce;

	emit signalFor_solutionForAttendanceInit(map_forAttndnce);

}

void TcpClient::forScheduleInit(QDataStream& stream) {

	QMap<QString, QVector<QVector<QString>>> map_forSchedule;
	stream >> map_forSchedule;

	emit signalFor_solutionForScheduleInit(map_forSchedule);

}

void TcpClient::forPurchaseInit(QDataStream& stream) {

	QVector<QVector<QString>> v_v_forPurchase;
	stream >> v_v_forPurchase;

	emit signalFor_solutionForPurchaseInit(v_v_forPurchase);

}

void TcpClient::forBtnOpen(QDataStream& stream) {

	QVector<QVector<QString>> v_v_forOpen;
	stream >> v_v_forOpen;

	emit signalFor_solutionForBtnOpen(v_v_forOpen);

}

void TcpClient::forChangeName_YGGL(QDataStream& stream) {

	QString pro = "";
	stream >> pro;

	emit signalFor_solutionForChangeName(pro);

}

void TcpClient::forEmployeeInfo(QDataStream& stream) {

	QVector<QVector<QString>> employeeInfoData;
	stream >> employeeInfoData;

	emit signalFor_solutionForEmployeeInfo(employeeInfoData);

}

void TcpClient::forImageData(QDataStream& stream) {

	QString pic_format = "";
	QByteArray data;
	QString address = "";
	stream >> pic_format >> data >> address;

	emit signalFor_solutionForImageData(pic_format, data, address);

}

void TcpClient::forInsuranceInfo(QDataStream& stream) {

	QVector<QVector<QString>> insuranceInfoData;
	stream >> insuranceInfoData;

	emit signalFor_solutionForInsuranceInfo(insuranceInfoData);

}

void TcpClient::forSendTotal(QDataStream& stream) {

	QVector<QVector<QString>> totalData;
	stream >> totalData;

	emit signalFor_solutionForTotalData(totalData);

}

void TcpClient::forMenuTotalData(QDataStream& stream) {

	QVector<QString> totalData_oneCol; int col = 0;
	stream >> totalData_oneCol >> col;

	emit signalFor_solutionForMenuTotalData(totalData_oneCol, col);

}

void TcpClient::onsig_save(QVector<QVector<QString>> v_v_BtnSaveClicked) {

	if (tcpSocket == NULL)
		return;

	QByteArray dataSend;
	QDataStream stream(&dataSend, QIODevice::WriteOnly);
	int className = ClassName::FORBTNATTNDNCE;
	stream << (quint32)0 << className << v_v_BtnSaveClicked;
	stream.device()->seek(0);
	stream << dataSend.size();
	tcpSocket->write(dataSend);
	tcpSocket->flush();

}

void TcpClient::onsig_save_2(QVector<QVector<QString>> v_v_forSche) {

	if (tcpSocket == NULL)
		return;

	QByteArray dataSend;
	QDataStream stream(&dataSend, QIODevice::WriteOnly);
	int className = ClassName::FORBTNSCHEDULE;
	stream << (quint32)0 << className << v_v_forSche;
	stream.device()->seek(0);
	stream << dataSend.size();
	tcpSocket->write(dataSend);
	tcpSocket->flush();

}

void TcpClient::onsig_sendPurchaseData(const QString& pro, int year, int month, int state) {

	if (tcpSocket == NULL)
		return;

	QByteArray dataSend;
	QDataStream stream(&dataSend, QIODevice::WriteOnly);
	int className = ClassName::PURCHASEDATA;
	stream << (quint32)0 << className << pro << year << month << state;
	stream.device()->seek(0);
	stream << dataSend.size();
	tcpSocket->write(dataSend);
	tcpSocket->flush();

}

void TcpClient::onsig_forSubmit(QVector<QVector<QString>> v_v_tableDate) {

	if (tcpSocket == NULL)
		return;

	QByteArray dataSend;
	QDataStream stream(&dataSend, QIODevice::WriteOnly);
	int className = ClassName::FORBTNSUBMIT;
	stream << (quint32)0 << className << v_v_tableDate;
	stream.device()->seek(0);
	stream << dataSend.size();
	tcpSocket->write(dataSend);
	tcpSocket->flush();

}

void TcpClient::onsig_btnOpenClicked(const QString& purchase_id) {

	if (tcpSocket == NULL)
		return;

	QByteArray dataSend;
	QDataStream stream(&dataSend, QIODevice::WriteOnly);
	int className = ClassName::FORBTNOPEN;
	stream << (quint32)0 << className << purchase_id;
	stream.device()->seek(0);
	stream << dataSend.size();
	tcpSocket->write(dataSend);
	tcpSocket->flush();

}

void TcpClient::onsig_sendStateData(const QString& pro_date, int state, int index, const QString& name, QVector<QString> advice) {

	if (tcpSocket == NULL)
		return;

	QByteArray dataSend;
	QDataStream stream(&dataSend, QIODevice::WriteOnly);
	int className = ClassName::FORSTATEDATA;
	stream << (quint32)0 << className << pro_date << state << index << name << advice;
	stream.device()->seek(0);
	stream << dataSend.size();
	tcpSocket->write(dataSend);
	tcpSocket->flush();

}

void TcpClient::onsig_forCostAndDate(QVector<QString> v_forCostAndDate) {

	if (tcpSocket == NULL)
		return;

	QByteArray dataSend;
	QDataStream stream(&dataSend, QIODevice::WriteOnly);
	int className = ClassName::COSTANDDATE;
	stream << (quint32)0 << className << v_forCostAndDate;
	stream.device()->seek(0);
	stream << dataSend.size();
	tcpSocket->write(dataSend);
	tcpSocket->flush();

}

void TcpClient::onsig_forDelete(const QString& id) {

	if (tcpSocket == NULL)
		return;

	QByteArray dataSend;
	QDataStream stream(&dataSend, QIODevice::WriteOnly);
	int className = ClassName::FORBTNDELETE;
	stream << (quint32)0 << className << id;
	stream.device()->seek(0);
	stream << dataSend.size();
	tcpSocket->write(dataSend);
	tcpSocket->flush();

}

void TcpClient::onsig_sendEntryData(QVector<QString> v_sendEntryData, const QByteArray& imageData) {

	if (tcpSocket == NULL)
		return;

	QByteArray dataSend;
	QDataStream stream(&dataSend, QIODevice::WriteOnly);
	int className = ClassName::FORSENDENTRYDATA;
	stream << (quint32)0 << className << v_sendEntryData << imageData;
	stream.device()->seek(0);
	stream << dataSend.size();
	tcpSocket->write(dataSend);
	tcpSocket->flush();

}

void TcpClient::onsig_sendChangeData(QVector<QString> v_sendChangeData) {

	if (tcpSocket == NULL)
		return;

	QByteArray dataSend;
	QDataStream stream(&dataSend, QIODevice::WriteOnly);
	int className = ClassName::FORSENDCHANGEDATA;
	stream << (quint32)0 << className << v_sendChangeData;
	stream.device()->seek(0);
	stream << dataSend.size();
	tcpSocket->write(dataSend);
	tcpSocket->flush();

}

void TcpClient::onsig_sendChangeName(const QString& name) {

	if (tcpSocket == NULL)
		return;

	QByteArray dataSend;
	QDataStream stream(&dataSend, QIODevice::WriteOnly);
	int className = ClassName::FORSENDCHANGENAME;
	stream << (quint32)0 << className << name;
	stream.device()->seek(0);
	stream << dataSend.size();
	tcpSocket->write(dataSend);
	tcpSocket->flush();

}

void TcpClient::onsig_sendOutData(QVector<QString> v_sendOutData) {

	if (tcpSocket == NULL)
		return;

	QByteArray dataSend;
	QDataStream stream(&dataSend, QIODevice::WriteOnly);
	int className = ClassName::FORSENDOUTDATA;
	stream << (quint32)0 << className << v_sendOutData;
	stream.device()->seek(0);
	stream << dataSend.size();
	tcpSocket->write(dataSend);
	tcpSocket->flush();

}

void TcpClient::onsig_forGetEmployeeInfoData(QVector<QString> v_forEmployeeInfoData) {

	if (tcpSocket == NULL)
		return;

	QByteArray dataSend;
	QDataStream stream(&dataSend, QIODevice::WriteOnly);
	int className = ClassName::FORSENDEMPLOYEEINFODATA;
	stream << (quint32)0 << className << v_forEmployeeInfoData;
	stream.device()->seek(0);
	stream << dataSend.size();
	tcpSocket->write(dataSend);
	tcpSocket->flush();

}

void TcpClient::onsig_sendImageData(const QString& name) {

	if (tcpSocket == NULL)
		return;

	QByteArray dataSend;
	QDataStream stream(&dataSend, QIODevice::WriteOnly);
	int className = ClassName::FORSENDIMAGEDATA;
	stream << (quint32)0 << className << name;
	stream.device()->seek(0);
	stream << dataSend.size();
	tcpSocket->write(dataSend);
	tcpSocket->flush();

}

void TcpClient::onsig_saveEmployeeInfo(QMap<QString, QString> map_saveEmployeeInfo, const QByteArray& data) {

	if (tcpSocket == NULL)
		return;

	QByteArray dataSend;
	QDataStream stream(&dataSend, QIODevice::WriteOnly);
	int className = ClassName::FORSAVEEMPLOYEEINFO;
	stream << (quint32)0 << className << map_saveEmployeeInfo << data;
	stream.device()->seek(0);
	stream << dataSend.size();
	tcpSocket->write(dataSend);
	tcpSocket->flush();

}

void TcpClient::onsig_forGetInsuranceInfo(QVector<QString> v_forInsuranceInfo) {

	if (tcpSocket == NULL)
		return;

	QByteArray dataSend;
	QDataStream stream(&dataSend, QIODevice::WriteOnly);
	int className = ClassName::FORINSURANCEINFO;
	stream << (quint32)0 << className << v_forInsuranceInfo;
	stream.device()->seek(0);
	stream << dataSend.size();
	tcpSocket->write(dataSend);
	tcpSocket->flush();

}

void TcpClient::onsig_saveInsuranceInfo(QVector<QString> v_saveInsuranceInfo) {

	if (tcpSocket == NULL)
		return;

	QByteArray dataSend;
	QDataStream stream(&dataSend, QIODevice::WriteOnly);
	int className = ClassName::FORSAVEINSURANCEINFO;
	stream << (quint32)0 << className << v_saveInsuranceInfo;
	stream.device()->seek(0);
	stream << dataSend.size();
	tcpSocket->write(dataSend);
	tcpSocket->flush();

}

void TcpClient::onsig_sendtotal(QVector<QString> v_sendTotal) {

	if (tcpSocket == NULL)
		return;

	QByteArray dataSend;
	QDataStream stream(&dataSend, QIODevice::WriteOnly);
	int className = ClassName::FORSENDTOTAL;
	stream << (quint32)0 << className << v_sendTotal;
	stream.device()->seek(0);
	stream << dataSend.size();
	tcpSocket->write(dataSend);
	tcpSocket->flush();

}

void TcpClient::onsig_menuTriggered(const QString& actText) {

	if (tcpSocket == NULL)
		return;

	QByteArray dataSend;
	QDataStream stream(&dataSend, QIODevice::WriteOnly);
	int className = ClassName::FORMENUTRIGGERED;
	stream << (quint32)0 << className << actText;
	stream.device()->seek(0);
	stream << dataSend.size();
	tcpSocket->write(dataSend);
	tcpSocket->flush();

}