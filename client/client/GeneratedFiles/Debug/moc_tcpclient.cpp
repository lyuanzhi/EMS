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
    QByteArrayData data[25];
    char stringdata0[437];
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
QT_MOC_LITERAL(8, 133, 49), // "QVector<ForAttndnce>[NUM_PROJ..."
QT_MOC_LITERAL(9, 183, 11), // "onReadyRead"
QT_MOC_LITERAL(10, 195, 11), // "onConnected"
QT_MOC_LITERAL(11, 207, 14), // "onDisconnected"
QT_MOC_LITERAL(12, 222, 7), // "onError"
QT_MOC_LITERAL(13, 230, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(14, 259, 14), // "onsig_register"
QT_MOC_LITERAL(15, 274, 12), // "RegisterInfo"
QT_MOC_LITERAL(16, 287, 12), // "onsig_change"
QT_MOC_LITERAL(17, 300, 10), // "ChgPwdInfo"
QT_MOC_LITERAL(18, 311, 11), // "onsig_login"
QT_MOC_LITERAL(19, 323, 9), // "UsernmPwd"
QT_MOC_LITERAL(20, 333, 26), // "onsig_sendAttenAndScheData"
QT_MOC_LITERAL(21, 360, 10), // "onsig_save"
QT_MOC_LITERAL(22, 371, 31), // "QVector<UsedWhenBtnSaveClicked>"
QT_MOC_LITERAL(23, 403, 12), // "onsig_save_2"
QT_MOC_LITERAL(24, 416, 20) // "QVector<ForAttndnce>"

    },
    "TcpClient\0sig_forUserNameExist\0\0"
    "sig_forSOrFCreated\0sig_forWrongOrSuccess\0"
    "sig_forPwdTrue\0UserInfo\0"
    "signalFor_solutionForAttendanceInit\0"
    "QVector<ForAttndnce>[NUM_PROJECT][NUM_DEPARTMENT]\0"
    "onReadyRead\0onConnected\0onDisconnected\0"
    "onError\0QAbstractSocket::SocketError\0"
    "onsig_register\0RegisterInfo\0onsig_change\0"
    "ChgPwdInfo\0onsig_login\0UsernmPwd\0"
    "onsig_sendAttenAndScheData\0onsig_save\0"
    "QVector<UsedWhenBtnSaveClicked>\0"
    "onsig_save_2\0QVector<ForAttndnce>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TcpClient[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,
       3,    0,   90,    2, 0x06 /* Public */,
       4,    0,   91,    2, 0x06 /* Public */,
       5,    1,   92,    2, 0x06 /* Public */,
       7,    2,   95,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,  100,    2, 0x0a /* Public */,
      10,    0,  101,    2, 0x0a /* Public */,
      11,    0,  102,    2, 0x0a /* Public */,
      12,    1,  103,    2, 0x0a /* Public */,
      14,    1,  106,    2, 0x0a /* Public */,
      16,    1,  109,    2, 0x0a /* Public */,
      18,    1,  112,    2, 0x0a /* Public */,
      20,    0,  115,    2, 0x0a /* Public */,
      21,    1,  116,    2, 0x0a /* Public */,
      23,    1,  119,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 8,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void, 0x80000000 | 15,    2,
    QMetaType::Void, 0x80000000 | 17,    2,
    QMetaType::Void, 0x80000000 | 19,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 22,    2,
    QMetaType::Void, 0x80000000 | 24,    2,

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
        case 4: _t->signalFor_solutionForAttendanceInit((*reinterpret_cast< QVector<ForAttndnce>(*)[NUM_PROJECT][NUM_DEPARTMENT]>(_a[1])),(*reinterpret_cast< QVector<ForAttndnce>(*)[NUM_PROJECT][NUM_DEPARTMENT]>(_a[2]))); break;
        case 5: _t->onReadyRead(); break;
        case 6: _t->onConnected(); break;
        case 7: _t->onDisconnected(); break;
        case 8: _t->onError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 9: _t->onsig_register((*reinterpret_cast< RegisterInfo(*)>(_a[1]))); break;
        case 10: _t->onsig_change((*reinterpret_cast< ChgPwdInfo(*)>(_a[1]))); break;
        case 11: _t->onsig_login((*reinterpret_cast< UsernmPwd(*)>(_a[1]))); break;
        case 12: _t->onsig_sendAttenAndScheData(); break;
        case 13: _t->onsig_save((*reinterpret_cast< QVector<UsedWhenBtnSaveClicked>(*)>(_a[1]))); break;
        case 14: _t->onsig_save_2((*reinterpret_cast< QVector<ForAttndnce>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
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
            using _t = void (TcpClient::*)(QVector<ForAttndnce> [NUM_PROJECT][NUM_DEPARTMENT], QVector<ForAttndnce> [NUM_PROJECT][NUM_DEPARTMENT]);
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpClient::signalFor_solutionForAttendanceInit)) {
                *result = 4;
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
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
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
void TcpClient::signalFor_solutionForAttendanceInit(QVector<ForAttndnce> _t1[NUM_PROJECT][NUM_DEPARTMENT], QVector<ForAttndnce> _t2[NUM_PROJECT][NUM_DEPARTMENT])
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
