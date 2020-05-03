using System;
using System.Drawing;
using System.IO;

using System.Drawing.Imaging;
using System.Windows.Forms;
namespace WindowsFormsApplication1
{
    public partial class CCSForm : Form
    {
        private Bitmap m_Bitmap;//测试图片
        private Bitmap c_Bitmap;//车牌图像
        private Bitmap objNewPic;

        int[] gray = new int[256];
        private Bitmap[] charFont;
        private Bitmap[] provinceFont;
        string[] charString;//数字字母存储的路径
        string[] provinceString;//省份存储的路径
        string[] charDigitalString;
        string[] provinceDigitalString;

        private Bitmap[] array_Bitmap = new Bitmap[7];//最终黑白字体图片
        private String name;
        
        int flag = 0;
        public static string charSourceBath = "E:\\platenum_distinguish\\车牌字符模板\\char\\";
        public static string provinceSourceBath = "E:\\platenum_distinguish\\车牌字符模板\\font\\";

        public CCSForm()
        {
            InitializeComponent();
        }
      
        //灰度直方图调用
        private void graydo()
        {
            switch (flag)
            {
                case 1:
                    {
                        pictureBox2.Refresh();
                        Bitmap bitmap = new Bitmap(pictureBox1.Image);
                        int[] hist = getHist(bitmap, bitmap.Width, bitmap.Height);
                        Graphics g = pictureBox2.CreateGraphics();
                        g.Clear(this.BackColor);
                        Pen pen = new Pen(Color.Red);
                        int max = hist[0];
                        for (int i = 0; i < bitmap.Width; i++)
                            if (max < hist[i])
                                max = hist[i];
                        for (int i = 0; i < bitmap.Width; i++)
                            hist[i] = hist[i] * 250 / max;
                        pen.Color = Color.Red;
                        for (int i = 0; i < bitmap.Width; i++)
                            g.DrawLine(pen, i, 255, i, 255 - hist[i]);
                        break;
                    }

                case 2:
                    {
                        pictureBox2.Refresh();
                        Bitmap bitmap = new Bitmap(pictureBox3.Image);
                        int[] hist = getHist(bitmap, bitmap.Width, bitmap.Height);
                        Graphics g = pictureBox2.CreateGraphics();
                        g.Clear(this.BackColor);
                        Pen pen = new Pen(Color.Red);
                        int max = hist[0];
                        for (int i = 0; i < bitmap.Width; i++)
                            if (max < hist[i])
                                max = hist[i];
                        for (int i = 0; i < bitmap.Width; i++)
                            hist[i] = hist[i] * 250 / max;
                        pen.Color = Color.Red;
                        for (int i = 0; i < bitmap.Width; i++)
                            g.DrawLine(pen, i, 255, i, 255 - hist[i]);
                        break;
                    }
                default:
                    break;

            }
        }

        //车辆图片处理方法
        public int[] getHist(Bitmap bm, int w, int h)
        {
            int[] hist = new int[500];
            for (int j = 0; j < h; j++)
            {
                for (int i = 0; i < w; i++)
                {
                    int grey = (bm.GetPixel(i, j)).R;
                    hist[grey]++;
                }
            }
            return hist;
        }

        //定位处理方法
        public int[,] edgeDetect(int[,] ing, int[,] tmp, int w, int h)
        {
            int[,] edge = new int[w, h];
            for (int j = 1; j < h - 1; j++)
            {
                for (int i = 1; i < w - 1; i++)
                {
                    edge[i, j] = Math.Abs(tmp[0, 0] * ing[i - 1, j - 1] +
                        tmp[0, 1] * ing[i - 1, j] +
                        tmp[0, 2] * ing[i - 1, j + 1] +
                        tmp[1, 0] * ing[i, j - 1] +
                        tmp[1, 1] * ing[i, j] +
                        tmp[1, 2] * ing[i, j + 1] +
                        tmp[2, 0] * ing[i + 1, j - 1] +
                        tmp[2, 1] * ing[i + 1, j] +
                        tmp[2, 2] * ing[i + 1, j + 1]);
                }
            }
            return edge;
        }
        //计算数组中的最大值索引
        private int maxNumber(int[] num)
        {
            int maxIndex = 0;
            int maxNum = 0;
            for (int i = 0; i < num.Length; i++)
            {
                if (maxNum < num[i])
                {
                    maxNum = num[i];
                    maxIndex = i;
                }
            }
            return maxIndex;
        }

        //车牌识别方法
        public int TransformFiles(string path)
        {
            DirectoryInfo dir = new DirectoryInfo(path);
            FileInfo[] files = dir.GetFiles("*.bmp");

            int j = 0;
            if (path.Equals(charSourceBath))
            {
                this.charString = new string[86];
                this.charDigitalString = new string[86];
                try
                {
                    foreach (FileInfo f in files)
                    {
                        charString[j] = (dir + f.ToString());
                        charDigitalString[j] = Path.GetFileNameWithoutExtension(charString[j]);
                        j++;
                    }
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message.ToString());
                }
            }
            else
            {
                provinceString = new string[22];
                provinceDigitalString = new string[22];

                try
                {
                    foreach (FileInfo f in files)
                    {
                        provinceString[j] = (dir + f.ToString());
                        provinceDigitalString[j] = Path.GetFileNameWithoutExtension(provinceString[j]);
                        j++;
                    }
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message.ToString());
                }
            }
            return j;
        }
        //计算数组中的最小值索引
        private int minNumber(int[] num)
        {
            int minIndex = 0;
            int minNum = 1000;
            for (int i = 0; i < num.Length; i++)
            {
                if (minNum > num[i])
                {
                    minNum = num[i];
                    minIndex = i;
                }
            }
            return minIndex;
        }

        private void 打开ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                OpenFileDialog openFileDialog = new OpenFileDialog();
                openFileDialog.Filter = "JPG文件(*.jpg)|*.jpg|位图文件(*.bmp)|*.bmp| 所有文件(*.bmp/*.jpg)|*.bmp/*.jpg";
                openFileDialog.FilterIndex = 2;
                openFileDialog.RestoreDirectory = true;//该值指示对话框在关闭前是否还原当前目录

                if (openFileDialog.ShowDialog() == DialogResult.OK)
                {
                    name = openFileDialog.FileName;
                    m_Bitmap = (Bitmap)Image.FromFile(name);
                    //this.always_Bitmap = m_Bitmap.Clone(new Rectangle(0, 0, m_Bitmap.Width, m_Bitmap.Height), PixelFormat.DontCare);
                    pictureBox1.Image = m_Bitmap;
                }
                openFileDialog.Dispose();
                flag = 1;
                graydo();
            }
            catch(Exception ex)
            {
                MessageBox.Show(ex.Message, "错误提示", MessageBoxButtons.OK, MessageBoxIcon.Stop);
            }
        }
        private void 重载ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                if (name != null)
                {
                    m_Bitmap = (Bitmap)Bitmap.FromFile(name, false);
                    pictureBox1.Image = m_Bitmap;
                }
                graydo();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "错误提示", MessageBoxButtons.OK, MessageBoxIcon.Stop);
            }
        }
        private void 保存ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                SaveFileDialog saveFileDialog = new SaveFileDialog();
                saveFileDialog.Filter = "Bitmap文件(*.bmp)|*.bmp| Jpeg文件(*.jpg)|*.jpg| 所有合适文件(*.bmp/*.jpg)|*.bmp/*.jpg";
                saveFileDialog.FilterIndex = 1;
                saveFileDialog.RestoreDirectory = true;
                if (saveFileDialog.ShowDialog() == DialogResult.OK)
                {
                    string fileName = saveFileDialog.FileName;
                    string strFilExtn = fileName.Remove(0, fileName.Length - 3);
                    pictureBox1.Image.Save(fileName);
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "错误提示", MessageBoxButtons.OK, MessageBoxIcon.Stop);
            }
        }
        private void 退出ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
        private void 灰度化ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                if (m_Bitmap != null)
                {
                    Bitmap bitmap = new Bitmap(pictureBox1.Image);
                    Color curColor;
                    int ret;
                    for (int i = 0; i < m_Bitmap.Width; i++)
                    {
                        for (int j = 0; j < m_Bitmap.Height; j++)
                        {
                            curColor = m_Bitmap.GetPixel(i, j);
                            ret = (int)(curColor.R * 0.299 + curColor.G * 0.587 + curColor.B * 0.114);
                            bitmap.SetPixel(i, j, Color.FromArgb(ret, ret, ret));
                        }
                    }
                    pictureBox1.Image = bitmap;
                    Invalidate();
                }
                flag = 1;
                graydo();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "错误提示", MessageBoxButtons.OK, MessageBoxIcon.Stop);
            }
        }
        private void 灰度均衡化ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                Bitmap curBitmap = (Bitmap)pictureBox1.Image.Clone();
                if (curBitmap != null)
                {
                    Bitmap bitmap = new Bitmap(pictureBox1.Image);
                    int[] hist = getHist(curBitmap, curBitmap.Width, curBitmap.Height);
                    Color color = new Color();
                    double p = (double)255 / (curBitmap.Width * curBitmap.Height);
                    double[] sum = new double[256];
                    int[] outg = new int[256];
                    sum[0] = hist[0];
                    for (int i = 1; i < 256; i++)
                        sum[i] = sum[i - 1] + hist[i];
                    for (int i = 0; i < 256; i++)
                        outg[i] = (int)(p * sum[i]);
                    for (int j = 0; j < curBitmap.Height; j++)
                    {
                        for (int i = 0; i < curBitmap.Width; i++)
                        {
                            int g = (curBitmap.GetPixel(i, j).R);
                            color = Color.FromArgb(outg[g], outg[g], outg[g]);
                            bitmap.SetPixel(i, j, color);
                        }
                    }
                    pictureBox1.Image = bitmap;
                }
                flag = 1;
                graydo();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "错误提示", MessageBoxButtons.OK, MessageBoxIcon.Stop);
            }
        }
        private void 均值滤波ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                Bitmap curBitmap = (Bitmap)pictureBox1.Image.Clone();
                if (curBitmap != null)
                {
                    Bitmap bitmap = new Bitmap(pictureBox1.Image);
                    for (int j = 0; j < curBitmap.Height; j++)
                    {
                        for (int i = 0; i < curBitmap.Width; i++)
                        {
                            int sum = 0;
                            for (int k = -1; k <= 1; k++)
                                for (int m = -1; m <= 1; m++)
                                    if ((i + k) > 0 && (i + k) < curBitmap.Width && (j + m) > 0 && (j + m) < curBitmap.Height)
                                        sum += (curBitmap.GetPixel(i + k, j + m)).R;
                            int avrage = (int)(sum / 9.0);
                            bitmap.SetPixel(i, j, Color.FromArgb(avrage, avrage, avrage));
                        }
                    }
                    pictureBox1.Image = bitmap;
                }
                flag = 1;
                graydo();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "错误提示", MessageBoxButtons.OK, MessageBoxIcon.Stop);
            }
        }
        private void sobel边缘检测ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                if (m_Bitmap != null)
                {
                    Bitmap bitmap = new Bitmap(pictureBox1.Image);
                    Color color = new Color();
                    int r;
                    int w = m_Bitmap.Width;
                    int h = m_Bitmap.Height;
                    int[,] inred = new int[w, h];
                    int[,] ingreen = new int[w, h];
                    int[,] inblue = new int[w, h];
                    int[,] ingray = new int[w, h];
                    for (int i = 0; i < w; i++)
                    {
                        for (int j = 0; j < h; j++)
                        {
                            color = m_Bitmap.GetPixel(i, j);
                            inred[i, j] = color.R;
                            ingreen[i, j] = color.G;
                            inblue[i, j] = color.B;
                            ingray[i, j] = (int)((color.R + color.G + color.B) / 3.0);
                        }
                    }
                    int[,] sobel1 = { { -1, 0, 1 }, { -2, 0, 2 }, { -1, 0, 1 } };
                    int[,] sobel2 = { { 1, 2, 1 }, { 0, 0, 0 }, { -1, -2, -1 } };
                    int[,] edge1 = edgeDetect(ingray, sobel1, w, h);
                    int[,] edge2 = edgeDetect(ingray, sobel2, w, h);
                    for (int j = 0; j < h; j++)
                    {
                        for (int i = 0; i < w; i++)
                        {
                            if (Math.Max(edge1[i, j], edge2[i, j]) > 200)
                                r = 255;
                            else
                                r = 0;
                            color = Color.FromArgb(r, r, r);
                            bitmap.SetPixel(i, j, color);
                        }
                    }
                    pictureBox1.Image = bitmap;
                }
                flag = 1;
                graydo();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "错误提示", MessageBoxButtons.OK, MessageBoxIcon.Stop);
            }
        }
        private void 车牌定位ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                Bitmap bitmap = (Bitmap)pictureBox1.Image.Clone();
                int height = bitmap.Height;
                int width = bitmap.Width;
                //定义上下左右边界
                int up = 0, down = 0, right = 0, left = 0;
                //定义车牌的高和宽
                int h, w;
                int[] array = new int[height];
                Color color1 = new Color();
                Color color2 = new Color();
                int number = 0, m = 0;
                if (bitmap != null)
                {
                    //逐行自下而上扫描像素0、1跳变数
                    for (int i = height; i > 0; i--)
                    {
                        for (int j = 0; j < width - 1; j++)
                        {
                            color1 = bitmap.GetPixel(j, i - 1);
                            color2 = bitmap.GetPixel(j + 1, i - 1);
                            if (Math.Abs(color1.R - color2.R) > 200)
                                array[i - 1]++;
                        }
                    }
                    //水平定位
                    for (int i = height - 1; i > 0; i--)
                    {
                        if (array[i] > 16)
                        {
                            if (m == 1)
                                number++;
                            if (m == 0)
                            {
                                m = 1;
                                number++;
                            }
                        }
                        if (array[i] <= 16)
                        {
                            if (m == 1)
                            {
                                m = 0;
                                if (number > 15)
                                {
                                    up = i;
                                    down = i + number + 3;
                                }
                            }
                        }
                        if (up != 0)
                            break;
                    }

                    //垂直定位
                    h = down - up;
                    w = (int)(3.8 * h);
                    int[] arraylist = new int[width - w];
                    for (int i = 0; i < width - w; i++)
                    {
                        for (int j = 0; j < h; j++)
                        {
                            for (int k = 0; k < w - 1; k++)
                            {
                                color1 = bitmap.GetPixel(k + i, j + up);
                                color2 = bitmap.GetPixel(k + i + 1, j + up);
                                if (Math.Abs(color1.R - color2.R) > 200)
                                    arraylist[i]++;
                            }
                        }
                    }
                    int max = this.maxNumber(arraylist);
                    left = max;
                    right = max + w;
                    Rectangle sourceRectangle = new Rectangle(left, up, w, h);
                    c_Bitmap = m_Bitmap.Clone(sourceRectangle,
                        PixelFormat.DontCare);
                    pictureBox3.Image = c_Bitmap;
                    Graphics g = pictureBox1.CreateGraphics();
                    Pen pen = new Pen(Color.Red);
                    g.DrawImage(bitmap, 0, 0, m_Bitmap.Width, m_Bitmap.Height);
                    g.DrawLine(pen, left, up, right, up);
                    g.DrawLine(pen, left, down, right, down);
                    g.DrawLine(pen, left, up, left, down);
                    g.DrawLine(pen, right, up, right, down);
                    flag = 2;
                    graydo();
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "错误提示", MessageBoxButtons.OK, MessageBoxIcon.Stop);
            }
        }
        private void 车牌灰度化ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                Bitmap curBitmap = (Bitmap)pictureBox3.Image.Clone();
                if (curBitmap != null)
                {
                    Color curColor;
                    int ret;
                    for (int i = 0; i < curBitmap.Width; i++)
                    {
                        for (int j = 0; j < curBitmap.Height; j++)
                        {
                            curColor = curBitmap.GetPixel(i, j);
                            ret = (int)(curColor.R * 0.299 + curColor.G * 0.587 + curColor.B * 0.114);
                            curBitmap.SetPixel(i, j, Color.FromArgb(ret, ret, ret));
                        }
                    }
                    pictureBox3.Image = curBitmap;
                    Invalidate();
                }
                flag = 2;
                graydo();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "错误提示", MessageBoxButtons.OK, MessageBoxIcon.Stop);
            }
        }
        private void 车牌二值化ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                Bitmap curBitmap = (Bitmap)pictureBox3.Image.Clone();
                if (curBitmap != null)
                {
                    for (int j = 1; j < curBitmap.Height - 1; j++)
                    {
                        for (int i = 1; i < curBitmap.Width - 1; i++)
                        {
                            int r;
                            if (curBitmap.GetPixel(i, j).R > 130)
                                r = 255;
                            else
                                r = 0;
                            curBitmap.SetPixel(i, j, Color.FromArgb(r, r, r));
                        }
                    }
                    pictureBox3.Image = curBitmap;
                }
                flag = 2;
                graydo();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "错误提示", MessageBoxButtons.OK, MessageBoxIcon.Stop);
            }
        }
        private void 精确定位ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                if (c_Bitmap != null)
                {
                    Bitmap bitmap = new Bitmap(pictureBox3.Image);
                    Color color = new Color();
                    int r;
                    int w = c_Bitmap.Width;
                    int h = c_Bitmap.Height;
                    int[,] inred = new int[w, h];
                    int[,] ingreen = new int[w, h];
                    int[,] inblue = new int[w, h];
                    int[,] ingray = new int[w, h];
                    for (int i = 0; i < w; i++)
                    {
                        for (int j = 0; j < h; j++)
                        {
                            color = c_Bitmap.GetPixel(i, j);
                            inred[i, j] = color.R;
                            ingreen[i, j] = color.G;
                            inblue[i, j] = color.B;
                            ingray[i, j] = (int)((color.R + color.G + color.B) / 3.0);
                        }
                    }
                    int[,] sobel1 = { { -1, 0, 1 }, { -2, 0, 2 }, { -1, 0, 1 } };
                    int[,] sobel2 = { { 1, 2, 1 }, { 0, 0, 0 }, { -1, -2, -1 } };
                    int[,] edge1 = edgeDetect(ingray, sobel1, w, h);
                    int[,] edge2 = edgeDetect(ingray, sobel2, w, h);
                    for (int j = 0; j < h; j++)
                    {
                        for (int i = 0; i < w; i++)
                        {
                            if (Math.Max(edge1[i, j], edge2[i, j]) > 200)
                                r = 255;
                            else
                                r = 0;
                            color = Color.FromArgb(r, r, r);
                            bitmap.SetPixel(i, j, color);
                        }
                    }

                    int cwidth = bitmap.Width;
                    int cheight = bitmap.Height;
                    int Height = cheight, Bottom = 0;
                    int Lleft = 0, Lright = 0;
                    int[] countx = new int[cheight];
                    int[] county = new int[cwidth];
                    //水平扫描像素值
                    for (int j = 0; j < cheight; j++)
                    {
                        for (int i = 0; i < cwidth - 1; i++)
                        {
                            color = bitmap.GetPixel(i, j);
                            if (color.R > 200)
                                countx[j]++;
                        }
                    }

                    //计算车牌号的上边缘
                    for (int y = cheight / 2; y > 0; y--)
                    {
                        if (countx[y] >= 30 && countx[(y + 1) % cheight] >= 28)
                            if (Height > y)
                                Height = y;
                    }

                    //计算车牌号的下边缘
                    for (int y = cheight / 2; y < cheight; y++)
                    {
                        if (countx[y] >= 30 && countx[(y + 1) % cheight] >= 28)
                            if (Bottom < y)
                                Bottom = y;
                    }

                    //垂直扫描像素值
                    for (int i = 0; i < cwidth; i++)
                    {
                        for (int j = 0; j < cheight - 1; j++)
                        {
                            color = bitmap.GetPixel(i, j);
                            if (color.R == 255)
                                county[i]++;
                        }
                    }

                    //计算车牌号的左边缘
                    for (int y = 0; y < cwidth; y++)
                    {
                        if (county[y] > 12)
                        {
                            Lleft = y + 2;
                            break;
                        }
                    }
                    //计算车牌号的右边缘
                    for (int y = cwidth - 1; y > 0; y--)
                    {
                        if (county[y] > 12)
                        {
                            Lright = y;
                            break;
                        }
                    }
                    Rectangle sourceRectangle = new Rectangle(Lleft, Height, Lright - Lleft, Bottom - Height);
                    Bitmap curBitmap = (Bitmap)pictureBox3.Image.Clone();
                    curBitmap = curBitmap.Clone(sourceRectangle, PixelFormat.DontCare);
                    pictureBox4.Image = curBitmap;
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "错误提示", MessageBoxButtons.OK, MessageBoxIcon.Stop);
            }
        }
        private void 字符分割ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                Bitmap curBitmap = (Bitmap)pictureBox4.Image.Clone();
                if (curBitmap != null)
                {
                    int cwidth = curBitmap.Width;
                    int cheight = curBitmap.Height;
                    Color color = new Color();
                    int[] county = new int[cwidth];
                    int[] array = new int[50];
                    int flag2 = 0;
                    int n = 0;
                    for (int i = 0; i < cwidth; i++)
                    {
                        for (int j = 0; j < cheight - 1; j++)
                        {
                            color = curBitmap.GetPixel(i, j);
                            if (color.R == 255)
                                county[i]++;
                        }
                    }
                    for (int i = 1; i < cwidth; i++)
                    {
                        if (county[i] > 2)
                        {
                            if (flag2 == 0)
                            {
                                array[n] = i;
                                n++;
                                flag2 = 1;
                            }
                        }
                        else
                        {
                            if (flag2 == 1)
                            {
                                array[n] = i;
                                n++;
                                flag2 = 0;
                            }
                        }
                    }
                    Graphics g = pictureBox4.CreateGraphics();
                    Pen pen = new Pen(Color.Red);
                    g.DrawImage(curBitmap, 0, 0, curBitmap.Width, curBitmap.Height);
                    g.DrawLine(pen, array[0], 0, array[0], cheight);
                    g.DrawLine(pen, array[1], 0, array[1], cheight);
                    g.DrawLine(pen, array[2], 0, array[2], cheight);
                    g.DrawLine(pen, array[3], 0, array[3], cheight);
                    g.DrawLine(pen, array[4], 0, array[4], cheight);
                    g.DrawLine(pen, array[5], 0, array[5], cheight);
                    g.DrawLine(pen, array[6], 0, array[6], cheight);
                    g.DrawLine(pen, array[7], 0, array[7], cheight);
                    g.DrawLine(pen, array[8], 0, array[8], cheight);
                    g.DrawLine(pen, array[9], 0, array[9], cheight);
                    g.DrawLine(pen, array[10], 0, array[10], cheight);
                    g.DrawLine(pen, array[11], 0, array[11], cheight);
                    g.DrawLine(pen, array[12], 0, array[12], cheight);
                    g.DrawLine(pen, array[13], 0, array[13], cheight);

                    Rectangle sourceRectangle0 = new Rectangle(array[0], 0, array[1] - array[0], cheight);
                    array_Bitmap[0] = curBitmap.Clone(sourceRectangle0, PixelFormat.DontCare);
                    pictureBox5.Image = array_Bitmap[0];
                    objNewPic = new System.Drawing.Bitmap(array_Bitmap[0], 9, 16);
                    array_Bitmap[0] = objNewPic;
                    objNewPic.Save("E:\\0.bmp");
                    objNewPic = null;

                    Rectangle sourceRectangle1 = new Rectangle(array[2], 0, array[3] - array[2], cheight);
                    array_Bitmap[1] = curBitmap.Clone(sourceRectangle1, PixelFormat.DontCare);
                    pictureBox6.Image = array_Bitmap[1];
                    objNewPic = new System.Drawing.Bitmap(array_Bitmap[1], 9, 16);
                    array_Bitmap[1] = objNewPic;
                    objNewPic.Save("E:\\1.bmp");
                    objNewPic = null;

                    Rectangle sourceRectangle2 = new Rectangle(array[4], 0, array[5] - array[4], cheight);
                    array_Bitmap[2] = curBitmap.Clone(sourceRectangle2, PixelFormat.DontCare);
                    pictureBox7.Image = array_Bitmap[2];
                    objNewPic = new System.Drawing.Bitmap(array_Bitmap[2], 9, 16);
                    array_Bitmap[2] = objNewPic;
                    objNewPic.Save("E:\\2.bmp");
                    objNewPic = null;

                    Rectangle sourceRectangle3 = new Rectangle(array[6], 0, array[7] - array[6], cheight);
                    array_Bitmap[3] = curBitmap.Clone(sourceRectangle3, PixelFormat.DontCare);
                    pictureBox8.Image = array_Bitmap[3];
                    objNewPic = new System.Drawing.Bitmap(array_Bitmap[3], 9, 16);
                    array_Bitmap[3] = objNewPic;
                    objNewPic.Save("E:\\3.bmp");
                    objNewPic = null;

                    Rectangle sourceRectangle4 = new Rectangle(array[8], 0, array[9] - array[8], cheight);
                    array_Bitmap[4] = curBitmap.Clone(sourceRectangle4, PixelFormat.DontCare);
                    pictureBox9.Image = array_Bitmap[4];
                    objNewPic = new System.Drawing.Bitmap(array_Bitmap[4], 9, 16);
                    array_Bitmap[4] = objNewPic;
                    objNewPic.Save("E:\\4.bmp");
                    objNewPic = null;

                    Rectangle sourceRectangle5 = new Rectangle(array[10], 0, array[11] - array[10], cheight);
                    array_Bitmap[5] = curBitmap.Clone(sourceRectangle5, PixelFormat.DontCare);
                    pictureBox10.Image = array_Bitmap[5];
                    objNewPic = new System.Drawing.Bitmap(array_Bitmap[5], 9, 16);
                    array_Bitmap[5] = objNewPic;
                    objNewPic.Save("E:\\5.bmp");
                    objNewPic = null;

                    Rectangle sourceRectangle6 = new Rectangle(array[12], 0, array[13] - array[12], cheight);
                    array_Bitmap[6] = curBitmap.Clone(sourceRectangle6, PixelFormat.DontCare);
                    pictureBox11.Image = array_Bitmap[6];
                    objNewPic = new System.Drawing.Bitmap(array_Bitmap[6], 9, 16);
                    array_Bitmap[6] = objNewPic;
                    objNewPic.Save("E:\\6.bmp");
                    objNewPic = null;
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "错误提示", MessageBoxButtons.OK, MessageBoxIcon.Stop);
            }
        }
        private void 车牌识别ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            try
            {
                int charBmpCount = this.TransformFiles(charSourceBath);//字母数字资源库中bitmap文件个数
                int provinceBmpCount = this.TransformFiles(provinceSourceBath);//省份资源库中bitmap文件个数
                int[] charMatch = new int[charBmpCount];//存储当前图片和资源库中图片比对后所得的像素不同的个数
                int[] provinceMatch = new int[provinceBmpCount];

                charFont = new Bitmap[charBmpCount];//存储字母数字bitmap文件
                provinceFont = new Bitmap[provinceBmpCount];//存储省份bitmap文件
                for (int i = 0; i < charBmpCount; i++)
                {
                    charMatch[i] = 0;
                }
                for (int i = 0; i < provinceBmpCount; i++)
                {
                    provinceMatch[i] = 0;
                }
                for (int i = 0; i < charBmpCount; i++)
                {
                    charFont[i] = (Bitmap)Bitmap.FromFile(charString[i], false);//charString存储的是路径
                }
                for (int i = 0; i < provinceBmpCount; i++)
                {
                    provinceFont[i] = (Bitmap)Bitmap.FromFile(provinceString[i], false);
                }

                int matchIndex = 0;//最终匹配索引
                string[] digitalFont = new string[7];

                if (array_Bitmap[0] != null)
                {
                    int nWidth = array_Bitmap[0].Width;
                    int nHeight = array_Bitmap[0].Height;
                    for (int i = 0; i < provinceBmpCount; i++)
                    {
                        for (int y = 0; y < nHeight; ++y)
                        {
                            for (int x = 0; x < nWidth; ++x)
                            {
                                if ((array_Bitmap[0].GetPixel(x, y).R - provinceFont[i].GetPixel(x, y).R) != 0)
                                    provinceMatch[i]++;
                            }
                        }
                    }
                    matchIndex = this.minNumber(provinceMatch);
                    digitalFont[0] = provinceDigitalString[matchIndex].Substring(0, 1);
                }

                if (array_Bitmap[1] != null && array_Bitmap[2] != null && array_Bitmap[3] != null && array_Bitmap[4] != null && array_Bitmap[5] != null && array_Bitmap[6] != null)
                {
                    for (int j = 1; j < 7; j++)
                    {
                        int nWidth = array_Bitmap[j].Width;
                        int nHeight = array_Bitmap[j].Height;
                        for (int i = 0; i < charBmpCount; i++)
                        {
                            charMatch[i] = 0;
                        }
                        for (int i = 0; i < charBmpCount; i++)
                        {
                            for (int y = 0; y < nHeight; ++y)
                            {
                                for (int x = 0; x < nWidth; ++x)
                                {
                                    if ((array_Bitmap[j].GetPixel(x, y).R - charFont[i].GetPixel(x, y).R) != 0)
                                        charMatch[i]++;
                                }
                            }
                        }
                        matchIndex = this.minNumber(charMatch);
                        digitalFont[j] = charDigitalString[matchIndex].Substring(0, 1);
                    }
                }
                this.ResultLabel.Text = "" + digitalFont[0] + digitalFont[1] + digitalFont[2] + digitalFont[3] + digitalFont[4] + digitalFont[5] + digitalFont[6];
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "错误提示", MessageBoxButtons.OK, MessageBoxIcon.Stop);
            }
        }

        private void 关于ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("版本：1.0", "关于", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void MainForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (MessageBox.Show("确认退出？", "退出", MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.Yes)
            {
                e.Cancel = false;
            }
            else
            {
                e.Cancel = true;
            }
        }
        private void MainForm_FormClosed(object sender, FormClosedEventArgs e)
        {
            //遍历关闭所有子窗口
            foreach (Form item in Application.OpenForms)
            {
                if (item.Name != "车牌处理系统") item.Close();
            }
        }
    }
}