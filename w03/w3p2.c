/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
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
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;
    char coffee1Type, coffee2Type, coffee3Type;
    int coffee1weight, coffee2weight, coffee3weight;
    char coffee1cream, coffee2cream, coffee3cream;
    char customerCType;
    int customerNoOfServing;
    char customerCcream;
    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n\n");
    printf("Enter the coffee product information being sold today...\n\n");
    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffee1Type);
    printf("Bag weight (g): ");
    scanf(" %d", &coffee1weight);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffee1cream);
    printf("\n");
    printf("COFFEE-2...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffee2Type);
    printf("Bag weight (g): ");
    scanf(" %d", &coffee2weight);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffee2cream);
    printf("\n");
    printf("COFFEE-3...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffee3Type);
    printf("Bag weight (g): ");
    scanf(" %d", &coffee3weight);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffee3cream);
    printf("\n");
    printf("---+------------------------+---------------+-------+\n");
    printf("   |    Coffee              |   Packaged    | Best  |\n");
    printf("   |     Type               |  Bag Weight   | Served|\n");
    printf("   +------------------------+---------------+ With  |\n");
    printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
    printf("---+------------------------+---------------+-------|\n");
    printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", (coffee1Type == 'l' || coffee1Type == 'L'), (coffee1Type == 'm' || coffee1Type == 'L'), (coffee1Type == 'r' || coffee1Type == 'R'), coffee1weight, coffee1weight / GRAMS_IN_LBS, (coffee1cream == 'y' || coffee1cream == 'Y'));
    printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", (coffee2Type == 'l' || coffee2Type == 'L'), (coffee2Type == 'm' || coffee2Type == 'L'), (coffee2Type == 'r' || coffee2Type == 'R'), coffee2weight, coffee2weight / GRAMS_IN_LBS, (coffee2cream == 'y' || coffee2cream == 'Y'));
    printf(" 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n\n", (coffee3Type == 'l' || coffee3Type == 'L'), (coffee3Type == 'm' || coffee3Type == 'L'), (coffee3Type == 'r' || coffee3Type == 'R'), coffee3weight, coffee3weight / GRAMS_IN_LBS, (coffee3cream == 'y' || coffee3cream == 'Y'));
    printf("Enter how you like your coffee...\n\n");
    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &customerCType);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &customerCcream);
    printf("Typical number of daily servings: ");
    scanf(" %d", &customerNoOfServing);
    printf("\n");
    printf("The below table shows how your preferences align to the available products:\n\n");
    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n", (customerCType == coffee1Type || customerCType == 'L'), ((coffee1weight == 250 && customerNoOfServing < 5) || (coffee1weight == 500 && customerNoOfServing < 10 && customerNoOfServing > 4) || (coffee1weight == 1000 && customerNoOfServing > 9)), (((customerCcream == 'y' || customerCcream == 'Y') && (coffee1cream == 'y' || coffee1cream == 'Y')) || ((customerCcream == 'n' || customerCcream == 'N') && (coffee1cream == 'n' || coffee1cream == 'N'))));
    printf(" 2|       %d         |      %d      |   %d   |\n", (customerCType == coffee2Type || customerCType == 'r'), ((coffee2weight == 250 && customerNoOfServing < 5) || (coffee2weight == 500 && customerNoOfServing < 10 && customerNoOfServing > 4) || (coffee2weight == 1000 && customerNoOfServing > 9)), (((customerCcream == 'y' || customerCcream == 'Y') && (coffee2cream == 'y' || coffee2cream == 'Y')) || ((customerCcream == 'n' || customerCcream == 'N') && (coffee2cream == 'n' || coffee2cream == 'N'))));
    printf(" 3|       %d         |      %d      |   %d   |\n", (customerCType == coffee3Type || customerCType == 'M'), ((coffee3weight == 250 && customerNoOfServing < 5) || (coffee3weight == 500 && customerNoOfServing < 10 && customerNoOfServing > 4) || (coffee3weight == 1000 && customerNoOfServing > 9)), (((customerCcream == 'y' || customerCcream == 'Y') && (coffee3cream == 'y' || coffee3cream == 'Y')) || ((customerCcream == 'n' || customerCcream == 'N') && (coffee3cream == 'n' || coffee3cream == 'N'))));
    printf("\n");
    printf("Enter how you like your coffee...\n\n");
    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &customerCType);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &customerCcream);
    printf("Typical number of daily servings: ");
    scanf(" %d", &customerNoOfServing);
    printf("\n");
    printf("The below table shows how your preferences align to the available products:\n\n");
    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n", (customerCType == coffee1Type || customerCType == 'L'), ((coffee1weight == 250 && customerNoOfServing < 5) || (coffee1weight == 500 && customerNoOfServing < 10 && customerNoOfServing > 4) || (coffee1weight == 1000 && customerNoOfServing > 9)), (((customerCcream == 'y' || customerCcream == 'Y') && (coffee1cream == 'y' || coffee1cream == 'Y')) || ((customerCcream == 'n' || customerCcream == 'N') && (coffee1cream == 'n' || coffee1cream == 'N'))));
    printf(" 2|       %d         |      %d      |   %d   |\n", (customerCType == coffee2Type || customerCType == 'r'), ((coffee2weight == 250 && customerNoOfServing < 5) || (coffee2weight == 500 && customerNoOfServing < 10 && customerNoOfServing > 4) || (coffee2weight == 1000 && customerNoOfServing > 9)), (((customerCcream == 'y' || customerCcream == 'Y') && (coffee2cream == 'Y' || coffee2cream == 'y')) || ((customerCcream == 'n' || customerCcream == 'N') && (coffee2cream == 'n' || coffee2cream == 'N'))));
    printf(" 3|       %d         |      %d      |   %d   |\n\n", (customerCType == coffee3Type || customerCType == 'M'), ((coffee3weight == 250 && customerNoOfServing < 5) || (coffee3weight == 500 && customerNoOfServing < 10 && customerNoOfServing > 4) || (coffee3weight == 1000 && customerNoOfServing > 9)), (((customerCcream == 'y' || customerCcream == 'Y') && (coffee3cream == 'y' || coffee3cream == 'Y')) || ((customerCcream == 'n' || customerCcream == 'N') && (coffee3cream == 'n' || coffee3cream == 'N'))));
    printf("Hope you found a product that suits your likes!\n");
    return 0;
}


/*
Provided formatting parts for printf statements:
As described in step-7
======================
printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",
As described in step-10
=======================
printf(" 1|       %d         |      %d      |   %d   |\n",
*/