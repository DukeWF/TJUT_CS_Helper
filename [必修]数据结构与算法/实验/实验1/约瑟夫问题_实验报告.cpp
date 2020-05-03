#include <iostream>
#include <cstdlib>

using namespace std;
//定义节点类型
typedef int ElemType;
typedef struct LNode{  
	ElemType PW;
	int ID;
	struct LNode *next;
}LNode;

//定义头指针
typedef LNode *LinkList;
//1.尾插法建立单循环链表：OK
LinkList CreateList_REC(LinkList L, int num){
	ElemType x;
	L=(LinkList)malloc(sizeof(LNode));
	LinkList p=L,q;
	L->next=L;
	for(int i=1;i<=num;i++){
		cin>>x;
		q=(LinkList)malloc(sizeof(LNode));
		q->PW=x;
		q->ID=i;
		p->next=q;
		p=q;
		p->next=L;
	}
	return L;
} 
//2.查找给定ID的节点，并返回其指针p：OK 
LinkList Find_ID(LinkList L, int ID){
	LinkList p=L->next;
	while(p->ID!=ID){
		p=p->next;
	}
	return p;
}
//3.根据PW与当前ID查找下一个删除对象，并返回其ID：OK 
int Find_LNode(LinkList L, int ID, int PW){
	LinkList p=L;
	int id=ID,id_max,id_min;
	//获取当前表最大/最小ID
	while(p->next!=L){
		p=p->next;
	}
	id_min=L->next->ID;
	id_max=p->ID;
	//被删节点是之前最末节点的情况：将起始id设置为当前最小id
	if(id_min==id_max) return id_min; 
	if(id>id_max){
		id=id_min;
	}
	//找到起始节点
	p=Find_ID(L,id);
	for(int i=0;i<PW-1;i++){
		if(p->next==L)
			p=p->next->next;
		else p=p->next;		
	}
	id=p->ID;
	return id;
}
//4.查找给定ID的前一个节点，并返回其指针p：OK 
LinkList Find_PID(LinkList L, int ID){
	LinkList p=L;
	while(p->next->ID!=ID){
		p=p->next;
	}
	return p;
}
//3.删除给定ID的对象，并返回其PW 
int Delete_LNode(LinkList L, int ID){
	LinkList p=Find_PID(L,ID);
	LinkList q=p->next;
	int id,pw;
	
	id=q->ID;
	pw=q->PW;
	cout<<id;
	p->next=q->next;
	free(q);
	
	return pw;
}
//4.输出 
void Display_YSF(LinkList L, ElemType start){
	LinkList p;
	ElemType pw=start;
	int id,id_next=0;
	while(L->next!=L){	
		p=L->next;
		if(id_next==0) id_next=1;
		
		id=Find_LNode(L,id_next,pw);
		
		if(Find_ID(L,id)->next!=L)
			id_next=Find_ID(L,id)->next->ID;	
		else 
			id_next=Find_ID(L,id)->next->next->ID;
		if(L->next!=L){
			if(p->next!=L){
				pw=Delete_LNode(L,id);
				cout<<" ";
			}
			else pw=Delete_LNode(L,id);			
		}	
		if(L->next==L){
			cout<<endl;
			break;
		}
	}
}
int main(){
	int T;
	int n,m;
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>n;
		cin>>m;
		LinkList L=CreateList_REC(L,n);
		Display_YSF(L,m);
	}
	return 0; 
} 

