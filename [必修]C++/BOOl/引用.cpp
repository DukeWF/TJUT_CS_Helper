/* TODO (#1#): ������������� */
#include <iostream>
using namespace std;
//ֵ���ݣ��޷����� 
void swap(int n1, int n2){
	int t=n1;
	n1=n2;
	n2=t;
}
//ָ�봫�� 
void swap(int* n1, int* n2){
	int t=*n1;
	*n1=*n2;
	*n2=t;
}
//���ô��� 
void swap(int& n1, int& n2){
	int t=n1;
	n1=n2;
	n2=t;
}
int main(){
	int x=1;
	int& rx=x;
	//��һ��д��
	int y=2, &ry=y;
	cout<<"Normal��"<<x<<" "<<y<<endl;
	swap(&x,&y);
	cout<<"Now   ��"<<x<<" "<<y<<endl;
}
int main(){
	int x=1;
	int& rx=x;
	//��һ��д��
	int y=2, &ry=y;
	cout<<"Normal��"<<x<<" "<<y<<endl;
	swap(x,y);
	cout<<"Now   ��"<<x<<" "<<y<<endl;
}
int main(){
	int x=1;
	int& rx=x;
	//��һ��д��
	int y=2, &ry=y;
	cout<<"Normal��"<<x<<" "<<y<<endl;
	swap(x,y);
	cout<<"Now   ��"<<x<<" "<<y<<endl;
}
