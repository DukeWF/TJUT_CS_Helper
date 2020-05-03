/*********************Copyright  1997-2017  Duke.Wang********************/
//实验3-01：二叉树遍历 
//版本：1.0
//说明：测试 
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
//1.创建二叉树（先序） 
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
//2.先序遍历（递归实现）
void PreOrder(BiTree root){
	if(root==NULL) return;
	cout<<root->data;
	PreOrder(root->lchild);
	PreOrder(root->rchild); 
} 
//3.中序遍历（非递归实现）
void NR_InOrder(BiTree root){
	BiTree p,stack[MaxNode];
	int top=0;
	if(root==NULL) return;
	p=root;
	while(!(p==NULL&&top==0)){
		while(p!=NULL){
			if(top<MaxNode-1){
				stack[top]=p;
				top++;
			}
			else return;
			p=p->lchild;
		}
		if(top<=0) return;
		else{
			top--;
			p=stack[top];
			cout<<p->data;
			p=p->rchild;
		}
	}
} 
//4.后序遍历（递归实现）
void PostOrder(BiTree root){
	if(root==NULL) return;
	PostOrder(root->lchild);
	PostOrder(root->rchild); 
	cout<<root->data;
}
int main(){
	BiTree root,root2,root3;
	root=Create_Tree();
	PreOrder(root);
	cout<<endl;
	NR_InOrder(root);
	cout<<endl;
	PostOrder(root);
}
