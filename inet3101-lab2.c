/*
Khalid Mohamed
Hassan Elmi
Parts Inventory Manager
Inet 3101 Lab 2
Joe Axberg
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Setting some max length constraints to aid in memory management
#define MAX_PARTNAME_LEN 50
#define MAX_PARTSIZEMET_LEN 20

// Declaring a structure to hold part information
typedef struct {
    int partNumber;                  // Part number as an integer
    char partName[MAX_PARTNAME_LEN]; // Part name with a max length
    float partSize;                  // Part size as a float
    char partSizeMetric[MAX_PARTSIZEMET_LEN]; // Part size metric with a max length
    float partCost;                  // Part cost as a float
} Part;

// Function to print all records in the database
void printRecords(Part *parts, int count) {
    printf("\n\nPrint out list of parts in database: \n\n");
    for (int i = 0; i < count; i++) {
        // Print each part's details
        printf("Part Number: %d\n", parts[i].partNumber);
        printf("Part Name: %s\n", parts[i].partName);
        printf("Part Size: %.2f\n", parts[i].partSize);
        printf("Part Metric: %s\n", parts[i].partSizeMetric);
        printf("Part Cost: %.2f\n", parts[i].partCost);
        printf("\n\n");
    }
}

// Function to add a new record to the database
void addRecord(Part **parts, int *count) {
    // Reallocating memory for the new record
    *parts = realloc(*parts, (*count + 1) * sizeof(Part));

    // Declaring variables to store the user input
    int partNum;
    char partName[MAX_PARTNAME_LEN];
    float partSize;
    char partSizeMetric[MAX_PARTSIZEMET_LEN];
    float partCost;

    // Getting user input for the new record
    printf("Please Enter the Part Number: ");
    scanf("%d", &partNum);

    printf("Please Enter the Part Name: ");
    scanf("%s", partName);

    printf("Please Enter the Part Size: ");
    scanf("%f", &partSize);

    printf("Please Enter Part Size Metric (pounds, kilograms, feet, etc.): ");
    scanf("%s", partSizeMetric);

    printf("Please Enter the Part Cost: ");
    scanf("%f", &partCost);

    // Using pointers to assign user input to the dynamically allocated memory
    (*parts)[*count].partNumber = partNum;
    strcpy((*parts)[*count].partName, partName);
    (*parts)[*count].partSize = partSize;
    strcpy((*parts)[*count].partSizeMetric, partSizeMetric);
    (*parts)[*count].partCost = partCost;

    // Incrementing the total count of records for any new additions
    (*count)++;
    // Printing the details of the new record
    printf("You entered:\n");
    printf("\tPart number = %d\n", partNum);
    printf("\tPart name = \"%s\"\n", partName);
    printf("\tPart size = %.2f\n", partSize);
    printf("\tPart size metric = \"%s\"\n", partSizeMetric);
    printf("\tPart cost = $%.2f\n", partCost);
}

// Function to delete the last inputted record
void deleteRecord(Part **parts, int *count, int *changes) {
    if (*count > 0) {
        // Allocating new memory for the records- (count -1)
        Part *newParts = malloc((*count - 1) * sizeof(Part));

        // Copy existing records to the new memory allocation, excluding the last record
        for (int i = 0; i < *count - 1; i++) {
            newParts[i] = (*parts)[i];
        }

        // Freeing up the formerly used memory and updating the pointer to the new memory allocation
        free(*parts);
        *parts = newParts;
        (*count)--;

        // Incrementing the number of changes
        (*changes)++;

        printf("Last record deleted.\n");
    } else {
        printf("No records to delete.\n");
    }
}

// Function to print the current total number of records
void printNumRecords(int count) {
    printf("\n\nNumber of parts records is: %d\n", count);
}

// Function to print the current size of the database in memory
void printDatabaseSize(int count) {
    // Calculating the memory size based on the number of records and the size of each record
    printf("\n\nCurrent database size in memory: %zu bytes\n", count * sizeof(Part));
}

// Function to print the total number of changes to the database (both additions and deletions since even deletions are counted)
void printNumChanges(int *changes, int increment) {
    if (increment) {
        // Increment the changes count if a modification has been made
        (*changes)++;
    } else {
        // Print the total number of changes made to the database
        printf("\n\nYou have modified the database %d times\n", *changes);
    }
}

// Main function to control the parts manager
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <database_name>\n", argv[0]);
        return 1;
    }

    // Storing the database name from the command line argument
    const char *databaseName = argv[1];
    printf("Database Name: %s\n", databaseName);

    Part *parts = NULL; // Pointer to the parts database
    int count = 0;      
    int changes = 0;    
    int selection;      

    // Allocating initial memory for the parts database
    parts = malloc(sizeof(Part));

    // Sample value to populate the database
    parts[count].partNumber = 101;
    strcpy(parts[count].partName, "windshield wiper");
    parts[count].partSize = 1.5;
    strcpy(parts[count].partSizeMetric, "meters");
    parts[count].partCost = 250.75;
    count++;
    changes++;

    int looper = 6; // Control value for while loop

    // Main menu loop
    while (looper <= 6) {
        // Print the menu options
        printf("\n\nParts Inventory Manager\n\n");
        printf("1. Print all records\n");
        printf("2. Add record\n");
        printf("3. Delete the last record\n");
        printf("4. Print number of records\n");
        printf("5. Print database size\n");
        printf("6. Print number of changes\n");
        printf("7. Exit\n\n");
        printf("Please enter your selection: ");
        scanf("%d", &selection);

        // Handle user selection and call the appropriate function
        switch (selection) {
            case 1:
                printRecords(parts, count);
                break;
            case 2:
                addRecord(&parts, &count);
                printNumChanges(&changes, 1);
                break;
            case 3:
                deleteRecord(&parts, &count, &changes);
                break;
            case 4:
                printNumRecords(count);
                break;
            case 5:
                printDatabaseSize(count);
                break;
            case 6:
                printNumChanges(&changes, 0);
                break;
            case 7:
                printf("\n\nThank you for using the Parts Inventory Manager\n");
                looper = selection;
                break;
            default:
                printf("Invalid selection. Please enter a number between 1 and 7.\n");
        }
    }

    // Free allocated memory for the parts database
    free(parts);
    return 0;
}
