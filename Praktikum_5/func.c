#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[])
{
    printf("\n\nAnzahl leerzeilen in String per Index \" asb asd r rr s   \": %d \n",countspaceIndex(" asb asd r rr s   "));
    printf("Anzahl leerzeilen in String per Zeiger \" asb asd r rr s   \": %d \n",countspaceZeiger(" asb asd r rr s   "));
    double d[] = {4.6,8.4,2.4,1.5,0.2};
    printf("Minimum des Arrays {4.6,8.4,2.4,1.5,0.2}: %f \n",min(d,5));

    printf("strcat von abc und defhij: %s\n",stringcat("abc"," defhij"));

    printf("Fakultaet von 10: %ld",fakultaet(10));

    printf("Bin von 10/0 , 10/1 , 10/10 , 49/6: %.1f , %.1f , %.1f , %.1f\n\n",binominal(10,0),binominal(10,1),binominal(10,10),binominal(49,6));
    return 0;
}

int countspaceIndex(char s[])
{
    int ic=0;
    for(int il=0;il<strlen(s); il++)
    {
        if(s[il]==' ') ic++;
    }
    return ic;
}

int countspaceZeiger(char s[])
{
    int ic=0;
    for(int il=0;il<strlen(s); il++)
    {
        if(*(s+il)==' ') ic++;
    }
    return ic;
}

double min(double a[],int n)
{
    if(n!=0)
    {
        double dmin=a[0];
        for(int il=1; il<n;il++)
        {
            if(a[il]<dmin) dmin = a[il];
        }
        return dmin;
    }
    else return 0.0;
}

char *stringcat(const char* str1, const char* str2)
{
    int iStrlen = strlen(str1)+strlen(str2);
    char *strcat = (char*) malloc(iStrlen*sizeof(char));

    int il;
    for(il=0; il<strlen(str1); il++)
    {
        strcat[il] = str1[il];
    }
    for(int il2=0; il2<strlen(str2); il2++)
    {
        strcat[il] = str2[il2];
        il++;
    }
    return strcat;
}

double fakultaet(int iZahl)
{
    if(iZahl == 0) return 1;
    else return iZahl*fakultaet(iZahl-1);
}

double binominal(int n, int k)
{
    double fn = (double) fakultaet(n);
    double fk = (double) fakultaet(k);
    double fnk = (double) fakultaet(n-k);
    return (double) fn / (fk*fnk);
}