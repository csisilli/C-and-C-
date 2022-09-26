namespace WhereisMiller
{
    partial class SqerForm
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
            this.sqrtButton = new System.Windows.Forms.Button();
            this.outputLabel = new System.Windows.Forms.Label();
            this.fromLabel = new System.Windows.Forms.Label();
            this.toLabel = new System.Windows.Forms.Label();
            this.fromTextBox = new System.Windows.Forms.TextBox();
            this.toTextBox2 = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // sqrtButton
            // 
            this.sqrtButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F);
            this.sqrtButton.Location = new System.Drawing.Point(253, 50);
            this.sqrtButton.Name = "sqrtButton";
            this.sqrtButton.Size = new System.Drawing.Size(250, 61);
            this.sqrtButton.TabIndex = 0;
            this.sqrtButton.Text = "Compute Square Roots";
            this.sqrtButton.UseVisualStyleBackColor = true;
            this.sqrtButton.Click += new System.EventHandler(this.sqrtButton_Click);
            // 
            // outputLabel
            // 
            this.outputLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 11F);
            this.outputLabel.Location = new System.Drawing.Point(172, 137);
            this.outputLabel.Name = "outputLabel";
            this.outputLabel.Size = new System.Drawing.Size(400, 250);
            this.outputLabel.TabIndex = 1;
            // 
            // fromLabel
            // 
            this.fromLabel.AutoSize = true;
            this.fromLabel.Location = new System.Drawing.Point(192, 124);
            this.fromLabel.Name = "fromLabel";
            this.fromLabel.Size = new System.Drawing.Size(50, 20);
            this.fromLabel.TabIndex = 2;
            this.fromLabel.Text = "From:";
            this.fromLabel.Click += new System.EventHandler(this.label1_Click);
            // 
            // toLabel
            // 
            this.toLabel.AutoSize = true;
            this.toLabel.Location = new System.Drawing.Point(451, 124);
            this.toLabel.Name = "toLabel";
            this.toLabel.Size = new System.Drawing.Size(31, 20);
            this.toLabel.TabIndex = 3;
            this.toLabel.Text = "To:";
            // 
            // fromTextBox
            // 
            this.fromTextBox.Location = new System.Drawing.Point(282, 124);
            this.fromTextBox.Name = "fromTextBox";
            this.fromTextBox.Size = new System.Drawing.Size(100, 26);
            this.fromTextBox.TabIndex = 4;
            // 
            // toTextBox2
            // 
            this.toTextBox2.Location = new System.Drawing.Point(507, 124);
            this.toTextBox2.Name = "toTextBox2";
            this.toTextBox2.Size = new System.Drawing.Size(100, 26);
            this.toTextBox2.TabIndex = 5;
            // 
            // SqerForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.toTextBox2);
            this.Controls.Add(this.fromTextBox);
            this.Controls.Add(this.toLabel);
            this.Controls.Add(this.fromLabel);
            this.Controls.Add(this.outputLabel);
            this.Controls.Add(this.sqrtButton);
            this.Name = "SqerForm";
            this.Text = "Square Root Calculator";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button sqrtButton;
        private System.Windows.Forms.Label outputLabel;
        private System.Windows.Forms.Label fromLabel;
        private System.Windows.Forms.Label toLabel;
        private System.Windows.Forms.TextBox fromTextBox;
        private System.Windows.Forms.TextBox toTextBox2;
    }
}

