/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P1)
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

#define MAX_ITEMS 10 // Macro for maximum number of wishlist items

#include <stdio.h>

int main(void)
{

    const float minIncome = 500;
    const float maxIncome = 400000;
    const float minItemPrice = 100;
    float monthlyIncome;
    int numOfItems, i, j, k;
    // Parallel arrays for item characteristics
    double Cost[MAX_ITEMS];
    int Priority[MAX_ITEMS];
    char Finance[MAX_ITEMS];
    double cost;
    double totalCost = 0;
    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n\n");
    printf("Enter your monthly NET income: $");
    scanf("%f", &monthlyIncome);
    while (monthlyIncome < minIncome || monthlyIncome > maxIncome)
    {
        if (monthlyIncome < minIncome)
        {
            printf("ERROR: You must have a consistent monthly income of at least $%.2f\n\n", minIncome);
        }
        else
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2f\n\n", maxIncome);
        }
        printf("Enter your monthly NET income: $");
        scanf("%f", &monthlyIncome);
    }
    printf("\n");
    printf("How many wish list items do you want to forecast?: ");
    scanf("%d", &numOfItems);
    while (numOfItems < 1 || numOfItems > MAX_ITEMS)
    {
        printf("ERROR: List is restricted to between 1 and %d items.\n\n", MAX_ITEMS);
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d", &numOfItems);
    }
    printf("\n");
    for (i = 0; i < numOfItems; i++)
    {
        printf("Item-%i Details:\n", i + 1);
        printf("   Item cost: $");
        scanf("%lf", &cost);
        while (cost < minItemPrice)
        {
            printf("      ERROR: Cost must be at least $%.2lf\n", minItemPrice);
            printf("   Item cost: $");
            scanf("%lf", &cost);
        }
        Cost[i] = cost;
        printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
        scanf("%d", &Priority[i]);
        while (Priority[i] < 1 || Priority[i] > 3)
        {
            printf("      ERROR: Value must be between 1 and 3\n");
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &Priority[i]);
        }
        printf("   Does this item have financing options? [y/n]: ");
        scanf(" %c", &Finance[i]);
        while (Finance[i] != 'y' && Finance[i] != 'n')
        {
            printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &Finance[i]);
        }
        printf("\n");
    }
    // Iteration construct for calculating total cost of wishlist items
    for (j = 0; j < numOfItems; j++)
    {
        totalCost = totalCost + Cost[j];
    }
    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    for (k = 0; k < numOfItems; k++)
    {
        printf("%3d  %5d    %5c    %11.2lf\n", k + 1, Priority[k], Finance[k], Cost[k]);
    }
    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", totalCost);
    printf("Best of luck in all your future endeavours!\n");
    return 0;

}