#!/bin/bash

for file in *.txt
do
    mv "$file" "${file%.txt}.doc"
done

echo "Done, extensions changed."