using Xunit;
using ExampleClasses;
using PVO11_console.Converters;

namespace CsvSerializeTest
{
    public class CsvSerialize_UnitTest
    {
        [Fact]
        public void Person_Serialization_Reflection()
        {
            ExampleSociety society = new ExampleSociety();
            var input = society.CreateExamplePeople();

            var expectedResult = "Id,Firstname,Lastname,Email,Profession" +
                "\n100,Marti,Gino,Marti.Gino@yopmail.com,worker" +
                "\n101,Dorice,Anselmi,Dorice.Anselmi@yopmail.com,doctor" +
                "\n102,Elbartina,Tamar,Elbertina.Tamar@yopmail.com,police officer" +
                "\n103,Marcelline,Maroney,Marcelline.Maroney@yopmail.com,doctor";

            var actualResult = CsvReflectionConvert.Serialize<Person>(input);

            Assert.Equal(expectedResult, actualResult);
        }

        [Fact]
        public void Person_Serialization_Manual()  //just for IEnumerable<Person>
        {
            ExampleSociety society = new ExampleSociety();
            var input = society.CreateExamplePeople();

            var expectedResult = "Id,Firstname,Lastname,Email,Profession" +
                "\n100,Marti,Gino,Marti.Gino@yopmail.com,worker" +
                "\n101,Dorice,Anselmi,Dorice.Anselmi@yopmail.com,doctor" +
                "\n102,Elbartina,Tamar,Elbertina.Tamar@yopmail.com,police officer" +
                "\n103,Marcelline,Maroney,Marcelline.Maroney@yopmail.com,doctor";

          
            var actualResult = CsvManualConvert_Serialize.Serialize(input); 
           
            Assert.Equal(expectedResult, actualResult);
        }
    }
}
