#ifndef SALSA20_H
#define SALSA20_H

#include <QObject>
#include <QtEndian>
#include <cstdio>
#include <cstdint> // we use 32-bit words
#include <cstdlib>

#define ROUNDS 20
#define U32C(v) (v##U)

#define KEY_LENGTH 32
#define IV_LENGTH 8
#define BLOCK_SIZE 64

#define NATIVE_LITTLE_ENDIAN
// https://github.com/jedisct1/libsodium

namespace QSS {

class Salsa20 : public QObject
{
    Q_OBJECT
public:
    explicit Salsa20(const QByteArray &_key, const QByteArray &_iv, QObject *parent = 0);

    QByteArray update(const QByteArray &input);

private:
    QByteArray key;
    QByteArray iv;

    int counter;
    int crypto_core_salsa20(
            unsigned char *out,
      const unsigned char *in,
      const unsigned char *k,
      const unsigned char *c
    );

    int crypto_stream_salsa20_xor_ic(
            unsigned char *c,
      const unsigned char *m, unsigned long long mlen,
      const unsigned char *n, uint64_t ic,
      const unsigned char *k
    );

    inline uint32_t rotate(uint32_t u,int c)
    {
      return (u << c) | (u >> (32 - c));
    }

    #define LOAD32_LE(SRC) Salsa20::load32_le(SRC)
    static inline uint32_t
    load32_le(const uint8_t src[4])
    {
    #ifdef NATIVE_LITTLE_ENDIAN
        uint32_t w;
        memcpy(&w, src, sizeof w);
        return w;
    #else
        uint32_t w = (uint32_t) src[0];
        w |= (uint32_t) src[1] <<  8;
        w |= (uint32_t) src[2] << 16;
        w |= (uint32_t) src[3] << 24;
        return w;
    #endif
    }

    #define STORE32_LE(DST, W) Salsa20::store32_le((DST), (W))
    static inline void
    store32_le(uint8_t dst[4], uint32_t w)
    {
    #ifdef NATIVE_LITTLE_ENDIAN
        memcpy(dst, &w, sizeof w);
    #else
        dst[0] = (uint8_t) w; w >>= 8;
        dst[1] = (uint8_t) w; w >>= 8;
        dst[2] = (uint8_t) w; w >>= 8;
        dst[3] = (uint8_t) w;
    #endif
    }


    //void salsa20_words(uint32_t *out, uint32_t in[16]);
    //void salsa20_block(uint8_t *out, uint8_t key[32], uint64_t nonce, uint64_t index) ;
};

}
#endif // SALSA20_H
