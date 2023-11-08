using System;
using ConsoleApp.Logic;
using System.Collections;
namespace hw_4
{
    class Program
    {
        static void Main(string[] args)
        {
        
            DoubleLinkedList<int> dlist = new DoubleLinkedList<int>();
            dlist.Add(5);
            dlist.Add(4);
            dlist.Add(3);
            foreach (int i in dlist)
            {
                Console.WriteLine(i);
            }
            if (dlist.Contains(5))
            {
                Console.WriteLine("dlist contains 5");
            }

            dlist.Remove(5);
            foreach (int i in dlist)
            {
                Console.WriteLine(i);
            }

            dlist.Delete(0);    //index
            foreach (int i in dlist)
            {
                Console.WriteLine(i);
            }
            var value = dlist.GetValue(0);
            Console.WriteLine(value);
        }
    }
}
