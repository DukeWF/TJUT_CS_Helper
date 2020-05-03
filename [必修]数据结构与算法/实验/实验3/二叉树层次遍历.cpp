/*********************Copyright  1997-2017  Duke.Wang********************/
//实验3-03：二叉树层次遍历 
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
//2.层次遍历（方法1）
int Level_Traversal(BiTree T, int level){
	if(!T||level<0) return 0;
	if(level==0){
		cout<<T->data;
		return 1; 
	}
	return Level_Traversal(T->lchild,level-1)+Level_Traversal(T->rchild,level-1);
}
void Level_Traversal(BiTree T){
	int i=0;
	for(i=0;;i++)
		if(!Level_Traversal(T,i)) break;
	return;
} 
int main(){
	BiTree root,root2,root3;
	root=Create_Tree();
	Level_Traversal(root);
	return 0;
}
