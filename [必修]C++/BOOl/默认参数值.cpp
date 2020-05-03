#include <iostream>
using namespace std;
void fun(int x, double y=2.0); 
int main(){
	fun(1,2.0);
} 
void fun(int x, double y){//只声明一次默认值 
	cout<<"x="<<x<<" y="<<y;
	return;
}
