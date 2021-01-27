using System;
using Logik;

namespace Praktikum_12
{
    class Program
    {
        static void Main(string[] args)
        {
            Fuhrpark fuhrpark = new Fuhrpark();
            fuhrpark.Aufnehmen(new Auto("Mercedes",2018));
            fuhrpark.Aufnehmen(new Auto("Mercedes",2020));
            fuhrpark.Aufnehmen(new Auto("Audi",2010));
            fuhrpark.Aufnehmen(new Auto("VW",2015));
            fuhrpark.Inventur();
            Console.WriteLine(fuhrpark.BerechneFlottenalter());
        }
    }
}
