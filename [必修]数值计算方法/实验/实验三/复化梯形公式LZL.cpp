#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

long double Tn[100],Sn[100],Cn[100],Rn[100];
double a=1.0,b=2.0;
double h;
double sum=0.0,xk=0.0;
int k;
bool temp=false;

void init();
void show(int i);
double trapezium(double T,int n);
double Simpson(double T1, double T2);
double Cotes(double S1, double S2);
double Romberg(double C1, double C2);

int main(){
	init();
	show(1);
	show(2);
	return 0;
} 
void init(){
	Tn[1]=1.0/2*(pow(1.0,1.5)+pow(2.0,1.5));
    for(k=1;k<10;k++){
    	Tn[k+1]=trapezium(Tn[k],pow(2,k-1));
    }
    for(k=1;k<10;k++){
    	Sn[k]=Simpson(Tn[k+1],Tn[k]);
	}
	for(k=1;k<10;k++){
    	Cn[k]=Cotes(Sn[k+1],Sn[k]);
	}
	for(k=1;k<10;k++){
    	Rn[k]=Romberg(Cn[k+1],Cn[k]);
	}
}
void show(int i){
	switch(i){
		case 1:{
			cout<<"k"<<"    "<<"等分次数"<<
			" \t"<<"梯形序列"<<"\t"<<
			"辛普森序列"<<"\t"<<"柯特斯序列"<<
			"\t"<<"龙贝格序列"<<endl;	
			break;
		}
		case 2:{
			for(k=0;k<10;k++){
				cout<<k<<"\t"<<pow(2,k)<<"\t"<<setprecision(8)<<Tn[k+1]<<"\t";
				if(k>=1) cout<<setprecision(8)<<Sn[k]<<"\t";
				else if(k>=2) cout<<setprecision(8)<<Cn[k-1]<<"\t";
				else if(k>=3){
					cout<<setprecision(8)<<Rn[k-2];
					if(Rn[k-2]-Rn[k-1]<0.000001&&temp){
						break;
					}
					temp=true;
				}
				cout<<endl;
			}
			cout<<endl;
			cout<<"近似值为:"<<setprecision(7)<<Rn[k];
			break;
		}
	}
}
double trapezium(double T,int n){
	h=(b-a)/n; 
	for(int i=0;i<=n-1;i++){
		xk=a+(i+1.0/2)*h;
		sum+=pow(xk,1.5);
	}
	return (h/2.0*sum+1.0/2*T);
}
double Simpson(double T1, double T2){
	return 4.0/3*T1-1.0/3*T2;
}
double Cotes(double S1, double S2){
	return 16.0/15*S1-1.0/15*S2;
}
double Romberg(double C1, double C2){
	return 64.0/63*C1-1.0/63*C2;
}
