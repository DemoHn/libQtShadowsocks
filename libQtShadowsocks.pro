# This file is part of project libQtShadowsocks
# Copyright (C) 2014, Symeon Huang <hzwhuang@gmail.com>
# Licensed Under GPLv3

QT       += core network concurrent

QT       -= gui

CONFIG   += c++11

TARGET    = QtShadowsocks

TEMPLATE  = lib

isEmpty(INSTALL_PREFIX) {
    unix: INSTALL_PREFIX = /usr
    else: INSTALL_PREFIX = $$top_srcdir
}

unix: {
    VERSION     = 1.0

    CONFIG     += create_pc create_prl no_install_prl link_pkgconfig

    target.path = $$INSTALL_PREFIX/lib
    header_files.files = $$HEADERS
    header_files.path  = $$INSTALL_PREFIX/include/qtshadowsocks
    INSTALLS   += target header_files

    QMAKE_PKGCONFIG_NAME = QtShadowsocks
    QMAKE_PKGCONFIG_DESCRIPTION = A Shadowsocks library written in C++/Qt5
    QMAKE_PKGCONFIG_PREFIX  = $$INSTALL_PREFIX
    QMAKE_PKGCONFIG_LIBDIR  = $$target.path
    QMAKE_PKGCONFIG_INCDIR  = $$header_files.path
    QMAKE_PKGCONFIG_VERSION = $$VERSION
    QMAKE_PKGCONFIG_DESTDIR = pkgconfig

    PKGCONFIG  += botan-1.10
}

win32: {
    DEFINES    += "FD_SETSIZE=1024"#increase the maximum pending tcp sockets. this value is 64 on Windows by default
    DEFINES    += "_WIN32_WINNT=0x0600"#drop support for Windows XP
    DEFINES    += QSS_STATIC
}

contains(DEFINES, QSS_STATIC) {
    CONFIG  += staticlib
}
else {
    DEFINES += QSS_LIBRARY
}

include(src/QtShadowsocks.pri)
