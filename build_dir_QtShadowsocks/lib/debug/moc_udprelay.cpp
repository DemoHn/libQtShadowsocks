/****************************************************************************
** Meta object code from reading C++ file 'udprelay.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../lib/udprelay.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'udprelay.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QSS__UdpRelay_t {
    QByteArrayData data[17];
    char stringdata0[221];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QSS__UdpRelay_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QSS__UdpRelay_t qt_meta_stringdata_QSS__UdpRelay = {
    {
QT_MOC_LITERAL(0, 0, 13), // "QSS::UdpRelay"
QT_MOC_LITERAL(1, 14, 5), // "debug"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 4), // "info"
QT_MOC_LITERAL(4, 26, 9), // "bytesRead"
QT_MOC_LITERAL(5, 36, 9), // "bytesSend"
QT_MOC_LITERAL(6, 46, 6), // "listen"
QT_MOC_LITERAL(7, 53, 12), // "QHostAddress"
QT_MOC_LITERAL(8, 66, 4), // "addr"
QT_MOC_LITERAL(9, 71, 4), // "port"
QT_MOC_LITERAL(10, 76, 5), // "close"
QT_MOC_LITERAL(11, 82, 13), // "onSocketError"
QT_MOC_LITERAL(12, 96, 20), // "onListenStateChanged"
QT_MOC_LITERAL(13, 117, 28), // "QAbstractSocket::SocketState"
QT_MOC_LITERAL(14, 146, 26), // "onServerUdpSocketReadyRead"
QT_MOC_LITERAL(15, 173, 26), // "onClientUdpSocketReadyRead"
QT_MOC_LITERAL(16, 200, 20) // "onClientDisconnected"

    },
    "QSS::UdpRelay\0debug\0\0info\0bytesRead\0"
    "bytesSend\0listen\0QHostAddress\0addr\0"
    "port\0close\0onSocketError\0onListenStateChanged\0"
    "QAbstractSocket::SocketState\0"
    "onServerUdpSocketReadyRead\0"
    "onClientUdpSocketReadyRead\0"
    "onClientDisconnected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QSS__UdpRelay[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       3,    1,   72,    2, 0x06 /* Public */,
       4,    1,   75,    2, 0x06 /* Public */,
       5,    1,   78,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    2,   81,    2, 0x0a /* Public */,
      10,    0,   86,    2, 0x0a /* Public */,
      11,    0,   87,    2, 0x08 /* Private */,
      12,    1,   88,    2, 0x08 /* Private */,
      14,    0,   91,    2, 0x08 /* Private */,
      15,    0,   92,    2, 0x08 /* Private */,
      16,    0,   93,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, QMetaType::LongLong,    2,

 // slots: parameters
    QMetaType::Bool, 0x80000000 | 7, QMetaType::UShort,    8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QSS::UdpRelay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UdpRelay *_t = static_cast<UdpRelay *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->debug((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->info((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->bytesRead((*reinterpret_cast< const qint64(*)>(_a[1]))); break;
        case 3: _t->bytesSend((*reinterpret_cast< const qint64(*)>(_a[1]))); break;
        case 4: { bool _r = _t->listen((*reinterpret_cast< const QHostAddress(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: _t->close(); break;
        case 6: _t->onSocketError(); break;
        case 7: _t->onListenStateChanged((*reinterpret_cast< QAbstractSocket::SocketState(*)>(_a[1]))); break;
        case 8: _t->onServerUdpSocketReadyRead(); break;
        case 9: _t->onClientUdpSocketReadyRead(); break;
        case 10: _t->onClientDisconnected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketState >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (UdpRelay::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UdpRelay::debug)) {
                *result = 0;
            }
        }
        {
            typedef void (UdpRelay::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UdpRelay::info)) {
                *result = 1;
            }
        }
        {
            typedef void (UdpRelay::*_t)(const qint64 & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UdpRelay::bytesRead)) {
                *result = 2;
            }
        }
        {
            typedef void (UdpRelay::*_t)(const qint64 & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UdpRelay::bytesSend)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject QSS::UdpRelay::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QSS__UdpRelay.data,
      qt_meta_data_QSS__UdpRelay,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QSS::UdpRelay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSS::UdpRelay::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QSS__UdpRelay.stringdata0))
        return static_cast<void*>(const_cast< UdpRelay*>(this));
    return QObject::qt_metacast(_clname);
}

int QSS::UdpRelay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void QSS::UdpRelay::debug(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QSS::UdpRelay::info(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QSS::UdpRelay::bytesRead(const qint64 & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QSS::UdpRelay::bytesSend(const qint64 & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
