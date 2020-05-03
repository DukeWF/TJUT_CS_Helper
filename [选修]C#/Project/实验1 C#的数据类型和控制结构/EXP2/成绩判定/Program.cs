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
            string s=Console.ReadLine();
            Int32 score = Int32.Parse(s);
            switch(score){
                case 100:
                    {
                        Console.WriteLine("良好");
                        break;
                    }
                case 89:
                    {
                        Console.WriteLine("良好");
                        break;
                    }
                case 79:
                    {
                        Console.WriteLine("中等");
                        break;
                    }
                case 69:
                    {
                        Console.WriteLine("及格");
                        break;
                    }
                case 59:
                    {
                        Console.WriteLine("不及格");
                        break;
                    }
            }
            Console.ReadLine();
        }
    }
}
