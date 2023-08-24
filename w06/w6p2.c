/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P2)
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
    int numOfItems, i, j, k, selection, countFinance, priorityFilter, item;
    // Parallel arrays for item characteristics
    double Cost[MAX_ITEMS];
    int Priority[MAX_ITEMS];
    char Finance[MAX_ITEMS];
    double cost, priorityCost;
    double totalCost = 0;
    int flag = 1; 
    int years;
    float months;
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
    while (flag)
    {
        printf("How do you want to forecast your wish list?\n");
        printf(" 1. All items (no filter)\n");
        printf(" 2. By priority\n");
        printf(" 0. Quit/Exit\n");
        printf("Selection: ");
        scanf("%d", &selection);
        printf("\n");
        if (selection == 0)
        {
            flag = 0;
        }
        if (selection == 1)
        {
            printf("====================================================\n");
            printf("Filter:   All items\n");
            printf("Amount:   $%1.2lf\n", totalCost);
            years = totalCost / ((monthlyIncome) * 12);
            months = ((int)totalCost % (12 * (int)monthlyIncome)) / monthlyIncome;
            if ((months - (int)months) > 0)
            {
                printf("Forecast: %d years, %d months\n", years, (int)(months + 1));
            }
            else
            {
                printf("Forecast: %d years, %d months\n", years, (int)months);
            }
        }
        if (selection != 1 && selection != 2 && selection != 0)
        {
            printf("ERROR: Invalid menu selection.\n\n");
        }
        if (selection == 2)
        {
            priorityFilter = 0;
            printf("What priority do you want to filter by? [1-3]: ");
            scanf("%d", &priorityFilter);
            printf("\n");
            printf("====================================================\n");
            printf("Filter:   by priority (%d)\n", priorityFilter);
            priorityCost = 0; 
            for (item = 0; item < numOfItems; item++)
            {
                if (Priority[item] == priorityFilter)
                {
                    priorityCost = priorityCost + Cost[item];
                }
            }
            printf("Amount:   $%1.2lf\n", priorityCost);
            years = priorityCost / ((monthlyIncome) * 12);
            months = ((int)priorityCost % (12 * (int)monthlyIncome)) / monthlyIncome; // Variable for calculating remaining months
            if ((months - (int)months) > 0)
            {
                printf("Forecast: %d years, %d months\n", years, (int)(months + 1));
            }
            else
            {
                printf("Forecast: %d years, %d months\n", years, (int)months);
            }
           
        }
        if (selection == 1)
        {
            // Iteration construct for checking financing options on items
            countFinance = 0;
            for (item = 0; item < numOfItems; item++)
            {
                if (Finance[item] == 'y')
                {
                    countFinance++;
                }
            }
            if (countFinance >= 1)
            {
                printf("NOTE: Financing options are available on some items.\n");
                printf("      You can likely reduce the estimated months.\n");
            }
            printf("====================================================\n\n");
        }if (selection == 2)
        {
            // Iteration construct for checking financing options on items
            countFinance = 0;
            for (item = 0; item < numOfItems; item++)
            {
                if (Finance[item] == 'y' && Priority[item] == priorityFilter)
                {
                    countFinance++;
                }
            }
            if (countFinance >= 1)
            {
                printf("NOTE: Financing options are available on some items.\n");
                printf("      You can likely reduce the estimated months.\n");
            }
            printf("====================================================\n\n");
        }
    }
    printf("Best of luck in all your future endeavours!\n");
    return 0;

}