/*
���ļ�Ϊ��̨���ݴ����ļ����漰���ؼ����ĳ������Դ���Ա
��private���η�ֹ�������޸ģ����ṩ�˹�����һ���ӿڡ���ע���
��Աͨ������Ԫ����������ǿ�ƽ��룬��Ŀǰ���ͨ���Ѿ����ҹرգ� 
*/
#include <iostream>
#include <stdlib.h>
#include <stdio.h> 
#include "database.h"

using namespace std;

class Atm : public Database{
	
	private:
		int sign;	//��Ǵ����Ա	
	public:
		//���տͻ��˴��ݹ��������ݳ�Ա��ǣ�ȷ��������� 
		Atm(int s){
			sign = s;
			showMenu_1();		
		}		
		
	private:
		//һ���˵� 
	void showMenu_1(){
		int s1; 
		system("cls");
		cout<<"1��ȡ��\t\t\t\t2: ���"<<endl;
		cout<<"3: ת��\t\t\t\t4: ��ѯ���"<<endl;
		cout<<"5: �޸�����\t\t\t6: �˳�\n\n"<<endl;
		getTime(); 
		cout<<"\n\n\n\n\n����������Ҫ�Ĳ�����";
		cin>>s1;
		this->getSelect(s1);
	}	
	
	//�����˵� 
	void showMenu_2(){
		int s2; 
		system("cls");
		cout<<"7: ����\t\t\t\t8: ��ӡ������¼"<<endl;
		cout<<"6: �˳�\n"<<endl;
		getTime(); 
		cout<<"\n\n\n\n\n����������Ҫ�Ĳ�����";
		cin>>s2;
		this->getSelect(s2);

	}

	//��ȡѡ�񣬸����û�ѡ�����ѡȡ��ͬ�Ĳ��� 
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
				cout<<"������󣡣�"<<endl;
				system("pause");
				this->showMenu_1(); 
				break; 
		}		
	}
	
	//ȡ��漰������ƣ�	
	void select_1(){
		int p, count = 0;
		system("cls");
		cout<<"������Ҫȡ���Ľ��(���β���������10000Ԫ)��";
		cin>>p;
		
		if(!(p>0 && p <= 10000)){            //�����������ͬ�� 
			system("cls");
			cout<<"���������\n";
			system("pause");
			this->showMenu_2();			 
		} 
	
		if(p > users[sign].money){           //����ж� ����ͬ�� 
			cout<<"����"<<endl; 	
		} 
		else{ 
			while(p % 50 != 0){              //���ƽ���ͬ�� 
				system("cls");
				cout<<"����Ľ��ֻ����50�ı��������������룺";
				cin>>p;
				count++;
				if(count == 3){
					system("cls");
					cout<<"���������������!\n";
					system("pause");
					this->showMenu_2();
				}
			}			
			users[sign].money -= p;
			cout<<"ȡ��ɹ�"<<endl;
			operatingData(1, sign, p);
			system("pause"); 
		}
		
		this->showMenu_2();
	
	}

	//���漰������ƣ�	
	void select_2(){
		int p, count = 0;
		system("cls");
		cout<<"������Ҫȡ����Ľ��(���β���������10000Ԫ)��";
		cin>>p;
		
		if(!(p>0 && p <= 10000)){
			system("cls");
			cout<<"���������\n";
			system("pause");
			this->showMenu_2();			 
		} 
		
		while(p % 50 != 0){
			system("cls");
			cout<<"����Ľ��ֻ����50�ı��������������룺";
			cin>>p;
			count++;
				if(count == 3){
					system("cls");
					cout<<"���������������!\n";
					system("pause");
					this->showMenu_2();
				}
			}			
		
		users[sign].money += p;
		system("cls");
		cout<<"���ɹ�"<<endl;
		
		operatingData(2, sign, p);
		
		system("pause"); 
		
		this->showMenu_2();


		
	}
	
	//ת�� 
	void select_3(){
		int p, i, count = 0;
		long int other_acc;
		
		system("cls");
		cout<<"������Է��˻���";
		cin>> other_acc;
		
		for(i = 0; i < n; i++){                       //�˻��ж� 
			if(other_acc == users[i].acc){
				if(other_acc == users[sign].acc){
					system("cls");
					cout<<"����ת�˸��Լ����˻�"<<endl;
					break;
				}
				
				cout<<"������ת�˽��(���β���������10000Ԫ)��";
				cin>>p;
				if(!(p>0 && p <= 10000)){
					system("cls");
					cout<<"���������\n";
					system("pause");
					this->showMenu_2();			 
				} 
			
				while(p % 50 != 0){
					system("cls");
					cout<<"����Ľ��ֻ����50�ı��������������룺";
					cin>>p;
					count++;
					if(count == 3){
					system("cls");
					cout<<"���������������!\n";
					system("pause");
					this->showMenu_2();
				}
			}	
			
			if(p > users[sign].money){
				cout<<"�㵱ǰ���㣡"; 
				system("pause");
				this->showMenu_1(); 
			}	
				
				system("cls");
				users[sign].money -= p;
				users[i].money += p;
				cout<<"ת�˳ɹ�"<<endl;	
				operatingData(3, sign, p);			
				break;
			}
				
		}
		
		if(other_acc != users[i].acc){
			cout<<"�˻�������"<<endl; 
		}
		
		system("pause"); 
		
		this->showMenu_2();	 		
	}
	
	//��ѯ��� 
	void select_4(){
		system("cls");
		cout<<"�㵱ǰ������ǣ�"<<users[sign].money<<endl;
		operatingData(4, sign, 0); 
		system("pause");
		this->showMenu_2();	 
	}
	
	//�޸����� 
	void select_5(){
		int p1, p2;
		system("cls");
		cout<<"������ԭ���룺";
		cin>>p1;
		
		if(p1 == users[sign].password){
			cout<<"�������µ�����(�˴�����Ϊ��������)��";
			cin>>p2;
			users[sign].password = p2;
			cout<<"�����޸ĳɹ�"<<endl;
			operatingData(5, sign, 0);
		}
		else{
			cout<<"ԭ���벻��ȷ"<<endl; 
		}
		
		system("pause");
		this->showMenu_2();	 		
	}
	
	//�˳����� 
	void select_6(){
		system("cls"); 
		cout<<"��л���ʹ��!!";
		Database::updateUserInformation();
		exit(0);
	}
	
	//����һ���˵����� 
	void select_7(){
		this->showMenu_1();		
	}
	
	//������¼ 
	void select_8(){		
		cout<<"������¼�Ѿ����ɣ���";
		this->showMenu_2();	  
	}	
	
};
