#include <iostream>
using namespace std;
class A{
	public:
		A(){
			
		}
		virtual ~A(){
			cout<<"deconstruction A"<<endl;
		}
}; 
class B:public A{
	int *p;
	public:
		B(){
			p=new int;
		}
		~B(){
			cout<<"deconstruction B"<<endl;
		}
};
main(){
	A *pa;
	pa=new B;
	delete pa;
}
