#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;
int main(){
	//setfill('�滻�ַ�')
	cout<<setfill('*')
	//setw(���Ϻ�һλ�ַ��ܹ�ռλ��)
	//���������С��setw������ֵ����������Ϊ0����ʵ��ֵ��� 
		<<setw(2)<<'\n'
		<<setw(3)<<'\n'
		<<setw(4)<<'\n'
		<<setw(5)<<'\n'
		<<setw(6)<<'\n';
		
	float f=17/7.0;
	cout<<f<<endl;
	//setprecision(num) ���Ʊ�����Ч����λ�� 
	cout<<setprecision(0)<<f<<endl;
	cout<<setprecision(1)<<f<<endl;
	cout<<setprecision(2)<<f<<endl;		
	return 0;
} 
