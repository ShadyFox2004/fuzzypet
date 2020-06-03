#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <sqlite3.h>

int main (int argc, char * argv[])
{
	// Pet state variables
	char* petName = malloc(45);
	int petSexe = 0;
	int petMood = 0;
	int petFood = 0;
	//...

	// Get the current pet state
	char* line = malloc(25);
	FILE* file = fopen("pet","r");
	size_t N = 0;
	if(file)
	{
		// Read petName from pet
		getline(&line,&N,file);
		char * ptr = strchr(line,'\n');
			if(ptr)	*ptr = '\0';
		strcpy(petName, line);
	
		// Read petSexe from pet	
		getline(&line,&N,file);
		ptr = strchr(line,'\n');
			if(ptr)	*ptr = '\0';
		petSexe = atoi(line);
		
		// Read petMood from pet	
		getline(&line,&N,file);
		ptr = strchr(line,'\n');
			if(ptr)	*ptr = '\0';
		petMood = atoi(line);
	
		// Read petFood from pet	
		getline(&line,&N,file);
		ptr = strchr(line,'\n');
			if(ptr)	*ptr = '\0';
		petFood = atoi(line);
		
		fclose(file);
	}
	else
	{
		printf("ERROR: can not read the file");
	}
	//...

	// ************ MAIN ************
	
	petFood-=5; 
	petMood-=5;
	
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
		printf("%s is in heat and look at you like if you are piece of meat, please calmdown the peting.\n", petName);

	else if(petMood > 75)
		printf("%s is looking at you hapily!\n", petName);

	else if(petMood > 50)
		printf("%s seams sad.\n", petName);

	else if(petMood > 25) 
		printf("%s is borded.\n", petName);

	else if(petMood > 0)
		printf("%s doesn't answher her Name...\n", petName); 

	// pet interaction section
	if(argc >= 2)
	{
		switch(argv[1][0])
		{
			case 'f':
			petFood += 25;
			printf("You fed %s.\n", petName);
			break;
			case 'p':
			petMood += 25;
			printf("You peted %s.\n", petName);
			break;
			default :
			printf("\tf = feed\n\tp = pet\n nothing exist%s.\n", petName);
			break;
		}
	}
	// ************ END *************
	// Save the current pet state To pet
	file = NULL;
	file = fopen("pet","w");
	if(file)
	{
		fprintf(file,"%s\n",petName);
		fprintf(file,"%i\n",petSexe);
		fprintf(file,"%i\n",petMood);
		fprintf(file,"%i\n",petFood);

		fclose(file);
	}
	else
	{
		printf("ERROR: can not read the file");
	}
	//...
	
	return 0;
}	
