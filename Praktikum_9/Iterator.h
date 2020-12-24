#ifndef ITERATOR_H
#define ITERATOR_H

template <class TP> class Iterator
{
    public:
        Iterator(){}
        virtual bool hasNext()=0;
        virtual TP next()=0;     
};

#endif