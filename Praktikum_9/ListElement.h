#ifndef LISTELEMENT_H
#define LISTELEMENT_H

#include <iostream>
template <class TT>
class ListElement
{
private:
    TT text;
    ListElement *nextElement;

public:
    ListElement(TT newText) : text{newText}, nextElement{nullptr}
    {
    }
    TT getText()
    {
        return text;
    }

    ListElement *getNextElement()
    {
        return nextElement;
    }

    void setNextElement(ListElement<TT> *ne)
    {
        nextElement = ne;
    }
};
#endif
