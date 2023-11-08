using PVO11_console.Converters;
using System;
using System.Collections.Generic;
using ExampleClasses;


namespace PVO11_console
{
    class Program
    {
        
        static void Main(string[] args)
        {
            //serialize
            /*ExampleSociety society = new ExampleSociety();
            List<Person> people = society.CreateExamplePeople();

            CsvReflectionConvert.SerializeAndPrint(people);
            CsvReflectionConvert.SerializeAndWriteFile(people, "text.txt");*/

            //deserialize
            string csv = "Id,Firstname,Lastname,Email,Profession\n100,Marti,Gino,Marti.Gino @yopmail.com,worker\n101,Dorice,Anselmi,Dorice.Anselmi @yopmail.com,doctor\n102,Elbertina,Tamar,Elbertina.Tamar @yopmail.com,police officer\n103,Marcelline,Maroney,Marcelline.Maroney @yopmail.com,doctor";
            var people = CsvManualConvert_Serialize.Deserialize(csv, typeof(Person));
            Console.WriteLine(1);
        }
    }
}
