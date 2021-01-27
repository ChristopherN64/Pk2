using System;

namespace Logik
{
    class Auto
    {  
        public int Baujahr{get;set;}

        private string hersteller;
        public string Hersteller{
            get{return this.hersteller;}
            set{this.hersteller = value;}
        }

        
        public Auto(string hersteller, int baujahr)
        {
            this.hersteller = hersteller;
            this.Baujahr = baujahr;
        }

        public override string ToString()
        {
            return "Hersteller: " + Hersteller + " Baujahr: " +  Baujahr;
        }
    }


    class AutoArgs : EventArgs
    {
        public Auto Auto{get;}

        public AutoArgs(Auto auto)
        {
            this.Auto=auto;
        }
    }
}