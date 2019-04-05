bank: Person.o Bank.o Main.o
	gcc -o bank Person.o Bank.o Main.o
Person.o: Person.c
	gcc -c Person.c
Bank.o: Bank.c
	gcc -c Bank.c
Main.o: Main.c Person.h Bank.h
	gcc -c Main.c
	