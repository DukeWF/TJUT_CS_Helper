//IOÖØÔØ 
#include "class.h">
ostream& operator<<(ostream &o, A&t){
	o<<t.a;
	return o;
}
istream& operator>>(istream &i, A&t){
	i>>t.a;
	return i;
}
