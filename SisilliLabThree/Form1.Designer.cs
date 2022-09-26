namespace SisilliLabThree
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
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.enterLabel = new System.Windows.Forms.Label();
            this.sendButton = new System.Windows.Forms.Button();
            this.printTextBox = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(283, 65);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(169, 26);
            this.textBox1.TabIndex = 0;
            // 
            // enterLabel
            // 
            this.enterLabel.AutoSize = true;
            this.enterLabel.Location = new System.Drawing.Point(193, 68);
            this.enterLabel.Name = "enterLabel";
            this.enterLabel.Size = new System.Drawing.Size(48, 20);
            this.enterLabel.TabIndex = 1;
            this.enterLabel.Text = "Enter";
            this.enterLabel.Click += new System.EventHandler(this.label1_Click);
            // 
            // sendButton
            // 
            this.sendButton.Location = new System.Drawing.Point(312, 113);
            this.sendButton.Name = "sendButton";
            this.sendButton.Size = new System.Drawing.Size(113, 41);
            this.sendButton.TabIndex = 2;
            this.sendButton.Text = "Send";
            this.sendButton.UseVisualStyleBackColor = true;
            this.sendButton.Click += new System.EventHandler(this.sendButton_Click);
            // 
            // printTextBox
            // 
            this.printTextBox.Location = new System.Drawing.Point(188, 174);
            this.printTextBox.Multiline = true;
            this.printTextBox.Name = "printTextBox";
            this.printTextBox.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.printTextBox.Size = new System.Drawing.Size(372, 216);
            this.printTextBox.TabIndex = 3;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.printTextBox);
            this.Controls.Add(this.sendButton);
            this.Controls.Add(this.enterLabel);
            this.Controls.Add(this.textBox1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Label enterLabel;
        private System.Windows.Forms.Button sendButton;
        private System.Windows.Forms.TextBox printTextBox;
    }
}

