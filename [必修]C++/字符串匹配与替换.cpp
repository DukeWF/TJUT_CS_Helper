#include <iostream>
#include <string>  
#include <fstream>  
#include <sstream> 
#include <cstring>
#include <cstdlib>

using namespace std;

bool _CLS = 0;//�������أ�0��1�� 
bool CLS(){
	if(_CLS==1){
		system("cls");
		return 1;
	}
	return 0;
}

string readFileIntoString(char * filename){  
	ifstream ifile(filename);
	if(!ifile){
		cout<<filename<<" ��Ӧ�ļ������ڣ�������������롣"<<endl;
		system("pause");
		CLS();
		ifile.close();
		return "error";
	}  
	//���ļ����뵽ostringstream����buf��  
	ostringstream buf;  
	char ch;  
	while(buf&&ifile.get(ch))  
	buf.put(ch);  
	//������������buf�������ַ���  
	return buf.str();  
} 

int main(){
	string path;
	char patharr[500];//MAX_PATH=260(stdlib.h)
		
	cout<<"�������ļ������ļ�·��:"; 
	cin>>path;
	strcpy(patharr,path.c_str());
	
	//�쳣����:�ļ�·�������ո�,����������һ��ѭ��	
	if(patharr[0]=='"'||patharr[path.size()]=='"'){
		cout<<"·���в��ܰ����ո�������������룬���ļ�������Ƶ���Ŀ¼���ٴ�ִ�С�"<<endl;
		system("pause");
		CLS();
		//continue;//������ǰѭ��			
	}	
	//�ļ���  
//	char * fn="a.txt";  
	string str;  
	str=readFileIntoString(patharr);
	
	//��ʼ�����ַ���
	for(int flag=0;str.find("\n");){
		flag=str.find("\n");
		str.replace(flag,1,"");
	}
	cout<<str<<endl;  
	system("pause"); 
}


