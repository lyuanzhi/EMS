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
    QByteArrayData data[13];
    char stringdata0[236];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WidgetPBCQ_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WidgetPBCQ_t qt_meta_stringdata_WidgetPBCQ = {
    {
QT_MOC_LITERAL(0, 0, 10), // "WidgetPBCQ"
QT_MOC_LITERAL(1, 11, 8), // "sig_save"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 31), // "QVector<UsedWhenBtnSaveClicked>"
QT_MOC_LITERAL(4, 53, 10), // "sig_save_2"
QT_MOC_LITERAL(5, 64, 20), // "QVector<ForAttndnce>"
QT_MOC_LITERAL(6, 85, 13), // "onsig_forpbcq"
QT_MOC_LITERAL(7, 99, 9), // "UserInfo&"
QT_MOC_LITERAL(8, 109, 49), // "QVector<ForAttndnce>[NUM_PROJ..."
QT_MOC_LITERAL(9, 159, 21), // "onCurrentIndexChanged"
QT_MOC_LITERAL(10, 181, 16), // "onBtnSaveClicked"
QT_MOC_LITERAL(11, 198, 18), // "onBtnLoadInClicked"
QT_MOC_LITERAL(12, 217, 18) // "onBtnSave_2Clicked"

    },
    "WidgetPBCQ\0sig_save\0\0"
    "QVector<UsedWhenBtnSaveClicked>\0"
    "sig_save_2\0QVector<ForAttndnce>\0"
    "onsig_forpbcq\0UserInfo&\0"
    "QVector<ForAttndnce>[NUM_PROJECT][NUM_DEPARTMENT]\0"
    "onCurrentIndexChanged\0onBtnSaveClicked\0"
    "onBtnLoadInClicked\0onBtnSave_2Clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WidgetPBCQ[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    1,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    3,   55,    2, 0x0a /* Public */,
       9,    1,   62,    2, 0x0a /* Public */,
      10,    0,   65,    2, 0x0a /* Public */,
      11,    0,   66,    2, 0x0a /* Public */,
      12,    0,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 8, 0x80000000 | 8,    2,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WidgetPBCQ::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WidgetPBCQ *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_save((*reinterpret_cast< QVector<UsedWhenBtnSaveClicked>(*)>(_a[1]))); break;
        case 1: _t->sig_save_2((*reinterpret_cast< QVector<ForAttndnce>(*)>(_a[1]))); break;
        case 2: _t->onsig_forpbcq((*reinterpret_cast< UserInfo(*)>(_a[1])),(*reinterpret_cast< QVector<ForAttndnce>(*)[NUM_PROJECT][NUM_DEPARTMENT]>(_a[2])),(*reinterpret_cast< QVector<ForAttndnce>(*)[NUM_PROJECT][NUM_DEPARTMENT]>(_a[3]))); break;
        case 3: _t->onCurrentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->onBtnSaveClicked(); break;
        case 5: _t->onBtnLoadInClicked(); break;
        case 6: _t->onBtnSave_2Clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WidgetPBCQ::*)(QVector<UsedWhenBtnSaveClicked> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WidgetPBCQ::sig_save)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (WidgetPBCQ::*)(QVector<ForAttndnce> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WidgetPBCQ::sig_save_2)) {
                *result = 1;
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
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void WidgetPBCQ::sig_save(QVector<UsedWhenBtnSaveClicked> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WidgetPBCQ::sig_save_2(QVector<ForAttndnce> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
