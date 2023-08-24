/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2
Full Name  : Sakshi Sakshi
Student ID#: 112602222
Email      : ssakshi7@myseneca.ca
Section    : NFF

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

// SAFE-GUARD: 
// It is good practice to apply safe-guards to header files
// Safe-guard's ensures only 1 copy of the header file is used in the project build
// The macro name should be mirroring the file name with _ for spaces, dots, etc.

// !!! DO NOT DELETE THE BELOW 2 LINES !!!
#ifndef CORE_H
#define CORE_H

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// 
// Copy your work done from Milestone #1 (core.h) into this file
// 
// NOTE:
// - Organize your functions into the below categories
// - Make sure the core.c file also lists these functions in the same order!
// - Be sure to provide a BRIEF comment for each function prototype
// - The comment should also be copied to the core.c function definition
//
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);






//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// This function ensures that a valid integer is entered and returned.
int inputInt(void);

// This function guarantees a positive integer value is entered and returned.
int inputIntPositive(void);

// This function guarantees an integer value is entered within the range (inclusive) and returned
int inputIntRange(int a, int b);

// This function guarantees a single character value is entered within the list of valid characters (as defined by the C string argument received) and returned
char inputCharOption(const char array[]);

// This function guarantees a C string value is entered containing the number of characters within the range specified by the 2nd and 3rd arguments(and return via the 1st argument pointer).
void inputCString(char* str, int min, int max);

// This function should display the phone number in the following format when it is a valid C string phone number
void displayFormattedPhone(const char* string);












// !!! DO NOT DELETE THE BELOW LINE !!!
#endif // !CORE_H
