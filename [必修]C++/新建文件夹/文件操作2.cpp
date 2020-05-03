#include <iostream>
#include <fstream>
using namespace std;
int main(){
	ofstream ou("j:\\file1.txt");
	ifstream in;
	ou<<"Welcome to 21st C++";
	in.open("j:\\file1.txt");
		if(in.fail())
			cout<<"文件不存在，打开失败"<<endl;
		else cout<<"文件已打开，可以进行读写操作"<<endl;
	in.close();
	return 0;
} 
