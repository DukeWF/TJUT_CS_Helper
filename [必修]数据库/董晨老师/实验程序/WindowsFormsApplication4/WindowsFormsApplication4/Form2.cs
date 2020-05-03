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
    public partial class Form2 : Form
    {
        private String name = null;
        private String sex = null;
        private String age = null;
        private String dept = null;
        public Form2()
        {
            InitializeComponent();
        }
        private bool judge_Empty_Textbox()
        {
            if(textBox1.Text.Trim() == String.Empty || textBox2.Text.Trim() == String.Empty||
                textBox3.Text.Trim() == String.Empty || textBox4.Text.Trim() == String.Empty){
                    return true;
                }
            return false;
        }
        private void clear_TextBox()
        {
            textBox1.Clear();
            textBox2.Clear();
            textBox4.Clear();
            textBox3.Clear();
            
        }
        private void funtion()
        {
            listView1.Clear();
            listView1.Columns.Add("姓名", 80);
            listView1.Columns.Add("性别");
            listView1.Columns.Add("年龄");
            listView1.Columns.Add("系名");

            String c = "server=USER-20160819NQ;database=st;Trusted_Connection=SSPI";

            SqlConnection conn = new SqlConnection(c);

            conn.Open();
            listView1.FullRowSelect = true;
            SqlCommand cmd = conn.CreateCommand();
            cmd.CommandText = "select * from Student";

            SqlDataReader dr = cmd.ExecuteReader();
            while (dr.Read())
            {
                ListViewItem itm = new ListViewItem();
                itm.Text = dr["Sname"].ToString().Trim();

                itm.SubItems.Add(dr["Ssex"].ToString().Trim());
                itm.SubItems.Add(dr["Sage"].ToString().Trim());
                itm.SubItems.Add(dr["Sdept"].ToString().Trim());

                listView1.Items.Add(itm);
            }

            conn.Close();
        }
        private void button1_Click(object sender, EventArgs e)
        {
            funtion();
        }

        private void listView1_SelectedIndexChanged(object sender, EventArgs e)
        {
            foreach (int i in this.listView1.SelectedIndices)
            {
                this.textBox1.Text = this.listView1.Items[i].SubItems[0].Text.ToString();
                this.textBox2.Text = this.listView1.Items[i].SubItems[1].Text.ToString();
                this.textBox3.Text = this.listView1.Items[i].SubItems[2].Text.ToString();
                this.textBox4.Text = this.listView1.Items[i].SubItems[3].Text.ToString();
            }
        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {
            label8.Text = "";
        }

        private void button5_Click(object sender, EventArgs e)
        {
            MessageBox.Show("系统已退出", "提示");
            Application.Exit();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (!judge_Empty_Textbox())
            {

                name = textBox1.Text;
                sex = textBox2.Text;
                age = textBox3.Text;
                dept = textBox4.Text;

                String c = "server=USER-20160819NQ;database=St;Trusted_Connection=SSPI";
                SqlConnection conn = new SqlConnection(c);
                conn.Open();

                SqlCommand com = new SqlCommand();
                com.Connection = conn;

                String str = null;

                str = "select Sname from Student";
                SqlCommand cmd = conn.CreateCommand();
                cmd.CommandText = str;
                SqlDataReader rd = cmd.ExecuteReader();
                rd.Read();
                if (name.Equals(rd["sname"].ToString().Trim()))
                {
                    label5.Text = "姓名与库中姓名一致";
                }
                if (!name.Equals(rd["sname"].ToString().Trim()) && name != String.Empty &&
                    (sex.Equals("男") || sex.Equals("女")) && (Convert.ToInt32(age) > 0 && Convert.ToInt32(age) <= 100))
                {
                    rd.Close();
                    str = "insert into Student values('" + name + "','" + sex + "','" +
                    age + "','" + dept + "')";

                    cmd = new SqlCommand(str, conn);
                    cmd.CommandType = CommandType.Text;

                    int i = cmd.ExecuteNonQuery();
                    MessageBox.Show("插入或修改成功", "提示");
                    clear_TextBox();
                }

                if (!sex.Equals("男") && !sex.Equals("女"))
                {
                    label6.Text = "不存在这类性别";
                }
                if (Convert.ToInt32(age) < 0 || Convert.ToInt32(age) > 100)
                {
                    label7.Text = "年龄超过正常值";
                }
                funtion();
                conn.Close();
            }
            else
            {
                if (textBox1.Text.Trim() == String.Empty)
                {
                    label5.Text = "姓名为空";
                }
                if(textBox2.Text.Trim() == String.Empty)
                {
                    label6.Text = "性别为空";
                }
                if (textBox3.Text.Trim() == String.Empty)
                {
                    label7.Text = "年纪为空";
                }
                if (textBox4.Text.Trim() == String.Empty)
                {
                    label8.Text = "院系为空";
                }
            }
            
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            label6.Text = "";
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            label5.Text = "";
        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {
            label7.Text = "";
        }

        //修改用户
        private void button3_Click(object sender, EventArgs e)
        {
            if (!judge_Empty_Textbox())
            {

                name = textBox1.Text;
                sex = textBox2.Text;
                age = textBox3.Text;
                dept = textBox4.Text;
                String c = "server=USER-20160819NQ;database=St;Trusted_Connection=SSPI";
                SqlConnection conn = new SqlConnection(c);
                conn.Open();

                SqlCommand com = new SqlCommand();
                com.Connection = conn;

                String str = null;

                str = "select Sname from Student";
                SqlCommand cmd = conn.CreateCommand();
                cmd.CommandText = str;
                SqlDataReader rd = cmd.ExecuteReader();
                rd.Read();
                if (!name.Equals(rd["sname"].ToString().Trim()) && name != String.Empty &&
                    (sex.Equals("男") || sex.Equals("女")) && (Convert.ToInt32(age) > 0 && Convert.ToInt32(age) <= 100))
                {
                    button4_Click(sender, e);
                    button2_Click(sender, e);
                    clear_TextBox();
                }
               
                if (!sex.Equals("男") && !sex.Equals("女"))
                {
                    label6.Text = "不存在这类性别";
                }
                if (Convert.ToInt32(age) < 0 || Convert.ToInt32(age) > 100)
                {
                    label7.Text = "年龄超过正常值";
                }
                funtion();
            }
            else
            {
                if (textBox1.Text.Trim() == String.Empty)
                {
                    label5.Text = "姓名为空";
                }
                if (textBox2.Text.Trim() == String.Empty)
                {
                    label6.Text = "性别为空";
                }
                if (textBox3.Text.Trim() == String.Empty)
                {
                    label7.Text = "年纪为空";
                }
                if (textBox4.Text.Trim() == String.Empty)
                {
                    label8.Text = "院系为空";
                }
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            name = textBox1.Text;
            sex = textBox2.Text;
            age = textBox3.Text;
            dept = textBox4.Text;
            String c = "server=USER-20160819NQ;database=St;Trusted_Connection=SSPI";
            SqlConnection conn = new SqlConnection(c);
            conn.Open();

            SqlCommand com = new SqlCommand();
            com.Connection = conn;

            String str = null;
            str = "delete from Student where sname = '" + name+ "'";
            SqlCommand cmd = new SqlCommand(str, conn);

            cmd.CommandType = CommandType.Text;
            int i = cmd.ExecuteNonQuery();
            funtion();
        }

        private void Form2_Load(object sender, EventArgs e)
        {
            funtion();
        }

        private void contextMenuStrip1_Opening(object sender, CancelEventArgs e)
        {

        }
    }
}
