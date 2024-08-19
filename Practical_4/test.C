#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Car
{
    int CID;
    char Cname[30];
    char Cprice[20];
    char Ccolor[20];
    struct Car *prev;
    struct Car *next;
};

struct Car *newnode, *head = NULL, *end;

void Last()
{
    newnode = (struct Car *)malloc(sizeof(struct Car));

    printf("Enter the value as: ID of car, Name of car, Price, color of car:-\n");
    scanf("%d %s %s %s", &newnode->CID, &newnode->Cname, &newnode->Cprice, &newnode->Ccolor);
    printf("\n");

    if (head == NULL)
    {
        newnode->next = NULL;
        newnode->prev = head;
        head = newnode;
        end = newnode;
    }
    else
    {
        newnode->prev = end;
        end->next = newnode;
        end = newnode;
        end->next = NULL;
    }
}

void display()
{
    struct Car *ttemp;

    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("\nDisplay value:\n");
        for (ttemp = head; ttemp != NULL; ttemp = ttemp->next)
        {
            printf("%d %s %s %s\n", ttemp->CID, ttemp->Cname, ttemp->Cprice, ttemp->Ccolor);
        }
        printf("\n");
    }
}

void findUnit()
{
    int choice, id;
    char name[30];
    printf("Enter choice (1 for ID, 2 for Name): ");
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("Enter Car ID to find: ");
        scanf("%d", &id);
    }
    else if (choice == 2)
    {
        printf("Enter Car Name to find: ");
        scanf("%s", name);
    }

    struct Car *temp = head;
    int found = 0;

    while (temp != NULL)
    {
        if ((choice == 1 && temp->CID == id) || (choice == 2 && strcmp(temp->Cname, name) == 0))
        {
            printf("Car found: %d %s %s %s\n", temp->CID, temp->Cname, temp->Cprice, temp->Ccolor);
            found = 1;
        }
        temp = temp->next;
    }

    if (!found)
    {
        printf("Car not found.\n");
    }
}

void deleteUnit()
{
    int choice, id;
    char name[30];
    printf("Enter choice (1 for ID, 2 for Name): ");
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("Enter Car ID to delete: ");
        scanf("%d", &id);
    }
    else if (choice == 2)
    {
        printf("Enter Car Name to delete: ");
        scanf("%s", name);
    }

    struct Car *temp = head;
    struct Car *prev = NULL;

    while (temp != NULL)
    {
        if ((choice == 1 && temp->CID == id) || (choice == 2 && strcmp(temp->Cname, name) == 0))
        {
            if (prev == NULL)
            {
                head = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            free(temp);
            printf("Car deleted successfully.\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("Car not found.\n");
}

void add()
{
    int choice;
    printf("Press <1> to add at front\n");
    printf("Press <2> to add at end\n");
    scanf("%d", &choice);

    newnode = (struct Car *)malloc(sizeof(struct Car));
    
    if(choice == 1 || choice == 2)
    {

        printf("Enter the value as: ID of car, Name of car, Price, color of car:-\n");
        scanf("%d %s %s %s", &newnode->CID, &newnode->Cname, &newnode->Cprice, &newnode->Ccolor);
        printf("\n");

        if (head == NULL)
        {
            newnode->next = NULL;
            newnode->prev = head;
            head = newnode;
            end = newnode;
        }
        else
        {
            if (choice == 1)
            {
                newnode->prev = NULL;
                newnode->next = head;
                head->prev = newnode;
                head = newnode;
            }
            else if (choice == 2)
            {
                newnode->prev = end;
                end->next = newnode;
                end = newnode;
                end->next = NULL;
            }
        }
    }
    else
    {
        printf("please Enter right number\n\n");
    }
}

int main()
{
    int a = 0;

    for (;;)
    {
        printf("Press <1> to add value at end \n");
        printf("Press <2> to display value \n");
        printf("Press <3> to find car \n");
        printf("Press <4> to delete car \n");
        printf("Press <5> to add car \n");
        printf("Press <6> to end code \n");
        printf("\nEnter number for menu:  ");
        scanf("%d", &a);

        switch (a)
        {
        case 1:
            int num_Car;
            printf("\nHow many units do you want: ");
            scanf("%d", &num_Car);

            for (int i = 0; i < num_Car; i++)
            {
                Last();
            }

            break;

        case 2:
            display();
            break;

        case 3:
            findUnit();
            break;

        case 4:
            deleteUnit();
            break;

        case 5:
            add();
            break;

        case 6:
            return 1;
            break;

        default:
            printf("Enter right number\n");
            break;
        }
    }
    return 0;
}
