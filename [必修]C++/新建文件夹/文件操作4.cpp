#include <iostream>
#include <fstream>
using namespace std;
int main(int argc,char *argv[]){
	char ch;
	if(argc!=3){
		cout<<"��������������"<<endl;
		return 1;
	}
	ifstream fin(argv[1]);
	if(!fin){
		cout<<"���ܴ�Դ�ļ�"<<endl;
		return 1;
	}
	ofstream fout(argv[2]);
	if(!fout){
		cout<<"���ܴ�Ŀ���ļ�"<<endl;
		return 1;
	}
	while(fin){
		fin.get(ch);
		fout.put(ch);
	}
	fin.close();
	fout.close();
	return 0;
}
