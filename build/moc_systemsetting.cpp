/****************************************************************************
** Meta object code from reading C++ file 'systemsetting.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../systemsetting.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'systemsetting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SystemSetting_t {
    QByteArrayData data[16];
    char stringdata0[183];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SystemSetting_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SystemSetting_t qt_meta_stringdata_SystemSetting = {
    {
QT_MOC_LITERAL(0, 0, 13), // "SystemSetting"
QT_MOC_LITERAL(1, 14, 13), // "updateTimeSig"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 13), // "screenSaveSig"
QT_MOC_LITERAL(4, 43, 19), // "onScreenSaveTimeOut"
QT_MOC_LITERAL(5, 63, 10), // "setSysTime"
QT_MOC_LITERAL(6, 74, 5), // "timer"
QT_MOC_LITERAL(7, 80, 11), // "setSysLight"
QT_MOC_LITERAL(8, 92, 8), // "lightNum"
QT_MOC_LITERAL(9, 101, 11), // "getSysLight"
QT_MOC_LITERAL(10, 113, 9), // "setSysVol"
QT_MOC_LITERAL(11, 123, 6), // "volNum"
QT_MOC_LITERAL(12, 130, 13), // "setScreenSave"
QT_MOC_LITERAL(13, 144, 4), // "time"
QT_MOC_LITERAL(14, 149, 14), // "openScreenSave"
QT_MOC_LITERAL(15, 164, 18) // "getScreenSaveModel"

    },
    "SystemSetting\0updateTimeSig\0\0screenSaveSig\0"
    "onScreenSaveTimeOut\0setSysTime\0timer\0"
    "setSysLight\0lightNum\0getSysLight\0"
    "setSysVol\0volNum\0setScreenSave\0time\0"
    "openScreenSave\0getScreenSaveModel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SystemSetting[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   61,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
       5,    1,   62,    2, 0x02 /* Public */,
       7,    1,   65,    2, 0x02 /* Public */,
       9,    0,   68,    2, 0x02 /* Public */,
      10,    1,   69,    2, 0x02 /* Public */,
      12,    2,   72,    2, 0x02 /* Public */,
      15,    0,   77,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Int,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   13,   14,
    QMetaType::QString,

       0        // eod
};

void SystemSetting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SystemSetting *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateTimeSig(); break;
        case 1: _t->screenSaveSig(); break;
        case 2: _t->onScreenSaveTimeOut(); break;
        case 3: _t->setSysTime((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->setSysLight((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: { int _r = _t->getSysLight();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->setSysVol((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->setScreenSave((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 8: { QString _r = _t->getScreenSaveModel();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SystemSetting::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SystemSetting::updateTimeSig)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SystemSetting::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SystemSetting::screenSaveSig)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SystemSetting::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_SystemSetting.data,
    qt_meta_data_SystemSetting,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SystemSetting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SystemSetting::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SystemSetting.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SystemSetting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void SystemSetting::updateTimeSig()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SystemSetting::screenSaveSig()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
