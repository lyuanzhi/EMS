/****************************************************************************
** Meta object code from reading C++ file 'homepage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../homepage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'homepage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Homepage_t {
    QByteArrayData data[16];
    char stringdata0[263];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Homepage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Homepage_t qt_meta_stringdata_Homepage = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Homepage"
QT_MOC_LITERAL(1, 9, 11), // "sig_forpbcq"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 9), // "UserInfo&"
QT_MOC_LITERAL(4, 32, 49), // "QVector<ForAttndnce>[NUM_PROJ..."
QT_MOC_LITERAL(5, 82, 11), // "sig_forwzgl"
QT_MOC_LITERAL(6, 94, 24), // "sig_sendAttenAndScheData"
QT_MOC_LITERAL(7, 119, 8), // "sig_save"
QT_MOC_LITERAL(8, 128, 31), // "QVector<UsedWhenBtnSaveClicked>"
QT_MOC_LITERAL(9, 160, 10), // "sig_save_2"
QT_MOC_LITERAL(10, 171, 20), // "QVector<ForAttndnce>"
QT_MOC_LITERAL(11, 192, 16), // "onsig_forPwdTrue"
QT_MOC_LITERAL(12, 209, 8), // "UserInfo"
QT_MOC_LITERAL(13, 218, 20), // "receiveAttAndSchDate"
QT_MOC_LITERAL(14, 239, 10), // "onsig_save"
QT_MOC_LITERAL(15, 250, 12) // "onsig_save_2"

    },
    "Homepage\0sig_forpbcq\0\0UserInfo&\0"
    "QVector<ForAttndnce>[NUM_PROJECT][NUM_DEPARTMENT]\0"
    "sig_forwzgl\0sig_sendAttenAndScheData\0"
    "sig_save\0QVector<UsedWhenBtnSaveClicked>\0"
    "sig_save_2\0QVector<ForAttndnce>\0"
    "onsig_forPwdTrue\0UserInfo\0"
    "receiveAttAndSchDate\0onsig_save\0"
    "onsig_save_2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Homepage[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   59,    2, 0x06 /* Public */,
       5,    1,   66,    2, 0x06 /* Public */,
       6,    0,   69,    2, 0x06 /* Public */,
       7,    1,   70,    2, 0x06 /* Public */,
       9,    1,   73,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    1,   76,    2, 0x0a /* Public */,
      13,    2,   79,    2, 0x0a /* Public */,
      14,    1,   84,    2, 0x0a /* Public */,
      15,    1,   87,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4, 0x80000000 | 4,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void, 0x80000000 | 10,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 12,    2,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4,    2,    2,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void, 0x80000000 | 10,    2,

       0        // eod
};

void Homepage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Homepage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_forpbcq((*reinterpret_cast< UserInfo(*)>(_a[1])),(*reinterpret_cast< QVector<ForAttndnce>(*)[NUM_PROJECT][NUM_DEPARTMENT]>(_a[2])),(*reinterpret_cast< QVector<ForAttndnce>(*)[NUM_PROJECT][NUM_DEPARTMENT]>(_a[3]))); break;
        case 1: _t->sig_forwzgl((*reinterpret_cast< UserInfo(*)>(_a[1]))); break;
        case 2: _t->sig_sendAttenAndScheData(); break;
        case 3: _t->sig_save((*reinterpret_cast< QVector<UsedWhenBtnSaveClicked>(*)>(_a[1]))); break;
        case 4: _t->sig_save_2((*reinterpret_cast< QVector<ForAttndnce>(*)>(_a[1]))); break;
        case 5: _t->onsig_forPwdTrue((*reinterpret_cast< UserInfo(*)>(_a[1]))); break;
        case 6: _t->receiveAttAndSchDate((*reinterpret_cast< QVector<ForAttndnce>(*)[NUM_PROJECT][NUM_DEPARTMENT]>(_a[1])),(*reinterpret_cast< QVector<ForAttndnce>(*)[NUM_PROJECT][NUM_DEPARTMENT]>(_a[2]))); break;
        case 7: _t->onsig_save((*reinterpret_cast< QVector<UsedWhenBtnSaveClicked>(*)>(_a[1]))); break;
        case 8: _t->onsig_save_2((*reinterpret_cast< QVector<ForAttndnce>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Homepage::*)(UserInfo & , QVector<ForAttndnce> [NUM_PROJECT][NUM_DEPARTMENT], QVector<ForAttndnce> [NUM_PROJECT][NUM_DEPARTMENT]);
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Homepage::sig_forpbcq)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Homepage::*)(UserInfo & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Homepage::sig_forwzgl)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Homepage::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Homepage::sig_sendAttenAndScheData)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Homepage::*)(QVector<UsedWhenBtnSaveClicked> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Homepage::sig_save)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Homepage::*)(QVector<ForAttndnce> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Homepage::sig_save_2)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Homepage::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Homepage.data,
    qt_meta_data_Homepage,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Homepage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Homepage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Homepage.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Homepage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Homepage::sig_forpbcq(UserInfo & _t1, QVector<ForAttndnce> _t2[NUM_PROJECT][NUM_DEPARTMENT], QVector<ForAttndnce> _t3[NUM_PROJECT][NUM_DEPARTMENT])
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Homepage::sig_forwzgl(UserInfo & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Homepage::sig_sendAttenAndScheData()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Homepage::sig_save(QVector<UsedWhenBtnSaveClicked> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Homepage::sig_save_2(QVector<ForAttndnce> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
