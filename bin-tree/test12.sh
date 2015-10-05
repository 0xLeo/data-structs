#!/bin/bash

echo "$(cat out1.txt | sed 's/[^0-9]//g' | sed '/^\s*$/d' | cut -d" " -f2 | sort -n)" > out1.txt

echo "$(cat out1.txt | sed 's/[^0-9]//g' | sed '/^\s*$/d' | cut -d" " -f3 | sort -n)" > out2.txt

d=$(diff out1.txt out2.txt)
[ -z $d ] && echo "-- generated and printed tree data match"
