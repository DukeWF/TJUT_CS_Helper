#include<iostream>
#include<math.h>
#include <iomanip>
using namespace std;
double tixing(double T,int n){
	double a=1.0,b=2.0;
	double h=(b-a)/n;
	double sum=0.0,xk=0.0;
	for(int i=0;i<=n-1;i++){
		xk=a+(i+1.0/2)*h;
		sum+=pow(xk,1.5);
	}
	return (h/2.0*sum+1.0/2*T);
}
int main(){
     long double Tn[100],Sn[100],Cn[100],Rn[100];
    Tn[1]=1.0/2*(pow(1.0,1.5)+pow(2.0,1.5));
    for(int k=1;k<10;k++){
    	Tn[k+1]=tixing(Tn[k],pow(2,k-1));
    }
    for(int k=1;k<10;k++){
    	Sn[k]=4.0/3*Tn[k+1]-1.0/3*Tn[k];
	}
	for(int k=1;k<10;k++){
    	Cn[k]=16.0/15*Sn[k+1]-1.0/15*Sn[k];
	}
	for(int k=1;k<10;k++){
    	Rn[k]=64.0/63*Cn[k+1]-1.0/63*Cn[k];
	}
    cout<<"k"<<"    "<<"等分次数"<<" \t"<<"梯形序列"<<"\t"<<
	"辛普森序列"<<"\t"<<"柯特斯序列"<<"\t"<<"龙贝格序列"<<endl; 
	int k;
	bool temp=false;
	for( k=0;k<10;k++){
		cout<<k<<"\t"<<pow(2,k)<<"\t"<<setprecision(8)<<Tn[k+1]<<"\t";
		if(k>=1){
			cout<<setprecision(8)<<Sn[k]<<"\t";
		}
		if(k>=2){
				cout<<setprecision(8)<<Cn[k-1]<<"\t";
		}
		if(k>=3){
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
} 

