#include <iostream>
using namespace std;
class A{
	public:
		virtual void f()=0{//�麯��--ʹ����������ͬ������ʵ��Ψһ���� 
//			cout<<"I am A"<<endl;
		}
}; 
class B:public A{
	public:
		void f(){
			cout<<"I am B"<<endl;
		}
}; 
int main(){
	B b;
	b.f();
}
