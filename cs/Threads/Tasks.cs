using System;
using System.Threading;
using System.Threading.Tasks;

void Request()
{
    Console.WriteLine("message");
}

void Process()
{
    Random rand = new();
    int number = rand.Next(1, 10);
    if (number == 1)
    {
        throw new ArgumentException("10% exception");
    }
}

string Response(Task task)
{
    if (task.IsFaulted)
    {
        return null;
    }
    else
    {
        return "constant string";
    }
}

void Log(Task<string> task)
{
    if (task.Result == null)
    {
        Console.WriteLine("task result is null");
    }
}

Task taskRequest = new Task(Request);   //supposed to be written "async" but error occurs
Task taskProcess = new Task(()=>
{
    Process();
});
Task<string> taskResponse = new Task<string>(()=>
{
   return Response(taskProcess);
});
Task taskLog = new Task(()=>
{
    Log(taskResponse);
});

taskRequest.Start();    //don't get how to rewrite it with task.Run()
              

await taskRequest
  .ContinueWith((taskProcess) => {})
  .ContinueWith((taskResponse) => { })
  .ContinueWith((taskLog) => {});

