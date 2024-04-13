/****************************************************************************
** Meta object code from reading C++ file 'widgetpbcq.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../widgetpbcq.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widgetpbcq.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WidgetPBCQ_t {
    QByteArrayData data[16];
    char stringdata0[287];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WidgetPBCQ_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WidgetPBCQ_t qt_meta_stringdata_WidgetPBCQ = {
    {
QT_MOC_LITERAL(0, 0, 10), // "WidgetPBCQ"
QT_MOC_LITERAL(1, 11, 18), // "sig_sendAttendData"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 20), // "sig_sendScheduleData"
QT_MOC_LITERAL(4, 52, 8), // "sig_save"
QT_MOC_LITERAL(5, 61, 26), // "QVector<QVector<QString> >"
QT_MOC_LITERAL(6, 88, 10), // "sig_save_2"
QT_MOC_LITERAL(7, 99, 13), // "onsig_forpbcq"
QT_MOC_LITERAL(8, 113, 9), // "UserInfo&"
QT_MOC_LITERAL(9, 123, 17), // "receiveAttendData"
QT_MOC_LITERAL(10, 141, 41), // "QMap<QString,QVector<QVector<..."
QT_MOC_LITERAL(11, 183, 19), // "receiveScheduleData"
QT_MOC_LITERAL(12, 203, 16), // "onBtnSaveClicked"
QT_MOC_LITERAL(13, 220, 18), // "onBtnSave_2Clicked"
QT_MOC_LITERAL(14, 239, 22), // "onsectionDoubleClicked"
QT_MOC_LITERAL(15, 262, 24) // "onsig_tempCbxIndexChange"

    },
    "WidgetPBCQ\0sig_sendAttendData\0\0"
    "sig_sendScheduleData\0sig_save\0"
    "QVector<QVector<QString> >\0sig_save_2\0"
    "onsig_forpbcq\0UserInfo&\0receiveAttendData\0"
    "QMap<QString,QVector<QVector<QString> > >\0"
    "receiveScheduleData\0onBtnSaveClicked\0"
    "onBtnSave_2Clicked\0onsectionDoubleClicked\0"
    "onsig_tempCbxIndexChange"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WidgetPBCQ[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   69,    2, 0x06 /* Public */,
       3,    1,   74,    2, 0x06 /* Public */,
       4,    1,   77,    2, 0x06 /* Public */,
       6,    1,   80,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   83,    2, 0x0a /* Public */,
       9,    1,   86,    2, 0x0a /* Public */,
      11,    1,   89,    2, 0x0a /* Public */,
      12,    0,   92,    2, 0x0a /* Public */,
      13,    0,   93,    2, 0x0a /* Public */,
      14,    1,   94,    2, 0x0a /* Public */,
      15,    1,   97,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 5,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void, 0x80000000 | 10,    2,
    QMetaType::Void, 0x80000000 | 10,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void WidgetPBCQ::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WidgetPBCQ *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_sendAttendData((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->sig_sendScheduleData((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->sig_save((*reinterpret_cast< QVector<QVector<QString> >(*)>(_a[1]))); break;
        case 3: _t->sig_save_2((*reinterpret_cast< QVector<QVector<QString> >(*)>(_a[1]))); break;
        case 4: _t->onsig_forpbcq((*reinterpret_cast< UserInfo(*)>(_a[1]))); break;
        case 5: _t->receiveAttendData((*reinterpret_cast< QMap<QString,QVector<QVector<QString> > >(*)>(_a[1]))); break;
        case 6: _t->receiveScheduleData((*reinterpret_cast< QMap<QString,QVector<QVector<QString> > >(*)>(_a[1]))); break;
        case 7: _t->onBtnSaveClicked(); break;
        case 8: _t->onBtnSave_2Clicked(); break;
        case 9: _t->onsectionDoubleClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->onsig_tempCbxIndexChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QVector<QString> > >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QVector<QString> > >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WidgetPBCQ::*)(const QString & , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WidgetPBCQ::sig_sendAttendData)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (WidgetPBCQ::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WidgetPBCQ::sig_sendScheduleData)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (WidgetPBCQ::*)(QVector<QVector<QString>> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WidgetPBCQ::sig_save)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (WidgetPBCQ::*)(QVector<QVector<QString>> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WidgetPBCQ::sig_save_2)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WidgetPBCQ::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_WidgetPBCQ.data,
    qt_meta_data_WidgetPBCQ,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WidgetPBCQ::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WidgetPBCQ::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WidgetPBCQ.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int WidgetPBCQ::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void WidgetPBCQ::sig_sendAttendData(const QString & _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WidgetPBCQ::sig_sendScheduleData(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void WidgetPBCQ::sig_save(QVector<QVector<QString>> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void WidgetPBCQ::sig_save_2(QVector<QVector<QString>> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
