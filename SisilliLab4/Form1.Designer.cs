namespace SisilliLab4
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.rollDice = new System.Windows.Forms.Button();
            this.resultTextbox = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // rollDice
            // 
            this.rollDice.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.rollDice.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.rollDice.Location = new System.Drawing.Point(309, 29);
            this.rollDice.Name = "rollDice";
            this.rollDice.Size = new System.Drawing.Size(127, 52);
            this.rollDice.TabIndex = 0;
            this.rollDice.Text = "Roll";
            this.rollDice.UseVisualStyleBackColor = false;
            this.rollDice.Click += new System.EventHandler(this.rollDice_Click);
            // 
            // resultTextbox
            // 
            this.resultTextbox.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.resultTextbox.Location = new System.Drawing.Point(150, 131);
            this.resultTextbox.Multiline = true;
            this.resultTextbox.Name = "resultTextbox";
            this.resultTextbox.ReadOnly = true;
            this.resultTextbox.Size = new System.Drawing.Size(452, 294);
            this.resultTextbox.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.label1.Location = new System.Drawing.Point(157, 108);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(264, 20);
            this.label1.TabIndex = 2;
            this.label1.Text = "The Result of 100,000 Dice Rolls is: ";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.resultTextbox);
            this.Controls.Add(this.rollDice);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button rollDice;
        private System.Windows.Forms.TextBox resultTextbox;
        private System.Windows.Forms.Label label1;
    }
}

