/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
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
    const double TAX = 0.13;
    const char patSize = 'S';
    float sShirtPrice;
    float mShirtPrice;
    float lShirtPrice;
    int noOfShirts;
    printf("Set Shirt Prices\n"
           "================\n"
           "Enter the price for a SMALL shirt: $");
    scanf("%f", &sShirtPrice);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%f", &mShirtPrice);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%f", &lShirtPrice);
    printf("\nShirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2f\n", sShirtPrice);
    printf("MEDIUM : $%.2f\n", mShirtPrice);
    printf("LARGE  : $%.2f\n\n", lShirtPrice);
    printf("Patty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &noOfShirts); 
    printf("\nPatty's shopping cart...\n");
    printf("Contains : %d shirts\n", noOfShirts);
    float subTotal = (sShirtPrice * noOfShirts);
    double taxes = TAX * (sShirtPrice * noOfShirts);
    int taxCentsAfterRounding = (taxes + 0.005) * 100;
    printf("Sub-total: $%8.4f\n", subTotal);
    printf("Taxes    : $%8.4f\n", (float)taxCentsAfterRounding/100);
    printf("Total    : $%8.4f\n", subTotal + (float)taxCentsAfterRounding / 100);
    return 0;
}