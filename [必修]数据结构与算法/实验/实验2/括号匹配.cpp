/*********************Copyright  1997-2017  Duke.Wang********************/
//ʵ��2-02������ƥ�� 
//�汾��1.0
//˵������ȫû��ջ��˼������ 
/************************************************************************/
#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
	int i=0,j=0,k=0,t=0;
	char ch[100];
	gets(ch);
	while(1){
		switch(ch[t]){
			case '(':{
				i++;
				break;
			}
			case '[':{
				j++;
				break;
			}
			case '{':{
				k++;
				break;
			}
			case ')':{
				i--;
				break;
			}
			case ']':{
				j--;
				break; 
			} 
			case '}':{
				k--;
				break;
			}
		}
		t++;	
		if(ch[t]=='\0') break;	
	}
	if(i==0&&j==0&&k==0) cout<<"YES";
	if(i>0) cout<<"NO"<<endl<<")";
	if(i<0) cout<<"NO"<<endl<<"(";
	if(j>0) cout<<"NO"<<endl<<"]";
	if(j<0) cout<<"NO"<<endl<<"[";
	if(k>0) cout<<"NO"<<endl<<"}";
	if(k<0) cout<<"NO"<<endl<<"{";
	return 0;
} 
