#ifndef AES_H
#define AES_H
// originally from https://github.com/dhuertas/AES
#include <QObject>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
class AES : public QObject
{
    Q_OBJECT
public:

    enum KeyBits {
        B128 = 128,
        B192 = 192,
        B256 = 256
    };

    //key length determines the key length;
    AES(QByteArray &key, QObject *parent = 0);
    QByteArray encode(QByteArray &input);
    QByteArray decode(QByteArray &input);

private:

    /*
     * The cipher Key.
     */
    int K;

    /*
     * Number of columns (32-bit words) comprising the State. For this
     * standard, Nb = 4.
     */
    int Nb = 4;

    /*
     * Number of 32-bit words comprising the Cipher Key. For this
     * standard, Nk = 4, 6, or 8.
     */
    int Nk;

    /*
     * Number of rounds, which is a function of  Nk  and  Nb (which is
     * fixed). For this standard, Nr = 10, 12, or 14.
     */
    int Nr;

    KeyBits keyLength;

    uint8_t gadd(uint8_t a, uint8_t b);
    uint8_t gsub(uint8_t a, uint8_t b);
    uint8_t gmult(uint8_t a, uint8_t b);

    void coef_add(uint8_t a[], uint8_t b[], uint8_t d[]);
    void coef_mult(uint8_t *a, uint8_t *b, uint8_t *d);

    uint8_t * Rcon(uint8_t i);
    void add_round_key(uint8_t *state, uint8_t *w, uint8_t r);
    void mix_columns(uint8_t *state);
    void inv_mix_columns(uint8_t *state);
    void shift_rows(uint8_t *state);
    void inv_shift_rows(uint8_t *state);

    void sub_bytes(uint8_t *state);
    void inv_sub_bytes(uint8_t *state);
    void sub_word(uint8_t *w);
    void rot_word(uint8_t *w);
    void key_expansion(uint8_t *key, uint8_t *w);
    void cipher(uint8_t *in, uint8_t *out, uint8_t *w);
    void inv_cipher(uint8_t *in, uint8_t *out, uint8_t *w);

};

#endif // AES_H
