#include<stdio.h>
#include<stdlib.h>

int main()
{

    int n,i,*ptr,sum=0;

    printf("Enter number of elements: ");
    scanf("%d",&n);


    ptr=(int*)malloc(n*sizeof(int));


    if(ptr==NULL)
    {

        printf("Unable to allocate memory");
        exit(0);

    }

    printf("Enter elements array: ");

    for(i=0;i<n;++i)
    {

        scanf("%d",ptr+i);
        sum+=*(ptr+i);

    }

    printf("Sum of all elements=%d",sum);

    free(ptr);

    return 0;
}