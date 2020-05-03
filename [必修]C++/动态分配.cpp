//获取姓名的构造函数 
#include <iostream>
#include <string.h>
using namespace std;

class student{
	private:
		char *name;
	public:
		student(){
			 char n[200]; 
			 cin>>n;
			 name=new char[strlen(n)+1];
			 strcpy(name,n);
		}
		student(char *n){
			 name=new char[strlen(n)+1];
			 strcpy(name,n);
		}		
		student(const student &n){
			name=new char[strlen(n.name)+1];
			strcpy(name,n.name);
		}
		~student(){
			delete name;
		}
		void show(){
		cout<<"Name:"<<name<<endl;
		}
		
}; 

int main(){
	student A("wang");
	A.show();
	cout<<endl<<endl;
	
	student B;
	B.show();
	cout<<endl<<endl;
	
	student C(A);
	C.show();
	cout<<endl<<endl;
	
	student *p;
	p = &A;
	p->show();
	
	return 0;
}
