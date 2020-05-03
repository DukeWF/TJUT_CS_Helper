#include <iostream>
#include <fstream>
using namespace std;

int main(){
	fstream ioFile;
	ioFile.open();
	ioFile<<"ÕÅÈý"<<" "<<76<<" "<<98<<" "<<67<<endl;
	ioFile.close();
}
