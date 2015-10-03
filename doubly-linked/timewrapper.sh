#!/bin/bash

# measure avg time:

N=60;
test_num=$(echo $1 | grep -o [0-9])

#########################################
# test 2
#########################################

if [ $test_num -eq 2 ]; then
	t_2=0
	for i in $(seq 1 $N); do
		t_start=$(date +%s%3N)
		./$1
		t_end=$(date +%s%3N)
		t_2=$(($t_2+$t_end-$t_start))
	done
	t_2=$(echo "scale=1; $t_2/$N" | bc)
	echo $t_2 >> test23.txt
	printf "OK. avg creation time = %.1f ms\n" $t_2
fi

#########################################
# test 3
#########################################

if [ $test_num -eq 3 ]; then
	t_3=0
	for i in $(seq 1 $N); do
		t_start=$(date +%s%3N)
		./$1
		t_end=$(date +%s%3N)
		t_3=$(($t_3+$t_end-$t_start))
	done
	t_3=$(echo "scale=1; $t_3/$N" | bc)
	temp=$(tail -1 test23.txt)	# essentially t_2
	echo "$(head -n -1 test23.txt)" > test23.txt
	echo $(echo "scale=1; $t_3 - $temp" | bc) >> test23.txt
	printf "OK. avg traversal time = %.1f ms\n" \
	$(echo $t_3 - $temp | bc)
fi
