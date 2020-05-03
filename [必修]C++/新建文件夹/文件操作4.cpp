#include <iostream>
#include <fstream>
using namespace std;
int main(int argc,char *argv[]){
	char ch;
	if(argc!=3){
		cout<<"命令行输入有误！"<<endl;
		return 1;
	}
	ifstream fin(argv[1]);
	if(!fin){
		cout<<"不能打开源文件"<<endl;
		return 1;
	}
	ofstream fout(argv[2]);
	if(!fout){
		cout<<"不能打开目标文件"<<endl;
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
