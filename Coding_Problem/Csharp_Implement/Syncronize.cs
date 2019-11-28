using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace Csharp_Implement
{
    class Counter
    {
        const int LOOP_COUNT = 1000;
        readonly object thisLock;

        private int count;
        public int Count { get { return count; } }
        public Counter()
        {
            thisLock = new object();
            count = 0;

        }
        public void Increase()
        {
            int loopCount = LOOP_COUNT;
            while(loopCount-- > 0)
            {
                //lock (thisLock)
                {
                    count++;
                }
                Thread.Sleep(1);
            }
        }
        public void Decrease()
        {
            int loopCount = LOOP_COUNT;
            while (loopCount-- > 0)
            {
                //lock (thisLock)
                {
                    count--;
                }
                Thread.Sleep(1);
            }
        }
    }
}
