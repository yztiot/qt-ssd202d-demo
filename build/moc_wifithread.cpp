/****************************************************************************
** Meta object code from reading C++ file 'wifithread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../wifithread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wifithread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WiFiThread_t {
    QByteArrayData data[12];
    char stringdata0[174];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WiFiThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WiFiThread_t qt_meta_stringdata_WiFiThread = {
    {
QT_MOC_LITERAL(0, 0, 10), // "WiFiThread"
QT_MOC_LITERAL(1, 11, 11), // "wifiNameSig"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 4), // "name"
QT_MOC_LITERAL(4, 29, 24), // "wifiConnectSuccessfulSig"
QT_MOC_LITERAL(5, 54, 24), // "disConnectCurrentWiFiSig"
QT_MOC_LITERAL(6, 79, 18), // "closeWiFiThreadSig"
QT_MOC_LITERAL(7, 98, 14), // "createWifiFile"
QT_MOC_LITERAL(8, 113, 16), // "onConnectWiFiSig"
QT_MOC_LITERAL(9, 130, 8), // "password"
QT_MOC_LITERAL(10, 139, 19), // "onDisConnectWiFiSig"
QT_MOC_LITERAL(11, 159, 14) // "onCloseWifiSig"

    },
    "WiFiThread\0wifiNameSig\0\0name\0"
    "wifiConnectSuccessfulSig\0"
    "disConnectCurrentWiFiSig\0closeWiFiThreadSig\0"
    "createWifiFile\0onConnectWiFiSig\0"
    "password\0onDisConnectWiFiSig\0"
    "onCloseWifiSig"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WiFiThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    1,   57,    2, 0x06 /* Public */,
       5,    0,   60,    2, 0x06 /* Public */,
       6,    0,   61,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   62,    2, 0x0a /* Public */,
       8,    2,   63,    2, 0x0a /* Public */,
      10,    0,   68,    2, 0x0a /* Public */,
      11,    0,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QStringList,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    9,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WiFiThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WiFiThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->wifiNameSig((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 1: _t->wifiConnectSuccessfulSig((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->disConnectCurrentWiFiSig(); break;
        case 3: _t->closeWiFiThreadSig(); break;
        case 4: _t->createWifiFile(); break;
        case 5: _t->onConnectWiFiSig((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: _t->onDisConnectWiFiSig(); break;
        case 7: _t->onCloseWifiSig(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WiFiThread::*)(QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WiFiThread::wifiNameSig)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (WiFiThread::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WiFiThread::wifiConnectSuccessfulSig)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (WiFiThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WiFiThread::disConnectCurrentWiFiSig)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (WiFiThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WiFiThread::closeWiFiThreadSig)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WiFiThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_WiFiThread.data,
    qt_meta_data_WiFiThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WiFiThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WiFiThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WiFiThread.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int WiFiThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void WiFiThread::wifiNameSig(QStringList _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WiFiThread::wifiConnectSuccessfulSig(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void WiFiThread::disConnectCurrentWiFiSig()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void WiFiThread::closeWiFiThreadSig()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
