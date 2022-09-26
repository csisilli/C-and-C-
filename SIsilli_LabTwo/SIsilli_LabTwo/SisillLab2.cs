using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SIsilli_LabTwo
{
    internal class SisillLab2
    {
        static void Main(string[] args)
        {
            double min = 0;
            double max = 2;
            double x = 0;
            x = (min + max) / 2;
            
            double y = System.Math.Pow(min, 3) - 2;
            double z = System.Math.Pow(x, 3) - 2;
            if(y <0 && 0 < z)
            {
                max = min;
            }
            else
            {
                min = max;
            }
            Console.WriteLine("The half-interval: " + x);
            Console.WriteLine("The cube root of the equation: " + System.Math.Pow(2, (double)1 / 3));
            Console.Read();
        }
    }
}
