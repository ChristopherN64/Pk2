#include <stdio.h>

char to_upper_case(char c)
{
    if(c>='a' && c<='z')
    {
        c-=32;
    }
    return c;
}