/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P2)
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


// System Libraries
#include <stdio.h>

// User-Defined Libraries
#include "w8p2.h"

// ----------------------------------------------------------------------------
// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* intPos)
{
    int s;
    do
    {
        scanf("%d", &s);
        if (intPos != NULL)
        {
            *intPos = s;
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
double getDoublePositive(double* dblPos)
{
    double dbl;
    do
    {
        scanf("%lf", &dbl);
        if (dblPos != NULL)
        {
            *dblPos = dbl;
        }
        if (dbl <= 0)
        {
            printf("ERROR: Enter a positive value: ");
        }
    } while (dbl <= 0);
    return dbl;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numProds)
{
    printf("Cat Food Cost Analysis\n"
        "======================\n\n");
    printf("Enter the details for %d dry food bags of product data for analysis.\n", numProds);
    printf("NOTE: A 'serving' is %dg\n\n", NUM_OF_GRAMS);
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int SNum)
{
    printf("Cat Food Product #%d\n", SNum + 1);
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
void displayCatFoodData(const int skuNum, const double* price, const int calPerServe, const double* weight)
{
    printf("%07d %10.2lf %10.1lf %8d\n", skuNum, *price, *weight, calPerServe);
}


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* lbs, double* dblA)
{
    double var1;
    var1 = (*lbs) / (KG_FACTOR);
    if (dblA != NULL)
    {
        *dblA = var1;
    }
    return var1;
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* lbs2, int* intA)
{
    int var2;
    var2 = (*lbs2 / KG_FACTOR) * 1000;
    if (intA != NULL)
    {
        *intA = var2;
    }
    return var2;
}

// 10. convert lbs: kg and g
void convertLbs(const double* lbs3, double* dbl1, int* intB)
{
    *dbl1 = convertLbsKg(lbs3, dbl1);
    *intB = convertLbsG(lbs3, intB);
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int numOfGrams, const int weightInGrams, double* u)
{
    if (u != NULL)
    {
        *u = (double)weightInGrams / (double)numOfGrams;
    }
    return (double)weightInGrams / (double)numOfGrams;
}


// 12. calculate: cost per serving
double calculateCostPerServing(const double* price2, const double* totalSrvings, double* f)
{
    if (f != NULL)
    {
        *f = *price2 / *totalSrvings;
    }
    return (*price2 / *totalSrvings);
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* g, const double* h, double* i)
{
    if (i != NULL)
    {
        *i = *g / *h;
    }
    return (*g / *h);
}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo str)
{
    struct ReportData prodReport = { 0, 0.0 , 0, 0.0, 0.0, 0, 0.0, 0.0, 0.0 };
    prodReport.skuNumber = str.skuNumber;
    prodReport.price = str.price;
    prodReport.calPerServe = str.calPerServe;
    prodReport.weightLbs = str.weight;
    convertLbs(&str.weight, &prodReport.weightKg, &prodReport.weightGrams);
    prodReport.totalServings = calculateServings(NUM_OF_GRAMS, prodReport.weightGrams, NULL);
    prodReport.costPerServe = calculateCostPerServing(&str.price, &prodReport.totalServings, NULL);
    double total_calories = (prodReport.calPerServe) * (prodReport.totalServings);
    prodReport.costPerCal = calculateCostPerCal(&str.price, &total_calories, NULL);
    return prodReport;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
    printf("Analysis Report (Note: Serving = %dg)\n", NUM_OF_GRAMS);
    printf("---------------\n");
    printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
    printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData prodReport, const int cheapVar)
{
    printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", prodReport.skuNumber, prodReport.price, prodReport.weightLbs, prodReport.weightKg, prodReport.weightGrams, prodReport.calPerServe, prodReport.totalServings, prodReport.costPerServe, prodReport.costPerCal);
    if (cheapVar != 0)
    {
        printf(" ***\n");
    }
    else
    {
        printf("\n");
    }
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo strc)
{
    printf("Final Analysis\n"
        "--------------\n");
    printf("Based on the comparison data, the PURRR-fect economical option is:\n");
    printf("SKU:%07d ", strc.skuNumber);
    printf("Price: $%04.2lf\n\n", strc.price);
    printf("Happy shopping!\n");
}

// ----------------------------------------------------------------------------

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
    struct ReportData report[MAX_PRODUCTS] = { {0, 0.0, 0, 0.0, 0.0, 0, 0.0, 0.0, 0.0} };
    int variable = 0;
    int cheapestVar;
    double costPerServing = 0.0;
    for (i = 0; i < MAX_PRODUCTS; i++)
    {
        report[i] = calculateReportData(products[i]);
        if (i == 1)
        {
            costPerServing = report[i - 1].costPerServe;
        }
        if (i > 0 && report[i].costPerServe < costPerServing)
        {
            cheapestVar = i;
            costPerServing = report[i].costPerServe;
            variable++;
        }
    }
    if (variable == 0)
    {
        cheapestVar = 0;
    }
    printf("\n");
    displayReportHeader();
    for (j = 0; j < MAX_PRODUCTS; j++)
    {
        int checkCheap = 0;
        if (j == cheapestVar)
        {
            checkCheap++;
        }
        displayReportData(report[j], checkCheap);
    }
    printf("\n");
    displayFinalAnalysis(products[cheapestVar]);

}