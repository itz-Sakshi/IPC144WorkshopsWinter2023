/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
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

int main(void)
{
    int repetitions = 0;
    int i = 0; // Will also work as a flag
    char loopType;
    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n\n");
    do
    {
        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &loopType, &repetitions);
        if (loopType == 'D' && repetitions >= 3 && repetitions <= 20)
        {
            printf("DO-WHILE: ");
            i = 0;
            do
            {
                printf("D");
                i++;
            } while (i < repetitions);
            printf("\n\n");
        }
        else if (loopType == 'W' && repetitions >= 3 && repetitions <= 20)
        {
            printf("WHILE   : ");
            i = 0;
            while (i < repetitions)
            {
                printf("W");
                i++;
            }
            printf("\n\n");
        }
        else if (loopType == 'F' && repetitions >= 3 && repetitions <= 20)
        {
            printf("FOR     : ");
            for (i = 0; i < repetitions; i++)
            {
                printf("F");
            }
            printf("\n\n");
        }
        else if (loopType == 'Q' && repetitions == 0)
        {
            i = 100;
            printf("\n");
        }
        else if ((loopType == 'F' || loopType == 'W' || loopType == 'D') && (repetitions > 20 || repetitions < 3))
        {
            printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
        }
        else if (loopType == 'Q' && repetitions != 0)
        {
            printf("ERROR: To quit, the number of iterations should be 0!\n\n");
        }
        else
        {
            printf("ERROR: Invalid entered value(s)!\n\n");
        }
    } while (i != 100); // i works as a flag here
    printf("+--------------------+\n");
    printf("Loop application ENDED\n");
    printf("+--------------------+\n");
    return 0;
}