#!/bin/bash

read -p "Enter file name: " file

tr 'a-z' 'A-Z' < $file && echo