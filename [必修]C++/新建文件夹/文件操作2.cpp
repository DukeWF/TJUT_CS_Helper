#include <iostream>
#include <fstream>
using namespace std;
int main(){
	ofstream ou("j:\\file1.txt");
	ifstream in;
	ou<<"Welcome to 21st C++";
	in.open("j:\\file1.txt");
		if(in.fail())
			cout<<"�ļ������ڣ���ʧ��"<<endl;
		else cout<<"�ļ��Ѵ򿪣����Խ��ж�д����"<<endl;
	in.close();
	return 0;
} 
