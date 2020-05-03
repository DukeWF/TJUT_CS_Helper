using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace 引用实现
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] input = {1,2,3,4,5,6,7,8,9,10};
            for (int i = 0; i<input.Length;i++ )
            {
                if ( input[i] % 7 == 0)
                    input[i] = 0;
                Console.Write(input[i]+" ");
            }
            Console.ReadLine();
        }
    }
}
