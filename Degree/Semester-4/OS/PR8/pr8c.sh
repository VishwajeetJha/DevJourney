#!/bin/bash

cd ../..

read -p "Enter directory name:" dir

files=$(find "$dir" -type f | wc -l)
dirs=$(find "$dir" -type d | wc -l)

echo "Total files = $files"
echo "Total directories = $dirs"