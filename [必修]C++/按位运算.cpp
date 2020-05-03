//按位运算简介（用于单片机/嵌入式编程） 
#include <iostream>
using namespace std;
int main(){
	int a=0x1234;
	int b=0x4321;
	int c=a|b;
	int d=a&b;
	int e=a^b;
	cout<<c<<endl<<d<<endl<<e;
	return 0;
}
