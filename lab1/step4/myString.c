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
    char *copiedString = (char*)malloc(sizeof(char) * sizeof(*s));

//    CHECK IF MALLOC RETURNS NULL, IF SO EXIT PROGRAM
    if(copiedString == NULL){
        printf("NO MORE MEMORY AVAILABLE FOR STORAGE");
        return 0;
    }

//    COPY THE STRING
    for(int i=0;i<17;i++){
        copiedString[i]=s[i];
    }
    copiedString[17] = 0x00;
    return copiedString;
}//copyString()


void printString(char *s)
// Read the specification carefully.  This printString() function does more
// than just print a string, it treats some of the characters in the string
// a bit differently than you might expect.
{
    for(int i=0;i<18;i++) {
        if(s[i] == ' ') {
            printf("\n");
        } else {
        printf("%c", s[i]);
        }
    }
}//printString()
