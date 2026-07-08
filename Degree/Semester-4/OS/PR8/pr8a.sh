#!/bin/bash

read -p "Enter subject: " sub
read -p "Enter message:" msg

users=$(who | awk '{print $1}' | sort | uniq)

for u in $users
do
    echo "$msg" | mail -s "$sub" $u
done

echo "Message sent to all logged-in users."