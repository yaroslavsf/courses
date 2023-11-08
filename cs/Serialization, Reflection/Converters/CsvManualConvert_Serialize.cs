using ExampleClasses;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PVO11_console.Converters
{
    public partial class CsvManualConvert_Serialize
    {
        
        public static string Serialize(List<Person> people)
        {
            string result = "";
            result =
              SerializeProperty(nameof(Person.Id)) +
              SerializeProperty(nameof(Person.Firstname)) +
              SerializeProperty(nameof(Person.Lastname)) +
              SerializeProperty(nameof(Person.Email)) +
              SerializeProperty(nameof(Person.Profession), true) + '\n';

            foreach (Person person in people)
            {

                result += SerializePropValue(person.Id);
                result += SerializePropValue(person.Firstname);
                result += SerializePropValue(person.Lastname);
                result += SerializePropValue(person.Email);
                result += SerializePropValue(person.Profession, true);
                result += '\n';
            }

            return result.Substring(0, result.Length - 1);
        }

        private static string SerializeProperty(string propName, bool isLast = false)
        {
            string propEnding = isLast ? string.Empty : ",";
            return $"{propName}{propEnding}";
        }

        private static string? SerializePropValue(object? propValue, bool isLast = false)
        {
            if (propValue == null)
                return "null";

            Type propType = propValue.GetType();
            string propEnding = isLast ? string.Empty : ",";

            bool isBuiltInType = propType.IsPrimitive
                || propType == typeof(string)
                || propType == typeof(DateTime);

            if (isBuiltInType)
            {
                return propValue switch
                {
                    string => $"{(string)propValue}{propEnding}",
                    bool => $"{propValue.ToString()!.ToLower()}{ propEnding }",
                    DateTime dateProp => $"{dateProp.ToString("yyyy-MM-ddTHH:mm:ss")}{propEnding}",
                    _ => $"{propValue.ToString()!}{propEnding}"
                };
            }

            return null;
            //TODO


            //if (propValue is IEnumerable enumerableProp)                    
            /*if (propValue is IEnumerable)
            {
                IEnumerable enumerableProp = (IEnumerable)propValue;

                string result = "[";

                foreach (object item in enumerableProp)
                {
                    result += $"{Serialize(item)},";
                }

                result = result.Substring(0, result.Length - 1);

                return result += "]";
            }

            return Serialize(propValue);*/
        }

    }
}
