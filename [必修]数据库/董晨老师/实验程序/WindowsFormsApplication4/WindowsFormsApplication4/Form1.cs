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
    public partial class 登录 : Form
    {
        public 登录()
        {
            InitializeComponent();
            this.BackgroundImage = Image.FromFile("C:\\Users\\Administrator\\Desktop\\QQ图片20171128231535.jpg");
        }


        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            
            button2.Text = "登录";
            button3.Text = "注册";
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (textBox2.Text.Trim() != String.Empty && textBox3.Text.Trim() != String.Empty)
            {
                String c = "server=USER-20160819NQ;database=st;Trusted_Connection=SSPI";

                SqlConnection conn = new SqlConnection(c);

                conn.Open();

                SqlCommand com = new SqlCommand();
                com.Connection = conn;

                String sql = "select * from Login where username='" + textBox2.Text + "'and pwd='" + textBox3.Text + "'";

                SqlCommand cmd = new SqlCommand(sql, conn);

                cmd.CommandType = CommandType.Text;
                SqlDataReader sdr;
                sdr = cmd.ExecuteReader();

                if (sdr.Read())
                {
                    Form2 form = new Form2();
                    form.Show();
                    this.Hide();
                    label1.Text = "登录成功";
                }
                else
                {
                    label1.Text = "用户名或密码错误";
                }
            }
            if (textBox2.Text.Trim() == String.Empty)
            {
                label4.Text = "用户名不能为空";
            }
            if (textBox3.Text.Trim() == String.Empty)
            {
                label5.Text = "密码不能为空";
            }
            
        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {
            new Form3().Show();
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            label4.Text = "";
            label5.Text = "";
            label1.Text = "";
        }
    }
}
