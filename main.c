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
#include<time.h>
char str[50];

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

char getState (Fuzzypet* myPetPtr, const char* filename)
{
	char* line = malloc(8*50);
	FILE* file = fopen(filename,"r");
	size_t N = 0;
	char* ptr;
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
		fclose(file);
		return 1;
	}
	return 0;
}

/*
 * 	doActions
 * 	do what you requested your fuzzypet
 */

#define currentTimeHours time(NULL)/60/60

int doActions (Fuzzypet* myPetPtr,int argc, char * argv[])
{
	// ************ MAIN ************
	int elapsedTimeHours = currentTimeHours - myPetPtr->lastTimeHours;
	printf("Elapsed Time Between Last Run %i h \n",elapsedTimeHours);
	
	//	if user didnt come to vist his pet let him explain why?
	//	if the response is not egnof let him have the penality
	if(elapsedTimeHours > 12) {
	} else {
		myPetPtr->food -= 5*elapsedTimeHours;
		myPetPtr->mood -= 5*elapsedTimeHours;
	}
	// pet interaction section
	for(int i = 1; i < argc; i++) {
		switch(argv[i][0]) {
			case 'f':
			myPetPtr->food += 25;
			printf("You fed %s.\n", myPetPtr->name);
			break;

			case 'p':
			myPetPtr->mood += 25;
			printf("You peted %s.\n", myPetPtr->name);
			break;

			case 'k':
			myPetPtr->mood -= 20 ;
			printf("You kicked %s.\n", myPetPtr->name);
			break;

			case 's':
			printf("Pet Name : %s \nPet Food : %i%%\nPet Mood : %i%%\n", myPetPtr->name, myPetPtr->food, myPetPtr->mood);
			// food state printout
			if(myPetPtr->food > 75)
			printf("%s is Healty.\n", myPetPtr->name);
			else if(myPetPtr->food > 50)
			printf("%s is Hungry.\n", myPetPtr->name);
			else if(myPetPtr->food > 25)
			printf("%s is starving.\n", myPetPtr->name);
			else if(myPetPtr->food == 0)
			printf("%s has died of hunger, you killed her!\n", myPetPtr->name);
			// mood state printout
			if(myPetPtr->mood > 100)
			printf("%s is in heat , please calmdown the peting.\n", myPetPtr->name);
			else if(myPetPtr->mood > 75)
			printf("%s is looking at you hapily!\n", myPetPtr->name);
			else if(myPetPtr->mood > 50)
			printf("%s seams sad.\n", myPetPtr->name);
			else if(myPetPtr->mood > 25) 
			printf("%s is bored.\n", myPetPtr->name);
			else if(myPetPtr->mood > 0)
			printf("%s doesn't answer her Name...\n", myPetPtr->name); 
			break;

			default :
			printf("\tf = feed\n\tp = pet\n\ts = status\nnothing exist%s.\n", myPetPtr->name);
			break;
		}
	}
}

/*
 * 	Save state
 * 	Save your current state
 */

char saveState(Fuzzypet* myPetPtr,const char* filename)
{	

	FILE* file = fopen(filename,"w");
	fprintf(file,"%s\n%i\n%i\n%i\n%i\n",myPetPtr->name,myPetPtr->gender,myPetPtr->mood,myPetPtr->food,currentTimeHours);
	fclose(file);
	return 0;
}

/*
 * 	MAIN PROGRAM
 */

int main (int argc, char * argv[]){
	Fuzzypet myPet;
	sprintf(str,"%s/.fuzzypet", getenv("HOME"));
	int didItWork = getState(&myPet,str);
	//printf("%s\n", str);
	if(didItWork){
		doActions(&myPet,argc,argv);
	}
	saveState(&myPet,str);
	return 0;
}
