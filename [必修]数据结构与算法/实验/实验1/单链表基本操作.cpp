/*********************Copyright  1997-2017  Duke.Wang********************/
//实验1-01：单链表基本操作
//版本：1.5
//说明：在初版的基础上加入更多注释细节，以便日后查看
//特别致谢：书记、五金提供的参考代码，以及115各位大佬学长提供的测试样例
/************************************************************************/
#include <iostream>
#include <cstdlib>

using namespace std;
//定义节点类型
typedef int ElemType;
typedef struct LNode{  
	ElemType data;
	struct LNode *next;
}LNode;

//定义头指针
typedef LNode *LinkList;

//定义单链表基本操作
//1.尾插法建立单链表(来源：书例） 
LinkList CreateList_tail(LinkList L, int num){
	ElemType x;
	L=(LinkList)malloc(sizeof(LNode));
	LinkList s,r=L;
	L->next=NULL;
	for(int i=0;i<num;i++){
		cin>>x;
		s=(LinkList)malloc(sizeof(LNode));
		s->data=x;
		r->next=s;
		r=s;
	}
	r->next=NULL;
	return L;
} 
//2. 删除运算 
LinkList ListDelete_NMM(LinkList L, int min, int max){
	LinkList p,q;
	p=L;
	//临界条件：头节点next域非空，执行循环查询操作 
	while(p->next!=NULL){
		//判断条件：当前指向数据域在min~max之间 
		if((p->next->data>min)&&(p->next->data<max)){
			//执行操作：切换next域，断开当前元素连接并连接到之后元素 
			q=p->next;
			p->next=q->next;
			free(q);//释放临时变量 
		}
		else p=p->next;
	}
	return L;
} 
//3.输出链表
void ListDisplay(LinkList L){
	//判断条件：头节点next域非空，即链表非空 
	if(L->next!=NULL){
		LinkList p=L->next;
		//临界条件：数据元素next域非空，即下一节点存在
		while(p->next){
			cout<<p->data<<" ";
			p=p->next;
		}
		cout<<p->data<<endl;//满足格式化要求，输出最后一个元素
	}
	else cout<<"-1"<<endl;
} 

//主函数实现
int main(){
	//由题意变量声明 
	int T;
	int n;
	int q;
	int type;
	LinkList L;
	//键入数据组数 
	cin>>T;
	 
	for(int i=0;i<T;i++){
		cin>>n;
		L=CreateList_tail(L,n);
		cin>>q;
		for(int i=0;i<q;i++){
			cin>>type;
			switch(type){
				case 1:{
					ListDisplay(L);
					break;
				}
				case 2:{
					int min,max;
					cin>>min;
					cin>>max;
					L=ListDelete_NMM(L,min,max);			
					break;
				}
				default:{
					break;
				}
			}
		}	
	}
	
	return 0;
}
