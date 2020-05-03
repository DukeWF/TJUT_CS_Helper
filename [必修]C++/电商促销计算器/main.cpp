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
		cout<<"欢迎使用电商促销火眼金睛计算器！"<<endl<<"请选择促销模型："<<endl<<"a.买2付1"<<endl<<"b.满减"<<endl<<"q.退出"<<endl; 
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
				cout<<"谢谢使用，再见！";
				exit(0);
				break;
			} 
			default:{
				cls;
				cout<<"您的输入有误！";
				cls;
			}
		}
	}
	
	return 0;
}
int maifu(){
	double temp,final;
	cout<<"请输入购买金额：";
	cin>>temp;
	final=temp/2.0;
	cout<<"实际商品单价为："<<final<<endl;
	pause;
	return 0;
}
int manjian(){
	double temp,man,jian,final;
	cout<<"请输入购买金额：";
	cin>>temp;
	cout<<"请输入满减金额："<<endl<<"满：";
	cin>>man;
	cout<<"减：";
	cin>>jian;
	if(jian>man){
		cout<<"您的输入有误！";
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
	cout<<"实际商品单价："<<final<<endl;
	pause;
	return 0;	
}
