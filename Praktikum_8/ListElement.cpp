#include "ListElement.h"
#include <iostream>

ListElement::ListElement(const char *newText) : text{newText}, nextElement{nullptr}
{
}

const char *ListElement::getText()
{
    return text;
}

ListElement *ListElement::getNextElement()
{
    return nextElement;
}

void ListElement::setNextElement(ListElement *ne)
{
    nextElement = ne;
}
