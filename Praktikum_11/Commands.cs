using System;
using Fh.Pk2.Rc;
using Fh.Pk2.Devices;


namespace Fh.Pk2.Commands
{
   class CdStart : Command
   {
       CdPlayer cdPlayer;

        public CdStart(CdPlayer cdp)
        {
            this.cdPlayer=cdp;
        }

       override public void execute()
       {
           this.cdPlayer.start();
       }
   }


   class CdStop : Command
   {
       CdPlayer cdPlayer;

       public CdStop(CdPlayer cdp)
       {
           this.cdPlayer=cdp;
       }

        public override void execute()
        {
            this.cdPlayer.stop();
        }
   }


   class GtHoch : Command
   {
       Garagentor garagentor;

       public GtHoch(Garagentor gt)
       {
           this.garagentor = gt;
       }

        public override void execute()
        {
            this.garagentor.hoch();
        }
   }

   class GtRunter : Command
   {
       Garagentor garagentor;

       public GtRunter(Garagentor gt)
       {
           this.garagentor=gt;
       }

        public override void execute()
        {
            this.garagentor.runter();
        }
   }
}