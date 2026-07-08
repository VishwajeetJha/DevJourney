#!/bin/bash

read -p "Enter how many numbers:" n

read -p "Enter numbers:" num

set -- $num

max=$1
min=$1
sum=0

for i in $num
do
    if [ $i -gt $max ]
    then
        max=$i
    fi

    if [ $i -lt $min ]
    then
        min=$i
    fi

    sum=$((sum + i))
done

avg=$((sum / n))

echo "Maximum = $max"
echo "Minimum = $min"
echo "Average = $avg"