/*************************************************************************
* Title: (CIS265_2B) Alphabetic Phone Number Convertor
* File: main.c
* Author: James Eli
* Date: 8/27/2017
*
* Write a program that translates an alphabetic phone number into numeric 
* form:
*   Enter phone number: CALLATT
*   2255288
* (In case you don’t have a telephone nearby, here are the letters on the 
* keys: 2=ABC, 3=DEF, 4=GHI, 5=JKL, 6=MNO, 7=PRS, 8=TUV, 9=WXY.) If the 
* original phone number contains nonalphabetic characters (digits or 
* punctuation, for example), leave then unchanged:
*
* Notes:
*  (1) Compiled with MS Visual Studio 2017 Community (v141), using C
*      language options.
*
* Submitted in partial fulfillment of the requirements of PCC CIS-265.
*************************************************************************
* Change Log:
*   08/27/2017: Initial release. JME
*************************************************************************/
#include <assert.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Definitions.
#define MAX_INPUT_ATTEMPTS             3  // Number of input attempts before aborting program.
#define MAX_PHONE_NUMBER_STRING_LENGTH 24 // Maximum length of input string.

// Convert phone character to number.
char toNumber(char c) {
	char _c = tolower(c); // Use lower case for comparisons.

	// Check for non-phone character.
	if (_c < 'a' || _c > 'z' || _c == 'q')
		return c;
	// Special case of 'z'.
	if (_c == 'z') 
		return '9';
	// Apply adjustemnt for missing 'q'.
	if (_c > 'p')
		_c -= 1;
	// Convert and return appropriate number.
	return '0' + (_c - 'a') / 3 + 2;
}

// Program starts here.
int main(void) {
	char s[MAX_PHONE_NUMBER_STRING_LENGTH]; // Holds input phone number.
	int attempts = MAX_INPUT_ATTEMPTS;      // Input attempt counter.

	// Attempts must be valid non-zero, positive number.
	assert(attempts > 0);

	// Attempt only so many inputs.
	while (attempts--) {
		// Prompt and grab user input.
		fputs("Enter phone number: ", stdout);
		if (!fgets(s, MAX_PHONE_NUMBER_STRING_LENGTH - 2, stdin)) {
			fputs("Fatal program error!\n", stderr);
			exit(EXIT_FAILURE);
		}
		else if (!strchr(s, '\n')) {
			// input too long, eat remainder.
			while (fgets(s, MAX_PHONE_NUMBER_STRING_LENGTH - 2, stdin) && !strchr(s, '\n'))
				; // Empty body.
			fputs("Too many characters input.\n", stdout);
		}
		else {
			// Catch special case of no input.
			if (strlen(s) > 1) {
				// Convert and display.
				for (unsigned int i = 0; i < strlen(s); i++)
					printf("%c", toNumber(s[i]));
				break;
			}
		}
	}
}

