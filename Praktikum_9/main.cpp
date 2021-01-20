#include <iostream>
#include <string.h>
#include "ListElement.h"
#include "LinkedList.h"
#include "Iterator.h"
#include "Medium.h"

void work(const char *t)
{
    std::cout << "Text: " << t << std::endl;
}

void ausgabe( Medium medium)
{
    std::cout << medium.getTitel() <<" " << medium.getJahr() <<std::endl;
}
// Test der LinkedList-
int main()
{
    using namespace std;

    LinkedList<Medium> liste;
    liste.append(Audio("Titel",2020,"Ich",222));
    liste.insert(Bild("Bild",1999,"Dortmund"), 2);
    LinkedList<Medium>  liste2 = liste;
    cout << "Liste:" << endl;
    liste.visit_all(ausgabe);
    liste.remove(2);
    cout << "Liste:" << endl;
    liste.visit_all(ausgabe);
    cout << "Liste2:" << endl;
    liste2.visit_all(ausgabe);


    cout << "ENDE" << endl;
    return 0;
}


