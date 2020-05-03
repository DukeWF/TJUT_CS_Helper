#include "ATM.h"

void ATM::welcome(){
	PAUSE;
	CLS;
	int t=0;
	cout<<endl<<"欢迎使用ATM模拟系统！"<<endl;
	cout<<"请插入您的卡片"<<endl;
	PAUSE;
	CLS; 
	cout<<"请输入您的密码:";
	while(1){
		if(cm.judge_pw()==1){
			cout<<endl<<"密码正确！"<<endl;
			PAUSE;
			break;
		}
		else{
			t++;
			CLS;
			cout<<"密码错误！"<<endl;			
			if(t>=3){
				cout<<"ERROR：错误次数已达到3次，已吞卡，请联系工作人员!"<<endl;
				exit(-1); 
			}
			cout<<"请输入您的密码:";
		}
	}
	CLS;
	menu();
}

void ATM::menu(){
	char ch;
	show_menu();
	do{
		ch=getch();
		switch(ch){
			case 'A':{
				deposit();
				show_menu();
				break;
			}
			case 'B':{
				withdraw();
				show_menu();
				break;
			}
			case 'C':{
				transfer();
				show_menu();
				break;
			}
			case 'D':{
				show_money();
				show_menu();
				break;
			}
			case 'E':{
				show_information();
				show_menu();
				break;
			}
			case 'F':{
				change_pw();
				show_menu();
				break;
			}			
			case 'Q':{//退卡结束
				CLS;
				cout<<"请收好您的卡片，感谢使用！"; 
				exit(0);
				break;	
			}
			default:{
				CLS; 
				cout<<"您的输入有误，请重新输入！";
				show_menu();
				break;
			}
		}				
	}while(1);
}

void ATM::show_menu(){
	PAUSE;
	CLS;
	cout<<endl<<"请选择以下操作："<<endl<<endl;
	cout<<"A.存款"<<endl<<"B.取款"<<endl<<"C.转账"<<endl<<"D.余额查询"<<endl<<"E.个人信息查询"<<endl<<"F.密码修改"<<endl<<"Q.退卡"<<endl;
}

void ATM::deposit(){
//存款操作 
	CLS;
	show_deposit();
	int temp=ATM::judge_num();
	cm.set_money(temp);
	show_deposit(temp);
}
void ATM::withdraw(){
//取款操作 
	CLS;
	char ch;
	show_withdraw();
	do{
		ch=getch();
		switch(ch){
			case 'A':{
				if(cm.get_money()>=100){
					cm.set_money(-100);
					show_withdraw(100);
				}
				else show_withdraw(100,0);
				PAUSE;
				withdraw();
				break;
			}
			case 'B':{
				if(cm.get_money()>=200){
					cm.set_money(-200);
					show_withdraw(200);
				}
				else show_withdraw(200,0); 
				PAUSE;
				withdraw();
				break;
			}
			case 'C':{
				if(cm.get_money()>=500){
					cm.set_money(-500);
					show_withdraw(500);
				}
				else show_withdraw(500,0); 
				PAUSE;
				withdraw();		
				break;
			}
			case 'D':{
				if(cm.get_money()>=1000){
					cm.set_money(-1000);
					show_withdraw(1000);
				}
				else show_withdraw(1000,0);
				PAUSE;
				withdraw();
				break;
			}
			case 'E':{
				show_withdraw(0); 
				int temp_money=judge_num();
				if(cm.get_money()==0){
					show_withdraw(0,2);
				}
				else if(cm.get_money()>=temp_money){
					cm.set_money(-temp_money);
					show_withdraw(temp_money);
				}
				else show_withdraw(temp_money,0);
				PAUSE;
				withdraw();
				break;
			}
			case 'Q':{
				menu();
				break;
			}
			default:{
				show_withdraw(0,-2);
				show_withdraw();
				break;
			}
		}
	}while(1);
}

void ATM::transfer(){
	CLS;
	int id,mo;
	do{
		int t=0;
		show_transfer(1);
		cin>>id;
		/*此处添加检验ID接口*/		//待更新 ver 2.0 
		show_transfer(2);
		cin>>mo;
		/*此处添加检验Money接口*/	//待更新 ver 2.0 
		if(mo>cm.get_money()){
			show_transfer(mo,id,0);
			PAUSE;
			t++;
		}
		else if(t>=3){
			show_transfer(mo,id,-3); 
			PAUSE;
			break;
		}
		else{
			cm.set_money(-mo);
		/*此处添加转账另外账户的信息，否则伪转账*/	//待更新 ver 2.0 
			show_transfer(mo,id,1);
			break;
		} 
	}while(1);
}
void ATM::change_pw(){
	int temp,t=0;
	while(1){
		CLS;
		cout<<"请输入新密码：";
		temp=cm.set_pw();
		cout<<"请再次输入新密码：";
		if(temp==cm.set_pw()){
			if(cm.judge_pw(temp)){
				cout<<"新密码与原密码相同，请重新输入！"<<endl;
				PAUSE; 
				t++;
				if(t>=3){
					cout<<"您的错误次数已达到3次，已吞卡，请联系客服中心。";
					PAUSE; 
					exit(-1); 
				}
			}
			else{
				cout<<"密码修改成功！";
				cm.set_pw(temp);
				break;			
			}
		}
		else{
			cout<<"您两次输入的密码不相同，请重新输入！"<<endl;	
			PAUSE; 			
			t++;
			if(t>=3){
				cout<<"您的错误次数已达到3次，已吞卡，请联系客服中心。"<<endl;
				PAUSE; 
				exit(-1);
			}					
		}
	}
}

void ATM::show_deposit(){
	CLS;
	cout<<endl<<"请输入存款金额:";
}

void ATM::show_deposit(int a){
	CLS;
	cout<<endl<<"存款"<<a<<"元成功！";
}

void ATM::show_withdraw(){
	CLS;
	cout<<endl<<"请选择取款金额："<<endl;
	cout<<"A:100"<<endl<<"B:200"<<endl<<"C:500"<<endl<<"D:1000"<<endl<<"E:其他金额"<<endl<<"Q:返回主菜单"<<endl;	
}

void ATM::show_withdraw(int a){
//一些基本的取款交互信息 
	CLS;
	if(a==0)
		cout<<endl<<"请选择取款金额："<<endl;
	else
		cout<<"取款"<<a<<"元成功！"<<endl;
}

void ATM::show_withdraw(int mo,int i){
//一些基本的取款错误提示
	CLS;
	if(i==0)
		cout<<endl<<"ERROR:取款"<<mo<<"元失败！您的账户余额不足！";
	else if(i==-1)                                                            
		cout<<endl<<"ERROR:取款"<<mo<<"元失败！ATM故障！请联系客服中心！";
	else if(i==-2)
		cout<<endl<<"ERROR:您的输入有误！"<<endl<<"请重新输入:";
	else if(i==-3)
		cout<<"ERROR:您的错误次数已达到3次，已退卡，感谢您的使用，再见！"<<endl;
}

void ATM::show_transfer(int i){
	if(i==1){
		CLS;
		cout<<endl<<"请输入您要转账的账户ID：";		
	}		
	else if(i==2)
		cout<<endl<<"请输入转账金额：";
}

void ATM::show_transfer(int mo, int id, int i){
	CLS;
	if(i==1)
		cout<<"转账至 ID："<<id<<" ，"<<mo<<"元成功！";
	else if(i==0)
		cout<<"ERROR:转账至 ID："<<id<<" ，"<<mo<<"元失败！您的账户余额不足！";
	else if(i==-1)
		cout<<endl<<"ERROR:转账至 ID："<<id<<" ，"<<mo<<"元失败！ATM故障！请联系客服中心！";
	else if(i==-2)
		cout<<endl<<"ERROR:您的输入有误！"<<endl<<"请重新输入:";
	else if(i==-3)
		cout<<"ERROR:您的错误次数已达到3次，已退卡，感谢您的使用，再见！"<<endl;

}

void ATM::show_money(){
	CLS;
	cout<<endl<<"当前余额："<<cm.get_money()<<endl;
}

void ATM::show_information(){
//格式化输出
	CLS;
	cout<<" _______________________________________ "<<endl;
	cout<<"|                                       |"<<endl; 
	cout<<"|\t\t账户基本信息\t\t|"<<endl;
	cout<<"|\t用户名:"<<cm.get_name()<<"\t\t\t|"<<endl;
	cout<<"|\t卡号:"<<cm.get_ID()<<"\t\t\t|"<<endl;
	cout<<"|\t余额:"<<cm.get_money()<<"\t\t\t|"<<endl;
	cout<<"|\t密码:"<<cm.get_pw()<<"\t\t\t|"<<endl;
	cout<<"|_______________________________________|"<<endl;
}

int ATM::judge_num(){//判断非整100数 
	int num;
	while(1){
		while(!(cin>>num)){ //cin输入错误时执行下边语句
		    cin.clear(); //清除流标记
		    cin.sync();  //清空流
		    cout<<"ERROR:您输入了非数字字符"<<endl<<"请重新输入："; //打印错误提示
		}
		if(num%100==0)
			return num;
		else{
		    cin.clear(); //清除流标记
		    cin.sync();  //清空流
		    cout<<"ERROR：您的金额不满足逻辑要求"<<endl<<"请重新输入："; //打印错误提示		    
		}
	}
}


