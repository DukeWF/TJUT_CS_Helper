/* TODO (#1#): ���Ա��ʵ����������� */
/*
	Name: ��ĩ��ϰ-���Ա�������� 
	Copyright: Duke_Wang 
	Author: Duke_Wang 
	Date: 28/06/17 12:07
	Description: ���Ա�-˳���/�����ʵ����������� 
*/
#include <cstdlib>
#include <iostream>
using namespace std;
const int MaxSize=100;
typedef int Elemtype;
typedef struct SqList{
	Elemtype data[MaxSize];
	int length;
}SqList;

typedef struct LNode{
	Elemtype data;
	LNode* next;
}LNode, *LinkList;
/* TODO (#1#): ˳����ʼ��(����ʽ) */
SqList* init(SqList L){
	SqList *T;
	Elemtype x;
	T=(SqList*)malloc(sizeof(SqList));
	if(T) T->length=0;
	else exit(-1);
	cin>>x;
	while(x){
		T->data[T->length]=x;
		T->length ++;
		cin>>x;
	}
	T->length ++;
	return T;
}
/* TODO (#1#): �������ʼ�� */
LinkList init(LinkList L){
	LinkList T,p;
	Elemtype x;
	/* TODO (#1#): ����һ�������� */
	T=(LinkList)malloc(sizeof(LNode));
	T->next=NULL;
	cin>>x;
	while(x){
		p=(LinkList)malloc(sizeof(LNode));
		p->data=x;
		/* TODO (#1#): �������ڵ�֮�����ϵ */
		p->next=T->next;
		T->next=p;
		cin>>x;
	}
	return T;
}
/* TODO (#1#): ���� */
void show(ElemType e){
	cout<<e; 
	return;
}
void show(SqList S){
	for(int i=0;i<S->length;i++){
		if(i!=((S->length)-1)) show(S->data[i]);
		else cout<<S->data[length];
	} 
	return;
}
void show(LinkList L){
	
} 
int main(){
	
}
