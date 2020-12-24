#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "ListIterator.h"
#include "ListElement.h"
#include "Iterator.h"
#include "LinkedList.h"
#include <string.h>
#include <iostream>


template <class T> class LinkedList
{
private:
    ListElement<T> *firstElement;
    ListElement<T> *lastElement;

public:
    LinkedList() : firstElement{nullptr}, lastElement{nullptr} {}

    LinkedList(const LinkedList &obj) : firstElement{nullptr}, lastElement{nullptr}
    {
        std::cout << "COPYY CONST" << std::endl;
        if (obj.firstElement != nullptr)
        {
            this->append(obj.firstElement->getText());
            ListElement<T> *leTemp = obj.firstElement->getNextElement();
            while (leTemp != nullptr)
            {
                this->append(leTemp->getText());
                leTemp = leTemp->getNextElement();
            }
        }
    }

    ~LinkedList()
    {
        //Löschen aller noch vorhanden List Elemente
        std::cout << "Destruktor" << std::endl;
        ListElement<T> *leTemp = firstElement;
        ListElement<T> *leLast;
        while (leTemp != nullptr)
        {
            leLast = leTemp;
            leTemp = leTemp->getNextElement();
            std::cout << "Lösche Element" << std::endl;
            delete leLast;
        }
        firstElement = lastElement = nullptr;
    }

    Iterator<T> *iterator()
    {
        return new ListIterator<T>(this->firstElement);
    }

    // Fuegt den Text (in konstanter Zeit) an der letzten
    // Listenposition hinzu. Liefert den Wert 1, wenn das
    // Element eingefuegt werden konnte. Ansonsten wird
    // der Wert 0 geliefert
    int append(T text)
    {
        ListElement<T> *leTemp = new ListElement<T>(text);
        if (firstElement == nullptr && lastElement == nullptr)
        {
            firstElement = lastElement = leTemp;
        }
        else
        {
            lastElement->setNextElement(leTemp);
            lastElement = leTemp;
        }
        return 1;
    }
    // Fuegt ein neues Element an der Position p ein.
    // Das erste Element der Liste befindet sich an der
    // Position 0. Das Element, das sich aktuell an der
    // Position p befindet, wird nach rechts geschoben.
    // Falls sich weniger als p Elemente in der Liste befinden,
    // wird der Text am Ende angefuegt
    int insert(T text, int p)
    {
        //Wenn die Liste noch leer ist
        if (firstElement == nullptr)
        {
            append(text);
        }
        //Wenn das Element am anfang eingefügt werden soll
        else if (p == 0)
        {
            ListElement<T> *leTemp = new ListElement<T>(text);
            leTemp->setNextElement(firstElement);
            firstElement = leTemp;
        }
        else
        {
            ListElement<T> *leTemp = new ListElement<T>(text);
            ListElement<T> *leBefore = firstElement;
            int il;

            //Ermitteln des p-ten Elements
            for (il = 0; leBefore->getNextElement() != nullptr && il < p - 1; il++)
            {
                leBefore = leBefore->getNextElement();
            }
            //Wenn der Index p größer als die Liste ist oder es sich bei dem Element vor dem Index um das Letzte handelt,
            //wird das neue Element angehangen
            if (il < (p - 1) || leBefore == lastElement)
            {
                lastElement->setNextElement(leTemp);
                lastElement = leTemp;
            }
            //Wenn das Element irgendwo in der Mitte eingefügt werden soll
            else
            {
                leTemp->setNextElement(leBefore->getNextElement());
                leBefore->setNextElement(leTemp);
            }
        }
        return 1;
    }

    // Loescht das Element an der Position p. Das erste
    // Element befindet sich an der Position 0.
    // Falls das p-te Element nicht existiert, wird das letzte
    // Element geloescht. Die Anzahl der geloeschten Elemente
    // wird als Funktionswert geliefert
    int remove(int p)
    {
        if (firstElement == nullptr)
            return 0;
        else
        {
            ListElement<T> *leTemp = firstElement;
            ListElement<T> *lastLeTemp = nullptr;
            int il;

            for (il = 0; leTemp->getNextElement() != nullptr && il < p; il++)
            {
                lastLeTemp = leTemp;
                leTemp = leTemp->getNextElement();
            }
            //Wenn es sich bei dem zu löschenden um das einzige element der Liste handelt
            if (leTemp == firstElement && leTemp == lastElement)
            {
                firstElement = nullptr;
                lastElement = nullptr;
            }
            //Wenn es sich bei dem zu löschenden um das Letzte element handelt
            else if (leTemp->getNextElement() == nullptr)
            {
                lastLeTemp->setNextElement(nullptr);
                lastElement = lastLeTemp;
            }
            //Wenn es sich bei dem zu löschenden um das erste element handelt
            else if (leTemp == firstElement)
            {
                firstElement = leTemp->getNextElement();
            }
            //Wenn es sich bei dem zu löschenden weder um das letzte noch um das erste handelt
            else
            {
                lastLeTemp->setNextElement(leTemp->getNextElement());
            }
            delete leTemp;
            return 1;
        }
    }

    // Liefert den Text an der p-ten Listenposition.
    // Das erste Listenelement befindet sich an der Position 0.
    // Falls das p-te Element nicht existiert, wird nullptr
    // geliefert
    T get(int p)
    {
        if (firstElement == nullptr)
            return nullptr;
        else
        {
            //Durchgehen aller Elemente der Linked List, bis man bei dem p-ten Element steht, oder es kein nächstes Element mehr gibt
            ListElement<T> *leTemp = firstElement;
            int il;
            for (il = 0; leTemp != nullptr && il < p; il++)
            {
                leTemp = leTemp->getNextElement();
            }
            if (il == p)
                return leTemp->getText();
            else
                return nullptr;
        }
    }

    // Berechnet den Index des ersten Elements, das den Text
    // text enthaelt. Falls kein Element den gesuchten Text
    // enthaelt, wird -1 geliefert
    int index_of(T text)
    {
        if (firstElement == nullptr)
            return -1;
        else
        {
            //Durchgehen aller Elemente bis eines mit dem gesuchten Text gefunden wurde oder alle überprüft wurden
            ListElement<T> *leTemp = firstElement;
            int il;
            for (il = 0; leTemp != nullptr; il++)
            {
                if (strcmp(leTemp->getText(), text) == 0)
                    return il;
                leTemp = leTemp->getNextElement();
            }
            return -1;
        }
    }

    // Liefert den Text des ersten Elements der Liste (in
    // konstanter Zeit)
    T first()
    {
        if (firstElement != nullptr)
            return firstElement->getText();
        else
            return nullptr;
    }
    // Liefert den Text des letzten Elements der Liste (in
    // konstanter Zeit
    T last()
    {
        if (lastElement != nullptr)
            return lastElement->getText();
        else
            return nullptr;
    }

    // Besucht alle Elemente der Liste und ruft fuer jedes
    // Element die Funktion work auf.
    void visit_all(void (*work)(T t))
    {
        Iterator<T> *iter = iterator();
        while (iter->hasNext())
        {
            work(iter->next());
        }
    }
};
#endif