/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
Full Name  : Sakshi Sakshi
Student ID#: 112602222
Email      : ssakshi7@myseneca.ca
Section    : NFF

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "core.h"
#include "string.h"
#include <ctype.h>

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

//
// Copy your work done from Milestone #2 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
//
// This function ensures that a valid integer is entered and returned.
int inputInt(void)
{
    char newLine = 'x';
    int var = 0;
    int flag = 1;

    do
    {
        scanf("%d%c", &var, &newLine);
        if (newLine == '\n')
        {
            flag = 0;
        }
        else
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
    } while (flag);
    return var;
}

// This function guarantees a positive integer value is entered and returned.
int inputIntPositive(void)
{
    int flag1 = 1;
    int var2 = 0;
    do
    {
        var2 = inputInt();
        if (var2 > 0)
        {
            flag1 = 0;
            
        }
        else
        {
            printf("Error! Value must be > 0: ");
        }
    } while (flag1);
    return var2;
}

// This function guarantees an integer value is entered within the range (inclusive) and returned
int inputIntRange(int lower, int upper)
{
    int flag2 = 1;
    int var3 = 0;
    do
    {
        var3 = inputInt();
        if (var3 >= lower && var3 <= upper)
        {
            flag2 = 0;
        }
        else
        {
            printf("ERROR! Value must be between %d and %d inclusive: ", lower, upper);
        }
    } while (flag2);
    return var3;
}

// This function guarantees a single character value is entered within the list of valid characters (as defined by the C string argument received) and returned
char inputCharOption(const char array[])
{
    int flag = 1;
    char c;
    do
    {
        int i;
        int counter = 0;
        char newLine;
        scanf(" %c%c", &c, &newLine);
        for (i = 0; i < strlen(array); i++)
        {
            if (c == array[i])
            {
                flag = 0;
                counter++;
            }
        }
        if(newLine != '\n' || counter == 0)
        {
            printf("ERROR: Character must be one of [%s]: ", array);
            flag = 1;
            clearInputBuffer();
        }
        else if (counter == 0)
        {
            printf("ERROR: Character must be one of [%s]: ", array);
            flag = 1;
        }
    } while (flag);
    return c;
}

// This function guarantees a C string value is entered containing the number of characters within the range specified by the 2nd and 3rd arguments(and return via the 1st argument pointer).
void inputCString(char(*str), int min, int max)
{
    int flag = 0;
    do
    {
        int count = 0;
        int p;
        char newLn = '\n';
        char str1[40];
        fgets(str1, 40, stdin);
        for (p = 0; p < strlen(str1) && strcmp(&str1[p], &newLn) != 0; p++)
        {
            count++;
        }
        if (min == max && count != min && count != 0)
        {
            printf("ERROR: String length must be exactly %d chars: ", min);
        }
        else if (min != max && count != max && count != 0)
        {
            if (count > max)
            {
                printf("ERROR: String length must be no more than %d chars: ", max);
            }
            else if (count < min)
            {
                printf("ERROR: String length must be between %d and %d chars: ", min, max);
            }
        }
        if (min == max && count == min && count != 0)
        {
            flag++;
            strcpy(str, str1);
            for (p = 0; p < strlen(str1); p++)
            {
            }
            str[p - 1] = '\0';
        }
        else if (min != max && count >= min && count <= max && count != 0)
        {
            flag++;
            strcpy(str, str1);
            for (p = 0; p < strlen(str1); p++)
            {
            }
            str[p - 1] = '\0';
        }
    } while (flag == 0);
}

// This function should display the phone number in the given format when it is a valid C string phone number
void displayFormattedPhone(const char* string)
{
    int j = 0;
    int x = 0;
    int check = 0;
    int numOfDigits = 0;
    if (string != NULL)
    {
        for (j = 0; j < strlen(string); j++)
        {
            numOfDigits++;
            for (x = 0; x <= 9; x++)
            {
                if (string[j] - 47 == x && string[j] <= 57 && string[j] >= 48)
                {
                    check++;
                }
            }
        }
        if (numOfDigits != 10 && check != 10)
        {
            printf("(___)___-____");
        }
        else
        {
            printf("(%c%c%c)%c%c%c-", string[0], string[1], string[2], string[3], string[4], string[5]);
            for (j = 6; j < strlen(string); j++)
            {
                printf("%c", string[j]);
            }
        }
    }
    else
    {
        printf("(___)___-____");
    }
}



//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

void inputPhone(char* phNum, int phnLen)
{
    int flag = 1, i = 0, count = 0, isVaild = 0;
    char inputString[50 + 1] = "\0";

    do
    {
        flag = 1;
        scanf("%50[^\n]s", inputString);
        clearInputBuffer();

        if (phNum == NULL)
        {
            flag = 0;
        }
        else
        {
            isVaild = 1;
            count = 0;
            count = strlen(inputString);

            if (count == phnLen)
            {
                for (i = 0; i < count; i++)
                {

                    if ((isdigit(phNum[i])) != 0)
                    {
                        isVaild = 0;
                    }
                }
            }
            else
            {
                isVaild = 0;
            }

        }

        if (!isVaild)
        {
            printf("Invalid %d-digit number! Number: ", phnLen);
            flag = 1;
        }
        else
        {
            flag = 0;
            for (i = 0; inputString[i] != '\0'; i++)
            {
                phNum[i] = inputString[i];
            }

        }
    } while (flag);
}