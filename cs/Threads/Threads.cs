using System;
using System.Threading;

namespace Threads
{
    class Program
    {
        //Numbers
        public class NumbersWrapper
        {
            public int Min { get; set; }
            public int Max { get; set; }

            public NumbersWrapper(int min, int max = 2)
            {
                this.Min = min;
                this.Max = max;
            }
        }
        public static void GenerateNumbers(object wrapper)
        {
            Random rand = new();
            while (true)
            {
                if (wrapper is NumbersWrapper nw)//here is a problem
                {
                    Console.WriteLine($"Randomly generated number:{rand.Next(nw.Min, nw.Max)}");
                }
                
                Thread.Sleep(500);
            }
        }  
        //Fibonacci
        public static int Fibonacci(int i, int current = 0, int prev = 1)
        {
            return i == 0 ? current : Fibonacci(i - 1, prev, prev + current);
        }
        public static void GenerateFibonacci()
        {
            int i = 1;            
            while(true)
            {               
                Console.WriteLine($"Fibonacci number:{Fibonacci(i)}");
                Thread.Sleep(500);
                i++;
            }
        }
        static void Main(string[] args)
        {
            int min, max;
            Console.WriteLine("Enter the first bound");
            min = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Enter the second bound");
            max = Convert.ToInt32(Console.ReadLine());
            NumbersWrapper wrapper = new NumbersWrapper(min,max);

            Thread thread1 = new Thread(wrapper => GenerateNumbers(wrapper));
            thread1.Start();


            Thread thread2 = new Thread(GenerateFibonacci);
            thread2.Start();

        }
    }
}
