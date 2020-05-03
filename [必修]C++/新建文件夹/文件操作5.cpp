#include <iostream>
#include <fstream>
using namespace std;
int main(){
	char c;
	int line=1;
	fstream fin("a.dat",ios::in);
	if(!fin){
		return -1;
	}
	while(fin.get(c)){
		if(c=='\n'){
			line++;
		}
	}
	cout<<"line:"<<line;
	return line;
}
