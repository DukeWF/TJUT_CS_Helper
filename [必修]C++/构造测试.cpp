/*
	Name: 
	Description:
	1.
	2.
		2.1:
		2.2:
	3.
	Time Complexity£º O()-O()-O()
*/
#include <iostream>
#include <string> 
using namespace std;

class student
{
public:
	student();
	student(int num=2000,string name="nqr",string s="cs");
	~student();
	void print()
	{
		cout<<num<<endl<<name<<endl<<s<<endl;
	}
private:
	int num;
	string name;
	string s;
};



student::student(int num,string name,string s)
{
	this->name=name;
	this->num=num;
	this->s=s;
	cout<< "the object " + this->name + " is constructed"<<endl;
}

student::~student()
{
	cout<<"the object is destoried"<<endl;
}

int main()
{
	student stu1= student();
	student stu2= new student();
	student stu3();
	
    stu.print();

	student s1=student(5132,"hkasnd","asidas");
	
    s1.print();
	return 0;
}
