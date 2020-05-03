#include <iostream>
#include <cmath>
using namespace std;
double e=0.5e-5;//精度 
const double N=1000;//最大迭代次数 
//求函数值 
double f(double x){
	return exp(-x);
}
double _f(double x){
	return x-(x-exp(-x))/(x+1);
}
double __f(double x){
	return x*exp(x)-1;
}
double __f(double x1, double x0){
	return x1-(__f(x1)*(x1-x0))/(__f(x1)-__f(x0));
}
int Iteration(){
	cout<<"迭 代法开始：" <<endl;
	cout<<"k     X"<<endl; 
	double x=0.5;
	double X=f(x);
	int k=1;
	while(fabs(X-x)>=e){
		if(k==N) return 0;
		else{
			k++;
			x=X;
		}
		X=f(x);
		cout<<k<<" "<<X<<endl; 
	}
	cout<<"迭 代法最终结果："<<X<<endl;
	return k;
}
int Newton(){
	cout<<"牛 顿迭代法开始：" <<endl;
	cout<<"k     X"<<endl; 
	double x=0.5;
	double X=_f(x);
	int k=1;
	while(1){
		if(_f(x)!=0){
			X=_f(x);
			cout<<k<<" "<<X<<endl; 
			if(fabs(X-x)>=e){
				if(k==N) return 0;
				else{
					k++;
					x=X;
				}
			}
			else{
				cout<<"牛 顿迭代法最终结果："<<X<<endl;
				return k;
			}
		}
		else return 0;
	}
}
int Secant(){
	cout<<"双 点弦截法法开始：" <<endl;
	cout<<"k     X"<<endl; 
	double x0=0.5;
	double x1=0.6;
	double x2;
	int k=1;
	
	while(1){
		x2=__f(x1,x0);
		cout<<k<<" "<<x2<<endl; 
		if(fabs(__f(x2))>e){
			if(k==N) return 0;
			else{
				k++;
				x0=x1;
				x1=x2;
			}
		}
		else{
			cout<<"双 点弦截法法最终结果："<<x2<<endl;
			return k;
		}
	}	
}

void compare(int k1, int k2, int k3){
	if(k1>k2){
		if(k2>k3) cout<<"双 点弦截法效率最高！";
		else cout<<"牛 顿迭代法效率最高！";
	}
	else if(k1<k3) cout<<"迭 代法效率最高";
	return;
}
int main(){
	int k1=Iteration();
	cout<<endl;
	int k2=Newton();
	cout<<endl;
	int k3=Secant();
	cout<<endl<<"比 较三种方法迭代次数："<<endl<<"迭 代法：   "<<k1<<endl<<"牛 顿迭代法："<<k2<<endl<<"双 点弦截法："<<k3<<endl;
	compare(k1,k2,k3); 
	return 0;
} 
