#pragma once

#include <QtWidgets/QWidget>
#include <qtcpsocket.h>
#include <qhostaddress.h>
#include "login.h"
#include "homepage.h"

//用于通信（主窗口）
class TcpClient : public QWidget
{
	Q_OBJECT

public:
	TcpClient(QWidget* parent = Q_NULLPTR);
	~TcpClient();

private:
	Login* login;
	Homepage* homepage;

private:
	QHBoxLayout* horizontalLayout;
	QLabel* label;

private:
	QTcpSocket* tcpSocket;
	quint32 sizePackLast;

public slots:
	void onReadyRead();
	void onConnected();
	void onDisconnected();
	void onError(QAbstractSocket::SocketError);
	void onsig_register(RegisterInfo);
	void onsig_change(ChgPwdInfo);
	void onsig_login(UsernmPwd);
	void onsig_sendAttendData(const QString&, int);
	void onsig_save(QVector<QVector<QString>>);
	void onsig_save_2(QVector<QVector<QString>>);
	void onsig_sendPurchaseData(const QString&, int, int, int);
	void onsig_forSubmit(QVector<QVector<QString>>);
	void onsig_sendScheduleData(const QString&);
	void onsig_btnOpenClicked(const QString&);
	void onsig_sendStateData(const QString&, int, int, const QString&, QVector<QString>);
	void onsig_forCostAndDate(QVector<QString>);
	void onsig_forDelete(const QString&);
	//yggl
	void onsig_sendEntryData(QVector<QString>, const QByteArray&);
	void onsig_sendChangeData(QVector<QString>);
	void onsig_sendChangeName(const QString&);
	void onsig_sendOutData(QVector<QString>);
	void onsig_forGetEmployeeInfoData(QVector<QString>);
	void onsig_sendImageData(const QString&);
	void onsig_saveEmployeeInfo(QMap<QString, QString>, const QByteArray&);
	void onsig_forGetInsuranceInfo(QVector<QString>);
	void onsig_saveInsuranceInfo(QVector<QString>);
	void onsig_sendtotal(QVector<QString>);
	void onsig_menuTriggered(const QString&);

private:
	void forPwdFalse();
	void forPwdTrue(QDataStream&);
	void forUserNameExist();
	void forSuccessfulCreated();
	void forFailedCreated();
	void forWrongInfo();
	void forSuccessfulChanged();
	void forAttendanceInit(QDataStream&);
	void forScheduleInit(QDataStream&);
	void forPurchaseInit(QDataStream&);
	void forSuccessfulSaved();
	void forFailedSaved();
	void forSuccessfulSubmit();
	void forFailedSubmit();
	void forBtnOpen(QDataStream&);
	void forState();
	void forSuccessfulDelete();
	void forRealNameExist();
	void forSuccessfulEntry();
	void forSuccessfulChanged_YGGL();
	void forChangeName_YGGL(QDataStream&);
	void forSuccessfulOut();
	void forRealNameNotExist();
	void forOut();
	void forEmployeeInfo(QDataStream&);
	void forImageData(QDataStream&);
	void forSuccessfulSaved_YGGL();
	void forInsuranceInfo(QDataStream&);
	void forSuccessfulSaved_2_YGGL();
	void forSendTotal(QDataStream&);
	void forMenuTotalData(QDataStream&);

signals:
	void sig_forUserNameExist();
	void sig_forSOrFCreated();
	void sig_forWrongOrSuccess();
	void sig_forPwdTrue(UserInfo);
	void signalFor_solutionForAttendanceInit(QMap<QString, QVector<QVector<QString>>>);
	void signalFor_solutionForScheduleInit(QMap<QString, QVector<QVector<QString>>>);
	void signalFor_solutionForPurchaseInit(QVector<QVector<QString>>);
	void signalFor_solutionForBtnOpen(QVector<QVector<QString>>);
	void sig_forSuccessfulSubmit();
	void sig_forState();
	void sig_forSuccessfulDelete();
	void signalFor_solutionForChangeName(const QString&);
	void sig_forSuccessful_YGGL(const QString&);
	void signalFor_solutionForEmployeeInfo(QVector<QVector<QString>>);
	void signalFor_solutionForImageData(const QString&, const QByteArray&, const QString&);
	void signalFor_solutionForInsuranceInfo(QVector<QVector<QString>>);
	void signalFor_solutionForTotalData(QVector<QVector<QString>>);
	void signalFor_solutionForMenuTotalData(QVector<QString>, int);

};
