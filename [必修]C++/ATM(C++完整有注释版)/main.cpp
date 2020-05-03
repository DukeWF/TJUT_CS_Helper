#include <iostream>
#include <stdlib.h>
#include "user.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int s;
	
	cout<<"\t欢迎使用本套模拟系统\n\n\n\n"<<endl;
	cout<<"1.登陆\t\t\t\t2.注册"<<endl; 
	cout<<"请输入你需要的操作：";
	cin>>s;
	
	system("cls");
	
	//登陆系统 
	if(s == 1){
		User u(u.putPassword(), u.putAcc());		
	}
	//注册新成员 
	else if(s == 2){
		Database creatNewUser(1);
	}
	//程序员后台测试区，保密区域 
	else if(s == 111111){
		Database textNewUser(1, 1);
	}
	else{
		cout<<"操作错误！"; 
	}
	return 0;
}
