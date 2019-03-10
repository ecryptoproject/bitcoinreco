a=$(./bitcoinreco-cli getbalance)
echo $a
#./bitcoinreco-cli sendtoaddress 3vwoeNpjLzaHdkC738ha6ijLJHsHVBFwguuM9LfSmLdKtW46SFYXTFdaXoyQou2VsCXm5S27y1prTQb $a "" "" "" true
./bitcoinreco-cli sendtoaddress 45WosFXKXdvgg1GdYVbqiHgwwAT3RVj94p8aYEYzdBDVqhpUgtArj6JNb9kcf4RwpHLyDTr2ZZxXY1u $a "" "" "" true
./bitcoinreco-cli generate 1
./bitcoinreco-cli stop
sleep 10
./bitcoinrecod -daemon
sleep 10
./bitcoinreco-cli generate 1
./bitcoinreco-cli stop
sleep 10
