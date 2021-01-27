using System;
using LinkedList;

namespace Logik
{
    class Fuhrpark
    {
        private LinkedList<Auto> fuhrpark; 

        public Fuhrpark(){this.fuhrpark = new LinkedList<Auto>();}
        public void Aufnehmen(Auto a)
        {
            this.fuhrpark.Add(a);
        }

        public void Inventur()
        {
            Iter<Auto> li = fuhrpark.Iterator();
            while(li.HasNext())
            {
                Auto auto = li.Next();
                Console.WriteLine(auto);
            }
        }
        
        public double BerechneFlottenalter()
        {
            Iter<Auto> li = fuhrpark.Iterator();
            int iSumme=0;
            int iAnzahl=0;
            while(li.HasNext())
            {
                Auto auto = li.Next();
                iAnzahl++;
                iSumme+= auto.Baujahr;
            }
            return iSumme / iAnzahl;
        }
    }
}