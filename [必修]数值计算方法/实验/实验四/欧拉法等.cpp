#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

double h;
int n;

void init();
void OL();
void NOL();
//void _4LK();
 
int main(){
	init();
	OL();
//	NOL();
//	_4LK();
}
void init(){
	cout<<"请 输入运行步长h:";
	cin>>h;	
	n=(int)1.0/h;
}
#define MAX_N n
double olx[MAX_N],oly[MAX_N];
double nolx[MAX_N],noly[MAX_N],nolyp[MAX_N];
double _4lkx[MAX_N],_4lky[MAX_N];

void OL(){
	olx[0]=0;
	for(int i=0;i<n+1;i++){
		olx[i]=(double)i*h;
	}
	oly[0]=0;
	for(int i=0;i<n;i++){
		oly[i+1]=oly[i]+h*(olx[i]-oly[i]);
		cout<<'y'<<(i+1)<<'=';
		printf("%.6f",oly[i+1]);
	}
}
void NOL(){
	nolx[0]=0;
	for(int i=0;i<n+1;i++){
		olx[i]=(double)i*h;
	}
	nolyp[0]=1;
	for(int i=0;i<n;i++){
		oly[i+1]=oly[i]+h*(olx[i]-oly[i]);
		cout<<'y'<<(i+1)<<'=';
		printf("%.6f",oly[i+1]);
	}
}

