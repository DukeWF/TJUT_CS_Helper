using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;
namespace WindowsFormsApplication4
{
    public partial class Form3 : Form
    {
        public Form3()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if(textBox1.Text.Trim() != String.Empty && textBox2.Text.Trim() != String.Empty)
            {
                String c = "server=USER-20160819NQ;database=St;Trusted_Connection=SSPI";
                SqlConnection conn = new SqlConnection(c);
                conn.Open();

                SqlCommand com = new SqlCommand();
                com.Connection = conn;

                String name = null;
                int pwd = 0;

                name = textBox1.Text;
                pwd = Convert.ToInt32(textBox2.Text);

                String str = null;

                str = "insert into Login values('" + name + "'," + pwd + ")";

                SqlCommand cmd = new SqlCommand(str, conn);
                cmd.CommandType = CommandType.Text;

                int i = cmd.ExecuteNonQuery();
                MessageBox.Show("注册成功", "提示");
                this.Hide();

                conn.Close();
            }
            if (textBox1.Text.Trim() == String.Empty)
            {
                label3.Text = "用户不能为空";
            }
            if (textBox2.Text.Trim() == String.Empty)
            {
                label4.Text = "密码不能为空";
            }

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            label3.Text = "";
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            label4.Text = "";
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
