//������ 
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;
class Class{
	
	private:
//		friend student;//��Ԫ���� 
		student stu;
		double sum;
		int num;
	public:
		Class();
		~Class();
		int total();
		double ave();				
};

//��δ�������� 
Class::Class():sum(0),num(0){
	stu = new student[];
	num++;
	sum+=stu.get_score();
	stu++;
}  
Class::~Class(){
	delete stu;
}
int Class::total(){
	return sum;	
}
double Class::ave(){
	return sum/(num*1.0);
}
//
//ѧ���� 
class student{
	friend Class;
	private:
		int ID;
		string name;
		double score;
	public:
		student(int id, string na, double sc);
		student();
		double get_score();
		void form(); 
};
student::student(){
	cout<<"Name:";
	cin>>name;
	cout<<"ID";
	cin>>ID;
	cout<<"Score:";
	cin>>score;
}
student::student(int id, string na, double sc){
	ID=id;
	name=na;
	score=sc;
}
double student::get_score(){
	return score;
}
void student::form(){
	cout<<ID<<"    "<<name<<"    "<<score<<endl;
}

int main(){
	if(getchar()!='\n') 
	Class cs; 
	
	cout<<"ѧ��������"<<cs.total()<<endl;
	cout<<"ѧ��ƽ���ɼ���"<<cs.ave()<<endl;
	
	return 0; 
}
