/*********************Copyright  1997-2017  Duke.Wang********************/
//实验2-01：进制转换
//版本：1.0
//说明：来源于书P53数值转换问题，加以改动 
/************************************************************************/
#include <iostream>
#include <cstdlib>
#define StackInitSize 100 
using namespace std;

typedef struct SeqStack{
	int data[StackInitSize];
	int top;
}SeqStack;
typedef SeqStack *StackLink;

StackLink InitStack(){
	StackLink s;
	s=(StackLink)malloc(sizeof(SeqStack));
	if(s!=NULL){
		s->top=-1;
		return s;
	}
	else{
		exit(0);
	}
}
int IsEmpty(StackLink s){
	return (s->top==-1)?1:0;
}
void Push(StackLink s, int x){
	if(s->top==StackInitSize){
		exit(0);
	}
	else{
		s->top++;
		s->data[s->top]=x;
	}
	return;
}
int Pop(StackLink s){
	int temp;
	if(IsEmpty(s)){
		exit(0);
	}
	else{
		temp=s->data[s->top];
		s->top--;
		return temp;
	}
}
void num_in(int x){
	x+=55;
	cout<<char(x);	
}
void conversion_num(int N, int r){
	StackLink s;
	int x;
	s=InitStack();
	while(N){
		Push(s,N%r);
		N=N/r; 
	}
	while(!IsEmpty(s)){
		x=Pop(s);
		if(x<=9&&x>=0) cout<<x;
		else num_in(x);
	}
	cout<<endl;
}
int main(){
	int N,r;
	cin>>N>>r;
	conversion_num(N,r);
	return 0;
}

