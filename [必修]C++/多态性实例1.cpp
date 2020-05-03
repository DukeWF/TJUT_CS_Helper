#include <iostream>
using namespace std;
class A{
	public:
		virtual void f()=0{//虚函数--使得派生类内同名函数实现唯一定义 
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
