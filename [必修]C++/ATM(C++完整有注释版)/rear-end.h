/*
此文件为后台数据处理文件，涉及许多关键核心程序，所以大多成员
用private修饰防止被恶意修改；仅提供了构造器一个接口。（注意程
序员通道“友元函数”可以强制进入，但目前这个通道已经被我关闭） 
*/
#include <iostream>
#include <stdlib.h>
#include <stdio.h> 
#include "database.h"

using namespace std;

class Atm : public Database{
	
	private:
		int sign;	//标记处理成员	
	public:
		//接收客户端传递过来的数据成员标记，确定处理对象 
		Atm(int s){
			sign = s;
			showMenu_1();		
		}		
		
	private:
		//一级菜单 
	void showMenu_1(){
		int s1; 
		system("cls");
		cout<<"1：取款\t\t\t\t2: 存款"<<endl;
		cout<<"3: 转账\t\t\t\t4: 查询余额"<<endl;
		cout<<"5: 修改密码\t\t\t6: 退出\n\n"<<endl;
		getTime(); 
		cout<<"\n\n\n\n\n请输入你需要的操作：";
		cin>>s1;
		this->getSelect(s1);
	}	
	
	//二级菜单 
	void showMenu_2(){
		int s2; 
		system("cls");
		cout<<"7: 返回\t\t\t\t8: 打印操作记录"<<endl;
		cout<<"6: 退出\n"<<endl;
		getTime(); 
		cout<<"\n\n\n\n\n请输入你需要的操作：";
		cin>>s2;
		this->getSelect(s2);

	}

	//获取选择，根据用户选择对象选取不同的操作 
	void getSelect(int s){
		switch(s){
			case 1:
				this->select_1();
				break;
			case 2:
				this->select_2();
				break;
			case 3:
				this->select_3();
				break;
			case 4:
				this->select_4();
				break;
			case 5:
				this->select_5();
				break;
			case 6:
				this->select_6();
				break;
			case 7:
				this->select_7();
				break;
			case 8:
				this->select_8();
				break;
			default:
				cout<<"输入错误！！"<<endl;
				system("pause");
				this->showMenu_1(); 
				break; 
		}		
	}
	
	//取款（涉及金额限制）	
	void select_1(){
		int p, count = 0;
		system("cls");
		cout<<"请输入要取出的金额(单次操作金额不许超过10000元)：";
		cin>>p;
		
		if(!(p>0 && p <= 10000)){            //限制输入金额（下同） 
			system("cls");
			cout<<"输入金额错误！\n";
			system("pause");
			this->showMenu_2();			 
		} 
	
		if(p > users[sign].money){           //余额判断 （下同） 
			cout<<"余额不足"<<endl; 	
		} 
		else{ 
			while(p % 50 != 0){              //限制金额（下同） 
				system("cls");
				cout<<"输入的金额只能是50的倍数，请重新输入：";
				cin>>p;
				count++;
				if(count == 3){
					system("cls");
					cout<<"操作错误次数过多!\n";
					system("pause");
					this->showMenu_2();
				}
			}			
			users[sign].money -= p;
			cout<<"取款成功"<<endl;
			operatingData(1, sign, p);
			system("pause"); 
		}
		
		this->showMenu_2();
	
	}

	//存款（涉及金额限制）	
	void select_2(){
		int p, count = 0;
		system("cls");
		cout<<"请输入要取存入的金额(单次操作金额不许超过10000元)：";
		cin>>p;
		
		if(!(p>0 && p <= 10000)){
			system("cls");
			cout<<"输入金额错误！\n";
			system("pause");
			this->showMenu_2();			 
		} 
		
		while(p % 50 != 0){
			system("cls");
			cout<<"输入的金额只能是50的倍数，请重新输入：";
			cin>>p;
			count++;
				if(count == 3){
					system("cls");
					cout<<"操作错误次数过多!\n";
					system("pause");
					this->showMenu_2();
				}
			}			
		
		users[sign].money += p;
		system("cls");
		cout<<"存款成功"<<endl;
		
		operatingData(2, sign, p);
		
		system("pause"); 
		
		this->showMenu_2();


		
	}
	
	//转账 
	void select_3(){
		int p, i, count = 0;
		long int other_acc;
		
		system("cls");
		cout<<"请输入对方账户：";
		cin>> other_acc;
		
		for(i = 0; i < n; i++){                       //账户判断 
			if(other_acc == users[i].acc){
				if(other_acc == users[sign].acc){
					system("cls");
					cout<<"不能转账给自己的账户"<<endl;
					break;
				}
				
				cout<<"请输入转账金额(单次操作金额不许超过10000元)：";
				cin>>p;
				if(!(p>0 && p <= 10000)){
					system("cls");
					cout<<"输入金额错误！\n";
					system("pause");
					this->showMenu_2();			 
				} 
			
				while(p % 50 != 0){
					system("cls");
					cout<<"输入的金额只能是50的倍数，请重新输入：";
					cin>>p;
					count++;
					if(count == 3){
					system("cls");
					cout<<"操作错误次数过多!\n";
					system("pause");
					this->showMenu_2();
				}
			}	
			
			if(p > users[sign].money){
				cout<<"你当前余额不足！"; 
				system("pause");
				this->showMenu_1(); 
			}	
				
				system("cls");
				users[sign].money -= p;
				users[i].money += p;
				cout<<"转账成功"<<endl;	
				operatingData(3, sign, p);			
				break;
			}
				
		}
		
		if(other_acc != users[i].acc){
			cout<<"账户不存在"<<endl; 
		}
		
		system("pause"); 
		
		this->showMenu_2();	 		
	}
	
	//查询余额 
	void select_4(){
		system("cls");
		cout<<"你当前的余额是："<<users[sign].money<<endl;
		operatingData(4, sign, 0); 
		system("pause");
		this->showMenu_2();	 
	}
	
	//修改密码 
	void select_5(){
		int p1, p2;
		system("cls");
		cout<<"请输入原密码：";
		cin>>p1;
		
		if(p1 == users[sign].password){
			cout<<"请输入新的密码(此处密码为可视密码)：";
			cin>>p2;
			users[sign].password = p2;
			cout<<"密码修改成功"<<endl;
			operatingData(5, sign, 0);
		}
		else{
			cout<<"原密码不正确"<<endl; 
		}
		
		system("pause");
		this->showMenu_2();	 		
	}
	
	//退出程序 
	void select_6(){
		system("cls"); 
		cout<<"感谢你的使用!!";
		Database::updateUserInformation();
		exit(0);
	}
	
	//返回一级菜单界面 
	void select_7(){
		this->showMenu_1();		
	}
	
	//操作记录 
	void select_8(){		
		cout<<"操作记录已经生成！！";
		this->showMenu_2();	  
	}	
	
};
