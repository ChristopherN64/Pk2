#include <iostream>
#include <string.h>
#include "ListElement.h"
#include "LinkedList.h"

void work(const char *t)
{
    std::cout << "Text: " << t << std::endl;
}

void ausgabe(const char *text)
{
    std::cout << text << std::endl;
}
// Test der LinkedList-
int main()
{
    using namespace std;
    LinkedList liste;
    liste.append("Element 1");
    liste.insert("Element 2", 2);
    LinkedList liste2 = liste;
    cout << "Liste:" << endl;
    liste.visit_all(ausgabe);
    liste.remove(2);
    cout << "Liste:" << endl;
    liste.visit_all(ausgabe);
    cout << "Liste2:" << endl;
    liste2.visit_all(ausgabe);

/*
    LinkedList *list = new LinkedList();
    list->append("ABC");
    list->append("Moin");
    list->append("Test 123 abs");
    list->append("0124");
    list->append("AUTO");
    list->append("pow");
    list->visit_all(&work);

    std::cout << "Element Nr 2 der Liste: "<< list->get(2) << std::endl;
    std::cout << "Element Nr 4 der Liste: "<< list->get(4) << std::endl;
    printf("Element Nr 14 der Liste: %s\n",list->get(14));

    list->remove(0);
    std::cout << std::endl << "Element 0 gelöscht" << std::endl;
    list->visit_all(&work);
    list->remove(2);
    std::cout << std::endl << "Element 2 gelöscht" << std::endl;
    list->visit_all(&work);

    std::cout << std::endl << "Text des Ersten: " << list->first()<<std::endl;
    std::cout << std::endl << "Text des Letzten: " << list->last()<<std::endl;

    std::cout << std::endl << "Index des Elementes Test 123 abs: " << list->index_of("Test 123 abs")<<std::endl;
    std::cout << std::endl;
    list->insert("Neues Element 0",0);
    list->visit_all(&work);
    std::cout << std::endl;
    list->insert("Neues Element 2",2);
    list->visit_all(&work);
    std::cout << std::endl;
    list->insert("Neues Element 50",50);
    list->visit_all(&work);
    std::cout << std::endl;

    delete list;
    
    return 0;
    */


    return 0;
}