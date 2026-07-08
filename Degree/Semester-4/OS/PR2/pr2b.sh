#!/bin/bash
echo "Practical 2.2"
echo "Enter two numbers to find sum: "
read -p "A: " a
read -p "B: " b
#c=$(($a + $b))
echo "Sum of $a and $b is: $(($a + $b))"
fact=1
for (( i = 1; i <= a; i++ ))
do
	fact=$((fact * i))
done
echo "Factorial of $a: $fact"
fact=1
for ((i=1; i<=b; i++))
do
	fact=$((fact * i))
done
echo "Factorial of $b: $fact"
