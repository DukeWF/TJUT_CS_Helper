#include <iostream>
using namespace std;
class employer{
	protected:
    	int code, age;//职工号及年龄
    	char sex[10];//性别
    	char name[10];//姓名
    public:
		employer(){
        	code=0;
			age=0;        
		}
		void getdata(){
			cout<<"Code:";
			cin>>code;
			cout<<"Name:";
			cin>>name;
			cout<<"Sex:";
			cin>>sex;
			cout<<"Age:";
			cin>>age;
    	}
    	void disp(){
    		cout<<"Code:"<<code<<endl
			<<"Name:"<<name<<endl
			<<"Sex:"<<sex<<endl
			<<"Age"<<age<<endl; 
		}

};
class teacher:public employer{
	protected:
		int hour;
	public:
		teacher():hour(30){
		};
		void getdata(){
			employer::getdata();
			cout<<"Hour:";
			cin>>hour;			
		}	
		double getSalary(){
			return (1000+hour*30);
		}
		void show(){
			cout<<"Teacher.salary:"<<getSalary()<<endl<<endl;
		}
	
};
class labworker:public employer{
	protected:
		int hour;
	public:
		labworker():hour(30){
		};
		void getdata(){
			employer::getdata();
			cout<<"Hour:";
			cin>>hour;			
		}
		double getSalary(){
			return (800+150+hour*5);
		}	
		void show(){
			cout<<"labworker.salary:"<<getSalary()<<endl<<endl;
		}	
};
int main(){
	teacher a;
	a.getdata();
	a.disp();
	a.show();
	labworker b;
	b.getdata();
	b.disp();
	b.show();
	return 0;
}

