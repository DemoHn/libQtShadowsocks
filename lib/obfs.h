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

    QString    url_gen;
    static QString UserAgents [] = {
        "Mozilla/5.0 (Windows NT 6.3; WOW64; rv:40.0) Gecko/20100101 Firefox/40.0",
        "Mozilla/5.0 (Windows NT 6.3; WOW64; rv:40.0) Gecko/20100101 Firefox/44.0",
        "Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/41.0.2228.0 Safari/537.36",
        "Microsoft-WNS/10.0"
        "Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:35.0) Gecko/20100101 Firefox/35.0",
        "Mozilla/5.0 (compatible; WOW64; MSIE 10.0; Windows NT 6.2)",
        "oriole",
        "Mozilla/4.0 (compatible; MSIE 7.0; Windows NT 6.3; Trident/7.0; .NET4.0E; .NET4.0C)",
        "Mozilla/5.0 (Windows NT 6.3; Trident/7.0; rv:11.0) like Gecko",
        "Mozilla/5.0 (Linux; Android 4.4; Nexus 5 Build/BuildID) AppleWebKit/537.36 (KHTML, like Gecko) Version/4.0 Chrome/30.0.0.0 Mobile Safari/537.36",
        "Mozilla/5.0 (iPad; CPU OS 5_0 like Mac OS X) AppleWebKit/534.46 (KHTML, like Gecko) Version/5.1 Mobile/9A334 Safari/7534.48.3",
        "Mozilla/5.0 (iPhone; CPU iPhone OS 5_0 like Mac OS X) AppleWebKit/534.46 (KHTML, like Gecko) Version/5.1 Mobile/9A334 Safari/7534.48.3"
    };

    static QString randomUrl [] = {
        "/download.php",
        "/inc/style.css",
        "/api/feed?region=CN&appid={X}",
        "/",
        "/query.php?q={E}",
        "/appinfo/{N}/sha/{X}",
        "/cgi-bin/v2/zh-CN/Home.xml?version=5.2",
        "/singletile/summary/today?market=zh-CN"
    };
};

}
#endif // OBFS_H
