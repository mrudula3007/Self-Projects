#include <stdio.h>
#include <string.h>

// Structure definitions
struct Date {
    int dd;
    int mm;
    int yy;
};

struct Note {
    int dd;
    int mm;
    char note[50];
};

// Function prototypes
void findDay();
void printAllDays();
void addNote();
int getDayNumber(int day, int month, int year);
char *getDayName(int day);
int getNumberOfDays(int month, int year);
void printMonth(int month, int year);

int main() {
    int choice;
    
    while(1) {
        printf("1. Find Out the Day\n");
        printf("2. Print all the days of a month\n");
        printf("3. Add a Note\n");
        printf("4. EXIT\n");
        printf("ENTER YOUR CHOICE : ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                findDay();
                break;
            case 2:
                printAllDays();
                break;
            case 3:
                addNote();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    
    return 0;
}

// Function to find out the day of the entered date
void findDay() {
    struct Date date;
    printf("Enter date (DD MM YYYY): ");
    scanf("%d %d %d", &date.dd, &date.mm, &date.yy);
    int dayNumber = getDayNumber(date.dd, date.mm, date.yy);
    printf("Day is: %s\n", getDayName(dayNumber));
    printf("\nPress any key to continue...");
    getchar(); // Clear input buffer
    getchar(); // Wait for key press
}

// Function to print all the days of a specified month
void printAllDays() {
    struct Date date;
    printf("Enter month and year (MM YYYY): ");
    scanf("%d %d", &date.mm, &date.yy);
    printMonth(date.mm, date.yy);
}

// Function to add a note for a specific date
void addNote() {
    struct Note note;
    FILE *fp;
    fp = fopen("note.txt", "a");
    if(fp == NULL) {
        printf("Error in Opening the file\n");
        return;
    }
    
    printf("Enter the date (DD MM): ");
    scanf("%d %d", &note.dd, &note.mm);
    printf("Enter the Note (50 characters max): ");
    scanf(" %[^\n]", note.note);
    
    fprintf(fp, "%02d/%02d: %s\n", note.dd, note.mm, note.note);
    
    fclose(fp);
    
    printf("\nNote added successfully!\n");
}

// Function to get the day number (0 = Sunday, 1 = Monday, ..., 6 = Saturday)
int getDayNumber(int day, int month, int year) {
    int monthTable[] = {0,3,2,5,0,3,5,1,4,6,2,4};
    year -= month < 3;
    return (year + year/4 - year/100 + year/400 + monthTable[month-1] + day) % 7;
}

// Function to get the day name (e.g., "Sunday", "Monday", etc.)
char *getDayName(int day) {
    char *dayNames[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    return dayNames[day];
}

// Function to get the number of days in a month
int getNumberOfDays(int month, int year) {
    switch(month) {
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            if((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
                return 29;
            else
                return 28;
        default:
            return 31;
    }
}

// Function to print all the days of a month
void printMonth(int month, int year) {
    printf("\n---------------------------\n");
    printf("      %d - %02d\n", year, month);
    printf("---------------------------\n");
    printf("Sun Mon Tue Wed Thu Fri Sat\n");
    
    int dayNumber = getDayNumber(1, month, year);
    int numberOfDays = getNumberOfDays(month, year);
    int i;
    
    for(i = 0; i < dayNumber; i++) {
        printf("    ");
    }
    
    for(i = 1; i <= numberOfDays; i++) {
        printf("%3d ", i);
        if((i + dayNumber) % 7 == 0 || i == numberOfDays) {
            printf("\n");
        }
    }
}
