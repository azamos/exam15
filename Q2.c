#include "exam.h"

int charInString( const char* str, char ch, int n )
{
	/******** DON'T CHANGE ********/
	fx1(); // do not change!!!
	/******************************/

	/*Write your code down here*/

	/*
	*Stop condition: If we got here,
		it means that we already found more then the original n matches,
		thus we return 0.
	*/
	if (n < 0) {
		return 0;
	}
	/*
	* Stop condition:
	*	if we finished going over the string,
	*	there are 2 options:
	*		1.if n==0, it means we have found the exact amount required originally
	*		2.else, means there are more to find, but since the word is finished, return 0
	*/
	if (*str == '\0') {
		return n == 0;
	}
	/*
	* if we found a matching character in
	* the string, we continue to the next step
	* of the recursion, by str+1, which will point us to
	* the next char of the string, but now we need to find less matches
	* to ch
	*/
	if (*str == ch) {
		return charInString(str + 1, ch, n - 1);
	}
	/*
	* Else, if not matching, again we go to next
	* step of the recursion,
	* but this time, we still need to find n more matches
	*/
	else {
		return charInString(str + 1, ch, n );
	}
}