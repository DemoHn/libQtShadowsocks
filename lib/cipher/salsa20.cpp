#include "cipher/salsa20.h"
#include <QDebug>

/*
Salsa20 algorithm

original code : https://github.com/andres-erbsen/salsa20

KEY Length : 32U
IV  Length : 8U
*/

using namespace QSS;
Salsa20::Salsa20(const QByteArray &_key, const QByteArray &_iv, QObject *parent) :
    QObject(parent),
    key(_key),
    iv(_iv)
{
    key.resize(KEY_LENGTH);
    iv.resize(IV_LENGTH);

    counter = 0;

    qDebug() << "salsa20";
}

int Salsa20::crypto_stream_salsa20_xor_ic(
        unsigned char *c,
  const unsigned char *m,unsigned long long mlen,
  const unsigned char *n, uint64_t ic,
  const unsigned char *k
)
{
  unsigned char in[16];
  unsigned char block[64];
  unsigned char kcopy[32];
  unsigned int i;
  unsigned int u;

  if (!mlen) return 0;

  for (i = 0;i < 32;++i) kcopy[i] = k[i];
  for (i = 0;i < 8;++i) in[i] = n[i];
  for (i = 8;i < 16;++i) {
      in[i] = (unsigned char) (ic & 0xff);
      ic >>= 8;
  }

  while (mlen >= 64) {
    crypto_core_salsa20(block,in,kcopy,NULL);
    for (i = 0;i < 64;++i) c[i] = m[i] ^ block[i];

    u = 1;
    for (i = 8;i < 16;++i) {
      u += (unsigned int) in[i];
      in[i] = u;
      u >>= 8;
    }

    mlen -= 64;
    c += 64;
    m += 64;
  }

  if (mlen) {
    crypto_core_salsa20(block,in,kcopy,NULL);
    for (i = 0;i < (unsigned int) mlen;++i) c[i] = m[i] ^ block[i];
  }

  return 0;
}


int Salsa20::crypto_core_salsa20(
        unsigned char *out,
  const unsigned char *in,
  const unsigned char *k,
  const unsigned char *c
)
{
  uint32_t x0, x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15;
  uint32_t j0, j1, j2, j3, j4, j5, j6, j7, j8, j9, j10, j11, j12, j13, j14, j15;
  int i;

  if (c == NULL) {
    j0 = x0 = U32C(0x61707865);
    j5 = x5 = U32C(0x3320646e);
    j10 = x10 = U32C(0x79622d32);
    j15 = x15 = U32C(0x6b206574);
  } else {
    j0 = x0 = LOAD32_LE(c + 0);
    j5 = x5 = LOAD32_LE(c + 4);
    j10 = x10 = LOAD32_LE(c + 8);
    j15 = x15 = LOAD32_LE(c + 12);
  }
  j1 = x1 = LOAD32_LE(k + 0);
  j2 = x2 = LOAD32_LE(k + 4);
  j3 = x3 = LOAD32_LE(k + 8);
  j4 = x4 = LOAD32_LE(k + 12);
  j6 = x6 = LOAD32_LE(in + 0);
  j7 = x7 = LOAD32_LE(in + 4);
  j8 = x8 = LOAD32_LE(in + 8);
  j9 = x9 = LOAD32_LE(in + 12);
  j11 = x11 = LOAD32_LE(k + 16);
  j12 = x12 = LOAD32_LE(k + 20);
  j13 = x13 = LOAD32_LE(k + 24);
  j14 = x14 = LOAD32_LE(k + 28);

  for (i = ROUNDS;i > 0;i -= 2) {
     x4 ^= rotate( x0+x12, 7);
     x8 ^= rotate( x4+ x0, 9);
    x12 ^= rotate( x8+ x4,13);
     x0 ^= rotate(x12+ x8,18);
     x9 ^= rotate( x5+ x1, 7);
    x13 ^= rotate( x9+ x5, 9);
     x1 ^= rotate(x13+ x9,13);
     x5 ^= rotate( x1+x13,18);
    x14 ^= rotate(x10+ x6, 7);
     x2 ^= rotate(x14+x10, 9);
     x6 ^= rotate( x2+x14,13);
    x10 ^= rotate( x6+ x2,18);
     x3 ^= rotate(x15+x11, 7);
     x7 ^= rotate( x3+x15, 9);
    x11 ^= rotate( x7+ x3,13);
    x15 ^= rotate(x11+ x7,18);
     x1 ^= rotate( x0+ x3, 7);
     x2 ^= rotate( x1+ x0, 9);
     x3 ^= rotate( x2+ x1,13);
     x0 ^= rotate( x3+ x2,18);
     x6 ^= rotate( x5+ x4, 7);
     x7 ^= rotate( x6+ x5, 9);
     x4 ^= rotate( x7+ x6,13);
     x5 ^= rotate( x4+ x7,18);
    x11 ^= rotate(x10+ x9, 7);
     x8 ^= rotate(x11+x10, 9);
     x9 ^= rotate( x8+x11,13);
    x10 ^= rotate( x9+ x8,18);
    x12 ^= rotate(x15+x14, 7);
    x13 ^= rotate(x12+x15, 9);
    x14 ^= rotate(x13+x12,13);
    x15 ^= rotate(x14+x13,18);
  }

  x0 += j0;
  x1 += j1;
  x2 += j2;
  x3 += j3;
  x4 += j4;
  x5 += j5;
  x6 += j6;
  x7 += j7;
  x8 += j8;
  x9 += j9;
  x10 += j10;
  x11 += j11;
  x12 += j12;
  x13 += j13;
  x14 += j14;
  x15 += j15;

  STORE32_LE(out + 0,x0);
  STORE32_LE(out + 4,x1);
  STORE32_LE(out + 8,x2);
  STORE32_LE(out + 12,x3);
  STORE32_LE(out + 16,x4);
  STORE32_LE(out + 20,x5);
  STORE32_LE(out + 24,x6);
  STORE32_LE(out + 28,x7);
  STORE32_LE(out + 32,x8);
  STORE32_LE(out + 36,x9);
  STORE32_LE(out + 40,x10);
  STORE32_LE(out + 44,x11);
  STORE32_LE(out + 48,x12);
  STORE32_LE(out + 52,x13);
  STORE32_LE(out + 56,x14);
  STORE32_LE(out + 60,x15);

  return 0;
}

QByteArray Salsa20::update(const QByteArray &input)
{
    QByteArray output;
    QByteArray _input(input);

    int length = input.size();

    int padding = counter % BLOCK_SIZE;

    qDebug() << "len " << length;
    if(padding)
    {
        QByteArray _padding(padding ,'\0');
        _input.prepend(_padding);
    }

    crypto_stream_salsa20_xor_ic(
                reinterpret_cast<uchar *>(output.data()),
                reinterpret_cast<const uchar *>(_input.constData()),
                (unsigned long long)(length + padding),
                reinterpret_cast<const uchar *>(iv.constData()),
                (counter / BLOCK_SIZE),
                reinterpret_cast<const uchar *>(key.constData())
                );

    counter += length;

    qDebug() << padding;
    output.resize(length + padding);
    output = output.mid(padding);

    //qDebug() << "output length " << output.length() << " " << output;

    return output;
}

/*
void Salsa20::salsa20_words(uint32_t *out, uint32_t in[16]) {
    uint32_t x[4][4];
    int i;
    for (i=0; i<16; ++i) x[i/4][i%4] = in[i];
    for (i=0; i<10; ++i) { // 10 double rounds = 20 rounds
        // column round: quarter round on each column; start at ith element and wrap
        quarter(x[0][0], x[1][0], x[2][0], x[3][0]);
        quarter(x[1][1], x[2][1], x[3][1], x[0][1]);
        quarter(x[2][2], x[3][2], x[0][2], x[1][2]);
        quarter(x[3][3], x[0][3], x[1][3], x[2][3]);
        // row round: quarter round on each row; start at ith element and wrap around
        quarter(x[0][0], x[0][1], x[0][2], x[0][3]);
        quarter(x[1][1], x[1][2], x[1][3], x[1][0]);
        quarter(x[2][2], x[2][3], x[2][0], x[2][1]);
        quarter(x[3][3], x[3][0], x[3][1], x[3][2]);
    }
    for (i=0; i<16; ++i) out[i] = x[i/4][i%4] + in[i];
}

// inputting a key, message nonce, keystream index and constants to that transormation
void Salsa20::salsa20_block(uint8_t *out, uint8_t key[32], uint64_t nonce, uint64_t index) {
    static const char c[16] = "expand 32-byte "; // arbitrary constant
    #define LE(p) ( (p)[0] | ((p)[1]<<8) | ((p)[2]<<16) | ((p)[3]<<24) )
    uint32_t in[16] = {LE(c),            LE(key),    LE(key+4),        LE(key+8),
                       LE(key+12),       LE(c+4),    nonce&0xffffffff, nonce>>32,
                       index&0xffffffff, index>>32,  LE(c+8),          LE(key+16),
                       LE(key+20),       LE(key+24), LE(key+28),       LE(c+12)};
    uint32_t wordout[16];
    salsa20_words(wordout, in);
    int i;
    for (i=0; i<64; ++i) out[i] = 0xff & (wordout[i/4] >> (8*(i%4)));
}

// enc/dec: xor a message with transformations of key, a per-message nonce and block index
QByteArray Salsa20::update(const QByteArray &input) {

    QByteArray output;
    output.resize(input.size());

    uint8_t * _key = reinterpret_cast<uint8_t *>(key.data());

    uint64_t nonce = 0;
    uint64_t mlen;

    int i;

    //use little endian now, but maybe big endian??
    memcpy(&nonce, reinterpret_cast<uint8_t*>(iv.data()), sizeof(nonce));

    mlen = static_cast<uint64_t>(input.size());

    uint8_t block[64];
    for (i=0; i<mlen; i++) {
        if (i%64 == 0) salsa20_block(block, _key, nonce, i/64);
        output[i] = block[i%64] ^ input[i];
    }
    return output;
}
*/
