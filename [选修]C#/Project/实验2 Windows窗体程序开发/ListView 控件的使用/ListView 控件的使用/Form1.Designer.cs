namespace ListView_控件的使用
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
            this.Main_ListView = new System.Windows.Forms.ListView();
            this.ID = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.SID = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.SName = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.SAddress = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.L_SID = new System.Windows.Forms.Label();
            this.L_Address = new System.Windows.Forms.Label();
            this.L_Name = new System.Windows.Forms.Label();
            this.T_SID = new System.Windows.Forms.TextBox();
            this.T_Name = new System.Windows.Forms.TextBox();
            this.T_Address = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // Main_ListView
            // 
            this.Main_ListView.CheckBoxes = true;
            this.Main_ListView.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.ID,
            this.SID,
            this.SName,
            this.SAddress});
            this.Main_ListView.FullRowSelect = true;
            this.Main_ListView.LabelEdit = true;
            this.Main_ListView.Location = new System.Drawing.Point(19, 100);
            this.Main_ListView.Margin = new System.Windows.Forms.Padding(4);
            this.Main_ListView.MultiSelect = false;
            this.Main_ListView.Name = "Main_ListView";
            this.Main_ListView.Size = new System.Drawing.Size(511, 239);
            this.Main_ListView.TabIndex = 0;
            this.Main_ListView.UseCompatibleStateImageBehavior = false;
            this.Main_ListView.View = System.Windows.Forms.View.Details;
            this.Main_ListView.SelectedIndexChanged += new System.EventHandler(this.Main_ListView_SelectedIndexChanged);
            // 
            // ID
            // 
            this.ID.Text = "序号";
            this.ID.Width = 40;
            // 
            // SID
            // 
            this.SID.Text = "学号";
            this.SID.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // SName
            // 
            this.SName.Text = "姓名";
            this.SName.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.SName.Width = 80;
            // 
            // SAddress
            // 
            this.SAddress.Text = "地址";
            this.SAddress.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.SAddress.Width = 180;
            // 
            // L_SID
            // 
            this.L_SID.AutoSize = true;
            this.L_SID.Location = new System.Drawing.Point(16, 16);
            this.L_SID.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.L_SID.Name = "L_SID";
            this.L_SID.Size = new System.Drawing.Size(37, 15);
            this.L_SID.TabIndex = 1;
            this.L_SID.Text = "学号";
            // 
            // L_Address
            // 
            this.L_Address.AutoSize = true;
            this.L_Address.Location = new System.Drawing.Point(16, 56);
            this.L_Address.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.L_Address.Name = "L_Address";
            this.L_Address.Size = new System.Drawing.Size(37, 15);
            this.L_Address.TabIndex = 2;
            this.L_Address.Text = "地址";
            // 
            // L_Name
            // 
            this.L_Name.AutoSize = true;
            this.L_Name.Location = new System.Drawing.Point(287, 16);
            this.L_Name.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.L_Name.Name = "L_Name";
            this.L_Name.Size = new System.Drawing.Size(37, 15);
            this.L_Name.TabIndex = 3;
            this.L_Name.Text = "姓名";
            // 
            // T_SID
            // 
            this.T_SID.Location = new System.Drawing.Point(79, 13);
            this.T_SID.Margin = new System.Windows.Forms.Padding(4);
            this.T_SID.Name = "T_SID";
            this.T_SID.Size = new System.Drawing.Size(169, 25);
            this.T_SID.TabIndex = 4;
            // 
            // T_Name
            // 
            this.T_Name.Location = new System.Drawing.Point(350, 13);
            this.T_Name.Margin = new System.Windows.Forms.Padding(4);
            this.T_Name.Name = "T_Name";
            this.T_Name.Size = new System.Drawing.Size(180, 25);
            this.T_Name.TabIndex = 5;
            // 
            // T_Address
            // 
            this.T_Address.Location = new System.Drawing.Point(79, 53);
            this.T_Address.Margin = new System.Windows.Forms.Padding(4);
            this.T_Address.Name = "T_Address";
            this.T_Address.Size = new System.Drawing.Size(451, 25);
            this.T_Address.TabIndex = 6;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(549, 356);
            this.Controls.Add(this.T_Address);
            this.Controls.Add(this.T_Name);
            this.Controls.Add(this.T_SID);
            this.Controls.Add(this.L_Name);
            this.Controls.Add(this.L_Address);
            this.Controls.Add(this.L_SID);
            this.Controls.Add(this.Main_ListView);
            this.Margin = new System.Windows.Forms.Padding(4);
            this.Name = "Form1";
            this.Text = "ListView控件的使用";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListView Main_ListView;
        private System.Windows.Forms.Label L_SID;
        private System.Windows.Forms.Label L_Address;
        private System.Windows.Forms.Label L_Name;
        private System.Windows.Forms.TextBox T_SID;
        private System.Windows.Forms.TextBox T_Name;
        private System.Windows.Forms.TextBox T_Address;
        private System.Windows.Forms.ColumnHeader ID;
        private System.Windows.Forms.ColumnHeader SID;
        private System.Windows.Forms.ColumnHeader SName;
        private System.Windows.Forms.ColumnHeader SAddress;
    }
}

