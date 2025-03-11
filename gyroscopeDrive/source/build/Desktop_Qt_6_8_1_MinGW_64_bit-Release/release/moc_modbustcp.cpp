/****************************************************************************
** Meta object code from reading C++ file 'modbustcp.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../modbustcp.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'modbustcp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN9ModbusTCPE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN9ModbusTCPE = QtMocHelpers::stringData(
    "ModbusTCP",
    "ModbusFunc",
    "MB_READ_HOLDING_REGS",
    "MB_WRITE_MULTIPLE_REGS",
    "ModbusError",
    "ERR_SUCCESS",
    "ERR_ILLEGAL_FUNCTION",
    "ERR_ILLEGAL_DATA_ADDRESS",
    "ERR_ILLEGAL_DATA_VALUE",
    "ERR_SLAVE_DEVICE_FAILURE",
    "ERR_ACKNOWLEDGE",
    "ERR_SLAVE_DEVICE_BUSY",
    "ERR_NEGATIVE_ACKNOWLEDGE",
    "ERR_MEMORY_PARITY_ERROR",
    "ERR_NO_CONNECTION",
    "ERR_GW_PATH_UNAVAILABLE",
    "ERR_GW_TARGET_FAILED_TO_RESP",
    "ERR_CANT_OPEN_PORT",
    "ERR_BAD_PARAMS",
    "ERR_INIT_FAILED",
    "ERR_NOT_RESPOND",
    "ERR_FUNC_NOT_SUPPORTED",
    "ERR_BAD_DATA_BUFF",
    "ERR_CRC_FAILED",
    "ERR_BAD_RESPONSE_LENGTH",
    "ERR_BAD_RESPONSE_FUNC",
    "ERR_BAD_RESPONSE_ADDRESS",
    "ERR_BAD_RESPONSE_COUNT",
    "ERR_BAD_RESPONSE_VALUE",
    "ERR_BAD_DATA_COUNT",
    "ERR_BAD_DATA_VALUE",
    "ERR_BAD_EXCERTION_RESPONSE",
    "ERR_UNDEFINED_PROTOCOL",
    "ERR_SEARCHING",
    "ERR_NO_SUCH_DEVICE",
    "ERR_CONNECT_ABORT"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN9ModbusTCPE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       2,   14, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // enums: name, alias, flags, count, data
       1,    1, 0x0,    2,   24,
       4,    4, 0x0,   31,   28,

 // enum data: key, value
       2, uint(ModbusTCP::MB_READ_HOLDING_REGS),
       3, uint(ModbusTCP::MB_WRITE_MULTIPLE_REGS),
       5, uint(ModbusTCP::ERR_SUCCESS),
       6, uint(ModbusTCP::ERR_ILLEGAL_FUNCTION),
       7, uint(ModbusTCP::ERR_ILLEGAL_DATA_ADDRESS),
       8, uint(ModbusTCP::ERR_ILLEGAL_DATA_VALUE),
       9, uint(ModbusTCP::ERR_SLAVE_DEVICE_FAILURE),
      10, uint(ModbusTCP::ERR_ACKNOWLEDGE),
      11, uint(ModbusTCP::ERR_SLAVE_DEVICE_BUSY),
      12, uint(ModbusTCP::ERR_NEGATIVE_ACKNOWLEDGE),
      13, uint(ModbusTCP::ERR_MEMORY_PARITY_ERROR),
      14, uint(ModbusTCP::ERR_NO_CONNECTION),
      15, uint(ModbusTCP::ERR_GW_PATH_UNAVAILABLE),
      16, uint(ModbusTCP::ERR_GW_TARGET_FAILED_TO_RESP),
      17, uint(ModbusTCP::ERR_CANT_OPEN_PORT),
      18, uint(ModbusTCP::ERR_BAD_PARAMS),
      19, uint(ModbusTCP::ERR_INIT_FAILED),
      20, uint(ModbusTCP::ERR_NOT_RESPOND),
      21, uint(ModbusTCP::ERR_FUNC_NOT_SUPPORTED),
      22, uint(ModbusTCP::ERR_BAD_DATA_BUFF),
      23, uint(ModbusTCP::ERR_CRC_FAILED),
      24, uint(ModbusTCP::ERR_BAD_RESPONSE_LENGTH),
      25, uint(ModbusTCP::ERR_BAD_RESPONSE_FUNC),
      26, uint(ModbusTCP::ERR_BAD_RESPONSE_ADDRESS),
      27, uint(ModbusTCP::ERR_BAD_RESPONSE_COUNT),
      28, uint(ModbusTCP::ERR_BAD_RESPONSE_VALUE),
      29, uint(ModbusTCP::ERR_BAD_DATA_COUNT),
      30, uint(ModbusTCP::ERR_BAD_DATA_VALUE),
      31, uint(ModbusTCP::ERR_BAD_EXCERTION_RESPONSE),
      32, uint(ModbusTCP::ERR_UNDEFINED_PROTOCOL),
      33, uint(ModbusTCP::ERR_SEARCHING),
      34, uint(ModbusTCP::ERR_NO_SUCH_DEVICE),
      35, uint(ModbusTCP::ERR_CONNECT_ABORT),

       0        // eod
};

Q_CONSTINIT const QMetaObject ModbusTCP::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ZN9ModbusTCPE.offsetsAndSizes,
    qt_meta_data_ZN9ModbusTCPE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN9ModbusTCPE_t,
        // enum 'ModbusFunc'
        QtPrivate::TypeAndForceComplete<ModbusTCP::ModbusFunc, std::true_type>,
        // enum 'ModbusError'
        QtPrivate::TypeAndForceComplete<ModbusTCP::ModbusError, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ModbusTCP, std::true_type>
    >,
    nullptr
} };

void ModbusTCP::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ModbusTCP *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *ModbusTCP::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModbusTCP::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN9ModbusTCPE.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ModbusTCP::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
