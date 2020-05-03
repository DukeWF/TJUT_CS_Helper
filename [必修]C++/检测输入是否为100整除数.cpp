#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

int main(){
	string pw="123456";
	string temp;
	int a[6];
	cout<<"Password:";
	for(int i=0;i<6;i++){
		if(int ch=(getch())>=0&&ch<=9){
			a[i]=ch;
			cout<<"*";
			continue;
		}
		else if(ch=(getch())!='\n') cout<<"\b";
		else{
			cout<<"ERROR!";
			exit(-1);
		}
	}
	for(int i=0;i<6;i++){
		cout<<a[i];
	}
	temp.append(a);
	cout<<"pw1:"<<pw<<endl<<"pw2:"<<temp<<endl<<"pw3:"<<a<<endl;
	if(temp==pw){
		return 1;
	}
	else return 0;
} 
