using System;

namespace LinkedList
{
    class LinkedList<T>{
        //Implizite erstellung der get und Set Protatys (Eigenschaften)
        ListElement<T> firstElement{get; set;}
        
        public LinkedList()
        {
            this.firstElement=null;
        }
        
        public void Add(T data)
        {
            ListElement<T> element = new ListElement<T>(data);
            //Wenn sich in der Liste noch kein Element befindet 
            if(this.firstElement == null)
            {
                this.firstElement = element;
            }
            else
            {
                //Durchgehen bis zum letzten Element
                ListElement<T> leTemp;
                leTemp = this.firstElement;
                while(leTemp.NextElement !=null)
                {
                    leTemp = leTemp.NextElement;
                }
                leTemp.NextElement = element;
            }
        }

        public bool Remove(int index)
        {
            ListElement<T> leTemp = this.firstElement;
            ListElement<T> leLast = null;

            //Wenn das erste Element gelöscht werden soll wird der First zeiger der ll versetzt 
            if(index==0)
            {
                firstElement = firstElement.NextElement;
                return true;
            }
            else
            {
                int il;
                //Laufen bis zum i-ten Element
                for(il=0; il<index  && leTemp.NextElement !=null;il++)
                {
                    leLast = leTemp;
                    leTemp = leTemp.NextElement;
                }
                //nur wenn nicht über die Listengröße hinaus gelaufen wurde, wird das Element gelöscht 
                if(il == index)
                {            
                    leLast.NextElement = leLast.NextElement.NextElement;
                    return true;
                }
                else return false;
            }
        }

        public Iter<T> Iterator()
        {
            return new ListIterator<T>(firstElement);
        }


        public class ListElement<TT>
        {
            //implizite erstellung von get und Set Propaty
            private TT data;

            public TT Data{
                get{
                    return this.data;
                }
                set{
                    this.data=value;
                }
            }

            private ListElement<TT> nextElement;
            //Explizite erstellung von get und Set Propaty

            public ListElement(TT data)
            {
                this.data=data;
            }

            public ListElement<TT> NextElement
            {
                get{
                    return this.nextElement;
                }
                
                set{
                    this.nextElement = value;
                }
            }
        }


        public class ListIterator<TTT> : Iter<TTT>
        {
            ListElement<TTT> aktuellesElement;
            bool firstNext;
            public ListIterator(ListElement<TTT> firstElement)
            {
                firstNext=true;
                this.aktuellesElement = firstElement;
            }
            
            
            //Beim Implementieren von interface Methoden muss und darf kein override stehen
            public bool HasNext()
            {
                bool returnValue = false;
                if(firstNext && aktuellesElement != null) returnValue = true;
                else if(!firstNext && aktuellesElement.NextElement !=null) returnValue = true;
                return returnValue;
            }

            public TTT Next()
            {
                if(firstNext)  firstNext = false;
                else aktuellesElement = aktuellesElement.NextElement;
                return aktuellesElement.Data;
            }
        }

    }
}