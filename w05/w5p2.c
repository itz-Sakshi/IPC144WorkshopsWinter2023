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
#define LOG_DAYS 3

int main(void)
{
    const int JAN = 1;
    int month, year, day;
    double morningRating, morningRatingTotal = 0;
    double eveningRating, eveningRatingTotal = 0;
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
        if (month < JAN || month > 12)
        {
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }
    } while ((month < JAN || month > 12) || (year < MIN_YEAR || year > MAX_YEAR));
    printf("\n");
    printf("*** Log date set! ***\n\n");
    switch (month)
    {
    case 1:
        for (day = 1; day < LOG_DAYS + 1; day++)
        {
            day <= 9 ? printf("%d-JAN-0%d\n", year, day) : printf("%d-JAN-%d\n", year, day);
            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf("%lf", &morningRating);
                if (morningRating < 0.0 || morningRating > 5.0)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while (morningRating < 0.0 || morningRating > 5.0);
            morningRatingTotal = morningRatingTotal + morningRating;
            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf("%lf", &eveningRating);
                if (eveningRating < 0.0 || eveningRating > 5.0)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while (eveningRating < 0.0 || eveningRating > 5.0);
            eveningRatingTotal = eveningRatingTotal + eveningRating;
            printf("\n");
        }
        break;
    case 2:
        for (day = 1; day < LOG_DAYS + 1; day++)
        {
            day <= 9 ? printf("%d-FEB-0%d\n", year, day) : printf("%d-FEB-%d\n", year, day);
            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf("%lf", &morningRating);
                if (morningRating < 0.0 || morningRating > 5.0)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while (morningRating < 0.0 || morningRating > 5.0);
            morningRatingTotal = morningRatingTotal + morningRating;
            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf("%lf", &eveningRating);
                if (eveningRating < 0.0 || eveningRating > 5.0)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while (eveningRating < 0.0 || eveningRating > 5.0);
            printf("\n");
            eveningRatingTotal = eveningRatingTotal + eveningRating;
        }
        break;
    case 3:
        for (day = 1; day < LOG_DAYS + 1; day++)
        {
            day <= 9 ? printf("%d-MAR-0%d\n", year, day) : printf("%d-MAR-%d\n", year, day);
            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf("%lf", &morningRating);
                if (morningRating < 0.0 || morningRating > 5.0)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while (morningRating < 0.0 || morningRating > 5.0);
            morningRatingTotal = morningRatingTotal + morningRating;
            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf("%lf", &eveningRating);
                if (eveningRating < 0.0 || eveningRating > 5.0)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while (eveningRating < 0.0 || eveningRating > 5.0);
            printf("\n");
            eveningRatingTotal = eveningRatingTotal + eveningRating;
        }
        break;
    case 4:
        for (day = 1; day < LOG_DAYS + 1; day++)
        {
            day <= 9 ? printf("%d-APR-0%d\n", year, day) : printf("%d-APR-%d\n", year, day);
            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf("%lf", &morningRating);
                if (morningRating < 0.0 || morningRating > 5.0)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while (morningRating < 0.0 || morningRating > 5.0);
            morningRatingTotal = morningRatingTotal + morningRating;
            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf("%lf", &eveningRating);
                if (eveningRating < 0.0 || eveningRating > 5.0)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while (eveningRating < 0.0 || eveningRating > 5.0);
            printf("\n");
            eveningRatingTotal = eveningRatingTotal + eveningRating;
        }
        break;
    case 5:
        for (day = 1; day < LOG_DAYS + 1; day++)
        {
            day <= 9 ? printf("%d-MAY-0%d\n", year, day) : printf("%d-MAY-%d\n", year, day);
            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf("%lf", &morningRating);
                if (morningRating < 0.0 || morningRating > 5.0)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while (morningRating < 0.0 || morningRating > 5.0);
            morningRatingTotal = morningRatingTotal + morningRating;
            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf("%lf", &eveningRating);
                if (eveningRating < 0.0 || eveningRating > 5.0)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while (eveningRating < 0.0 || eveningRating > 5.0);
            printf("\n");
            eveningRatingTotal = eveningRatingTotal + eveningRating;
        }
        printf("\n");
        break;
    case 6:
        for (day = 1; day < LOG_DAYS + 1; day++)
        {
            day <= 9 ? printf("%d-JUN-0%d\n", year, day) : printf("%d-JUN-%d\n", year, day);
            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf("%lf", &morningRating);
                if (morningRating < 0.0 || morningRating > 5.0)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while (morningRating < 0.0 || morningRating > 5.0);
            morningRatingTotal = morningRatingTotal + morningRating;
            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf("%lf", &eveningRating);
                if (eveningRating < 0.0 || eveningRating > 5.0)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while (eveningRating < 0.0 || eveningRating > 5.0);
            printf("\n");
            eveningRatingTotal = eveningRatingTotal + eveningRating;
        }
        printf("\n");
        break;
    case 7:
        for (day = 1; day < LOG_DAYS + 1; day++)
        {
            day <= 9 ? printf("%d-JUL-0%d\n", year, day) : printf("%d-JUL-%d\n", year, day);
            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf("%lf", &morningRating);
                if (morningRating < 0.0 || morningRating > 5.0)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while (morningRating < 0.0 || morningRating > 5.0);
            morningRatingTotal = morningRatingTotal + morningRating;
            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf("%lf", &eveningRating);
                if (eveningRating < 0.0 || eveningRating > 5.0)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while (eveningRating < 0.0 || eveningRating > 5.0);
            printf("\n");
            eveningRatingTotal = eveningRatingTotal + eveningRating;
        }
        printf("\n");
        break;
    case 8:
        for (day = 1; day < LOG_DAYS + 1; day++)
        {
            day <= 9 ? printf("%d-AUG-0%d\n", year, day) : printf("%d-AUG-%d\n", year, day);
            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf("%lf", &morningRating);
                if (morningRating < 0.0 || morningRating > 5.0)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while (morningRating < 0.0 || morningRating > 5.0);
            morningRatingTotal = morningRatingTotal + morningRating;
            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf("%lf", &eveningRating);
                if (eveningRating < 0.0 || eveningRating > 5.0)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while (eveningRating < 0.0 || eveningRating > 5.0);
            printf("\n");
            eveningRatingTotal = eveningRatingTotal + eveningRating;
        }
        printf("\n");
        break;
    case 9:
        for (day = 1; day < LOG_DAYS + 1; day++)
        {
            day <= 9 ? printf("%d-SEP-0%d\n", year, day) : printf("%d-SEP-%d\n", year, day);
            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf("%lf", &morningRating);
                if (morningRating < 0.0 || morningRating > 5.0)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while (morningRating < 0.0 || morningRating > 5.0);
            morningRatingTotal = morningRatingTotal + morningRating;
            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf("%lf", &eveningRating);
                if (eveningRating < 0.0 || eveningRating > 5.0)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while (eveningRating < 0.0 || eveningRating > 5.0);
            printf("\n");
            eveningRatingTotal = eveningRatingTotal + eveningRating;
        }
        printf("\n");
        break;
    case 10:
        for (day = 1; day < LOG_DAYS + 1; day++)
        {
            day <= 9 ? printf("%d-OCT-0%d\n", year, day) : printf("%d-OCT-%d\n", year, day);
            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf("%lf", &morningRating);
                if (morningRating < 0.0 || morningRating > 5.0)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while (morningRating < 0.0 || morningRating > 5.0);
            morningRatingTotal = morningRatingTotal + morningRating;
            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf("%lf", &eveningRating);
                if (eveningRating < 0.0 || eveningRating > 5.0)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while (eveningRating < 0.0 || eveningRating > 5.0);
            printf("\n");
            eveningRatingTotal = eveningRatingTotal + eveningRating;
        }
        printf("\n");
        break;
    case 11:
        for (day = 1; day < LOG_DAYS + 1; day++)
        {
            day <= 9 ? printf("%d-NOV-0%d\n", year, day) : printf("%d-NOV-%d\n", year, day);
            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf("%lf", &morningRating);
                if (morningRating < 0.0 || morningRating > 5.0)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while (morningRating < 0.0 || morningRating > 5.0);
            morningRatingTotal = morningRatingTotal + morningRating;
            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf("%lf", &eveningRating);
                if (eveningRating < 0.0 || eveningRating > 5.0)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while (eveningRating < 0.0 || eveningRating > 5.0);
            printf("\n");
            eveningRatingTotal = eveningRatingTotal + eveningRating;
        }
        printf("\n");
        break;
    case 12:
        for (day = 1; day < LOG_DAYS + 1; day++)
        {
            day <= 9 ? printf("%d-DEC-0%d\n", year, day) : printf("%d-DEC-%d\n", year, day);
            do
            {
                printf("   Morning rating (0.0-5.0): ");
                scanf("%lf", &morningRating);
                if (morningRating < 0.0 || morningRating > 5.0)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while (morningRating < 0.0 || morningRating > 5.0);
            morningRatingTotal = morningRatingTotal + morningRating;
            do
            {
                printf("   Evening rating (0.0-5.0): ");
                scanf("%lf", &eveningRating);
                if (eveningRating < 0.0 || eveningRating > 5.0)
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                }
            } while (eveningRating < 0.0 || eveningRating > 5.0);
            printf("\n");
            eveningRatingTotal = eveningRatingTotal + eveningRating;
        }
        printf("\n");
        break;
    }
    printf("Summary\n");
    printf("=======\n");
    printf("Morning total rating: %6.3lf\n", morningRatingTotal);
    printf("Evening total rating: %6.3lf\n", eveningRatingTotal);
    printf("----------------------------\n");
    printf("Overall total rating: %6.3lf\n\n", morningRatingTotal + eveningRatingTotal);
    printf("Average morning rating: %4.1lf\n", morningRatingTotal / LOG_DAYS);
    printf("Average evening rating: %4.1lf\n", eveningRatingTotal / LOG_DAYS);
    printf("----------------------------\n");
    printf("Average overall rating: %4.1lf\n", (morningRatingTotal / LOG_DAYS + eveningRatingTotal / LOG_DAYS) / 2);
    return 0;
}