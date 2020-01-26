// MYSTRING.C
// Code provided for ELEC278 Lab 1 Step 4
// See the instructions in the lab sheet for details about
// the code you are to add to the functions shown below.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myString.h"


char *copyString(char *s)
// Parameter s points to an existing string.
// Function fetches memory sufficient to hold a copy of the existing string,
// and copies the string to the memory fetched.  Return value is the pointer
// to the memory containing the copy of the string.
{
	char * copied = malloc(sizeof(s));
	copied = strcpy(copied, s);
	if (copied == NULL) {
		printf("Error: not enough memory");
		exit(0);
	}
	return copied;
}//copyString()


void printString(char *s)
// Read the specification carefully.  This printString() function does more
// than just print a string, it treats some of the characters in the string
// a bit differently than you might expect.
{
	int i = 0;
	while (s[i] != '\0') {
		if (s[i] == ' ')
			printf("\n");
		else
			printf("%c", s[i]);
		i++;
	}
}//printString()
