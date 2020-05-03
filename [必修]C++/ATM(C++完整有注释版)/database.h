/*
���ļ�����ģ�����ݿ���� �����ļ��ж�ȡ�û����ݲ��ұ������
*/
#include <string.h>
#include <time.h>
#include <fstream>
#include <stdlib.h>
#ifndef _TOOL_H_
#define _TOOL_H_

using namespace std;

//�˽ṹ��ģ�����ݿ��еı������û����� 
struct Data{
		string name;
		long int acc;
		int password;
		int money;
		int flag; 
};

class Database{	
	protected:
		struct Data * users;  //�ṹ��ָ�� 
		int n;                //ͳ���ļ��г�Ա�����������ж����У� 
		int sign;			  //��Ǵӿͻ��˵�½�����ݳ�Ա 
	
	public:
		//�ͻ��˲����ӿ� 
		Database(){
			n = getNumber();  //��ȡ��Ա���� 
			
			users = new struct Data[n]; //�ڶ��ж�̬�������ݿռ� 
			
			getUserInformation();    //���ļ������ݶ����ڴ� 
		}
		//�ͻ���ע��ӿ� 
		Database(int i){
			n = getNumber();       // ��ȡ��Ա���� 
			
			users = new struct Data[n];  //�ڶ��ж�̬�������ݿռ� 
			
			getUserInformation();    //���ļ������ݶ����ڴ�
			
			appendUser();        //����³�Ա 
			
		}
		//����Ա���Խӿ� 
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
		//���ļ������ݶ����ڴ�
		void getUserInformation(){         
			fstream fin("�û���Ϣ.txt", ios::in|ios::out|ios::binary);
			
			if(!fin){
				cout<<"ϵͳ���ϣ�";
				exit(-1); 
			}
			
			for(int i = 0; i < n; i++){
				fin>>users[i].name>>users[i].acc>>users[i].password>>users[i].money>>users[i].flag;
			}
			
			fin.close();
		}
	
		//�����ļ������ݶ����ڴ�
		void updateUserInformation(){
			fstream fout("�û���Ϣ.txt", ios::out|ios::in|ios::binary);
			
			if(!fout){
				cout<<"ϵͳ���ϣ�";
				exit(-1); 
			}
			
			for(int i = 0; i < n; i++){
			fout<<users[i].name<<" "<<users[i].acc<<" "<<users[i].password<<" "<<users[i].money<<" "<<users[i].flag<<endl;
			}
			
			fout.close();		
		}
		
		//���ļ�������³�Ա 
		void appendUser(){
			struct Data newUser;
			fstream fapp("�û���Ϣ.txt", ios::app|ios::out|ios::binary);
			
			if(!fapp){
				cout<<"ϵͳ���ϣ�";
				exit(-1); 
			}
			
			cout<<"������";
			cin>>newUser.name;
			cout<<"�˻����˻�ֻ��Ϊ�ԡ�2245����ͷ��6λ������2245"; 
			cin>>newUser.acc;
			if(newUser.acc < 0 || newUser.acc > 99){
				cout<<"�����˻���ʽ����ȷ";
				exit(-1); 
			}
			newUser.acc += 224500;		
			cout<<"���룺";  
			cin>>newUser.password;
			newUser.money = 0;
			newUser.flag = 1;
			
			for(int i = 0; i < n;i++){
				if(newUser.acc == users[i].acc){
					cout<<"�û��Ѿ�����";
					exit(0);
				}
			}
			  
			fapp<<"\n"<<newUser.name<<" "<<newUser.acc<<" "<<newUser.password<<" "<<newUser.money<<" "<<newUser.flag;
			
			fapp.close();
		
			cout<<"ע��ɹ�";
			exit(0); 
		}
		
		//��ȡ�ļ��г�Ա���� 
		int getNumber(){
			struct _stat info;  
			_stat("�û���Ϣ.txt", &info);  
			int size = info.st_size;		
			return int(size/(sizeof(Data)+4));  		
		}
		
		//��������¼д���ļ� 
		void operatingData(int i, int len, int money){
			fstream fout("������¼.txt", ios::out|ios::app|ios::binary);
			
			switch(i){
				case 1:
					fout<<users[len].name<<"ȡ����"<<money<<"Ԫ... \n";
					break; 
				case 2:
					fout<<users[len].name<<"�洢��"<<money<<"Ԫ... \n";
					break; 
				case 3:
					fout<<users[len].name<<"ת����"<<money<<"Ԫ... \n";
					break; 
				case 4:
					fout<<users[len].name<<"��ѯ�����... \n";
					break; 		
				case 5:
					fout<<users[len].name<<"�޸�������... \n";
					break; 		
			}
			
			fout.close(); 
		}
		
		//��ȡϵͳʱ�� 
		void getTime(){
		
		time_t t = time(0); 
    	char tmp[64]; 
   	 	
		strftime(tmp, sizeof(tmp), "%Y/%m/%d %X %A �����%j�� %z" ,localtime(&t)); 
    	
		puts(tmp); 

		}
	
		//����Ա���Ժ������������� 
		void test(){
			for(int i = 0; i < n; i++){
			cout<<users[i].name<<" "<<users[i].acc<<" "<<users[i].password<<" "<<users[i].money<<" "<<users[i].flag<<endl;
			}
		}
	
};

#endif
