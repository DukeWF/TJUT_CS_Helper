#include<iostream>
using namespace std;

struct s1{
	char c[4]; 
	char *s;
}s1={"abc","def"};

struct s2{
	char *cp;
	struct s1 ss1;
}s2={"ghi",{"jkl","mno"}};


int main(){
	printf("%c,%c\n",s1.c[0],*s1.s);
	printf("%s,%s\n",s1.c,s1.s);
	printf("%s,%s\n",s2.cp,s2.ss1.s);
	printf("%s,%s\n",++s2.cp,++s2.ss1.s);
	
	char* c = new char[10];
	for(int i=0;i<10;i++){
		c[i]=i+'0';
	}
	char p[11] = "0123456789";
	
	printf("%d\n",c);
	printf("%c",*++c);
	
}
