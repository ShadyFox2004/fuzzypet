#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//#include <sqlite3.h>

int main (int argc, char * argv[])
{
	/* Pet state variables */
	char* petName = malloc(45);
	int petSexe = 0;
	int petMood = 0;
	int petFood = 0;
	int lastTimeHours = 0;	
	int currentTimeHours = time(NULL)/3600;
	int elapsedTimeHours = 0;
	//...

	/* Get the current pet state */
	char* line = malloc(25);
	FILE* file = fopen("pet","r");
	size_t N = 0;
	if(file) {
		// Read petName from pet
		getline(&line,&N,file);
		char * ptr = strchr(line,'\n');
			if(ptr)	
				*ptr = '\0';
		strcpy(petName, line);
	
		// Read petSexe from pet	
		getline(&line,&N,file);
		ptr = strchr(line,'\n');
			if(ptr)	
				*ptr = '\0';
		petSexe = atoi(line);
		
		// Read petMood from pet	
		getline(&line,&N,file);
		ptr = strchr(line,'\n');
			if(ptr)	
				*ptr = '\0';
		petMood = atoi(line);
	
		// Read petFood from pet	
		getline(&line,&N,file);
		ptr = strchr(line,'\n');
			if(ptr)	
				*ptr = '\0';
		petFood = atoi(line);

		// Read lastTimeHours from pet	
		getline(&line,&N,file);
		ptr = strchr(line,'\n');
			if(ptr)	
				*ptr = '\0';
		lastTimeHours = atoi(line);

		fclose(file);
	} else {
		printf("ERROR: can not read the file");
	}
	//...

	// ************ MAIN ************
	
	// pet info updating.
	elapsedTimeHours = currentTimeHours - lastTimeHours;
	printf("Elapsed Time Between Last Run %i h \n",elapsedTimeHours);
	
	//	if user didnt come to vist his pet let him explain why?
	//	if the response is not egnof let him have the penality
	if(elapsedTimeHours > 12) {
		char rep = '0';
		int loop = 1;
		while(loop) {
			printf("Why you didn\'t come visit your pet %s earilier? \n", petName);
			printf("Please, be honest if you want my program to help you.\n");
			printf("\n");
			printf("Reason here :\n");
			printf("\t1)	I was working.\n");
			printf("\t2)	I wasn't able to connect to my pc.\n");
			printf("\t3)	I was watching porn.\n");
			printf("\t4)	I hate my pet.\n");
			printf("\t5)    I hate this program.\n");
			printf("\t6)	I hate my life.\n");
			printf("\t7)	I didn't pay attention.\n");
			printf("\t8)	I was supporting ShadyFox2004.\n");
			printf("\n");
			printf("your choice : ");
			scanf("%c",&rep);

			switch(rep) {
			case '1':
				printf("\nok, this reason is good\n");
				loop = 0;
				break;
			case '2':
				printf("\nok, this reason is good\n");
				loop = 0;
				break;
			case '3':
				printf("\npornographie is a bad thing,\n");
			       	printf("it is made to make you adict.\n");
				printf("I will have merci but this is your last chance.\n");
				loop = 0;
				break;
			case '4':
				printf("\nOutch, this hurted my feelings.\n");
				printf("\nThe animal control is now on its way\n");
				loop = 0;
				break;
			case '5':
				printf("Please say what you dont like about it in my github");
				loop = 0;
				break;
			case '6':
				loop = 0;
				break;
			case '7':
				loop = 0;
				break;
			case '8':
				loop = 0;
				break;
			default :
				break;
			}
		}
	} else {
		petFood -= 5*elapsedTimeHours;
		petMood -= 5*elapsedTimeHours;
	}

	// pet interaction section
	for(int i = 1; i < argc; i++) {
		switch(argv[i][0]) {
		case 'f':
			petFood += 25;
			printf("You fed %s.\n", petName);
			break;
		case 'p':
			petMood += 25;
			printf("You peted %s.\n", petName);
			break;

		case 'k':
			petMood -= 20 ;
			printf("You kicked %s.\n", petName);
			break;
		case 's':
			printf("Pet Name : %s \nPet Food : %i%%\nPet Mood : %i%%\n", petName, petFood, petMood);
			// food state printout
			if(petFood > 75)
				printf("%s is Healty.\n", petName);
			else if(petFood > 50)
				printf("%s is Hungry.\n", petName);
			else if(petFood > 25)
				printf("%s is starving.\n", petName);
			else if(petFood == 0)
				printf("%s has died of hunger, you killed her!\n", petName);
			// mood state printout
			if(petMood > 100)
				printf("%s is in heat , please calmdown the peting.\n", petName);
			else if(petMood > 75)
				printf("%s is looking at you hapily!\n", petName);
			else if(petMood > 50)
				printf("%s seams sad.\n", petName);
			else if(petMood > 25) 
				printf("%s is bored.\n", petName);
			else if(petMood > 0)
				printf("%s doesn't answer her Name...\n", petName); 
			break;
		default :
			printf("\tf = feed\n\tp = pet\n\ts = status\nnothing exist%s.\n", petName);
			break;
		}
	}
	// ************ END *************
	// Save the current pet state To pet
	file = NULL;
	file = fopen("pet","w");
	if(file) {
		fprintf(file,"%s\n%i\n%i\n%i\n%i\n",petName,petSexe,petMood,petFood,currentTimeHours);
		fclose(file);
	} else {
		printf("ERROR: can not read the file");
	}
	//...
	return 0;
}	
