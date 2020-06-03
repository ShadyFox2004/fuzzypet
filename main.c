#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <sqlite3.h>

int main ()
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
		
		printf(petName);

		fclose(file);
	}
	else
	{
		printf("ERROR: can not read the file");
	}
	//...

	// ************ MAIN ************
	



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
