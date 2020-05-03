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


namespace 数据库实验
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void show()
        {
            listView1.Clear();
            listView1.Columns.Add("姓名");
            listView1.Columns.Add("学号");
            listView1.Columns.Add("性别");
            listView1.Columns.Add("班级",100);

            String c = "server=RY-PC\\RENYI;database=experiment3;Trusted_Connection=SSPI";
            SqlConnection conn = new SqlConnection(c);
            conn.Open();
            listView1.FullRowSelect = true;
            SqlCommand cmd = conn.CreateCommand();
            cmd.CommandText = "select * from Information";
            SqlDataReader dr = cmd.ExecuteReader();
            while (dr.Read())
            {
                ListViewItem itm = new ListViewItem();
                itm.Text = dr["Sname"].ToString().Trim();

                itm.SubItems.Add(dr["Snumber"].ToString().Trim());
                itm.SubItems.Add(dr["Ssex"].ToString().Trim());
                itm.SubItems.Add(dr["Sclass"].ToString().Trim());

                listView1.Items.Add(itm);
            }

            conn.Close();
        }


        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label6_Click(object sender, EventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {
            string name = textBox1.Text;
            string number = textBox2.Text;
            string sex = textBox3.Text;
            string clas = textBox4.Text;

            String c = "server=RY-PC\\RENYI;database=experiment3;Trusted_Connection=SSPI";
            SqlConnection conn = new SqlConnection(c);
            conn.Open();

            SqlCommand cmd = conn.CreateCommand();
            cmd.CommandText = "update Information set Sname='" + name + "'," +
                "Snumber='" + number + "',Ssex='" + sex + "',Sclass='" + clas + "'" +
                "where Sname='" + name + "'";

            cmd.CommandType = CommandType.Text;
            int i = cmd.ExecuteNonQuery();
            conn.Close();
            show();
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

        private void Form1_Load(object sender, EventArgs e)
        {
            show();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string name = textBox1.Text;
            string number = textBox2.Text;
            string sex = textBox3.Text;
            string clas = textBox4.Text;

            String c = "server=RY-PC\\RENYI;database=experiment3;Trusted_Connection=SSPI";
            SqlConnection conn = new SqlConnection(c);
            conn.Open();
           
            SqlCommand cmd = conn.CreateCommand();
            cmd.CommandText = "insert into Information values('"+name+"','"+number+ "','" + sex + "','" + clas + "')";

            cmd.CommandType = CommandType.Text;
            int i = cmd.ExecuteNonQuery();
            conn.Close();
            show();

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button4_Click(object sender, EventArgs e)
        {
            show();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            String c = "server=RY-PC\\RENYI;database=experiment3;Trusted_Connection=SSPI";
            SqlConnection conn = new SqlConnection(c);
            conn.Open();


            SqlCommand cmd = conn.CreateCommand();
            cmd.CommandText = "delete from Information where Sname= '" + textBox1.Text + "'";

            cmd.CommandType = CommandType.Text;
            int i = cmd.ExecuteNonQuery();

            show();
        }
    }
}
