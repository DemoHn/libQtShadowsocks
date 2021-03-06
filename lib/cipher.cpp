/*
 * cipher.cpp - the source file of Cipher class
 *
 * Copyright (C) 2014-2015 Symeon Huang <hzwhuang@gmail.com>
 *
 * This file is part of the libQtShadowsocks.
 *
 * libQtShadowsocks is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * libQtShadowsocks is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with libQtShadowsocks; see the file LICENSE. If not, see
 * <http://www.gnu.org/licenses/>.
 */

#include "cipher.h"
#include <QDebug>

#include <stdexcept>
#include <QCryptographicHash>
#include <QMessageAuthenticationCode>

using namespace QSS;

Cipher::Cipher(const QByteArray &method,
               const QByteArray &key,
               const QByteArray &iv,
               bool encode,
               QObject *parent) :
    QObject(parent),
    _method(NONE),
    iv(iv)
{

    _encode = encode;
    if (method.contains("RC4")) {
        rc4 = new RC4(key, iv, this);
        _method = M_RC4;
    }
    else if(method.contains("Salsa"))
    {
        salsa20 = new Salsa20(key, iv, this);
        _method = M_SALSA20;
    }else if(method.contains("AES"))
    {
        aes     = new AES(key, iv, this);
        _method = M_AES;
    }else if(method.contains("ChaCha"))
    {
        chacha = new ChaCha(key, iv, this);
        _method = M_CHACHA20;
    }

    else{
        qWarning() << "no such cipher method : " << method;
    }
}

Cipher::~Cipher()
{
//    if (pipe)   delete pipe;
}

const QMap<QByteArray, Cipher::CipherKeyIVLength> Cipher::keyIvMap =
        Cipher::generateKeyIvMap();
const QMap<QByteArray, QByteArray> Cipher::cipherNameMap =
        Cipher::generateCipherNameMap();
const int Cipher::AUTH_LEN = 10;

QMap<QByteArray, Cipher::CipherKeyIVLength> Cipher::generateKeyIvMap()
{
    QMap<QByteArray, CipherKeyIVLength> map;
    map.insert("aes-128-cfb", {16, 16});
    map.insert("aes-192-cfb", {24, 16});
    map.insert("aes-256-cfb", {32, 16});
    map.insert("chacha20", {32, 8});
    map.insert("chacha20-ietf", {32, 12});
//    map.insert("rc2-cfb", {16, 8});
    map.insert("rc4-md5", {16, 16});
    map.insert("salsa20", {32, 8});
    return map;
}

QMap<QByteArray, QByteArray> Cipher::generateCipherNameMap()
{
    QMap<QByteArray, QByteArray> map;
    map.insert("aes-128-cfb", "AES-128/CFB");
    map.insert("aes-192-cfb", "AES-192/CFB");
    map.insert("aes-256-cfb", "AES-256/CFB");
    map.insert("chacha20", "ChaCha");
    map.insert("chacha20-ietf", "ChaCha");
//    map.insert("rc2-cfb", "RC2/CFB");
    map.insert("rc4-md5", "RC4-MD5");
    map.insert("salsa20", "Salsa20");

    return map;
}

QByteArray Cipher::update(const QByteArray &data)
{
    switch(_method)
    {
        case M_SALSA20:
            return salsa20->update(data);
        case M_RC4:
            return rc4->update(data);
        case M_AES:
            return aes->update_CFB(data, _encode);
        case M_CHACHA20:
            return chacha->update(data);
        default:
            throw std::runtime_error("ciphers are not initialised!!");

    }

    return QByteArray();
/*    if (chacha) {
        return chacha->update(data);
    } else if (rc4) {
        return rc4->update(data);
    } else if (pipe) {
        pipe->process_msg(reinterpret_cast<const Botan::byte *>
                          (data.constData()), data.size());
        SecureByteArray c = pipe->read_all(Botan::Pipe::LAST_MESSAGE);
        QByteArray out(reinterpret_cast<const char *>(DataOfSecureByteArray(c)),
                       c.size());
        return out;
    } else {
        throw std::runtime_error("Underlying ciphers are all uninitialised!");
    }*/
}

const QByteArray &Cipher::getIV() const
{
    return iv;
}

QByteArray Cipher::randomIv(int length)
{
    //directly return empty byte array if no need to genenrate iv
    if (length == 0) {
        return QByteArray();
    }

    QByteArray output;
/*
    Botan::AutoSeeded_RNG rng;
    QByteArray out;
    out.resize(length);
    rng.randomize(reinterpret_cast<Botan::byte *>(out.data()), length);
    return out;
    */
    for(int j=0;j<length;j++)
    {
        output.append(qrand() % 256);
    }
    return output;
}

QByteArray Cipher::hmacSha1(const QByteArray &key, const QByteArray &msg)
{
    return QMessageAuthenticationCode::hash(msg,
                                       key,
                                       QCryptographicHash::Sha1).left(AUTH_LEN);
}

QByteArray Cipher::md5Hash(const QByteArray &in)
{
    return QCryptographicHash::hash(in, QCryptographicHash::Md5);
}

bool Cipher::isSupported(const QByteArray &method)
{
    /*
#if BOTAN_VERSION_CODE < BOTAN_VERSION_CODE_FOR(1,11,0)
    if (method.contains("ChaCha"))  return true;
#endif

    if (method.contains("RC4")) {
        return true;
    } else {
        std::string str(method.constData(), method.length());
        Botan::Keyed_Filter *filter;
        try {
            filter = Botan::get_cipher(str, Botan::ENCRYPTION);
        } catch (Botan::Exception &e) {
            qWarning("%s\n", e.what());
            return false;
        }
        delete filter;
        return true;
    }*/
    return true;
}

QList<QByteArray> Cipher::getSupportedMethodList()
{
    QList<QByteArray> supportedMethods;
    for (auto it = Cipher::cipherNameMap.cbegin();
         it != Cipher::cipherNameMap.cend();
         ++it) {
        if (Cipher::isSupported(it.value())) {
            supportedMethods.push_back(it.key());
        }
    }
    return supportedMethods;
}
