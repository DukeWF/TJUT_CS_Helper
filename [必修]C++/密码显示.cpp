#include<iostream>
#include<conio.h>
using namespace std;
int main(){
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
		else if(ch=='\r'){//屏蔽回车键 
		}
		else{//密文显示 
			cout<<"*";
			password[i++]=ch;
		}
	//判断部分结束
	}while(i<6);
	cout<<endl<<"password:"<<password<<endl;	
	//转换部分：转换char*为int 
	int temp=0;
	for(i=0;i<6;i++){
		temp=temp*10+(password[i]-'0');
	}
	//转换部分结束 
	cout<<endl<<temp;
	return 0;
}
