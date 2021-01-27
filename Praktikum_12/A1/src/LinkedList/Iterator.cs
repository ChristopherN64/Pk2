using System;

namespace LinkedList{

    public interface Iter<T>
    {
        //Implizit Public und Abstract
        bool HasNext();
        T Next();
    }
}