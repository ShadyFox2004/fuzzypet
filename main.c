/*	
 *	What fuzzy pet needs to do ? 
 */

/*	
 *	Start.
 *	He need to get its current state.
 *	He need to do its actions.
 *	He need to save its state.
 *	End.
 */

/*
 * 	What he needs ?
 */	

/*	
 *	1. He need a contructor to "DEFINE" him.
 *
 * 	2. He need a scrip to get its "getState"
 *
 * 	3. He need to do its "doActions"
 *
 * 	4. He need to save its state "saveState"
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
 * 	What is a fuzzy pet
 */

typedef struct Fuzzypet {
	char name[50];
	char gender;
	int mood;
	int food;
	int lastTimeHours;	
} Fuzzypet;

/*
 *	getState,
 *	get pet if it exist state.
 */

/*
 * 	BECAUSE IM LAZY I USE MACROS
 */
#define getString(); getline(&line,&N,file);\
		ptr = strchr(line,'\n');\
		if(ptr)\
			*ptr = '\0';\

char getState (Fuzzypet* myPetPtr)
{
	char* line = malloc(8*50);
	FILE* file = fopen(".fuzzypet","r");
	size_t N = 0;
	char* ptr;
	if(file?0:1) {
		file = fopen("~/fuzzypet","r");
	}
	if(file) {
		getString();
		strcpy(myPetPtr->name, line);
		getString();
		myPetPtr->gender =  atoi(line);
		getString();
		myPetPtr->mood = atoi(line);
		getString();
		myPetPtr->food = atoi(line);
		getString();
		myPetPtr->lastTimeHours = atoi(line);
		return 0;
	}
	return 1;
}
int main (){
	Fuzzypet myPet;
	int didItWork = getState(&myPet);
	printf("%i\n", didItWork);
}
