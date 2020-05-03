#include "ATM.h"

void ATM::welcome(){
	PAUSE;
	CLS;
	int t=0;
	cout<<endl<<"��ӭʹ��ATMģ��ϵͳ��"<<endl;
	cout<<"��������Ŀ�Ƭ"<<endl;
	PAUSE;
	CLS; 
	cout<<"��������������:";
	while(1){
		if(cm.judge_pw()==1){
			cout<<endl<<"������ȷ��"<<endl;
			PAUSE;
			break;
		}
		else{
			t++;
			CLS;
			cout<<"�������"<<endl;			
			if(t>=3){
				cout<<"ERROR����������Ѵﵽ3�Σ����̿�������ϵ������Ա!"<<endl;
				exit(-1); 
			}
			cout<<"��������������:";
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
			case 'Q':{//�˿�����
				CLS;
				cout<<"���պ����Ŀ�Ƭ����лʹ�ã�"; 
				exit(0);
				break;	
			}
			default:{
				CLS; 
				cout<<"���������������������룡";
				show_menu();
				break;
			}
		}				
	}while(1);
}

void ATM::show_menu(){
	PAUSE;
	CLS;
	cout<<endl<<"��ѡ�����²�����"<<endl<<endl;
	cout<<"A.���"<<endl<<"B.ȡ��"<<endl<<"C.ת��"<<endl<<"D.����ѯ"<<endl<<"E.������Ϣ��ѯ"<<endl<<"F.�����޸�"<<endl<<"Q.�˿�"<<endl;
}

void ATM::deposit(){
//������ 
	CLS;
	show_deposit();
	int temp=ATM::judge_num();
	cm.set_money(temp);
	show_deposit(temp);
}
void ATM::withdraw(){
//ȡ����� 
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
		/*�˴���Ӽ���ID�ӿ�*/		//������ ver 2.0 
		show_transfer(2);
		cin>>mo;
		/*�˴���Ӽ���Money�ӿ�*/	//������ ver 2.0 
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
		/*�˴����ת�������˻�����Ϣ������αת��*/	//������ ver 2.0 
			show_transfer(mo,id,1);
			break;
		} 
	}while(1);
}
void ATM::change_pw(){
	int temp,t=0;
	while(1){
		CLS;
		cout<<"�����������룺";
		temp=cm.set_pw();
		cout<<"���ٴ����������룺";
		if(temp==cm.set_pw()){
			if(cm.judge_pw(temp)){
				cout<<"��������ԭ������ͬ�����������룡"<<endl;
				PAUSE; 
				t++;
				if(t>=3){
					cout<<"���Ĵ�������Ѵﵽ3�Σ����̿�������ϵ�ͷ����ġ�";
					PAUSE; 
					exit(-1); 
				}
			}
			else{
				cout<<"�����޸ĳɹ���";
				cm.set_pw(temp);
				break;			
			}
		}
		else{
			cout<<"��������������벻��ͬ�����������룡"<<endl;	
			PAUSE; 			
			t++;
			if(t>=3){
				cout<<"���Ĵ�������Ѵﵽ3�Σ����̿�������ϵ�ͷ����ġ�"<<endl;
				PAUSE; 
				exit(-1);
			}					
		}
	}
}

void ATM::show_deposit(){
	CLS;
	cout<<endl<<"����������:";
}

void ATM::show_deposit(int a){
	CLS;
	cout<<endl<<"���"<<a<<"Ԫ�ɹ���";
}

void ATM::show_withdraw(){
	CLS;
	cout<<endl<<"��ѡ��ȡ���"<<endl;
	cout<<"A:100"<<endl<<"B:200"<<endl<<"C:500"<<endl<<"D:1000"<<endl<<"E:�������"<<endl<<"Q:�������˵�"<<endl;	
}

void ATM::show_withdraw(int a){
//һЩ������ȡ�����Ϣ 
	CLS;
	if(a==0)
		cout<<endl<<"��ѡ��ȡ���"<<endl;
	else
		cout<<"ȡ��"<<a<<"Ԫ�ɹ���"<<endl;
}

void ATM::show_withdraw(int mo,int i){
//һЩ������ȡ�������ʾ
	CLS;
	if(i==0)
		cout<<endl<<"ERROR:ȡ��"<<mo<<"Ԫʧ�ܣ������˻����㣡";
	else if(i==-1)                                                            
		cout<<endl<<"ERROR:ȡ��"<<mo<<"Ԫʧ�ܣ�ATM���ϣ�����ϵ�ͷ����ģ�";
	else if(i==-2)
		cout<<endl<<"ERROR:������������"<<endl<<"����������:";
	else if(i==-3)
		cout<<"ERROR:���Ĵ�������Ѵﵽ3�Σ����˿�����л����ʹ�ã��ټ���"<<endl;
}

void ATM::show_transfer(int i){
	if(i==1){
		CLS;
		cout<<endl<<"��������Ҫת�˵��˻�ID��";		
	}		
	else if(i==2)
		cout<<endl<<"������ת�˽�";
}

void ATM::show_transfer(int mo, int id, int i){
	CLS;
	if(i==1)
		cout<<"ת���� ID��"<<id<<" ��"<<mo<<"Ԫ�ɹ���";
	else if(i==0)
		cout<<"ERROR:ת���� ID��"<<id<<" ��"<<mo<<"Ԫʧ�ܣ������˻����㣡";
	else if(i==-1)
		cout<<endl<<"ERROR:ת���� ID��"<<id<<" ��"<<mo<<"Ԫʧ�ܣ�ATM���ϣ�����ϵ�ͷ����ģ�";
	else if(i==-2)
		cout<<endl<<"ERROR:������������"<<endl<<"����������:";
	else if(i==-3)
		cout<<"ERROR:���Ĵ�������Ѵﵽ3�Σ����˿�����л����ʹ�ã��ټ���"<<endl;

}

void ATM::show_money(){
	CLS;
	cout<<endl<<"��ǰ��"<<cm.get_money()<<endl;
}

void ATM::show_information(){
//��ʽ�����
	CLS;
	cout<<" _______________________________________ "<<endl;
	cout<<"|                                       |"<<endl; 
	cout<<"|\t\t�˻�������Ϣ\t\t|"<<endl;
	cout<<"|\t�û���:"<<cm.get_name()<<"\t\t\t|"<<endl;
	cout<<"|\t����:"<<cm.get_ID()<<"\t\t\t|"<<endl;
	cout<<"|\t���:"<<cm.get_money()<<"\t\t\t|"<<endl;
	cout<<"|\t����:"<<cm.get_pw()<<"\t\t\t|"<<endl;
	cout<<"|_______________________________________|"<<endl;
}

int ATM::judge_num(){//�жϷ���100�� 
	int num;
	while(1){
		while(!(cin>>num)){ //cin�������ʱִ���±����
		    cin.clear(); //��������
		    cin.sync();  //�����
		    cout<<"ERROR:�������˷������ַ�"<<endl<<"���������룺"; //��ӡ������ʾ
		}
		if(num%100==0)
			return num;
		else{
		    cin.clear(); //��������
		    cin.sync();  //�����
		    cout<<"ERROR�����Ľ������߼�Ҫ��"<<endl<<"���������룺"; //��ӡ������ʾ		    
		}
	}
}


