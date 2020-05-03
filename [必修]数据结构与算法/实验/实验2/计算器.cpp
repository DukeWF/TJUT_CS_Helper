/*********************Copyright  1997-2017  Duke.Wang********************/
//ʵ��2-03��������
//�汾��1.5
//˵�����޸�һ�������ݣ���AC 
/************************************************************************/
#include <iostream>
#include <cstdlib>
using namespace std;
//������ʽջ 
typedef int StackElemType;
typedef struct node{
	int data;
	struct node* next;
}node; 
typedef node* LinkStack;
int priority[8][8]={3,3,1,1,1,1,3,3,
					3,3,1,1,1,1,3,3,
					3,3,3,3,3,1,3,3,
					3,3,3,3,3,1,3,3,
					3,3,3,3,3,1,3,3,
					1,1,1,1,1,1,2,2,
					3,3,3,3,3,0,3,3,
					1,1,1,1,1,1,0,2}; 
int IsEmpty(LinkStack S); 
//1.��ʼ���ÿ�ջ
LinkStack InitStack(LinkStack S){
	LinkStack top;
	top=NULL;
	return top;
}
//2.��ջ 
LinkStack Push(LinkStack S, int x){
	LinkStack p;
	p=(LinkStack)malloc(sizeof(node));
	if(p){
		p->data=x;
		p->next=S;
		S=p;
	}
	else exit(0);
	return S;
}
//3.��ջ
LinkStack Pop(LinkStack S, int *x){
	LinkStack temp;
	if(!IsEmpty(S)){
		temp=S;
		*x=S->data;
		S=S->next;
		free(temp);
		return S;
	}
	else return NULL;
}
//4.��ȡջ��Ԫ��
int GetTop(LinkStack S){
	if(IsEmpty(S))
		return 0;
	else return S->data;
} 
//5.�ж�ջ���� 
int IsEmpty(LinkStack S){
	return S?0:1;
}
//6.��ȡ���ȼ�
int sub(int c){
	switch(c){
		case '+':
			return 0;
		case '-':
			return 1;
		case '*':
			return 2;
		case '/':
			return 3;
		case '%':
			return 4;
		case '(':
			return 5;
		case ')':
			return 6;
		case '\n':
			return 7; 
	}
}
int main(){
	int x1,x2,i,j,op,temp;
	char ch;
	LinkStack OPTR=NULL;
	LinkStack OPND=NULL;
	OPTR=Push(OPTR,'\n');
	ch=getchar();
	while(!(ch=='\n'&&GetTop(OPTR)=='\n')){
		if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='%'||ch=='('||ch==')'||ch=='\n'){
			i=sub(GetTop(OPTR));
			j=sub(ch);
			if(priority[i][j]==3){
				OPTR=Pop(OPTR,&op);
				OPND=Pop(OPND,&x2);
				OPND=Pop(OPND,&x1);
				switch(op){
					case '+':
						OPND=Push(OPND,x1+x2);						
						break;
					case '-':
						OPND=Push(OPND,x1-x2);
						break;
					case '*':
						OPND=Push(OPND,x1*x2);
						break;
					case '/':
						OPND=Push(OPND,x1/x2);
						break;
					case '%':
						OPND=Push(OPND,x1%x2);
				}
				continue;
			}
			if(priority[i][j]==1)
				OPTR=Push(OPTR,ch);
			if(priority[i][j]==2)
				OPTR=Pop(OPTR,&temp);
		}
		else
			OPND=Push(OPND,ch-48);
		ch=getchar();
	}
	cout<<GetTop(OPND);
	return 0;
}
