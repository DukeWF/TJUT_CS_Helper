#include <iostream>
#include <fstream>
using namespace std;
int main(){
	ofstream fout("j:\\file1.txt");
	fout<<"Hello World!"<<endl;//向文件输出 
	fout<<10<<endl;
	fout<<hex<<10<<endl;
	fout.close();
	ifstream fin("j:\\file1.txt");
	char c[20];
	int i;
	char ch;
	fin>>c;
	fin>>i;
	fin>>ch;
	cout<<c<<endl;
	cout<<i<<endl;
	cout<<ch<<endl;
	fin.close();
	return 0;
}
