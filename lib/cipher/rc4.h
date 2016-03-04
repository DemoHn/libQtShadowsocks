#ifndef RC4_H
#define RC4_H

#include <QObject>
#include <QCryptographicHash>
#include <QVector>

namespace QSS {

class RC4 : public QObject
{
    Q_OBJECT
public:
    RC4(const QByteArray &key, const QByteArray &iv, QObject *parent = 0);
    ~RC4();

    QByteArray RC4::update(const QByteArray &input);

private:
    //void generate();
    //void XOR(uchar *a, uchar *b, int count, uchar *result);

    struct State{
        unsigned char x;
        unsigned char y;
        unsigned char m[256];
    };

    QByteArray realKey;
    // init state
    void _setup(State *s, uchar *key);
    QByteArray _crypt(State *s, const QByteArray &input);
    QByteArray md5Hash(const QByteArray &data);

    State ss;
};

}
#endif // RC4_H
