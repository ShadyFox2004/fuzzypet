#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <sqlite3.h>

int main ()
{
	// Pet state variables
	char* petName = NULL;
	int petMood = 0;
	//...

	// Get the current pet state
	char* line = malloc(25);
	FILE* file = fopen("pet.state","r");
	size_t N = 0;
	if(file)
	{
		getline(&line,&N,file);
		char * ptr = strchr(line,'\n');
		if(ptr)	*ptr = '\0';
		getline(&line,&N,file);
		ptr = strchr(line,'\n');
		if(ptr)	*ptr = '\0';
		petMood = atoi(line);
		printf(petName);

		fclose(file);
	}
	else
	{
		printf("ERROR: can not read the file");
	}
	//...

	// Save the current pet state
	
	return 0;
}	
