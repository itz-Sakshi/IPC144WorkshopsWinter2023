/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
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


// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"
#include "string.h"
#include <stdlib.h>
#include <ctype.h>


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

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
            "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
            "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
    const struct Appointment* appoint,
    int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
            appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
        patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
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
            menuAppointment(data);
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


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
            "==============================\n"
            "1) VIEW   ALL Appointments\n"
            "2) VIEW   Appointments by DATE\n"
            "3) ADD    Appointment\n"
            "4) REMOVE Appointment\n"
            "------------------------------\n"
            "0) Previous menu\n"
            "------------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------


// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
void addPatient(struct Patient patient[], int max)
{
    int i;
    int a = -1;
    int flag = 1;
    for (i = 0; i < max && flag; i++)
    {
        if (patient[i].patientNumber == 0)
        {
            a = i;
            flag = 0;
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
// (Copy your code from MS#2)
void editPatient(struct Patient patient[], int max)
{
    int num4;
    printf("Enter the patient number: ");
    num4 = inputIntPositive();
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
// (Copy your code from MS#2)
void removePatient(struct Patient patient[], int max)
{
    int num;
    char c[3] = "yn";
    char a[3] = "\0";
    printf("Enter the patient number: ");
    num = inputIntPositive();
    int b = findPatientIndexByPatientNum(num, patient, max);
    if (b == -1)
    {
        printf("\nERROR: Patient record not found!\n\n");
    }
    else
    {

        printf("\n");
        displayPatientData(&patient[b], FMT_FORM);
        printf("\nAre you sure you want to remove this patient record? (y/n): ");
        a[0] = inputCharOption(c);
        char s[NAME_LEN + 1] = "\0";
        char str[PHONE_DESC_LEN + 1] = "\0";
        char str1[PHONE_LEN + 1] = "\0";
        if (a[0] == 'y')
        {
            patient[b].patientNumber = 0;
            strcpy(patient[b].name, s);
            strcpy(patient[b].phone.number, str);
            strcpy(patient[b].phone.description, str1);
            printf("Patient record has been removed!\n\n");
        }
        else
        {
            printf("Operation aborted.\n\n");
        }
    }
}


// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

void viewAllAppointments(struct ClinicData* data)
{
    int i, j = 0;
    int index = 0;
    struct Appointment a_temp = { 0 };
    displayScheduleTableHeader(&data->appointments->date, 1);
    for (i = 0; i < data->maxAppointments; i++)
    {
        for (j = i; j < data->maxAppointments; j++)
        {
            if (data->appointments[i].date.year > data->appointments[j].date.year)
            {
                a_temp = data->appointments[i];
                data->appointments[i] = data->appointments[j];
                data->appointments[j] = a_temp;
            }
            if (data->appointments[i].date.year == data->appointments[j].date.year && data->appointments[i].date.month > data->appointments[j].date.month)
            {
                a_temp = data->appointments[i];
                data->appointments[i] = data->appointments[j];
                data->appointments[j] = a_temp;
            }
            if (data->appointments[i].date.year == data->appointments[j].date.year && data->appointments[i].date.month == data->appointments[j].date.month && data->appointments[i].date.day > data->appointments[j].date.day)
            {
                a_temp = data->appointments[i];
                data->appointments[i] = data->appointments[j];
                data->appointments[j] = a_temp;
            }
            if (data->appointments[i].date.year == data->appointments[j].date.year && data->appointments[i].date.month == data->appointments[j].date.month && data->appointments[i].date.day == data->appointments[j].date.day && data->appointments[i].time.hour > data->appointments[j].time.hour)
            {
                a_temp = data->appointments[i];
                data->appointments[i] = data->appointments[j];
                data->appointments[j] = a_temp;
            }
            if (data->appointments[i].date.year == data->appointments[j].date.year && data->appointments[i].date.month == data->appointments[j].date.month && data->appointments[i].date.day == data->appointments[j].date.day && data->appointments[i].time.hour == data->appointments[j].time.hour && data->appointments[i].time.min > data->appointments[j].time.min)
            {
                a_temp = data->appointments[i];
                data->appointments[i] = data->appointments[j];
                data->appointments[j] = a_temp;
            }
        }
    }
    for (i = 0; i < data->maxAppointments; i++)
    {
        if (data->appointments[i].patientNumber != 0)
        {
            index = findPatientIndexByPatientNum(data->appointments[i].patientNumber, data->patients, data->maxPatient);

            displayScheduleData(&data->patients[index], &data->appointments[i], 1);
        }
    }
    printf("\n");
}


// View appointment schedule for the user input date
void viewAppointmentSchedule(struct ClinicData* data)
{
    int i = 0, j = 0, leapYr = 0, match = 0;
    struct Date date = { 0 };
    printf("Year        : ");
    date.year = inputInt();
    leapYr = ((date.year % 4 == 0) && (date.year % 100 != 0)) || (date.year % 400 == 0);
    printf("Month (1-12): ");
    date.month = inputIntRange(1, 12);
    if (date.month == 2)
    {
        if (leapYr == 1)
        {
            printf("Day (1-29)  : ");
            date.day = inputIntRange(1, 29);
        }
        else
        {
            printf("Day (1-28)  : ");
            date.day = inputIntRange(1, 28);
        }
    }
    else if (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11)
    {
        printf("Day (1-30)  : ");
        date.day = inputIntRange(1, 30);
    }
    else
    {
        printf("Day (1-31)  : ");
        date.day = inputIntRange(1, 31);
    }
    printf("\n");
    displayScheduleTableHeader(&date, 0);
    for (i = 0; i < data->maxAppointments; i++)
    {
        if ((data->appointments[i].date.year == date.year) && (data->appointments[i].date.month == date.month) && (data->appointments[i].date.day == date.day))
        {
            for (j = 0; j < data->maxPatient; j++)
            {
                if (data->appointments[i].patientNumber == data->patients[j].patientNumber) {

                    displayScheduleData(&data->patients[j], &data->appointments[i], 0);
                    match++;
                }
            }
        }
    }
    if (match == 0)
    {
        printf("No records found!\n");
    }
    printf("\n");
}


// Add an appointment record to the appointment array
void addAppointment(struct Appointment appointments[], int maxAppointments, struct Patient patient[], int maxPatient)
{
    int s, i, j = 0;
    int aHour = 0;
    int ptNum = 0;
    int aMinute = 0;
    int aDay = 0;
    int aMonth = 0;
    int aYear = 0;
    int checkAvailableNumber = 0, checkRoom = 0;
    int checkAvailableTime;
    for (i = 0; i < maxAppointments; i++)
    {
        if (appointments[i].patientNumber == 0)
        {
            checkRoom = i;
        }
    }
    for (s = 0; s < maxAppointments; s++)
    {
        {
            if (appointments[s].date.year == 0)
            {
                checkAvailableNumber++;
            }
        }
    }
    if (checkAvailableNumber != 0)
    {
        printf("Patient Number: ");
        ptNum = inputIntPositive();
        do {
            checkAvailableTime = 0;
            printf("Year        : ");
            aYear = 0;
            aYear = inputIntRange(2000, 3000);
            printf("Month (1-12): ");
            aMonth = inputIntRange(1, 12);
            if (aYear % 4 == 0 && aMonth == 2)
            {
                printf("Day (1-29)  :");
                aDay = inputIntRange(1, 29);
            }
            else if (aYear % 4 != 0 && aMonth == 2)
            {
                printf("Day (1-28)  : ");
                aDay = inputIntRange(1, 28);
            }
            else if (aMonth % 2 != 0 || aMonth == 8)
            {
                printf("Day (1-31)  : ");
                aDay = inputIntRange(1, 31);
            }
            else
            {
                printf("Day (1-30)  : ");
                aDay = inputIntRange(1, 30);
            }
            printf("Hour (0-23)  : ");
            aHour = inputIntRange(0, 23);
            printf("Minute (0-59): ");
            aMinute = inputIntRange(0, 59);
            for (s = 0; s < maxAppointments; s++)
            {
                if (appointments[s].date.day == aDay && appointments[s].date.month == aMonth && appointments[s].date.year == aYear
                    && appointments[s].time.hour == aHour && appointments[s].time.min == aMinute)
                {
                    printf("\nERROR: Appointment timeslot is not available!\n\n");
                    checkAvailableTime++;
                }
            }
        } while (checkAvailableTime != 0);
        if (aHour < START_HOUR || aHour > END_HOUR || aMinute % MINUTE_INTERVAL != 0 || (aHour >= END_HOUR && aMinute > 0))
        {
            do
            {
                printf("ERROR: Time must be between %d:00 and %d:00 in %d minute intervals.\n\n", START_HOUR, END_HOUR, MINUTE_INTERVAL);
                printf("Hour (0-23)  : ");
                aHour = inputIntRange(0, 23);
                printf("Minute (0-59): ");
                aMinute = inputIntRange(0, 59);
            } while (aHour < START_HOUR || aHour > END_HOUR || aMinute % MINUTE_INTERVAL != 0 || (aHour >= END_HOUR && aMinute > 0));
        }
        j = checkRoom;
        appointments[j].patientNumber = ptNum;
        appointments[j].date.day = aDay;
        appointments[j].date.month = aMonth;
        appointments[j].date.year = aYear;
        appointments[j].time.hour = aHour;
        appointments[j].time.min = aMinute;
        printf("\n*** Appointment scheduled! ***\n\n");
    }
    else
    {
        printf("\nERROR: No Appointment schedule is vacant!\n\n");
    }
}


// Remove an appointment record from the appointment array
void removeAppointment(struct Appointment appointments[], int maxAppointments, struct Patient patient[], int maxPatient)
{
    int ptNum = 0;
    printf("Patient Number: ");
    ptNum = inputIntPositive();
    int found = 0;
    int s, j;
    int x = 0;
    int searchDay = 0;
    int searchMonth = 0;
    int searchYear = 0;
    found = findPatientIndexByPatientNum(ptNum, patient, maxPatient);
    for (s = 0; s < maxAppointments; s++)
    {
        {
            if (appointments[s].patientNumber == ptNum)
            {
                x++;
            }
        }
    }
    if (found != -1 && x != 0)
    {
        printf("Year        : ");
        searchYear = 0;
        searchYear = inputIntRange(2000, 3000);
        printf("Month (1-12): ");
        searchMonth = inputIntRange(1, 12);
        if (searchYear % 4 == 0 && searchMonth == 2)
        {
            printf("Day (1-29)  : ");
            searchDay = inputIntRange(1, 29);
        }
        else if (searchYear % 4 != 0 && searchMonth == 2)
        {
            printf("Day (1-28)  : ");
            searchDay = inputIntRange(1, 28);
        }
        else if (searchMonth % 2 != 0 || searchMonth == 8)
        {
            printf("Day (1-31)  : ");
            searchDay = inputIntRange(1, 31);
        }
        else
        {
            printf("Day (1-30)  : ");
            searchDay = inputIntRange(1, 30);
        }
        char c[3] = "yn";
        char a[3] = "\0";
        for (j = 0; j < maxAppointments; j++)
        {
            int var2 = findPatientIndexByPatientNum(appointments[j].patientNumber, patient, maxPatient);
            if (appointments[j].patientNumber == ptNum && appointments[j].date.day == searchDay &&
                appointments[j].date.month == searchMonth && appointments[j].date.year == searchYear)
            {
                printf("\n");
                displayPatientData(&patient[var2], FMT_FORM);
                printf("Are you sure you want to remove this appointment (y,n): ");
                a[0] = inputCharOption(c);
                if (a[0] == 'y')
                {
                    appointments[j].date.day = 0;
                    appointments[j].date.month = 0;
                    appointments[j].date.year = 0;
                    appointments[j].time.hour = 0;
                    appointments[j].time.min = 0;
                    appointments[j].patientNumber = 0;
                    printf("\nAppointment record has been removed!\n\n");
                }
                else
                {
                    printf("Operation Aborted!\n\n");
                }
            }
        }
    }
    else
    {
        printf("ERROR: Patient record not found!\n\n");
    }
}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (Copy your code from MS#2)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    int x;
    int numb;
    printf("Search by patient number: ");
    numb = inputIntPositive();
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
// (Copy your code from MS#2)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    int i;
    int y = 0;
    char phn[11] = "\0";
    printf("Search by phone number: ");
    scanf("%s", phn);
    printf("\n");
    displayPatientTableHeader();
    for (i = 0; i < max; i++)
    {
        if (strcmp(phn, patient[i].phone.number) == 0)
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
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
void inputPatient(struct Patient* patient)
{
    printf("Patient Data Input\n"
        "------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    inputCString(patient->name, 1, NAME_LEN);
    putchar('\n');
    inputPhoneData(&patient->phone);
}

// Get user input for phone contact information
// (Copy your code from MS#2)
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
        inputPhone(phone->number, PHONE_LEN);
        printf("\n");
    }
    else if (select == 2)
    {
        char choice2[5] = "HOME";
        strcpy(phone->description, choice2);
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        inputPhone(phone->number, PHONE_LEN);
        printf("\n");
    }
    else if (select == 3)
    {
        char choice3[5] = "WORK";
        strcpy(phone->description, choice3);
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        inputPhone(phone->number, PHONE_LEN);
        printf("\n");
    }
    else if (select == 4)
    {
        char num1[PHONE_LEN] = "\0";
        strcpy(num1, phone->number);
        char choice4[5] = "TBD";
        strcpy(phone->description, choice4);
    }
}




//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
int importPatients(const char* datafile, struct Patient patients[], int max)
{
    FILE* patientFile = fopen(datafile, "r");
    int i;
    for (i = 0; i < max && patientFile != NULL && fscanf(patientFile, "%d|%[^|]|%[^|]|%[^\n]", &patients[i].patientNumber,
        patients[i].name,
        patients[i].phone.description,
        patients[i].phone.number) != EOF; i++)
    {
    }
    if (patientFile != NULL)
    {
        fclose(patientFile);
    }
    return i;
}

// Import appointment data from file into an Appointment array (returns # of records read)
int importAppointments(const char* datafile, struct Appointment appoints[], int max)
{
    FILE* appointmentFile = fopen(datafile, "r");
    int i;
    for (i = 0; i < max && appointmentFile != NULL && fscanf(appointmentFile, "%d,%d,%d,%d,%d,%d", &appoints[i].patientNumber, &appoints[i].date.year, &appoints[i].date.month, &appoints[i].date.day, &appoints[i].time.hour, &appoints[i].time.min) != EOF; i++)
    {
    }
    if (appointmentFile != NULL)
    {
        fclose(appointmentFile);
    }
    return i;
}