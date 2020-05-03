//静态数据成员方式 学生类 
#include <iostream>
#include <string>
using namespace std;
class student{
	private:
		int ID;
		string name;
		double score;
		static double sum;
		static int num;
	public:
		student(int id, string na, double sc);
		student();
		static double ave();
		static int total();
		void form();
};
student::student(){
	cout<<"Name:";
	cin>>name;
	cout<<"ID";
	cin>>ID;
	cout<<"Score:";
	cin>>score;
	sum+=score;
	num++;
}
student::student(int id, string na, double sc){
	ID=id;
	name=na;
	score=sc;
	sum+=sc;
	num++;
}
double student::ave(){
	return sum/(num*1.0);
}
int student::total(){
	return num;
}
void student::form(){
	cout<<ID<<"    "<<name<<"    "<<score<<endl;
}
double student::sum=0;
int student::num=0;

int main(){
	student a();
	student b(1001,"Wang",100);
	cout<<"学号    姓名    成绩"<<endl;
	a.form();
	b.form();
	cout<<"学生人数："<<student::total()<<endl;
	cout<<"学生平均成绩："<<student::ave()<<endl;
	
	return 0; 
}
