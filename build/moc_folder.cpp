/****************************************************************************
** Meta object code from reading C++ file 'folder.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../folder.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'folder.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Folder_t {
    QByteArrayData data[19];
    char stringdata0[194];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Folder_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Folder_t qt_meta_stringdata_Folder = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Folder"
QT_MOC_LITERAL(1, 7, 12), // "sigDelFolder"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 13), // "SigEditFolder"
QT_MOC_LITERAL(4, 35, 15), // "updataFolderSig"
QT_MOC_LITERAL(5, 51, 4), // "path"
QT_MOC_LITERAL(6, 56, 11), // "comeBackSig"
QT_MOC_LITERAL(7, 68, 11), // "getTotalBuf"
QT_MOC_LITERAL(8, 80, 14), // "getTotalUsable"
QT_MOC_LITERAL(9, 95, 13), // "getFolderList"
QT_MOC_LITERAL(10, 109, 11), // "getFileList"
QT_MOC_LITERAL(11, 121, 12), // "deleteFolder"
QT_MOC_LITERAL(12, 134, 4), // "name"
QT_MOC_LITERAL(13, 139, 9), // "addFolder"
QT_MOC_LITERAL(14, 149, 10), // "editFolder"
QT_MOC_LITERAL(15, 160, 7), // "oldName"
QT_MOC_LITERAL(16, 168, 7), // "newName"
QT_MOC_LITERAL(17, 176, 8), // "inFolder"
QT_MOC_LITERAL(18, 185, 8) // "comeBack"

    },
    "Folder\0sigDelFolder\0\0SigEditFolder\0"
    "updataFolderSig\0path\0comeBackSig\0"
    "getTotalBuf\0getTotalUsable\0getFolderList\0"
    "getFileList\0deleteFolder\0name\0addFolder\0"
    "editFolder\0oldName\0newName\0inFolder\0"
    "comeBack"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Folder[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    0,   80,    2, 0x06 /* Public */,
       4,    1,   81,    2, 0x06 /* Public */,
       6,    0,   84,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       7,    0,   85,    2, 0x02 /* Public */,
       8,    0,   86,    2, 0x02 /* Public */,
       9,    0,   87,    2, 0x02 /* Public */,
      10,    0,   88,    2, 0x02 /* Public */,
      11,    1,   89,    2, 0x02 /* Public */,
      13,    1,   92,    2, 0x02 /* Public */,
      14,    2,   95,    2, 0x02 /* Public */,
      17,    1,  100,    2, 0x02 /* Public */,
      18,    0,  103,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,

 // methods: parameters
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QStringList,
    QMetaType::QStringList,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   15,   16,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,

       0        // eod
};

void Folder::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Folder *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigDelFolder(); break;
        case 1: _t->SigEditFolder(); break;
        case 2: _t->updataFolderSig((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->comeBackSig(); break;
        case 4: { QString _r = _t->getTotalBuf();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 5: { QString _r = _t->getTotalUsable();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 6: { QStringList _r = _t->getFolderList();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 7: { QStringList _r = _t->getFileList();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->deleteFolder((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->addFolder((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->editFolder((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 11: _t->inFolder((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->comeBack(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Folder::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Folder::sigDelFolder)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Folder::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Folder::SigEditFolder)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Folder::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Folder::updataFolderSig)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Folder::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Folder::comeBackSig)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Folder::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Folder.data,
    qt_meta_data_Folder,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Folder::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Folder::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Folder.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Folder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void Folder::sigDelFolder()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Folder::SigEditFolder()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Folder::updataFolderSig(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Folder::comeBackSig()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
