/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P1)
Full Name  : Sakshi Sakshi
Student ID#: 112602222
Email      : ssakshi7@myseneca.ca
Section    : NFF
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/


// ----------------------------------------------------------------------------
//MACROS
#define MAX_PRODUCTS 3
#define NUM_OF_GRAMS 64


// structures
struct CatFoodInfo
{
    int skuNumber;
    double price;
    int calPerServe;
    double weight;
};



// ----------------------------------------------------------------------------
// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* x);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* y);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int m);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int n);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int a, const double* b, const int c, const double* d);

// 7. Logic entry point
void start(void);








