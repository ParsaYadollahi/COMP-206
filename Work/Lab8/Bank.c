#include<stdlib.h>

#define MAXACCOUNTS 10
#define BOOLEAN int
#define TRUE 1
#define FALSE 0

struct ACCOUNT {
	int acctNo;
	int custNo;
	double balance;
} accounts[MAXACCOUNTS];

void initAccounts() {
	int i;
	
	for(i=0; i<MAXACCOUNTS; i++) {
		accounts[i].acctNo = -1;
		accounts[i].custNo = -1;
		accounts[i].balance= 0.0;
	}
}

BOOLEAN addAccount(int acctNo, int custNo, double amount) {
	int i;
	
	// find a free spot
	for(i=0; i<MAXACCOUNTS && accounts[i].acctNo!=-1; i++);
	
	// determine if we add it
	if (i < MAXACCOUNTS) {
		accounts[i].acctNo = acctNo;
		accounts[i].custNo = custNo;
		accounts[i].balance= amount;
		return TRUE;
	}
	
	return FALSE;
}

double getBalance(int acctNo) {
	int i;
	
	// find by ID
	for(i=0; i<MAXACCOUNTS && accounts[i].acctNo!=acctNo;i++);
	
	// if found return the balance
	if (i<MAXACCOUNTS) return accounts[i].balance;
	else return -1; // to indicate ERROR
}