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
		return 1;//密码相同 返回1 
	else return 0;//密码不相同 返回0 
}

int customer::judge_pw(int i){
	if(i==password)
		return 1;//密码相同 返回1 
	else return 0;//密码不相同 返回0 
}

int customer::set_pw(){
	char password[100];
	int i=0;
	do{
		char ch;
		ch=getch();
	//判断部分：实现退格重新输出，密文显示与屏蔽回车键功能
		if(ch==8){ //退格键
			if(i!=0){	
			cout<<char(8)<<" "<<char(8);
			i--;//潜在BUG？i<0存在吗？ 
			}
		}
		else if(ch>='0'&&ch<='9'){//密文显示 
			cout<<"*";
			password[i++]=ch;
		}
	//判断部分结束
	}while(i<6);
	//转换部分：转换char*为int 
	int temp=0;
	for(i=0;i<6;i++){
		temp=temp*10+(password[i]-'0');
	}
	//转换部分结束
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
		cout<<"余额数据有误！"<<endl;
		exit(-1);
	}
}

string customer::get_name(){
	return name;
}

int customer::get_pw(){
	return password;
}

