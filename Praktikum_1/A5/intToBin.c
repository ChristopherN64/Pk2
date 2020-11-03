#include <stdio.h>
#include <math.h>

void intToBin(int iZahl)
{
    for(int il=15;il>=0; il--)
    {
        if(pow(2,il)<=iZahl)
        {
            //printf("\n%d   %d\n",iZahl, pow(2,il));
            iZahl-=pow(2,il);
            printf("1");
        }
        else printf("0");
    }
}