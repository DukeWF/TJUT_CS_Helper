#include <iostream>
#include <cstdlib>
using namespace std;
class MyObj
{
public:
	MyObj()
	{
		cout << "�չ���\n";
		m_n = 0;
	}

	MyObj(int n)
	{
		cout << "��������\n�n";
		m_n = n;
	}

	MyObj(const MyObj& obj)
	{
		cout << "��������\n�n";
		m_n = obj.m_n;
	}

	MyObj operator =(const MyObj& obj)
	{
		cout << "=����\n�n";
		m_n = obj.m_n;
		return *this;	//6���ÿ������캯��
	}

	~MyObj()
	{
		cout << "����\n�n";
	}

	int m_n;
};

MyObj test(int n)
{
	MyObj aa(n);		//2���ò�������
	return aa;			//3���ÿ������죬������ʱ������Ҫ���� 
}						//4�����ֲ�����aa

int main() 
{
	
		MyObj bb;		//1���ÿչ���
		bb = test(1);	//5���ø�ֵ������7����test���ص���ʱ����8����=���ص���ʱ����
						//9����bb
}
