/****************************************************************************
** Meta object code from reading C++ file 'wifi.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../wifi.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wifi.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WiFi_t {
    QByteArrayData data[25];
    char stringdata0[353];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WiFi_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WiFi_t qt_meta_stringdata_WiFi = {
    {
QT_MOC_LITERAL(0, 0, 4), // "WiFi"
QT_MOC_LITERAL(1, 5, 8), // "startSig"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 11), // "wifiNameQml"
QT_MOC_LITERAL(4, 27, 4), // "name"
QT_MOC_LITERAL(5, 32, 14), // "connectWiFiSig"
QT_MOC_LITERAL(6, 47, 8), // "password"
QT_MOC_LITERAL(7, 56, 21), // "connectCurrentNameSig"
QT_MOC_LITERAL(8, 78, 17), // "disconnectWiFiSig"
QT_MOC_LITERAL(9, 96, 20), // "disCurrentWifiSigQml"
QT_MOC_LITERAL(10, 117, 12), // "closeWiFiSig"
QT_MOC_LITERAL(11, 130, 13), // "onWifiNameSig"
QT_MOC_LITERAL(12, 144, 26), // "onWifiConnectSuccessfulSig"
QT_MOC_LITERAL(13, 171, 13), // "onRunScanWiFi"
QT_MOC_LITERAL(14, 185, 26), // "onDisConnectCurrentWiFiSig"
QT_MOC_LITERAL(15, 212, 20), // "onCloseWiFiThreadSig"
QT_MOC_LITERAL(16, 233, 8), // "scanWiFi"
QT_MOC_LITERAL(17, 242, 11), // "connectWiFi"
QT_MOC_LITERAL(18, 254, 11), // "runScanWiFi"
QT_MOC_LITERAL(19, 266, 9), // "closeWiFi"
QT_MOC_LITERAL(20, 276, 14), // "disconnectWiFi"
QT_MOC_LITERAL(21, 291, 19), // "setWifiCurrentState"
QT_MOC_LITERAL(22, 311, 5), // "state"
QT_MOC_LITERAL(23, 317, 19), // "getWifiCurrentState"
QT_MOC_LITERAL(24, 337, 15) // "getWifiNameList"

    },
    "WiFi\0startSig\0\0wifiNameQml\0name\0"
    "connectWiFiSig\0password\0connectCurrentNameSig\0"
    "disconnectWiFiSig\0disCurrentWifiSigQml\0"
    "closeWiFiSig\0onWifiNameSig\0"
    "onWifiConnectSuccessfulSig\0onRunScanWiFi\0"
    "onDisConnectCurrentWiFiSig\0"
    "onCloseWiFiThreadSig\0scanWiFi\0connectWiFi\0"
    "runScanWiFi\0closeWiFi\0disconnectWiFi\0"
    "setWifiCurrentState\0state\0getWifiCurrentState\0"
    "getWifiNameList"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WiFi[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  114,    2, 0x06 /* Public */,
       3,    1,  115,    2, 0x06 /* Public */,
       5,    2,  118,    2, 0x06 /* Public */,
       7,    1,  123,    2, 0x06 /* Public */,
       8,    0,  126,    2, 0x06 /* Public */,
       9,    0,  127,    2, 0x06 /* Public */,
      10,    0,  128,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    1,  129,    2, 0x0a /* Public */,
      12,    1,  132,    2, 0x0a /* Public */,
      13,    0,  135,    2, 0x0a /* Public */,
      14,    0,  136,    2, 0x0a /* Public */,
      15,    0,  137,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      16,    0,  138,    2, 0x02 /* Public */,
      17,    2,  139,    2, 0x02 /* Public */,
      18,    0,  144,    2, 0x02 /* Public */,
      19,    0,  145,    2, 0x02 /* Public */,
      20,    0,  146,    2, 0x02 /* Public */,
      21,    1,  147,    2, 0x02 /* Public */,
      23,    0,  150,    2, 0x02 /* Public */,
      24,    0,  151,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    4,    6,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    4,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   22,
    QMetaType::Bool,
    QMetaType::QStringList,

       0        // eod
};

void WiFi::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WiFi *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startSig(); break;
        case 1: _t->wifiNameQml((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 2: _t->connectWiFiSig((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->connectCurrentNameSig((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->disconnectWiFiSig(); break;
        case 5: _t->disCurrentWifiSigQml(); break;
        case 6: _t->closeWiFiSig(); break;
        case 7: _t->onWifiNameSig((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 8: _t->onWifiConnectSuccessfulSig((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->onRunScanWiFi(); break;
        case 10: _t->onDisConnectCurrentWiFiSig(); break;
        case 11: _t->onCloseWiFiThreadSig(); break;
        case 12: _t->scanWiFi(); break;
        case 13: _t->connectWiFi((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 14: _t->runScanWiFi(); break;
        case 15: _t->closeWiFi(); break;
        case 16: _t->disconnectWiFi(); break;
        case 17: _t->setWifiCurrentState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: { bool _r = _t->getWifiCurrentState();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 19: { QStringList _r = _t->getWifiNameList();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WiFi::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WiFi::startSig)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (WiFi::*)(QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WiFi::wifiNameQml)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (WiFi::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WiFi::connectWiFiSig)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (WiFi::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WiFi::connectCurrentNameSig)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (WiFi::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WiFi::disconnectWiFiSig)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (WiFi::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WiFi::disCurrentWifiSigQml)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (WiFi::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WiFi::closeWiFiSig)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WiFi::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_WiFi.data,
    qt_meta_data_WiFi,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WiFi::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WiFi::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WiFi.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int WiFi::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void WiFi::startSig()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void WiFi::wifiNameQml(QStringList _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void WiFi::connectWiFiSig(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void WiFi::connectCurrentNameSig(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void WiFi::disconnectWiFiSig()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void WiFi::disCurrentWifiSigQml()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void WiFi::closeWiFiSig()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
