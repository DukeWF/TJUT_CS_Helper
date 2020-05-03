/*********************Copyright  1997-2017  Duke.Wang********************/
//ʵ��5-02�������������Ĺ����루���򣩱��� 
//�汾��1.0
//˵�������� 
/************************************************************************/
#include <iostream>
#include <queue>  
#include <stack>
#define MAX_NUM 100
using namespace std;
typedef int KeyType;
typedef struct BiTNode{
	KeyType data;
	BiTNode *lchild, *rchild;
}BiTNode;
typedef BiTNode *BiTree;
int arr[MAX_NUM];
int index=0;
void Insert(BiTree &T, KeyType k){
	if(T==NULL){
		T=(BiTree)malloc(sizeof(BiTNode));
		T->data=k;
		T->lchild=T->rchild=NULL;
	}
	else if(k<=T->data) Insert(T->lchild,k);
	else if(k>T->data) Insert(T->rchild,k); 
}
void Create_BST(BiTree &T){
	T=NULL;
	KeyType k;
	while(1){
		cin>>k;
		if(k==-1) break;
		else Insert(T,k);
	}
}
void Init_SEQ(KeyType data){
	arr[index]=data;
	index++;
}
void InOrder(BiTree T){
	if(T==NULL) return;
	InOrder(T->lchild);
	Init_SEQ(T->data);
	InOrder(T->rchild); 
}
void show(){
	int i;
	for(i=0;i<index-1;i++){
		cout<<arr[i]<<" ";
	}
	cout<<arr[index-1];
}
int main(){
	BiTree T;
	Create_BST(T);
	InOrder(T);
	show();
	return 0;
}
