#include <iostream>
#include <string.h>
using namespace std;

class my_string{
	private:
		char *s;
	public:
		my_string(char *str){
			if(str!=NULL){
			s = new char[strlen(str)+1];
			strcpy(s,str);
			}
			else s=str;
		}
		void add(const my_string&t){
			char *p = new char[strlen(s)+strlen(t.s)+1];
			strcpy(p,this->s);
			strcat(p,t.s);
			delete s;
			s = p; 
		}
		void show(){
			cout<<this->s<<endl;
		}
		~my_string(){
			delete s;
		//	delete p;
		}
};
int main(){
	my_string s1("abc"), s2("123");
	s1.show();
	s2.show();
	s1.add(s2);
	s1.show();
}
