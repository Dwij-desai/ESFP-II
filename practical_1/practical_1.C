#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// id, or by name or by class

struct student
{
    char id[10];
    char name[10];
    int age;
    char clas[10];
    char sem[5];
    char subj[10];
    char fee[10];
    // sem subject fee
}e;


int main()
{
    int size,i;
    int option;
    char search_id[10];
    char search_name[10];
    char search_class[10];


   struct student*p;
   
   printf("No. of students:-\n");
   scanf("%d",&size);
 
   p=(struct student*)malloc(size*(sizeof(struct student)));

   for (i=0;i<size;i++)
   {
        printf("\nEnter stundent no.%d's id,name,age,class,sem,subj,fee:-\n",i+1);
        scanf("%s%s%d%s%s%s%s",&(p+i)->id,&(p+i)->name,&(p+i)->age,&(p+i)->clas,&(p+i)->sem,&(p+i)->subj,&(p+i)->fee);
   }
   for (i=0;i<size;i++)
   {
        printf("\nInfo of student no.%d:- %s %s %d %s %s %s %s \n",i+1,(p+i)->id,(p+i)->name,(p+i)->age,(p+i)->clas,(p+i)->sem,(p+i)->subj,(p+i)->fee);
   }

// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    printf("\n1.Search by roll no.\n2.Search by name\n3.Search by class.\n4. exit the program");
    scanf("%d", &option);

    switch (option)
    {
        case 1:  // id 
        
        printf("\nEnter student id:\t");
        scanf("%s",&search_id);

        for(i=0;i<size;i++)
        {
            if(strcmp((p+i)->id,search_id) == 0)
            {

                printf("\nInfo of student:- %s %s %d %s %s %s %s \n",(p+i)->id,(p+i)->name,(p+i)->age,(p+i)->clas,(p+i)->sem,(p+i)->subj,(p+i)->fee);

            }
            else
            {
                printf("\nname does not exisit");
                
            }
        }

        break; 

        case 2: // name
        
        printf("\nEnter student name:\t");
        scanf("%s",&search_name);

        for(i=0;i<size;i++)
        {
            if(strcmp((p+i)->name,search_name) == 0)
            {

                printf("\nInfo of student:- %s %s %d %s %s %s %s \n",(p+i)->id,(p+i)->name,(p+i)->age,(p+i)->clas,(p+i)->sem,(p+i)->subj,(p+i)->fee);

            }
            else
            {
                printf("\nname does not exisit");
                
            }
        }

        break;

        case 3: // class
        
        printf("\nEnter student class:\t");
        scanf("%s",&search_class);

        for(i=0;i<size;i++)
        {
            if(strcmp((p+i)->clas,search_class) == 0)
            {

                printf("\nInfo of student:- %s %s %d %s %s %s %s \n",(p+i)->id,(p+i)->name,(p+i)->age,(p+i)->clas,(p+i)->sem,(p+i)->subj,(p+i)->fee);

            }
            else
            {
                printf("\nname does not exisit");
                
            }
        }

        break;

        default:
            break;
    }
    end:
        free (p);
        return 0;
}