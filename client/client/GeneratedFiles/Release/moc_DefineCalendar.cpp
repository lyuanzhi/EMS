/****************************************************************************
** Meta object code from reading C++ file 'DefineCalendar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../DefineCalendar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DefineCalendar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DefineCalendar_t {
    QByteArrayData data[14];
    char stringdata0[132];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DefineCalendar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DefineCalendar_t qt_meta_stringdata_DefineCalendar = {
    {
QT_MOC_LITERAL(0, 0, 14), // "DefineCalendar"
QT_MOC_LITERAL(1, 15, 11), // "setFinished"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 8), // "dateTime"
QT_MOC_LITERAL(4, 37, 10), // "UpdateYear"
QT_MOC_LITERAL(5, 48, 10), // "UpdatePage"
QT_MOC_LITERAL(6, 59, 8), // "SetToday"
QT_MOC_LITERAL(7, 68, 9), // "ClearTime"
QT_MOC_LITERAL(8, 78, 8), // "BtnSlots"
QT_MOC_LITERAL(9, 87, 13), // "ComboBoxSlots"
QT_MOC_LITERAL(10, 101, 5), // "index"
QT_MOC_LITERAL(11, 107, 13), // "CurPageChange"
QT_MOC_LITERAL(12, 121, 4), // "year"
QT_MOC_LITERAL(13, 126, 5) // "month"

    },
    "DefineCalendar\0setFinished\0\0dateTime\0"
    "UpdateYear\0UpdatePage\0SetToday\0ClearTime\0"
    "BtnSlots\0ComboBoxSlots\0index\0CurPageChange\0"
    "year\0month"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DefineCalendar[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   57,    2, 0x0a /* Public */,
       5,    0,   58,    2, 0x0a /* Public */,
       6,    0,   59,    2, 0x0a /* Public */,
       7,    0,   60,    2, 0x0a /* Public */,
       8,    0,   61,    2, 0x09 /* Protected */,
       9,    1,   62,    2, 0x09 /* Protected */,
      11,    2,   65,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::QDateTime,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   12,   13,

       0        // eod
};

void DefineCalendar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DefineCalendar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setFinished((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
        case 1: _t->UpdateYear(); break;
        case 2: _t->UpdatePage(); break;
        case 3: _t->SetToday(); break;
        case 4: _t->ClearTime(); break;
        case 5: _t->BtnSlots(); break;
        case 6: _t->ComboBoxSlots((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->CurPageChange((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DefineCalendar::*)(const QDateTime & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DefineCalendar::setFinished)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DefineCalendar::staticMetaObject = { {
    &QCalendarWidget::staticMetaObject,
    qt_meta_stringdata_DefineCalendar.data,
    qt_meta_data_DefineCalendar,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DefineCalendar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DefineCalendar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DefineCalendar.stringdata0))
        return static_cast<void*>(this);
    return QCalendarWidget::qt_metacast(_clname);
}

int DefineCalendar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QCalendarWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void DefineCalendar::setFinished(const QDateTime & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
