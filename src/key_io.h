// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2015 The Bitcoinreco Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOINRECO_KEY_IO_H
#define BITCOINRECO_KEY_IO_H

#include <chainparams.h>
#include <key.h>
#include <pubkey.h>
#include <script/standard.h>
#include <interfaces/node.h>

#include <string>

extern CPubKey temppubkeyForBitCoinRecoAddress;
class CWallet;
class CPubKey;

CKey DecodeSecret(const std::string& str);
std::string EncodeSecret(const CKey& key);

CExtKey DecodeExtKey(const std::string& str);
std::string EncodeExtKey(const CExtKey& extkey);
CExtPubKey DecodeExtPubKey(const std::string& str);
std::string EncodeExtPubKey(const CExtPubKey& extpubkey);

std::string EncodeDestinationHasSecondKey(const CTxDestination& dest);
std::string EncodeDestination(const CTxDestination& dest,const CPubKey& key2);
//std::string EncodeDestination(const CTxDestination& dest,CWallet& wallet);
CTxDestination DecodeDestination(const std::string& str);
bool IsValidDestinationString(const std::string& str);
bool IsValidDestinationString(const std::string& str, const CChainParams& params);

#endif // BITCOINRECO_KEY_IO_H
