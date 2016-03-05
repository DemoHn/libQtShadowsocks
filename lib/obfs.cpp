#include "obfs.h"
#include <QDebug>
#include <QDateTime>

using namespace QSS;

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
    "/query.php?q={X}",
    "/appinfo/{N}/sha/{X}",
    "/cgi-bin/v2/zh-CN/Home.xml?version=5.2",
    "/singletile/summary/today?market=zh-CN"
};

OBFS::OBFS(QString _method, bool is_local, const Address server_address, QObject *parent) :
    QObject(parent),server_param(""), server_address(server_address)
{
    qDebug() << "__obfs";
    has_sent_header = false;
    has_recv_header = false;

    if(_method.contains("plain")){
        method = PLAIN;
    }
    else if(_method.contains("http_simple"))
    {
        method = HTTP_SIMPLE;
    }
    // TODO more methods support
    else{
        method = PLAIN;
    }

    //role
    if(is_local){
        role = LOCAL;
    }else{
        role = SERVER;
    }
}

OBFS::OBFS(){

}

OBFS::~OBFS()
{

}

QByteArray OBFS::preEncrypt(QByteArray &input)
{
    return input;
}

QByteArray OBFS::encode(QByteArray &input)
{
    if(role == LOCAL)
    {
        switch(method){
            default:
            case PLAIN:
            {
                return input;
            }
            case HTTP_SIMPLE:
            {
                if(has_sent_header){
                    return input;
                }else{
                    QString HTTP_header("");
                    QString url_string;

                    url_string = randomUrl[qrand() % 8] ;

                    HTTP_header += QString("GET %1 HTTP/1.1\r\n").arg(url_string);
                    HTTP_header += QString("Host: %1:%2\r\n").arg(server_address.getAddress()).arg(server_address.getPort());
                    HTTP_header += QString("User-Agent: %1 \r\n").arg(UserAgents[qrand() % 10]);
                    HTTP_header += QString("Content-Type: application/octet-stream\r\nConnection: keep-alive\r\n\r\n");

                    QByteArray _header = HTTP_header.toLocal8Bit();
                    input.prepend(_header);

                    has_sent_header = true;
                    return input;
                }

            }
        }
    }else{
        switch(method){
            default:
            case PLAIN:
                return input;
            case HTTP_SIMPLE:
            {
                if(has_sent_header)
                    return input;

                QString HTTP_header("");
                QDateTime current_datetime = QDateTime::currentDateTimeUtc();

                HTTP_header += QString("HTTP/1.1 200 OK\r\nServer: openresty\r\n");
                HTTP_header += QString("Date: %1\r\n").arg(current_datetime.toString("yyyy mm dd HH:mm:ss GMT"));
                HTTP_header += QString("Content-Type: text/plain; Transfer-Encoding: chunked\r\nConnection: keep-alive\r\n\r\n");

                QByteArray _header = HTTP_header.toLocal8Bit();
                input.prepend(_header);

                has_sent_header = true;
                return input;
            }
        }
    }
}

QByteArray OBFS::decode(QByteArray &input)
{
    if(role == LOCAL)
    {
        switch(method){
            default:
            case PLAIN:
                return input;
            case HTTP_SIMPLE:
            {
                if(has_recv_header)
                    return input;

                int _index = input.indexOf("\r\n\r\n");
                qDebug() << _index;
                if(_index > 0){
                    input = input.mid(_index + 4);
                    has_recv_header = true;
                    return input;
                }else{
                    // input decode not right
                    return QByteArray();
                }
            }
        }
    }else{
        switch(method){
            default:
            case PLAIN:
                return input;
            case HTTP_SIMPLE:
            {
                int _index = input.indexOf("\r\n\r\n");

                if(_index > 0){
                    input = input.mid(_index + 4);
                    return input;
                }else{
                    // input decode not right
                    return QByteArray();
                }
            }
        }
    }
    return input;
}

QByteArray OBFS::postDecrypt(QByteArray &input)
{
    return input;
}


void OBFS::setServerParam(QString &param)
{
    server_param = param;
}

