using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace EXP1
{
    class Program
    {
        static void Main(string[] args)
        {
            int i=1;
            double d=3.1415926;
            bool b=true;
            char c='c';
            string str="string";

            Console.WriteLine("下面执行输出变量:");
            Console.WriteLine("int:" + i + "\ndouble:" + d + "\nbool:" + b + "\nchar:" + c + "\nstring:" + str+"\n");
            Console.Write("请输入一串数字:");
            string s=Console.ReadLine();
            Int64 s_i=Int64.Parse(s);
            
            Console.WriteLine("\n下面执行数据类型转换:");
            Console.WriteLine("double->int:" + (Int32)d);
            Console.WriteLine("string->int（Type.Parse方法）:"+s_i);
            Console.WriteLine("string->int（Convert方法）:" + Convert.ToInt32(s));

        }
    }
}
