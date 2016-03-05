#ifndef OBFS_H
#define OBFS_H

#include <QObject>
#include <QString>
#include <QByteArray>
#include "address.h"

namespace QSS{

class OBFS : public QObject
{
    Q_OBJECT
public:
    OBFS(QString method, bool is_local, const Address server_address, QObject *parent = 0);
    OBFS();
    ~OBFS();

    QByteArray preEncrypt(QByteArray &input);
    QByteArray encode(QByteArray &input);
    QByteArray decode(QByteArray &input);
    QByteArray postDecrypt(QByteArray &input);

    void       setServerParam(QString &param);

    enum OBFSmethod{
        PLAIN,
        HTTP_SIMPLE,
        TLS_SIMPLE,
        RANDOM_HEAD
    };

    enum Role{
        LOCAL,
        SERVER
    };

private:
    OBFSmethod method;
    Role       role;
    QString    server_param;
    Address    server_address;

    bool       has_sent_header;
    bool       has_recv_header;
};

}
#endif // OBFS_H
