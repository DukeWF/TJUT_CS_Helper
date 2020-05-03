/*********************Copyright  1997-2017  Duke.Wang********************/
//ʵ��3-03����������α��� 
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
//2.��α���������1��
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
