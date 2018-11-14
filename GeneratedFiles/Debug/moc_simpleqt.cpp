/****************************************************************************
** Meta object code from reading C++ file 'simpleqt.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../simpleqt.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'simpleqt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SimpleQt_t {
    QByteArrayData data[13];
    char stringdata0[129];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SimpleQt_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SimpleQt_t qt_meta_stringdata_SimpleQt = {
    {
QT_MOC_LITERAL(0, 0, 8), // "SimpleQt"
QT_MOC_LITERAL(1, 9, 5), // "about"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 13), // "toggleToolbar"
QT_MOC_LITERAL(4, 30, 13), // "toggleCtrlbar"
QT_MOC_LITERAL(5, 44, 14), // "onFirstStartup"
QT_MOC_LITERAL(6, 59, 13), // "CreateInfoDlg"
QT_MOC_LITERAL(7, 73, 6), // "onPlay"
QT_MOC_LITERAL(8, 80, 6), // "onStop"
QT_MOC_LITERAL(9, 87, 10), // "showPixmap"
QT_MOC_LITERAL(10, 98, 7), // "QImage*"
QT_MOC_LITERAL(11, 106, 11), // "startRecord"
QT_MOC_LITERAL(12, 118, 10) // "stopRecord"

    },
    "SimpleQt\0about\0\0toggleToolbar\0"
    "toggleCtrlbar\0onFirstStartup\0CreateInfoDlg\0"
    "onPlay\0onStop\0showPixmap\0QImage*\0"
    "startRecord\0stopRecord"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SimpleQt[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x0a /* Public */,
       3,    0,   65,    2, 0x0a /* Public */,
       4,    0,   66,    2, 0x0a /* Public */,
       5,    0,   67,    2, 0x0a /* Public */,
       6,    0,   68,    2, 0x0a /* Public */,
       7,    0,   69,    2, 0x0a /* Public */,
       8,    0,   70,    2, 0x0a /* Public */,
       9,    2,   71,    2, 0x0a /* Public */,
      11,    0,   76,    2, 0x0a /* Public */,
      12,    0,   77,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SimpleQt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SimpleQt *_t = static_cast<SimpleQt *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->about(); break;
        case 1: _t->toggleToolbar(); break;
        case 2: _t->toggleCtrlbar(); break;
        case 3: _t->onFirstStartup(); break;
        case 4: _t->CreateInfoDlg(); break;
        case 5: _t->onPlay(); break;
        case 6: _t->onStop(); break;
        case 7: _t->showPixmap((*reinterpret_cast< QImage*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->startRecord(); break;
        case 9: _t->stopRecord(); break;
        default: ;
        }
    }
}

const QMetaObject SimpleQt::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SimpleQt.data,
      qt_meta_data_SimpleQt,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SimpleQt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SimpleQt::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SimpleQt.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int SimpleQt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
