#!/bin/bash

read -p "Enter a string: " str
revStr=$(echo "$str" | rev)

if [ "$str" = "$revStr" ]
then
	echo "String is Palindrome!"
else
	echo "String is NOT Palindrome.."
fi
