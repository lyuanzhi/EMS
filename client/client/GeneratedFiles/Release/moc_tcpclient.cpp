/****************************************************************************
** Meta object code from reading C++ file 'tcpclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../tcpclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TcpClient_t {
    QByteArrayData data[57];
    char stringdata0[1193];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TcpClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TcpClient_t qt_meta_stringdata_TcpClient = {
    {
QT_MOC_LITERAL(0, 0, 9), // "TcpClient"
QT_MOC_LITERAL(1, 10, 20), // "sig_forUserNameExist"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 18), // "sig_forSOrFCreated"
QT_MOC_LITERAL(4, 51, 21), // "sig_forWrongOrSuccess"
QT_MOC_LITERAL(5, 73, 14), // "sig_forPwdTrue"
QT_MOC_LITERAL(6, 88, 8), // "UserInfo"
QT_MOC_LITERAL(7, 97, 35), // "signalFor_solutionForAttendan..."
QT_MOC_LITERAL(8, 133, 41), // "QMap<QString,QVector<QVector<..."
QT_MOC_LITERAL(9, 175, 33), // "signalFor_solutionForSchedule..."
QT_MOC_LITERAL(10, 209, 33), // "signalFor_solutionForPurchase..."
QT_MOC_LITERAL(11, 243, 26), // "QVector<QVector<QString> >"
QT_MOC_LITERAL(12, 270, 28), // "signalFor_solutionForBtnOpen"
QT_MOC_LITERAL(13, 299, 23), // "sig_forSuccessfulSubmit"
QT_MOC_LITERAL(14, 323, 12), // "sig_forState"
QT_MOC_LITERAL(15, 336, 23), // "sig_forSuccessfulDelete"
QT_MOC_LITERAL(16, 360, 31), // "signalFor_solutionForChangeName"
QT_MOC_LITERAL(17, 392, 22), // "sig_forSuccessful_YGGL"
QT_MOC_LITERAL(18, 415, 33), // "signalFor_solutionForEmployee..."
QT_MOC_LITERAL(19, 449, 30), // "signalFor_solutionForImageData"
QT_MOC_LITERAL(20, 480, 34), // "signalFor_solutionForInsuranc..."
QT_MOC_LITERAL(21, 515, 30), // "signalFor_solutionForTotalData"
QT_MOC_LITERAL(22, 546, 34), // "signalFor_solutionForMenuTota..."
QT_MOC_LITERAL(23, 581, 16), // "QVector<QString>"
QT_MOC_LITERAL(24, 598, 11), // "onReadyRead"
QT_MOC_LITERAL(25, 610, 11), // "onConnected"
QT_MOC_LITERAL(26, 622, 14), // "onDisconnected"
QT_MOC_LITERAL(27, 637, 7), // "onError"
QT_MOC_LITERAL(28, 645, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(29, 674, 14), // "onsig_register"
QT_MOC_LITERAL(30, 689, 12), // "RegisterInfo"
QT_MOC_LITERAL(31, 702, 12), // "onsig_change"
QT_MOC_LITERAL(32, 715, 10), // "ChgPwdInfo"
QT_MOC_LITERAL(33, 726, 11), // "onsig_login"
QT_MOC_LITERAL(34, 738, 9), // "UsernmPwd"
QT_MOC_LITERAL(35, 748, 20), // "onsig_sendAttendData"
QT_MOC_LITERAL(36, 769, 10), // "onsig_save"
QT_MOC_LITERAL(37, 780, 12), // "onsig_save_2"
QT_MOC_LITERAL(38, 793, 22), // "onsig_sendPurchaseData"
QT_MOC_LITERAL(39, 816, 15), // "onsig_forSubmit"
QT_MOC_LITERAL(40, 832, 22), // "onsig_sendScheduleData"
QT_MOC_LITERAL(41, 855, 20), // "onsig_btnOpenClicked"
QT_MOC_LITERAL(42, 876, 19), // "onsig_sendStateData"
QT_MOC_LITERAL(43, 896, 20), // "onsig_forCostAndDate"
QT_MOC_LITERAL(44, 917, 15), // "onsig_forDelete"
QT_MOC_LITERAL(45, 933, 19), // "onsig_sendEntryData"
QT_MOC_LITERAL(46, 953, 20), // "onsig_sendChangeData"
QT_MOC_LITERAL(47, 974, 20), // "onsig_sendChangeName"
QT_MOC_LITERAL(48, 995, 17), // "onsig_sendOutData"
QT_MOC_LITERAL(49, 1013, 28), // "onsig_forGetEmployeeInfoData"
QT_MOC_LITERAL(50, 1042, 19), // "onsig_sendImageData"
QT_MOC_LITERAL(51, 1062, 22), // "onsig_saveEmployeeInfo"
QT_MOC_LITERAL(52, 1085, 21), // "QMap<QString,QString>"
QT_MOC_LITERAL(53, 1107, 25), // "onsig_forGetInsuranceInfo"
QT_MOC_LITERAL(54, 1133, 23), // "onsig_saveInsuranceInfo"
QT_MOC_LITERAL(55, 1157, 15), // "onsig_sendtotal"
QT_MOC_LITERAL(56, 1173, 19) // "onsig_menuTriggered"

    },
    "TcpClient\0sig_forUserNameExist\0\0"
    "sig_forSOrFCreated\0sig_forWrongOrSuccess\0"
    "sig_forPwdTrue\0UserInfo\0"
    "signalFor_solutionForAttendanceInit\0"
    "QMap<QString,QVector<QVector<QString> > >\0"
    "signalFor_solutionForScheduleInit\0"
    "signalFor_solutionForPurchaseInit\0"
    "QVector<QVector<QString> >\0"
    "signalFor_solutionForBtnOpen\0"
    "sig_forSuccessfulSubmit\0sig_forState\0"
    "sig_forSuccessfulDelete\0"
    "signalFor_solutionForChangeName\0"
    "sig_forSuccessful_YGGL\0"
    "signalFor_solutionForEmployeeInfo\0"
    "signalFor_solutionForImageData\0"
    "signalFor_solutionForInsuranceInfo\0"
    "signalFor_solutionForTotalData\0"
    "signalFor_solutionForMenuTotalData\0"
    "QVector<QString>\0onReadyRead\0onConnected\0"
    "onDisconnected\0onError\0"
    "QAbstractSocket::SocketError\0"
    "onsig_register\0RegisterInfo\0onsig_change\0"
    "ChgPwdInfo\0onsig_login\0UsernmPwd\0"
    "onsig_sendAttendData\0onsig_save\0"
    "onsig_save_2\0onsig_sendPurchaseData\0"
    "onsig_forSubmit\0onsig_sendScheduleData\0"
    "onsig_btnOpenClicked\0onsig_sendStateData\0"
    "onsig_forCostAndDate\0onsig_forDelete\0"
    "onsig_sendEntryData\0onsig_sendChangeData\0"
    "onsig_sendChangeName\0onsig_sendOutData\0"
    "onsig_forGetEmployeeInfoData\0"
    "onsig_sendImageData\0onsig_saveEmployeeInfo\0"
    "QMap<QString,QString>\0onsig_forGetInsuranceInfo\0"
    "onsig_saveInsuranceInfo\0onsig_sendtotal\0"
    "onsig_menuTriggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TcpClient[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      46,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      18,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  244,    2, 0x06 /* Public */,
       3,    0,  245,    2, 0x06 /* Public */,
       4,    0,  246,    2, 0x06 /* Public */,
       5,    1,  247,    2, 0x06 /* Public */,
       7,    1,  250,    2, 0x06 /* Public */,
       9,    1,  253,    2, 0x06 /* Public */,
      10,    1,  256,    2, 0x06 /* Public */,
      12,    1,  259,    2, 0x06 /* Public */,
      13,    0,  262,    2, 0x06 /* Public */,
      14,    0,  263,    2, 0x06 /* Public */,
      15,    0,  264,    2, 0x06 /* Public */,
      16,    1,  265,    2, 0x06 /* Public */,
      17,    1,  268,    2, 0x06 /* Public */,
      18,    1,  271,    2, 0x06 /* Public */,
      19,    3,  274,    2, 0x06 /* Public */,
      20,    1,  281,    2, 0x06 /* Public */,
      21,    1,  284,    2, 0x06 /* Public */,
      22,    2,  287,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      24,    0,  292,    2, 0x0a /* Public */,
      25,    0,  293,    2, 0x0a /* Public */,
      26,    0,  294,    2, 0x0a /* Public */,
      27,    1,  295,    2, 0x0a /* Public */,
      29,    1,  298,    2, 0x0a /* Public */,
      31,    1,  301,    2, 0x0a /* Public */,
      33,    1,  304,    2, 0x0a /* Public */,
      35,    2,  307,    2, 0x0a /* Public */,
      36,    1,  312,    2, 0x0a /* Public */,
      37,    1,  315,    2, 0x0a /* Public */,
      38,    4,  318,    2, 0x0a /* Public */,
      39,    1,  327,    2, 0x0a /* Public */,
      40,    1,  330,    2, 0x0a /* Public */,
      41,    1,  333,    2, 0x0a /* Public */,
      42,    5,  336,    2, 0x0a /* Public */,
      43,    1,  347,    2, 0x0a /* Public */,
      44,    1,  350,    2, 0x0a /* Public */,
      45,    2,  353,    2, 0x0a /* Public */,
      46,    1,  358,    2, 0x0a /* Public */,
      47,    1,  361,    2, 0x0a /* Public */,
      48,    1,  364,    2, 0x0a /* Public */,
      49,    1,  367,    2, 0x0a /* Public */,
      50,    1,  370,    2, 0x0a /* Public */,
      51,    2,  373,    2, 0x0a /* Public */,
      53,    1,  378,    2, 0x0a /* Public */,
      54,    1,  381,    2, 0x0a /* Public */,
      55,    1,  384,    2, 0x0a /* Public */,
      56,    1,  387,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QByteArray, QMetaType::QString,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void, 0x80000000 | 23, QMetaType::Int,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 28,    2,
    QMetaType::Void, 0x80000000 | 30,    2,
    QMetaType::Void, 0x80000000 | 32,    2,
    QMetaType::Void, 0x80000000 | 34,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    2,    2,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::QString, 0x80000000 | 23,    2,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 23,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 23, QMetaType::QByteArray,    2,    2,
    QMetaType::Void, 0x80000000 | 23,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 23,    2,
    QMetaType::Void, 0x80000000 | 23,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 52, QMetaType::QByteArray,    2,    2,
    QMetaType::Void, 0x80000000 | 23,    2,
    QMetaType::Void, 0x80000000 | 23,    2,
    QMetaType::Void, 0x80000000 | 23,    2,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void TcpClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TcpClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_forUserNameExist(); break;
        case 1: _t->sig_forSOrFCreated(); break;
        case 2: _t->sig_forWrongOrSuccess(); break;
        case 3: _t->sig_forPwdTrue((*reinterpret_cast< UserInfo(*)>(_a[1]))); break;
        case 4: _t->signalFor_solutionForAttendanceInit((*reinterpret_cast< QMap<QString,QVector<QVector<QString> > >(*)>(_a[1]))); break;
        case 5: _t->signalFor_solutionForScheduleInit((*reinterpret_cast< QMap<QString,QVector<QVector<QString> > >(*)>(_a[1]))); break;
        case 6: _t->signalFor_solutionForPurchaseInit((*reinterpret_cast< QVector<QVector<QString> >(*)>(_a[1]))); break;
        case 7: _t->signalFor_solutionForBtnOpen((*reinterpret_cast< QVector<QVector<QString> >(*)>(_a[1]))); break;
        case 8: _t->sig_forSuccessfulSubmit(); break;
        case 9: _t->sig_forState(); break;
        case 10: _t->sig_forSuccessfulDelete(); break;
        case 11: _t->signalFor_solutionForChangeName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->sig_forSuccessful_YGGL((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->signalFor_solutionForEmployeeInfo((*reinterpret_cast< QVector<QVector<QString> >(*)>(_a[1]))); break;
        case 14: _t->signalFor_solutionForImageData((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 15: _t->signalFor_solutionForInsuranceInfo((*reinterpret_cast< QVector<QVector<QString> >(*)>(_a[1]))); break;
        case 16: _t->signalFor_solutionForTotalData((*reinterpret_cast< QVector<QVector<QString> >(*)>(_a[1]))); break;
        case 17: _t->signalFor_solutionForMenuTotalData((*reinterpret_cast< QVector<QString>(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 18: _t->onReadyRead(); break;
        case 19: _t->onConnected(); break;
        case 20: _t->onDisconnected(); break;
        case 21: _t->onError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 22: _t->onsig_register((*reinterpret_cast< RegisterInfo(*)>(_a[1]))); break;
        case 23: _t->onsig_change((*reinterpret_cast< ChgPwdInfo(*)>(_a[1]))); break;
        case 24: _t->onsig_login((*reinterpret_cast< UsernmPwd(*)>(_a[1]))); break;
        case 25: _t->onsig_sendAttendData((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 26: _t->onsig_save((*reinterpret_cast< QVector<QVector<QString> >(*)>(_a[1]))); break;
        case 27: _t->onsig_save_2((*reinterpret_cast< QVector<QVector<QString> >(*)>(_a[1]))); break;
        case 28: _t->onsig_sendPurchaseData((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 29: _t->onsig_forSubmit((*reinterpret_cast< QVector<QVector<QString> >(*)>(_a[1]))); break;
        case 30: _t->onsig_sendScheduleData((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 31: _t->onsig_btnOpenClicked((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 32: _t->onsig_sendStateData((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< QVector<QString>(*)>(_a[5]))); break;
        case 33: _t->onsig_forCostAndDate((*reinterpret_cast< QVector<QString>(*)>(_a[1]))); break;
        case 34: _t->onsig_forDelete((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 35: _t->onsig_sendEntryData((*reinterpret_cast< QVector<QString>(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 36: _t->onsig_sendChangeData((*reinterpret_cast< QVector<QString>(*)>(_a[1]))); break;
        case 37: _t->onsig_sendChangeName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 38: _t->onsig_sendOutData((*reinterpret_cast< QVector<QString>(*)>(_a[1]))); break;
        case 39: _t->onsig_forGetEmployeeInfoData((*reinterpret_cast< QVector<QString>(*)>(_a[1]))); break;
        case 40: _t->onsig_sendImageData((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 41: _t->onsig_saveEmployeeInfo((*reinterpret_cast< QMap<QString,QString>(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 42: _t->onsig_forGetInsuranceInfo((*reinterpret_cast< QVector<QString>(*)>(_a[1]))); break;
        case 43: _t->onsig_saveInsuranceInfo((*reinterpret_cast< QVector<QString>(*)>(_a[1]))); break;
        case 44: _t->onsig_sendtotal((*reinterpret_cast< QVector<QString>(*)>(_a[1]))); break;
        case 45: _t->onsig_menuTriggered((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QVector<QString> > >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QVector<QString> > >(); break;
            }
            break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QVector<QString> > >(); break;
            }
            break;
        case 15:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QVector<QString> > >(); break;
            }
            break;
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QVector<QString> > >(); break;
            }
            break;
        case 17:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QString> >(); break;
            }
            break;
        case 21:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        case 26:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QVector<QString> > >(); break;
            }
            break;
        case 27:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QVector<QString> > >(); break;
            }
            break;
        case 29:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QVector<QString> > >(); break;
            }
            break;
        case 32:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 4:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QString> >(); break;
            }
            break;
        case 33:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QString> >(); break;
            }
            break;
        case 35:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QString> >(); break;
            }
            break;
        case 36:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QString> >(); break;
            }
            break;
        case 38:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QString> >(); break;
            }
            break;
        case 39:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QString> >(); break;
            }
            break;
        case 42:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QString> >(); break;
            }
            break;
        case 43:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QString> >(); break;
            }
            break;
        case 44:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QString> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TcpClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpClient::sig_forUserNameExist)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TcpClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpClient::sig_forSOrFCreated)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TcpClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpClient::sig_forWrongOrSuccess)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TcpClient::*)(UserInfo );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpClient::sig_forPwdTrue)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (TcpClient::*)(QMap<QString,QVector<QVector<QString>> > );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpClient::signalFor_solutionForAttendanceInit)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (TcpClient::*)(QMap<QString,QVector<QVector<QString>> > );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpClient::signalFor_solutionForScheduleInit)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (TcpClient::*)(QVector<QVector<QString>> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpClient::signalFor_solutionForPurchaseInit)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (TcpClient::*)(QVector<QVector<QString>> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpClient::signalFor_solutionForBtnOpen)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (TcpClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpClient::sig_forSuccessfulSubmit)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (TcpClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpClient::sig_forState)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (TcpClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpClient::sig_forSuccessfulDelete)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (TcpClient::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpClient::signalFor_solutionForChangeName)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (TcpClient::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpClient::sig_forSuccessful_YGGL)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (TcpClient::*)(QVector<QVector<QString>> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpClient::signalFor_solutionForEmployeeInfo)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (TcpClient::*)(const QString & , const QByteArray & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpClient::signalFor_solutionForImageData)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (TcpClient::*)(QVector<QVector<QString>> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpClient::signalFor_solutionForInsuranceInfo)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (TcpClient::*)(QVector<QVector<QString>> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpClient::signalFor_solutionForTotalData)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (TcpClient::*)(QVector<QString> , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpClient::signalFor_solutionForMenuTotalData)) {
                *result = 17;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TcpClient::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_TcpClient.data,
    qt_meta_data_TcpClient,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TcpClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TcpClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TcpClient.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int TcpClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 46)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 46;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 46)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 46;
    }
    return _id;
}

// SIGNAL 0
void TcpClient::sig_forUserNameExist()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void TcpClient::sig_forSOrFCreated()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void TcpClient::sig_forWrongOrSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void TcpClient::sig_forPwdTrue(UserInfo _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TcpClient::signalFor_solutionForAttendanceInit(QMap<QString,QVector<QVector<QString>> > _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void TcpClient::signalFor_solutionForScheduleInit(QMap<QString,QVector<QVector<QString>> > _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void TcpClient::signalFor_solutionForPurchaseInit(QVector<QVector<QString>> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void TcpClient::signalFor_solutionForBtnOpen(QVector<QVector<QString>> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void TcpClient::sig_forSuccessfulSubmit()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void TcpClient::sig_forState()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void TcpClient::sig_forSuccessfulDelete()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void TcpClient::signalFor_solutionForChangeName(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void TcpClient::sig_forSuccessful_YGGL(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void TcpClient::signalFor_solutionForEmployeeInfo(QVector<QVector<QString>> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void TcpClient::signalFor_solutionForImageData(const QString & _t1, const QByteArray & _t2, const QString & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void TcpClient::signalFor_solutionForInsuranceInfo(QVector<QVector<QString>> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void TcpClient::signalFor_solutionForTotalData(QVector<QVector<QString>> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void TcpClient::signalFor_solutionForMenuTotalData(QVector<QString> _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
