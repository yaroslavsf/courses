using System;

namespace Calculator
{
    public delegate double CalcOperationDelegate(double x, double y);
    static class Calculator
    {
        static public double Add(double x, double y)
        {
            return x + y;
        }
        static public double Sub(double x, double y)
        {
            return x - y;
        }
       static public double Mult(double x, double y)
        {
            return x * y;
        }
        static public double Div(double x, double y)
        {
            
            if(y == 0)
            {
                throw new Exception();
            }
            return x / y;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("enter the operation to do");          
            string sign = Console.ReadLine();

            Console.WriteLine("enter x and y(in defferent rows)");
            double x = Convert.ToDouble(Console.ReadLine());
            double y = Convert.ToDouble(Console.ReadLine());

            CalcOperationDelegate operation = null;
            switch (sign)
            {
                case "-":
                    operation = Calculator.Sub;
                    break;
                case "+":
                    operation = Calculator.Add;
                    break;
                case "*":
                    operation = Calculator.Mult;
                    break;
                case "/":
                    operation = Calculator.Div;
                    break;
            }

            Console.WriteLine($"your answer is {operation(x, y)}");
        }
    }
}
