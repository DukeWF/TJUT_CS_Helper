#include <iostream>
#include <fstream>
using namespace std;
int main(){
	fstream file;
	file.open("J:\\a.txt");
	if(file.fail()){
		cout<<"���ļ�ʧ�ܣ�";
		system("pause");
		return 0; 
	}
	char str[256];
	while(file>>str){
		cout<<str<<endl;
	}
	file<<"END";
	file.close();
	return 0;
} 
