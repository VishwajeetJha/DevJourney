#!/bin/bash

#use source ./pr7b.sh LEVEL_VALUE
#           to move LEVEL_VALUE times up in the directory structure

n=$1

while [ "$n" -gt 0 ]
do
    cd .. || return 1
    n=$((n - 1))
done

pwd