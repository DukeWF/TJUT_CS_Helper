#include <iostream>
using namespace std;
class Date{
	private:
		int day, month, year;
	public:
		void printDate();
		void setDay(int d);
		void setMonth(int m);
		void setYear(int y);
};
void Date::printDate(){
	cout<<"The Date is (d.m.y) : "<<day<<"."<<month<<"."<<year<<endl;
}
void Date::setDay(int d){
	day=d;
}
void Date::setMonth(int m){
	month=m;
}
void Date::setYear(int y){
	year=y;
}
int main(){
	Date testDay;
	testDay.setDay(5);
	testDay.setMonth(10);
	testDay.setYear(2003);
	testDay.printDate();
	
	return 0;
}
