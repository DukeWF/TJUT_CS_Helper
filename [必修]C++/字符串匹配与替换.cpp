#include <iostream>
#include <string>  
#include <fstream>  
#include <sstream> 
#include <cstring>
#include <cstdlib>

using namespace std;

bool _CLS = 0;//清屏开关，0关1开 
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
		cout<<filename<<" 对应文件不存在，请检查后重新输入。"<<endl;
		system("pause");
		CLS();
		ifile.close();
		return "error";
	}  
	//将文件读入到ostringstream对象buf中  
	ostringstream buf;  
	char ch;  
	while(buf&&ifile.get(ch))  
	buf.put(ch);  
	//返回与流对象buf关联的字符串  
	return buf.str();  
} 

int main(){
	string path;
	char patharr[500];//MAX_PATH=260(stdlib.h)
		
	cout<<"请输入文件名或文件路径:"; 
	cin>>path;
	strcpy(patharr,path.c_str());
	
	//异常处理:文件路径包含空格,报错并进入下一次循环	
	if(patharr[0]=='"'||patharr[path.size()]=='"'){
		cout<<"路径中不能包括空格，请检查后重新输入，或将文件与程序复制到根目录下再次执行。"<<endl;
		system("pause");
		CLS();
		//continue;//跳过当前循环			
	}	
	//文件名  
//	char * fn="a.txt";  
	string str;  
	str=readFileIntoString(patharr);
	
	//开始操作字符串
	for(int flag=0;str.find("\n");){
		flag=str.find("\n");
		str.replace(flag,1,"");
	}
	cout<<str<<endl;  
	system("pause"); 
}


