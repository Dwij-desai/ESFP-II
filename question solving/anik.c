#include <stdio.h>
#include <string.h>
#include <conio.h>

#define num 100
#define activity 5

// Structure to represent a daily routine
struct DailyRoutine {
    char activities[activity][50];
};

// Structure to represent a student
struct Student {
    int rollNumber;
    char name[50];
    int age;
    struct DailyRoutine routine;
};

// Function to add a new student
void addStudent(struct Student students[], int *count)
 {  FILE *file;
    file=fopen("record.txt", "a");
    printf("Enter Roll Number: ");
    scanf("%d", &students[*count].rollNumber);
    
    printf("Enter Name: ");
    scanf(" %s\n", students[*count].name);  
    
    printf("Enter Age: ");
    scanf("%d", &students[*count].age);

    // Initialize daily routine
    printf("Enter Daily Routine Activities (up to %d activities):\n", activity);
    for (int i = 0; i < activity; i++) {
        printf("Activity %d: ", i + 1);
        scanf("%s[^\n]", students[*count].routine.activities[i]);

    }

    (*count)++;
    printf("Student added successfully.\n");
    fprintf(file,"%d\n",students[*count].rollNumber);
    fprintf(file,"%s\n",students[*count].name);
    fprintf(file,"%d\n",students[*count].age);
    fprintf(file,"%s\n",students[*count].routine.activities);
    fclose(file);
}

// Function to display all students
void displayStudents(struct Student students[], int count) {
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\nRoll Number\tName\t\tAge\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t\t%s\t\t%d\n", students[i].rollNumber, students[i].name, students[i].age);
    }
}
void passhidder(char *pass)
{
    char password[15];
    int i = 0;
start:
    printf("\r                        \r");
    for (i = 0; i < 16; i++)
    {
        password[i] = getch();
        if (password[i] == '\b')
        {
            goto start;
            break;
        }
        printf("\r");
        if (password[i] == ' ' || password[i] == '\r' || i == 15)
        {
            password[i] = '\0';

            break;
        }
        for (int p = 0; p < i + 1; p++)
        {
            printf("*");
        }
    }
    strcpy(pass, password);
}
// Function to search for a student by roll number and display daily routine
void searchStudent(struct Student students[], int count) {
    if (count == 0) {
        printf("No students to search.\n");
        return;
    }

    int rollToSearch;
    printf("Enter Roll Number to Search: ");
    scanf("%d", &rollToSearch);

    for (int i = 0; i < count; i++) {
        if (students[i].rollNumber == rollToSearch) {
            printf("\nRoll Number\tName\t\tAge\n");
            printf("%d\t\t%s\t\t%d\n", students[i].rollNumber, students[i].name, students[i].age);

            printf("\nDaily Routine:\n");
            for (int j = 0; j < activity; j++) {
                printf("Activity %d: %s\n", j + 1, students[i].routine.activities[j]);
            }
            return;
        }
    }

    printf("Student with Roll Number %d not found.\n", rollToSearch);
}

void main() {
    struct Student students[num];
    int count = 0;
    int choice;
    char username[20];
    char password[20];

     // Prompt user for input
    printf("Enter username: ");
    scanf("%s ", username);

    printf("Enter password: \n");
    passhidder(password);

    // Check if the entered username and password are correct
    if (strcmp(username, "staff") == 0 && strcmp(password, "staff123") == 0) 
    {
        
    

    do {
        printf("\nStudent Life Cycle Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                searchStudent(students, count);
                break;
            case 4:
                printf("Logging off!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } 
    while (choice != 4);
    } 
    else 
    {
        printf("Login failed. Incorrect username or password.\n");
    }

}