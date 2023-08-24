/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P2)
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
    const char patSize = 'S', salSize = 'M', tomSize = 'L';
    float sShirtPrice;
    float mShirtPrice;
    float lShirtPrice;
    int noOfPatShirts;
    int noOfTomShirts;
    int noOfSalShirts;
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
    scanf("%d", &noOfPatShirts);
    printf("\nTommy's shirt size is '%c'\n", tomSize);
    printf("Number of shirts Tommy is buying: ");
    scanf("%d", &noOfTomShirts);
    printf("\nSally's shirt size is '%c'\n", salSize);
    printf("Number of shirts Sally is buying: ");
    scanf("%d", &noOfSalShirts);
    printf("\nCustomer Size Price Qty Sub-Total       Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    float subTotal1 = (sShirtPrice * noOfPatShirts);
    double taxes1 = TAX * (sShirtPrice * noOfPatShirts);
    int taxCentsAfterRounding1 = (taxes1 + 0.005) * 100;
    printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", patSize, sShirtPrice, noOfPatShirts, subTotal1, (double)taxCentsAfterRounding1 / 100, subTotal1 + ((double)taxCentsAfterRounding1 / 100));
    float subTotal2 = (mShirtPrice * noOfSalShirts);
    double taxes2 = TAX * (mShirtPrice * noOfSalShirts);
    int taxCentsAfterRounding2 = (taxes2 + 0.005) * 100;
    printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", salSize, mShirtPrice, noOfSalShirts, subTotal2, (double)taxCentsAfterRounding2 / 100, subTotal2 + ((double)taxCentsAfterRounding2 / 100));
    float subTotal3 = (lShirtPrice * noOfTomShirts);
    double taxes3 = TAX * (lShirtPrice * noOfTomShirts);
    int taxCentsAfterRounding3 = (taxes3 + 0.005) * 100;
    printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", tomSize, lShirtPrice, noOfTomShirts, subTotal3, (double)taxCentsAfterRounding3 / 100, subTotal3 + ((double)taxCentsAfterRounding3 / 100));
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    float subTotal = subTotal1 + subTotal2 + subTotal3;
    double Taxes = ((double)taxCentsAfterRounding1 / 100) + ((double)taxCentsAfterRounding2 / 100) + ((double)taxCentsAfterRounding3 / 100);
    printf("                        %9.4lf %9.4lf %9.4lf\n\n", subTotal, Taxes, subTotal + Taxes);
    printf("Daily retail sales represented by coins\n");
    printf("=======================================\n\n");
    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("             %9.4lf\n", subTotal);
    int toonies = subTotal / 2;
    int loonies = (subTotal - (toonies * 2))/ 1;
    int quarters = (subTotal - (loonies + (toonies * 2))) / 0.25;
    int dimes = (subTotal - (loonies + (toonies * 2) + (quarters * 0.25))) / 0.10;
    int nickles = (subTotal - (loonies + (toonies * 2) + (quarters * 0.25)+ (dimes * 0.10)))/ 0.05;
    int pennies = (subTotal - (loonies + (toonies * 2) + (quarters * 0.25)+ (nickles * 0.05))) / 0.01;
    printf("Toonies  %d %9.4lf\n", (int)(subTotal / 2), subTotal - (2 * toonies));
    printf("Loonies  %3d % 9.4lf\n", loonies, (subTotal - (loonies + (toonies * 2))));
    printf("Quarters %3d %9.4lf\n", quarters, (subTotal - (loonies + (toonies * 2) + (quarters * 0.25))));
    printf("Dimes    %3d %9.4lf\n", dimes, (subTotal - (loonies + (toonies * 2) + (quarters * 0.25) + (dimes * 0.10))));
    printf("Nickels  %3d %9.4lf\n", nickles, (subTotal - (loonies + (toonies * 2) + (quarters * 0.25) + (nickles * 0.05))));
    printf("Pennies  %3d    0.0000\n\n", pennies);
    printf("Average cost/shirt: $%.4lf\n\n", subTotal / (noOfPatShirts + noOfSalShirts + noOfTomShirts) + 0.00005);
    printf("Sales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    double Total = subTotal + Taxes;
    printf("             %9.4lf\n", Total);
    toonies = Total / 2;
    loonies = (Total - (toonies * 2))/ 1;
    quarters = (Total - (loonies + (toonies * 2))) / 0.25;
    dimes = (Total - (loonies + (toonies * 2) + (quarters * 0.25))) / 0.10;
    nickles = (Total - (loonies + (toonies * 2) + (quarters * 0.25)+ (dimes * 0.10)))/ 0.05;
    pennies = (Total - (loonies + (toonies * 2) + (quarters * 0.25)+ (nickles * 0.05))) / 0.01;
    printf("Toonies  %d %9.4lf\n", (int)(Total / 2), Total - (2 * toonies));
    printf("Loonies  %3d % 9.4lf\n", loonies, (Total - (loonies + (toonies * 2))));
    printf("Quarters %3d %9.4lf\n", quarters, (Total - (loonies + (toonies * 2) + (quarters * 0.25))));
    printf("Dimes    %3d %9.4lf\n", dimes, (Total - (loonies + (toonies * 2) + (quarters * 0.25) + (dimes * 0.10))));
    printf("Nickels  %3d %9.4lf\n", nickles, (Total - (loonies + (toonies * 2) + (quarters * 0.25) + (nickles * 0.05))));
    printf("Pennies  %3d    0.0000\n\n", pennies);
    printf("Average cost/shirt: $%.4lf\n", Total / (noOfPatShirts + noOfSalShirts + noOfTomShirts) + 0.00005);

    return 0;
}