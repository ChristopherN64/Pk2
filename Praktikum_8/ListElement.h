#ifndef LISTELEMENT_H
#define LISTELEMENT_H

class ListElement
{
    private:
        const char *text;
        ListElement *nextElement;

    public:
        ListElement(const char *newText);

        const char* getText();

        ListElement* getNextElement();

        void setNextElement(ListElement *ne);
};
#endif 
