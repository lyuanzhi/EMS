#pragma once

#include <qtcpserver.h>
#include <qtcpsocket.h>
#include "structure.h"
#include <qdatastream.h>
#include <QFile>
#include "database.h"
#include <qtextedit.h>
#include <qlayout.h>

class TcpConnect : public QWidget
{
	Q_OBJECT

public:
	TcpConnect(QWidget* parent = Q_NULLPTR);
	~TcpConnect();
	QString host_info;

private:
    QTcpServer* server;
    QList<QTcpSocket*> clients;
    quint32 sizePackLast;
    Database* database;
	QHBoxLayout* horizontalLayout;
	QTextEdit* textReadOnly;

private:
    void handleLogin_getData(QTcpSocket* socket, QDataStream& stream);
    void handleRegister_getData(QTcpSocket* socket, QDataStream& stream);
    void handleChgPwd_getData(QTcpSocket* socket, QDataStream& stream);
    void handleForAttndnce_getData(QTcpSocket* socket, QDataStream& stream);
    void handleForSchedule_getData(QTcpSocket* socket, QDataStream& stream);
    void handleAttendData_getData(QTcpSocket* socket, QDataStream& stream);
    void handleScheduleData_getData(QTcpSocket* socket, QDataStream& stream);
    void handlePurchaseData_getData(QTcpSocket* socket, QDataStream& stream);
    void handleForSubmit_getData(QTcpSocket* socket, QDataStream& stream);
    void handleForOpen_getData(QTcpSocket* socket, QDataStream& stream);
    void handleForState_getData(QTcpSocket* socket, QDataStream& stream);
    void handleForCostAndDate_getData(QTcpSocket* socket, QDataStream& stream);
    void handleForDelete_getData(QTcpSocket* socket, QDataStream& stream);
    void handleForEntryData_getData(QTcpSocket* socket, QDataStream& stream);
    void handleForChangeData_getData(QTcpSocket* socket, QDataStream& stream);
    void handleForChangeName_getData(QTcpSocket* socket, QDataStream& stream);
    void handleForOutData_getData(QTcpSocket* socket, QDataStream& stream);
    void handleForEmployeeInfo_getData(QTcpSocket* socket, QDataStream& stream);
    void handleForImageData_getData(QTcpSocket* socket, QDataStream& stream);
    void handleForSaveEmployeeInfo_getData(QTcpSocket* socket, QDataStream& stream);
    void handleForInsuranceInfo_getData(QTcpSocket* socket, QDataStream& stream);
    void handleForSaveInsuranceInfo_getData(QTcpSocket* socket, QDataStream& stream);
    void handleForSendTotal_getData(QTcpSocket* socket, QDataStream& stream);
    void handleForMenuTriggered_getData(QTcpSocket* socket, QDataStream& stream);

public slots:
    void onReadyRead();
    void onNewConnection();
    void onDisconnected();
    void onError(QAbstractSocket::SocketError socketError);

};
