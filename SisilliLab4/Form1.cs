using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SisilliLab4
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void rollDice_Click(object sender, EventArgs e)
        {
            //random rolls
            Random roll =new Random();
            int[] amount = new int[13];
            
            //set up the paramters, roll for 100,000. Dice is from 2s-12s
            for(int i=0;i<100000; i++)
            {
                amount[roll.Next(1, 13)]++;
            }
            for(int i = 2; i <= 12; i++)
            {
                resultTextbox.Text += "Number of " + i +"'s and : " + amount[i] +System.Environment.NewLine;
            }
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }
    }
}
