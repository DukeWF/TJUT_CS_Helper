using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace 类_接口及多态
{
    //定义接口Body
    interface Body 
    {
        float area();
    }
    //创建类Cube，实现Body接口
    class Cube:Body 
    {
        private float a;
        public Cube(float a)
        {
            this.a = a;
        }
        public float area() 
        {
            return 6 * a * a;
        }
    }
    //创建类Ball，实现Body接口
    class Ball : Body
    {
        private float r;
        public Ball(float r)
        {
            this.r = r;
        }
        public float area()
        {
            return (float)(4 * 3.14 * r * r);
        }
    }

    class MainClass
    {
        public static float getArea(Body b) 
        {
            return b.area();
        }
        static void Main(string[] args)
        {
            Cube cube = new Cube(10);
            Ball ball = new Ball(5);
            Console.WriteLine("Cube`s Area=" + getArea(cube));
            Console.WriteLine("Ball`s Area=" + getArea(ball));
            Console.ReadLine();
        }
    }
}
