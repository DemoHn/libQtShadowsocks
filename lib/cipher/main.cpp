#include <QCoreApplication>
#include "aes.h"
#include "rc4.h"
#include "salsa20.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    const char key[] = {
            0x00, 0x09, 0x70, 0x03,
            0x04, 0x05, 0x06, 0x07,
            0x08, 0x09, 0x0a, 0x0b,
            0x0c, 0x0d, 0x0e, 0x0f,
            0x10, 0x11, 0x12, 0x13,
            0x14, 0x15, 0x16, 0x17,
            0x18, 0x19, 0x1a, 0x1b,
            0x1c, 0x1d, 0x1e, 0x3f
    };

    const char in[] = {
        0x00, 0x11, 0x11, 0x11,
        0x13, 0x12, 0x12, 0x12,
        0x88, 0x99, 0xaa, 0xbb,
        0xcc, 0xdd, 0xee, 0xff,

        0xdb, 0xdc, 0xdd, 0xde,
        0x88, 0x99, 0xaa, 0xbb,
        0xcc, 0xdd, 0xee, 0xff,

        0x11, 0x12, 0x12, 0x12,
        0x88, 0x99, 0xaa, 0xbb,
        0xcc, 0xdd, 0xee, 0xff,

        0x11, 0x12, 0x12, 0x12,
        0x88, 0x99, 0xaa, 0xbb,
        0xcc, 0xdd, 0xee, 0xff,
    };

    const char iv[] = {
        0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,
        0x88, 0x23, 0xaa, 0xbb,
        0xcc, 0xdd, 0xee, 0xfc
    };

    QByteArray _key(key, 32);
    QByteArray _in(in, 28);
    QByteArray _iv(iv, 16);

    AES aes(_key, _iv);
    RC4 rc4(_key, _iv);
    Salsa20 salsa20(_key, _iv);

    qDebug() << "\nAES encryptor - CFB \n";
    QByteArray encode_in = aes.update_CFB(_in, true);
    qDebug() << "AES encode " << encode_in << " :size: " << encode_in.size();

    QByteArray decode_in = aes.update_CFB(encode_in, false);
    qDebug() << "RC4 decode " << decode_in << " :size: " << decode_in.size();


    qDebug() << "\nRC4 encryptor \n";
    QByteArray _encode_in = rc4.update(_in);
    qDebug() << "RC4 encode " << _encode_in << " :size: " << _encode_in.size();

    QByteArray _decode_in = rc4.update(_encode_in);
    qDebug() << "RC4 decode " << _decode_in << " :size: " << _decode_in.size();

    qDebug() << "\nSalsa20 encryptor \n";
    QByteArray __encode_in = salsa20.update(_in);
    qDebug() << "RC4 encode " << __encode_in << " :size: " << __encode_in.size();

    QByteArray __decode_in = salsa20.update(__encode_in);
    qDebug() << "RC4 decode " << __decode_in << " :size: " << __decode_in.size();
    return a.exec();
}
