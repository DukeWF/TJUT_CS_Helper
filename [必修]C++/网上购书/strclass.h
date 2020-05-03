//#ifndef STRCLASS_H
//#define STRCLASS_H
//#include <string>
//#include <iostream>
//using namespace std;
//class string
//{	
//	friend ostream& operator<<(ostream& S, const string& Str);
//	friend istream& operator>>(istream& S, string& Str);
//	public:
//		string();
//		string(const string& Str);
//		void operator=(const string& Str);
//		~string();
//		string(char *p);
//	private:
//		short m_Length;
//		char *m_Data;
//		
//};
//ostream& operator<<(ostream& S, const string& Str){
//	short i;
//	for(i=0;i<Str.m_Length-1;i++)
//		S<<Str.m_Data[i];
//	return S;
//}
//istream& operator>>(istream& S, string& Str){
//	const short BUFLEN=256;
//	char Buf[BUFLEN];
//	memset(Buf,0,BUFLEN);
//	if(S.peek()=='\0')
//		S.ignore();
//	S.getline(Buf,BUFLEN,'\n');
//	Str=Buf;
//	return S;
//}
//
//#endif
