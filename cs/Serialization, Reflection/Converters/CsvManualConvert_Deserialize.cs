using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Reflection;
using System.Text.RegularExpressions;



namespace PVO11_console.Converters
{
    public partial class CsvManualConvert_Serialize
    {
        public static List<object> Deserialize(string inputCsv, Type type)
        {
            // {
            // "FirstName":"Peter",
            // "LastName":"Parker",
            // "Age":16,
            // "IsAvenger":true
            // }

            List<object> result = new List<object>();

            

            PropertyInfo[] propertyInfos = type.GetProperties();

            string[] fields = inputCsv
                .Split('\n');

            string[] propertyNames = fields[0]
                .Split(',');

            for (int i = 1; i < fields.Length; ++i)
            {
                object resultObj = Activator.CreateInstance(type)!;    //for one obj

                string[] values = fields[i].Split(',');
                for(int j = 0; j < propertyNames.Length; ++j)
                {
                    PropertyInfo? propertyInfo = FindProperty(propertyInfos, propertyNames[j]);
                    SetPropertyValue(resultObj, propertyInfo, values[j]);
                }
                
                result.Add(resultObj);
            }
            

            return result;
        }

        private static void SetPropertyValue(object result, PropertyInfo propertyInfo, string valueStr)
        {
            Type propType = propertyInfo.PropertyType;

            object? value;
            if (propType == typeof(string))
            {
                value = valueStr;
            }
            else if (propType == typeof(int))
            {
                value = Convert.ToInt32(valueStr);
            }
            else if (propType == typeof(bool))
            {
                value = Convert.ToBoolean(valueStr);
            }
            else
            {
                throw new ArgumentException($"Type {propType.Name} is not supported");
            }

            propertyInfo.SetValue(result, value);
        }

        private static PropertyInfo FindProperty(PropertyInfo[] propertyInfos, string fieldName)
        {
            PropertyInfo? propertyInfo = propertyInfos
                .Where(p => p.Name == fieldName)
                .FirstOrDefault();

            if (propertyInfo == null)
                throw new ArgumentException($"Object doesn't have '{fieldName}' field");

            return propertyInfo;
        }
    }
}
