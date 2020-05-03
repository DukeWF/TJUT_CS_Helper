//四阶-龙格库塔法求解微分方程 
#include <iostream>
#include <cstdio>
using namespace std;
//全局变量 
int num;
double h;
double k1,k2,k3,k4,l1,l2,l3,l4;
//原型声明 
void init();
double f(double x,double y);
double f(double x);
void _4LK(double h, int num);
//实现 
int main(){
	init();
	_4LK(h,num);
	return 0;
}
double f(double x,double y){
	return 1/(y-x);
} 
double f(double x){
	return (-1/x)+1;
}
void init(){
	cout<<"请输入步长:";
	cin>>h;
	num=2.0/h;
}
void _4LK(double h,int num){
	double x[num+1],y1[num+1],y2[num+1];
	y1[0]=1.0;y2[0]=1.0;
    for(int n=1;n<num+1;n++){
    	x[n]=n*h;
    	k1=f(x[n-1],y2[n-1]);
        l1=f(y1[n-1]);
        
    	k2=f(x[n-1]+h/2,y2[n-1]+h/2*l1);
    	l2=f(y1[n-1]+h/2*k1);
    	
    	k3=f(x[n-1]+h/2,y2[n-1]+h/2*l2);
        l3=f(y1[n-1]+h/2*k2);
        
    	k4=f(x[n],y2[n-1]+h*l3);
    	l4=f(y1[n-1]+h*k3);
    	
    	y1[n]=y1[n-1]+h/6*(k1+2*k2+2*k3+k4);
    	y2[n]=y2[n-1]+h/6*(l1+2*l2+2*l3+l4);
	}
	cout<<"xn\t    y1\t\ty2"<<endl;
	for(int i=1;i<num+1;i++){
		printf("%.1f     %.6f    %.6f\n",x[i],y1[i],y2[i]);
	}
}
