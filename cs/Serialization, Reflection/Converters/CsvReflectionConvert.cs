using System;
using System.Reflection;
using System.IO;
using System.Collections.Generic;

namespace PVO11_console.Converters
{
    public class CsvReflectionConvert
    {
        public static void SerializeAndPrint<T>(IEnumerable<T> source)
        {
            Console.WriteLine(Serialize(source));
        }
        public static void SerializeAndWriteFile<T>(IEnumerable<T> source, string filePath)
        {     
            FileInfo fi = new FileInfo(filePath);
            if (!fi.Exists)
            {
                Console.WriteLine("file doesn't exist");
            }
            using (FileStream fs = new FileStream(filePath, FileMode.Truncate))
            {
                string csv = Serialize(source);
                byte[] buffer = new byte[csv.Length];
                for(int i = 0; i < csv.Length; ++i)
                {
                    buffer[i] = (byte)csv[i];
                }
                fs.Write(buffer, 0, csv.Length);
            }
        }
            public static string Serialize<T>(IEnumerable<T> source)
            {
            string result = "";
            bool first = true;
            foreach(T item in source)
            {
                PropertyInfo[] propertyInfos = item.GetType().GetProperties();

                if (first == true)
                {
                    for (int i = 0; i < propertyInfos.Length; i++)
                    {
                        PropertyInfo propInfo = propertyInfos[i];

                        bool hasGetter = propInfo.GetMethod != null;
                        bool isLastProp = i == propertyInfos.Length - 1;

                        if (hasGetter)
                        {
                            //properties
                            result += SerializeProperty(propInfo.Name, isLastProp);
                        }

                    }
                    first = false;
                } 
                
                    for (int i = 0; i < propertyInfos.Length; i++)
                    {
                        PropertyInfo propInfo = propertyInfos[i];

                        bool hasGetter = propInfo.GetMethod != null;
                        bool isLastProp = i == propertyInfos.Length - 1;

                        if (hasGetter)
                        {
                            //values
                            var value = propInfo.GetValue(item);
                            result += SerializePropValue(value, isLastProp);

                        }
                    }
                
                
                result += '\n';
            }
            


            return result.Substring(0,result.Length-1);
        }

        private static string SerializeProperty(string propName, bool isLast = false)
        {
            string propEnding = isLast ? "\n" : ",";
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