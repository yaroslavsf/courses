using System;
using System.IO;
using System.Collections.Generic;
namespace test_cs
{
    class Finder
    {
        private string filePath;
        private int readingChunk;
        private List<string> words = new List<string>();
        private List<int> wordsCounter = new List<int>();
        public Finder(string fp, int rChunk)
        {
            filePath = fp;
            readingChunk = rChunk;
        }
        public int checkBuffer(byte[] buffer)
        {
            int i = readingChunk - 1;
            while ((char)buffer[i] != ',')
            {
                i--;
            }
            return i + 1;
        }
        public void AddWords(List<string> tWords)
        {
            foreach(string some in tWords)
            {
                words.Add(some);
            }
            for (int i = 0; i < words.Count; i++)
            {
                wordsCounter.Add(0);
            }
        }
        public void Info()
        {
            for (int x = 0; x < words.Count; x++)
            {
                Console.WriteLine($"{words[x]} : {wordsCounter[x]}");
            }
        }
        public void FindWords()
        {           
            Console.WriteLine(Directory.GetCurrentDirectory());
            FileInfo fi = new FileInfo(filePath);
            if (!fi.Exists)
            {
                Console.WriteLine("file not exists");
            }
            using (FileStream fs = new FileStream(filePath, FileMode.Open))
            {
                long sizeCounter = 0;
                long sizeCounterBuff = 0;
                byte[] buffer = new byte[readingChunk];
                string myBuf = "";
                while (sizeCounter < fi.Length)
                {
                    //check buffer
                    fs.Seek(sizeCounter, SeekOrigin.Begin);
                    fs.Read(buffer);
                    sizeCounterBuff = checkBuffer(buffer);

                    for (int i = 0; i < sizeCounterBuff; i++)
                    {
                        if (sizeCounter + sizeCounterBuff > fi.Length)
                        {
                            sizeCounterBuff = fi.Length - sizeCounter;
                        }
                        if ((char)buffer[i] == ',' || i + 1 == sizeCounterBuff)
                        {
                            for (int x = 0; x < words.Count; x++)
                            {
                                if (words[x] == myBuf)
                                {
                                    wordsCounter[x]++;
                                }
                            }
                            myBuf = "";
                        }
                        else
                        {
                            myBuf += (char)buffer[i];
                        }
                    }
                    sizeCounter += sizeCounterBuff;
                }
               
            }
        }
    }
    
    class Program
    {

        static void Main(string[] args)
        {
            //here you can manipulate the size of reading chunk(2nd param)
            Finder r = new Finder("input.txt", 500);

            List<string> words = new List<string> { "aab", "bbq", "max", "po", "p" };
            r.AddWords(words);
            r.FindWords();
            r.Info();
        }
    }
}
