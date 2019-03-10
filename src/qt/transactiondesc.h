// Copyright (c) 2011-2014 The Bitcoinreco Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOINRECO_QT_TRANSACTIONDESC_H
#define BITCOINRECO_QT_TRANSACTIONDESC_H

#include <QObject>
#include <QString>
#include "walletmodel.h"

class TransactionRecord;

namespace interfaces {
class Node;
class Wallet;
struct WalletTx;
struct WalletTxStatus;
}

/** Provide a human-readable extended HTML description of a transaction.
 */
class TransactionDesc: public QObject
{
    Q_OBJECT

public:
    static QString toHTML(interfaces::Node& node, interfaces::Wallet& wallet, TransactionRecord *rec, int unit,WalletModel *model);

private:
    TransactionDesc() {}

    static QString FormatTxStatus(const interfaces::WalletTx& wtx, const interfaces::WalletTxStatus& status, bool inMempool, int numBlocks, int64_t adjustedTime);
};

#endif // BITCOINRECO_QT_TRANSACTIONDESC_H
