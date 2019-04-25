#!/bin/sh

DIR=$(date +%G%m%d)

mkdir $DIR

touch $DIR/sticker.data


echo "============= ksd_reloading =================" >> $DIR/sticker.log

./checker >> $DIR/sticker.log

cat $DIR/sticker.log | grep "ksd"
cat $DIR/sticker.log | tail -n 50 | more




#echo $DIR
