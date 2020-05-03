/*
此文件用来模拟数据库操作 ，从文件中读取用户数据并且保存操作
*/
#include <string.h>
#include <time.h>
#include <fstream>
#include <stdlib.h>
#ifndef _TOOL_H_
#define _TOOL_H_

using namespace std;

//此结构体模拟数据库中的表，储存用户数据 
struct Data{
		string name;
		long int acc;
		int password;
		int money;
		int flag; 
};

class Database{	
	protected:
		struct Data * users;  //结构体指针 
		int n;                //统计文件中成员个数（表中有多少列） 
		int sign;			  //标记从客户端登陆的数据成员 
	
	public:
		//客户端操作接口 
		Database(){
			n = getNumber();  //获取成员数量 
			
			users = new struct Data[n]; //在堆中动态创建数据空间 
			
			getUserInformation();    //将文件中数据读入内存 
		}
		//客户端注册接口 
		Database(int i){
			n = getNumber();       // 获取成员数量 
			
			users = new struct Data[n];  //在堆中动态创建数据空间 
			
			getUserInformation();    //将文件中数据读入内存
			
			appendUser();        //添加新成员 
			
		}
		//程序员测试接口 
		Database(int i, int j){
			n = getNumber();
			
			users = new struct Data[n];
			
			getUserInformation();
			
			test();
			
			operatingData(1, 1, 0);
			operatingData(2, 2, 0);
			operatingData(3, 3, 0);
							
		}
		
		virtual ~Database(){
			delete []users;
		}
		
		protected:
		//将文件中数据读入内存
		void getUserInformation(){         
			fstream fin("用户信息.txt", ios::in|ios::out|ios::binary);
			
			if(!fin){
				cout<<"系统故障！";
				exit(-1); 
			}
			
			for(int i = 0; i < n; i++){
				fin>>users[i].name>>users[i].acc>>users[i].password>>users[i].money>>users[i].flag;
			}
			
			fin.close();
		}
	
		//更新文件中数据读入内存
		void updateUserInformation(){
			fstream fout("用户信息.txt", ios::out|ios::in|ios::binary);
			
			if(!fout){
				cout<<"系统故障！";
				exit(-1); 
			}
			
			for(int i = 0; i < n; i++){
			fout<<users[i].name<<" "<<users[i].acc<<" "<<users[i].password<<" "<<users[i].money<<" "<<users[i].flag<<endl;
			}
			
			fout.close();		
		}
		
		//在文件中添加新成员 
		void appendUser(){
			struct Data newUser;
			fstream fapp("用户信息.txt", ios::app|ios::out|ios::binary);
			
			if(!fapp){
				cout<<"系统故障！";
				exit(-1); 
			}
			
			cout<<"姓名：";
			cin>>newUser.name;
			cout<<"账户（账户只能为以“2245”开头的6位数）：2245"; 
			cin>>newUser.acc;
			if(newUser.acc < 0 || newUser.acc > 99){
				cout<<"输入账户格式不正确";
				exit(-1); 
			}
			newUser.acc += 224500;		
			cout<<"密码：";  
			cin>>newUser.password;
			newUser.money = 0;
			newUser.flag = 1;
			
			for(int i = 0; i < n;i++){
				if(newUser.acc == users[i].acc){
					cout<<"用户已经存在";
					exit(0);
				}
			}
			  
			fapp<<"\n"<<newUser.name<<" "<<newUser.acc<<" "<<newUser.password<<" "<<newUser.money<<" "<<newUser.flag;
			
			fapp.close();
		
			cout<<"注册成功";
			exit(0); 
		}
		
		//获取文件中成员个数 
		int getNumber(){
			struct _stat info;  
			_stat("用户信息.txt", &info);  
			int size = info.st_size;		
			return int(size/(sizeof(Data)+4));  		
		}
		
		//将操作记录写入文件 
		void operatingData(int i, int len, int money){
			fstream fout("操作记录.txt", ios::out|ios::app|ios::binary);
			
			switch(i){
				case 1:
					fout<<users[len].name<<"取出了"<<money<<"元... \n";
					break; 
				case 2:
					fout<<users[len].name<<"存储了"<<money<<"元... \n";
					break; 
				case 3:
					fout<<users[len].name<<"转出了"<<money<<"元... \n";
					break; 
				case 4:
					fout<<users[len].name<<"查询了余额... \n";
					break; 		
				case 5:
					fout<<users[len].name<<"修改了密码... \n";
					break; 		
			}
			
			fout.close(); 
		}
		
		//获取系统时间 
		void getTime(){
		
		time_t t = time(0); 
    	char tmp[64]; 
   	 	
		strftime(tmp, sizeof(tmp), "%Y/%m/%d %X %A 本年第%j天 %z" ,localtime(&t)); 
    	
		puts(tmp); 

		}
	
		//程序员测试函数，可以无视 
		void test(){
			for(int i = 0; i < n; i++){
			cout<<users[i].name<<" "<<users[i].acc<<" "<<users[i].password<<" "<<users[i].money<<" "<<users[i].flag<<endl;
			}
		}
	
};

#endif
