#include <iostream>
#include <cmath>
using namespace std;
double f(double x){
	return pow(x,5)+3*x-1;
}
void dichotomia(){
	double a=0,b=1,e;
	cin>>e;
	while(abs(b-a)>e){
		double h=(a+b)/2;
		cout<<"["<<a<<","<<b<<"]"<<" "<<h<<endl;
		if(f(h)*f(a)<0){
			b=h;
		}
		else if(f(h)*f(b)<0){
			a=h;
		}
	}
	cout<<"x="<<(a+b)/2;
}
int main()
{
	dichotomia();
	return 0;
}
