using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace 重载
{
    class Program
    {
        int sum(int a, int b)
        {
            return a + b;
        }
        int sum(int []a, int i)
        {
            int sum=0;
            if(i<a.Length)
                sum+=a[i];
            return sum;
        }
        double sum(double a, double b)
        {
            return a + b;
        }
        double sum(double[] a, int i)
        {
            double sum = 0;
            if (i < a.Length)
                sum += a[i];
            return sum;
        }
        static void Main(string[] args)
        {
            int i_a=1,i_b=2;
            int[] i_arr = { 1, 2, 3, 4, 5, 6, 7 };
            double d_a = 1, d_b = 2;
            double[] d_arr = { 1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5 };
            Console.WriteLine("(int)a+b="sum(i_a,i_b));
        }
    }
}
