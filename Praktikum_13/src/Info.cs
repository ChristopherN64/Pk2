using System;

namespace Logik
{
    class Info
    {
        public Info(Fuhrpark fuhrpark)
        {
            fuhrpark.Ereignis += fpListener;
        }

        public void fpListener(object sender,EventArgs arg)
        {
            AutoArgs autoArgs = (AutoArgs)arg;
            Console.WriteLine(autoArgs.Auto+" wurde Hinzugefügt");
        }
    }
}