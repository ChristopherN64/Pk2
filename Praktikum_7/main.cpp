#include <iostream>
#include <string.h>
#include "Medium.h"

int main(int argc, char const *argv[])
{
    Medium *m[2];
    m[0] = new Audio("it Means Nothing",2007,"Stereiogibucs",229);
    m[1] = new Bild("Gebaeude FB Informatik",2018,"Dortmund");

    for(int il=0 ; il<sizeof(m)/sizeof(m[0]);il++)
    {
        m[il]->druckeDaten();
        std::cout << "Alter: " << m[il]->alter() << " Jahre " << std::endl;
        delete m[il];
    }
    return 0;
}
