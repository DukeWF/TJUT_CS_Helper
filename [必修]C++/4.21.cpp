//4.21`派生类继承 
#include <iostream>
using namespace std;
class Time{
	protected:
		int hours, minutes, seconds;
	public:
		Time(int h, int m, int s){
			hours=h;
			minutes=m;
			seconds=s;
		}
		void display(){
			cout<<"出生时间："<<hours<<"时"<<minutes<<"分"<<seconds<<"秒"<<endl;
		}
};
class Date{
	protected:
		int month, day, year;
	public:
		Date(int m, int d, int y){
			month=m;
			day=d;
			year=y;
		}
		void display(){
			cout<<"出生年月："<<year<<"年"<<day<<"月"<<month<<"日"<<endl;
		}
};
#include <string>
class Birthtime:public Time,public Date{
	protected:
		string Childname;
	public:
		Birthtime(string nm, int _h, int _m, int _s, int _mo, int _d, int _y):Time(_h, _m,_s),Date(_mo, _d, _y){
			Childname=nm;
		} 
		void display(){
			cout<<"姓名："<<Childname<<endl; 
			Date::display();
			Time::display();
		}	
};
int main(){
	Birthtime test("test",13,30,29,10,11,2016);
	test.display();
	return 0; 
}		
