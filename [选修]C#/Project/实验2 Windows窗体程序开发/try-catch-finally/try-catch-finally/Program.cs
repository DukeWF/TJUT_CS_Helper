using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace try_catch_finally
{
    class Program
    {
        static void Main(string[] args)
        {
            int a, b;
            try
            {
                Console.Write("请输入被除数:");
                a = int.Parse(Console.ReadLine());
                Console.Write("请输入除数:");
                b = int.Parse(Console.ReadLine());
                double sum = a /b;
                //将b显式转换成double类型时，显示正无穷大？？？
                Console.WriteLine(sum);
            }
            catch(Exception e)
            {
                Console.WriteLine("除数为0！");
            }
            finally 
            {
                Console.WriteLine("Finally!");
            }
            Console.ReadLine();
        }
    }
}
