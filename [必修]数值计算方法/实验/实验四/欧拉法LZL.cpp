//���ַ������΢�ַ��� 
#include <iostream>
#include <cmath>
#include <cstdio>
#define MAX_NUM 100
using namespace std;
//ȫ�ֱ��� 
int num=0;
double h;
double f[MAX_NUM];
//ԭ������ 
void print(int x);
void init(); 
void F(double h);
void OL(double h);
void NOL(double h);
void _4LK(double h);
//ʵ�� 
int main(){
	init();
	OL(h);
	NOL(h);
	_4LK(h);
	return 0;
}
void init(){
	cout<<"�����벽��:";
	cin>>h;
	num=1/h;
	F(h);
}
void print(int x){
	switch(x){
		case 1:{
			cout<<"ŷ����:"<<endl;
			cout<<"xn\t   yn\t      ��ȷ��"<<endl;			
			break;
		}
		case 2:{
			cout<<"�Ľ�ŷ����:"<<endl;
			cout<<"xn\t   yn\t      ��ȷ��"<<endl;				
			break;
		}
		case 3:{
			cout<<"�Ľ�����-������:"<<endl;
			cout<<"xn\t   yn\t      ��ȷ��"<<endl;				
			break;
		} 
		default: break;	
	}
	return;
}
void F(double h){
	double x;
	for(int i=1;i<num+1;i++){
		x=i*h;
		f[i]=x+exp(-x)-1;
	}
}
void OL(double h){
	print(1);
	double xn[num+1],yn[num+1];
	xn[0]=0.0;
	yn[0]=0.0;
	for(int n=1;n<num+1;n++){
		yn[n]=yn[n-1]+h*(xn[n-1]-yn[n-1]);
		xn[n]=n*h;
	}
	for(int i=1;i<num+1;i++){
		printf("%.1f     %.6f     %.6f\n",xn[i],yn[i],f[i]);
	}
}
void NOL(double h){
	print(2);
	double xn[num+1],yn0[num+1],yn1[num+1];
	xn[0]=0.0;
	yn0[0]=0.0;
	yn1[0]=0.0;
	for(int n=1;n<num+1;n++){
		yn0[n]=yn1[n-1]+h*(xn[n-1]-yn0[n-1]);
		xn[n]=n*h;
		yn1[n]=yn1[n-1]+h/2*((xn[n-1]-yn1[n-1])+xn[n]-yn0[n]);
	}
	for(int i=1;i<num+1;i++){
		printf("%.1f     %.6f     %.6f\n",xn[i],yn1[i],f[i]);
	}
}
void _4LK(double h){
	print(3);
	double xn[num+1],yn0[num+1],yn1[num+1];
	double k1,k2,k3,k4;
	xn[0]=0.0;
	yn0[0]=0.0;
	yn1[0]=0.0;
	for(int n=1;n<num+1;n++){
		xn[n]=n*h;
        k1=xn[n-1]-yn1[n-1];
        k2=(xn[n-1]+h/2)-(yn1[n-1]+h/2*k1);
        k3=(xn[n-1]+h/2)-(yn1[n-1]+h/2*k2);
        k4=xn[n]-(yn1[n-1]+h*k3);
        yn1[n]=yn1[n-1]+h/6*(k1+2*k2+2*k3+k4);
	}
	for(int i=1;i<num+1;i++){
		printf("%.1f     %.6f     %.6f\n",xn[i],yn1[i],f[i]);
	}
}
