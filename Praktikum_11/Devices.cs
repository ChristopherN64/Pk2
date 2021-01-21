using System;

namespace Fh.Pk2.Devices
{
    class CdPlayer
    {
        public void start()
        {
            Console.WriteLine("CdPlayer gestartet");
        }

        public void stop()
        {
            Console.WriteLine("CdPlayer gestoppt");
        }
    }

    class Garagentor
    {
        public void hoch()
        {
            Console.WriteLine("Garagentor wird geöffnet");
        }

        public void runter()
        {
            Console.WriteLine("Garagentor wird geschlossen");
        }
    }


}