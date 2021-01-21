using System;
using Fh.Pk2.Commands;
using Fh.Pk2.Devices;
using Fh.Pk2.Rc;


namespace Praktikum_11
{
    class Program
    {
        static void Main(string[] args)
        {

            CdPlayer cdPlayer = new CdPlayer();
            Garagentor garagentor = new Garagentor();

            CdStart cdStart = new CdStart(cdPlayer);
            CdStop cdStop = new CdStop(cdPlayer);
            GtHoch gtHoch = new GtHoch(garagentor);
            GtRunter gtRunter = new GtRunter(garagentor);
    
            RemoteControll remoteControll = new RemoteControll();
            remoteControll.setCommand(0,cdStart,cdStop);
            remoteControll.setCommand(1,gtHoch,gtRunter);

            remoteControll.pressOn(0);
            remoteControll.pressOff(1);
        }
    }
}
