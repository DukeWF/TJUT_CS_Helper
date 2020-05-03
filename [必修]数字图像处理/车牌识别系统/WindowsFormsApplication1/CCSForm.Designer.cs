namespace WindowsFormsApplication1
{
    partial class CCSForm
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
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(CCSForm));
            this.toolTip1 = new System.Windows.Forms.ToolTip(this.components);
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.GraphyPanel = new System.Windows.Forms.Panel();
            this.pictureBox2 = new System.Windows.Forms.PictureBox();
            this.label1 = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.panel1 = new System.Windows.Forms.Panel();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.panel2 = new System.Windows.Forms.Panel();
            this.ResultLabel = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.groupBox5 = new System.Windows.Forms.GroupBox();
            this.pictureBox11 = new System.Windows.Forms.PictureBox();
            this.pictureBox10 = new System.Windows.Forms.PictureBox();
            this.pictureBox9 = new System.Windows.Forms.PictureBox();
            this.pictureBox8 = new System.Windows.Forms.PictureBox();
            this.pictureBox7 = new System.Windows.Forms.PictureBox();
            this.pictureBox6 = new System.Windows.Forms.PictureBox();
            this.pictureBox5 = new System.Windows.Forms.PictureBox();
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.文件ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.打开ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.重载ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.保存ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.退出ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.图片预处理ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.灰度化ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.灰度均衡化ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.均值滤波ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.定位处理ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.sobel边缘检测ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.车牌定位ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.车牌处理ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.灰度化ToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.二值化ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.精确定位ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.字符分割ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.车牌识别ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.帮助ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.文档ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.关于ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.ExtractPanel = new System.Windows.Forms.Panel();
            this.pictureBox4 = new System.Windows.Forms.PictureBox();
            this.LocatedPanel = new System.Windows.Forms.Panel();
            this.pictureBox3 = new System.Windows.Forms.PictureBox();
            this.toolStripStatusLabel = new System.Windows.Forms.ToolStripStatusLabel();
            this.groupBox4.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.GraphyPanel.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).BeginInit();
            this.groupBox1.SuspendLayout();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.panel2.SuspendLayout();
            this.groupBox5.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox11)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox10)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox9)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox8)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox7)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox6)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox5)).BeginInit();
            this.statusStrip1.SuspendLayout();
            this.menuStrip1.SuspendLayout();
            this.ExtractPanel.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox4)).BeginInit();
            this.LocatedPanel.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox3)).BeginInit();
            this.SuspendLayout();
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.ExtractPanel);
            this.groupBox4.Font = new System.Drawing.Font("微软雅黑", 9F);
            this.groupBox4.Location = new System.Drawing.Point(707, 585);
            this.groupBox4.Margin = new System.Windows.Forms.Padding(4);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Padding = new System.Windows.Forms.Padding(4);
            this.groupBox4.Size = new System.Drawing.Size(250, 102);
            this.groupBox4.TabIndex = 17;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "车牌精确定位";
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.LocatedPanel);
            this.groupBox3.Font = new System.Drawing.Font("微软雅黑", 9F);
            this.groupBox3.Location = new System.Drawing.Point(447, 585);
            this.groupBox3.Margin = new System.Windows.Forms.Padding(4);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Padding = new System.Windows.Forms.Padding(4);
            this.groupBox3.Size = new System.Drawing.Size(250, 102);
            this.groupBox3.TabIndex = 16;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "车牌定位";
            // 
            // groupBox2
            // 
            this.groupBox2.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.groupBox2.Controls.Add(this.GraphyPanel);
            this.groupBox2.Font = new System.Drawing.Font("微软雅黑", 9F);
            this.groupBox2.ForeColor = System.Drawing.Color.Black;
            this.groupBox2.Location = new System.Drawing.Point(730, 28);
            this.groupBox2.Margin = new System.Windows.Forms.Padding(4);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Padding = new System.Windows.Forms.Padding(4);
            this.groupBox2.Size = new System.Drawing.Size(575, 540);
            this.groupBox2.TabIndex = 15;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "车牌直方图";
            // 
            // GraphyPanel
            // 
            this.GraphyPanel.BackColor = System.Drawing.SystemColors.Control;
            this.GraphyPanel.Controls.Add(this.pictureBox2);
            this.GraphyPanel.Location = new System.Drawing.Point(8, 18);
            this.GraphyPanel.Margin = new System.Windows.Forms.Padding(4);
            this.GraphyPanel.Name = "GraphyPanel";
            this.GraphyPanel.Size = new System.Drawing.Size(559, 514);
            this.GraphyPanel.TabIndex = 0;
            // 
            // pictureBox2
            // 
            this.pictureBox2.Location = new System.Drawing.Point(4, 4);
            this.pictureBox2.Margin = new System.Windows.Forms.Padding(4);
            this.pictureBox2.Name = "pictureBox2";
            this.pictureBox2.Size = new System.Drawing.Size(551, 506);
            this.pictureBox2.TabIndex = 0;
            this.pictureBox2.TabStop = false;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(236, 424);
            this.label1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(0, 15);
            this.label1.TabIndex = 14;
            // 
            // groupBox1
            // 
            this.groupBox1.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.groupBox1.Controls.Add(this.panel1);
            this.groupBox1.Font = new System.Drawing.Font("微软雅黑", 9F);
            this.groupBox1.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.groupBox1.Location = new System.Drawing.Point(17, 28);
            this.groupBox1.Margin = new System.Windows.Forms.Padding(4);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Padding = new System.Windows.Forms.Padding(4);
            this.groupBox1.Size = new System.Drawing.Size(680, 540);
            this.groupBox1.TabIndex = 13;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "车牌图片";
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.SystemColors.Control;
            this.panel1.Controls.Add(this.pictureBox1);
            this.panel1.Location = new System.Drawing.Point(8, 18);
            this.panel1.Margin = new System.Windows.Forms.Padding(4);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(664, 514);
            this.panel1.TabIndex = 0;
            // 
            // pictureBox1
            // 
            this.pictureBox1.Location = new System.Drawing.Point(4, 4);
            this.pictureBox1.Margin = new System.Windows.Forms.Padding(4);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(660, 510);
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            // 
            // panel2
            // 
            this.panel2.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel2.Controls.Add(this.ResultLabel);
            this.panel2.Controls.Add(this.label2);
            this.panel2.Font = new System.Drawing.Font("宋体", 10.5F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.panel2.Location = new System.Drawing.Point(17, 585);
            this.panel2.Margin = new System.Windows.Forms.Padding(4);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(422, 102);
            this.panel2.TabIndex = 20;
            // 
            // ResultLabel
            // 
            this.ResultLabel.AutoSize = true;
            this.ResultLabel.ForeColor = System.Drawing.SystemColors.ControlText;
            this.ResultLabel.Location = new System.Drawing.Point(80, 55);
            this.ResultLabel.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.ResultLabel.Name = "ResultLabel";
            this.ResultLabel.Size = new System.Drawing.Size(0, 18);
            this.ResultLabel.TabIndex = 1;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.label2.Font = new System.Drawing.Font("微软雅黑", 9F);
            this.label2.ForeColor = System.Drawing.SystemColors.ControlText;
            this.label2.Location = new System.Drawing.Point(15, 18);
            this.label2.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(88, 20);
            this.label2.TabIndex = 0;
            this.label2.Text = "车牌号码为:";
            // 
            // groupBox5
            // 
            this.groupBox5.Controls.Add(this.pictureBox11);
            this.groupBox5.Controls.Add(this.pictureBox10);
            this.groupBox5.Controls.Add(this.pictureBox9);
            this.groupBox5.Controls.Add(this.pictureBox8);
            this.groupBox5.Controls.Add(this.pictureBox7);
            this.groupBox5.Controls.Add(this.pictureBox6);
            this.groupBox5.Controls.Add(this.pictureBox5);
            this.groupBox5.Font = new System.Drawing.Font("微软雅黑", 9F);
            this.groupBox5.Location = new System.Drawing.Point(970, 585);
            this.groupBox5.Margin = new System.Windows.Forms.Padding(4);
            this.groupBox5.Name = "groupBox5";
            this.groupBox5.Padding = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.groupBox5.Size = new System.Drawing.Size(332, 102);
            this.groupBox5.TabIndex = 18;
            this.groupBox5.TabStop = false;
            this.groupBox5.Text = "单个字符提取";
            // 
            // pictureBox11
            // 
            this.pictureBox11.Location = new System.Drawing.Point(256, 41);
            this.pictureBox11.Margin = new System.Windows.Forms.Padding(4);
            this.pictureBox11.Name = "pictureBox11";
            this.pictureBox11.Size = new System.Drawing.Size(31, 44);
            this.pictureBox11.TabIndex = 0;
            this.pictureBox11.TabStop = false;
            // 
            // pictureBox10
            // 
            this.pictureBox10.Location = new System.Drawing.Point(221, 41);
            this.pictureBox10.Margin = new System.Windows.Forms.Padding(4);
            this.pictureBox10.Name = "pictureBox10";
            this.pictureBox10.Size = new System.Drawing.Size(27, 44);
            this.pictureBox10.TabIndex = 0;
            this.pictureBox10.TabStop = false;
            // 
            // pictureBox9
            // 
            this.pictureBox9.Location = new System.Drawing.Point(185, 41);
            this.pictureBox9.Margin = new System.Windows.Forms.Padding(4);
            this.pictureBox9.Name = "pictureBox9";
            this.pictureBox9.Size = new System.Drawing.Size(28, 44);
            this.pictureBox9.TabIndex = 0;
            this.pictureBox9.TabStop = false;
            // 
            // pictureBox8
            // 
            this.pictureBox8.Location = new System.Drawing.Point(148, 41);
            this.pictureBox8.Margin = new System.Windows.Forms.Padding(4);
            this.pictureBox8.Name = "pictureBox8";
            this.pictureBox8.Size = new System.Drawing.Size(29, 44);
            this.pictureBox8.TabIndex = 0;
            this.pictureBox8.TabStop = false;
            // 
            // pictureBox7
            // 
            this.pictureBox7.Location = new System.Drawing.Point(115, 41);
            this.pictureBox7.Margin = new System.Windows.Forms.Padding(4);
            this.pictureBox7.Name = "pictureBox7";
            this.pictureBox7.Size = new System.Drawing.Size(25, 44);
            this.pictureBox7.TabIndex = 0;
            this.pictureBox7.TabStop = false;
            // 
            // pictureBox6
            // 
            this.pictureBox6.Location = new System.Drawing.Point(77, 41);
            this.pictureBox6.Margin = new System.Windows.Forms.Padding(4);
            this.pictureBox6.Name = "pictureBox6";
            this.pictureBox6.Size = new System.Drawing.Size(29, 44);
            this.pictureBox6.TabIndex = 0;
            this.pictureBox6.TabStop = false;
            // 
            // pictureBox5
            // 
            this.pictureBox5.Location = new System.Drawing.Point(39, 41);
            this.pictureBox5.Margin = new System.Windows.Forms.Padding(4);
            this.pictureBox5.Name = "pictureBox5";
            this.pictureBox5.Size = new System.Drawing.Size(31, 44);
            this.pictureBox5.TabIndex = 0;
            this.pictureBox5.TabStop = false;
            // 
            // statusStrip1
            // 
            this.statusStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripStatusLabel});
            this.statusStrip1.Location = new System.Drawing.Point(0, 695);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Size = new System.Drawing.Size(1318, 26);
            this.statusStrip1.TabIndex = 21;
            this.statusStrip1.Text = "statusStrip1";
            // 
            // menuStrip1
            // 
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.文件ToolStripMenuItem,
            this.图片预处理ToolStripMenuItem,
            this.定位处理ToolStripMenuItem,
            this.车牌处理ToolStripMenuItem,
            this.车牌识别ToolStripMenuItem,
            this.帮助ToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(1318, 28);
            this.menuStrip1.TabIndex = 22;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // 文件ToolStripMenuItem
            // 
            this.文件ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.打开ToolStripMenuItem,
            this.重载ToolStripMenuItem,
            this.保存ToolStripMenuItem,
            this.退出ToolStripMenuItem});
            this.文件ToolStripMenuItem.ForeColor = System.Drawing.SystemColors.Desktop;
            this.文件ToolStripMenuItem.Name = "文件ToolStripMenuItem";
            this.文件ToolStripMenuItem.Size = new System.Drawing.Size(89, 24);
            this.文件ToolStripMenuItem.Text = "文件（&F）";
            // 
            // 打开ToolStripMenuItem
            // 
            this.打开ToolStripMenuItem.Name = "打开ToolStripMenuItem";
            this.打开ToolStripMenuItem.Size = new System.Drawing.Size(216, 26);
            this.打开ToolStripMenuItem.Text = "打开";
            this.打开ToolStripMenuItem.Click += new System.EventHandler(this.打开ToolStripMenuItem_Click);
            // 
            // 重载ToolStripMenuItem
            // 
            this.重载ToolStripMenuItem.Name = "重载ToolStripMenuItem";
            this.重载ToolStripMenuItem.Size = new System.Drawing.Size(216, 26);
            this.重载ToolStripMenuItem.Text = "重置";
            this.重载ToolStripMenuItem.Click += new System.EventHandler(this.重载ToolStripMenuItem_Click);
            // 
            // 保存ToolStripMenuItem
            // 
            this.保存ToolStripMenuItem.Name = "保存ToolStripMenuItem";
            this.保存ToolStripMenuItem.Size = new System.Drawing.Size(216, 26);
            this.保存ToolStripMenuItem.Text = "保存";
            this.保存ToolStripMenuItem.Click += new System.EventHandler(this.保存ToolStripMenuItem_Click);
            // 
            // 退出ToolStripMenuItem
            // 
            this.退出ToolStripMenuItem.Name = "退出ToolStripMenuItem";
            this.退出ToolStripMenuItem.Size = new System.Drawing.Size(216, 26);
            this.退出ToolStripMenuItem.Text = "退出";
            this.退出ToolStripMenuItem.Click += new System.EventHandler(this.退出ToolStripMenuItem_Click);
            // 
            // 图片预处理ToolStripMenuItem
            // 
            this.图片预处理ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.灰度化ToolStripMenuItem,
            this.灰度均衡化ToolStripMenuItem,
            this.均值滤波ToolStripMenuItem});
            this.图片预处理ToolStripMenuItem.ForeColor = System.Drawing.SystemColors.Desktop;
            this.图片预处理ToolStripMenuItem.Name = "图片预处理ToolStripMenuItem";
            this.图片预处理ToolStripMenuItem.Size = new System.Drawing.Size(135, 24);
            this.图片预处理ToolStripMenuItem.Text = "图片预处理（&P）";
            // 
            // 灰度化ToolStripMenuItem
            // 
            this.灰度化ToolStripMenuItem.Name = "灰度化ToolStripMenuItem";
            this.灰度化ToolStripMenuItem.Size = new System.Drawing.Size(216, 26);
            this.灰度化ToolStripMenuItem.Text = "灰度化";
            this.灰度化ToolStripMenuItem.Click += new System.EventHandler(this.灰度化ToolStripMenuItem_Click);
            // 
            // 灰度均衡化ToolStripMenuItem
            // 
            this.灰度均衡化ToolStripMenuItem.Name = "灰度均衡化ToolStripMenuItem";
            this.灰度均衡化ToolStripMenuItem.Size = new System.Drawing.Size(216, 26);
            this.灰度均衡化ToolStripMenuItem.Text = "灰度均衡化";
            this.灰度均衡化ToolStripMenuItem.Click += new System.EventHandler(this.灰度均衡化ToolStripMenuItem_Click);
            // 
            // 均值滤波ToolStripMenuItem
            // 
            this.均值滤波ToolStripMenuItem.Name = "均值滤波ToolStripMenuItem";
            this.均值滤波ToolStripMenuItem.Size = new System.Drawing.Size(216, 26);
            this.均值滤波ToolStripMenuItem.Text = "均值滤波";
            this.均值滤波ToolStripMenuItem.Click += new System.EventHandler(this.均值滤波ToolStripMenuItem_Click);
            // 
            // 定位处理ToolStripMenuItem
            // 
            this.定位处理ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.sobel边缘检测ToolStripMenuItem,
            this.车牌定位ToolStripMenuItem});
            this.定位处理ToolStripMenuItem.ForeColor = System.Drawing.SystemColors.Desktop;
            this.定位处理ToolStripMenuItem.Name = "定位处理ToolStripMenuItem";
            this.定位处理ToolStripMenuItem.Size = new System.Drawing.Size(122, 24);
            this.定位处理ToolStripMenuItem.Text = "定位处理（&D）";
            // 
            // sobel边缘检测ToolStripMenuItem
            // 
            this.sobel边缘检测ToolStripMenuItem.Name = "sobel边缘检测ToolStripMenuItem";
            this.sobel边缘检测ToolStripMenuItem.Size = new System.Drawing.Size(216, 26);
            this.sobel边缘检测ToolStripMenuItem.Text = "Sobel边缘检测";
            this.sobel边缘检测ToolStripMenuItem.Click += new System.EventHandler(this.sobel边缘检测ToolStripMenuItem_Click);
            // 
            // 车牌定位ToolStripMenuItem
            // 
            this.车牌定位ToolStripMenuItem.Name = "车牌定位ToolStripMenuItem";
            this.车牌定位ToolStripMenuItem.Size = new System.Drawing.Size(216, 26);
            this.车牌定位ToolStripMenuItem.Text = "车牌定位";
            this.车牌定位ToolStripMenuItem.Click += new System.EventHandler(this.车牌定位ToolStripMenuItem_Click);
            // 
            // 车牌处理ToolStripMenuItem
            // 
            this.车牌处理ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.灰度化ToolStripMenuItem1,
            this.二值化ToolStripMenuItem,
            this.精确定位ToolStripMenuItem,
            this.字符分割ToolStripMenuItem});
            this.车牌处理ToolStripMenuItem.ForeColor = System.Drawing.SystemColors.Desktop;
            this.车牌处理ToolStripMenuItem.Name = "车牌处理ToolStripMenuItem";
            this.车牌处理ToolStripMenuItem.Size = new System.Drawing.Size(123, 24);
            this.车牌处理ToolStripMenuItem.Text = "车牌处理（&H）";
            // 
            // 灰度化ToolStripMenuItem1
            // 
            this.灰度化ToolStripMenuItem1.Name = "灰度化ToolStripMenuItem1";
            this.灰度化ToolStripMenuItem1.Size = new System.Drawing.Size(216, 26);
            this.灰度化ToolStripMenuItem1.Text = "灰度化";
            this.灰度化ToolStripMenuItem1.Click += new System.EventHandler(this.车牌灰度化ToolStripMenuItem_Click);
            // 
            // 二值化ToolStripMenuItem
            // 
            this.二值化ToolStripMenuItem.Name = "二值化ToolStripMenuItem";
            this.二值化ToolStripMenuItem.Size = new System.Drawing.Size(216, 26);
            this.二值化ToolStripMenuItem.Text = "二值化";
            this.二值化ToolStripMenuItem.Click += new System.EventHandler(this.车牌二值化ToolStripMenuItem_Click);
            // 
            // 精确定位ToolStripMenuItem
            // 
            this.精确定位ToolStripMenuItem.Name = "精确定位ToolStripMenuItem";
            this.精确定位ToolStripMenuItem.Size = new System.Drawing.Size(216, 26);
            this.精确定位ToolStripMenuItem.Text = "精确定位";
            this.精确定位ToolStripMenuItem.Click += new System.EventHandler(this.精确定位ToolStripMenuItem_Click);
            // 
            // 字符分割ToolStripMenuItem
            // 
            this.字符分割ToolStripMenuItem.Name = "字符分割ToolStripMenuItem";
            this.字符分割ToolStripMenuItem.Size = new System.Drawing.Size(216, 26);
            this.字符分割ToolStripMenuItem.Text = "字符分割";
            this.字符分割ToolStripMenuItem.Click += new System.EventHandler(this.字符分割ToolStripMenuItem_Click);
            // 
            // 车牌识别ToolStripMenuItem
            // 
            this.车牌识别ToolStripMenuItem.ForeColor = System.Drawing.SystemColors.Desktop;
            this.车牌识别ToolStripMenuItem.Name = "车牌识别ToolStripMenuItem";
            this.车牌识别ToolStripMenuItem.Size = new System.Drawing.Size(122, 24);
            this.车牌识别ToolStripMenuItem.Text = "车牌识别（&G）";
            this.车牌识别ToolStripMenuItem.Click += new System.EventHandler(this.车牌识别ToolStripMenuItem_Click);
            // 
            // 帮助ToolStripMenuItem
            // 
            this.帮助ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.文档ToolStripMenuItem,
            this.关于ToolStripMenuItem});
            this.帮助ToolStripMenuItem.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.帮助ToolStripMenuItem.Name = "帮助ToolStripMenuItem";
            this.帮助ToolStripMenuItem.Size = new System.Drawing.Size(93, 24);
            this.帮助ToolStripMenuItem.Text = "帮助（&H）";
            // 
            // 文档ToolStripMenuItem
            // 
            this.文档ToolStripMenuItem.Enabled = false;
            this.文档ToolStripMenuItem.Name = "文档ToolStripMenuItem";
            this.文档ToolStripMenuItem.Size = new System.Drawing.Size(216, 26);
            this.文档ToolStripMenuItem.Text = "帮助文档";
            // 
            // 关于ToolStripMenuItem
            // 
            this.关于ToolStripMenuItem.Name = "关于ToolStripMenuItem";
            this.关于ToolStripMenuItem.Size = new System.Drawing.Size(216, 26);
            this.关于ToolStripMenuItem.Text = "关于";
            this.关于ToolStripMenuItem.Click += new System.EventHandler(this.关于ToolStripMenuItem_Click);
            // 
            // ExtractPanel
            // 
            this.ExtractPanel.Controls.Add(this.pictureBox4);
            this.ExtractPanel.Location = new System.Drawing.Point(8, 19);
            this.ExtractPanel.Margin = new System.Windows.Forms.Padding(4);
            this.ExtractPanel.Name = "ExtractPanel";
            this.ExtractPanel.Size = new System.Drawing.Size(234, 76);
            this.ExtractPanel.TabIndex = 0;
            // 
            // pictureBox4
            // 
            this.pictureBox4.Location = new System.Drawing.Point(4, 4);
            this.pictureBox4.Margin = new System.Windows.Forms.Padding(4);
            this.pictureBox4.Name = "pictureBox4";
            this.pictureBox4.Size = new System.Drawing.Size(230, 72);
            this.pictureBox4.TabIndex = 0;
            this.pictureBox4.TabStop = false;
            // 
            // LocatedPanel
            // 
            this.LocatedPanel.Controls.Add(this.pictureBox3);
            this.LocatedPanel.Location = new System.Drawing.Point(8, 19);
            this.LocatedPanel.Margin = new System.Windows.Forms.Padding(4);
            this.LocatedPanel.Name = "LocatedPanel";
            this.LocatedPanel.Size = new System.Drawing.Size(236, 76);
            this.LocatedPanel.TabIndex = 0;
            // 
            // pictureBox3
            // 
            this.pictureBox3.Location = new System.Drawing.Point(0, 0);
            this.pictureBox3.Margin = new System.Windows.Forms.Padding(4);
            this.pictureBox3.Name = "pictureBox3";
            this.pictureBox3.Size = new System.Drawing.Size(234, 76);
            this.pictureBox3.TabIndex = 0;
            this.pictureBox3.TabStop = false;
            // 
            // toolStripStatusLabel
            // 
            this.toolStripStatusLabel.ForeColor = System.Drawing.SystemColors.Desktop;
            this.toolStripStatusLabel.Image = ((System.Drawing.Image)(resources.GetObject("toolStripStatusLabel.Image")));
            this.toolStripStatusLabel.LinkColor = System.Drawing.Color.Black;
            this.toolStripStatusLabel.Margin = new System.Windows.Forms.Padding(10, 3, 10, 3);
            this.toolStripStatusLabel.Name = "toolStripStatusLabel";
            this.toolStripStatusLabel.Size = new System.Drawing.Size(89, 20);
            this.toolStripStatusLabel.Text = "处理进度";
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1318, 721);
            this.Controls.Add(this.statusStrip1);
            this.Controls.Add(this.menuStrip1);
            this.Controls.Add(this.panel2);
            this.Controls.Add(this.groupBox5);
            this.Controls.Add(this.groupBox4);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.groupBox1);
            this.ForeColor = System.Drawing.SystemColors.GradientActiveCaption;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MainMenuStrip = this.menuStrip1;
            this.Margin = new System.Windows.Forms.Padding(4);
            this.Name = "MainForm";
            this.Text = "车牌识别系统";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.MainForm_FormClosing);
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.MainForm_FormClosed);
            this.groupBox4.ResumeLayout(false);
            this.groupBox3.ResumeLayout(false);
            this.groupBox2.ResumeLayout(false);
            this.GraphyPanel.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).EndInit();
            this.groupBox1.ResumeLayout(false);
            this.panel1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            this.groupBox5.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox11)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox10)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox9)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox8)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox7)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox6)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox5)).EndInit();
            this.statusStrip1.ResumeLayout(false);
            this.statusStrip1.PerformLayout();
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ExtractPanel.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox4)).EndInit();
            this.LocatedPanel.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox3)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ToolTip toolTip1;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Panel GraphyPanel;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.PictureBox pictureBox2;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.Label ResultLabel;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.GroupBox groupBox5;
        private System.Windows.Forms.PictureBox pictureBox11;
        private System.Windows.Forms.PictureBox pictureBox10;
        private System.Windows.Forms.PictureBox pictureBox9;
        private System.Windows.Forms.PictureBox pictureBox8;
        private System.Windows.Forms.PictureBox pictureBox7;
        private System.Windows.Forms.PictureBox pictureBox6;
        private System.Windows.Forms.PictureBox pictureBox5;
        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem 文件ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 打开ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 重载ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 保存ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 退出ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 图片预处理ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 灰度化ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 灰度均衡化ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 均值滤波ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 定位处理ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem sobel边缘检测ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 车牌定位ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 车牌处理ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 灰度化ToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem 二值化ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 精确定位ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 字符分割ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 车牌识别ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 帮助ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 文档ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 关于ToolStripMenuItem;
        private System.Windows.Forms.Panel ExtractPanel;
        private System.Windows.Forms.PictureBox pictureBox4;
        private System.Windows.Forms.Panel LocatedPanel;
        private System.Windows.Forms.PictureBox pictureBox3;
        private System.Windows.Forms.ToolStripStatusLabel toolStripStatusLabel;
    }
}