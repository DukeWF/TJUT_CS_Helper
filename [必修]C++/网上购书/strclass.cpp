//#include "strclass.h"
//
//string::string(){
//	m_Length=1;
//	m_Data=new char[m_Length];
//	memcpy(m_Data,"",m_Length);
//}
//string::string(const string& Str){
//	m_Length=Str.m_Length;
//	m_Data=new char[m_length];
//	memcpy(m_Data,Str.m_Data,m_Length);
//}
//string::string(char *p){
//	m_Length=strlen(p)+1;
//	m_Data=new char[m_Length];
//	memcpy(m_Data,p,m_Length);
//}
//void string::operator=(const string& Str){
//	if(&Str!=this){
//		delete[] m_Data;
//		m_Length=Str.m_Length;
//		m_Data=new char[m_Length];
//		memcpy(m_Data,Str.m_Data,m_Length);
//	}
//	return; 
//}
//string::~string(){
//	delete []m_Data;
//}

