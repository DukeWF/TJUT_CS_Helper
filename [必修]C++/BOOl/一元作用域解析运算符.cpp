/* TODO (#1#): 一元作用域解析运算符 */
#include <iostream>
using namespace std;
int v1=10;//globle v1
int main(){
	int v1=20;
	//用"::"修饰同名全局变量
	cout<<"globle v1="<<::v1<<" v1="<<v1;
	return 0;
} 
