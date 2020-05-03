//基类和派生类（继承受保护对象） 
#include <iostream>
using namespace std;
//基类实例 
class base{
	protected: 
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
	protected:
		int b;
	public:
		//通过继承protected内成员实现数据成员调用 
		derivative(int x, int y):b(y){
			a=x;
			cout<<"B is CONSTRUCTED"<<endl; 
		}
		void show(){
			cout<<"A:"<<a<<endl;
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
