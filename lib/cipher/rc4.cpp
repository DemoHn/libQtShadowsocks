#include "cipher/rc4.h"
#include <QDebug>

using namespace QSS;
RC4::RC4(const QByteArray &key, const QByteArray &iv, QObject *parent) :
    QObject(parent)
{
    realKey = md5Hash(key + iv);
    realKey.resize(key.size());
    //generate();
}

RC4::~RC4()
{

}

QByteArray RC4::md5Hash(const QByteArray &data)
{
    return QCryptographicHash::hash(data, QCryptographicHash::Md5);
}

void RC4::_setup(State *s, uchar *key)
{
    s->x = 0;
    s->y = 0;
    for (quint32 i = 0; i < 256; ++i) {
        (s->m)[i] = static_cast<unsigned char>(i);
    }

    for (quint32 i = 0, state_index = 0; i < 256; ++i) {
        state_index = (state_index + key[i % realKey.length()] + (s->m)[i])
                    % 256;
        std::swap((s->m)[i], (s->m)[state_index]);
    }
}

QByteArray RC4::_crypt(State *s, const QByteArray &input)
{
    quint32 len = input.size();
    unsigned char sx, sy;
    unsigned char * state;

    sx = s->x;
    sy = s->y;
    state = s->m;

    QByteArray output;
    for(uint j = 0 ; j < len ; j++)
    {
        sx = (sx+1) % 256;
        sy = (sy + state[sx]) % 256;

        std::swap(state[sx], state[sy]);

        output.append( input[j] ^ state[ ( state[sx] + state[sy] ) % 256] );
    }

    output.resize(len);
    return output;
}

QByteArray RC4::update(const QByteArray &input)
{
    unsigned char *key = reinterpret_cast<unsigned char *>(realKey.data());
    State s;

    _setup(&s, key);
    return _crypt(&s, input);
}

/*
QByteArray RC4::update(QByteArray &input)
{
    quint32 length = input.length();
    QByteArray output;

    output.resize(length);

    unsigned char *in =
            reinterpret_cast<unsigned char*>(input.data());
    unsigned char *out =
            reinterpret_cast<unsigned char*>(output.data());

    for (quint32 delta = 4096 - position;
         length >= delta;
         delta = 4096 - position) {//4096 == buffer.size()

        XOR(buffer.data() + position, in , delta, out);
        length -= delta;
        in += delta;
        out += delta;
        generate();
    }

    XOR(buffer.data() + position, in, length, out);
    position += length;
    return output;
}

void RC4::generate()
{
    unsigned char sx, sy;
    for (int i = 0; i < buffer.size(); i += 4) {
        sx = state[x + 1]; y = (y + sx) % 256; sy = state[y];
        state[x + 1] = sy; state[y] = sx;
        buffer[i] = state[(sx + sy) % 256];

        sx = state[x + 2]; y = (y + sx) % 256; sy = state[y];
        state[x + 2] = sy; state[y] = sx;
        buffer[i + 1] = state[(sx + sy) % 256];

        sx = state[x + 3]; y = (y + sx) % 256; sy = state[y];
        state[x + 3] = sy; state[y] = sx;
        buffer[i + 2] = state[(sx + sy) % 256];

        x = (x + 4) % 256;
        sx = state[x]; y = (y + sx) % 256; sy = state[y];
        state[x] = sy; state[y] = sx;
        buffer[i + 3] = state[(sx + sy) % 256];
    }
    position = 0;
}

void RC4::XOR(uchar *a, uchar *b, int count, uchar *result)
{
    for(int j = 0; j < count ; j ++){
        *result =  (*a) ^ (*b);
        a += 1;
        b += 1;
        result += 1;
    }
}
*/
