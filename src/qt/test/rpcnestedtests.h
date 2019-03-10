// Copyright (c) 2016-2017 The Bitcoinreco Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOINRECO_QT_TEST_RPCNESTEDTESTS_H
#define BITCOINRECO_QT_TEST_RPCNESTEDTESTS_H

#include <QObject>
#include <QTest>

#include <txdb.h>
#include <txmempool.h>

class RPCNestedTests : public QObject
{
    Q_OBJECT

    private Q_SLOTS:
    void rpcNestedTests();
};

#endif // BITCOINRECO_QT_TEST_RPCNESTEDTESTS_H
