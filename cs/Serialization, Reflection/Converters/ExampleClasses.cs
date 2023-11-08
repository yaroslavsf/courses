using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExampleClasses
{
    public class ExampleSociety
    {
        public List<Person> CreateExamplePeople()
        {
            Person person1 = new Person(100, "Marti", "Gino", "Marti.Gino@yopmail.com", "worker");
            Person person2 = new Person(101, "Dorice", "Anselmi", "Dorice.Anselmi@yopmail.com", "doctor");
            Person person3 = new Person(102, "Elbartina", "Tamar", "Elbertina.Tamar@yopmail.com", "police officer");
            Person person4 = new Person(103, "Marcelline", "Maroney", "Marcelline.Maroney@yopmail.com", "doctor");
            List<Person> people = new List<Person> { person1, person2, person3, person4 };
            return people;
        }
    }

    public class Person
    {
        public int Id { get; set; }
        public string Firstname { get; set; }
        public string Lastname { get; set; }
        public string Email { get; set; }
        public string Profession { get; set; }

        public Person()
        {

        }
        public Person(int id, string firstname, string lastname, string email, string profession)
        {
            Id = id;
            Firstname = firstname;
            Lastname = lastname;
            Email = email;
            Profession = profession;
        }
    }
}
