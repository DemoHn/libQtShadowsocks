#ifndef SALSA20_H
#define SALSA20_H

#include <QObject>
#include <QtEndian>
#include <cstdio>
#include <cstdint> // we use 32-bit words
#include <cstdlib>

// rotate x to left by n bits, the bits that go over the left edge reappear on the right
#define R(x,n) (((x) << (n)) | ((x) >> (32-(n))))

#define KEY_LENGTH 32
#define IV_LENGTH 8
// addition wraps modulo 2^32
// the choice of 7,9,13,18 "doesn't seem very important" (spec)
#define quarter(a,b,c,d) do {\
    b ^= R(d+a, 7);\
    c ^= R(a+b, 9);\
    d ^= R(b+c, 13);\
    a ^= R(c+d, 18);\
} while (0)

namespace QSS {
// code ref : https://github.com/andres-erbsen/salsa20/blob/master/salsa20.c
class Salsa20 : public QObject
{
    Q_OBJECT
public:
    explicit Salsa20(const QByteArray &_key, const QByteArray &_iv, QObject *parent = 0);

    QByteArray update(const QByteArray &input);

private:
    QByteArray key;
    QByteArray iv;

    void salsa20_words(uint32_t *out, uint32_t in[16]);
    void salsa20_block(uint8_t *out, uint8_t key[32], uint64_t nonce, uint64_t index) ;
};

}
#endif // SALSA20_H
