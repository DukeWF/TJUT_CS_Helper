 /* TODO (#1#): 动态内存管理 */
#include <iostream>
using namespace std;
int main(){
	//申请变量空间（同时声明） 
	<类型名>* <变量名> = new<类型名>(初值);
	//申请数组 （同时声明） 
	<类型名>* <数组名> = new<类型名>[常量表达式];
	//释放空间 
	delete <指针名>;
	delete[] <数组名>;
} 
