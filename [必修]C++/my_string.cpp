#include <iostream>
#include <string.h>
using namespace std;

class my_string{
	private:
		char *s;
	public:
		my_string();
		my_string(char *t);
		~my_string();
		my_string add(my_string &t);
		void show();
};
my_string::my_string(){
	s = NULL;
}
my_string::my_string(char *t){
	if(t==NULL)
		s==NULL;
	else{
		s = new char[strlen(t)+1];
		strcpy(s,t);
	}
}
my_string::~my_string(){
	if(s!=NULL)
		delete []s;
}
my_string my_string::add(my_string &t){
	char *i = strcat(s,t.s);
	my_string r(i);
	return r;
}
void my_string::show(){
	cout<<s;
}
