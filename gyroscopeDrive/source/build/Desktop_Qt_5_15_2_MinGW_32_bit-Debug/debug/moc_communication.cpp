/****************************************************************************
** Meta object code from reading C++ file 'communication.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../communication.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'communication.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_COMMUNICATION_t {
    QByteArrayData data[15];
    char stringdata0[174];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_COMMUNICATION_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_COMMUNICATION_t qt_meta_stringdata_COMMUNICATION = {
    {
QT_MOC_LITERAL(0, 0, 13), // "COMMUNICATION"
QT_MOC_LITERAL(1, 14, 13), // "btnDevConnect"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 9), // "ipAddress"
QT_MOC_LITERAL(4, 39, 6), // "number"
QT_MOC_LITERAL(5, 46, 16), // "btnDevDisconnect"
QT_MOC_LITERAL(6, 63, 11), // "isConnected"
QT_MOC_LITERAL(7, 75, 12), // "btnDevEnable"
QT_MOC_LITERAL(8, 88, 13), // "btnDevEnable2"
QT_MOC_LITERAL(9, 102, 13), // "btnDevDisable"
QT_MOC_LITERAL(10, 116, 13), // "btnDev1SetPos"
QT_MOC_LITERAL(11, 130, 3), // "pos"
QT_MOC_LITERAL(12, 134, 13), // "btnDev2SetPos"
QT_MOC_LITERAL(13, 148, 12), // "readPosition"
QT_MOC_LITERAL(14, 161, 12) // "deviceNumber"

    },
    "COMMUNICATION\0btnDevConnect\0\0ipAddress\0"
    "number\0btnDevDisconnect\0isConnected\0"
    "btnDevEnable\0btnDevEnable2\0btnDevDisable\0"
    "btnDev1SetPos\0pos\0btnDev2SetPos\0"
    "readPosition\0deviceNumber"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_COMMUNICATION[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    2,   59,    2, 0x02 /* Public */,
       5,    1,   64,    2, 0x02 /* Public */,
       6,    1,   67,    2, 0x02 /* Public */,
       7,    1,   70,    2, 0x02 /* Public */,
       8,    1,   73,    2, 0x02 /* Public */,
       9,    1,   76,    2, 0x02 /* Public */,
      10,    1,   79,    2, 0x02 /* Public */,
      12,    1,   82,    2, 0x02 /* Public */,
      13,    1,   85,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::Int, QMetaType::QString, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Bool, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Int, QMetaType::Int,   14,

       0        // eod
};

void COMMUNICATION::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<COMMUNICATION *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { int _r = _t->btnDevConnect((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->btnDevDisconnect((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: { bool _r = _t->isConnected((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->btnDevEnable((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->btnDevEnable2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->btnDevDisable((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->btnDev1SetPos((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->btnDev2SetPos((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: { int _r = _t->readPosition((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject COMMUNICATION::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_COMMUNICATION.data,
    qt_meta_data_COMMUNICATION,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *COMMUNICATION::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *COMMUNICATION::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_COMMUNICATION.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int COMMUNICATION::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
