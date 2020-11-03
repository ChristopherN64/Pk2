#include <stdio.h>

void einMalEins()
{
    int iKl;
    printf("Kleinse und Größte Zahl des Ein mal Eins eingeben:\n");
    scanf("%d",&iKl);
    int iGr;
    scanf("%d",&iGr);

    for(int il=1; il<=10; il++)
    {
        for(int il2 = iKl; il2<=iGr;il2++)
        {
            printf(" %d ", il*il2);
        }
        printf("\n");
    }
}