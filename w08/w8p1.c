/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P1)
Full Name  : Sakshi Sakshi
Student ID#: 112602222
Email      : ssakshi7@myseneca.ca
Section    : NFF
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS


// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* x)
{
    int s;
    do
    {
        scanf("%d", &s);
        if (x != NULL)
        {
            *x = s;
        }
        if (s <= 0)
        {
            printf("ERROR: Enter a positive value: ");
        }
    } while (s <= 0);
    return s;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* y)
{
    double dbl;
    do
    {
        scanf("%lf", &dbl);
        if (y != NULL)
        {
            *y = dbl;
        }
        if (dbl <= 0)
        {
            printf("ERROR: Enter a positive value: ");
        }
    } while (dbl <= 0);
    return dbl;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int m)
{
    printf("Cat Food Cost Analysis\n"
        "======================\n\n");
    printf("Enter the details for %d dry food bags of product data for analysis.\n", m);
    printf("NOTE: A 'serving' is %dg\n\n", NUM_OF_GRAMS);
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int n)
{
    printf("Cat Food Product #%d\n", n + 1);
    printf("--------------------\n");
    printf("SKU           : ");
    struct CatFoodInfo product = { 0, 0.0, 0 ,0.0 };
    product.skuNumber = getIntPositive(NULL);
    printf("PRICE         : $");
    product.price = getDoublePositive(NULL);
    printf("WEIGHT (LBS)  : ");
    product.weight = getDoublePositive(NULL);
    printf("CALORIES/SERV.: ");
    product.calPerServe = getIntPositive(NULL);
    return product;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
    printf("SKU         $Price    Bag-lbs Cal/Serv\n");
    printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int a, const double* b, const int c, const double* d)
{
    printf("%07d %10.2lf %10.1lf %8d\n", a, *b, *d, c);
}

// 7. Logic entry point
void start(void)
{
    int i;
    int j;
    struct CatFoodInfo products[MAX_PRODUCTS] = { {0, 0.0, 0, 0.0} };
    openingMessage(MAX_PRODUCTS);
    for (i = 0; i < MAX_PRODUCTS; i++)
    {
        products[i] = getCatFoodInfo(i);
        printf("\n");
    }
    displayCatFoodHeader();
    for (j = 0; j < MAX_PRODUCTS; j++)
    {
        displayCatFoodData(products[j].skuNumber, &products[j].price, products[j].calPerServe, &products[j].weight);
    }
}










