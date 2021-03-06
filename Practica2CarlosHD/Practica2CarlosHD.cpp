// Practica2CarlosHD.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <assert.h>


/********/

// The size of the int type to make all of these functions work regardless of the platform where they run.
const int SIZEOF_INT = sizeof(int);

/********/


/********/

void displayAllBytes(int numberToDisplay);
int getExampleTableGreatestInteger();
unsigned char getExampleTableGreatestByte();
void reverseString(char * outputBuffer, const char * stringToReverse);

/********/


/**
Displays all the bytes that compound an integer separately.

@param parameter Integer which is desired to have its bytes displayed
*/
void displayAllBytes(int numberToDisplay)
{
	int i = (SIZEOF_INT - 1);
	// An unsigned char pointer (1-byte length) must be declared and pointed to the direction of the int parameter. To do this, reinterpret_cast must be used.
	// Type must be unsigned char to avoid having undesired 0 to 1 bits changes.
	unsigned char *pStart = reinterpret_cast<unsigned char *>(&numberToDisplay);
	unsigned char *p = (pStart + i);

	printf("\n Integer bytes: 0x%08x\n", numberToDisplay);
	while(p >= pStart)
	{
		printf("\n Byte %d: %x", i--, *(p--));
	}
}


/**
Returns the example table (int tabla[] = { 1, 3, 2, 5, 3, 0xFFFFFFFF, 2 };) greatest integer.

@return The greatest integer of the example table
*/
int getExampleTableGreatestInteger()
{
	int tabla[] = { 1, 3, 2, 5, 3, static_cast<int>(0xFFFFFFFF), 2 };
	int *p = tabla;
	int *pEnd = (p + ((sizeof(tabla) / SIZEOF_INT) - 1));
	int greatestIntegerValue = *p;

	while(p < pEnd)
	{
		++p;
		if (greatestIntegerValue < *p)
			greatestIntegerValue = *p;
	}

	return greatestIntegerValue;
}


/**
Returns the example table (int tabla[] = { 1, 3, 2, 5, 3, 0xFFFFFFFF, 2 };) greatest byte among every byte contained in every table integer.

@return The greatest byte of the example table, considering every byte an unsigned number.
*/
unsigned char getExampleTableGreatestByte()
{
	int tabla[] = { 1, 3, 2, 5, 3, static_cast<int>(0xffffffff), 2 };
	int *pTable = tabla;
	unsigned char *pByte = reinterpret_cast<unsigned char *>(pTable);
	unsigned char greatestByteValue = '\0';
	unsigned char *pEnd = (pByte + (sizeof(tabla) - 1));

	while (pByte < pEnd)
	{
		++pByte;
		if (greatestByteValue < *(pByte))
			greatestByteValue = *(pByte);
	}

	return greatestByteValue;
}


/**
Stores in an output buffer the reverse string of the parameter string.

@param outputBuffer Output buffer where ths reversed string is stored.
@param stringToReverse String which reverse is generated.
*/
void reverseString(char * outputBuffer, const char * stringToReverse)
{
	assert(outputBuffer);
	assert(stringToReverse);

	// Length of the string.
	unsigned int stringLength = 0;
	// Pointer which will address the end of the string
	const char * stringToReverseEnd = nullptr;
	// Pointer which will address the end of the buffer
	char * outputBufferEnd = nullptr;

	// Custom strlen
	while ('\0' != *(stringToReverse + stringLength))
		stringLength++;
	
	stringToReverseEnd = (stringToReverse + (stringLength - 1));
	outputBufferEnd = (outputBuffer + (stringLength));
	*outputBufferEnd = '\0';
	outputBufferEnd--;

	while (outputBuffer <= outputBufferEnd)
	{
		*(outputBuffer++) = *(stringToReverseEnd--);
		*(outputBufferEnd--) = *(stringToReverse++);
	}
	
}


int main()
{
	char optionSelected;
	bool showPressAnyKey = true;
	int intToDisplay;
	int greatestInteger;
	unsigned char greatestByte;
	char stringToReverse[4][50] = { "Even", "Odd", "This is a complete sentence", "This is a number 11 and this is another 20937" };
	char * buffer = nullptr;

	do {

		printf("\n\nSelect an option:\n");
		printf("\n1 - Display all bytes inside an int");
		printf("\n2 - Get greatest int inside example table");
		printf("\n3 - Get greatest byte inside example table");
		printf("\n4 - Reverse an string (show examples)");
		printf("\nq - Quit");
		printf("\n\n");

		scanf_s("%s", &optionSelected, 2);

		switch (optionSelected)
		{
		case '1': // Display all bytes inside an int
			printf("\n\nEnter the number to display its bytes: ");
			scanf_s("%d", &intToDisplay);
			displayAllBytes(intToDisplay);
			break;

		case '2': // Get greatest int inside example table
			greatestInteger = getExampleTableGreatestInteger();
			printf("\nThe greatest integer is %d (0x%08x)", greatestInteger, greatestInteger);
			break;

		case '3': // Get greatest byte inside example table
			greatestByte = getExampleTableGreatestByte();
			printf("\nThe greatest byte is %x", greatestByte);
			break;

		case '4': // Reverse an string

			printf("\n\nString 1");
			printf("\n----------");

			printf("\nThe original is: %s", stringToReverse[0]);
			buffer = new char[(strlen(stringToReverse[0]) + 1)];
			reverseString(buffer, stringToReverse[0]);
			printf("\nThe reversed string is: %s", stringToReverse[0]);
			reverseString(buffer, stringToReverse[0]);
			printf("\nThe original string reversing the reversed is: %s", buffer);
			delete[]buffer;
			buffer = nullptr;

			printf("\n\nString 2");
			printf("\n----------");

			printf("\nThe original is: %s", stringToReverse[1]);
			buffer = new char[(strlen(stringToReverse[1]) + 1)];
			reverseString(buffer, stringToReverse[1]);
			printf("\nThe reversed string is: %s", stringToReverse[1]);
			reverseString(buffer, stringToReverse[1]);
			printf("\nThe original string reversing the reversed is: %s", buffer);
			delete[]buffer;
			buffer = nullptr;

			printf("\n\nString 3");
			printf("\n----------");

			printf("\nThe original is: %s", stringToReverse[2]);
			buffer = new char[(strlen(stringToReverse[2]) + 1)];
			reverseString(buffer, stringToReverse[2]);
			printf("\nThe reversed string is: %s", stringToReverse[2]);
			reverseString(buffer, stringToReverse[2]);
			printf("\nThe original string reversing the reversed is: %s", buffer);
			delete[]buffer;
			buffer = nullptr;

			printf("\n\nString 4");
			printf("\n----------");

			printf("\nThe original is: %s", stringToReverse[3]);
			buffer = new char[(strlen(stringToReverse[3]) + 1)];
			reverseString(buffer, stringToReverse[3]);
			printf("\nThe reversed string is: %s", stringToReverse[3]);
			reverseString(buffer, stringToReverse[3]);
			printf("\nThe original string reversing the reversed is: %s", buffer);
			delete[]buffer;
			buffer = nullptr;

			break;

		default: // Quit
			optionSelected = 'q';
			showPressAnyKey = false;
			break;
		}

		if (showPressAnyKey)
		{
			printf("\nPress Enter to continue...");
			while ('\n' != getchar());
			getchar(); // wait for ENTER
		}

	} while ('q' != optionSelected && 'Q' != optionSelected);


	return 0;
}

