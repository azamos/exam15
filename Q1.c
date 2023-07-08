#include "exam.h"

char* createLongString( const char* arr[], int size )
{
	int len = 0;
	/*
	* First, determine the required amount of bytes for
	* dynamic allocation. The +1 is for the space between words,
	* except for the last one, which is for the null terminator.
	*/
	for (int i = 0; i < size; i++) {
		len += strlen(arr[i])+1;
	}
	char* longString = (char*)malloc(sizeof(char) * len);
	if (!longString) {
		return NULL;
	}
	char* p = longString;//used to traverse the allocated string
	for (int i = 0; i < size; i++) {
		int short_str_len = strlen(arr[i]);
		strcpy(p, arr[i]);
		p += short_str_len;//Advance to the location after the current word
		*p = ' ';//Set the current location to space
		p++;//Advance to where the next word will be copied into
	}
	longString[len - 1] = '\0';//Was space before, do to generity of the code
	return longString;
}