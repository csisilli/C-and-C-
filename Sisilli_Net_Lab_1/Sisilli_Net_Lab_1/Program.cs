using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
namespace Sisilli_Net_Lab_1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            double total = 0;
            
            Console.WriteLine("Please Enter Ten Numbers ");
            for (int count =0; count <= 10; count++)
            {
                Console.Write("Enter a number: ");
                // num = double.Parse(Console.ReadLine());
                double num;
                while (!double.TryParse(Console.ReadLine(), out num))
                {
                    MessageBox.Show("Bad Value, Enter number again: ");    
                }
                total += num;
                double average;
                average = total / count;
                if (average > 0)
                {
                    Console.WriteLine("The Average is: ", average);
                }
            }
           
            

        }
    }
}
