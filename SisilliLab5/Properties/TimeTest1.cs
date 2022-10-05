using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
namespace SisilliLab5.Properties
{
    // TimeTest1 uses creates and uses a Time1 object
    class TimeTest1
    {
        // main entry point for application
        static void Main(string[] args)
        {
            Time1 time = new Time1();  // calls Time1 constructor
            string output;

            // assign string representation of time to output
            output = "Initial universal time is: " +
               time.ToUniversalString() +
               "\nInitial standard time is: " +
               time.ToStandardString();

            // attempt valid time settings
            time.SetTime(13, 27, 6);

            // append new string representations of time to output
            output += "\n\nUniversal time after SetTime: " +
               time.ToUniversalString() +
               "\nStandard time after SetTime is: " +
               time.ToStandardString();


            time.Hour = 20;
            time.Minute = 20;
            time.Second = 20;
            output += "\n\nSetting hours, minutes, and seconds individually: " +
               "\nUniversal time: " + time.ToUniversalString() +
               "\nStandard time: " + time.ToStandardString();

            // attempt invalid time settings
            time.SetTime(99, 99, 99);

            output += "\n\nInvalid settings: " +
               "\nUniversal time: " + time.ToUniversalString() +
               "\nStandard time: " + time.ToStandardString();

            time.SetTime(11, 20, 31); // Putting time first
            time.Hour = 99;
            time.Minute = 99;
            time.Second = 99;
            output += "\n\nInvalid hours, minutes, and seconds individually: " +
               "\nUniversal time: " + time.ToUniversalString() +
               "\nStandard time: " + time.ToStandardString();

            MessageBox.Show(output, "Testing Class Time1");

        } // end method Main

    } // end class TimeTest1
}
