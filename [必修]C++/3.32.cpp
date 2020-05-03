#include <iostream>
#include <math.h>
using namespace std;

class cylinder{
	private:
		double r, h;
		double value;
	public:
		cylinder(double R, double H);
		void vol();
};
cylinder::cylinder(double R, double H){
	r=R;
	h=H;
	value=M_PI*(pow(r,2))*h;
}
void cylinder::vol(){
	cout<<"The value is:"<<value<<endl;
}
int main(){
	cylinder x(2.2,8.09);
	x.vol();
	return 0;
}
