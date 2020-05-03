/* TODO (#1#): 线性表的实现与基本操作 */
/*
	Name: 期末复习-线性表基本操作 
	Copyright: Duke_Wang 
	Author: Duke_Wang 
	Date: 28/06/17 12:07
	Description: 线性表-顺序表/链表的实现与基本操作 
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
/* TODO (#1#): 顺序表初始化(交互式) */
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
/* TODO (#1#): 单链表初始化 */
LinkList init(LinkList L){
	LinkList T,p;
	Elemtype x;
	/* TODO (#1#): 建立一个空链表 */
	T=(LinkList)malloc(sizeof(LNode));
	T->next=NULL;
	cin>>x;
	while(x){
		p=(LinkList)malloc(sizeof(LNode));
		p->data=x;
		/* TODO (#1#): 建立两节点之间的联系 */
		p->next=T->next;
		T->next=p;
		cin>>x;
	}
	return T;
}
/* TODO (#1#): 遍历 */
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
