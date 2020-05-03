#include <iostream>
using namespace std;
void fun1(){
	int i=1;
	int sum=0;
	for(;i<10;i++){
		sum+=i;
	}
	cout<<"i="<<i<<" sum="<<sum<<endl;
	return;
}
void fun2(){
	int i=1;
	int sum=0;
	for(int i=1;i<10;i++){
		sum+=i;
	}
	cout<<"i="<<i<<" sum="<<sum<<endl;
	return;
}
int main(){
	fun1();
	fun2();
	return 0; 
}
