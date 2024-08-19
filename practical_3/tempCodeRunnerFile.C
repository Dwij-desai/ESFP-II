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
    struct Car* temp;

    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        for (temp = head; temp != NULL; temp = temp->next)
        {
            printf("%d %s %s %s\n", temp->CID, temp->Cname, temp->Cprice, temp->Ccolor);
        }
    }
} // end of fuction->display

int main()
{
    int a=0;
    
    for(;;)
    {

        printf("Press <1> to add value on end \n");
        printf("Press <2> to display value \n");
        printf("Press <3> to display value \n");
        printf("Press <4> to End code \n");
        printf("Enter number for manu:  ");
        scanf("%d",&a);

        switch (a)
        {
            case 1:
                    int num_Car;
                    printf("\nHow many products you want to purchase: ");
                    scanf("%d", &num_Car);

                    for(int i = 0; i < num_Car