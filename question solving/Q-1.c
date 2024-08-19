#include<stdio.h>
#include<stdlib.h>

int main() 
{
    int n,i,*ptr,sum=0;

    ptr=(int*)calloc(n,sizeof(int));

    if(ptr==NULL) 
    {
        printf("Unable to allocate memory");
        exit(0);
    }
    return 0;
}