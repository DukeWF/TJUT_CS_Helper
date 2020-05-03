#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;
int main(){
	ifstream input("scores.txt");
	ofstream output("formattedscores.txt"); 
	
	char firstName[80];
	char mi;
	char lastName[80];
	int score;	
	while(!input.eof()){
		input>>firstName>>mi>>lastName>>score;
		output<<setw(6)<<firstName<<setw(2)<<mi<<setw(6)<<lastName<<setw(4)<<score<<endl;	
	}
	return 0;
} 
