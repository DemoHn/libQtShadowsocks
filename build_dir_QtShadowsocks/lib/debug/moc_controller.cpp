/****************************************************************************
** Meta object code from reading C++ file 'controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../lib/controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QSS__Controller_t {
    QByteArrayData data[19];
    char stringdata0[253];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QSS__Controller_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QSS__Controller_t qt_meta_stringdata_QSS__Controller = {
    {
QT_MOC_LITERAL(0, 0, 15), // "QSS::Controller"
QT_MOC_LITERAL(1, 16, 4), // "info"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 5), // "debug"
QT_MOC_LITERAL(4, 28, 19), // "runningStateChanged"
QT_MOC_LITERAL(5, 48, 16), // "newBytesReceived"
QT_MOC_LITERAL(6, 65, 12), // "newBytesSent"
QT_MOC_LITERAL(7, 78, 20), // "bytesReceivedChanged"
QT_MOC_LITERAL(8, 99, 16), // "bytesSentChanged"
QT_MOC_LITERAL(9, 116, 19), // "tcpLatencyAvailable"
QT_MOC_LITERAL(10, 136, 5), // "start"
QT_MOC_LITERAL(11, 142, 4), // "stop"
QT_MOC_LITERAL(12, 147, 16), // "onTcpServerError"
QT_MOC_LITERAL(13, 164, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(14, 193, 3), // "err"
QT_MOC_LITERAL(15, 197, 11), // "onBytesRead"
QT_MOC_LITERAL(16, 209, 11), // "onBytesSend"
QT_MOC_LITERAL(17, 221, 23), // "onServerAddressLookedUp"
QT_MOC_LITERAL(18, 245, 7) // "success"

    },
    "QSS::Controller\0info\0\0debug\0"
    "runningStateChanged\0newBytesReceived\0"
    "newBytesSent\0bytesReceivedChanged\0"
    "bytesSentChanged\0tcpLatencyAvailable\0"
    "start\0stop\0onTcpServerError\0"
    "QAbstractSocket::SocketError\0err\0"
    "onBytesRead\0onBytesSend\0onServerAddressLookedUp\0"
    "success"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QSS__Controller[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       3,    1,   87,    2, 0x06 /* Public */,
       4,    1,   90,    2, 0x06 /* Public */,
       5,    1,   93,    2, 0x06 /* Public */,
       6,    1,   96,    2, 0x06 /* Public */,
       7,    1,   99,    2, 0x06 /* Public */,
       8,    1,  102,    2, 0x06 /* Public */,
       9,    1,  105,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,  108,    2, 0x0a /* Public */,
      11,    0,  109,    2, 0x0a /* Public */,
      12,    1,  110,    2, 0x09 /* Protected */,
      15,    1,  113,    2, 0x09 /* Protected */,
      16,    1,  116,    2, 0x09 /* Protected */,
      17,    2,  119,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::ULongLong,    2,
    QMetaType::Void, QMetaType::ULongLong,    2,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,   18,   14,

       0        // eod
};

void QSS::Controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Controller *_t = static_cast<Controller *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->info((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->debug((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->runningStateChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->newBytesReceived((*reinterpret_cast< const quint64(*)>(_a[1]))); break;
        case 4: _t->newBytesSent((*reinterpret_cast< const quint64(*)>(_a[1]))); break;
        case 5: _t->bytesReceivedChanged((*reinterpret_cast< const qint64(*)>(_a[1]))); break;
        case 6: _t->bytesSentChanged((*reinterpret_cast< const qint64(*)>(_a[1]))); break;
        case 7: _t->tcpLatencyAvailable((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 8: { bool _r = _t->start();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 9: _t->stop(); break;
        case 10: _t->onTcpServerError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 11: _t->onBytesRead((*reinterpret_cast< const qint64(*)>(_a[1]))); break;
        case 12: _t->onBytesSend((*reinterpret_cast< const qint64(*)>(_a[1]))); break;
        case 13: _t->onServerAddressLookedUp((*reinterpret_cast< const bool(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Controller::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::info)) {
                *result = 0;
            }
        }
        {
            typedef void (Controller::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::debug)) {
                *result = 1;
            }
        }
        {
            typedef void (Controller::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::runningStateChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (Controller::*_t)(const quint64 & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::newBytesReceived)) {
                *result = 3;
            }
        }
        {
            typedef void (Controller::*_t)(const quint64 & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::newBytesSent)) {
                *result = 4;
            }
        }
        {
            typedef void (Controller::*_t)(const qint64 & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::bytesReceivedChanged)) {
                *result = 5;
            }
        }
        {
            typedef void (Controller::*_t)(const qint64 & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::bytesSentChanged)) {
                *result = 6;
            }
        }
        {
            typedef void (Controller::*_t)(const int & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::tcpLatencyAvailable)) {
                *result = 7;
            }
        }
    }
}

const QMetaObject QSS::Controller::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QSS__Controller.data,
      qt_meta_data_QSS__Controller,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QSS::Controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSS::Controller::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QSS__Controller.stringdata0))
        return static_cast<void*>(const_cast< Controller*>(this));
    return QObject::qt_metacast(_clname);
}

int QSS::Controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void QSS::Controller::info(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QSS::Controller::debug(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QSS::Controller::runningStateChanged(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QSS::Controller::newBytesReceived(const quint64 & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QSS::Controller::newBytesSent(const quint64 & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QSS::Controller::bytesReceivedChanged(const qint64 & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void QSS::Controller::bytesSentChanged(const qint64 & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void QSS::Controller::tcpLatencyAvailable(const int & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_END_MOC_NAMESPACE
