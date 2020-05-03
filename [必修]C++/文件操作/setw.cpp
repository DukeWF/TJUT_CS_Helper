#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;
int main(){
	//setfill('替换字符')
	cout<<setfill('*')
	//setw(加上后一位字符总共占位数)
	//若输出变量小于setw设置数值，或者设置为0，则按实际值输出 
		<<setw(2)<<'\n'
		<<setw(3)<<'\n'
		<<setw(4)<<'\n'
		<<setw(5)<<'\n'
		<<setw(6)<<'\n';
		
	float f=17/7.0;
	cout<<f<<endl;
	//setprecision(num) 控制保留有效数字位数 
	cout<<setprecision(0)<<f<<endl;
	cout<<setprecision(1)<<f<<endl;
	cout<<setprecision(2)<<f<<endl;		
	return 0;
} 
