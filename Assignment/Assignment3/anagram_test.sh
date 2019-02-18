#!/bin/bash

clear

gcc -o anagram anagram.c

./anagram listen silent
x=$?

if [ $x -eq 0 ]; then
	echo "test succeeded";
else
	echo "test failed";
fi

./anagram listen silence
y=$?
if [ $y -eq 1 ]; then
	echo "test succeeded";
else
	echo "test failed";
fi

echo "Execution of anagram program has ended successfully!"
