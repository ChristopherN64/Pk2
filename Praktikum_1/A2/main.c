#include <stdio.h>
#include "libmy.h"

int main(int argc, char const *argv[])
{
    printf("ASCI Tabelle: \n");
    printAsci(10);
    printf("\n\nEin mal Eins:\n");
    einMalEins();
    printf("\n\n513 in als Binär %d");
    intToBin(513);
    return 0;
}
