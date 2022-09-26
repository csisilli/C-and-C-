using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WhereisMiller
{
    public partial class SqerForm : Form
    {
        public SqerForm()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void sqrtButton_Click(object sender, EventArgs e)
        {
            outputLabel.Text = " ";
            double fromLabel = double.Parse(fromTextBox.Text);
            double toLabel = double.Parse(toTextBox2.Text);
            for(double x= fromLabel; x <= toLabel; x++)
            {

                double sq= Math.Sqrt(x); 

               outputLabel.Text += "Square Root of: "+ x+ " = " +sq + "\n";
                //outputLabel.Text +=  x.ToString() + sq.ToString() + "\n";
            }
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }
    }
}
