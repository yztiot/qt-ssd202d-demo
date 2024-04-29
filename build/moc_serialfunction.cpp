/****************************************************************************
** Meta object code from reading C++ file 'serialfunction.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../serialfunction.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serialfunction.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SerialFunction_t {
    QByteArrayData data[21];
    char stringdata0[197];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SerialFunction_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SerialFunction_t qt_meta_stringdata_SerialFunction = {
    {
QT_MOC_LITERAL(0, 0, 14), // "SerialFunction"
QT_MOC_LITERAL(1, 15, 13), // "serialDataSig"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 8), // "startSig"
QT_MOC_LITERAL(4, 39, 8), // "writeSig"
QT_MOC_LITERAL(5, 48, 4), // "data"
QT_MOC_LITERAL(6, 53, 14), // "openSerialFail"
QT_MOC_LITERAL(7, 68, 4), // "info"
QT_MOC_LITERAL(8, 73, 20), // "openSerialSuccessful"
QT_MOC_LITERAL(9, 94, 10), // "serialName"
QT_MOC_LITERAL(10, 105, 6), // "tipSig"
QT_MOC_LITERAL(11, 112, 3), // "tip"
QT_MOC_LITERAL(12, 116, 8), // "readData"
QT_MOC_LITERAL(13, 125, 10), // "openSerial"
QT_MOC_LITERAL(14, 136, 4), // "raud"
QT_MOC_LITERAL(15, 141, 3), // "bit"
QT_MOC_LITERAL(16, 145, 5), // "check"
QT_MOC_LITERAL(17, 151, 4), // "stop"
QT_MOC_LITERAL(18, 156, 13), // "runOpenSerial"
QT_MOC_LITERAL(19, 170, 11), // "closeSerial"
QT_MOC_LITERAL(20, 182, 14) // "writeSerialSig"

    },
    "SerialFunction\0serialDataSig\0\0startSig\0"
    "writeSig\0data\0openSerialFail\0info\0"
    "openSerialSuccessful\0serialName\0tipSig\0"
    "tip\0readData\0openSerial\0raud\0bit\0check\0"
    "stop\0runOpenSerial\0closeSerial\0"
    "writeSerialSig"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SerialFunction[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       3,    0,   72,    2, 0x06 /* Public */,
       4,    1,   73,    2, 0x06 /* Public */,
       6,    1,   76,    2, 0x06 /* Public */,
       8,    1,   79,    2, 0x06 /* Public */,
      10,    1,   82,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    1,   85,    2, 0x0a /* Public */,
      13,    4,   88,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      18,    4,   97,    2, 0x02 /* Public */,
      19,    0,  106,    2, 0x02 /* Public */,
      20,    1,  107,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,   11,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   14,   15,   16,   17,

 // methods: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   14,   15,   16,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,

       0        // eod
};

void SerialFunction::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SerialFunction *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->serialDataSig((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->startSig(); break;
        case 2: _t->writeSig((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->openSerialFail((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->openSerialSuccessful((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->tipSig((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->readData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->openSerial((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 8: _t->runOpenSerial((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 9: _t->closeSerial(); break;
        case 10: _t->writeSerialSig((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SerialFunction::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialFunction::serialDataSig)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SerialFunction::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialFunction::startSig)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SerialFunction::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialFunction::writeSig)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SerialFunction::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialFunction::openSerialFail)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (SerialFunction::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialFunction::openSerialSuccessful)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (SerialFunction::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialFunction::tipSig)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SerialFunction::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_SerialFunction.data,
    qt_meta_data_SerialFunction,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SerialFunction::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SerialFunction::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SerialFunction.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SerialFunction::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void SerialFunction::serialDataSig(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SerialFunction::startSig()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void SerialFunction::writeSig(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SerialFunction::openSerialFail(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void SerialFunction::openSerialSuccessful(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void SerialFunction::tipSig(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
