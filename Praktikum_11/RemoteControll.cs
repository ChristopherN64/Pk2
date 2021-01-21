using System;

namespace Fh.Pk2.Rc
{
    class RemoteControll
    {
        Command[,] commands;
        

        public RemoteControll()
        {
            this.commands = new Command[4,2];
        }
        public void setCommand(int i,Command on,Command off)
        {
            this.commands[i,0] = off;
            this.commands[i,1] = on;
        }

        public void pressOn(int i)
        {
            this.commands[i,1].execute();
        }

        public void pressOff(int i)
        {
            this.commands[i,0].execute();
        }
    }

    abstract class Command
    {
       public abstract void execute();
    }
}