#include <iostream>
using namespace std;

class point{
	private:
		int x;
		int y;
	public:
		point(){
			cout<<"����������"<<endl; 
			cout<<"X:";
			cin>>x;
			cout<<"Y:";
			cin>>y;
		} 
		void show(){
			cout<<"����Ϊ��("<<x<<","<<y<<")"; 
		}
}; 

class circle{
	private:
		point cir;
		int r;
	public:
		circle(){
			cout<<"������뾶:";
			cin>>r;
		}
		void show(){
			cir.show();
			cout<<"R="<<r<<endl;
		}
};
class rectangle{ 
	private:
		point rec;
		int l;
		int s;
	public:
		rectangle(){
			cout<<"�����볤��:";
			cin>>l;
			cout<<"��������:";
			cin>>s;  
		}
		void show(){
			rec.show();
			cout<<" ��Ϊ"<<l<<" ��Ϊ"<<s; 
		}
};
int main(void){
	circle yuan;
	yuan.show();
	rectangle juxing;
	juxing.show();
	return 0;
}
