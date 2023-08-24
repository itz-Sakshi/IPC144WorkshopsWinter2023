/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P1)
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

#define MIN_YEAR 2012
#define MAX_YEAR 2022

int main(void)
{
    const int JAN = 1;
    const int DEC = 12;
    int month, year;
    printf("General Well-being Log\n");
    printf("======================\n");
    do
    {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &year, &month);
        if (year < MIN_YEAR || year > MAX_YEAR)
        {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
        }
        else if (month < JAN || month > 12)
        {
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }
    } while ((month < JAN || month > 12 ) || (year < MIN_YEAR || year > MAX_YEAR));
    printf("\n");
    printf("*** Log date set! ***\n\n");
    printf("Log starting date: ");
    switch (month)
    {
    case 1:
        printf("%d-JAN-01", year);
        break;
    case 2:
        printf("%d-FEB-01", year);
        break;
    case 3:
        printf("%d-MAR-01", year);
        break;
    case 4:
        printf("%d-APR-01", year);
        break;
    case 5:
        printf("%d-MAY-01", year);
        break;
    case 6:
        printf("%d-JUN-01", year);
        break;
    case 7:
        printf("%d-JUL-01", year);
        break;
    case 8:
        printf("%d-AUG-01", year);
        break;
    case 9:
        printf("%d-SEP-01", year);
        break;
    case 10:
        printf("%d-OCT-01", year);
        break;
    case 11:
        printf("%d-NOV-01", year);
        break;
    case 12:
        printf("%d-DEC-01", year);
        break;
    }
    return 0;
}