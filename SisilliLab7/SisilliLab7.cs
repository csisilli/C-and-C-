using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
using System.Threading.Tasks;
using System.Globalization;

namespace SisilliLab7
{
    internal class SisilliLab7
    {
        static void DirectoryFiles(string directName, ref DateTime dateTime)
        {
            string[] fileList;
           fileList =Directory.GetFiles(directName);
            for(int i=0; i<fileList.Length; i++)
            {
                DateTime dateFile= Directory.GetLastWriteTime(fileList[i]);
                if (DateTime.Compare(dateFile, dateTime) >=0)
                {
                    Console.WriteLine(fileList[i]); 
                }
            }

            string[] directlist;
            directlist = Directory.GetDirectories(directName);
            for (int i = 0; i < directlist.Length; i++)
            {
                DirectoryFiles(directlist[i], ref dateTime);
            }
        }
        static void Main(string[] args)
        {
            string directName = args[0];
            string form = "d";
            CultureInfo cultureInfo = CultureInfo.InvariantCulture;
            DateTime dateTime = DateTime.ParseExact(args[1],form,cultureInfo);
            if (!Directory.Exists(directName))
            {
                Console.WriteLine("Error this Directory does not exist");
                Console.Read();
                return;
            }
            Console.WriteLine("Directory is:");
            DirectoryFiles(directName,ref dateTime);
            Console.Read();
            
        }
    }
}
