using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
//init
IEnumerable<int> numbers = GetNumbers(10);
IEnumerable<int> GetNumbers(int maxNumber)
{
return new NumbersGenerator();
}

//first task
/*void ForEach(IEnumerable<int> numbers, Action<object> source)
{
    foreach(var number in numbers)
    {
        source(number);
    }
}
ForEach(numbers, Console.WriteLine);*/

//second task
/*IEnumerable<T2> Select<T1, T2>(IEnumerable<T1> source,  Func<T1, T2> converter)
{
    foreach(var item in source)
    {
        yield return converter(item);
    }
}
IEnumerable<string> strings = new string[]{ "1", "2", "3" };

var convertedStrings = Select<string, int>(strings, int.Parse);
foreach(var item in convertedStrings)
{
    Console.WriteLine(item.GetType());
}*/

//third task
/*bool All<T>(IEnumerable<T> source, Func<T, bool> checker)
{
    foreach(var item in source)
    {
        if (!checker(item))
        {
            return true;
        }
    }
    return false;
}
IEnumerable<string> strings = new string[] { "1", "2", "3" };
bool checkAll = All<string>(strings, string.IsNullOrEmpty);
Console.WriteLine(checkAll);*/
class NumbersGenerator : IEnumerable<int>
{
    public IEnumerator<int> GetEnumerator()
    {
        return new NumbersEnumerator();
    }

    IEnumerator IEnumerable.GetEnumerator()
    {
        return new NumbersEnumerator();
    }
}
class NumbersEnumerator : IEnumerator<int>
{
    public int Start { get; set; } = 1;

    public int MaxNumber { get; set; } = 10;
    public int Current { get; set; }

    object IEnumerator.Current => Current;

    public void Dispose() { }

    public bool MoveNext()
    {
        if (Current < MaxNumber)
        {
            Current = Start;
            Start++;
            return true;
        }
        return false;
    }

    public void Reset()
    {
        throw new NotImplementedException();
    }
}