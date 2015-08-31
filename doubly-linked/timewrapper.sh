#!/bin/bash

# measure avg time:

t=0; N=10
for i in $(seq 1 $N)
do
t=$(echo "$t + " $(./test | grep -oP "[0-9]{1,2}\.[0-9]{4}")  | bc )
done

printf "OK. avg time = %.4f\n" $(echo "scale=4; $t/$N" | bc)

