/*********************Copyright  1997-2017  Duke.Wang********************/
//ʵ��1-01���������������
//�汾��1.5
//˵�����ڳ���Ļ����ϼ������ע��ϸ�ڣ��Ա��պ�鿴
//�ر���л����ǡ�����ṩ�Ĳο����룬�Լ�115��λ����ѧ���ṩ�Ĳ�������
/************************************************************************/
#include <iostream>
#include <cstdlib>

using namespace std;
//����ڵ�����
typedef int ElemType;
typedef struct LNode{  
	ElemType data;
	struct LNode *next;
}LNode;

//����ͷָ��
typedef LNode *LinkList;

//���嵥�����������
//1.β�巨����������(��Դ�������� 
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
//2. ɾ������ 
LinkList ListDelete_NMM(LinkList L, int min, int max){
	LinkList p,q;
	p=L;
	//�ٽ�������ͷ�ڵ�next��ǿգ�ִ��ѭ����ѯ���� 
	while(p->next!=NULL){
		//�ж���������ǰָ����������min~max֮�� 
		if((p->next->data>min)&&(p->next->data<max)){
			//ִ�в������л�next�򣬶Ͽ���ǰԪ�����Ӳ����ӵ�֮��Ԫ�� 
			q=p->next;
			p->next=q->next;
			free(q);//�ͷ���ʱ���� 
		}
		else p=p->next;
	}
	return L;
} 
//3.�������
void ListDisplay(LinkList L){
	//�ж�������ͷ�ڵ�next��ǿգ�������ǿ� 
	if(L->next!=NULL){
		LinkList p=L->next;
		//�ٽ�����������Ԫ��next��ǿգ�����һ�ڵ����
		while(p->next){
			cout<<p->data<<" ";
			p=p->next;
		}
		cout<<p->data<<endl;//�����ʽ��Ҫ��������һ��Ԫ��
	}
	else cout<<"-1"<<endl;
} 

//������ʵ��
int main(){
	//������������� 
	int T;
	int n;
	int q;
	int type;
	LinkList L;
	//������������ 
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
