/*
此文件为客户端，提供进入程序的接口，用户通过输入
账户密码获取处理对象，把对象标记传给后台进行处理 
除了提供的接口，核心程序还是进行私密封装防止恶意
修改 

*/

#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include "database.h"
#include "rear-end.h"

using namespace std;

class User : public Database{
	private:
		int sign;
	
	public:
		//提供给用户的接口，用户输入账户密码进入系统 		
		User(int p, long int a){
			if(acc_exists(a)){
				if(password_access(p)){
					Atm a(sign);           //将对象标记传递给后台			
				}								
			}
			else{
				system("cls"); 
				cout<<"账户不存在！"<<endl;
				exit(-1); 
			}
			
		}
		
		//获取账号 
		long int putAcc(){
			long int a;
			cout<<"请输入账号：";
			cin>>a;
			return a; 
		}
		
		//获取密码 
		int putPassword(){
			int p;
	
			cout<<"请输入密码："; 
			p = password_hide();
			
		}
		
	private:
		//密码隐藏 
		int password_hide(){
			char p[11] = {"\0"};
			int count, s, n = 0;
			for(count = 0; count < 6; count++){
			s = getch();
			cout<<"*";	
			p[count] = s;		
			n = n * 10 + p[count] - '0';				
			}
	
			return n;
		}
		
		//判断用户是否存在，并获取处理对象 
		bool acc_exists(long int a){
			int i;		
			for(i = 0; i < n; i++){
				if(a == users[i].acc){
					this->sign = i;
						if(users[sign].flag == 0){
							system("cls"); 
							cout<<"账户已经被冻结";
							exit(0); 
						}
					return true;
				}
			}
			
			return false;			
		}
		
		//判断密码是否正确 （3次错误就冻结账户） 
		bool password_access(int p){
			int count = 0;
				while(count != 3){
					if(p != users[sign].password){
						system("cls"); 
						cout<<"密码错误请重新输入："; 
						p = password_hide(); 
					}
					else{					
						return true;
					}
					count++;
				}
			system("cls"); 
			cout<<"输入次数过多，你的账户已经被冻结";
			users[sign].flag = 0;				           //冻结账户 
			Database::updateUserInformation();             //储存冻结状态 
			exit(-1);			
		}
	
};
