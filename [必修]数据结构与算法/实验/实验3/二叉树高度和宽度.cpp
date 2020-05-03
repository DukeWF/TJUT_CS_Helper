/*********************Copyright  1997-2017  Duke.Wang********************/
//ʵ��3-04���������߶ȺͿ��
//�汾��1.0
//˵�������� 
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
//2.��������߶ȣ���ȣ�
int Get_Height(BiTree T){
	if(T==NULL) return 0;
	return Get_Height(T->lchild)>Get_Height(T->rchild)?(Get_Height(T->lchild)+1):(Get_Height(T->rchild)+1);
}

//3.����������
int Get_Width(BiTree pNode){  
    if (pNode == NULL)  
    {  
        return 0;  
    }  
    std::deque<BiTree> dequeTreeNode;//˫�˶���  
    int maxWidth = 1;//���Ŀ��,���ڵ�ֻ��һ���ڵ�ʱ�򷵻�1  
    dequeTreeNode.push_back(pNode);//ͷ������  
    while (true)  
    {  
  
        int length = dequeTreeNode.size();//��ǰ��ڵ�ĸ���  
        if (length == 0)//��ǰ��û�нڵ㣬����ѭ��  
        {  
            break;  
        }  
        while (length > 0)//�����ǰ�㻹�нڵ�  
        {  
            BiTree pTemp = dequeTreeNode.front();  
            dequeTreeNode.pop_front();//����  
            length--;//���ȼ�һ  
            if (pTemp->lchild)  
            {  
                dequeTreeNode.push_back(pTemp->lchild);//��һ��ڵ����  
            }  
            if (pTemp->rchild)  
            {  
                dequeTreeNode.push_back(pTemp->rchild);//��һ��ڵ����  
            }  
        }  
        maxWidth = maxWidth > dequeTreeNode.size() ? maxWidth : dequeTreeNode.size();//�õ������  
    }  
    return maxWidth;  
}

int main(){
	BiTree root;
	root=Create_Tree();
	cout<<Get_Height(root)<<" "<<Get_Width(root);
	return 0;
}
