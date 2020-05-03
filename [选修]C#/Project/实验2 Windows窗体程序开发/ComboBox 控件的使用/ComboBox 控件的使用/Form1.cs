using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ComboBox_控件的使用
{
    public partial class Form1 : Form
    {
        string[] data = { "中共党员", "共青团员", "群众", "民主党派", "无党派人士", "其他" };
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            C_ZZMM.Items.AddRange(data);

        }

        private void C_ZZMM_SelectedIndexChanged(object sender, EventArgs e)
        {
            T_ZZMM.Text = C_ZZMM.Text;
        }
    }
}
