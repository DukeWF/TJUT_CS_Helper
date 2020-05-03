namespace ComboBox_控件的使用
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
            this.ZZMM = new System.Windows.Forms.Label();
            this.V_ZZMM = new System.Windows.Forms.Label();
            this.C_ZZMM = new System.Windows.Forms.ComboBox();
            this.T_ZZMM = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // ZZMM
            // 
            this.ZZMM.AutoSize = true;
            this.ZZMM.Location = new System.Drawing.Point(72, 28);
            this.ZZMM.Name = "ZZMM";
            this.ZZMM.Size = new System.Drawing.Size(53, 12);
            this.ZZMM.TabIndex = 0;
            this.ZZMM.Text = "政治面貌";
            // 
            // V_ZZMM
            // 
            this.V_ZZMM.AutoSize = true;
            this.V_ZZMM.Location = new System.Drawing.Point(12, 63);
            this.V_ZZMM.Name = "V_ZZMM";
            this.V_ZZMM.Size = new System.Drawing.Size(113, 12);
            this.V_ZZMM.TabIndex = 1;
            this.V_ZZMM.Text = "选中的政治面貌的值";
            // 
            // C_ZZMM
            // 
            this.C_ZZMM.FormattingEnabled = true;
            this.C_ZZMM.Location = new System.Drawing.Point(151, 25);
            this.C_ZZMM.Name = "C_ZZMM";
            this.C_ZZMM.Size = new System.Drawing.Size(121, 20);
            this.C_ZZMM.TabIndex = 2;
            this.C_ZZMM.SelectedIndexChanged += new System.EventHandler(this.C_ZZMM_SelectedIndexChanged);
            // 
            // T_ZZMM
            // 
            this.T_ZZMM.Location = new System.Drawing.Point(151, 60);
            this.T_ZZMM.Name = "T_ZZMM";
            this.T_ZZMM.Size = new System.Drawing.Size(121, 21);
            this.T_ZZMM.TabIndex = 3;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(328, 105);
            this.Controls.Add(this.T_ZZMM);
            this.Controls.Add(this.C_ZZMM);
            this.Controls.Add(this.V_ZZMM);
            this.Controls.Add(this.ZZMM);
            this.Name = "Form1";
            this.Text = "ComboBox控件";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label ZZMM;
        private System.Windows.Forms.Label V_ZZMM;
        private System.Windows.Forms.ComboBox C_ZZMM;
        private System.Windows.Forms.TextBox T_ZZMM;
    }
}

