/* TODO (#1#): һԪ�������������� */
#include <iostream>
using namespace std;
int v1=10;//globle v1
int main(){
	int v1=20;
	//��"::"����ͬ��ȫ�ֱ���
	cout<<"globle v1="<<::v1<<" v1="<<v1;
	return 0;
} 
