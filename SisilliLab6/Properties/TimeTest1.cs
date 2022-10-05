using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SisilliLab6.Properties
{
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
                string output ="";
                try
                {
                    // String representation of time to output
                    output = "Initial universal time is: " +
                       time.ToUniversalString() +
                       "\nInitial standard time is: " +
                       time.ToStandardString();

                    // attempt valid time settings
                    time.SetTime(13, 27, 6);

                    // String representations of time to output
                    output += "\n\nUniversal time after SetTime is: " +
                       time.ToUniversalString() +
                       "\nStandard time after SetTime is: " +
                       time.ToStandardString();

                    // Invalid time settings
                    time.SetTime(99, 99, 99);

                    output += "\n\nAttempting invalid settings: " +
                       "\nUniversal time: " + time.ToUniversalString() +
                       "\nStandard time: " + time.ToStandardString();


                    // Setting hour, minutes and seconds to make it equal
                    time.Hour = 20;
                    time.Minute = 20;
                    time.Second = 20;
                    output += "\n\nAfter setting hours, minutes, and seconds individually: " +
                       "\nUniversal time: " + time.ToUniversalString() +
                       "\nStandard time: " + time.ToStandardString();




                    // Invalid time settings
                    time.SetTime(99, 99, 99);

                    output += "\n\n Invalid settings: " +
                   "\nUniversal time: " + time.ToUniversalString() +
                   "\nStandard time: " + time.ToStandardString();


                    time.SetTime(11, 20, 31); // Putting the time in
                    time.Hour = 99;
                    time.Minute = 99;
                    time.Second = 99;
                    output += "\n\nThe Invalid hours, minutes, and seconds individually: " +
                       "\nUniversal time: " + time.ToUniversalString() +
                       "\nStandard time: " + time.ToStandardString();
                }
                catch (Exception ex)
                {
                    output += "\n\n Uh oh Exception ";
                    output += ex.Message;
                    Console.WriteLine("Exception has occured " + ex.Message);
                }

                MessageBox.Show(output, "Testing Class Time1");

            } // end method Main

        } // end class TimeTest1
    }
}
