#!/bin/bash

arr=($@)
n=$#

for ((i=0; i<n; i++))
do
    for ((j=i+1; j<n; j++))
    do
        if [ ${arr[i]} -lt ${arr[j]} ]
        then
            temp=${arr[i]}
            arr[i]=${arr[j]}
            arr[j]=$temp
        fi
    done
done

echo "Descending Order:"
echo "${arr[@]}"