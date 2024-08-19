#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

struct Car
{
    
    int CID;
    char Cname[30];
    char Cprice[20];
    char Ccolor[20];

    struct Car*next;

};

struct Car *newnode,*head,*end;
// void deleteProduct(struct Car **head_ref, int choice, int id, char name[]);

void Last()
{
    newnode = (struct Car*)malloc(sizeof (struct Car)); 

    printf("Enter the value as: ID of car , Name of car , Price , color of car:-\n");
    scanf("%d %s %s %s",&newnode->CID,&newnode->Cname,&newnode->Cprice,&newnode->Ccolor);  

    if(head == NULL)
    {

        newnode->next = NULL;
        head = newnode;
        end = newnode;
        
    }
    else
    {

        end->next = newnode;
        end = newnode;
        end->next = NULL;

    }

}// end of fuction-.end

void display()
{
    struct Car* ttemp;

    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("\nDisplay value:\n");
        for (ttemp = head; ttemp != NULL; ttemp = temp->next)
        {
            printf("%d %s %s %s\n", ttemp->CID, ttemp->Cname, ttemp->Cprice, ttemp->Ccolor);
        }
        printf("\n");
    }
} // end of fuction->display

// void deleteProduct(struct Car **head_ref, int choice, int id, char name[])

// {
//     struct Car *temp = *head_ref;
//     struct Car *prev = NULL;

//     if (choice == 1) 
//     {
//         printf("Enter Car ID: ");
//         scanf("%d", &id);
//     } 
//     else if (choice == 2) 
//     {
//         printf("Enter Car Name: ");
//         scanf("%s", name);
//     }

//     if (temp != NULL && ((choice == 1 && temp->Cid == id) || (choice == 2 && strcmp(temp->Came, name) == 0))) 
//     {
//         *head_ref = temp->next;
//         free(temp);
//         return;
//     }

//     while (temp != NULL && ((choice == 1 && temp->Cid != id) || (choice == 2 && strcmp(temp->Cname, name) != 0))) 
//     {
//         prev = temp;
//         temp = temp->next;
//     }

//     if (temp == NULL) 
//     {
//         printf("Car not found.\n");
//         return;
//     }

//     prev->next = temp->next;
//     free(temp);
// }

int main()
{
    int a=0;
    
    for(;;)
    {

        printf("Press <1> to add value on end \n");
        printf("Press <2> to display value \n");
        printf("Press <3> to display value \n");
        printf("Press <4> to End code \n");
        printf("\nEnter number for manu:  ");
        scanf("%d",&a);

        switch (a)
        {
            case 1:
                    int num_Car;
                    printf("\nHow many units do you want: ");
                    scanf("%d", &num_Car);

                    for(int i = 0; i < num_Car; i++)
                    {
                        Last();
                    }

            break;

            case 2:

                display();

            break;

            case 3:

                deleteProduct();
//                 char choice;
//                 printf("Do you want to find individual product information (y/n)?: ");
//                 scanf(" %c", &choice);
//                 if (choice == 'y' || choice == 'Y') 
//                 {
//                     int find_choice;
//                     printf("How do you want to find product information by ID or by Name: 1 for ID and 2 for Name: ");
//                     scanf("%d", &find_choice);
//                     findProduct(head, find_choice);
//                 }
// // ---------------------------------------------------------------------------------------------------------------------------------------------------------------------
//                 printf("Do you want to delete product record (y/n): ");
//                 scanf(" %c", &choice);
//                 if (choice == 'y' || choice == 'Y') {
//                     int delete_choice;
//                     printf("How do you want to delete record by ID or By name? 1 for by ID and 2 for by Name: ");
//                     scanf("%d", &delete_choice);
//                     deleteProduct(&head, delete_choice, 0, "");
//                     printf("============= Updated Record ============\n");
//                     displayProducts(head);
//                 }

//                 struct Product *temp;
//                 while (head != NULL) {
//                     temp = head;
//                     head = head->next;
//                     free(temp);
//                 }

            break;

            case 3:

                return 1;

            break;

            default:

                printf("Enter right number");

            break;
        }
    }
    return 0;
}// end of fuction->Main