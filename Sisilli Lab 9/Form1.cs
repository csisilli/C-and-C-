using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Sisilli_Lab_9
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        
        private void Form1_Load(object sender, EventArgs e)
        {

        }
        private void findSplit()
        {
            outputText.Text = "";
            string pattern = patternText.Text;
            string strings = stringText.Text;
            string[] args = Regex.Split(strings, pattern);
            for (int i = 0; i < args.Length; i++)
            {
                outputText.Text += ((i + 1) + "  The String is: " + args[i]);
            }
        }
        private void patternText_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter) return;
            findSplit();
        }
        private void stringText_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter) return;
            findSplit();
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }
    }
}
