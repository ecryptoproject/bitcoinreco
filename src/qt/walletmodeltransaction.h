// Copyright (c) 2011-2017 The Bitcoinreco Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOINRECO_QT_WALLETMODELTRANSACTION_H
#define BITCOINRECO_QT_WALLETMODELTRANSACTION_H

#include <qt/walletmodel.h>

#include <memory>

#include <QObject>

class SendCoinsRecipient;

namespace interfaces {
class Node;
class PendingWalletTx;
}

/** Data model for a walletmodel transaction. */
class WalletModelTransaction
{
public:
    explicit WalletModelTransaction(const QList<SendCoinsRecipient> &recipients);

    QList<SendCoinsRecipient> getRecipients() const;

    std::unique_ptr<interfaces::PendingWalletTx>& getWtx();
    unsigned int getTransactionSize();

    void setTransactionFee(const CAmount& newFee);
    CAmount getTransactionFee() const;

    CAmount getTotalTransactionAmount() const;

    void reassignAmounts(int nChangePosRet); // needed for the subtract-fee-from-amount feature

private:
    QList<SendCoinsRecipient> recipients;
    std::unique_ptr<interfaces::PendingWalletTx> wtx;
    CAmount fee;
};

#endif // BITCOINRECO_QT_WALLETMODELTRANSACTION_H