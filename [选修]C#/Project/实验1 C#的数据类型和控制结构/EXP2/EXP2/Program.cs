using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace EXP2
{
    class Program
    {
        static void Main()
        {
            Console.WriteLine("利用分支循环实现1-100内整数和与奇数和:");
            int i = 0;
            int sum = 0;
            while (i < 100)
            {
                sum += ++i ;

            }
            Console.WriteLine("1+2+...+100="+sum);
            for(i=1,sum=0;i<=100;i+=2)
            {
                sum+=i;
            }
            Console.WriteLine("1+3+...+99="+sum);
        }
    }
}
