#!/bin/bash

read -p "Enter first file name:" f1

read -p "Enter second file name:" f2

cmp -s $f1 $f2

if [ $? -eq 0 ]
then
    echo "Both files are same"
else
    echo "Files are different"
fi