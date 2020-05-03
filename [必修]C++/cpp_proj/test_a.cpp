#include <iostream>
#include <cstdlib>
using namespace std;
class MyObj
{
public:
	MyObj()
	{
		cout << "空构造\n";
		m_n = 0;
	}

	MyObj(int n)
	{
		cout << "参数构造\n";
		m_n = n;
	}

	MyObj(const MyObj& obj)
	{
		cout << "拷贝构造\n";
		m_n = obj.m_n;
	}

	MyObj operator =(const MyObj& obj)
	{
		cout << "=操作\n";
		m_n = obj.m_n;
		return *this;	//6调用拷贝构造函数
	}

	~MyObj()
	{
		cout << "析构\n";
	}

	int m_n;
};

MyObj test(int n)
{
	MyObj aa(n);		//2调用参数构造
	return aa;			//3调用拷贝构造，生成临时对象（重要！） 
}						//4析构局部对象aa

int main() 
{
	
		MyObj bb;		//1调用空构造
		bb = test(1);	//5调用赋值函数，7析构test返回的临时对象，8析构=返回的临时对象
						//9析构bb
}
