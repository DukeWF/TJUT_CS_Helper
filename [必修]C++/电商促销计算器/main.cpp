#include <iostream>
#define cls system("cls")
#define pause system("pause")
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int maifu();
int manjian();
 
int main(int argc, char** argv) {
	char ch;
	while(ch!=EOF){
		cout<<"��ӭʹ�õ��̴������۽𾦼�������"<<endl<<"��ѡ�����ģ�ͣ�"<<endl<<"a.��2��1"<<endl<<"b.����"<<endl<<"q.�˳�"<<endl; 
		cin>>ch; 
		switch(ch){
			case 'a':{
				cls;
				maifu();
				cls;
				break;
			}
			case 'b':{
				cls;
				manjian();
				cls;
				break;
			}
			case 'q':{
				cls;
				cout<<"ллʹ�ã��ټ���";
				exit(0);
				break;
			} 
			default:{
				cls;
				cout<<"������������";
				cls;
			}
		}
	}
	
	return 0;
}
int maifu(){
	double temp,final;
	cout<<"�����빺���";
	cin>>temp;
	final=temp/2.0;
	cout<<"ʵ����Ʒ����Ϊ��"<<final<<endl;
	pause;
	return 0;
}
int manjian(){
	double temp,man,jian,final;
	cout<<"�����빺���";
	cin>>temp;
	cout<<"������������"<<endl<<"����";
	cin>>man;
	cout<<"����";
	cin>>jian;
	if(jian>man){
		cout<<"������������";
		pause;
		return -1;
	}
	else{
		if(temp<man){
			final=temp;
		}
		else{
			final=temp-jian;
		}
	}
	cout<<"ʵ����Ʒ���ۣ�"<<final<<endl;
	pause;
	return 0;	
}
