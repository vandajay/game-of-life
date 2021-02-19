#!/bin/bash

# build starting graph in world.txt

# $1 = rows, $2 = cols, $3 = iterations

for ((i = 0; i <= $3; ++i))
do
    clear
    echo "$1 $2 $i" | cat - world.txt > tmp.txt
    ./a.out < tmp.txt
    sleep .2s
done

rm tmp.txt

exit 0
