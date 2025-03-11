/****************************************************************************
** Meta object code from reading C++ file 'modbustcp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../modbustcp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'modbustcp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ModbusTCP_t {
    QByteArrayData data[36];
    char stringdata0[719];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ModbusTCP_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ModbusTCP_t qt_meta_stringdata_ModbusTCP = {
    {
QT_MOC_LITERAL(0, 0, 9), // "ModbusTCP"
QT_MOC_LITERAL(1, 10, 10), // "ModbusFunc"
QT_MOC_LITERAL(2, 21, 20), // "MB_READ_HOLDING_REGS"
QT_MOC_LITERAL(3, 42, 22), // "MB_WRITE_MULTIPLE_REGS"
QT_MOC_LITERAL(4, 65, 11), // "ModbusError"
QT_MOC_LITERAL(5, 77, 11), // "ERR_SUCCESS"
QT_MOC_LITERAL(6, 89, 20), // "ERR_ILLEGAL_FUNCTION"
QT_MOC_LITERAL(7, 110, 24), // "ERR_ILLEGAL_DATA_ADDRESS"
QT_MOC_LITERAL(8, 135, 22), // "ERR_ILLEGAL_DATA_VALUE"
QT_MOC_LITERAL(9, 158, 24), // "ERR_SLAVE_DEVICE_FAILURE"
QT_MOC_LITERAL(10, 183, 15), // "ERR_ACKNOWLEDGE"
QT_MOC_LITERAL(11, 199, 21), // "ERR_SLAVE_DEVICE_BUSY"
QT_MOC_LITERAL(12, 221, 24), // "ERR_NEGATIVE_ACKNOWLEDGE"
QT_MOC_LITERAL(13, 246, 23), // "ERR_MEMORY_PARITY_ERROR"
QT_MOC_LITERAL(14, 270, 17), // "ERR_NO_CONNECTION"
QT_MOC_LITERAL(15, 288, 23), // "ERR_GW_PATH_UNAVAILABLE"
QT_MOC_LITERAL(16, 312, 28), // "ERR_GW_TARGET_FAILED_TO_RESP"
QT_MOC_LITERAL(17, 341, 18), // "ERR_CANT_OPEN_PORT"
QT_MOC_LITERAL(18, 360, 14), // "ERR_BAD_PARAMS"
QT_MOC_LITERAL(19, 375, 15), // "ERR_INIT_FAILED"
QT_MOC_LITERAL(20, 391, 15), // "ERR_NOT_RESPOND"
QT_MOC_LITERAL(21, 407, 22), // "ERR_FUNC_NOT_SUPPORTED"
QT_MOC_LITERAL(22, 430, 17), // "ERR_BAD_DATA_BUFF"
QT_MOC_LITERAL(23, 448, 14), // "ERR_CRC_FAILED"
QT_MOC_LITERAL(24, 463, 23), // "ERR_BAD_RESPONSE_LENGTH"
QT_MOC_LITERAL(25, 487, 21), // "ERR_BAD_RESPONSE_FUNC"
QT_MOC_LITERAL(26, 509, 24), // "ERR_BAD_RESPONSE_ADDRESS"
QT_MOC_LITERAL(27, 534, 22), // "ERR_BAD_RESPONSE_COUNT"
QT_MOC_LITERAL(28, 557, 22), // "ERR_BAD_RESPONSE_VALUE"
QT_MOC_LITERAL(29, 580, 18), // "ERR_BAD_DATA_COUNT"
QT_MOC_LITERAL(30, 599, 18), // "ERR_BAD_DATA_VALUE"
QT_MOC_LITERAL(31, 618, 26), // "ERR_BAD_EXCERTION_RESPONSE"
QT_MOC_LITERAL(32, 645, 22), // "ERR_UNDEFINED_PROTOCOL"
QT_MOC_LITERAL(33, 668, 13), // "ERR_SEARCHING"
QT_MOC_LITERAL(34, 682, 18), // "ERR_NO_SUCH_DEVICE"
QT_MOC_LITERAL(35, 701, 17) // "ERR_CONNECT_ABORT"

    },
    "ModbusTCP\0ModbusFunc\0MB_READ_HOLDING_REGS\0"
    "MB_WRITE_MULTIPLE_REGS\0ModbusError\0"
    "ERR_SUCCESS\0ERR_ILLEGAL_FUNCTION\0"
    "ERR_ILLEGAL_DATA_ADDRESS\0"
    "ERR_ILLEGAL_DATA_VALUE\0ERR_SLAVE_DEVICE_FAILURE\0"
    "ERR_ACKNOWLEDGE\0ERR_SLAVE_DEVICE_BUSY\0"
    "ERR_NEGATIVE_ACKNOWLEDGE\0"
    "ERR_MEMORY_PARITY_ERROR\0ERR_NO_CONNECTION\0"
    "ERR_GW_PATH_UNAVAILABLE\0"
    "ERR_GW_TARGET_FAILED_TO_RESP\0"
    "ERR_CANT_OPEN_PORT\0ERR_BAD_PARAMS\0"
    "ERR_INIT_FAILED\0ERR_NOT_RESPOND\0"
    "ERR_FUNC_NOT_SUPPORTED\0ERR_BAD_DATA_BUFF\0"
    "ERR_CRC_FAILED\0ERR_BAD_RESPONSE_LENGTH\0"
    "ERR_BAD_RESPONSE_FUNC\0ERR_BAD_RESPONSE_ADDRESS\0"
    "ERR_BAD_RESPONSE_COUNT\0ERR_BAD_RESPONSE_VALUE\0"
    "ERR_BAD_DATA_COUNT\0ERR_BAD_DATA_VALUE\0"
    "ERR_BAD_EXCERTION_RESPONSE\0"
    "ERR_UNDEFINED_PROTOCOL\0ERR_SEARCHING\0"
    "ERR_NO_SUCH_DEVICE\0ERR_CONNECT_ABORT"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ModbusTCP[] = {

 // content:
       8,       // revision
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

void ModbusTCP::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject ModbusTCP::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ModbusTCP.data,
    qt_meta_data_ModbusTCP,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ModbusTCP::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModbusTCP::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ModbusTCP.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ModbusTCP::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
