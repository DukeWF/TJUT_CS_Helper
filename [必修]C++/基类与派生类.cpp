//基类和派生类
#include <iostream>
using namespace std;
//基类实例 
class base{
	int a;
	public:
		base(int t=0):a(t){
			cout<<"A is CONSTRUCTED."<<endl;
		}
		void show(){
			cout<<"A:"<<a<<endl;
		}
		~base(){
			cout<<"A is dead."<<endl;
		} 
		
};
//派生类实例 
class derivative:public base{
	int b;
	public:
		//通过初始化成员列表调用基类的私有对象（利用构造函数） 
		derivative(int x, int y):base(x),b(y){
			cout<<"B is CONSTRUCTED"<<endl; 
		}
		void show(){
			base::show();
			cout<<"B:"<<b<<endl; 
		}
		~derivative(){
			cout<<"B is dead."<<endl;
		}
};
int main(){
	derivative a(1,2); 
	a.show();
}
