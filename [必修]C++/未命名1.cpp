#include <iostream>
using namespace std;

class A{
	public: 
	A(int a){
		cout<<"111"<<endl;
	}
	~A(){
		cout<<"aaa"<<endl;
	}
};

class B{
	public:
	B(int a){
		cout<<"222"<<endl;
	}
	~B(){
		cout<<"bbb"<<endl;
	} 
};

class C{
	A a;
	B b;
	
	public:
	C(int x, int y):a(x),b(y){
		cout<<"333"<<endl;
	} 
	
	~C(){
		cout<<"ccc"<<endl;
	}
};

int main(void){
	
	C c(1, 2);
	
	
	return 0;
}
