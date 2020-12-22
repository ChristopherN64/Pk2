#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "ListElement.h"
#include "Iterator.h"
class LinkedList
{
    private:
        ListElement *firstElement;
        ListElement *lastElement;
    
    public:
        LinkedList(const LinkedList &obj);
        LinkedList();
        ~LinkedList();
    
        Iterator* iterator();

        // Fuegt den Text (in konstanter Zeit) an der letzten
        // Listenposition hinzu. Liefert den Wert 1, wenn das
        // Element eingefuegt werden konnte. Ansonsten wird
        // der Wert 0 geliefert
        int append(const char *text);

        // Fuegt ein neues Element an der Position p ein.
        // Das erste Element der Liste befindet sich an der
        // Position 0. Das Element, das sich aktuell an der
        // Position p befindet, wird nach rechts geschoben.
        // Falls sich weniger als p Elemente in der Liste befinden,
        // wird der Text am Ende angefuegt
        int insert(const char* text, int p);
    


        // Loescht das Element an der Position p. Das erste
        // Element befindet sich an der Position 0.
        // Falls das p-te Element nicht existiert, wird das letzte
        // Element geloescht. Die Anzahl der geloeschten Elemente
        // wird als Funktionswert geliefert
        int remove(int p);

        // Liefert den Text an der p-ten Listenposition.
        // Das erste Listenelement befindet sich an der Position 0.
        // Falls das p-te Element nicht existiert, wird nullptr
        // geliefert
        const char *get(int p);
        

        // Berechnet den Index des ersten Elements, das den Text
        // text enthaelt. Falls kein Element den gesuchten Text
        // enthaelt, wird -1 geliefert
        int index_of(const char *text);

        // Liefert den Text des ersten Elements der Liste (in
        // konstanter Zeit)
        const char *first();
        // Liefert den Text des letzten Elements der Liste (in
        // konstanter Zeit)
        const char *last();

        // Besucht alle Elemente der Liste und ruft fuer jedes
        // Element die Funktion work auf.
        void visit_all(void (*work)(const char* t));
};

class ListIterator : public Iterator
{
    private:
        ListElement *currentElement;
        bool firstElement;
    public:
        ListIterator(ListElement *firstElement);
        bool hasNext() override;
        const char* next() override;
};
#endif