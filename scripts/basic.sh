#!/bin/sh

time=`stat -c %x $2 | awk '{print \$1}'`

sed -i '1i\'"// Source : $1" $2
sed -i '2i\'"// Author : Hao Chen" $2
sed -i '3i\'"// Date   : $time\n" $2
