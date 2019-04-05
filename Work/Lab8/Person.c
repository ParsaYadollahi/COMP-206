#include<stdlib.h>
#include<string.h>

#define MAXPEOPLE 10
#define BOOLEAN int
#define TRUE 1
#define FALSE 0

struct PERSON {
	int ID;
	char name[30];
} people[MAXPEOPLE];

void initPeople() {
	int i;
	
	for(i=0; i<MAXPEOPLE; i++) people[i].ID = -1; // empty space
}

BOOLEAN addPerson(int ID, char name[]) {
	int i;
	
	// find a free spot
	for(i=0; i<MAXPEOPLE && people[i].ID!=-1; i++);
	
	// determine if we add someone
	if (i<MAXPEOPLE) {
		people[i].ID = ID;
		strcpy(people[i].name,name);
		return TRUE;
	}
	
	return FALSE;
}

char *getName(int ID) {
	int i;
	
	// find by ID
	for(i=0; i<MAXPEOPLE && people[i].ID!=ID;i++);
	
	// if found return the name
	if (i<MAXPEOPLE) return strdup(people[ID].name);
	else return NULL;
}