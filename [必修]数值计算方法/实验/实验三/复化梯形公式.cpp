#include<iostream>
#include<cmath>
using namespace std;
int n;
double a=1.0,b=2.0;
double sum=0.0,x=0.0;

void init();
void trapezium();

int main(){
	init();
	trapezium();
	return 0;
}
void init(){
	cout<<"请输入等分次数:";
	cin>>n;
}
void trapezium(){
	double h=(b-a)/n;
	for(int i=1;i<=n-1;i++){
		x=a+i*h;
		sum+=1.0/x;
	}
	cout<<h/2.0*(1.0/a+2*sum+1.0/b);
}
