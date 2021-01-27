using System;
using LinkedList;

namespace Logik
{
    class Fuhrpark
    {
        private LinkedList<Auto> fuhrpark; 

        //Ereignis Delegate
        public delegate void EreignisHandler(object sender,EventArgs arg);
        //Das Ereignis Objekt über das Benachichtigungen aller Regestrierten Listener erzeugt werden können und dem per += Funktionen (Listener) hinzugefügt werden können 
        public event EreignisHandler Ereignis;

        public Fuhrpark(){this.fuhrpark = new LinkedList<Auto>();}
        public void Aufnehmen(Auto a)
        {
            this.fuhrpark.Add(a);
            //Sende ein Ereignis an alle registrierten Listener 
            this.Ereignis(this,new AutoArgs(a));
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