#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ifstream input("scores.txt");
//	input.open("scores.txt");
	if(input.fail()){
		cout<<"Fail!"<<endl;
		return 0;
	}
	char firstName[80];
	char mi;
	char lastName[80];
	int score;
	while(!input.eof()){
		input>>firstName>>mi>>lastName>>score;
		cout<<firstName<<" "<<mi<<" "<<lastName<<" "<<score<<endl;	
	}
	input.close();
	cout<<"Done!"<<endl;
	return 0;
}
