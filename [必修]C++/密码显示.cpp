#include<iostream>
#include<conio.h>
using namespace std;
int main(){
	char password[100];
	int i=0;
	do{
		char ch;
		ch=getch();
	//�жϲ��֣�ʵ���˸����������������ʾ�����λس�������
		if(ch==8){ //�˸��
			if(i!=0){	
			cout<<char(8)<<" "<<char(8);
			i--;//Ǳ��BUG��i<0������ 
			}
		}	
		else if(ch=='\r'){//���λس��� 
		}
		else{//������ʾ 
			cout<<"*";
			password[i++]=ch;
		}
	//�жϲ��ֽ���
	}while(i<6);
	cout<<endl<<"password:"<<password<<endl;	
	//ת�����֣�ת��char*Ϊint 
	int temp=0;
	for(i=0;i<6;i++){
		temp=temp*10+(password[i]-'0');
	}
	//ת�����ֽ��� 
	cout<<endl<<temp;
	return 0;
}
