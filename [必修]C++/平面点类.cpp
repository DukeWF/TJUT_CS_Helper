#include <iostream>
using namespace std;

class point{
	private:
		int x;
		int y;
	public:
		point(){
			cout<<"请输入坐标"<<endl; 
			cout<<"X:";
			cin>>x;
			cout<<"Y:";
			cin>>y;
		} 
		void show(){
			cout<<"坐标为：("<<x<<","<<y<<")"; 
		}
}; 

class circle{
	private:
		point cir;
		int r;
	public:
		circle(){
			cout<<"请输入半径:";
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
			cout<<"请输入长度:";
			cin>>l;
			cout<<"请输入宽度:";
			cin>>s;  
		}
		void show(){
			rec.show();
			cout<<" 长为"<<l<<" 宽为"<<s; 
		}
};
int main(void){
	circle yuan;
	yuan.show();
	rectangle juxing;
	juxing.show();
	return 0;
}
