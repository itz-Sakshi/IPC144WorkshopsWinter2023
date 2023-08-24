/*
*****************************************************************************
                          Workshop - #4 (P2)
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

int main(void)
{
    int shopAgain = 1; // Used as a flag
    do
    {
        int numApples = 0, numOranges = 0, numPears = 0, numTomatoes = 0, numCabbages = 0;
        printf("Grocery Shopping\n");
        printf("================\n");
        do
        {
            printf("How many APPLES do you need? : ");
            scanf("%d", &numApples);
            if (numApples < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (numApples < 0);
        printf("\n");
        do
        {
            printf("How many ORANGES do you need? : ");
            scanf("%d", &numOranges);
            if (numOranges < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (numOranges < 0);
        printf("\n");
        do
        {
            printf("How many PEARS do you need? : ");
            scanf("%d", &numPears);
            if (numPears < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (numPears < 0);
        printf("\n");
        do
        {
            printf("How many TOMATOES do you need? : ");
            scanf("%d", &numTomatoes);
            if (numTomatoes < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (numTomatoes < 0);
        printf("\n");
        do
        {
            printf("How many CABBAGES do you need? : ");
            scanf("%d", &numCabbages);
            if (numCabbages < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (numCabbages < 0);
        printf("\n");
        printf("--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n\n");
        if (numApples > 0)
        {
            int i = 0, count = 0;
            while (count < numApples)
            {
                printf("Pick some APPLES... how many did you pick? : ");
                scanf("%d", &i);
                if (i > 0 && (count + i) <= numApples)
                {
                    count = count + i;
                    if (count < numApples)
                    {
                        printf("Looks like we still need some APPLES...\n");
                    }
                }
                else if (i > 0 && (count + i) > numApples)
                {
                    printf("You picked too many... only %d more APPLE(S) are needed.\n", (numApples - count));
                }
                else  
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
            }
            printf("Great, that's the apples done!\n\n");
        }
        if (numOranges > 0)
                {
                    int i = 0, count = 0;
                    while (count < numOranges)
                    {
                        printf("Pick some ORANGES... how many did you pick? : ");
                        scanf("%d", &i);
                        if (i > 0 && (count + i) <= numOranges)
                        {
                            count = count + i;
                            if (count < numOranges)
                            {
                                printf("Looks like we still need some ORANGES...\n");
                            }
                        }
                        else if (i > 0 && (count + i) > numOranges)
                        {
                            printf("You picked too many... only %d more ORANGE(S) are needed.\n", (numOranges - count));
                        }
                        else  
                        {
                            printf("ERROR: You must pick at least 1!\n");
                        }
                    }
                    printf("Great, that's the oranges done!\n\n");
                }
        if (numPears > 0)
                {
                    int i = 0, count = 0;
                    while (count < numPears)
                    {
                        printf("Pick some PEARS... how many did you pick? : ");
                        scanf("%d", &i);
                        if (i > 0 && (count + i) <= numPears)
                        {
                            count = count + i;
                            if (count < numPears)
                            {
                                printf("Looks like we still need some PEARS...\n");
                            }
                        }
                        else if (i > 0 && (count + i) > numPears)
                        {
                            printf("You picked too many... only %d more PEAR(S) are needed.\n", (numPears - count));
                        }
                        else  
                        {
                            printf("ERROR: You must pick at least 1!\n");
                        }
                    }
                    printf("Great, that's the pears done!\n\n");
                }
        if (numTomatoes > 0)
                {
                    int i = 0, count = 0;
                    while (count < numTomatoes)
                    {
                        printf("Pick some TOMATOES... how many did you pick? : ");
                        scanf("%d", &i);
                        if (i > 0 && (count + i) <= numTomatoes)
                        {
                            count = count + i;
                            if (count < numTomatoes)
                            {
                                printf("Looks like we still need some TOMATOES...\n");
                            }
                        }
                        else if (i > 0 && (count + i) > numTomatoes)
                        {
                            printf("You picked too many... only %d more TOMATO(ES) are needed.\n", (numTomatoes - count));
                        }
                        else  
                        {
                            printf("ERROR: You must pick at least 1!\n");
                        }
                    }
                    printf("Great, that's the tomatoes done!\n\n");
                }
        if (numCabbages > 0)
                {
                    int i = 0, count = 0;
                    while (count < numCabbages)
                    {
                        printf("Pick some CABBAGES... how many did you pick? : ");
                        scanf("%d", &i);
                        if (i > 0 && (count + i) <= numCabbages)
                        {
                            count = count + i;
                            if (count < numCabbages)
                            {
                                printf("Looks like we still need some CABBAGES...\n");
                            }
                        }
                        else if (i > 0 && (count + i) > numCabbages)
                        {
                            printf("You picked too many... only %d more CABBAGE(S) are needed.\n", (numCabbages - count));
                        }
                        else  
                        {
                            printf("ERROR: You must pick at least 1!\n");
                        }
                    }
                    printf("Great, that's the cabbages done!\n\n");
                }
        printf("All the items are picked!\n\n");
        printf("Do another shopping? (0=NO): ");
        scanf("%d", &shopAgain);
        printf("\n");
    } while (shopAgain != 0);
    printf("Your tasks are done for today - enjoy your free time!\n");
    return 0;
}