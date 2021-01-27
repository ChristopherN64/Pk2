using System;
using Logik;

namespace Praktikum_12
{
    class Program
    {
        static void Main(string[] args)
        {
            
            
            Fuhrpark fuhrpark = new Fuhrpark();
            //Zuweisung auch per Lambda möglich
            fuhrpark.Ereignis+=ergAusgabe;
            Info info = new Info(fuhrpark);
            fuhrpark.Aufnehmen(new Auto("Mercedes",2018));
            fuhrpark.Aufnehmen(new Auto("Mercedes",2020));
            fuhrpark.Aufnehmen(new Auto("Audi",2010));
            fuhrpark.Aufnehmen(new Auto("VW",2015));
            Console.WriteLine("Durchschnittliches Baujahr: "+fuhrpark.BerechneFlottenalter());
            
        }

        //EventListener Methode (Wird aufgerufen wenn per fuhrpark.Ereignis ein Event gesendet wird)
        public static void ergAusgabe(object sender, EventArgs arg)
        {
            Console.WriteLine("Ein Auto wurde hinzugefügt nämlich das Auto: ");
        }
    }
}
