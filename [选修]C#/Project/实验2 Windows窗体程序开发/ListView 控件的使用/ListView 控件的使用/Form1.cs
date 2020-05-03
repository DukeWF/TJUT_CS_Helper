using System;
using System.Windows.Forms;

namespace ListView_控件的使用
{
    public partial class Form1 : Form
    {
        int i;
        string[,] data = { { "20140001", "张三", "天津市西青区宾水西道391号" },
                           { "20140002", "李四", "天津市西青区宾水西道391号" } };
        public void Init_ListView(string [,]data)
        {
            //遍历添加项
            for(i=0;i<data.GetLength(0);i++)
            {
                ListViewItem lv = new ListViewItem();
                lv.Text=Convert.ToString(i+1);
                lv.SubItems.Add(data[i, 0]);
                lv.SubItems.Add(data[i, 1]);
                lv.SubItems.Add(data[i, 2]);
                Main_ListView.Items.Add(lv);
            }
        }
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Init_ListView(data);
        }

        private void Main_ListView_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (Main_ListView.SelectedItems.Count > 0)
            {
                T_SID.Text = Main_ListView.SelectedItems[0].SubItems[1].Text;
                T_Name.Text = Main_ListView.SelectedItems[0].SubItems[2].Text;
                T_Address.Text = Main_ListView.SelectedItems[0].SubItems[3].Text;
            }
        }
    }
}
