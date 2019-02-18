#!/bin/bash

#1)
clear

#2)
cd $HOME

#3)
if [ ! -d $1 ]; then
	mkdir $1
fi

#4)
cd $1

#5)
if [ ! -f extract.log ]; then
	touch extract.log
fi

#6) 7)
if [ ! -f Information ]; then
	touch Information
	echo "Information file is created" > extract.log
else
	echo "Information file already exists" > extract.log
fi

#8)
chmod a= Information
chmod u+rw Information
chmod g+r Information

#9)
echo "Access right changed for Information file" >> extract.log

#10)
z=$(who -q | grep [abcd])
echo $z > Information

#11)
echo "List of user names has been added to the Information file" >> extract.log

#12)
x="The number of found users is: "
y=$(wc -w < Information)
echo $x$y >> extract.log

#13)
echo "Execution of InformationExtractor script has ended successfully!"
