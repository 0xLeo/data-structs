#!/bin/bash

echo "$(tail -n +2 out1.txt | cut -d" " -f2 | sort -n)" > out1.txt

echo "$(tail -n +2 out2.txt | cut -d" " -f3 | sort -n)" > out2.txt

d=$(diff out1.txt out2.txt)
[ -z $d ] && echo "-- generated and printed tree data match"
