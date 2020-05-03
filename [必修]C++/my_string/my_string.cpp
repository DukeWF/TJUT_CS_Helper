#include <string.h>
#include <iostream>
using namespace std;
#include "my_string.h"

my_string::my_string(char *s){
	if(s){
		str = new char[strlen(s)+1];
		strcpy(str, s);
	}
}

my_string::~my_string(){
	delete str;
}

void my_string::print(){
	cout<<str<<endl;
}
