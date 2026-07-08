#!/bin/bash
echo "Practical 2.3"
read -p "Enter a number to find whether prime or not: " num

for((i=2; i<num; i++))
do
	c=$((num%i))
	if [ "$c" -eq 0 ]; then
		echo "$num is NOT a prime."
		exit
	fi
done
echo "$num is a prime!"
