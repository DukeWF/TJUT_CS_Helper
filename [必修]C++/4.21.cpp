//4.21`������̳� 
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
			cout<<"����ʱ�䣺"<<hours<<"ʱ"<<minutes<<"��"<<seconds<<"��"<<endl;
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
			cout<<"�������£�"<<year<<"��"<<day<<"��"<<month<<"��"<<endl;
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
			cout<<"������"<<Childname<<endl; 
			Date::display();
			Time::display();
		}	
};
int main(){
	Birthtime test("test",13,30,29,10,11,2016);
	test.display();
	return 0; 
}		
