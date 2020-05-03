#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;
int main(){
	ofstream output("state.txt"); 
	output<<"New York#Beijing#Henan#Warsaw";
	output.close();
	 
	ifstream input("state.txt");	
	char city[40];
	while(!input.eof()){
		input.getline(city,40,'#');
		cout<<city<<endl;
	}
	input.close();
	return 0;
} 
