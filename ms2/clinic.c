/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2
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
#include <string.h>

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"



//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            printf("<<< Feature not yet available >>>\n\n");
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ", patient->patientNumber, patient->name);
        
        displayFormattedPhone(patient->phone.number);
        
        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! Put all the remaining function definitions below !!!
// Note: Maintain the same order/sequence as it is listed in the header file
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i, j;
    int a = 0;
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber == 0)
        {
            a++;
        }
    }
    if (a == max)
    {
        printf("*** No records found ***\n");
    }
    else
    {
        displayPatientTableHeader();
        for (j = 0; j < max; j++)
        {
            if (patient[j].patientNumber != 0)
            {
                displayPatientData(&patient[j], fmt);
            }
        }
        printf("\n");
    }
}


// Search for a patient record based on patient number or phone number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientData(const struct Patient patient[], int max)
{
    int selection;
    do
    {
        printf("Search Options\n"
            "==========================\n"
            "1) By patient number\n"
            "2) By phone number\n"
            "..........................\n"
            "0) Previous menu\n"
            "..........................\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        if (selection == 1)
        {
            searchPatientByPatientNumber(patient, max);
            clearInputBuffer();
            suspend();
        }
        else if (selection == 2)
        {
            searchPatientByPhoneNumber(patient, max);
            clearInputBuffer();
            suspend();
        }
    } while (selection);

}

// Add a new patient record to the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void addPatient(struct Patient patient[], int max)
{
    int i;
    int a = -1;
    for (i = 0; i < max && patient[i - 1].patientNumber != 0; i++)
    {
        if (patient[i].patientNumber == 0)
        {
            a = i;
        }
    }
    if (a == -1)
    {
        printf("ERROR: Patient listing is FULL!\n\n");
    }
    else
    {
        int n = nextPatientNumber(patient, max);
        patient[a].patientNumber = n;
        inputPatient(&patient[a]);
        printf("*** New patient record added ***\n\n");
    }
}

// Edit a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void editPatient(struct Patient patient[], int max)
{
    int num4;
    printf("Enter the patient number: ");
    scanf("%d", &num4);
    printf("\n");
    int b = findPatientIndexByPatientNum(num4, patient, max);
    if (b == -1)
    {
        printf("ERROR: Patient record not found!\n");
    }
    else
    {
        menuPatientEdit(&patient[b]);
    }
}

// Remove a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void removePatient(struct Patient patient[], int max)
{
    int num;
    char c;
    printf("Enter the patient number: ");
    scanf("%d", &num);
    int b = findPatientIndexByPatientNum(num, patient, max);
    if (b == -1)
    {
        printf("\nERROR: Patient record not found!\n\n");
        clearInputBuffer();
    }
    else
    {
        printf("\n");
        displayPatientData(&patient[b], FMT_FORM);
        printf("\nAre you sure you want to remove this patient record? (y/n): ");
        scanf(" %c", &c);
        char s[NAME_LEN + 1] = "\0";
        char str[PHONE_DESC_LEN + 1] = "\0";
        char str1[PHONE_LEN + 1] = "\0";
        if (c == 'y')
        {
            patient[b].patientNumber = 0;
            strcpy(patient[b].name, s);
            strcpy(patient[b].phone.number, str);
            strcpy(patient[b].phone.description, str1);
            printf("Patient record has been removed!\n\n");
            clearInputBuffer();
        }
        else
        {
            printf("Operation aborted.\n\n");
            clearInputBuffer();
        }
    }
}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    int x;
    int numb;
    printf("Search by patient number: ");
    scanf("%d", &numb);
    printf("\n");
    x = findPatientIndexByPatientNum(numb, patient, max);
    if (x == -1)
    {
        printf("*** No records found ***\n\n");
    }
    else
    {
        displayPatientData(&patient[x], FMT_FORM);
        printf("\n");
    }
}

// Search and display patient records by phone number (tabular)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    int i;
    int y = 0;
    char ph_num[PHONE_LEN + 1];
    printf("Search by phone number: ");
    scanf("%s", ph_num);
    printf("\n");
    displayPatientTableHeader();
    for (i = 0; i < max; i++)
    {
        if (strcmp(patient[i].phone.number, ph_num) == 0)
        {
            displayPatientData(&patient[i], FMT_TABLE);
            y++;
        }
    }
    printf("\n");
    if (y == 0)
    {
        printf("*** No records found ***\n\n");
    }
}


// Get the next highest patient number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int nextPatientNumber(const struct Patient patient[], int max)
{
    int numb1 = 0;
    int i;
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber > numb1)
        {
            numb1 = patient[i].patientNumber;
        }
    }
    int index = (numb1 + 1);
    return index;
}

// Find the patient array index by patient number (returns -1 if not found)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int findPatientIndexByPatientNum(int patientNumber,
    const struct Patient patient[], int max)
{
    int i;
    int a = -1;
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber == patientNumber)
        {
            a = i;
        }
    }
    return a;
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPatient(struct Patient* patient)
{
    printf("Patient Data Input\n"
        "------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    inputCString(patient->name, 1, NAME_LEN + 1);
    putchar('\n');
    inputPhoneData(&patient->phone);
}

// Get user input for phone contact information
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPhoneData(struct Phone* phone)
{
    int select;
    printf("Phone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n"
        "2. Home\n"
        "3. Work\n"
        "4. TBD\n");
    printf("Selection: ");
    select = inputIntRange(1, 4);
    putchar('\n');
    if (select == 1)
    {
        char choice[5] = "CELL";
        strcpy(phone->description, choice);
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        scanf("%s", phone->number);
        printf("\n");
        clearInputBuffer();
    }
    else if (select == 2)
    {
        char choice2[5] = "HOME";
        strcpy(phone->description, choice2);
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        scanf("%s", phone->number);
        printf("\n");
        clearInputBuffer();
    }
    else if (select == 3)
    {
        char choice3[5] = "WORK";
        strcpy(phone->description, choice3);
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        scanf("%s", phone->number);
        printf("\n");
        clearInputBuffer();
    }
    else if (select == 4)
    {
        char num1[PHONE_LEN] = "\0";
        strcpy(num1, phone->number);
        char choice4[5] = "TBD";
        strcpy(phone->description, choice4);
    }
}