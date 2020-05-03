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
			 score=s; 
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
		cout<<"Name:"<<name<<"\tScore:"<<score<<endl;
		}
		
}; 

class banji{
	private:
		int num;
		student *s;
	public:
		banji(int n);
		~banji();
		void show();
		double average(); 
};
banji::banji(int n){
	num = n;
	s = new student[n];
}
double banji::average(){
	//不能直接访问私有成员？! 
}
banji::~banji(){
	delete []s;//释放数组的标志：[]数组名 
}
void banji::show(){
	for(int i=0;i<num;i++){
		s[i].show();
	}
}

int main(){
	banji cs(2);
	cs.show();
}
