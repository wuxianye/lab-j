
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int main(void) {
	// Set email address here
	char email[] = "xianye.wu@student.manchester.ac.uk";
	// 0pen file for writing
	FILE* fptr;
	fptr = fopen("certificate.txt", "w");
	if (fptr == NULL) { // display error if can't open file
		printf("Error, Not able to open the file.");
		return EXIT_FAILURE;
	}
	
	
	// 0utput wanted text
	fprintf(fptr, "Hello. My email address is:\n"); 
	fprintf(fptr, "%s\n", email);
	fprintf(fptr, "I completed the course on ");

	struct tm* local;
	time_t t;
	t = time(NULL);
	local = localtime(&t);
	char date[20];
	strftime(date, 20, "%b %e %Y", local); 
	fprintf(fptr, "%s", date);
	

	// Close and tidy up
	fclose(fptr);
	fptr = NULL;
	return EXIT_SUCCESS;
}