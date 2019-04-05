#include<stdio.h>
#include "Person.h"
#include "Bank.h"

int main() {
	double balance=0.0;
	
	initPeople();
	initAccounts();
	
	if (!addPerson(1,"Bob")) puts("Could not add Bob");
	if (!addPerson(2,"Mary"))puts("Could not add Mary");
	
	if (!addAccount(0,1,100.25)) puts("Can not add account Bob");
	if (!addAccount(1,2,300.00)) puts("Can not add account Mary");
	
	if ( (balance=getBalance(0)) <0) puts("Error");
	else printf("Balance = %f\n", balance);
}