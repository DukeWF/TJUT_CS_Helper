#include <iostream>
#include <stdlib.h>
#include "user.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int s;
	
	cout<<"\t��ӭʹ�ñ���ģ��ϵͳ\n\n\n\n"<<endl;
	cout<<"1.��½\t\t\t\t2.ע��"<<endl; 
	cout<<"����������Ҫ�Ĳ�����";
	cin>>s;
	
	system("cls");
	
	//��½ϵͳ 
	if(s == 1){
		User u(u.putPassword(), u.putAcc());		
	}
	//ע���³�Ա 
	else if(s == 2){
		Database creatNewUser(1);
	}
	//����Ա��̨���������������� 
	else if(s == 111111){
		Database textNewUser(1, 1);
	}
	else{
		cout<<"��������"; 
	}
	return 0;
}
