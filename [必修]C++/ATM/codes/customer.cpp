#include "customer.h"
//#include <cstring>
#include <conio.h>
customer::customer(){
	cout<<"ID:";
	cin>>ID;
	cout<<"Name:";
	cin>>name;
	cout<<"Money:";
	cin>>money;
	cout<<"Password:";
	password=set_pw();
}
int customer::judge_pw(){
	int t=set_pw();
	if(t==password)
		return 1;//������ͬ ����1 
	else return 0;//���벻��ͬ ����0 
}

int customer::judge_pw(int i){
	if(i==password)
		return 1;//������ͬ ����1 
	else return 0;//���벻��ͬ ����0 
}

int customer::set_pw(){
	char password[100];
	int i=0;
	do{
		char ch;
		ch=getch();
	//�жϲ��֣�ʵ���˸����������������ʾ�����λس�������
		if(ch==8){ //�˸��
			if(i!=0){	
			cout<<char(8)<<" "<<char(8);
			i--;//Ǳ��BUG��i<0������ 
			}
		}
		else if(ch>='0'&&ch<='9'){//������ʾ 
			cout<<"*";
			password[i++]=ch;
		}
	//�жϲ��ֽ���
	}while(i<6);
	//ת�����֣�ת��char*Ϊint 
	int temp=0;
	for(i=0;i<6;i++){
		temp=temp*10+(password[i]-'0');
	}
	//ת�����ֽ���
	cout<<endl;
//	system("pause");
	return temp;
}

void customer::set_pw(int pw){
	password=pw;
}

void customer::set_money(int mo){
	money+=mo;
}

string customer::get_ID(){
	return ID;
}

double customer::get_money(){
	if(money>=0)
		return money;
	else{
		cout<<"�����������"<<endl;
		exit(-1);
	}
}

string customer::get_name(){
	return name;
}

int customer::get_pw(){
	return password;
}

