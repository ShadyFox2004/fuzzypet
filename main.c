#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <sqlite3.h>

#define NBOFLINE 4

int main ()
{
	// Pet state variables
	char* petName = malloc(8);
	//...

	// Get the current pet state
	FILE * file = fopen("pet.state","r");
	size_t N = 0;
	if(file != NULL)
	{
		getline(&petName,&N,file);
		printf(petName);
		fclose(file);
	}
	else
	{
	//	FILE * file = fopen("pet","w");
	//	fputs("test",file);
	//	fprintf(stdout,petName);
	//	fclose(file);
		printf("ERRER Reding the file");
	}
	//...

	// Save the current pet state
	
	return 0;
}	
