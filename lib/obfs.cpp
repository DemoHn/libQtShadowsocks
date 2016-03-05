#include "obfs.h"
#include <QDebug>

using namespace QSS;

OBFS::OBFS(QString method, bool is_local, const Address server_address, QObject *parent) :
    QObject(parent),server_param(""), server_address(server_address)
{
    if(method.contains("plain")){
        method = PLAIN;
    }
    else if(method.contains("http_simple"))
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
    QString HTTP_header("");

    QString url_string;

    HTTP_header += "GET "
    return input;
}

QByteArray OBFS::decode(QByteArray &input)
{
    return input;
}

QByteArray OBFS::postDecrypt(QByteArray &input)
{
    return input;
}

QString OBFS::url_gen(QString fake_url)
{

}

void OBFS::setServerParam(QString &param)
{
    server_param = param;
}

