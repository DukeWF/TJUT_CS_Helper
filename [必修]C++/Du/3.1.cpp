//1. �Ķ���������ȶ���"��"��Point������"��"��������"Բ"��Circle���������
#include <iostream>
using namespace std;
#define PI 3.14159
class Point         // ����"��"��
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

class Circle: public Point // ����"Բ"�࣬���м̳�
{
	int r;               // "Բ"�İ뾶 
public:
	Circle(int x, int y, int ra) : Point(x, y)  // B 
	{	r = ra;	 }
	void Setr(int ra)
	{	r = ra; }
	double Area( )                //��Բ�����
	{	return PI*r*r;	}
	void Move(int x_offset, int y_offset) //��Բ������ƽ��
	{
		int x1=Getx( );        //��ȡ�����˽�г�Ա
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
	c.Setxy(4, 5);      //������Բ������ 
	c.Setr(2);         //�����ð뾶ֵ 
	c.ShowCircle( );
}

