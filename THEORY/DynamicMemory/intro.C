//              Dynamic Memory Allocation


//             This is  Malloc()

// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
//     int *p, n , i;
//     printf("write before molloc:-");
//     scanf("%d",&n);

//     p = (int*)malloc(n*(sizeof(int)));  // Here sizeof(int) will take bit as difal

//     for(i=1 ;i<=n;i++)
//     {
//         printf("\nwrite after malloc:-");
//         scanf("%d",p+i);
//     }

//     for(i=1 ;i<=n;i++)
//     {
//         printf("\nOutput no.%d of malloc:- %d",i,*(p+i));
//     }
//     return 0;
// }

//             This is  calloc()



#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p, n , i;
    printf("write before calloc:-");
    scanf("%d",&n);

    p = (int*)calloc(n,(sizeof(int)));  // Here sizeof(int) will take bit as difal

    for(i=1 ;i<=n;i++)
    {
        printf("\nwrite after calloc:-");
        scanf("%d",p+i);
    }


    for(i=1 ;i<=n;i++)
    {
        printf("\nOutput no.%d of calloc:- %d",i,*(p+i));
    }
    return 0;
}
