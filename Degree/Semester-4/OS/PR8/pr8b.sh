#!/bin/bash

cd /home/vish/Pictures

echo "5 Largest Files in Current Directory:"

ls -lS | grep "^-" | head -5