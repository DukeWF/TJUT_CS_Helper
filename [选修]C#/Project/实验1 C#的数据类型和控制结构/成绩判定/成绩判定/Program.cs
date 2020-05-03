using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace 成绩判定
{
    class Program
    {
        static void Main(string[] args)
        {
            string score = Console.ReadLine();

            switch (Convert.ToInt32(score)/10)
            {
                case 10:

                case 9:
                    {
                        Console.WriteLine("优秀");
                        break;
                    }
                case 8:
                    {
                        Console.WriteLine("良好");
                        break;
                    }
                case 7:
                    {
                        Console.WriteLine("中等");
                        break;
                    }
                case 6:
                    {
                        Console.WriteLine("及格");
                        break;
                    }
                case 5:
                    {
                        Console.WriteLine("不及格");
                        break;
                    }
                default: 
                    {
                        Console.WriteLine("输入信息超过正常范围，退出");
                        break;
                    }
            }
            
        }
    }
}
