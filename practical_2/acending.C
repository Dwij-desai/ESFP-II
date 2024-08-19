#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[50];
    char clas[20];
    char semester[10];
    char subject[50];
    int exam_fee;
};

void displayRecords(struct Student *students, int num_records);
void updateRecord(struct Student *students, int num_records);
void deleteRecord(struct Student *students, int *num_records);
int searchRecord(struct Student *students, int num_records, int choice, int key, char *search_name);

int main() 
{
    int num_records;

    printf("Enter how many records you want to store: ");
    scanf("%d", &num_records);

    struct Student *students = (struct Student *)malloc(num_records * sizeof(struct Student));

    if (students == NULL) {
        printf("Memory Allocation Failed!!\n");
        return 1;
    }

    for (int i = 0; i < num_records; i++) {
        printf("Enter rno, name, std, sem, subject, and fee: ");
        scanf("%d %s %s %s %s %d", &students[i].rollno, students[i].name, students[i].clas, students[i].semester, students[i].subject, &students[i].exam_fee);
    }

    printf("========== Output of student information============\n");
    displayRecords(students, num_records);

    char choice;

    printf("Do you want to modify/update records (Y/N)? ");
    scanf(" %c", &choice);

    if (choice == 'Y' || choice == 'y') 
    {

        int updateChoice;
        
        printf("How do you want to modify records - by id or by name?\n");
        printf("Press <1> for by id and press <2> for by name: ");
        scanf("%d", &updateChoice);

        updateRecord(students, num_records);

        printf("========== Output after modification============\n");
        displayRecords(students, num_records);
    }

    printf("Do you want to delete records (Y/N)? ");
    scanf(" %c", &choice);

    if (choice == 'Y' || choice == 'y') {
        int deleteChoice;
        printf("How do you want to delete records - by id or by name?\n");
        printf("Press <1> for by id and press <2> for by name: ");
        scanf("%d", &deleteChoice);

        deleteRecord(students, &num_records);

        printf("========== Output after deletion============\n");
        displayRecords(students, num_records);
    }

    char search_name[50];
    printf("Find the student record by name:\n");
    printf("Enter student name: ");
    scanf("%s", search_name);
    int result = searchRecord(students, num_records, 2, -1, search_name); 

    if (result == -1) {
        printf("Student not found.\n");
    }

    free(students);

    return 0;
}

void displayRecords(struct Student *students, int num_records) 
{
    for (int i = 0; i < num_records; i++) {
        printf("%d %s %s %s %s %d\n", students[i].rollno, students[i].name, students[i].clas, students[i].semester, students[i].subject, students[i].exam_fee);
    }
}

void updateRecord(struct Student *students, int num_records) 
{
    int updateChoice;
    printf("Enter student id or name to update: ");
    scanf("%d", &updateChoice);

    int index = searchRecord(students, num_records, 1, updateChoice, ""); 

    if (index != -1) 
    {
        printf("Enter new details for the student:\n");
        printf("Enter rno, name, std, sem, subject, and fee: ");
        scanf("%d %s %s %s %s %d", &students[index].rollno, students[index].name, students[index].clas, students[index].semester, students[index].subject, &students[index].exam_fee);
        printf("Record Updated successfully\n");
    } 
    else 
       {
        printf("Record not found.\n");
    }
}

// Function to delete a record by id or name
void deleteRecord(struct Student *students, int *num_records) 
{
    int deleteChoice;
    printf("Enter student id or name to delete: ");
    scanf("%d", &deleteChoice);

    int index = searchRecord(students, *num_records, 1, deleteChoice, ""); 

    if (index != -1) {
        for (int j = index; j < (*num_records - 1); j++) {
            students[j] = students[j + 1];
        }

        (*num_records)--;
        students = (struct Student *)realloc(students, (*num_records) * sizeof(struct Student));

        printf("Record deleted successfully\n");
    } else {
        printf("Record not found.\n");
    }
}

int searchRecord(struct Student *students, int num_records, int choice, int key, char *search_name) 
{
    int found = -1;

    for (int i = 0; i < num_records; i++) {
        if ((choice == 1 && students[i].rollno == key) ||
            (choice == 2 && strcmp(students[i].name, search_name) == 0)) {
            found = i;
            break;
        }
    }

    return found;
}