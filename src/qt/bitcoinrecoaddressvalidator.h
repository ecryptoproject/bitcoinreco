// Copyright (c) 2011-2014 The Bitcoinreco Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOINRECO_QT_BITCOINRECOADDRESSVALIDATOR_H
#define BITCOINRECO_QT_BITCOINRECOADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class BitcoinrecoAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit BitcoinrecoAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** Bitcoinreco address widget validator, checks for a valid bitcoinreco address.
 */
class BitcoinrecoAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit BitcoinrecoAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // BITCOINRECO_QT_BITCOINRECOADDRESSVALIDATOR_H
