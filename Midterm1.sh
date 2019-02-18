#!/bin/bash

if [ ! $# = 2 ]; then
	exit 1
fi

if [ "$1" = "admin" ] && [ "$2" = "password123" ]; then
	echo "Connection successful"
else 
	echo "user name or password is invalid"
fi
