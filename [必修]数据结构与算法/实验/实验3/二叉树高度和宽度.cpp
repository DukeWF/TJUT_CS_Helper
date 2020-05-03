/*********************Copyright  1997-2017  Duke.Wang********************/
//实验3-04：二叉树高度和宽度
//版本：1.0
//说明：测试 
/************************************************************************/
#include <iostream>
#include <cstdlib>
#include <queue>
#define MaxNode 100
using namespace std;  

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
//2.求二叉树高度（深度）
int Get_Height(BiTree T){
	if(T==NULL) return 0;
	return Get_Height(T->lchild)>Get_Height(T->rchild)?(Get_Height(T->lchild)+1):(Get_Height(T->rchild)+1);
}

//3.求二叉树宽度
int Get_Width(BiTree pNode){  
    if (pNode == NULL)  
    {  
        return 0;  
    }  
    std::deque<BiTree> dequeTreeNode;//双端队列  
    int maxWidth = 1;//最大的宽度,用于当只有一个节点时候返回1  
    dequeTreeNode.push_back(pNode);//头结点入队  
    while (true)  
    {  
  
        int length = dequeTreeNode.size();//当前层节点的个数  
        if (length == 0)//当前层没有节点，跳出循环  
        {  
            break;  
        }  
        while (length > 0)//如果当前层还有节点  
        {  
            BiTree pTemp = dequeTreeNode.front();  
            dequeTreeNode.pop_front();//出队  
            length--;//长度减一  
            if (pTemp->lchild)  
            {  
                dequeTreeNode.push_back(pTemp->lchild);//下一层节点入队  
            }  
            if (pTemp->rchild)  
            {  
                dequeTreeNode.push_back(pTemp->rchild);//下一层节点入队  
            }  
        }  
        maxWidth = maxWidth > dequeTreeNode.size() ? maxWidth : dequeTreeNode.size();//得到最大宽度  
    }  
    return maxWidth;  
}

int main(){
	BiTree root;
	root=Create_Tree();
	cout<<Get_Height(root)<<" "<<Get_Width(root);
	return 0;
}
