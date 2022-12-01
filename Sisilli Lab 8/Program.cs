using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Text.RegularExpressions;
//Lab 8
//Name:Caitlin Sisilli

namespace Sisilli_Lab_8
{
    internal class Program
    {
        
        
        static void Main(string[] args)
        {
            SortedDictionary<String,
                             int> words= new SortedDictionary<String,
                                                            int>();
            var str = File.ReadAllText("SisilliLab8.txt");
            var wordFreq = new Regex(@"\w+");
            
            foreach (Match match in wordFreq.Matches(str))
            {
                int currentCount = 0;
                words.TryGetValue(match.Value, out currentCount);

                currentCount++;
                words[match.Value] = currentCount;
            }
            Console.WriteLine(words);
        }
    }
}

    


