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
}

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

