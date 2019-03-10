rm ~/.bitcoinreco/wallet.dat
./bitcoinrecod -daemon
sleep 10
./bitcoinreco-cli importprivkey UvrkaRFq2j8M6z7LwaXZvy1bGSjbH7S3BGWEvcJsy1oo4K3GUPDR
./bitcoinreco-cli getbalance
