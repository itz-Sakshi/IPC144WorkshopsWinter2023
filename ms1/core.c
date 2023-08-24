/*
*****************************************************************************
                        Assignment 1 - Milestone 1
Full Name  : Sakshi Sakshi
Student ID#: 112602222
Email      : ssakshi7@myseneca.ca
Section    : NFF

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "core.h"

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

int inputInt(void)
{
    char newLine = 'x';
    int var = 0;
    if (newLine == '\n')
    {
        return var;
    }
    else
    {
        do
        {
            scanf("%d%c", &var, &newLine);
            if (newLine == '\n')
            {
                return var;
            }
            else
            {
                clearInputBuffer();
                printf("Error! Input a whole number: ");
            }
        } while (1);
    }
}

int inputIntPositive(void)
{
    do
    {
        int var2 = inputInt();
        if (var2 > 0)
        {
            return var2;
        }
        else
        {
            printf("ERROR! Value must be > 0: ");
        }
    } while (1);
}

int inputIntRange(int lower, int upper)
{
    do
    {
        int var3 = inputInt();
        if (var3 >= lower && var3 <= upper)
        {
            return var3;
        }
        else
        {
            printf("ERROR! Value must be between %d and %d inclusive: ", lower, upper);
        }
    } while (1);
}

char inputCharOption(const char array[])
{
    do
    {
        int i;
        int counter = 0;
        char c;
        scanf(" %c", &c);
        for (i = 0; array[i] != '\0'; i++)
        {
            if (c == array[i])
            {
                counter++;
            }
        }
        if (counter > 0)
        {
            return c;
        }
        else
        {
            printf("ERROR: Character must be one of [%s]: ", array);
        }
    } while (1);
}

void inputCString(char *str, int min, int max)
{
    int flag = 0;
    do
    {
        int count = 0;
        int p;
        char str1[40];
        clearInputBuffer();
        scanf("%40[^\n]", str1);
        for (p = 0; str1[p] != '\0'; p++)
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
            for (p = 0; str1[p] != '\0'; p++)
            {
                str[p] = str1[p];
            }
            str[p] = '\0';
        }
        else if (min != max && count >= min && count <= max && count != 0)
        {
            flag++;
            for (p = 0; str1[p] != '\0'; p++)
            {
                str[p] = str1[p];
            }
            str[p] = '\0';
        }
    } while (!flag);
}

void displayFormattedPhone(const char* string)
{
    int j = 0;
    int check = 0;
    int numOfDigits = 0;
    if (string != NULL)
    {
        for (j = 0; string[j] != '\0'; j++)
        {
            numOfDigits++;
            if (string[j] <= 57 && string[j] >= 48)
            {
                check++;
            }
        }
        if (numOfDigits != 10 || check != 10)
        {
            printf("(___)___-____");
        }
        else
        {
            printf("(%c%c%c)%c%c%c-%c%c%c%c", string[0], string[1], string[2], string[3], string[4], string[5], string[6], string[7], string[8], string[9]);
        }
    }
    else
    {
        printf("(___)___-____");
    }
}