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
//	char *i = strcat(s,t.s);
//	my_string r(i);
//	r.show();
//	return r;
	char *p = new char[strlen(s)+strlen(t.s)+1];
	
}
void my_string::show(){
	cout<<s;
}

int main(){
	my_string s1("Hello "), s2("World!");
	my_string s3;
	s3=s1.add(s2);
	s3.show();
}
