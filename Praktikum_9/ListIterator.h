#ifndef LISTIT_H
#define LISTIT_H
#include <string.h>
#include <iostream>
#include "ListElement.h"
#include "Iterator.h"

template <class Type> class ListIterator : public Iterator<Type>{
    private:
        ListElement<Type> *currentElement;
        bool firstElement;

    public:
        ListIterator(ListElement<Type> *firstElement)
        {
            this->currentElement = firstElement;
            this->firstElement = true;
        }

        bool hasNext() override
        {
            if (!firstElement)
            {
                if (this->currentElement->getNextElement() != nullptr)
                    return true;
                else
                    return false;
            }
            else
            {
                if (this->currentElement != nullptr)
                    return true;
                else
                    return false;
            }
        }

        Type next() override
        {
            if (!firstElement)
            {
                currentElement = currentElement->getNextElement();
            }
            else
            {
                firstElement = false;
            }
            return currentElement->getText();
        }
};

#endif