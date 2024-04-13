/****************************************************************************
** Meta object code from reading C++ file 'widgetwzgl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../widgetwzgl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widgetwzgl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WidgetWZGL_t {
    QByteArrayData data[14];
    char stringdata0[239];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WidgetWZGL_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WidgetWZGL_t qt_meta_stringdata_WidgetWZGL = {
    {
QT_MOC_LITERAL(0, 0, 10), // "WidgetWZGL"
QT_MOC_LITERAL(1, 11, 18), // "sig_tableIsNotOpen"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 13), // "onsig_forwzgl"
QT_MOC_LITERAL(4, 45, 9), // "UserInfo&"
QT_MOC_LITERAL(5, 55, 22), // "onMyLabelCreateClicked"
QT_MOC_LITERAL(6, 78, 22), // "onMyLabelImportClicked"
QT_MOC_LITERAL(7, 101, 21), // "onMyLabelPrintClicked"
QT_MOC_LITERAL(8, 123, 18), // "onBtnDeleteClicked"
QT_MOC_LITERAL(9, 142, 16), // "onBtnSaveClicked"
QT_MOC_LITERAL(10, 159, 18), // "onBtnSubmitClicked"
QT_MOC_LITERAL(11, 178, 20), // "onMyLabelxmjlClicked"
QT_MOC_LITERAL(12, 199, 19), // "onMyLabelzhbClicked"
QT_MOC_LITERAL(13, 219, 19) // "onMyLabelzjbClicked"

    },
    "WidgetWZGL\0sig_tableIsNotOpen\0\0"
    "onsig_forwzgl\0UserInfo&\0onMyLabelCreateClicked\0"
    "onMyLabelImportClicked\0onMyLabelPrintClicked\0"
    "onBtnDeleteClicked\0onBtnSaveClicked\0"
    "onBtnSubmitClicked\0onMyLabelxmjlClicked\0"
    "onMyLabelzhbClicked\0onMyLabelzjbClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WidgetWZGL[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   70,    2, 0x0a /* Public */,
       5,    0,   73,    2, 0x0a /* Public */,
       6,    0,   74,    2, 0x0a /* Public */,
       7,    0,   75,    2, 0x0a /* Public */,
       8,    0,   76,    2, 0x0a /* Public */,
       9,    0,   77,    2, 0x0a /* Public */,
      10,    0,   78,    2, 0x0a /* Public */,
      11,    0,   79,    2, 0x0a /* Public */,
      12,    0,   80,    2, 0x0a /* Public */,
      13,    0,   81,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WidgetWZGL::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WidgetWZGL *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_tableIsNotOpen(); break;
        case 1: _t->onsig_forwzgl((*reinterpret_cast< UserInfo(*)>(_a[1]))); break;
        case 2: _t->onMyLabelCreateClicked(); break;
        case 3: _t->onMyLabelImportClicked(); break;
        case 4: _t->onMyLabelPrintClicked(); break;
        case 5: _t->onBtnDeleteClicked(); break;
        case 6: _t->onBtnSaveClicked(); break;
        case 7: _t->onBtnSubmitClicked(); break;
        case 8: _t->onMyLabelxmjlClicked(); break;
        case 9: _t->onMyLabelzhbClicked(); break;
        case 10: _t->onMyLabelzjbClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WidgetWZGL::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WidgetWZGL::sig_tableIsNotOpen)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WidgetWZGL::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_WidgetWZGL.data,
    qt_meta_data_WidgetWZGL,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WidgetWZGL::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WidgetWZGL::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WidgetWZGL.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int WidgetWZGL::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void WidgetWZGL::sig_tableIsNotOpen()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
