#!/bin/bash

# takes exe test3/4/5
# outputs time4 - time3 or time5 - time3
# test3.txt = creation time, 
# test4.txt = search, test5.txt = traversal
 
N=50;
test_num=$(echo $1 | grep -o [0-9])

#########################################
# tests 3, 4, 5
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
	echo $t_3 >> test3.txt
	#cp test3.txt test3_.txt
	printf "OK. avg creation time = %.1f ms\n" $t_3


elif [ $test_num -eq 4 ]; then
	t_4=0
	for i in $(seq 1 $N); do
		t_start=$(date +%s%3N)
		./$1
		t_end=$(date +%s%3N)
		t_4=$(($t_4+$t_end-$t_start))
	done
	t_4=$(echo "scale=1; $t_4/$N" | bc)
	temp=$(tail -1 test3.txt)	# essentially t_3
	echo $(echo "scale=1; $t_4 - $temp" | bc) >> test4.txt
	printf "OK. avg search time = %.1f ms\n" \
	$(echo $t_4 - $temp | bc)

elif [ $test_num -eq 5 ]; then
	t_5=0
	for i in $(seq 1 $N); do
		t_start=$(date +%s%3N)
		./$1
		t_end=$(date +%s%3N)
		t_5=$(($t_5+$t_end-$t_start))
	done
	t_5=$(echo "scale=1; $t_5/$N" | bc)
	temp=$(tail -1 test3.txt)	# essentially t_3
	echo $(echo "scale=1; $t_5 - $temp" | bc) >> test5.txt
	printf "OK. avg traversal time = %.1f ms\n" \
	$(echo $t_5 - $temp | bc)
fi
