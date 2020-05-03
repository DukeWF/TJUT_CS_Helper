#include <iostream>
#include <cmath>
using namespace std;
#define PI 3.1415926
class Circle{
	private:
		double radius;
	public:
		Circle():radius(0){
		};
		Circle(double r):radius(r){
		};
		double getRadius();
		double getPerimeter();
		void disp();		
};
double Circle::getRadius(){
	return radius;	
}
double Circle::getPerimeter(){
	return (2*PI*radius);
}
void Circle::disp(){
	cout<<"Radius:"<<getRadius()<<endl<<"Perimeter:"<<getPerimeter()<<endl<<"Area:"<<(PI*pow(radius,2))<<endl;
}

