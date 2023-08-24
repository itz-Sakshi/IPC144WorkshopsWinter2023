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
// defines/macros
#define MAX_PRODUCTS 3
#define NUM_OF_GRAMS 64
#define KG_FACTOR 2.20462

// structures
struct CatFoodInfo
{
    int skuNumber;
    double price;
    int calPerServe;
    double weight;
};

struct ReportData
{
    int skuNumber;
    double price;
    int calPerServe;
    double weightLbs;
    double weightKg;
    int weightGrams;
    double totalServings;
    double costPerServe;
    double costPerCal;
};


// ----------------------------------------------------------------------------
// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* intPos);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* dblPos);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numProds);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int SNum);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int skuNum, const double* price, const int calPerServe, const double* weight);


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double* lbs, double* dblA);

// 9. convert lbs: g
int convertLbsG(const double* lbs2, int* intA);


// 10. convert lbs: kg / g
void convertLbs(const double* lbs3, double* dbl1, int* intB);

// 11. calculate: servings based on gPerServ
double calculateServings(const int numOfGrams, const int weightInGrams, double* u);

// 12. calculate: cost per serving
double calculateCostPerServing(const double* price2, const double* totalSrvings, double* f);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* g, const double* h, double* i);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo str);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData, const int cheap_var);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo strc);

// ----------------------------------------------------------------------------

// 7. Logic entry point 
void start(void);