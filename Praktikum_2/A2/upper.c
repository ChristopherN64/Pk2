#include <stdio.h>
#include <string.h>
#include "../A1/toUpperCase.h"

void upper(char text[]);

int main(int argc, char const *argv[])
{
    char string[] = "string Ab4 ()";
    upper(string);
    printf("%s",string);
    return 0;
}


void upper(char text[])
{
    for(int il=0; il<strlen(text);il++)
    {
        text[il] = to_upper_case(text[il]);
    }
}