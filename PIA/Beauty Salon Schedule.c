#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define _MAX_EVENTS 9 // 10:00am to 7:00pm
#define _MAX_DESCRIPTION 101 // 100 Character Description Max

typedef struct {

    int hour; 
    int minute; 
    char description[_MAX_DESCRIPTION];

} event;

 
// Print the menu selection
void printMenu() {

 puts("*******  Kigri´s Beauty Salon  *******\n"
                       "\n"
        "+-------------------------+\n"
        "|  1. Make an appointment |\n"
        "|  2. Delete appointment  |\n"
        "|  3. Prices              |\n"
        "|  4. Display Schedule    |\n"
        "|  5. Save Schedule       |\n"
        "|  6. Exit                |\n"
        "+-------------------------+\n");

}

bool isNull(const event *e) { return e == NULL; }

event *initEvent() {
    event *e = (event*)malloc(sizeof(event));

    e->hour = 0;
    e->minute = 0;
    strcpy(e->description, "");

    return e;
}

int inputRange(const int min, const int max) {

    int input = 0;
    char temp[21];
    char *prompt = "| Enter a number between %d and %d: ";

    printf(prompt, min, max);

    fgets(temp, 21, stdin);
    input = atoi(temp);

    while (input > max || input < min) { // Data validation
        printf(prompt, min, max);
        fgets(temp, 21, stdin);
        input = atoi(temp);
    }

    return input;

}

event* newEvent(event *e) {

    if (isNull(e)) { // If e is NULL
        e = initEvent();
    }

    char *seperator = "+--------------------------------+";

    printf("\n%s\n|           NEW APPOINTMENT            |\n%s\n\n", seperator, seperator);
    
        puts("+---------- CUSTOMER NAME ----------+");
        printf("%s", "| Enter a name: ");
        fgets(e->description, _MAX_DESCRIPTION, stdin);
           puts("+-------------------------+\n");

    puts("| Name successfully added.\n");

    puts("+---------- APPOINTMENT TIME ----------+");

    e->hour = inputRange(0, 23);
    e->minute = inputRange(0, 59);

    puts(seperator);

    puts("\n+--- SERVICE ---+");

    printf("%s", "| Enter a required service: ");

    fgets(e->description, _MAX_DESCRIPTION, stdin);

    puts("+-------------------------+\n");

    puts("| Appointment successfully added.\n");

    return e;

}

void addEventAtIndex(event list[], const event e, const int i) {

    if (isNull(&e)) { // if our event is NULL, return
        return;
    }

    list[i].hour = e.hour;
    list[i].minute = e.minute;
    strcpy(list[i].description, e.description);

}

void sort(event list[], const int size) {

    for (int i = 1; i < size; i++) {
        for (int j = i; j > 0 && (list[j - 1].hour > list[j].hour || (list[j - 1].hour == list[j].hour && list[j - 1].minute > list[j].minute)); j--) {
            int hourJ = list[j].hour;
            int minuteJ = list[j].minute;
            char descriptionJ[_MAX_DESCRIPTION];
            strcpy(descriptionJ, list[j].description);

            int hourJMinus1 = list[j - 1].hour;
            int minuteJMinus1 = list[j - 1].minute;
            char descriptionJMinus1[_MAX_DESCRIPTION];
            strcpy(descriptionJMinus1, list[j - 1].description);

            list[j].hour = hourJMinus1;
            list[j].minute = minuteJMinus1;
            strcpy(list[j].description, descriptionJMinus1);

            list[j - 1].hour = hourJ;
            list[j - 1].minute = minuteJ;
            strcpy(list[j - 1].description, descriptionJ);
        }
    }

}

// Add an appointment to an appointment list by sorting it into position
void sortInsert(event list[], int *size, event e) {

    addEventAtIndex(list, e, *size); // Add event to the end of the list

    (*size)++; // Increment size

    // Insertion Sort
    sort(list, *size);

}

void printEvent(const event e) {

    char h1 = { (e.hour / 10) + '0' }; // Extract the first digit and convert to char (if any, else 0)
    char h2 = { (e.hour - (e.hour / 10) * 10) + '0' }; // Extract the second digit and convert to char

    char m1 = { (e.minute / 10) + '0' };
    char m2 = { (e.minute - (e.minute / 10) * 10) + '0' };

    printf("%c%c:%c%c - %s", h1, h2, m1, m2, e.description);

}

void printEventList(const event list[], const int size) {

    if (size == 0) {
        puts("\n| You have no appointments scheduled!\n");
        return;
    }

    char *seperator = "+--------------------------------+";

    printf("\n%s\n|          MY SCHEDULE           |\n%s\n\n", seperator, seperator);

    for (int i = 0; i < size; i++) {
        printf("| [%d] ", i);
        printEvent(list[i]);

    }

    putchar('\n');

}

// Delete an event from an event list
void deleteEvent(event list[], int *size) {

    if (*size == 0) { // If list is empty
        puts("\n| Appointment list already empty.\n");
        return;
    }

    char temp[21];
    int id;

    char *seperator = "\n+--------------------------------+";
    printf("%s\n|          DELETE APPOINTMENT          |%s\n\n", seperator, seperator);

    for (int i = 0; i < *size; i++) {
        printf("| [%d] ", i);
        printEvent(list[i]);
    }

    printf("%s", "\n| Enter the ID of an appointment to delete: ");

    fgets(temp, 21, stdin);
    id = atoi(temp);

    if (id > *size - 1) {
        printf("\n| No event located at %d\n", id);
        return;
    }

    printf("| Appointment [%d] deleted successfully.\n\n", id);

    list[id].hour = 99;
    list[id].minute = 99;
    strcpy(list[id].description, "");

    if (id != (*size - 1)) { 
        sort(list, *size);
    }

    (*size)--;

}


char *encode(char *s) {

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == ' ') {
            s[i] = '_';
        }
    }

    return s;

}

// Replace all underscores in a string with an spaces
char *decode(char *s) {

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '_') {
            s[i] = ' ';
        }
    }

    return s;

}

void saveEventList(char *filename, event list[], int size) {

    FILE *f = fopen(filename, "w");

    if (f == NULL) { // If our file is NULL, return
        return;
    }

    for (int i = 0; i < size; i++) {
        fprintf(f, "%d %d %s", list[i].hour, list[i].minute, encode(list[i].description));
    }

    printf("\n| %d %s successfully saved into \"%s\".\n\n", size, (size == 1) ? "appointment" : "appointment", filename);

    fclose(f);

}


void loadEventList(char *filename, event list[], int *size) {

    FILE *f = fopen(filename, "r");
    char temp[6 + _MAX_DESCRIPTION];

    if (f == NULL) {
        printf("\n| File \"%s\" not found.\n\n", filename);
        return;
    }

    *size = 0; // Set size to 0

    while (fgets(temp, sizeof(temp), f)) {

        char *word = strtok(temp, " "); // Use space as the token delimiter, get the first token (hour)
        list[*size].hour = atoi(word); // Store the token into the list

        word = strtok(NULL, " "); // Get the second token (minute)
        list[*size].minute = atoi(word);

        word = strtok(NULL, " "); // Get the third token (description)
        strcpy(list[*size].description, decode(word)); // Decode our word before copying it (remove underscores)

        (*size)++; 

    }

    printf("\n| %d %s successfully loaded from \"%s\".\n", *size, (*size == 1) ? "event" : "events", filename);

    printEventList(list, *size); // Display the event list when finished, show the user what's been loaded

}

int main() {

    event list[_MAX_EVENTS];
    int index = 0; // Number of elements in list
    int selection = 0;
    char file[FILENAME_MAX];
    char response = 'Y';
    char temp[21];

    while (selection != 6) {

        printMenu(); // Print the menu

        printf("%s", "| Please select an option: "); // Prompt for input
        fgets(temp, 21, stdin);
        selection = atoi(temp); // Convert string input to int

        switch (selection) {

        case 1: // New Appointment
            if (index + 1 > _MAX_EVENTS) {
                printf("| You can only have %d appointments at one time!\n\n", index);
                break;
            }
            sortInsert(list, &index, *newEvent(&list[index]));
            break;
        case 2: // Delete Event
            deleteEvent(list, &index);
            break;
        case 4: // Display Schedule
            printEventList(list, index);
            break;
        case 3: // Prices
            puts("\n| Makeup       90 US$\n");
            puts("\n| Hairstyle    70 US$\n");
            puts("\n| Haircut      40 US$\n");
            break;
        case 5: // Save Schedule
            if (index == 0) { // No events, don't save anything
                puts("| You dont't have events in your schedule!\n");
            }
            break;
        case 6: // Exit Program
            puts("\n| Thank you for choosing our services!\n");
            break;
        default: // Error
            puts("\n| Error in selection\n");
            break;

        }

    }

}