#!/bin/sh
for I in {1..5}; do
    echo "Count: $I"
done

cp file.txt file_backup.txt

NUMBER=1
echo -n "Testing..."
while [ "$NUMBER" -lt 4 ];
do
  echo -n "$NUMBER..."
  NUMBER=`expr $NUMBER + 1`
done
echo