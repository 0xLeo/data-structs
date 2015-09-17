#!/bin/bash

t=0; N=6;
for i in $(seq 1 $N)
do
	t_start=$(date +%s%3N)
	./test4
	t_end=$(date +%s%3N)
	t=$(($t+$t_end-$t_start))
done

echo "OK. avg search time =" $(echo "scale=4; $t/$N/1000"| bc) s
