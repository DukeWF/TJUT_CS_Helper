/* TODO (#1#): 引用与参数传递 */
#include <iostream>
using namespace std;
//值传递：无法交换 
void swap(int n1, int n2){
	int t=n1;
	n1=n2;
	n2=t;
}
//指针传递 
void swap(int* n1, int* n2){
	int t=*n1;
	*n1=*n2;
	*n2=t;
}
//引用传递 
void swap(int& n1, int& n2){
	int t=n1;
	n1=n2;
	n2=t;
}
int main(){
	int x=1;
	int& rx=x;
	//另一种写法
	int y=2, &ry=y;
	cout<<"Normal："<<x<<" "<<y<<endl;
	swap(&x,&y);
	cout<<"Now   ："<<x<<" "<<y<<endl;
}
int main(){
	int x=1;
	int& rx=x;
	//另一种写法
	int y=2, &ry=y;
	cout<<"Normal："<<x<<" "<<y<<endl;
	swap(x,y);
	cout<<"Now   ："<<x<<" "<<y<<endl;
}
int main(){
	int x=1;
	int& rx=x;
	//另一种写法
	int y=2, &ry=y;
	cout<<"Normal："<<x<<" "<<y<<endl;
	swap(x,y);
	cout<<"Now   ："<<x<<" "<<y<<endl;
}
