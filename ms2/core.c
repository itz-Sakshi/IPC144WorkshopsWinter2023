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

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

//
// Copy your work done from Milestone #1 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
// - Also copy the commented "sections" to help with finding functions quickly!
//



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
            return var;
        }
        else
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
    } while (flag);
    return 0;
}

// This function guarantees a positive integer value is entered and returned.
int inputIntPositive(void)
{
    int flag1 = 1;
    do
    {
        int var2 = inputInt();
        if (var2 > 0)
        {
            flag1 = 0;
            return var2;
        }
        else
        {
            printf("Error! Value must be > 0: ");
        }
    } while (flag1);
    return 0;
}

// This function guarantees an integer value is entered within the range (inclusive) and returned
int inputIntRange(int lower, int upper)
{
    int flag2 = 1;
    do
    {
        int var3 = inputInt();
        if (var3 >= lower && var3 <= upper)
        {
            flag2 = 0;
            return var3;
        }
        else
        {
            printf("Error! Value must be between %d and %d inclusive: ", lower, upper);
        }
    } while (flag2);
    return 0;
}

// This function guarantees a single character value is entered within the list of valid characters (as defined by the C string argument received) and returned
char inputCharOption(const char array[])
{
    int flag = 1;
    do
    {
        int i;
        int counter = 0;
        char c;
        scanf(" %c", &c);
        for (i = 0; i < strlen(array); i++)
        {
            if (strncmp(&c, &array[i], 1) == 0)
            {
                flag = 0;
                counter++;
            }
        }
        if (counter > 0)
        {
            return c;
        }
        else
        {
            printf("ERROR! Character must be one of [%s]: ", array);
        }
    } while (flag);
    return 0;
}

// This function guarantees a C string value is entered containing the number of characters within the range specified by the 2nd and 3rd arguments(and return via the 1st argument pointer).
void inputCString(char(*str), int min, int max)
{
    int flag = 0;
    do
    {
        int count = 0;
        int p;
        char new_ln = '\n';
        char str1[40];
        fgets(str1, 40, stdin);
        for (p = 0; p < strlen(str1) && strcmp(&str1[p], &new_ln) != 0; p++)
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
    int num_of_digits = 0;
    if (string != NULL)
    {
        for (j = 0; j < strlen(string); j++)
        {
            num_of_digits++;
            for (x = 0; x <= 9; x++)
            {
                if (string[j] - 47 == x && string[j] <= 57 && string[j] >= 48)
                {
                    check++;
                }
            }
        }
        if (num_of_digits != 10 && check != 10)
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
