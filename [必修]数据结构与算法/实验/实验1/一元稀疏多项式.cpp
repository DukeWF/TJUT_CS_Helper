/*********************Copyright  1997-2017  Duke.Wang********************/
//ʵ��1-03��һԪ����ʽ������ 
//�汾��1.5
//˵������
/************************************************************************/
#include <iostream>
#include <cstdlib>
using namespace std;

//����ڵ�����
typedef struct PolyNode{  
	int coef;			//ϵ��
	int exp;			//ָ�� 
	struct PolyNode *next;
}PolyNode;

typedef PolyNode *Polynomial;
//1.β�巨��������ʽ������ 
Polynomial Create_Polyn(Polynomial L,int num){
	int c,e;
	L=(Polynomial)malloc(sizeof(PolyNode));
	Polynomial p=L,q;
	L->next=L;
	for(int i=1;i<=num;i++){
		cin>>c>>e;
		q=(Polynomial)malloc(sizeof(PolyNode));
		q->coef=c;
		q->exp=e;
		p->next=q;
		p=q;
		p->next=NULL;
	}
	return L;
}
//2.��ʾ����ʽ 
void Display_Polyn(Polynomial L){
	Polynomial p=L;
	if(p->next!=NULL){
		while(p->next!=NULL){
			p=p->next;
			cout<<p->coef<<"X^"<<p->exp;
			if(p->next!=NULL&&p->next->coef>0)
				cout<<"+";
		}
	}
	else cout<<"0";
	cout<<endl;
}
//3.����ʽ���
Polynomial Add_Poly(Polynomial A,Polynomial B){
	Polynomial C,S;
	Polynomial Pa,Pb,Pc;
	int x;
	Pa=A->next;
	Pb=B->next;
	C=(Polynomial)malloc(sizeof(PolyNode));
	Pc=C;
	Pc->next=NULL;
	while(Pa&&Pb){
		if(Pa->exp==Pb->exp){
			x=Pa->coef+Pb->coef;
			if(x!=0){
				S=(Polynomial)malloc(sizeof(PolyNode));
				S->coef=x;
				S->exp=Pa->exp;
				S->next=NULL;
				Pc->next=S;
				Pc=S;
			}
			Pa=Pa->next;
			Pb=Pb->next;
		}
		else 
			if(Pa->exp<Pb->exp){
				S=(Polynomial)malloc(sizeof(PolyNode));
				S->coef=Pa->coef;
				S->exp=Pa->exp;
				S->next=NULL;
				Pc->next=S;
				Pc=S;
				Pa=Pa->next;
			}
			else{
				S=(Polynomial)malloc(sizeof(PolyNode));
				S->coef=Pb->coef;
				S->exp=Pb->exp;
				S->next=NULL;
				Pc->next=S;
				Pc=S;
				Pb=Pb->next;
			}
	}
	while(Pa){
		S=(Polynomial)malloc(sizeof(PolyNode));
		S->coef=Pa->coef;
		S->exp=Pa->exp;
		S->next=NULL;
		Pc->next=S;
		Pc=S;
		Pa=Pa->next;
	}
	while(Pb){
		S=(Polynomial)malloc(sizeof(PolyNode));
		S->coef=Pb->coef;
		S->exp=Pb->exp;
		S->next=NULL;
		Pc->next=S;
		Pc=S;
		Pb=Pb->next;		
	}
	return C;	
}
//3.����ʽ��� 
Polynomial Sub_Poly(Polynomial A,Polynomial B){
	Polynomial C,S;
	Polynomial Pa,Pb,Pc;
	int x;
	Pa=A->next;
	Pb=B->next;
	C=(Polynomial)malloc(sizeof(PolyNode));
	Pc=C;
	Pc->next=NULL;
	while(Pa&&Pb){
		if(Pa->exp==Pb->exp){
			x=Pa->coef-Pb->coef;
			if(x!=0){
				S=(Polynomial)malloc(sizeof(PolyNode));
				S->coef=x;
				S->exp=Pa->exp;
				S->next=NULL;
				Pc->next=S;
				Pc=S;
			}
			Pa=Pa->next;
			Pb=Pb->next;
		}
		else if(Pa->exp<Pb->exp){
			S=(Polynomial)malloc(sizeof(PolyNode));
			S->coef=Pa->coef;
			S->exp=Pa->exp;
			S->next=NULL;
			Pc->next=S;
			Pc=S;
			Pa=Pa->next;
		}
		else{
			S=(Polynomial)malloc(sizeof(PolyNode));
			S->coef=Pb->coef;
			S->exp=Pb->exp;
			S->next=NULL;
			Pc->next=S;
			Pc=S;
			Pb=Pb->next;
		}
	} 
	while(Pa){
		S=(Polynomial)malloc(sizeof(PolyNode));
		S->coef=Pa->coef;
		S->exp=Pa->exp;
		S->next=NULL;
		Pc->next=S;
		Pc=S;
		Pa=Pa->next;
	}
	while(Pb){
		S=(Polynomial)malloc(sizeof(PolyNode));
		S->coef=-(Pb->coef);
		S->exp=Pb->exp;
		S->next=NULL;
		Pc->next=S;
		Pc=S;
		Pb=Pb->next;		
	}
	
	return C;
}
int main(){
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		int num_A,num_B;
		cin>>num_A;
		cin>>num_B; 
		Polynomial A=Create_Polyn(A,num_A);
		Polynomial B=Create_Polyn(B,num_B);
		int q;
		cin>>q;
		for(int i=0;i<q;i++){
			int type;
			cin>>type;
			switch(type){
				case 1:{
					Display_Polyn(A);
					Display_Polyn(B);
					break;
				}
				case 2:{
					A=Add_Poly(A,B);
					break;
				}
				case 3:{
					A=Sub_Poly(A,B);
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
