/****************************************************************************
** Meta object code from reading C++ file 'rgstr.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../rgstr.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rgstr.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Rgstr_t {
    QByteArrayData data[7];
    char stringdata0[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Rgstr_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Rgstr_t qt_meta_stringdata_Rgstr = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Rgstr"
QT_MOC_LITERAL(1, 6, 10), // "sig_return"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 12), // "sig_register"
QT_MOC_LITERAL(4, 31, 12), // "RegisterInfo"
QT_MOC_LITERAL(5, 44, 22), // "onsig_forUserNameExist"
QT_MOC_LITERAL(6, 67, 20) // "onsig_forSOrFCreated"

    },
    "Rgstr\0sig_return\0\0sig_register\0"
    "RegisterInfo\0onsig_forUserNameExist\0"
    "onsig_forSOrFCreated"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Rgstr[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    1,   35,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   38,    2, 0x0a /* Public */,
       6,    0,   39,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Rgstr::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Rgstr *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_return(); break;
        case 1: _t->sig_register((*reinterpret_cast< RegisterInfo(*)>(_a[1]))); break;
        case 2: _t->onsig_forUserNameExist(); break;
        case 3: _t->onsig_forSOrFCreated(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Rgstr::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Rgstr::sig_return)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Rgstr::*)(RegisterInfo );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Rgstr::sig_register)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Rgstr::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Rgstr.data,
    qt_meta_data_Rgstr,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Rgstr::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Rgstr::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Rgstr.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Rgstr::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Rgstr::sig_return()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Rgstr::sig_register(RegisterInfo _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
