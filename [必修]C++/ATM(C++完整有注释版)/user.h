/*
���ļ�Ϊ�ͻ��ˣ��ṩ�������Ľӿڣ��û�ͨ������
�˻������ȡ������󣬰Ѷ����Ǵ�����̨���д��� 
�����ṩ�Ľӿڣ����ĳ����ǽ���˽�ܷ�װ��ֹ����
�޸� 

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
		//�ṩ���û��Ľӿڣ��û������˻��������ϵͳ 		
		User(int p, long int a){
			if(acc_exists(a)){
				if(password_access(p)){
					Atm a(sign);           //�������Ǵ��ݸ���̨			
				}								
			}
			else{
				system("cls"); 
				cout<<"�˻������ڣ�"<<endl;
				exit(-1); 
			}
			
		}
		
		//��ȡ�˺� 
		long int putAcc(){
			long int a;
			cout<<"�������˺ţ�";
			cin>>a;
			return a; 
		}
		
		//��ȡ���� 
		int putPassword(){
			int p;
	
			cout<<"���������룺"; 
			p = password_hide();
			
		}
		
	private:
		//�������� 
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
		
		//�ж��û��Ƿ���ڣ�����ȡ������� 
		bool acc_exists(long int a){
			int i;		
			for(i = 0; i < n; i++){
				if(a == users[i].acc){
					this->sign = i;
						if(users[sign].flag == 0){
							system("cls"); 
							cout<<"�˻��Ѿ�������";
							exit(0); 
						}
					return true;
				}
			}
			
			return false;			
		}
		
		//�ж������Ƿ���ȷ ��3�δ���Ͷ����˻��� 
		bool password_access(int p){
			int count = 0;
				while(count != 3){
					if(p != users[sign].password){
						system("cls"); 
						cout<<"����������������룺"; 
						p = password_hide(); 
					}
					else{					
						return true;
					}
					count++;
				}
			system("cls"); 
			cout<<"����������࣬����˻��Ѿ�������";
			users[sign].flag = 0;				           //�����˻� 
			Database::updateUserInformation();             //���涳��״̬ 
			exit(-1);			
		}
	
};
