using System;
using System.Threading;

namespace Csharp_Implement
{
    class BasicThread
    {
        public static void DoSomething()
        {
            for (int i = 0; i < 5; ++i)
            {
                Console.WriteLine($"DoSomething : {i}");
                Thread.Sleep(10);
            }
        }
    }
}
