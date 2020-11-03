#include <stdio.h>

void printAsci(int s)
{
    int il=32;
    for(il=32; il<127;il++)
    {
        printf("%d %c   ",il,il);
        if((il-31)%s==0) 
        {
            printf("\n");
        }

    }
}