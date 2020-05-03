/*********************Copyright  1997-2017  Duke.Wang********************/
//ʵ��3-02�������������� 
//�汾��1.0
//˵��������
/************************************************************************/
#include <iostream>
#include <cstdlib>
#define MaxNode 100
using namespace std;  
#include <queue>  
#include <stack>  

typedef struct BiTNode{
	char data;
	BiTNode *lchild, *rchild;
}BiTNode;
typedef BiTNode *BiTree;
//1.���������������� 
BiTree Create_Tree(){
	char ch;
	BiTree T;
	cin>>ch;
	if(ch=='#') T=NULL;
	else if(!(T=(BiTree)malloc(sizeof(BiTNode)))) exit(1);
	else{
		T->data=ch;
		T->lchild=Create_Tree();
		T->rchild=Create_Tree();
	}
	return T;
}
//2.����������ݹ�ʵ�֣�
void InOrder(BiTree root){
	if(root==NULL) return;
	InOrder(root->lchild);
	cout<<root->data;
	InOrder(root->rchild);
}
//3.�����������ݹ飩 
void Change_LR(BiTree root){
	BiTree temp=NULL;
	if(root->lchild==NULL&&root->rchild==NULL) return;
	else{
		temp=root->lchild;
		root->lchild=root->rchild;
		root->rchild=temp;	
	}
	if(root->lchild) Change_LR(root->lchild);
	if(root->rchild) Change_LR(root->rchild);
} 
int main(){
	BiTree root,root2,root3;
	root=Create_Tree();
	Change_LR(root);
	InOrder(root);
}
