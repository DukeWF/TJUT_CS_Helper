#include <iostream>
#include <cmath>
using namespace std;
#define PI 3.1415926
class Circle{
	protected:
		double radius;
	public:
		Circle():radius(0){}
		Circle(double r):radius(r){}
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
class Cylinder:public Circle{
	private:
		double height;
	public:
		Cylinder(double r,double h){
			radius=r;
			height=h;
		}
		double getHeight();
		double getVol();
		void dispVol();
};
double Cylinder::getHeight(){
	return height;
}
double Cylinder::getVol(){
	return (PI*pow(radius,2)*height);
}
void Cylinder::dispVol(){
	cout<<"Vol:"<<getVol()<<endl;
}
int main(){
	double r,h;
	cout<<"R=";
	cin>>r;
	cout<<"H=";
	cin>>h;
	Cylinder test(r,h);
	test.disp();
	test.dispVol();
	return 0;
}

