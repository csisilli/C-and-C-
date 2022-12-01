using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace Sisilli_Lab_10
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int content= args.Length;
            if (content == 0)
            {
                Console.WriteLine("No FileName Found");
                return;
            }
            Process[] proces = new Process[content];
            for(int i = 0; i<content; i++)
            {
                proces[i] = new Process();
                proces[i].StartInfo.FileName = args[i];
                proces[i].Start();
            }
            while (true)
            {
                proces[0].WaitForExit(1000);
                for(int i = 0; i < content; i++)
                {
                    if (proces[i].HasExited)
                    {
                        proces[i].Start();
                    }
                }
            }
        }
    }
}
