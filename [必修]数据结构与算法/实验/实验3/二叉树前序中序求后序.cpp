//二叉树 前序和中序得到后序
#include <iostream>
using namespace std;
typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode;
typedef BiTNode *BiTree;
int pre_order[100];
int mid_order[100];

BiTree construct_post_order(int pre_l, int pre_r, int mid_l, int mid_r)
{
    if (pre_r - pre_l < 0)
    {
        return NULL;
    }
    BiTree root;
    root = new BiTNode;
    root->data = pre_order[pre_l];
    if (pre_r == pre_l)
    {
        root->lchild = NULL;
        root->rchild = NULL;
        return root;
    }
    int index;
    for (index = mid_l; index <= mid_r; index++)
    {
        if (mid_order[index] == pre_order[pre_l])
            break;
    }
    root->lchild = construct_post_order(pre_l+1, pre_l+(index-mid_l), mid_l, index-1);
    root->rchild = construct_post_order(pre_l+(index-mid_l)+1, pre_r, index+1, mid_r);
    return root;
}

void post_Order(BiTree root)
{
    if(root != NULL)
    {
        post_Order(root->lchild);
        post_Order(root->rchild);
        cout<<root->data;
    }
}

int main()
{
    int n=0;
    char ch;
    int i=0;
    while((ch=getchar())!='\n'){
        pre_order[i]=ch;
        i++;
        n++;
    }
    i=0;
    while((ch=getchar())!='\n'){
        mid_order[i]=ch;
        i++;
    }
    BiTree root = construct_post_order(0, n-1, 0, n-1);
    post_Order(root);
    return 0;
}
