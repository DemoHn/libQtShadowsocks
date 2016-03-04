/****************************************************************************
** Meta object code from reading C++ file 'tcprelay.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../lib/tcprelay.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcprelay.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QSS__TcpRelay_t {
    QByteArrayData data[18];
    char stringdata0[233];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QSS__TcpRelay_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QSS__TcpRelay_t qt_meta_stringdata_QSS__TcpRelay = {
    {
QT_MOC_LITERAL(0, 0, 13), // "QSS::TcpRelay"
QT_MOC_LITERAL(1, 14, 5), // "debug"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 4), // "info"
QT_MOC_LITERAL(4, 26, 9), // "bytesRead"
QT_MOC_LITERAL(5, 36, 9), // "bytesSend"
QT_MOC_LITERAL(6, 46, 16), // "latencyAvailable"
QT_MOC_LITERAL(7, 63, 8), // "finished"
QT_MOC_LITERAL(8, 72, 13), // "onDNSResolved"
QT_MOC_LITERAL(9, 86, 7), // "success"
QT_MOC_LITERAL(10, 94, 6), // "errStr"
QT_MOC_LITERAL(11, 101, 17), // "onRemoteConnected"
QT_MOC_LITERAL(12, 119, 22), // "onRemoteTcpSocketError"
QT_MOC_LITERAL(13, 142, 26), // "onRemoteTcpSocketReadyRead"
QT_MOC_LITERAL(14, 169, 21), // "onLocalTcpSocketError"
QT_MOC_LITERAL(15, 191, 25), // "onLocalTcpSocketReadyRead"
QT_MOC_LITERAL(16, 217, 9), // "onTimeout"
QT_MOC_LITERAL(17, 227, 5) // "close"

    },
    "QSS::TcpRelay\0debug\0\0info\0bytesRead\0"
    "bytesSend\0latencyAvailable\0finished\0"
    "onDNSResolved\0success\0errStr\0"
    "onRemoteConnected\0onRemoteTcpSocketError\0"
    "onRemoteTcpSocketReadyRead\0"
    "onLocalTcpSocketError\0onLocalTcpSocketReadyRead\0"
    "onTimeout\0close"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QSS__TcpRelay[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       3,    1,   87,    2, 0x06 /* Public */,
       4,    1,   90,    2, 0x06 /* Public */,
       5,    1,   93,    2, 0x06 /* Public */,
       6,    1,   96,    2, 0x06 /* Public */,
       7,    0,   99,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    2,  100,    2, 0x08 /* Private */,
      11,    0,  105,    2, 0x08 /* Private */,
      12,    0,  106,    2, 0x08 /* Private */,
      13,    0,  107,    2, 0x08 /* Private */,
      14,    0,  108,    2, 0x08 /* Private */,
      15,    0,  109,    2, 0x08 /* Private */,
      16,    0,  110,    2, 0x08 /* Private */,
      17,    0,  111,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QSS::TcpRelay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TcpRelay *_t = static_cast<TcpRelay *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->debug((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->info((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->bytesRead((*reinterpret_cast< const qint64(*)>(_a[1]))); break;
        case 3: _t->bytesSend((*reinterpret_cast< const qint64(*)>(_a[1]))); break;
        case 4: _t->latencyAvailable((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 5: _t->finished(); break;
        case 6: _t->onDNSResolved((*reinterpret_cast< const bool(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 7: _t->onRemoteConnected(); break;
        case 8: _t->onRemoteTcpSocketError(); break;
        case 9: _t->onRemoteTcpSocketReadyRead(); break;
        case 10: _t->onLocalTcpSocketError(); break;
        case 11: _t->onLocalTcpSocketReadyRead(); break;
        case 12: _t->onTimeout(); break;
        case 13: _t->close(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TcpRelay::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpRelay::debug)) {
                *result = 0;
            }
        }
        {
            typedef void (TcpRelay::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpRelay::info)) {
                *result = 1;
            }
        }
        {
            typedef void (TcpRelay::*_t)(const qint64 & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpRelay::bytesRead)) {
                *result = 2;
            }
        }
        {
            typedef void (TcpRelay::*_t)(const qint64 & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpRelay::bytesSend)) {
                *result = 3;
            }
        }
        {
            typedef void (TcpRelay::*_t)(const int & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpRelay::latencyAvailable)) {
                *result = 4;
            }
        }
        {
            typedef void (TcpRelay::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpRelay::finished)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject QSS::TcpRelay::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QSS__TcpRelay.data,
      qt_meta_data_QSS__TcpRelay,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QSS::TcpRelay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSS::TcpRelay::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QSS__TcpRelay.stringdata0))
        return static_cast<void*>(const_cast< TcpRelay*>(this));
    return QObject::qt_metacast(_clname);
}

int QSS::TcpRelay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void QSS::TcpRelay::debug(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QSS::TcpRelay::info(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QSS::TcpRelay::bytesRead(const qint64 & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QSS::TcpRelay::bytesSend(const qint64 & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QSS::TcpRelay::latencyAvailable(const int & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QSS::TcpRelay::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
