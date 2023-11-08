using System;
using System.Threading;

namespace MyThreadPool
{
    class Program
    {
        public static void Main()
        {
            while(true)
            {
                ThreadPool.QueueUserWorkItem(GenerateNumbers);
            }
            
         
        }

 
        static void GenerateNumbers(Object stateInfo)
        {
            Random rand = new();          
            int randNumber = rand.Next(100, 2000);
            Console.WriteLine($"Randomly generated number:{randNumber}", Thread.CurrentThread.ManagedThreadId);
            Thread.Sleep(randNumber);
            

        }
    }
}
