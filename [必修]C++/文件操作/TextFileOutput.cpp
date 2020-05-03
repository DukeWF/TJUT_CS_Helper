#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ofstream output;
	output.open("scores.txt");
	output<<"John"<<" "<<"T"<<" "<<"Smith"<<" "<<90<<endl;
	output.close();
	cout<<"Okay";
	return 0;	
} 
