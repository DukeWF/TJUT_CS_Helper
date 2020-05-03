//构造函数与析构函数 --> 动态分配实例 
#include <iostream>
#include <string.h>
using namespace std;

class student{
	private:
		char *name;
		int score;
	public:
		student(){
			 char n[200]; 
			 int s;
			 cout<<"Input your name:";
			 cin>>n;
			 name=new char[strlen(n)+1];
			 strcpy(name,n);
			 cout<<"Input your score:";
			 cin>>s;
		}
		student(char *n, int s){
			 name=new char[strlen(n)+1];
			 strcpy(name,n);
			 score = s;
		}		
		student(const student &n){
			name=new char[strlen(n.name)+1];
			strcpy(name,n.name);
			score = n.score;
		}
		~student(){
			delete name;
		}
		void show(){
		cout<<"Name:"<<name<<"Score:"<<score<<endl;
		}
		
}; 

int main(){
	student s[2];
	s[0].show();
	s[1].show(); 
//	student A("wang");
//	A.show();
//	cout<<endl<<endl;
//	
//	student B;
//	B.show();
//	cout<<endl<<endl;
//	
//	student C(A);
//	C.show();
//	cout<<endl<<endl;
//	
//	student *p;
//	p = &A;
//	p->show();
//	
//	return 0;
}
