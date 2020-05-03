//4.22 
#include <iostream>
#include <string>
using namespace std;
class person{
	protected:
		int ID;
		string name;
	public:
		person(int id, string nm){
			ID=id;
			name=nm;	
		}	
		person(){
			cout<<"input your name:";
			cin>>name;
			cout<<"input your ID:";
			cin>>ID;
		}
		void display(){
			cout<<"Name:"<<name<<endl;
			cout<<"ID:"<<ID<<endl;
		}
};
class student:public person{
	private:
		int class_id;
		double score;
	public:
		student(int id, string nm, int c_id, double sc):person(id,nm){
			class_id=c_id;
			score=sc; 
		}
		student(){
			cout<<"Input your Class ID:";
			cin>>class_id;
			cout<<"Input your Score:";
			cin>>score;			
		}
		void display(){
			person::display();
			cout<<"Class ID:"<<class_id<<endl;
			cout<<"Score:"<<score<<endl;			
		}
};
class teacher:public person{
	private:
		string grade;
		string department;
	public:
		teacher(int id, string nm, string gr, string de):person(id,nm){
			grade=gr;
			department=de; 
		}
		teacher(){
			cout<<"Input your Grade:";
			cin>>grade;
			cout<<"Input your Department:";
			cin>>department;			
		}
		void display(){
			person::display();
			cout<<"Grade:"<<grade<<endl;
			cout<<"Department:"<<department<<endl;			
		}
};
int main(){
	student a(1001,"Tony",1,100);
	a.display();
	student b;
	b.display();
	teacher c(1001,"Zhang","Dr.","Cs");
	c.display();
	teacher d;
	d.display();
	return 0;
}
