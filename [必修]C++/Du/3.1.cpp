//1. 阅读下面程序，先定义"点"类Point，再由"点"类派生出"圆"类Circle，分析结果
#include <iostream>
using namespace std;
#define PI 3.14159
class Point         // 定义"点"类
{
	int x, y;
public:
	Point(int a=0, int b=0)
	{		x=a; y=b;	}

	void ShowPoint( )
	{	cout<<"Point:("<<x<<','<<y<<")\n";	}

	int Getx( )
	{	  return x;  }

	int Gety( )
	{		return y;	}

	void Setxy(int a, int b)
	{	x=a; y=b;	}
};

class Circle: public Point // 定义"圆"类，公有继承
{
	int r;               // "圆"的半径 
public:
	Circle(int x, int y, int ra) : Point(x, y)  // B 
	{	r = ra;	 }
	void Setr(int ra)
	{	r = ra; }
	double Area( )                //求圆的面积
	{	return PI*r*r;	}
	void Move(int x_offset, int y_offset) //将圆心坐标平移
	{
		int x1=Getx( );        //存取基类的私有成员
		int y1=Gety( );                  // D
		x1 += x_offset; y1 += y_offset;
		Setxy(x1, y1);                   // E
	}
	void ShowCircle( )
	{
		ShowPoint( );                   // F
		cout<<" Radius: "<<r<<'\t';
		cout<<"Area: "<<Area( )<<endl;    //G
	}
};
int main()
{
	Circle c(1, 1, 1);
	c.ShowCircle( );
	c.Move(1, 2);
	c.ShowCircle( );
	c.Setxy(4, 5);      //重新置圆心坐标 
	c.Setr(2);         //重新置半径值 
	c.ShowCircle( );
}

