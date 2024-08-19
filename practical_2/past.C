#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student_name
{
    int rollno;
    char name[50];
    char clas[20];
    char semester[10];
    char subject[50];
    int exam_fee;
};

void displayRecords(struct Student *p, int num_records);
void updateRecord(struct Student *p, int num_records);
void deleteRecord(struct Student *p, int *num_records);
int searchRecord(struct Student *p, int num_records, int choice, int key, char *search_name);

int main()
{
  int size,i;

  struct student_name*p;
  p=(struct student_name*)malloc(size*(sizeof(struct student_name)));

  if (p == NULL) 
  {
    printf("Memory Allocation Failed!!\n");
    return 1;
  }
  else
  {

    printf("No. of p:-\n");
    scanf("%d",&size);

    for (i=0;i<size;i++)
    {
      printf("\nEnter stundent no.%d's rllno,name,std,sem,subject and fee:-\n",i+1);
      scanf("%d%s%s%s%s%d",&(p+i)->rollno,&(p+i)->name,&(p+i)->clas,&(p+i)->semester,&(p+i)->subject,&(p+i)->exam_fee);
    }

    for (i=0;i<size;i++)
    {
      printf("\nInfo of student no.%d:- %d %s %s %s %s %d\n",i+1,&(p+i)->rollno,(p+i)->name,(p+i)->clas,(p+i)->semester,(p+i)->subject,(p+i)->exam_fee);
    }
    

    // -------------------------------------------------------------------------------------------------
    char choice;

    printf("Do you want to modify/update records (Y/N)? ");
    scanf(" %c", &choice);

    if (choice == 'Y' || choice == 'y') 
    {

        int updateChoice;

        printf("How do you want to modify records - by id or by name?\n");
        printf("Press <1> for by id and press <2> for by name: ");
          
        int updateChoice;
        printf("Enter student id or name to update: ");
        scanf("%d", &updateChoice);

        int index = searchRecord(p, num_records, 1, updateChoice, ""); 

        if (index != -1) 
        {
          printf("Enter new details for the student:\n");
          printf("Enter rno, name, std, sem, subject, and fee: ");
          scanf("%d %s %s %s %s %d", &p[index].rollno, p[index].name, p[index].clas, p[index].semester, p[index].subject, &p[index].exam_fee);
          printf("Record Updated successfully\n");
        } 
        else 
        {
          printf("Record not found.\n");
        }

        // updateRecord(p, num_records);

        printf("========== Output after modification============\n");
        for (int i = 0; i < num_records; i++) 
        {
          printf("%d %s %s %s %s %d\n", p[i].rollno, students[i].name, p[i].clas, p[i].semester, p[i].subject, p[i].exam_fee);
        }
    }
// ----------------------------------------------------------------------------------------------

    printf("Do you want to delete records (Y/N)? ");
    scanf(" %c", &choice);

    if (choice == 'Y' || choice == 'y')
    {
      int deleteChoice;
      printf("How do you want to delete records - by id or by name?\n");
      printf("Press <1> for by id and press <2> for by name: ");
      scanf("%d", &deleteChoice);

        int deleteChoice;
        printf("Enter student id or name to delete: ");
        scanf("%d", &deleteChoice);

        int index = searchRecord(p, *num_records, 1, deleteChoice, ""); 

        if (index != -1)
        {
              for (int j = index; j < (*num_records - 1); j++) 
              {
                p[j] = p[j + 1];
              }

            (*num_records)--;
            p = (struct Student *)realloc(p, (*num_records) * sizeof(struct Student));

              printf("Record deleted successfully\n");
        } 
        else 
        {
          printf("Record not found.\n");
        }

      printf("========== Output after deletion============\n");
      for (int i = 0; i < num_records; i++) 
        {
          printf("%d %s %s %s %s %d\n", p[i].rollno, students[i].name, students[i].clas, students[i].semester, students[i].subject, students[i].exam_fee);
        }
    }

// ---------------------------------------------------------------------------------------
    char search_name[50];
    printf("Find the student record by name:\n");
    printf("Enter student name: ");
    scanf("%s", search_name);
    int result = searchRecord(p, num_records, 2, -1, search_name);

    // test 


    // int found = -1;

    // for (int i = 0; i < num_records; i++) {
    //     if ((choice == 1 && p[i].rollno == key) ||
    //         (choice == 2 && strcmp(p[i].name, search_name) == 0)) {
    //         found = i;
    //         break;
    //     }
    // }

    // return found;

     
    // test end

    if (result == -1) 
    {
      printf("Student not found.\n");
    }

    free(p);

  }

  // ----------------------------------------------------------------------------------------------------------------------
//   int searchRecord(struct Student *students, int num_records, int choice, int key, char *search_name) 
//   {
//       int found = -1;

//       for (int i = 0; i < num_records; i++) 
//       {
//           if ((choice == 1 && students[i].rollno == key) ||(choice == 2 && strcmp(students[i].name, search_name) == 0)) 
//           {
//             found = i;
//             break;
//           }
//       }

//       return found;
//   }
//   return 0;
// }